import macros
from wine import trace
from strutils import join, `%`
from sequtils import repeat, mapIt, map
from algorithm import reversed

{.push compileTime.}
## All the procedures in this file is a compile time procedures, so
## they just generate the code and never being called at runtime.

proc genArgs*(n: int): seq[NimNode] =
  ## Generates arguments list and return value for the procedure declaration.
  ## n - is number of arguments to be generated. The arguments have names like
  ## argument1, argument2 etc... The return value is always uint64 to avoid
  ## the edx register eating when it is really uint64
  ## (no idea how to distinguish)
  result = newSeq[NimNode](n+1)
  result[0] = newIdentNode("uint64")
  for i in 1..n:
    result[i] = newIdentDefs(newIdentNode("argument" & $i),
                             newIdentNode("pointer"))

proc genCall*(name: string, n: int): NimNode =
  ## Generates the call of the function with name `name` and `n` number of
  ## arguments which have names argument1, argument2 etc...
  var args = newSeq[NimNode](n+1)
  args[0] = newIdentNode(name)
  for i in 1..n:
    args[i] = newIdentNode("argument" & $i)
  newTree(nnkCall, args)

proc genAsmNativeCall64*(name: string, n: int): NimNode =
  const mapping = ["rdi", "rsi", "rdx", "rcx", "r8", "r9"]
  var str = newNimNode(nnkTripleStrLit)
  var pushes = ""
  var asigns = newSeq[string]()
  asigns.add("[name]\"g\"(`" & name & "`)")
  var clubbers = newSeq[string]()
  clubbers.add("\"cc\"")
  clubbers.add("\"rsp\"")
  clubbers.add("\"rax\"")
  for i in 1..n:
    if i == 1:
      asigns.add("[argument" & $i & "]\"g\"(`origin`)")
    else:
      asigns.add("[argument" & $i & "]\"g\"(`argument" & $i & "`)")
    if i <= mapping.len:
      pushes = pushes & "mov %[argument" & $i & "], %%" & mapping[i-1] & "\n"
      clubbers.add("\"" & mapping[i-1] & "\"")
    else:
      pushes = pushes & "push %[argument" & $i & "]\n"
  str.strVal = pushes & """
  call %[name]
  mov %%rax, %[result]
  :[result]"=g"(`tmpvar`)
  :""" & asigns.join(", ") & """
  :""" & clubbers.join(", ")
  let asmstmt = newTree(nnkAsmStmt, newEmptyNode(), str)
  quote do:
    (var tmpvar: uint64; `asmstmt`; tmpvar)

proc genAsmHiddenCall*(name, obj: string, n: int): NimNode =
  ## Generates the call of the method with name `name` of object `obj` and
  ## `n` number of arguments which have names argument1, argument2 etc...
  ## The method performs in-memory return so the additional hidden argument
  ## is added before the object argument and the stack fix is being performed
  var args = newSeq[string]()
  args.add("hidden")
  args.add(obj)
  for i in 1..n:
    args.add("argument" & $i)
  proc mapins(a: string): string = "[$1]\"g\"(`$1`)" % a
  let addition = (n + 1) * 4 # stack pointer should be increased on this value
                             # after call
  let ins = args.map(mapins).join(", ")
  let pushes = args.reversed()
    .map(proc(a: string): string = "push %[" & a & "]").join("\n    ")
     ## argument pushes to the stack
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
  ## Generates the call of the trace function from wine.nim, which exposes
  ## all the arguments passed (`n` arguments total). Arguments are named
  ## argument1, argument2, etc...
  var args = newSeq[NimNode](n + 2)
  args[0] = bindSym("trace")
  args[1] = newStrLitNode("(" & "%p".repeat(n).join(", ") & ")")
  for i in 1..n:
    args[i+1] = newIdentNode("argument" & $i)
  newTree(nnkCall, args)

{.pop.}
