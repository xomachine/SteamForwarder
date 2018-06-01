from tables import Table

proc wrapIfNecessary*(address: pointer): pointer {.cdecl.}
proc wrapIfNecessary*(value: uint64): uint64 {.cdecl.}

from strutils import split, parseHexInt, repeat
from tables import initTable, `[]`, `[]=`, contains, values
from wine import trace
from classparser import readClasses
from vtables import wrapClass, fastWrap
from maps import getMMap, checkAddress, Flags, MemMaps
from utils import `+`, `-`

const cls = readClasses()
proc wrapIfClass(address: pointer, checker: proc(a: pointer): bool): pointer =
  ## Performs analyze of an object passed by `address` and tries to find
  ## its type info. `checker` is a procedure to check if address is valid
  ## Returns wrapped object if an analysis has shown that given object is
  ## known object and can be wrapped, returns `address` otherwise.
  let vtableaddr = cast[ptr pointer](address)[]
  trace("Walking through the class...")
  trace("[%p]->", vtableaddr)
  if not checker(vtableaddr):
    trace("invalid\n")
    return address
  trace("vtable...")
  let tinfoaddr = cast[ptr pointer](vtableaddr-sizeof(pointer))[]
  trace("[%p]->", tinfoaddr)
  if not checker(tinfoaddr):
    trace("invalid\n")
    return address
  trace("typeinfo...")
  let strptraddr = cast[ptr pointer](tinfoaddr+sizeof(pointer))
  trace("[%p]->", tinfoaddr + sizeof(pointer))
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

proc wrapIfClass(address: pointer, m: Slice[pointer]): pointer =
  ## Overloaded wrapIfClass with included
  ## simple checker procedure that checks if `address` in
  ## range `m`
  proc checker(a: pointer): bool =
    a in m
  wrapIfClass(address, checker)

var curMap: MemMaps

proc wrapIfNecessary(value: uint64): uint64 =
  ## Checkis if given `value` is address to an object that can be wrapped.
  ## Returns the wrapped object address if it is so or `value` otherwise
  ## This procedure preserves the edx part of uint64 or denies it if object
  ## was wrapped.
  let potencialAddress = cast[pointer](value)
  let potencialWrap = wrapIfNecessary(potencialAddress)
  if potencialAddress != potencialWrap:
    return cast[uint64](potencialWrap)
  return value
proc wrapIfNecessary(address: pointer): pointer =
  ## Checkis if given `value` is address to an object that can be wrapped.
  ## Returns the wrapped object address if it is so or `value` otherwise
  let already = fastWrap(address)
  if already != nil:
    trace("Translating: %p -> %p\n", address, already)
    return already
  getMMap(curMap)
  let affinity = curMap.checkAddress(address)
  if Flags.read in affinity.permissions:
    trace("Looks like %p - is valid address with %s at \"%s\"\n", address,
          affinity.permissions.repr.cstring, affinity.name.cstring)
    proc checker(a: pointer): bool =
      let af = curMap.checkAddress(a)
      if not (Flags.read in af.permissions and af.name == "steamclient.so"):
        #trace("invalid address permissions: %p %p (related to \"%s\")\n", a,
        #      af.permissions, af.name.cstring)
        return false
      return true
    return wrapIfClass(address, checker)
  return address
