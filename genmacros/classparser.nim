from tables import Table

{.push, compileTime.}

type
  StackState* = tuple
    ## The stack information about particular method.
    depth: int ## The stack depth method diving to.
               ## It helps to figure out number of the arguments of the method.
    swap: bool ## Indicator of in-memory return
  Classes* = Table[string, seq[StackState]]

proc readClasses*(): Classes
{.pop.}

const classes* = readClasses()

from strutils import splitLines, split, parseInt
from tables import initTable, `[]`, `[]=`, pairs

const cdfile {.strdefine.} = ""
  ## File name of classes info container. Being passed as the compiler option.

proc readClasses(): Classes =
  ## Reads the classes information from given file (defined via -d:cdfile=<>
  ## compiler option).
  result = initTable[string, seq[StackState]]()
  #var curaddr = 0'u32
  var curstr = ""
  let filedata = slurp(cdfile)
  for line in filedata.splitLines():
    if line.len == 0:
      continue
    elif line[0] == '!':
      let splitted = line.split({'!', ':'})
      assert splitted.len == 3
      curstr = splitted[1]
      #result[curaddr] = newSeq[int]()
      result[curstr] = newSeq[StackState]()
    else:
      let depth = parseInt(line)
      let swap = line[0] == '+'
      #result[curaddr].add(depth)
      result[curstr].add((depth: depth, swap: swap))
