from strutils import `%`, join
from sequtils import map, mapIt, foldl
from streams import Stream
from arg import Arg, TheType, toDeclaration, parseArgs, parseType,
                to_format, isVoid, isException, isClass, toSpecArg
from re import re, find, match, reMultiline, reDotAll, contains

type
  CallInfo* = tuple
    name: string
    args: seq[Arg]
    returntype: TheType
    class: string
    inline: bool
    private: bool

const hidden_ptr = (name: "hidden", thetype: (base: "CSteamID", reference: "*"))

proc fixcall(self: CallInfo): CallInfo =
  result = self
  (result.returntype, result.args) =
    # CSteamID should be returned by reference instead of value
    # due to the wine inability to correctly handle calling convention
    if self.returntype.isException():
      (hidden_ptr.thetype, hidden_ptr & self.args)
    else: (self.returntype, self.args)

let funcre = re("""^(extern "C"|S_API|inline)([^{};]*?[&*\s])(\w+)\(([^{};]*)\)""" &
                """([^{})]*;.*?)$""", {reMultiline, reDotAll})

proc parseFuncs*(raw: string): seq[CallInfo] =
  result = newSeq[CallInfo]()
  var i = 0
  var matches = newSeq[string](5)
  while (i = raw.find(funcre, matches, i); i >= 0):
    var function: CallInfo
    function.class = ""
    function.private = false
    # inline functions is not a part of latest steam ABI, but they are
    # exist in previous versions of steam_api.dll, so they must be
    # added in a special way
    function.inline = matches[0] == "inline"
    function.returntype = matches[1].parseType()
    function.name = matches[2]
    function.args = matches[3].parseArgs()
    result.add(function)
    i += matches.mapIt(it.len).foldl(a + b)

let methodre = re("""^\s*(\w*)(:?\s*virtual\s+)([^{};]*?)\s*(\w+)\(([^{};]*?)\)[^)]*;.*?$""", {reMultiline, reDotAll})
proc parseMethods*(raw: string, class: string, enums: seq[string] = @[]): seq[CallInfo] =
  result = newSeq[CallInfo]()
  var i = 0
  var matches = newSeq[string](5)
  while (i = raw.find(methodre, matches, i); i >= 0):
    var themethod: CallInfo
    themethod.private = matches[0] in ["private", "protected"]
    themethod.class = class
    themethod.inline = false
    themethod.returntype = matches[2].parseType()
    themethod.name = matches[3]
    themethod.args = matches[4].parseArgs()
    if enums.len > 0:
      proc enumfix(source: Arg): Arg =
        result = source
        if result.thetype.base in enums:
          # For enums declared inside a class
          result.thetype.base = "$1::$2" % [class, result.thetype.base]
      themethod.args = themethod.args.map(enumfix)
    result.add(themethod)
    i += matches.mapIt(it.len).foldl(a + b)

proc toDeclaration(args: seq[Arg]): string =
  args.map(toDeclaration).join(", ")

proc makeHead(self: CallInfo): string =
  let fixed = fixcall(self)
  let name = if self.class.len > 0: self.class & "_::" & self.name
    else: self.name & '_'
  let inline_declaration = 
    if self.returntype.isClass() and self.inline:
      "$1 * saved_$1 = NULL;" % self.returntype.base
    else: ""
  """$4
$1 $2($3)""" % [fixed.returntype.to_declaration(), name,
                fixed.args.to_declaration(), inline_declaration]  

proc makeDeclaration*(self: CallInfo): string {.procvar.} =
  let fixed = fixcall(self)
  let convention =
    if self.class == "": "__cdecl"
    else: "__attribute__((thiscall))"
  let virtual =
    if self.class.len > 0: "virtual"
    else: ""
  "$1 $2 $3($4) $5;" % [virtual, fixed.returntype.to_declaration(), self.name,
                        fixed.args.to_declaration(), convention]

proc makeTraceArgs(self: CallInfo, firstarg: string = "this"): string =
  # RunCallbacks is being called to often and tracing it may cause
  # performance degradation
  if unlikely(self.name == "SteamAPI_RunCallbacks"): ""
  else:
    let args =
      if self.class.len > 0:
        (name: firstarg, thetype: (base: self.class, reference: "*")) &
          self.args
      else: self.args
    let trace_args = args.mapIt(it.name).join(", ")
    let final_trace_args = if trace_args.len > 0: ", " & trace_args else: ""
    let format_args = args.mapIt(it.thetype).map(to_format).join(", ")
    let tracer = if firstarg == "this": "TRACE(\"" else: ""
    """$3($1)\n"$2);""" % [format_args, final_trace_args, tracer]

proc makeTraceResult*(self: CallInfo): string =
  case self.returntype.base
  of "void": ""
  else:
    """TRACE("() = $1\n", result);""" % self.returntype.to_format()

proc makeRealCall(self: CallInfo): string =
  let arglist = self.args.mapIt(it.name).join(", ")
  if self.class.len > 0:
    """this->internal->$1($2)""" % [self.name, arglist]
  else:
    """$1($2)""" % [self.name, arglist]

proc makeResult(self: CallInfo, test: bool = false): string =
  if self.private:
    ""
  elif self.returntype.isVoid():
    """$1;""" % self.makeRealCall()
  elif self.returntype.isException():
    """*hidden = $1;""" % self.makeRealCall()
  elif self.returntype.isClass():
    let realcall = if test: "NULL" else: self.makeRealCall()
    if self.inline and not test:
      """if (saved_$1 == NULL) {
    auto internal = $2;
    if (internal == NULL) {
      TRACE("() = NULL!\n");
      return saved_$1;
    }
    saved_$1 = ($1 *) new $1_(internal);
    TRACE("(): ($1 *)%p wrapped as ($1_ *)%p\n", internal, saved_$1);
  }
  TRACE("() = ($1_ *)%p\n", saved_$1);
""" % [self.returntype.base, realcall]
    elif self.inline:
      """
  auto result = new $1_(NULL);
  $2
""" % [self.returntype.base, self.makeTraceResult()]
    else:
      """auto result = new $1_($2);
  $3
""" % [self.returntype.base, realcall, self.makeTraceResult()]
  else:
    """auto result = $1;
  $2
""" % [self.makeRealCall(), self.makeTraceResult()]

let callbackre = re"""^SteamAPI_(Un)?[Rr]egisterCall(back|Result)$"""
proc makeBody*(self: CallInfo): string {.procvar.} =
  if unlikely(self.name.match(callbackre)):
    # Callbacks are handled in callbacks.cpp in a special way
    ""
  else:
    let returnstmt =
      if self.returntype.isVoid(): ""
      elif self.returntype.isException(): "return hidden;"
      elif self.returntype.isClass():
        if self.inline:
          """return saved_$1;""" % self.returntype.base
        else:
          """return ($1)result;""" % self.returntype.to_declaration()
      else: "return result;"
    """
$1
{
  $2
  $3
  $4
}
""" % [self.makeHead(), self.makeTraceArgs(), self.makeResult(), returnstmt]

proc makeTest*(self: CallInfo): string {.procvar.} =
  proc makeDeclaration(a: Arg): string =
    let rvalue =
      if a.thetype.toSpecArg() == "str": a.name & """ = "Test""""
      else: a.name
    """  $1 $2;""" % [a.thetype.toDeclaration(), rvalue]
  let tracer = self.makeTraceArgs(self.class & "_var")
  let arglist = self.args.mapIt(it.name).join(", ")
  let arg_declarations = self.args.map(makeDeclaration).join("\n")
  """
  {
    $1
    printf("test::steam_api:$3 $5
    $2_var->$3($4);
    std::cout << "DONE!" << std::endl;
  }
""" % [arg_declarations, self.class, self.name, arglist, tracer]

proc makeTestBody*(self: CallInfo): string {.procvar.} =
  let resultcall =
    if self.class == "" and self.returntype.isClass():
      self.makeResult(test = true) & "\n  return ($1)result;" %
        self.returntype.toDeclaration()
    else: ""
  """
$1
{
  $2
  $3
}
""" % [self.makeHead(), self.makeTraceArgs(), resultcall]

when isMainModule:
  const test = """
  virtual CSteamID somemethod(testnum a, CSteamID * b, int var1, char * var2,
    const char* var3);
"""
  let methods = test.parseMethods("someclass")
  for m in methods:
    echo m.makeBody()
