from call import CallInfo, parseMethods, makeDeclaration, makeBody,
                 makeTest, makeTestBody
from sequtils import mapIt, foldl, map
from strutils import join, `%`
from re import re, find, reMultiline
from streams import Stream, newStringStream, getPosition, setPosition
from parser import parseTill

type
  Class = tuple
    name: string
    methods: seq[CallInfo]

let classre = re("""^(class\s+)(\w+)([^#;]*?){?$""", {reMultiline})
let enumre = re("""^\s*enum\s+(\w+).*?$""", {reMultiline})

proc parseEnums(raw: string): seq[string] =
  result = newSeq[string]()
  var i = 0
  var matches = newSeq[string](1)
  while (i = raw.find(enumre, matches, i); i>=0):
    result.add(matches[0])
    i += matches[0].len + 5 # len of enum and space

proc parseClasses*(raw: string): seq[Class] =
  let stream = newStringStream(raw)
  var i = 0
  result = newSeq[Class]()
  var matches = newSeq[string](3)
  while (i = raw.find(classre, matches, i); i>=0):
    var theclass: Class
    theclass.name = matches[1]
    i += matches.mapIt(it.len).foldl(a + b)
    stream.setPosition(i)
    discard stream.parseTill({'{'})
    let underclass = stream.parseTill({'}'})
    i = stream.getPosition()
    let enums = underclass.parseEnums()
    theclass.methods = underclass.parseMethods(theclass.name, enums)
    result.add(theclass)


proc toDeclaration*(self: Class): string {.procvar.} =
  let methods = self.methods.map(makeDeclaration).join("\n  ")
  """
class $1_
{
public:
  $2
  $1_($1*to_wrap);
  ~$1_();
private:
  $1 * internal;
};
""" % [self.name, methods]

proc makeConDestructor(self: Class): string =
  """
$1_::$1_($1 * towrap)
{
  this->internal = towrap;
}

$1_::~$1_()
{
  delete this->internal;
}
""" % self.name

proc toImplementation*(self: Class): string {.procvar.} =
  self.methods.map(makeBody).join("\n") & self.makeConDestructor()

proc toTestImplementation*(self: Class): string {.procvar.} =
  self.methods.map(makeTestBody).join("\n") & self.makeConDestructor()

proc makeTest*(self: Class): string {.procvar.} =
  let methods = self.methods.map(makeTest).join("\n")
  """
  {
    auto $1_var = $2();
$3
  }
""" % [self.name, self.name[1..^1], methods]
  
when isMainModule:
  let test = """
class myclass
//some comment {}
{
  enum testnum{
    testing, testing, testing
  };

  virtual CSteamID testmethod(testnum a, CSteamID * b);
  virtual char * mymethod();
};
"""
  let classes = test.parseClasses()
  for c in classes:
    echo c.toDeclaration()
