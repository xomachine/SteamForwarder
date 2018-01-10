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

