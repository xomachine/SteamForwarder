type
  Class* = tuple
    ## The object without fields but with virtual methods memory representation
    vtable: pointer
  WrappedClass* = object
    ## Wrapped object memory representation
    vtable*: pointer
    origin*: ptr Class
  MethodProc = proc() {.cdecl.}

proc getVTableByStr*(name: string, address: pointer): pointer

from strutils import toHex, `%`
from utils import strToAsm, `+`, `-`
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

const classes = readClasses()
macro eachTable(sink: untyped): untyped =
  ## Generates vtables for classes obtained from steamclient.so and fills
  ## the `sink` with them. Also generates necessary pseudo methods.
  result = newStmtList()
  result.add quote do:
    `sink` = initTable[string, seq[MethodProc]]()
  for k, v in classes.pairs:
    result.add(eachInt(k, v, sink))
  result.insert(0, makePseudoMethods())

var vtables: Table[string, seq[MethodProc]]
eachTable(vtables)

proc getVTableByStr(name: string, address: pointer): pointer =
  ## Wraps object passed by given `address` and which has a given type `name`
  if name notin classes:
    return nil
  let origin = cast[ptr Class](address)
  let tinfoaddr = cast[ptr MethodProc](origin.vtable - pointer.sizeof())
  vtables[name][1] = tinfoaddr[]
  return vtables[name][2].addr

