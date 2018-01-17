from tables import Table

{.push, compileTime.}

type
  StackState* = tuple
    depth: int
    swap: bool
  Classes* = Table[string, seq[StackState]]

proc readClasses*(): Classes
{.pop.}

const classes* = readClasses()

from strutils import splitLines, split, parseInt
from tables import initTable, `[]`, `[]=`, pairs

const cdfile {.strdefine.} = ""

proc readClasses(): Classes =
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
