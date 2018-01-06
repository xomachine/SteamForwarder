from os import paramStr, paramCount
from osproc import execProcess
from strutils import splitLines, parseHexInt, toHex, splitWhitespace, find,
                     isDigit, count, contains, split, strip
from bfd import bfd_open, bfd_close, bfd_init, bfd_get_section_by_name,
                getContent, bfd_count_sections, init, bfd_get_start_address
from disasm import initDisasm, parseInstructions, Disasmer
from tables import initTable, `[]`, `[]=`, contains, del, `$`

proc addr2Pattern(address: Natural): string =
  var a: uint32 = address.uint32
  let cs = cast[cstring](a.addr)
  result = $cs

proc parseEA(s: string): tuple[register: string, offset: int] =
  let splitted = s.split({'(', ')'})
  result.register = splitted[1]
  result.offset =
    if splitted[0].len == 0 or splitted[0][0] == '%':
      0
    elif splitted[0][0] == '-':
      -parseHexInt(splitted[0].strip(true, true, {'-'}))
    elif splitted[0][0] == '*':
      parseHexInt(splitted[0].strip(true, true, {'*'}))
    else: parseHexInt(splitted[0])

proc readMethod(disasmer: var Disasmer, madr: uint32): int =
  var registers = initTable[string, int]()
  registers["%esp"] = 0
  var maxsp = 0
  for instr in parseInstructions(disasmer, madr):
    #echo instr.name, ": ", instr.src, " -> ", instr.dst
    case instr.name
    of "push":
      registers["%esp"] -= 4
    of "pop":
      registers["%esp"] += 4
    of "add":
      if instr.dst in registers:
        registers[instr.dst] += parseHexInt(instr.src)
    of "sub":
      if instr.dst in registers:
        registers[instr.dst] -= parseHexInt(instr.src)
    of "lea":
      let parsed = parseEA(instr.src)
      if parsed.register in registers:
        let ea = registers[parsed.register] + parsed.offset
        registers[instr.dst] = ea
        maxsp = max(maxsp, ea)
      elif instr.dst in registers:
        registers.del(instr.dst)
    of "mov", "movl":
      if instr.src in registers and not (instr.dst[^1] == ')'):
        registers[instr.dst] = registers[instr.src]
      elif instr.dst in registers and not (instr.src in registers):
        registers.del(instr.dst)
    of "retq", "jmpq":
      break
    else:
      discard
    if not(instr.src.isNil or instr.src[^1] != ')') or
         not(instr.dst.isNil or instr.dst[^1] != ')'):
      let parsed = 
        if instr.src[^1] == ')':parseEA(instr.src)
        else:parseEA(instr.dst)
      if parsed.register in registers:
        maxsp = max(maxsp, parsed.offset + registers[parsed.register])
    maxsp = max(registers["%esp"], maxsp)
  return max(4, maxsp)

iterator methods(start: ptr char): uint32 =
  let reinterpreted = cast[ptr array[0, uint32]](start)
  var shift = 0
  var offset = 0'u32
  while(offset = reinterpreted[shift]; offset > 10'u32):
    yield offset
    shift += 1

assert(paramCount() > 0)
bfd_init()
let filename = paramStr(1)
let file = bfd_open(filename, nil)
if not file.init():
  quit "Failed to open!"
echo "Num of sections: ", file.bfd_count_sections()
#let startAddr = bfd_get_start_address(file)
let strSegment = file.bfd_get_section_by_name(".rodata")
let textSegment = file.bfd_get_section_by_name(".text")
let vtableSegment = file.bfd_get_section_by_name(".data.rel.ro")
if strSegment.isNil or vtableSegment.isNil:
  discard file.bfd_close()
  quit "Failed to find section!"
echo "strSegment size: ", strSegment.size
echo "vtableSegment size: ", vtableSegment.size
let textSegmentData = file.getContent(textSegment)
let vtableSegmentData = file.getContent(vtableSegment)
let strSegmentData = file.getContent(strSegment)
var disasmer = file.initDisasm(textSegment, textSegmentData[0].unsafeAddr)
const classPattern = "CAdapterSteam"
var offset = -1
echo "Searching for classPattern"
while (offset = strSegmentData.find(classPattern, offset+1); offset >= 0):
  let realoffset = offset + strSegment.vma.int - 2
  echo "Found at ", realoffset.toHex()
  echo "Data: ", cast[cstring](strSegmentData[offset].unsafeAddr)
  let strPattern = realoffset.addr2Pattern()
  let tinfo = vtableSegmentData.find(strPattern) + vtableSegment.vma.int - 4
  echo "Found TInfo at: ", tinfo.toHex()
  let vtPattern = tinfo.addr2Pattern()
  let vtable = vtableSegmentData.find(vtPattern) + 4
  echo "Found VTable at: ", (vtable + vtableSegment.filepos.int).toHex()
  for madr in methods(vtableSegmentData[vtable].unsafeAddr):
    echo "Found method at: ", madr.toHex(), ", depth: ", readMethod(disasmer, madr)
discard bfd_close(file)
