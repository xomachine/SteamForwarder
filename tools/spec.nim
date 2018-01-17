from strutils import split, parseInt
from tables import initOrderedTable, OrderedTable, `[]`, `[]=`

type
  Symbol* = object
    idx*: Natural
    callconv*: string
    name*: string
  SpecFile* = OrderedTable[string, Symbol]

proc readSpecFile*(file: File): SpecFile =
  result = initOrderedTable[string, Symbol]()
  for line in file.lines():
    if line.len == 0 or line[0] == '#':
      continue
    let splitted = line.split()
    let sym = Symbol(idx: splitted[0].parseInt, callconv: splitted[1],
                     name: splitted[2])
    result[splitted[2]] = sym
