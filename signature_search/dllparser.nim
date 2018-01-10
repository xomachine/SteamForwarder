from os import paramCount, paramStr, walkFiles, pcFile
from tables import OrderedTable, `[]`, contains, len, `$`, initTable, `[]=`,
                   values
from spec import readSpecFile, SpecFile
from strutils import toHex, join
from sequtils import repeat
from spcounter import readProcedure
from libs.disasm import initDisasm
from libs.bfd import bfd_init, init, bfd_open, bfd_close, readSymbolTable,
                     BFS_GLOBAL, Symbol, BFD, bfd_get_start_address,
                     bfd_get_section_by_name, getContent

proc findBestSOLib(verfolder: string, specdata: SpecFile): BFD =
  var maxcount = 0
  for filename in walkFiles(verfolder & "/*/libsteam_api.so"):
    let bfile = bfd_open(filename, nil)
    if not bfile.init():
      quit "Can not open " & filename
    let symbols = bfile.readSymbolTable()
    var counter = 0
    for s in symbols:
      if (s.flags and BFS_GLOBAL) != 0 and s.value > 0'u32 and
         $s.name in specdata:
        counter += 1
    if counter < maxcount:
      discard bfile.bfd_close()
    else:
      if not result.isNil():
        discard result.bfd_close()
      if specdata.len == counter:
        stderr.writeLine("Found exact match: " & filename)
        return bfile
      else:
        maxcount = counter
        result = bfile


assert(paramCount() == 1)
let specdata = stdin.readSpecFile()
stderr.writeLine("Spec file: loaded " & $specdata.len & " entries")
let versionfolder = paramStr(1)
bfd_init()
let bfile = findBestSOLib(versionfolder, specdata)
let startAddress = bfd_get_start_address(bfile)
let symbols = bfile.readSymbolTable()
let textSection = bfile.bfd_get_section_by_name(".text")
let textSectionData = bfile.getContent(textSection)
var disasmer = initDisasm(bfile, textSection,
                          textSectionData[0].unsafeAddr)
stderr.writeLine("Read " & $symbols.len & " symbols from library")
var resolved = initTable[string, string]()
for sym in symbols:
  let name = $sym.name
  if sym.value != 0 and (sym.flags and BFS_GLOBAL) > 0 and
     name in specdata:
    let address = sym.value + startAddress
    let depth = disasmer.readProcedure(address)
    let arguments = repeat("ptr", depth div 4).join(" ")
    resolved[name] = arguments
    #echo name, ":", depth
for entry in specdata.values:
  let tail =
    if entry.name in resolved:
      "cdecl " & entry.name & "(" & resolved[entry.name] & ") " & entry.name &
        "_"
    else:
      entry.callconv & " " & entry.name
  echo entry.idx, " ", tail

