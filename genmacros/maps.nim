
from posix import Pid

type
  Flags* {.pure.} = enum
    read
    write
    execute
    private
  ModuleEntry* = tuple
    mrange: Slice[uint32]
    permissions: set[Flags]
    name: string
  MemMaps* = tuple
    upper: int
    d: array[1024, ModuleEntry]
{.push cdecl.}
proc getRealPid*(): string
proc getMMap*(old: var MemMaps)
proc checkAddress*(m: MemMaps, address: uint32): ModuleEntry
#proc parseFlags(f: string): set[Flags]
proc getCurWPath(): string
proc getWPath(p: string): string
{.pop.}

from posix import getppid, Pid, getcwd, readlink
from strutils import parseInt, format, strip, rsplit, split, parseHexInt,
                     IdentChars, IdentStartChars, HexDigits
from wine import trace
import strscans

proc getCurWPath(): string =
  ## Obtains current executable working dir
  var buffer: array[256, char]
  $getcwd(buffer[0].addr, 255)

proc getWPath(p: string): string =
  ## Obtains current working dir of `p`
  result = newString(256)
  let read = readlink("/proc/" & $p & "/cwd", result[0].addr, 255)
  result.setLen(read)

proc flags(f: string, res: var set[Flags], start: int): int =
  let leters = "rwxp"
  if start + 4 >= f.len: return 0
  var outp: set[Flags]
  for fl in Flags:
    let i = fl.ord + start
    if f[i] == leters[fl.ord]: outp.incl(fl)
    elif f[i] == '-': outp.excl(fl)
    else: return 0
  res = outp
  return 4

proc hex(input: string, intval: var uint32, start: int): int =
  var i = start
  while i < input.len and input[i] in HexDigits: i.inc
  if i != start: intval = parseHexInt(input[start..<i]).uint32
  return i - start

proc modname(input: string, name: var string, start: int): int =
  var i = input.len - 1
  let addition = {'[', ']', '.'}
  let valid = IdentChars + addition
  while i >= start and input[i] notin valid: i.dec
  var fin = max(i, start)
  while i >= start and input[i] in valid: i.dec
  name = input[max(i+1, start)..fin]
  return input.len - start

proc contains(o: MemMaps, s: string): bool =
  for i in 0..<o.upper:
    if o.d[i].name == s:
      return true
  return false

proc getMMap(old: var MemMaps) =
  ## Obtains content of /proc/$$/maps and parses it to get real module mapping
  ## The real mappings are needed to check correctness memory references
  if "steamclient.so" in old:
    return
  let realPid {.global.} = getRealPid()
  let mapfile {.global.} = "/proc/" & realPid & "/maps"
  var i = 0
  for line in mapfile.lines():
    if line.scanf("${hex}-${hex} ${flags} ${modname}", old.d[i].mrange.a,
                  old.d[i].mrange.b, old.d[i].permissions, old.d[i].name):
      i.inc
  old.upper = i

proc getRealPid(): string =
  ## Some workaround to get current PID in linux terms instead of windows PID
  let ppid = getppid()
  let curPath = getCurWPath()
  for line in "/proc/$1/task/$1/children".format(ppid).lines():
    let stripped = line.strip()
    let pPath = getWPath(stripped)
    if curPath == pPath:
      trace("Real PID = %s\n", stripped.cstring)
      return stripped

proc checkAddress(m: MemMaps, address: uint32): ModuleEntry =
  for i in 0..<m.upper:
    if address in m.d[i].mrange:
      return m.d[i]
