from libs.disasm import Disasmer
from tables import Table
from sets import HashSet

type
  StackStatus* = tuple
    depth: int
    retStruct: bool

proc interpretStack(disasmer: var Disasmer, madr: uint32,
                    regs: Table[string, int],
                    visited: var HashSet[uint32]): StackStatus
proc readProcedure*(disasmer: var Disasmer, madr: uint32): StackStatus

from strutils import split, parseHexInt, strip, toHex
from sets import initSet, incl, contains
from tables import `[]`, `[]=`, initTable, contains, del
from libs.disasm import parseInstructions

var stackprotector = 0'u32 # address of stack protector procedure

proc parseEA(s: string): tuple[register: string, offset: int] =
  ## Parses the effective address in format "0x[value]([register])" to
  ## the pair of register and value
  let splitted = s.split({'(', ')'})
  if splitted.len == 1:
    return (register: "", offset: parseHexInt(s))
  result.register = splitted[1]
  result.offset =
    if splitted[0].len == 0 or splitted[0][0] == '%':
      0
    elif splitted[0][0] == '-':
      -parseHexInt(splitted[0].strip(true, true, {'-'}))
    elif splitted[0][0] == '*':
      parseHexInt(splitted[0].strip(true, true, {'*'}))
    else: parseHexInt(splitted[0])

proc readProcedure(disasmer: var Disasmer, madr: uint32): StackStatus =
  ## Emulates the stack of procedure located in `madr` using the
  ## disassembler instance `disasmer`. Returns the stack information
  ## including stack depth procedure accessing to and inmemory return indicator.
  var registers = initTable[string, int]()
  registers["%esp"] = 0
  var visited = initSet[uint32](256)
  disasmer.interpretStack(madr, registers, visited)

proc merge(a, b: StackStatus): StackStatus =
  ## Compares stack informations and selects one with deepest stack access and
  ## inmemory return indicator set.
  result.depth = max(a.depth, b.depth)
  result.retStruct = a.retStruct or b.retStruct

proc interpretStack(disasmer: var Disasmer, madr: uint32,
                  regs: Table[string, int],
                  visited: var HashSet[uint32]): StackStatus =
  ## Interprets assembler code of the procedure given in `madr` via disassembler
  ## instance `disasmer` with given initial registers table `regs`.
  ## If address from `visited` encountered - returns
  ## The result of this proc is the stack information
  var registers = regs
  var couldbenoreturn = 0'u32
  for address, instr in parseInstructions(disasmer, madr):
    if address in visited:
#      echo address.toHex(), " is already visited! Stopping"
      break
    visited.incl(address)
    when defined(debug):
      echo address.toHex, ": ", $registers["%esp"], ":", instr.name, " ",
           instr.src, "->", instr.dst,
           (if instr.address > 0'u32: instr.address.toHex() else: "")
    case instr.name
    of "push":
      registers["%esp"] -= 4
    of "pop":
      registers["%esp"] += 4
    of "add":
      if instr.dst in registers:
        #if instr.src in registers:
        #  registers[instr.dst] += registers[instr.src]
        if instr.src[0] != '%':
          registers[instr.dst] += parseHexInt(instr.src)
    of "sub":
      if instr.dst in registers:
        #if instr.src in registers:
        #  registers[instr.dst] -= registers[instr.src]
        if instr.src[0] != '%':
          registers[instr.dst] -= parseHexInt(instr.src)
    of "leaveq", "leave":
      registers["%esp"] = registers["%ebp"] + 4
      registers.del("%ebp")
    of "lea":
      let parsed = parseEA(instr.src)
      if parsed.register in registers:
        let ea = registers[parsed.register] + parsed.offset
        registers[instr.dst] = ea
        result.depth = max(result.depth, ea)
      elif instr.dst in registers:
        registers.del(instr.dst)
    of "mov", "movl", "movzwl", "movzbl":
      if instr.src in registers and not (instr.dst[^1] == ')'):
        let src =
          case instr.name
          of "movzwl": registers[instr.src] and 0x0000FFFF
          of "movzbl": registers[instr.src] and 0x000000FF
          else: registers[instr.src]
        registers[instr.dst] = src
      elif instr.dst in registers and not (instr.src in registers):
        registers.del(instr.dst)
    of "jmpq", "jmp":
      return merge(disasmer.interpretStack(instr.address, registers, visited),
                   result)
    of "(bad)":
      break
      #quit("Bad instruction encountered!")
    of "nop":
      if registers["%esp"] == 0 or couldbenoreturn > 0'u32:
        # euristics! if nop after call encountered it could be stack protector
        # call without return
        stackprotector = couldbenoreturn
        break
    of "retq", "ret":
      if not instr.src.isNil:
        let stackpop = parseHexInt(instr.src)
        if stackpop > 4:
          quit "Stack pop when returning structure by value is bigger than " &
               "expected! stackpop = " & $stackpop
        result.retStruct = stackpop > 0
      case registers["%esp"]
      of 0: break
      of -4:
        result.retStruct = true
        break
      else:
        stderr.writeLine("WARNING! Stack corruption detected! This message " &
                         "may be harmless if caused by indirect no-return " &
                         "call in code. Anyway, the result of this branch " &
                         "will be abandoned.")
        return (depth: 0, retStruct: false)
    elif instr.name[0] == 'j' and (instr.address notin visited):
      when defined(debug):
        echo "Conditional jump to ", instr.address.toHex
      #visited.incl(instr.address)
      result = merge(disasmer.interpretStack(instr.address, registers, visited),
                     result)
      when defined(debug):
        echo "Returned back to main flow at ", address.toHex()
    else:
      discard
    if instr.name in ["callq", "call"]:
      if stackprotector == 0:
        # trying to detect stack protector. if nop will be encountered after
        # this call - this call is a stack protector call
        couldbenoreturn = instr.address
      elif instr.address == stackprotector:
        # call to stack protector never returns
        break
    else:
      couldbenoreturn = 0
    if not(instr.src.isNil or instr.src[^1] != ')') or
         not(instr.dst.isNil or instr.dst[^1] != ')'):
      let parsed = 
        if instr.src[^1] == ')': parseEA(instr.src)
        else:parseEA(instr.dst)
      if parsed.register in registers:
        result.depth = max(result.depth,
                           parsed.offset + registers[parsed.register])
    if "%esp" notin registers:
      quit("esp dereferenced!!! registers = " & registers.repr)
    result.depth = max(registers["%esp"], result.depth)
  if result.depth > 48: # just a sanity check
    quit("Sanity check failed!!! depth = " & $result.depth)

