import re
import parseopt
from os import walkFiles, existsFile
from strutils import `%`, join, strip, toUpperAscii
from sequtils import mapIt
from ospaths import `/`, extractFilename, changeFileExt,
                    parentDir
from parseutils import parseInt
const tdesc = """[constlausigedr\s]*[\w:]+""" &
              """[constlausigedr\s]*[*\s&]+"""

type OutType = enum
  header
  cpp
type Arg = tuple
  thetype: string
  name: string
type CallInfo = tuple
  name: string
  args: seq[Arg]
  rettype: string
  prefix: string
  inline: bool
type nConv = proc(a: Arg): string
type SpecFile = tuple
  names: seq[string]
  behaviours: seq[string]
  args: seq[string]
  newnames: seq[string]
 
let classre = re"^class\s+(\w+)[^#;]*({?)\s*$"
let enumterm = re"^\s+};\s*$"
let argre = re("""\s*($1)\s*(\w+)\s*""" % tdesc)
let enumre = re"^\s+enum\s+(\w+)\s*$"
let closere = re"^};\s*$"
let methodre = re("""^\s*.*virtual\s+(""" & tdesc &
  """)\s*(\w+)\(([^{}]*)\)[^)]*;.*$""")
let openre = re"^{\s*$"
let ifdefre = re"^\s*\#ifdef\s+.*$"
let ifre = re"^\s*\#if\s+.*$"
let endifre = re"^\s*\#endif\s*$"
let elsere = re"^\s*\#else\s*$"
let sapire = re("""^(S_API|inline)\s+("""& tdesc &
              """)(S_CALLTYPE\s+)?(\w+)\(([^{}]*)\)""" &
              """[^{})]*;.*$""")

let specre = re"^([0-9]+|@)\s+(\w+)\s+(\w+)(\([^)]*\))?\s*(\w+)?.*$"
let strre = re"^\s*(\w+\s+)char\s*\*\s*$"
let intre = re"^\s*(\w+\s+)?(u?int([136][246])?|long)\s*$"
let floatre = re"^\s*(\w+\s+)?float([136][246])?\s*"

proc mapper(a: string): string =
  let ftype =
    if a.match(strre): """\"%s\""""
    elif a.match(intre):
      "%d"
    elif a.match(floatre):
      "%f"
    elif a == "bool": "%d"
    else: "%p"
  "($2)$1" % [ftype, a]

proc get_spec_arg(a: string): string =
  if a.match(strre): "str"
  elif re"\*" in a: "ptr"
  else: "long"


proc parseArgs(a: string): seq[Arg] =
  var matches = newSeq[string](2)
  result = newSeq[Arg]()
  var idx = 0
  while (idx = a.find(argre, matches, idx);idx >= 0):
    idx += matches[0].len + matches[1].len
    result.add((thetype: matches[0].strip(), name: matches[1]))

proc genBody(outs: File, cinfo: CallInfo,
             n: nConv = proc(a: Arg): string = a.name) =
  let (firstarg, this) =
    if cinfo.prefix.len > 0: (1, ", this") else: (0, "")
  let namelist =
    if cinfo.args.len > firstarg:
      cinfo.args[firstarg..^1].mapIt(n(it)).join(", ")
    else: ""
  let namelisttrace =
    if namelist.len > 0: [this, namelist].join(", ")
    else: this
  let fstr = cinfo.args.mapIt(mapper(it.thetype)).join(", ")
  let trace = "  TRACE($1$2);" % ["\"($1)\\n\"" % fstr,
                                  namelisttrace]
  if likely(re"RunCallbacks" notin cinfo.name):
    outs.writeLine trace
  if "void" == cinfo.rettype.strip():
    outs.writeLine """  $3$1($2);""" %
      [cinfo.name, namelist, cinfo.prefix]
  elif cinfo.rettype.strip() == "CSteamID":
    # Very special case of returning structure by value
    # Structure should be written into hidden pointer
    # passed to the method as argument(but not declared)
    # The pointer should be returned afterward
    let namelistnohidden = 
      if cinfo.args.len > firstarg+1:
        cinfo.args[(firstarg+1)..^1].mapIt(n(it)).join(", ")
      else: ""
    outs.writeLine(
      """  *hidden = $3$1($2);""" %
      [cinfo.name, namelistnohidden, cinfo.prefix])
    outs.writeLine """  return hidden;"""
  elif re"ISteam" in cinfo.rettype:
    let basereturntype = cinfo.rettype.replace(re"\s*\*")
    let (outval, cond) =
      if cinfo.inline:
        ("saved_" & cinfo.name,
         "if (!saved_$1) " % cinfo.name)
      else: ("result", "auto")
    outs.writeLine """  $3 $2 = new $1_();""" %
      [basereturntype, outval, cond] 
    outs.writeLine "  $4->internal = $3$1($2);" %
      [cinfo.name, namelist, cinfo.prefix, outval]
    outs.writeLine("""  TRACE(" = $1 wrapped[$2]\n",""" %
      [mapper(basereturntype & "_*"), mapper(cinfo.rettype)] &
      """ $1, $1->internal);""" % outval)
    outs.writeLine """  return ($1)$2;""" %
      [cinfo.rettype, outval]
  else:
    outs.writeLine(
      """  $1 result = $4$2($3);""" %
      [cinfo.rettype, cinfo.name, namelist,
       cinfo.prefix])
    outs.writeLine """  TRACE(" = $1\n", result);""" %
      [mapper(cinfo.rettype)]
    outs.writeLine """  return result;"""

proc parseSpec(filename: string): SpecFile =
  result.names = newSeq[string]()
  result.behaviours = newSeq[string]()
  result.newnames = newSeq[string]()
  result.args = newSeq[string]()
  var matches = newSeq[string](5)
  var counter = 0
  for line in filename.lines():
    if line.match(specre, matches):
      var num = 0
      if matches[0] == "@":
        counter += 1
        num = counter
      else: discard matches[0].parseInt(num)
      if result.names.len <= num:
        result.names.setlen(num)
        result.behaviours.setlen(num)
      result.behaviours[num-1] = matches[1]
      result.names[num-1] = matches[2]
      if not matches[3].isNil():
        if result.args.len <= num:
          result.args.setlen(num)
        result.args[num-1] =
          matches[3].strip(true, true, {'(', ')'})
        matches[3] = nil
  result.newnames.setlen(result.names.len)
  result.args.setlen(result.names.len)

proc writeSpec(filename: string, spec: SpecFile) =
  let outs = open(filename, fmWrite)
  assert spec.names.len == spec.newnames.len
  assert spec.names.len == spec.behaviours.len
  for i in 0..<spec.names.len:
    let newname =
      if spec.newnames[i].isNil(): ""
      else: spec.newnames[i]
    let behaviour =
      if newname == "": "stub"
      else: spec.behaviours[i]
    let arg =
      if newname == "": ""
      else: spec.args[i]
    outs.writeLine "$1 $3 $2($5) $4" %
      [$(i+1), spec.names[i], behaviour, newname, arg]
  outs.close()

proc makeClasses(filename: string, targetdir:string,
                 otype:OutType)
proc parseSteamApiH(source, dest: string,
                    spec: var SpecFile)

##############
# Begin here #
##############
var sourcedir = ""
var target = ""
var specfile = ""
for t, k, v in getopt():
  case t
  of cmdShortOption, cmdLongOption:
    case k
    of "s", "source":
      sourcedir = v
    of "t", "target":
      target = v
    of "spec":
      specfile = v
    of "h", "help":
      echo "-s, --source - set steamapi headers folder"
      echo "--spec - set spec file location"
      echo "-t, --target - set classes destination folder"
    else:
      discard
  else:
    discard
if sourcedir.len == 0 or target.len == 0 or specfile == "":
  quit("Use options to set spec file, steamapi headers" &
       " and target folders")
var thespec = parseSpec(specfile)
parseSteamApiH(sourcedir, target, thespec)
let head = open(target / "steam_api_.h", fmWrite)
let forbidden_files = [
  "isteammasterserverupdater.h",
  "isteamappticket.h",
  "isteamgamecoordinator.h",
  "isteamps3overlayrenderer.h"
]
for f in walkFiles(sourcedir / "isteam*.h"):
  let fname = f.extractFilename()
  if unlikely(fname in forbidden_files):
    continue
  makeclasses(f, target, header)
  makeclasses(f, target, cpp)
  head.writeLine("""#include "$1"""" % 
                 (target / "wrap_" & fname))
head.close()
writeSpec(specfile.changeFileExt("auto.spec"), thespec)

proc addCall(oss: File, call: CallInfo, spec: var SpecFile) =
  let posInSpec = spec.names.find(call.name)
  if posInSpec < 0:
    # If function not in spec - dont perform codegen 
    return
  echo "Adding: " & call.name
  spec.newnames[posInSpec] = call.name & "_"
  spec.behaviours[posInSpec] = "cdecl"
  if re"[Rr]egisterCall" in call.name:
    # it's callback handler we should not generate code 
    # for it becouse its already defined in callbacks.cpp.
    spec.args[posInSpec] =
      if re"Unregister" in call.name: " ptr "
      else: " ptr long "
    return
  let args =
    call.args.mapIt(it.thetype & " " & it.name).join(", ")
  if spec.args[posInSpec].isNil():
    spec.args[posInSpec] =
      call.args.mapIt(get_spec_arg(it.thetype)).join(" ")
  if call.inline:
    oss.writeLine """$1_* saved_$2;""" %
      [call.rettype.strip(true, true, {'*',' '}), call.name]
  oss.writeLine """$1 $2_($3)""" %
    [call.rettype, call.name, args]
  oss.writeLine "{"
  oss.genBody(call)
  oss.writeLine "}"

proc readHeader(oss: File, spec: var SpecFile,
                source, dest, name: string) =
  var matches = newSeq[string](5)
  var skipper = 0
  for line in (source / name).lines():
    if line.match(ifre) or line.match(ifdefre):
      if skipper > 0 or re"_PS3" in line or
         re"_SERVER" in line:
        skipper += 1
      continue
    elif skipper > 0:
      if line.match(endifre) or line.match(elsere):
        skipper -= 1
      continue
    if line.match(sapire, matches):
      let fname = matches[3]
      let rettype = matches[1].strip()
      let args = matches[4]
      let inline = matches[0] == "inline"
      let pargs = parseArgs(args)
      let cinfo = (name: fname, args: pargs,
                   rettype: rettype, prefix: "",
                   inline: inline)
      oss.addCall(cinfo, spec)

proc parseSteamApiH(source, dest: string,
                    spec: var SpecFile) =
  let osfile = "steam_api.cpp"
  let oss = open(osfile, fmWrite)
  oss.writeLine """#include "config.h""""
  if existsFile(source / "steam_api_flat.h"):
    oss.writeLine """#include "steam_api_flat.h""""
  oss.writeLine """#include "steam_api.h""""
  oss.writeLine """#include "$1/steam_api_.h"""" % dest
  oss.writeLine """#include "stdint.h""""
  oss.writeLine """#ifdef __cplusplus"""
  oss.writeLine """extern "C" {"""
  oss.writeLine """#endif"""
  oss.readHeader(spec, source, dest, "steam_api.h")
  if existsFile(source / "steam_api_flat.h"):
    oss.readHeader(spec, source, dest, "steam_api_flat.h")
  if existsFile(source / "steam_api_internal.h"):
    oss.readHeader(spec, source, dest, "steam_api_internal.h")
  #oss.addCall((name: "SteamClient", args: @[],
  #             rettype: "ISteamClient *", prefix: "")
  oss.writeLine """#ifdef __cplusplus"""
  oss.writeLine """}"""
  oss.writeLine """#endif"""
  oss.close()

proc makeClasses(filename: string, targetdir:string,
                 otype:OutType) =
  var matches = newSeq[string](3)
  var enumnames = newSeq[string]()
  var cur_class = ""
  var enumreading = false
  var skipper = 0
  let fname = filename.extractFilename()
  let resultfname =
    if otype == header:
      "wrap_" & fname
    else:
      "wrap_" & fname.changeFileExt("cpp")
  let outs = open(targetdir / resultfname, fmWrite)
  let modname = resultfname.toUpperAscii().replace(re"[^\w]",
                                                   "_")
  outs.writeLine """#ifndef $1""" % modname
  outs.writeLine """#define $1""" % modname
  if otype == header:
    outs.writeLine """#include "steam_api.h""""
    #outs.writeLine """#ifdef __cplusplus"""
    #outs.writeLine """extern {"""
    #outs.writeLine """#endif"""
    #outs.writeLine """#include "$1"""" %
    #  filename.extractFilename()
  else:
    outs.writeLine """#include "$1/steam_api_.h" """ %
                   targetdir
    outs.writeLine """#include "windef.h""""
    outs.writeLine """#include "wine/debug.h""""
    outs.writeLine """#include "config.h""""
  let stream = open(filename, fmRead)
  for line in stream.lines():
    if line.match(ifre) or line.match(ifdefre):
      if skipper > 0 or re"_PS3" in line or
         re"_SERVER" in line:
        skipper += 1
      continue
    elif skipper > 0:
      if line.match(endifre) or line.match(elsere):
        skipper -= 1
      continue
    if line.match(classre, matches):
      cur_class = matches[0]
      let classname = matches[0] & "_"
      if otype == header:
        outs.writeLine "class $1 $2" %
                       [classname, matches[1]]
    elif cur_class.len > 0 and line.match(openre):
      if otype == header:
        outs.writeLine "{"
    elif cur_class.len > 0 and line.match(closere):
      if otype == header:
        outs.writeLine "  public:"
        outs.writeLine "    $1 *internal;" % cur_class
        outs.writeLine "};"
      cur_class = ""
      enumnames = newSeq[string]()
    elif line.match(methodre, matches):
      let prereturn = matches[0].strip()
      let (args, returntype) =
        if unlikely(prereturn == "CSteamID"):
          ("CSteamID* hidden" &
           (if matches[2].len > 0: "," else: "") &
           matches[2], prereturn & "*")
        else: (matches[2], prereturn)
      let mname = matches[1]
      if cur_class.len <= 0:
        continue
      if otype == header:
          outs.writeLine "  virtual $1 $2($3)" %
            [returntype, mname, args] &
            " __attribute__((thiscall));"
      else:
        let pargs = (thetype:"this[$1]" % cur_class,
                     name: "this") & parseArgs(args)
        outs.writeLine "$1 $2_::$3($4)" %
          [returntype, cur_class, mname, args]
        outs.writeLine "{"
        if not line.match(re"^\s*virtual\s+.*$"):
          outs.writeLine """  TRACE("(deprecated)\n");"""
        else:
          proc namer(a: Arg): string =
            if a.thetype.strip() in enumnames:
              "($1::$2)$3" % [curclass, a.thetype, a.name]
            else: a.name
          let cinfo = (name: mname, args: pargs,
                       rettype: prereturn,
                       prefix: "this->internal->",
                       inline: false)
          outs.genBody(cinfo, namer)
        outs.writeLine "}"
    elif enumreading and line.match(enumterm):
      outs.writeLine line
      enumreading = false
    elif enumreading or (cur_class.len > 0 and
                         line.match(enumre, matches)):
      if otype == header:
        outs.writeLine line
        enumreading = true
      else:
        enumnames.add(matches[0])
  if otype == header:
    discard
    #outs.writeLine """#ifdef __cplusplus"""
    #outs.writeLine """}"""
    #outs.writeLine """#endif"""
  outs.writeLine """#endif"""
  stream.close()
  outs.close()
 