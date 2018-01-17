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

{.push cdecl.}

proc wrap*(address: uint32): uint32
proc unwrap*(address: uint32)
proc wrapToOrigin*(address: uint32)
proc sync_back*()
proc sync*()


from wine import trace
from tables import initTable, `[]`, `[]=`, contains, del, mvalues, Table
#from nogctable import initTable, `[]`, `[]=`, contains, del, optimize, mvalues
from maps import getMMap, checkAddress, MemMaps, Flags
from strutils import repeat
from utils import `+`, `-`, dumpMemoryRefs


proc run(obj: ptr WrappedCallback, p: pointer) =
  trace("[%p](%p)\n", obj, p)
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

proc run2(obj: ptr WrappedCallback, p: pointer, iofail: bool, scall: uint64) =
  trace("[%p](%p, %p, %p)\n", obj, p, iofail, scall)
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

proc getCallbackSizeBytes(obj: ptr WrappedCallback): int32 =
  trace("[%p]() = %d\n", obj, sizeof(WrappedCallback))
  return sizeof(WrappedCallback).int32
{.pop.}

var vtable = [
  cast[pointer](run),
  cast[pointer](run2),
  cast[pointer](getCallbackSizeBytes)
]


var callbacks = initTable[uint32, WrappedCallback]()
#var callbacks: Table[uint32, WrappedCallback]

proc sync() =
  discard
  #for c in callbacks.mvalues:
  #  if c.flags != c.origin.flags or  c.icallback != c.origin.icallback:
  #    trace("Status: %s\n", c.repr.cstring)
  #    quit(1)


proc sync_back() =
  discard
  #for c in callbacks.mvalues:
  #  if c.origin.flags != c.flags or c.origin.icallback != c.icallback:
  #    trace("Status: %s\n", c.repr.cstring)
  #    quit(1)

proc unwrap(address: uint32) =
  trace("Deleting %p...", address)
  callbacks.del(address)
  #if callbacks.size > 1024:
  #  callbacks.optimize()
  trace("done\n")

proc wrapToOrigin(address: uint32) =
  let wc = cast[ptr WrappedCallback](address)
  trace("before origin: %p, %p\n", wc.origin.flags, wc.origin.icallback)
  trace("before: %p, %p\n", wc.flags, wc.icallback)
  wc.origin.flags = wc.flags
  wc.origin.icallback = wc.icallback
  trace("before: %p, %p\n", wc.origin.flags, wc.origin.icallback)

proc wrap(address: uint32): uint32 =
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
