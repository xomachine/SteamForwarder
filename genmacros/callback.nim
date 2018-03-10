
type
  WinCallback = object
    ## The CCallback object representation which got from wine side
    vtable: ptr array[3, pointer]
    flags: uint8
    icallback: int32
  WrappedCallback = object
    ## The CCallback object with replaced vtable
    vtable: pointer
    flags: uint8
    icallback: int32
    origin: ptr WinCallback

{.push cdecl.}

proc wrap*(address: uint32): uint32
proc unwrap*(address: uint32)
proc wrapToOrigin*(address: uint32)

from wine import trace
from tables import initTable, `[]`, `[]=`, contains, del, mvalues, Table
from maps import getMMap, checkAddress, MemMaps, Flags
from strutils import repeat
from utils import `+`, `-`, dumpMemoryRefs

## Here begin declarations of the virtual methods of the WrappedCallback
## object. Every method follows the thiscall calling conventions
## (actually cdecl, but they are similiar) of GNU compiler.
## Methods perform following:
## 1. Figuring out the original method of original object in vtable
## 2. Saving esp to prevent stack corruption by original method
## 3. Puting the original object reference to ecx and other arguments into
##    the stack to meet the MSVC thiscall convention
## 4. Calling the original method
## 5. Restoring esp as there was no the original method call at all

proc run(obj: ptr WrappedCallback, p: pointer) =
  ## First CCallback virtual method.
  trace("[%p](%p)\n", obj, p)
  let originRun = (obj.origin.vtable + 0)[]
  let originObj = obj.origin
  asm """
    mov %[obj], %%ecx
    push %[p]
    call %[mcall]
    ::[obj]"g"(`originObj`), [p]"g"(`p`), [mcall]"g"(`originRun`)
    :"eax", "ecx", "esp", "cc"
  """

proc run2(obj: ptr WrappedCallback, p: pointer, iofail: bool, scall: uint64) =
  ## Second CCallback virtual method
  trace("[%p](%p, %p, %p)\n", obj, p, iofail, scall)
  let originRun = (obj.origin.vtable + 4)[]
  let originObj = obj.origin
  asm """
    mov %[obj], %%ecx
    push %[scall]
    push %[iofail]
    push %[p]
    call %[originRun]
    ::[obj]"g"(`originObj`), [scall]"g"(`scall`), [iofail]"g"(`iofail`), [p]"g"(`p`), [originRun]"g"(`originRun`)
    : "ecx", "eax", "esp", "cc"
  """

proc getCallbackSizeBytes(obj: ptr WrappedCallback): int32 =
  ## Third CCallback virtual method. It does not need to call original
  ## getCallbackSizeBytes because it is used to obtain the actually passed to
  ## the linux side object.
  trace("[%p]()\n", obj)
  let originRun = (obj.origin.vtable + 8)[]
  let originObj = obj.origin
  asm """
    mov %[obj], %%ecx
    call %[mcall]
    mov %%eax, %[result]
    :[result]"=g"(`result`)
    :[obj]"g"(`originObj`), [mcall]"g"(`originRun`)
    :"eax", "ecx", "esp", "cc"
  """
  trace(" = %d\n", result)
{.pop.}

var vtable = [
  cast[pointer](run),
  cast[pointer](run2),
  cast[pointer](getCallbackSizeBytes)
]

var callbacks = initTable[uint32, WrappedCallback]()
  ## The registred wrapped callback objects list.

proc unwrap(address: uint32) =
  ## Removes the wrapped callback object from the registred list causing the GC
  ## to collect it. The address should point to the original CCallback object.
  trace("Deleting %p...", address)
  callbacks.del(address)
  trace("done\n")

proc wrapToOrigin(address: uint32) =
  ## Moves the CCallback object fields from wrapped one to original.
  ## The address should be a pointer to the WrappedCallback object.
  let wc = cast[ptr WrappedCallback](address)
  trace("before origin: %p, %p\n", wc.origin.flags, wc.origin.icallback)
  trace("before: %p, %p\n", wc.flags, wc.icallback)
  wc.origin.flags = wc.flags
  wc.origin.icallback = wc.icallback
  trace("before: %p, %p\n", wc.origin.flags, wc.origin.icallback)

proc wrap(address: uint32): uint32 =
  ## Wraps the CCallback got from wine side to the linux side equivalent.
  ## The address should be a pointer to the original(wine side) CCallback
  ## object. Returns the pointer to the WrappedCallback object.
  trace("Wrapping %p...", address)
  let origin = cast[ptr WinCallback](address)
  if address notin callbacks:
    callbacks[address] = WrappedCallback(vtable: vtable[0].addr,
                                         flags: origin.flags,
                                         icallback: origin.icallback,
                                         origin: origin)
    trace("wrapped as %p\n", callbacks[address].addr)
  else:
    callbacks[address].flags = origin.flags
    callbacks[address].icallback = origin.icallback
    trace("already wrapped\n")
  cast[uint32](callbacks[address].addr)
