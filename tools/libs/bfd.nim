
{.passL: "-lbfd".}
{.passC: "-DPACKAGE".}

const BFS_GLOBAL* = (1 shl 1)
const BFS_DEBUGGING* = (1 shl 3)

type
  BFDBool* = cint
  BFDImpl* {.importc: "bfd", header: "<bfd.h>", incompleteStruct.} = object
  BFD* = ptr BFDImpl
  SectionImpl* {.importc: "asection", header: "<bfd.h>", incompleteStruct.} = object
    vma*: cuint
    size*: cuint
    rawsize*: cuint
    filepos*: cuint
  SymbolImpl {.importc: "asymbol", header: "<bfd.h>", incompleteStruct.} = object
    name*: cstring
    value*: cuint
    flags*: cint
  Symbol* = ptr SymbolImpl
    
  Section* = ptr SectionImpl
  SectionInfo* = tuple
    fileStart: Natural
    memStart: Natural
    size: Natural

proc bfd_init*() {.importc, header: "<bfd.h>".}
proc bfd_get_start_address*(b: BFD): cuint {.importc, header: "<bfd.h>".}
proc bfd_open*(filename, target: cstring, fd: FileHandle): BFD
  {.importc: "bfd_fdopenr", header: "<bfd.h>".}
proc bfd_open*(filename, target: cstring): BFD
  {.importc: "bfd_openr", header: "<bfd.h>".}
proc bfd_get_linker_section*(b: BFD, name: cstring): Section
  {.importc, header: "<bfd.h>".}
proc bfd_close*(b: BFD): BFDBool {.importc, header: "<bfd.h>".}
proc bfd_get_section_by_name*(b: BFD, name: cstring): Section
  {. importc, header: "<bfd.h>".}
proc bfd_get_section_contents*(b: BFD, asec: Section, location: pointer,
                               offset: cuint, count: cuint): BFDBool
  {.importc, header: "<bfd.h>".}
proc readSymbolTable*(b: BFD): seq[Symbol] =
  let tablesize: clong = 0
  {.emit: [tablesize, " = bfd_get_symtab_upper_bound(", b, ");"].}
  let archsize: cint = 32
  {.emit: [archsize, " = bfd_get_arch_size(", b, ");"].}
#  echo "Required to allocate ", tablesize, " in ", archsize, " arch"
  if tablesize < 0:
    raise newException(Exception,
      "Incorrect upperbound value obtained from BFD library")
  elif tablesize == 0:
    return @[]
  result = newSeq[Symbol](tablesize div (archsize div 8))
  let readsize: clong = 0
  {.emit: [readsize, " = bfd_canonicalize_symtab(", b, ", ", result[0].addr,
           ");"].}
#  echo "Read ", readsize, " symbols"
  result.setLen(readsize)
proc getContent*(b: BFD, s: Section, start: cuint = 0, size: cuint = 0): string =
  let realsize = if size == 0: s.size else: size
  result = newString(realsize)
  {.emit: ["bfd_get_section_contents(", b, ", ", s, ", ", result[0].addr, ", ",
           start, ", ", realsize, ");"].}

proc bfd_count_sections*(b: BFD): cuint {.importc, header:"<bfd.h>".}
proc init*(b: BFD): bool =
  let res: BFDBool = 0
  {.emit: [res, " = bfd_check_format(", b, ", bfd_object);"].}
  if res == 0:
    discard b.bfd_close()
    false
  else:
    true

proc getSectionInfo*(s: Section): SectionInfo =
  result.memStart = s.vma
  result.fileStart = s.filepos
  result.size = s.rawsize
