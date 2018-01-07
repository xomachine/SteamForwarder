{.passL: "-lopcodes".}
from bfd import BFD, Section
from strutils import count, `%`, replace, contains, strip

type
  Printer* = proc(dest: pointer, fmtstr: cstring)
               {.cdecl, varargs.}
  DisasmInfo* {.header: "<dis-asm.h>", importc:"disassemble_info".} = object
    fprintf_func: Printer
    stream*: pointer
    buffer*: pointer
    buffer_vma*: cuint
    buffer_length*: cuint
    section*: Section
    print_address_func: proc(a: cuint, di: ptr DisasmInfo) {.cdecl.}
  DInfo* = ptr DisasmInfo
  Disassembler* = proc(vma: cuint, di: DInfo): cint {.cdecl.}
  WaitFor = enum
    instruction
    dst
    src
  Instruction = tuple
    name: string
    dst: string
    src: string
    address: uint32
  Disasmer* = object
    disass: Disassembler
    dinfo: DisasmInfo
    waiting: WaitFor
    pending: Instruction

proc disassembler*(b: BFD): Disassembler =
  {.emit: [result, "= disassembler(bfd_get_arch(", b, "), 0, " &
           "bfd_get_mach(", b, "), ", b, ");"].}
proc initDInfo*(pipe: pointer, p: Printer): DisasmInfo =
  {.emit: ["init_disassemble_info(", result.addr, ", ", pipe, ", ", p, ");"].}
proc disassemble_init_for_target*(di: DInfo)
  {.importc, header: "<dis-asm.h>".}

proc printer(dest: pointer, fmtstr: cstring) {.cdecl, varargs.} =
  {.emit: "va_list ptr;".}
  {.emit: ["va_start(ptr, ", fmtstr, ");"].}
  let mo = cast[ptr Disasmer](dest)
  let formattedStr = $fmtstr
  if formattedStr == ",":
    mo.waiting = dst
  elif formattedStr == "%x":
    # address available
    var t: cuint
    {.emit: [t," = va_arg(ptr, unsigned int);"].}
    mo.pending.address = t
  elif formattedStr == "%s":
    var t: cstring
    {.emit: [t," = va_arg(ptr, char*);"].}
    let a = strip($t, true, true, {'$', ' '})
    #echo "'", formattedStr, "'@", formattedStr.len,", ", a, ", w:", mo.waiting
    case mo.waiting
    of instruction:
      mo.pending.name = a
      mo.waiting = src
    of dst:
      mo.pending.dst = a.replace("r", "e")
      mo.waiting = instruction
    of src:
      mo.pending.src = a.replace("r", "e")
      mo.waiting = instruction
  elif formattedStr.len() > 2:
    #error in parsing
    let nargs = formattedStr.count("%s")
    var args = newSeq[string](nargs)
    for i in 0..<nargs:
      var a: cstring
      {.emit: [a," = va_arg(ptr, char*);"].}
      args[i] = $a
    #echo formattedStr
    #echo formattedStr.replace("$", "\\$").replace("%s", "$#") % args
  else:
    discard
    #echo "Unknown: ", formattedStr

proc initDisasm*(b: BFD, s: Section, buffer: pointer): Disasmer =
  result.disass = disassembler(b)
  result.dinfo = initDInfo(result.addr, printer)
  result.dinfo.section = s
  result.dinfo.buffer_length = s.size
  result.dinfo.buffer_vma = s.vma
  result.dinfo.buffer = buffer
  result.dinfo.print_address_func = proc(a: cuint, di: DInfo){.cdecl.} =
    di.stream.printer("%x", a)
  disassemble_init_for_target(result.dinfo.addr)


iterator parseInstructions*(d: var Disasmer, start: uint32): Instruction =
  var lastlen = 0
  var shift = 0'u32
  d.pending.reset
  d.waiting = instruction
  while (lastlen = d.disass(start+shift, d.dinfo.unsafeAddr);
         lastlen > 0):
    yield d.pending
    d.pending.reset
    d.waiting = instruction
    shift += lastlen.uint32

