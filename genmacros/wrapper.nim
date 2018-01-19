from tables import Table

proc wrapIfNecessary*(address: uint32): uint32 {.cdecl.}
proc wrapIfNecessary*(value: uint64): uint64 {.cdecl.}

from strutils import split, parseHexInt, repeat
from tables import initTable, `[]`, `[]=`, contains, values
from wine import trace
from classparser import readClasses
from vtables import wrapClass, fastWrap
from maps import getMMap, checkAddress, Flags, MemMaps

const cls = readClasses()
proc wrapIfClass(address: uint32, checker: proc(a: uint32): bool): uint32 =
  ## Performs analyze of an object passed by `address` and tries to find
  ## its type info. `checker` is a procedure to check if address is valid
  ## Returns wrapped object if an analysis has shown that given object is
  ## known object and can be wrapped, returns `address` otherwise.
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
#   trace("Unknown class %s! This should be reported!\n", descstr[0].unsafeAddr)
    return address

proc wrapIfClass(address: uint32, m: Slice[uint32]): uint32 =
  ## Overloaded wrapIfClass with included
  ## simple checker procedure that checks if `address` in
  ## range `m`
  proc checker(a: uint32): bool =
    a in m
  wrapIfClass(address, checker)

var curMap: MemMaps

proc wrapIfNecessary(value: uint64): uint64 =
  ## Checkis if given `value` is address to an object that can be wrapped.
  ## Returns the wrapped object address if it is so or `value` otherwise
  ## This procedure preserves the edx part of uint64 or denies it if object
  ## was wrapped.
  let potencialAddress = cast[uint32](value)
  let potencialWrap = wrapIfNecessary(potencialAddress)
  if potencialAddress != potencialWrap:
    return potencialWrap
  return value
proc wrapIfNecessary(address: uint32): uint32 =
  ## Checkis if given `value` is address to an object that can be wrapped.
  ## Returns the wrapped object address if it is so or `value` otherwise
  let already = fastWrap(address)
  if already > 0'u32:
    trace("Translating: %p -> %p\n", address, already)
    return already
  getMMap(curMap)
  let affinity = curMap.checkAddress(address)
  if Flags.read in affinity.permissions:
    trace("Looks like %p - is valid address with %s at \"%s\"\n", address,
          affinity.permissions.repr.cstring, affinity.name.cstring)
    proc checker(a: uint32): bool =
      let af = curMap.checkAddress(a)
      if not (Flags.read in af.permissions and af.name == "steamclient.so"):
        #trace("invalid address permissions: %p %p (related to \"%s\")\n", a,
        #      af.permissions, af.name.cstring)
        return false
      return true
    return wrapIfClass(address, checker)
  return address
