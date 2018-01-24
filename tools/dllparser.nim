from os import paramCount, paramStr, walkFiles, pcFile
from tables import OrderedTable, `[]`, contains, len, `$`, initTable, `[]=`,
                   values
from spec import readSpecFile, SpecFile
from strutils import toHex, join
from sequtils import repeat
from spcounter import readProcedure, StackStatus
from libs.disasm import initDisasm
from libs.bfd import bfd_init, init, bfd_open, bfd_close, readSymbolTable,
                     BFS_DEBUGGING, Symbol, BFD, bfd_get_start_address,
                     bfd_get_section_by_name, getContent, BFS_GLOBAL

type
  MatchingLib = tuple
    path: string
    handle: BFD

proc findBestSOLib(verfolder: string, specdata: SpecFile): MatchingLib =
  ## Iterates over all subfolder in `verfolder` and parses symbols from
  ## libsteam_api.so located there. Then compares the parsed symbols with
  ## given `specdata` and returns best libsteam_api.so matching.
  var maxcount = 0
  for filename in walkFiles(verfolder & "/*/libsteam_api.so"):
    let bfile = bfd_open(filename, nil)
    if not bfile.init():
      quit("Can not open " & filename)
    let symbols = bfile.readSymbolTable()
    var counter = 0
    for s in symbols:
      if (s.flags and BFS_GLOBAL) > 0 and s.value > 0'u32 and
         $s.name in specdata:
        counter += 1
    if counter < maxcount:
      discard bfile.bfd_close()
    else:
      if not result.handle.isNil():
        discard result.handle.bfd_close()
      if specdata.len == counter:
        stderr.writeLine("Found exact match: " & filename)
        return (path: filename, handle: bfile)
      else:
        maxcount = counter
        result = (path: filename, handle: bfile)


assert(paramCount() == 1, "This program requires one and only one parameter: " &
                          "versions folder with various versions of " &
                          "libsteam_api.so in subfolders. It also reads spec " &
                          "file from stdin.")
let specdata = stdin.readSpecFile()
stderr.writeLine("Spec file: loaded " & $specdata.len & " entries")
let versionfolder = paramStr(1)
bfd_init()
let (libpath, bfile) = findBestSOLib(versionfolder, specdata)
let startAddress = bfd_get_start_address(bfile)
let symbols = bfile.readSymbolTable()
let textSection = bfile.bfd_get_section_by_name(".text")
let textSectionData = bfile.getContent(textSection)
var disasmer = initDisasm(bfile, textSection,
                          textSectionData[0].unsafeAddr)
stderr.writeLine("Read " & $symbols.len & " symbols from library")
var resolved = initTable[string, StackStatus]()
echo("# ", libpath)
for sym in symbols:
  let name = $sym.name
  if sym.value != 0 and (sym.flags and BFS_DEBUGGING) > 0 and
     name in specdata:
    let address = sym.value + startAddress
    when defined(debug):
      stderr.writeLine("Procedure: " & name & " with flags " & $sym.flags)
    resolved[name] = disasmer.readProcedure(address)
for entry in specdata.values:
  let tail =
    if entry.name in resolved:
      (let stack = resolved[entry.name];
       let nargs = stack.depth div 4;
       let arguments = repeat("ptr", nargs).join(" ");
       "cdecl " & entry.name & "(" & arguments & ") " & entry.name &
         "_" & " #" & (if stack.retStruct: "+" else: "") & $nargs)
    else:
      entry.callconv & " " & entry.name
  echo(entry.idx, " ", tail)

