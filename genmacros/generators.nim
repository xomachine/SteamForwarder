import macros
from wine import trace
from strutils import join
from sequtils import repeat

proc genArgs*(n: int): seq[NimNode] {.compileTime.} =
  result = newSeq[NimNode](n+1)
  result[0] = newIdentNode("uint32")
  for i in 1..n:
    result[i] = newIdentDefs(newIdentNode("argument" & $i),
                             newIdentNode("uint32"))
proc genCall*(name: string, n: int): NimNode {.compileTime.} =
  var args = newSeq[NimNode](n+1)
  args[0] = newIdentNode(name)
  for i in 1..n:
    args[i] = newIdentNode("argument" & $i)
  newTree(nnkCall, args)

proc genTraceCall*(n: int): NimNode {.compileTime.} =
  var args = newSeq[NimNode](n + 2)
  args[0] = bindSym("trace")
  args[1] = newStrLitNode("(" & "%p".repeat(n).join(", ") & ")")
  for i in 1..n:
    args[i+1] = newIdentNode("argument" & $i)
  newTree(nnkCall, args)
