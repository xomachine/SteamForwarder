
from posix import Pid

type
  Flags* {.pure.} = enum
    ## Attributes of memory region
    read
    write
    execute
    private
  ModuleEntry* = tuple
    ## The memory region related to file descriptor
    mrange: Slice[pointer]
    permissions: set[Flags]
    name: string
  MemMaps* = tuple
    ## The array of all memory regions related to process in linux
    upper: int
    d: array[1024, ModuleEntry]
{.push cdecl.}
proc getRealPid*(): string
proc getMMap*(old: var MemMaps)
proc checkAddress*(m: MemMaps, address: pointer): ModuleEntry
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
  ## Obtains current working dir of process with pid `p`
  result = newString(256)
  trace("PID to check: %s\n", p.cstring)
  let read = readlink("/proc/" & $p & "/cwd", result[0].addr, 255)
  if read notin 0..255:
    trace("Incorrect read value %d!\n", read)
    return ""
  result.setLen(read)

proc flags(f: string, res: var set[Flags], start: int): int =
  ## Flags reader for scanf
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

proc hex(input: string, intval: var pointer, start: int): int =
  ## Hex number reader for scanf
  var i = start
  while i < input.len and input[i] in HexDigits: i.inc
  if i != start: intval = cast[pointer](parseHexInt(input[start..<i]))
  return i - start

proc modname(input: string, name: var string, start: int): int =
  ## Module name reader for scanf (skips all unnecessary information)
  var i = input.len - 1
  let addition = {'[', ']', '.'}
  let valid = IdentChars + addition
  while i >= start and input[i] notin valid: i.dec
  var fin = max(i, start)
  while i >= start and input[i] in valid: i.dec
  name = input[max(i+1, start)..fin]
  return input.len - start

proc contains(o: MemMaps, s: string): bool =
  ## Checks if module with name `s` has a region in the linux process memory
  ## described by `o`
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
    for pid in line.split():
      if pid.len == 0:
        continue
      let stripped = pid.strip()
      let pPath = getWPath(stripped)
      if curPath == pPath:
        trace("Real PID = %s\n", stripped.cstring)
        return stripped

proc checkAddress(m: MemMaps, address: pointer): ModuleEntry =
  ## Checks if given `address` belongs to the linux process described by `m`
  ## and returns the region description which the `address` is related to
  for i in 0..<m.upper:
    if address in m.d[i].mrange:
      return m.d[i]
