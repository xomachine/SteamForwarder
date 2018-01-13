from tables import Table

{.push, compileTime.}

type
  Classes* = Table[string, seq[int]]

proc readClasses*(): Classes
proc genClasses*(c: Classes): NimNode
{.pop.}

const classes* = readClasses()

from strutils import splitLines, split, parseHexInt
from tables import initTable, `[]`, `[]=`, pairs

proc genClasses(c: Classes): NimNode =
  for address, methods in c:
    discard

const cdfile {.strdefine.} = ""

proc readClasses(): Classes =
  result = initTable[string, seq[int]]()
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
      #curaddr = parseHexInt(splitted[2]).uint32
      #result[curaddr] = newSeq[int]()
      result[curstr] = newSeq[int]()
    else:
      let depth = parseHexInt(line)
      #result[curaddr].add(depth)
      result[curstr].add(depth)
