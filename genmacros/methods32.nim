import macros
from classparser import StackState

const pseudoMethodPrefix* = "pMethod" # Just a name prefix for pseudo methods
proc makePseudoMethods*(): NimNode {.compileTime.}
proc eachInt*(k: string, a: seq[StackState], sink: NimNode): NimNode
  {.compileTime.}
proc makePseudoMethod(stack: uint8, swp: bool): NimNode {.compileTime.}

from generators import genArgs, genCall, genTraceCall, genAsmHiddenCall
from strutils import toHex

static:
  ## Compile time variables to count which pseudo methods needed to be generated
  var declared: set[uint8] = {}
  var swpdeclared: set[uint8] = {}

proc makePseudoMethods(): NimNode =
  ## Generates a both of swapped and non-swapped pseudo methods according
  ## to their invocations.
  result = newStmtList()
  for i in declared:
    result.add(makePseudoMethod(i, false))
  for i in swpdeclared:
    result.add(makePseudoMethod(i, true))

proc makePseudoMethod(stack: uint8, swp: bool): NimNode =
  ## Generates a pseudo method for stack depth of `stack`.
  ## If `swp` is true, the generated method should perform inmemory return.
  ## This pseudo method generator is valid only for 32-bit context!
  result = newProc(newIdentNode(pseudoMethodPrefix & $stack &
                                (if swp:"S" else: "")))
  result.addPragma(newIdentNode("cdecl"))
  let nargs = max(int(stack div 4) - 1 - int(swp), 0)
  let justargs = genArgs(nargs)
  let origin = newIdentNode("origin")
  let rmethod = newIdentNode("rmethod")
  var mcall = genCall("rmethod", nargs) # The origin method call
  mcall.insert(1, origin)
  var argseq = @[ # The arguments of pseudo method include
    newIdentNode("uint64"), # return value if uint64 to prevent edx eating
    newIdentDefs(newIdentNode("shift"), newIdentNode("uint32")),
      # shift in vtable of original method
    newIdentDefs(newIdentNode("obj"), newIdentNode("uint32")),
      # reference to and object
    newIdentDefs(newIdentNode("prebp"), newIdentNode("uint32")),
      # ebp of caller (not for purpose, just lies here)
    newIdentDefs(newIdentNode("raddr"), newIdentNode("uint32")),
      # return address to method caller (also just lies here)
  ]
  if swp:
    # in method returns inmemory, the hidden memory pointer is inserted
    # before actual arguments
    argseq.add(newIdentDefs(newIdentNode("hidden"), newIdentNode("pointer")))
  # and the actual arguments after
  argseq &= justargs[1..^1]
  var callargs = @[ # the linux method call arguments
    newIdentNode("uint64"),
    newIdentDefs(newIdentNode("obj"), newIdentNode("uint32")),
  ] & justargs[1..^1]
  let procty = newTree(nnkProcTy, newTree(nnkFormalParams, callargs),
                       newTree(nnkPragma, newIdentNode("cdecl")))
  let args = newTree(nnkFormalParams, argseq)
  result[3] = args
  let tracecall = genTraceCall(nargs)
  result.body = quote do:
    trace("Method No %d was called for obj=%p and return to %p\n",
          shift, obj, raddr)
    `tracecall`
    trace("\nPrevious ebp = %p\n", prebp)
    let wclass = cast[ptr WrappedClass](obj)
    let `origin` = cast[uint32](wclass.origin)
    trace("Origin = %p\n", `origin`)
    let vtableaddr = wclass.origin.vtable
    trace("Origins VTable = %p\n", vtableaddr)
    let maddr = cast[ptr `procty`](cast[uint32](vtableaddr) + shift*4)
    trace("Method address to call: %p\n", maddr)
    let `rmethod` = maddr[]
    trace("Method to call: %p\n", `rmethod`)
  if swp:
    # for inmemory return we need some assembler magic
    let asmcall = genAsmHiddenCall("rmethod", "origin", nargs)
    result.body.add quote do:
      trace("Hidden before = %p (%p) \n", hidden, cast[ptr cint](hidden)[])
      `asmcall`
      trace("Hidden result = %p (%p) \n", hidden, cast[ptr cint](hidden)[])
      return cast[uint32](hidden)
    ## the inmemory returns are never being objects that require wrapping
  else:
    # the return value may also be an object and needs to be wrapped
    # if necessary
    result.body.add quote do:
      let res = `mcall`
      trace("Result = %p\n", res)
      return wrapIfNecessary(res)

proc eachInt(k: string, a: seq[StackState], sink: NimNode): NimNode =
  ## Generates wrapped methods for WrappedClass's vtable by given in `a`
  ## stack information. Places methods to the `sink`s entry with key `k`
  result = newStmtList()
  let klit = newStrLitNode(k)
  result.add quote do:
    `sink`[`klit`] = newSeq[MethodProc](2)
  for i, v in a.pairs():
    if v.swap: # counts what pseudo methods involved to generate them after
      swpdeclared.incl(v.depth.uint8)
    else:
      declared.incl(v.depth.uint8)
    let asmcode = """
    push %ecx # push object reference
    push $0x""" & i.toHex & """ # push number of method inside the vtable
    call `""" & pseudoMethodPrefix & $v.depth & (if v.swap: "S" else: "") &
      """` # call the related pseudomethod
    add $0x4, %esp # remove number of method from the stack
    pop %ecx # pop object reference back
    pop %ebp # well compiller stores ebp regardless, so we need to pop it back
    ret $""" & $(v.depth-4) &  """ # clean arguments from the stack and return
"""
    var tstr = newNimNode(nnkTripleStrLit)
    tstr.strVal = asmcode
    let asmstmt = newTree(nnkAsmStmt, newEmptyNode(), tstr)
    let methodname = newIdentNode("m" & k & $i)
    result.add quote do:
      proc `methodname` () {.asmNoStackFrame, noReturn, cdecl.} =
        `asmstmt`
      add(`sink`[`klit`], `methodname`)
