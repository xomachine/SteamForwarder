type
  Class* = tuple
    ## The object without fields but with virtual methods memory representation
    vtable: pointer
  WrappedClass* = object
    ## Wrapped object memory representation
    vtable*: pointer
    origin*: ptr Class

proc getVTableByStr*(name: cstring, address: pointer): pointer

from classparser import Classes, readClasses
from methods import convertToAST, vtableByName
from wrapper import wrapIfNecessary
from wine import trace
from generators import genTraceCall, genArgs, genCall, genAsmHiddenCall
when hostCPU == "i386":
  from methods32 import makeAPIDesc
when hostCPU == "amd64":
  from methods64 import makeAPIDesc
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
macro makeVTables(sink: untyped): untyped =
  ## Generates vtables for classes obtained from steamclient.so and fills
  ## the `sink` with them. Also generates necessary pseudo methods.
  convertToAST(sink, makeAPIDesc(classes))

makeVTables(vtables)

proc getVTableByStr(name: cstring, address: pointer): pointer =
  ## Wraps object passed by given `address` and which has a given type `name`
  vtables.vtableByName(name)
