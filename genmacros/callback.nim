
type
  WinCallback = object
    vtable: ptr array[3, pointer]
    flags: uint8
    icallback: int32
  WrappedCallback = object
    vtable: pointer
    flags: uint8
    icallback: int32
    origin: ptr WinCallback

proc wrap*(address: uint32): uint32
proc unwrap*(address: uint32)
proc wrapToOrigin*(address: uint32)
proc sync_back*()
proc sync*()


from wine import trace
from tables import initTable, `[]`, `[]=`, contains, del, mvalues
from maps import getMMap, checkAddress, MemMaps, Flags
from strutils import repeat
from utils import `+`, `-`, dumpMemoryRefs


proc run(obj: ptr WrappedCallback, p: pointer) {.cdecl.} =
  trace("Callback %p run (%p)\n", obj, p)
  let originRun = (obj.origin.vtable + 0)[]
  let originObj = obj.origin
  asm """
    mov %[obj], %%ecx
    mov %%esp, %%ebx
    push %[p]
    call %[mcall]
    mov %%ebx, %%esp
    ::[obj]"g"(`originObj`), [p]"g"(`p`), [mcall]"g"(`originRun`)
    :"eax", "ebx", "ecx", "cc"
  """

proc run2(obj: ptr WrappedCallback, p: pointer, iofail: bool, scall: uint32) {.cdecl.} =
  trace("Callback %p run (%p, %p, %p)\n", obj, p, iofail, scall)
  let originRun = (obj.origin.vtable + 4)[]
  let originObj = obj.origin
  asm """
    mov %[obj], %%ecx
    mov %%esp, %%ebx
    push %[scall]
    push %[iofail]
    push %[p]
    call %[originRun]
    mov %%ebx, %%esp
    ::[obj]"g"(`originObj`), [scall]"g"(`scall`), [iofail]"g"(`iofail`), [p]"g"(`p`), [originRun]"g"(`originRun`)
    : "ecx", "ebx", "eax", "cc"
  """

proc getCallbackSizeBytes(obj: ptr WrappedCallback): int32 {.cdecl.} =
  trace("Callback %p run ()", obj)
  let originRun = (obj.origin.vtable + 8)[]
  let originObj = obj.origin
  asm """
    mov %[obj], %%ecx
    mov %%esp, %%ebx
    call %[originRun]
    mov %%eax, %[result]
    mov %%ebx, %%esp
    : [result]"=g"(`result`)
    : [obj]"g"(`originObj`), [originRun]"g"(`originRun`)
    : "eax", "ebx", "ecx", "cc"
  """
  trace(" = %p\n", result)

let vtable: VTable = [
  cast[pointer](run),
  cast[pointer](run2),
  cast[pointer](getCallbackSizeBytes)
]

var callbacks = initTable[uint32, WrappedCallback]()

proc unwrap(address: uint32) =
  trace("Deleting %p...", address)
  callbacks.del(address)
  trace("done\n")

proc wrap(address: uint32): uint32 =
  trace("Wrapping %p...", address)
  if address notin callbacks:
    let origin = cast[ptr WinCallback](address)
    callbacks[address] = WrappedCallback(vtable: vtable.unsafeAddr,
                                         flags: origin.flags,
                                         icallback: origin.icallback,
                                         origin: origin)
    trace("wrapped as %p\n", callbacks[address].addr)
  else:
    trace("already wrapped\n")
  cast[uint32](callbacks[address].addr)
