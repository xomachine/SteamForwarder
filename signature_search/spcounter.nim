from strutils import split, parseHexInt, strip
from tables import `[]`, `[]=`, initTable, contains, del
from libs.disasm import parseInstructions, Disasmer

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


proc readProcedure*(disasmer: var Disasmer, madr: uint32): int =
  var registers = initTable[string, int]()
  registers["%esp"] = 0
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
        result = max(result, ea)
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
        result = max(result, parsed.offset + registers[parsed.register])
    result = max(registers["%esp"], result)

