type
  Class* = tuple
    vtable: pointer
  WrappedClass* = object
    vtable*: pointer
    origin*: ptr Class
  MethodProc = proc() {.cdecl.}

proc wrapClass*(name: string, address: uint32): uint32

from strutils import toHex, `%`
from utils import strToAsm
from wrapper import wrapIfNecessary
from classparser import Classes, classes, readClasses
from tables import Table, initTable, pairs, `[]=`, `[]`, contains, keys
from wine import trace
from generators import genTraceCall, genArgs, genCall
import macros

const pseudoMethodPrefix = "pMethod"
static:
  var declared: set[uint8] = {}

proc makePseudoMethod(stack: uint8): NimNode {.compileTime.} =
  result = newProc(newIdentNode(pseudoMethodPrefix & $stack))
  result.addPragma(newIdentNode("cdecl"))
  let nargs = int(stack div 4) - 1
  let justargs = genArgs(nargs)
  let rmethod = newIdentNode("rmethod")
  var mcall = genCall("rmethod", nargs)
  let wclass = newIdentNode("wclass")
  mcall.insert(1, newDotExpr(wclass, newIdentNode("origin")))
  var callargs = justargs
  callargs.insert(newIdentDefs(newIdentNode("obj"), newIdentNode("pointer")), 1)
  let procty = newTree(nnkProcTy, newTree(nnkFormalParams, callargs),
                       newTree(nnkPragma, newIdentNode("cdecl")))
  var argseq = justargs
  argseq.insert(newIdentDefs(newIdentNode("raddr"), newIdentNode("uint32")), 1)
  argseq.insert(newIdentDefs(newIdentNode("prebp"), newIdentNode("uint32")), 1)
  argseq.insert(newIdentDefs(newIdentNode("obj"), newIdentNode("uint32")), 1)
  argseq.insert(newIdentDefs(newIdentNode("shift"), newIdentNode("uint32")), 1)
  var args = newTree(nnkFormalParams, argseq)
  result[3] = args
  let tracecall = genTraceCall(nargs)
  result.body = quote do:
    trace("Method No %d was called for obj=%p and return to %p\n",
          shift, obj, raddr)
    `tracecall`
    trace("\nPrevious ebp = %p\n", prebp)
    let `wclass` = cast[ptr WrappedClass](obj)
    trace("Origin = %p\n", `wclass`.origin)
    let vtableaddr = `wclass`.origin.vtable
    trace("Origins VTable = %p\n", vtableaddr)
    let maddr = cast[ptr `procty`](cast[uint32](vtableaddr) + shift*4)
    trace("Method address to call: %p\n", maddr)
    let `rmethod` = maddr[]
    trace("Method to call: %p\n", `rmethod`)
    let res = `mcall`
    trace("Result = %p\n", res)
    return wrapIfNecessary(res)
#  hint result.repr

proc eachInt(k: string, a: seq[int], sink: NimNode): NimNode {.compileTime.} =
  result = newStmtList()
  let klit = newStrLitNode(k)
  result.add quote do:
    `sink`[`klit`] = newSeq[MethodProc](1)
  for i, v in a.pairs():
    declared.incl(v.uint8)
    let asmcode = """
    push %ecx # push object reference
    push $0x""" & i.toHex & """ # push number of method inside the vtable
    call `""" & pseudoMethodPrefix & $v & """` # call the related pseudomethod
    add $0x4, %esp # remove number of method from the stack
    pop %ecx # pop object reference back
    pop %ebp # well compiller stores ebp regardless, so we need to pop it back
    ret $""" & $(v-4) &  """ # pop all args except the object itself(in ecx)
"""
    var tstr = newNimNode(nnkTripleStrLit)
    tstr.strVal = asmcode
    let asmstmt = newTree(nnkAsmStmt, newEmptyNode(), tstr)
    let methodname = newIdentNode("m" & k & $i)
    result.add quote do:
      proc `methodname` () {.asmNoStackFrame, noReturn, cdecl.} =
        `asmstmt`
      add(`sink`[`klit`], `methodname`)

macro eachTable(sink: untyped): untyped =
  result = newStmtList()
  result.add quote do:
    `sink` = initTable[string, seq[MethodProc]]()
  let cc = readClasses()
  for k, v in cc.pairs:
    result.add(eachInt(k, v, sink))
  for i in declared:
    result.insert(0, makePseudoMethod(i))

var vtables: Table[string, seq[MethodProc]]
eachTable(vtables)
var classAssociations = initTable[uint32, WrappedClass]()

proc wrapClass(name: string, address: uint32): uint32 =
  trace("Wrapping %p as %s...", address, name.cstring)
  if address notin classAssociations:
    trace("new class required\n")
    let origin = cast[ptr Class](address)
    let tinfoaddr = cast[ptr MethodProc](cast[uint32](origin.vtable) - 4)
    var shift = 0'u32
    while true:
      let maddr = cast[ptr uint32](cast[uint32](origin.vtable) + shift)[]
      trace("Method: %p\n", maddr)
      if maddr < 0x10000'u32:
        break
      shift += 4
    #for a in vtables[name]:
    #  trace("Wrapped method: %p\n", a)
    trace("Type info located at %p and equals %p\n", tinfoaddr, tinfoaddr[])
    vtables[name][0] = tinfoaddr[]
    trace("Type info placed at %p and equals %p\n", vtables[name][0].addr, vtables[name][0])
    let vtableptr = vtables[name][1].addr
    trace("Setting vtableptr to %p\n", vtableptr)
    classAssociations[address] = WrappedClass(vtable: vtableptr, origin: origin)
  else:
    trace("already wrapped\n")
  result = cast[uint32](classAssociations[address].addr)
  trace("Wrapped into class at %p\n", result)

