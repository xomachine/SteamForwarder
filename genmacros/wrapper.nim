from tables import Table

proc wrapIfNecessary*(address: uint32): uint32 {.cdecl.}

from strutils import split, parseHexInt, repeat
from tables import initTable, `[]`, `[]=`, contains, values
from wine import trace, moduleByAddress, ModInfo, checkAddr
from classparser import readClasses
from vtables import wrapClass, fastWrap
from maps import getMMap, checkAddress, Flags

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
    return wrapClass(descstr, address)
  else:
#    trace("Unknown class %s! This should be reported!\n", descstr[0].unsafeAddr)
    return address

proc wrapIfClass(address: uint32, m: Slice[uint32]): uint32 =
  proc checker(a: uint32): bool =
    a in m
  wrapIfClass(address, checker)


proc wrapIfNecessary(address: uint32): uint32 =
  let already = fastWrap(address)
  if already > 0'u32:
    trace("Translating: %p -> %p\n", address, already)
    return already
  let curMap = getMMap()
  let affinity = curMap.checkAddress(address)
  if Flags.read in affinity.permissions:
    trace("Looks like %p - is valid address with %s at \"%s\"\n", address,
          affinity.permissions.repr.cstring, affinity.name.cstring)
    proc checker(a: uint32): bool =
      let af = curMap.checkAddress(a)
      if not (Flags.read in af.permissions and af.name == "steamclient.so"):
        trace("invalid address permissions: %p %s (related to \"%s\")\n", a,
              af.permissions.repr.cstring, af.name.cstring)
    return wrapIfClass(address, checker)
  return address
