from classparser import StackState
type
  Class* = tuple
    ## The object without fields but with virtual methods memory representation
    vtable: pointer
  WrappedClass* = object
    ## Wrapped object memory representation
    vtable*: pointer
    origin*: ptr Class
  MethodProc = proc() {.cdecl.}

proc fastUnWrap*(address: pointer): pointer
proc wrapClass*(name: string, address: pointer): pointer
proc fastWrap*(address: pointer): pointer
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

## Typical method call of wrapped class.
## 1. Method from wrapped object vtable pushes to the stack object reference
##    from the ecx register and vtable shift to find the original method
## 2. Method from wrapped object calls pseudo method for corresponding
##    arguments number and inmemory return if necessary
## 3. Pseudo method performs all debug prints, finds and makes the actual method
##    call for original object using the information pushed by wrapped method
## 4. Pseudo method returns to the wrapped method which performs the stack
##    cleanup and returns back to caller.
## This complicated structure needed to minimize amount assembler code.
## In fact pseudo methods written in Nim with little assembler part for
## inmemory return case, while the wrapped method is totaly written in
## assembler. This approach also reduces the library size by concentration
## debug calls in few pseudo methods which are not dependent of object or method
## instead of repeating the `trace` calls in each wrapped method

const pseudoMethodPrefix = "pMethod" # Just a name prefix for pseudo methods
static:
  ## Compile time variables to count which pseudo methods needed to be generated
  var declared: set[uint8] = {}
  var swpdeclared: set[uint8] = {}

proc makePseudoMethod(stack: uint8, swp: bool): NimNode {.compileTime.} =
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
      return cast[uint64](hidden)
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

macro eachTable(sink: untyped): untyped =
  ## Generates vtables for classes obtained from steamclient.so and fills
  ## the `sink` with them. Also generates necessary pseudo methods.
  result = newStmtList()
  result.add quote do:
    `sink` = initTable[string, seq[MethodProc]]()
  let cc = readClasses()
  for k, v in cc.pairs:
    result.add(eachInt(k, v, sink))
  when hostCPU == "i386":
    for i in declared:
      result.insert(0, makePseudoMethod(i, false))
    for i in swpdeclared:
      result.insert(0, makePseudoMethod(i, true))

var vtables: Table[string, seq[MethodProc]]
eachTable(vtables)
## The classes which already wrapped is stored in the `classAssociations`
var classAssociations = initTable[pointer, WrappedClass]()

proc fastUnWrap(address: pointer): pointer =
  ## Checks if `address` already in classAssocations and returns the
  ## unwrapped object address if it is so or original `address` in other case
  for k in classAssociations.keys():
    if classAssociations[k].addr == address:
      return k
  return address

proc fastWrap(address: pointer): pointer =
  ## Checks if `address` already in classAssocations and returns the
  ## wrapped object address if it is so or 0 in other case
  if address in classAssociations:
    classAssociations[address].addr
  else:
    nil

proc wrapClass(name: string, address: pointer): pointer =
  ## Wraps object passed by given `address` and which has a given type `name`
  trace("Wrapping %p as %s...", address, name.cstring)
  if address notin classAssociations:
    trace("new class required\n")
    let origin = cast[ptr Class](address)
    let tinfoaddr = cast[ptr MethodProc](cast[uint](origin.vtable) - 4)
    #var shift = 0'u32
    #while true:
    #  let maddr = cast[ptr uint](cast[uint](origin.vtable) + shift)[]
    #  trace("Method: %p\n", maddr)
    #  if maddr < 0x10000'u32 or maddr > 0xffff0000'u32:
    #    break
    #  shift += 4
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
  result = classAssociations[address].addr
  trace("Wrapped into class at %p\n", result)

