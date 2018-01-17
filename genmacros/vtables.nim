from classparser import StackState
type
  Class* = tuple
    vtable: pointer
  WrappedClass* = object
    vtable*: pointer
    origin*: ptr Class
  MethodProc = proc() {.cdecl.}

proc wrapClass*(name: string, address: uint32): uint32
proc fastWrap*(address: uint32): uint32
proc eachInt(k: string, a: seq[StackState], sink: NimNode): NimNode
  {.compileTime.}

from strutils import toHex, `%`
from utils import strToAsm
from wrapper import wrapIfNecessary
from classparser import Classes, classes, readClasses
from tables import Table, initTable, pairs, `[]=`, `[]`, contains, keys
from wine import trace
from generators import genTraceCall, genArgs, genCall, genAsmHiddenCall
import macros

const pseudoMethodPrefix = "pMethod"
static:
  var declared: set[uint8] = {}
  var swpdeclared: set[uint8] = {}

proc makePseudoMethod(stack: uint8, swp: bool): NimNode {.compileTime.} =
  result = newProc(newIdentNode(pseudoMethodPrefix & $stack &
                                (if swp:"S" else: "")))
  result.addPragma(newIdentNode("cdecl"))
  let nargs = max(int(stack div 4) - 1 - int(swp), 0)
  let justargs = genArgs(nargs)
  let origin = newIdentNode("origin")
  let rmethod = newIdentNode("rmethod")
  var mcall = genCall("rmethod", nargs)
  mcall.insert(1, origin)
  var argseq = @[
    newIdentNode("uint64"),
    newIdentDefs(newIdentNode("shift"), newIdentNode("uint32")),
    newIdentDefs(newIdentNode("obj"), newIdentNode("uint32")),
    newIdentDefs(newIdentNode("prebp"), newIdentNode("uint32")),
    newIdentDefs(newIdentNode("raddr"), newIdentNode("uint32")),
  ]
  if swp:
    argseq.add(newIdentDefs(newIdentNode("hidden"), newIdentNode("pointer")))
  argseq &= justargs[1..^1]
  var callargs = @[
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
    let asmcall = genAsmHiddenCall("rmethod", "origin", nargs)
    result.body.add quote do:
      trace("Hidden before = %p (%p) \n", hidden, cast[ptr cint](hidden)[])
      `asmcall`
      trace("Hidden result = %p (%p) \n", hidden, cast[ptr cint](hidden)[])
      return cast[uint64](hidden)
  else:
    result.body.add quote do:
      let res = `mcall`
      trace("Result = %p\n", res)
      return wrapIfNecessary(res)

proc eachInt(k: string, a: seq[StackState], sink: NimNode): NimNode =
  result = newStmtList()
  let klit = newStrLitNode(k)
  result.add quote do:
    `sink`[`klit`] = newSeq[MethodProc](2)
  for i, v in a.pairs():
    if v.swap:
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
    ret $""" & $(v.depth-4) &  """ # pop all args except the object itself(in ecx)
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
    result.insert(0, makePseudoMethod(i, false))
  for i in swpdeclared:
    result.insert(0, makePseudoMethod(i, true))

var vtables: Table[string, seq[MethodProc]]
eachTable(vtables)
var classAssociations = initTable[uint32, WrappedClass]()

proc fastWrap(address: uint32): uint32 =
  if address in classAssociations:
    cast[uint32](classAssociations[address].addr)
  else:
    0

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
      if maddr < 0x10000'u32 or maddr > 0xffff0000'u32:
        break
      shift += 4
    #for a in vtables[name]:
    #  trace("Wrapped method: %p\n", a)
    trace("Type info located at %p and equals %p\n", tinfoaddr, tinfoaddr[])
    vtables[name][1] = tinfoaddr[]
    trace("Type info placed at %p and equals %p\n", vtables[name][1].addr, vtables[name][1])
    let vtableptr = vtables[name][2].addr
    trace("Setting vtableptr to %p\n", vtableptr)
    classAssociations[address] = WrappedClass(vtable: vtableptr, origin: origin)
  else:
    trace("already wrapped\n")
  result = cast[uint32](classAssociations[address].addr)
  trace("Wrapped into class at %p\n", result)

