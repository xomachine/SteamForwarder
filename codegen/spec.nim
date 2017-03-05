from re import re, match
from strutils import `%`, strip, join
from sequtils import mapIt
from parseutils import parseInt
from call import CallInfo
from arg import Arg, toSpecArg

type SpecFile* = tuple
  names: seq[string]
  behaviours: seq[string]
  args: seq[string]
  newnames: seq[string]

let specre = re"^([0-9]+|@)\s+(\w+)\s+(\w+)(\([^)]*\))?\s*(\w+)?.*$"


proc parseSpec*(filename: string): SpecFile =
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
          matches[3].strip(true, true, {'(', ')', ' '})
        matches[3] = nil
  result.newnames.setlen(result.names.len)
  result.args.setlen(result.names.len)

proc writeSpec*(filename: string, spec: SpecFile) =
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
      if spec.args[i].isNil() or spec.args[i] == "": ""
      else: " " & spec.args[i] & " "
    outs.writeLine "$1 $3 $2($5) $4" %
      [$(i+1), spec.names[i], behaviour, newname, arg]
  outs.close()

proc filterSpec*(self: var SpecFile, functions: seq[CallInfo]): seq[CallInfo] =
  result = newSeq[CallInfo]()
  for c in functions:
    let pos = self.names.find(c.name)
    if pos >= 0:
      self.newnames[pos] = c.name & '_'
      self.args[pos] = c.args.mapIt(it.thetype.toSpecArg()).join(" ")
      self.behaviours[pos] = "cdecl"
      result.add(c)
