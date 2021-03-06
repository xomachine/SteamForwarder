
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

proc wrap*(address: pointer): pointer
proc unwrap*(address: pointer)
proc wrapToOrigin*(address: pointer)

from wine import trace
from stacktable import AddrTable, convertToWrapped, removeByOrigin, associate
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
{.push, codegenDecl: "$# __attribute__((sysv_abi)) $#$#".}
proc run(obj: ptr WrappedCallback, p: pointer)
proc run2(obj: ptr WrappedCallback, p: pointer, iofail: bool, scall: uint64)
proc getCallbackSizeBytes(obj: ptr WrappedCallback): pointer
{.pop.}
proc run(obj: ptr WrappedCallback, p: pointer) =
  ## First CCallback virtual method.
  trace("[%p](%p)\n", obj, p)
  let originRun = (obj.origin.vtable + 0)[]
  let originObj = obj.origin
  when hostCPU == "i386":
    asm """
      mov %[obj], %%ecx
      push %[p]
      call %[mcall]
      ::[obj]"g"(`originObj`), [p]"g"(`p`), [mcall]"g"(`originRun`)
      :"eax", "ecx", "esp", "cc"
    """
  else:
    asm """
      mov %[obj], %%rcx
      mov %[p], %%rdx
      call %[mcall]
      ::[obj]"g"(`originObj`), [mcall]"g"(`originRun`), [p]"g"(`p`)
      :"cc", "rcx", "rdx"
    """

proc run2(obj: ptr WrappedCallback, p: pointer, iofail: bool, scall: uint64) =
  ## Second CCallback virtual method
  trace("[%p](%p, %p, %p)\n", obj, p, iofail, scall)
  let originRun = (obj.origin.vtable + pointer.sizeof)[]
  let originObj = obj.origin
  when hostCPU == "i386":
    asm """
      mov %[obj], %%ecx
      push %[scall]
      push %[iofail]
      push %[p]
      call %[originRun]
      ::[obj]"g"(`originObj`), [scall]"g"(`scall`), [iofail]"g"(`iofail`), [p]"g"(`p`), [originRun]"g"(`originRun`)
      : "ecx", "eax", "esp", "cc"
    """
  else:
    asm """
      mov %[obj], %%rcx
      mov %[p], %%rdx
      mov %[iofail], %%r8
      mov %[scall], %%r9
      call %[mcall]
      ::[obj]"g"(`originObj`), [mcall]"g"(`originRun`), [p]"g"(`p`), [iofail]"g"(`iofail`), [scall]"g"(`scall`)
      :"cc", "rcx", "rdx", "r8", "r9"
    """

proc getCallbackSizeBytes(obj: ptr WrappedCallback): pointer =
  ## Third CCallback virtual method. It does not need to call original
  ## getCallbackSizeBytes because it is used to obtain the actually passed to
  ## the linux side object.
  trace("[%p]()\n", obj)
  #let originRun = (obj.origin.vtable + pointer.sizeof()*2)[]
  #let originObj = obj.origin
  #asm """
  #  mov %[obj], %%ecx
  #  call %[mcall]
  #  mov %%eax, %[result]
  #  :[result]"=g"(`result`)
  #  :[obj]"g"(`originObj`), [mcall]"g"(`originRun`)
  #  :"eax", "ecx", "esp", "cc"
  #"""
  #trace(" = %d\n", result)
  trace("[%p]() = %d\n", obj, sizeof(WrappedCallback))
  return cast[pointer](sizeof(WrappedCallback))
{.pop.}

var vtable = [
  cast[pointer](run),
  cast[pointer](run2),
  cast[pointer](getCallbackSizeBytes)
]

var callbacks: AddrTable[100, WrappedCallback]
  ## The registred wrapped callback objects list.

proc unwrap(address: pointer) =
  ## Removes the wrapped callback object from the registred list causing the GC
  ## to collect it. The address should point to the original CCallback object.
  trace("Deleting %p...", address)
  callbacks.removeByOrigin(address)
  trace("done\n")

proc wrapToOrigin(address: pointer) =
  ## Moves the CCallback object fields from wrapped one to original.
  ## The address should be a pointer to the WrappedCallback object.
  let wc = cast[ptr WrappedCallback](address)
  wc.origin.flags = wc.flags
  wc.origin.icallback = wc.icallback

proc wrap(address: pointer): pointer =
  ## Wraps the CCallback got from wine side to the linux side equivalent.
  ## The address should be a pointer to the original(wine side) CCallback
  ## object. Returns the pointer to the WrappedCallback object.
  trace("Wrapping %p...", address)
  let already = callbacks.convertToWrapped(address)
  let origin = cast[ptr WinCallback](address)
  let wrapped =
    if already.isNil():
      let newwrapped = callbacks.associate(address)
      newwrapped.vtable = vtable[0].addr
      newwrapped.origin = origin
      trace("wrapped as %p\n", newwrapped)
      newwrapped
    else:
      trace("already wrapped\n")
      already
  wrapped.flags = origin.flags
  wrapped.icallback = origin.icallback
  return wrapped
