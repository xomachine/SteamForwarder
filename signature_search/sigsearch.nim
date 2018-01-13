from os import paramStr, paramCount
from osproc import execProcess
from tables import initTable, `[]`, `[]=`, contains, del, `$`
from strutils import splitLines, parseHexInt, toHex, splitWhitespace, find,
                     count, contains, split, strip, parseInt, isDigit
from spcounter import readProcedure
from libs.bfd import bfd_open, bfd_close, bfd_init, bfd_get_section_by_name,
                getContent, bfd_count_sections, init, bfd_get_start_address
from libs.disasm import initDisasm

proc addr2Pattern(address: Natural): string =
  var a: uint32 = address.uint32
  let cs = cast[cstring](a.addr)
  result = $cs

iterator methods(start: ptr char, bounds: Slice[uint32]): uint32 =
  let reinterpreted = cast[ptr array[0, uint32]](start)
  var shift = 0
  var offset = 0'u32
  while(offset = reinterpreted[shift]; offset in bounds):
    yield offset.uint32
    shift += 1

assert(paramCount() > 0)
bfd_init()
let filename = paramStr(1)
let file = bfd_open(filename, nil)
if not file.init():
  quit "Failed to open!"
let strSegment = file.bfd_get_section_by_name(".rodata")
let textSegment = file.bfd_get_section_by_name(".text")
let vtableSegment = file.bfd_get_section_by_name(".data.rel.ro")
if strSegment.isNil or vtableSegment.isNil:
  discard file.bfd_close()
  quit "Failed to find section!"
let textSegmentData = file.getContent(textSegment)
let vtableSegmentData = file.getContent(vtableSegment)
let strSegmentData = file.getContent(strSegment)
var disasmer = file.initDisasm(textSegment, textSegmentData[0].unsafeAddr)
let textBounds = Slice[uint32](a: textSegment.vma,
                               b: textSegment.vma+textSegment.size)
proc searchPattern(pattern: string) =
  var offset = -1
  while (offset = strSegmentData.find(pattern, offset+1); offset >= 0):
    let realoffset = offset + strSegment.vma.int - 2
    var classname = $cast[cstring](strSegmentData[offset].unsafeAddr)
    if not(strSegmentData[offset-1].isDigit and
           strSegmentData[offset-2].isDigit):
      continue
    var size = $cast[cstring](strSegmentData[offset-2].unsafeAddr)
    size.setLen(2)
    stderr.writeLine("Size: " & size)
    classname.setLen(size.parseInt)
    stderr.writeLine(classname & " found at " & realoffset.toHex())
    let strPattern = realoffset.addr2Pattern()
    let tinfo = vtableSegmentData.find(strPattern) + vtableSegment.vma.int - 4
    stderr.writeLine("Found TInfo at: " & tinfo.toHex())
    let vtPattern = tinfo.addr2Pattern()
    let vtable = vtableSegmentData.find(vtPattern) + 4
    if vtable < 4:
      continue
    stderr.writeLine("Found VTable at: " &
                     (vtable + vtableSegment.filepos.int).toHex())
    echo "!", classname, ":", toHex(vtable-4)
    for madr in methods(vtableSegmentData[vtable].unsafeAddr, textBounds):
      let depth = readProcedure(disasmer, madr)
      if depth > 42:
        echo depth
        return
      stderr.writeLine("Method at: " & madr.toHex() &
                       " dives into stack on depth: " & $depth)
      echo $max(depth, 4)
      # 4 is minimal depth because even an empty method receives its object as
      # the first argument
const classPattern = "CAdapterSteam"
const classPattern2 = "CSteam"
searchPattern(classPattern)
searchPattern(classPattern2)
discard bfd_close(file)
