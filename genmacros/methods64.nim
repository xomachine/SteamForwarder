from classparser import StackState

const pseudoMethodPrefix = "pseudoMethod"
proc eachInt*(k: string, a: seq[StackState], sink: NimNode): NimNode
  {.compileTime.}
proc makePseudoMethods*(): NimNode {.compileTime.}

from strutils import toHex
from utils import strToAsm, `+`
from generators import genArgs, genCall, genTraceCall, genAsmNativeCall64
import macros

static:
  var methods: set[uint8]

proc makePseudoMethod(stack: uint8): NimNode {.compileTime.} =
  result = newProc(newIdentNode(pseudoMethodPrefix & $stack))
  let nargs = max(int(stack div 4), 0)
  let meaningfull_args = genArgs(nargs)
  result[3] = newTree(nnkFormalParams, meaningfull_args)
  let mcall = genAsmNativeCall64("origin_method", nargs)
  let omethod = newIdentNode("origin_method")
  let tracecall = genTraceCall(nargs)
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
    trace("Origin: %p\n", obj.origin)
    trace("Origin vtable: %p\n", obj.origin.vtable)
    let methodptr = cast[ptr `procty`](obj.origin.vtable + mnum*sizeof(pointer))
    let `omethod` = methodptr[]
    trace("Method address: %p\n", `omethod`)
    let res = `mcall`
    trace("Result = %p\n", res)
    wrapIfNecessary(res)

proc makePseudoMethods(): NimNode =
  result = newStmtList()
  for m in methods:
    result.add(makePseudoMethod(m))

proc eachInt(k: string, a: seq[StackState], sink: NimNode): NimNode =
  result = newStmtList()
  let klit = newStrLitNode(k)
  result.add quote do:
    `sink`[`klit`] = newSeq[MethodProc](2)
  for i, v in a.pairs():
    methods.incl(v.depth.uint8)
    var tq = newNimNode(nnkTripleStrLit)
    tq.strVal = """
    # pop %rbp # necessary because compiler ignores noAsmStackFrame somehow
    # xchg %rcx, %rdx # it looks like wine already performs call conversion
    mov $0x""" & i.toHex & """, %r11 # The virtual method number
    jmp `""" & pseudoMethodPrefix & $v.depth & """`
"""
    let asmstmt = newTree(nnkAsmStmt, newEmptyNode(), tq)
    let methodname = newIdentNode("m" & k & $i)
    result.add quote do:
      proc `methodname`() {.asmNoStackFrame, cdecl.} =
        `asmstmt`
      add(`sink`[`klit`], `methodname`)
