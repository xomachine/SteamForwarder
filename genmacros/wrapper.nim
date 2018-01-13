from tables import Table

proc wrapIfNecessary*(address: uint32): uint32 {.cdecl.}

from strutils import split, parseHexInt, repeat
from tables import initTable, `[]`, `[]=`, contains, values
from wine import trace, moduleByAddress, ModInfo, checkAddr
from classparser import readClasses
from vtables import wrapClass, fastWrap

let cls = readClasses()

proc wrapIfClass(address: uint32, checker: proc(a: uint32): bool): uint32 =
  let vtableaddr = cast[ptr uint32](address)[]
  trace("Walking through the class...")
  trace("[%p]->", vtableaddr)
  if not checker(vtableaddr):
    trace("invalid\n")
    return address
  trace("vtable...")
  let tinfoaddr = cast[ptr uint32](vtableaddr-4)[]
  trace("[%p]->", tinfoaddr)
  if not checker(tinfoaddr):
    trace("invalid\n")
    return address
  trace("typeinfo...")
  let strptraddr = cast[ptr uint32](tinfoaddr+4)
  trace("[%p]->", tinfoaddr + 4)
  if not checker(strptraddr[]):
    trace("invalid\n")
    return address
  let descstr = $cast[cstring](strptraddr[]+2)
  trace("class name (%s)\n", strptraddr[])
  if descstr in cls:
    wrapClass(descstr, address)
  else:
#    trace("FIXME: %s is unknown signature! You should definetely report it!\n",
#          strptraddr[])
    address

proc wrapIfClass(address: uint32, m: Slice[uint32]): uint32 =
  proc checker(a: uint32): bool =
    a in m
  wrapIfClass(address, checker)

proc wrapIfNecessary(address: uint32): uint32 =
  let already = fastWrap(address)
  if already > 0'u32:
    trace("Translating: %p -> %p\n", address, already)
    return already
  if address > 0x10000'u32:
    let m = moduleByAddress(address)
    let endaddr = m.baseOfImage + m.imageSize
    let name = cast[cstring](m.moduleName.unsafeAddr)
    if name.len > 0:
      trace("Found module %s at address %p in range %p-%p(%p)\n", name, address,
            m.baseOfImage, endaddr, m.imageSize)
    if name == "steamclient.so":
      let slice = Slice[uint32](a: m.baseOfImage, b: endaddr)
      return wrapIfClass(address, slice)
    if checkAddr(address, 4):
      proc checker(a: uint32): bool =
        checkAddr(a, 4)
      return wrapIfClass(address, checker)
  return address
