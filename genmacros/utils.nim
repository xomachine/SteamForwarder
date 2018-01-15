from macros import newTree, newNimNode, `strVal=`, nnkAsmStmt, newEmptyNode,
                   nnkTripleStrLit

type
  Symbol* = tuple
    name: string
    realname: string
    nargs: int
  SpecFile* = tuple
    libpath: string
    symbols: seq[Symbol]

macro strToAsm*(a: static[string]): untyped =
  var str = newNimNode(nnkTripleStrLit)
  str.strVal = a
  newTree(nnkAsmStmt, newEmptyNode(), str)

from strutils import splitLines, split, strip, parseInt
from maps import MemMaps, checkAddress, Flags
from wine import trace

proc parseFullSpec*(filename: string): SpecFile {.compileTime.} =
  let file = slurp(filename)
  result.symbols = newSeq[Symbol]()
  for line in file.splitLines:
    #echo "Splitting ", line
    if line.len > 0 and line[0] == '#':
      result.libpath = line.strip(true, true, {'#', ' '})
    let bySpace = line.split({' ', '('})
    if bySpace.len < 4:
      continue
    #let idx = bySpace[0]
    let conv = bySpace[1]
    if conv == "cdecl":
      let nargs = bySpace[^1].strip(true, true, {'#', ' '}).parseInt()
      let name = bySpace[^2]
      result.symbols.add((name: name, realname: name.strip(false, true, {'_'}),
                  nargs: nargs))

proc `+`*(a: pointer, b: int): ptr pointer =
  cast[ptr pointer](cast[int](a) + b)
proc `-`*(a: pointer, b: int): ptr pointer =
  cast[ptr pointer](cast[int](a) - b)


proc check*(m: MemMaps, p: pointer): auto =
  m.checkAddress(cast[uint32](p))

proc dumpMemoryRefs*(m: MemMaps, p: ptr pointer, level: string = "") =
  if level.len > 6:
    return
  #if Flags.read notin m.check(p).permissions:
  #  trace("%s%p - invalid\n", level.cstring, p)
  #  return
  trace("%s%p: %p", level.cstring, p, p[])
  if Flags.read notin m.check(p[]).permissions:
    trace(" - invalid\n")
    return
  trace("\n")
  let nextlevel = level & "  "
  let sellevel = level & ">>"
  for i in countup(-4, 20, 4):
    if i == 0:
      m.dumpMemoryRefs(p[] + i, sellevel)
    else:
      m.dumpMemoryRefs(p[] + i, nextlevel)

