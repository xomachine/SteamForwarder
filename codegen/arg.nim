from strutils import `%`, startsWith
from sequtils import mapIt, foldl
from streams import Stream
from parser import parseTill
from re import re, find, match
type
  TheType* = tuple
    base: string
    reference: string
  Arg* = tuple
    name: string
    thetype: TheType

const tdesc* = """([constlausigedr\s]*[\w:]+""" &
              """\s*[constlausigedr]*)\s*([&*]*)\s*"""

let argre = re("""\s*$1\s*(\w+)\s*""" % tdesc)
let typere = re(tdesc)

proc isException*(self: TheType): bool =
  self.base == "CSteamID" and self.reference == ""

proc isVoid*(self: TheType): bool =
  self.base == "void" and self.reference == ""

proc isClass*(self: TheType): bool =
  self.base.startsWith("ISteam")


proc toDeclaration*(self: TheType): string {.procvar.} =
  "$1 $2" % [self.base, self.reference]

let floatre = re"""^.*(float|double)\s*$"""
let intre = re"""^.*u?(int|long)\s*$"""
let charre = re"""^.*u?char\s*$"""
proc to_format*(self: TheType): string {.procvar.} =
  let ftype =
    if self.base == "bool" or self.base.match(intre): "%d"
    elif self.base.match(charre):
      if '*' in self.reference: """\"%s\""""
      else: """\"%c\""""
    elif self.base.match(floatre): "%f"
    else: "%p"
  "($2)$1" % [ftype, self.to_declaration()]

proc toSpecArg*(self: TheType): string =
  if self.base.match(charre) and '*' in self.reference: "str"
  elif '*' in self.reference: "ptr"
  else: "long"

proc parseType*(raw: string, shift: int = 0): TheType =
  var matches = newSeq[string](2)
  assert raw.find(typere, matches, shift) >= 0
  result.base = matches[0]
  result.reference = matches[1]

proc parseArgs*(raw: string): seq[Arg] =
  result = newSeq[Arg]()
  var i = 0
  var matches = newSeq[string](3)
  while (i = raw.find(argre, matches, i); i >= 0):
    var a: Arg
    a.thetype.base = matches[0]
    a.thetype.reference = matches[1]
    a.name = matches[2]
    result.add(a)
    i += matches.mapIt(it.len).foldl(a + b, 0)

proc parseArg*(raw: Stream): Arg =
  let arg = raw.parseTill({','})
  var matches = newSeq[string](3)
  assert arg.find(argre, matches) >= 0
  result.thetype.base = matches[0]
  result.thetype.reference = matches[1]
  result.name = matches[2]


proc toDeclaration*(self: Arg): string {.procvar.} =
  "$1 $2" % [self.thetype.to_declaration(), self.name]

