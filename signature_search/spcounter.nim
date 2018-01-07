from strutils import split, parseHexInt, strip, toHex
from sets import HashSet, initSet, incl, contains
from tables import `[]`, `[]=`, initTable, contains, del, Table
from libs.disasm import parseInstructions, Disasmer


proc interpretStack(disasmer: var Disasmer, madr: uint32,
                    regs: Table[string, int], visited: var HashSet[uint32]): int

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
  var visited = initSet[uint32](256)
  disasmer.interpretStack(madr, registers, visited)

proc interpretStack(disasmer: var Disasmer, madr: uint32,
                  regs: Table[string, int], visited: var HashSet[uint32]): int =
  var registers = regs
  for address, instr in parseInstructions(disasmer, madr):
    if address in visited:
#      echo address.toHex(), " is already visited! Stopping"
      break
    visited.incl(address)
#    echo address.toHex, ": ", instr.name, " ", instr.src, "->", instr.dst, (if instr.address > 0'u32: instr.address.toHex() else: "")
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

    of "jmpq", "jmp":
      return max(disasmer.interpretStack(instr.address, registers, visited),
                 result)
    of "retq":
      break
    elif instr.name[0] == 'j' and (instr.address notin visited):
#      echo "Conditional jump to ", instr.address.toHex
      #visited.incl(instr.address)
      result = max(disasmer.interpretStack(instr.address, registers, visited),
                   result)
#      echo "Returned back to main flow at ", address.toHex()
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

