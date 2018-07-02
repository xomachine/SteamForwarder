from classparser import StackState, Classes
from methods import MethodDesc, VTableDesc, APIDesc

const pseudoMethodPrefix = "pseudoMethod"
{.push, compileTime.}
proc makeMethodDesc(i: int, k: string, v: StackState): MethodDesc
proc makeVTableDesc(name: string, sstates: seq[StackState]): VTableDesc
proc makeAPIDesc*(classes: Classes): APIDesc
{.pop.}

from strutils import toHex
from utils import strToAsm, `+`
from tables import pairs
from generators import genArgs, genCall, genTraceCall, genAsmNativeCall64
import macros

proc makePseudoMethod(stack: uint8, hidden: bool): NimNode {.compileTime.} =
  result = newProc(newIdentNode(pseudoMethodPrefix &
                                (if hidden: "S" else: "") & $stack))
  let nargs = max(int(stack div 4), 1 + int(hidden))
  let meaningfull_args = genArgs(nargs)
  result[3] = newTree(nnkFormalParams, meaningfull_args)
  let mcall = genAsmNativeCall64("origin_method", nargs)
  let omethod = newIdentNode("origin_method")
  let tracecall = genTraceCall(nargs)
  let hdn = newLit(hidden)
  let procty = newTree(nnkProcTy, newTree(nnkFormalParams, meaningfull_args),
                       newTree(nnkPragma, newIdentNode("cdecl")))
  result.body = quote do:
    let mnum = 0
    asm """
    mov %%r11, %[mnum]
    :[mnum]"=g"(`mnum`)
    ::
"""
    trace("Calling method number %d\n", mnum)
    `tracecall`
    trace("\n")
    let obj = cast[ptr WrappedClass](argument1)
    let origin = obj.origin
    trace("Origin: %p\n", origin)
    trace("Origin vtable: %p\n", origin.vtable)
    let methodptr = cast[ptr `procty`](origin.vtable + mnum*sizeof(pointer))
    let `omethod` = methodptr[]
    trace("Method address: %p\n", `omethod`)
    let res = `mcall`
    trace("Result = %p\n", res)
    when `hdn`:
      let data = cast[ptr uint64](argument2)
      data[] = res
      cast[uint64](argument2)
    else:
      wrapIfNecessary(res)


proc makeMethodDesc(i: int, k: string, v: StackState): MethodDesc =
  var tq = newNimNode(nnkTripleStrLit)
  tq.strVal = """
  # pop %rbp # necessary because compiler ignores noAsmStackFrame somehow
  # xchg %rcx, %rdx # it looks like wine already performs call conversion
  mov $0x""" & i.toHex & """, %r11 # The virtual method number
  jmp `""" & pseudoMethodPrefix & (if v.swap: "S" else: "") & $v.depth & """`
"""
  result.body = newTree(nnkAsmStmt, newEmptyNode(), tq)
  result.name = "m" & k & $i

proc makeVTableDesc(name: string, sstates: seq[StackState]): VTableDesc =
  result.name = name
  result.methods = newSeq[MethodDesc]()
  for i, v in sstates.pairs():
    if v.swap:
      result.swapDepths.incl(v.depth.uint8)
    else:
      result.commonDepths.incl(v.depth.uint8)
    result.methods.add(makeMethodDesc(i, name, v))

proc makeAPIDesc*(classes: Classes): APIDesc =
  var common, swapped: set[uint8]
  result.vtables = newSeq[VTableDesc]()
  for k, v in classes.pairs():
    let vtable = makeVTableDesc(k, v)
    result.vtables.add(vtable)
    common = common + vtable.commonDepths
    swapped = swapped + vtable.swapDepths
  result.pseudomethods = newStmtList()
  for m in common:
    result.pseudomethods.add(makePseudoMethod(m, false))
  for m in swapped:
    result.pseudomethods.add(makePseudoMethod(m, true))
