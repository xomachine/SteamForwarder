
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
  MemMaps* = seq[ModuleEntry]
{.push cdecl.}
proc getRealPid*(): Pid
proc getMMap*(): MemMaps
proc checkAddress*(m: MemMaps, address: uint32): ModuleEntry
proc parseFlags(f: string): set[Flags]
proc getCurWPath(): string
proc getWPath(p: string): string
{.pop.}

from posix import getppid, Pid, getcwd, readlink
from strutils import parseInt, format, strip, rsplit, split, parseHexInt
from wine import trace

proc getCurWPath(): string =
  ## Obtains current executable working dir
  var buffer = newString(256)
  discard getcwd(buffer[0].addr, 255)
  trace("ResultSetLen: %s\n", buffer.cstring)
  $(buffer.cstring)

proc getWPath(p: string): string =
  ## Obtains current working dir of `p`
  result = newString(256)
  let read = readlink("/proc/" & $p & "/cwd", result[0].addr, 255)
  result.setLen(read)

proc parseFlags(f: string): set[Flags] =
  if f[0] == 'r': result.incl(Flags.read)
  if f[1] == 'w': result.incl(Flags.write)
  if f[2] == 'x': result.incl(Flags.execute)
  if f[3] == 'p': result.incl(Flags.private)

proc getMMap(): MemMaps =
  ## Obtains content of /proc/$$/maps and parses it to get real module mapping
  ## The real mappings are needed to check correctness memory references
  let realPid {.global.} = getRealPid()
  let mapfile {.global.} = "/proc/" & $realPid & "/maps"
  result = newSeq[ModuleEntry]()
  for line in mapfile.lines():
    let splitted = line.split()
    if splitted.len < 3:
      # illformed line, may be blank
      continue
    let bounds = splitted[0].split({'-'})
    if bounds[0].len > 8:
      # 64-bit address should be skipped while we are in 32-bit space
      continue
    let perms = parseFlags(splitted[1])
    let name = splitted[^1].rsplit('/', 1)[^1]
    let mrange = Slice[uint32](a: bounds[0].parseHexInt.uint32,
                               b: bounds[1].parseHexInt.uint32)
    result.add((mrange: mrange, permissions: perms, name: name))


proc getRealPid(): posix.Pid =
  ## Some workaround to get current PID in linux terms instead of windows PID
  let ppid = getppid()
  trace("PPID = %d\n", ppid)
  let curPath = getCurWPath()
  trace("WinExe = %s\n", curPath.cstring)
  for line in "/proc/$1/task/$1/children".format(ppid).lines():
    trace("Read line: %s\n", line.cstring)
    let stripped = line.strip()
    let pPath = getWPath(stripped)
    trace("exeName: %s\n", pPath.cstring)
    if curPath == pPath:
      return stripped.parseInt().Pid

proc checkAddress(m: MemMaps, address: uint32): ModuleEntry =
  for entry in m:
    if address in entry.mrange:
      return entry
