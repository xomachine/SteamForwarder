proc wrapIfNecessary*(address: pointer): pointer {.cdecl.}
proc wrapIfNecessary*(value: uint64): uint64 {.cdecl.}

from strutils import split, parseHexInt, repeat
from wine import trace
from vtables import getVTableByStr, WrappedClass, Class
from stacktable import AddrTable, associate, convertToWrapped, convertToOrigin
from maps import getMMap, checkAddress, Flags, MemMaps
from utils import `+`, `-`

## The classes which already wrapped is stored in the `classAssociations`
var classAssociations: AddrTable[100, WrappedClass]

proc wrapIfClass(address: pointer, checker: proc(a: pointer): bool): pointer =
  ## Performs analyze of an object passed by `address` and tries to find
  ## its type info. `checker` is a procedure to check if address is valid
  ## Returns wrapped object if an analysis has shown that given object is
  ## known object and can be wrapped, returns `address` otherwise.
  while true:
    let vtableaddr = cast[ptr pointer](address)[]
    trace("Walking through the class...")
    trace("[%p]->", vtableaddr)
    if not checker(vtableaddr): break
    trace("vtable...")
    let tinfoaddr = cast[ptr pointer](vtableaddr-sizeof(pointer))[]
    trace("[%p]->", tinfoaddr)
    if not checker(tinfoaddr): break
    trace("typeinfo...")
    let strptraddr = cast[ptr pointer](tinfoaddr+sizeof(pointer))
    trace("[%p]->", tinfoaddr + sizeof(pointer))
    if not checker(strptraddr[]): break
    let descstr = $cast[cstring](strptraddr[]+2)
    trace("class name (%s)->", strptraddr[])
    let vtableptr = getVTableByStr(descstr, address)
    if vtableptr.isNil: break
    trace("wrapping with vtable at %p!\n", vtableptr)
    let wrapped = classAssociations.associate(address)
    wrapped.origin = cast[ptr Class](address)
    wrapped.vtable = vtableptr
    trace("Wrapped to %p\n", wrapped)
    return wrapped
  trace("invalid\n")
  return address

proc unwrapClass*(address: pointer): pointer =
  let origin = classAssociations.convertToOrigin(address)
  if origin.isNil(): address
  else: origin

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

proc checker(a: pointer): bool =
  let af = curMap.checkAddress(a)
  return Flags.read in af.permissions and af.name == "steamclient.so"

proc wrapIfNecessary(address: pointer): pointer =
  ## Checks if given `value` is address to an object that can be wrapped.
  ## Returns the wrapped object address if it is so or `value` otherwise
  let already = classAssociations.convertToWrapped(address)
  if not already.isNil():
    trace("Translating: %p -> %p\n", address, already)
    return already
  getMMap(curMap)
  let affinity = curMap.checkAddress(address)
  if Flags.read in affinity.permissions:
    trace("Looks like %p - is valid address with %s at \"%s\"\n", address,
          affinity.permissions.repr.cstring, affinity.name.cstring)
    return wrapIfClass(address, checker)
  return address
