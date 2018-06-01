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

from strutils import toHex, `%`
from utils import strToAsm
from wrapper import wrapIfNecessary
from classparser import Classes, classes, readClasses
from tables import Table, initTable, pairs, `[]=`, `[]`, contains, keys
from wine import trace
from generators import genTraceCall, genArgs, genCall, genAsmHiddenCall
when hostCPU == "i386":
  from methods32 import eachInt, makePseudoMethods
when hostCPU == "amd64":
  from methods64 import eachInt, makePseudoMethods
when hostCPU notin ["amd64", "i386"]:
  error("Unsupported platform: " & hostCPU)
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

macro eachTable(sink: untyped): untyped =
  ## Generates vtables for classes obtained from steamclient.so and fills
  ## the `sink` with them. Also generates necessary pseudo methods.
  result = newStmtList()
  result.add quote do:
    `sink` = initTable[string, seq[MethodProc]]()
  let cc = readClasses()
  for k, v in cc.pairs:
    result.add(eachInt(k, v, sink))
  result.insert(0, makePseudoMethods())

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
    let tinfoaddr = cast[ptr MethodProc](cast[int](origin.vtable) -
                                         pointer.sizeof())
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

