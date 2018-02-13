from classparser import StackState

const pseudoMethodPrefix = "pseudoMethod"
proc eachInt*(k: string, a: seq[StackState], sink: NimNode): NimNode
  {.compileTime.}
proc makePseudoMethods*(): NimNode {.compileTime.}

from strutils import toHex
from utils import strToAsm, `+`
from generators import genArgs, genCall, genTraceCall
import macros

static:
  var methods: set[uint8]

proc makePseudoMethod(stack: uint8): NimNode {.compileTime.} =
  result = newProc(newIdentNode(pseudoMethodPrefix & $stack))
  let nargs = max(int(stack div 4), 0)
  let meaningfull_args = genArgs(nargs)
  result[3] = newTree(nnkFormalParams, meaningfull_args)
  let mcall = genCall("origin_method", nargs)
  let omethod = newIdentNode("origin_method")
  let tracecall = genTraceCall(nargs)
  let procty = newTree(nnkProcTy, newTree(nnkFormalParams, meaningfull_args),
                       newTree(nnkPragma, newIdentNode("cdecl")))
  result.body = quote do:
    let mnum = 0
    asm """
    mov %%r10, %[mnum]
    :[mnum]"=g"(`mnum`)
    ::
"""
    trace("Calling method number %d\n", mnum + 1)
    `tracecall`
    let `omethod` = cast[`procty`](argument1 + mnum*8)
    `mcall`

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
    pop %rbp # necessary because compiler ignores noAsmStackFrame somehow
    # xchg %rcx, %rdx # it looks like wine already performs call conversion
    mov $0x""" & i.toHex & """, %r10 # The virtual method number
    jmp `""" & pseudoMethodPrefix & $v.depth & """`
"""
    let asmstmt = newTree(nnkAsmStmt, newEmptyNode(), tq)
    let methodname = newIdentNode("m" & k & $i)
    result.add quote do:
      proc `methodname`() {.asmNoStackFrame, noReturn, cdecl.} =
        `asmstmt`
      add(`sink`[`klit`], `methodname`)
