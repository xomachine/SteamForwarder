from strutils import `%`, startsWith, strip, isNilOrEmpty, join
from sequtils import mapIt, foldl, filterIt
from streams import Stream, newStringStream, getPosition, setPosition, atEnd
from parser import parseTill
from re import re, find, match, reMultiline
type
  TheType* = tuple
    base: string
    reference: string
  Arg* = tuple
    name: string
    thetype: TheType
const modifiers = """(const|u?n?signed|long|short|class|struct|\s)*"""
const tdesc = "^" & modifiers & """?([\w:]+)""" &
              """\s*?""" & modifiers & """?\s*([&*]*)\s*$"""

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
let intre = re"""^.*u?(int|long)(16|32|64)?\s*$"""
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
  var matches = newSeq[string](4)
  assert(raw.find(typere, matches, shift) >= 0,
         "Cannot find type in $1" % raw[shift..^1])
  result.base = matches[0..2].filterIt(not it.isNilOrEmpty())
                .mapIt(it.strip()).join(" ").strip()
  result.reference = matches[^1]

let argre = re("""\s*([^,)=]+[^\w=])\s*(\w+)\s*($|[,)=])""", {reMultiline})
proc parseArgs*(raw: string): seq[Arg] =
  result = newSeq[Arg]()
  var matches = newSeq[string](3)
  let rawstream = newStringStream(raw)
  var ss = ""
  while (ss = rawstream.parseTill({',', '}'}); ss.find(argre, matches) >= 0):
    var a: Arg
    a.thetype = matches[0].parseType()
    a.name = matches[1]
    result.add(a)


proc toDeclaration*(self: Arg): string {.procvar.} =
  "$1 $2" % [self.thetype.to_declaration(), self.name]

