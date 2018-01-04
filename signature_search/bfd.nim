
{.passL: "-lbfd".}
{.passC: "-DPACKAGE".}

type
  BFDBool* = cint
  BFDImpl* {.importc: "bfd", header: "<bfd.h>", incompleteStruct.} = object
  BFD* = ptr BFDImpl
  SectionImpl* {.importc: "asection", header: "<bfd.h>", incompleteStruct.} = object
    vma*: cuint
    size*: cuint
    rawsize*: cuint
    filepos*: cuint

    
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
proc getContent*(b: BFD, s: Section, start: cuint = 0, size: cuint = 0): string =
  let realsize = if size == 0: s.size else: size
  result = newString(realsize)
  {.emit: ["bfd_get_section_contents(", b, ", ", s, ", ", result[0].addr, ", ",
           start, ", ", realsize, ");"].}

proc bfd_count_sections*(b: BFD): cuint {.importc, header:"<bfd.h>".}
proc init*(b: BFD): bool =
  var res: BFDBool
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
