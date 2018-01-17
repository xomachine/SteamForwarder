import macros
from wine import trace
from strutils import join, `%`
from sequtils import repeat, mapIt, map
from algorithm import reversed

{.push compileTime.}

proc genArgs*(n: int): seq[NimNode] =
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

proc genAsmHiddenCall*(name, obj: string, n: int): NimNode =
  var args = newSeq[string]()
  args.add("hidden")
  args.add(obj)
  for i in 1..n:
    args.add("argument" & $i)
  proc mapins(a: string): string = "[$1]\"g\"(`$1`)" % a
  let addition = (n + 1) * 4
  let ins = args.map(mapins).join(", ")
  let pushes = args.reversed()
    .map(proc(a: string): string = "push %[" & a & "]").join("\n    ")
  let asmstr = pushes & """

    call %[""" & name & """]
    add $""" & $addition & """, %%esp
    ::""" & ins & """, [""" & name & """]"r"(`""" & name & """`)
    :"cc"
  """
  var strlit = newNimNode(nnkTripleStrLit)
  strlit.strVal = asmstr
  newTree(nnkAsmStmt, newEmptyNode(), strlit)

proc genTraceCall*(n: int): NimNode =
  var args = newSeq[NimNode](n + 2)
  args[0] = bindSym("trace")
  args[1] = newStrLitNode("(" & "%p".repeat(n).join(", ") & ")")
  for i in 1..n:
    args[i+1] = newIdentNode("argument" & $i)
  newTree(nnkCall, args)

{.pop.}
