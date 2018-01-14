
#proc internalTrace(format: cstring)
#  {.header: "<wine/debug.h>", importc: "TRACE", varargs.}
#proc noop() {.header:"<stdarg.h>", codegenDecl: "".}



{.emit: """#include <stdarg.h>""".}
{.emit: """#include "windef.h"""".}
{.emit: """#include "winbase.h"""".}
{.emit: """#include "wine/debug.h"""".}
{.emit: """#include "tlhelp32.h"""".}
#{.emit: "WINE_DEFAULT_DEBUG_CHANNEL(steam_api);".}
{.passL:"-ldbghelp".}
{.passL:"-lpsapi".}
{.passC:"-I.".}
proc trace*(format: cstring)
  {.varargs, noDecl, importc: "TRACE", header: "debug.h".}

from winlean import Handle, getCurrentProcess, getLastError, openProcess

const MAXFN = 260

type
  GUID = tuple
    a: culong
    b: cushort
    c: cushort
    d: array[8, byte]
  SYM_TYPE* {.size: 4.} = enum
    none
    coff
    cv
    pdb
    exported
    deferred
    sym
    dia
    virtual
  ModInfo* = object
    structSize: uint32
    fileOffset*: uint32
    baseOfImage*: uint32
    padding*: uint32
    imageSize*: uint32
    timeDateStamp: uint32
    checkSum: uint32
    numSyms: uint32
    symType*: SYM_TYPE
    moduleName*: array[32, char]
    imageName: array[256, char]
    loadedImageName: array[256, char]
    loadedPdbName: array[256, char]
    cVSig: uint32
    cVData: array[MAX_FN*3, char]
    pdbSig: uint32
    pdbSig70: GUID
    pdbAge: uint32
    pdbUnmatched: bool
    dbgUnmatched: bool
    lineNumbers: bool
    globalSymbols: bool
    typeInfo: bool
    sourceIndexed: bool
    publics: bool

proc initModInfo(): ModInfo =
  result.structSize = ModInfo.sizeof.uint32

proc checkAddr*(address: uint32, size: uint32): bool {.importc: "IsBadReadPtr".}

GC_disable()

proc moduleByAddress*(address: uint32): ModInfo =
  result = initModInfo()
  #let pid = 0
  #{.emit: [pid, " = GetCurrentProcessId();"].}
  {.emit: "long opt = SymGetOptions();".}
  {.emit: "SymSetOptions(opt | 0x40000000);".}
  #let phandle = openProcess(0x6, false, pid)
  let phandle = getCurrentProcess()
  let status = false
  {.emit: [status, " = SymInitialize(", phandle, ", NULL, FALSE);"].}
  if not status:
    trace("SymInitialize failed with %p\n", getLastError())
  {.emit: [status, " = SymGetModuleInfo64(", phandle, ", ", address.uint64, ", ",
           result.addr, ");"].}
  if not status:
    trace("SymGetModuleInfo64 failed with %p\n", getLastError())
  {.emit: "SymSetOptions(opt);".}

{.emit:"""
BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, void *reserved)
{
    TRACE("(%p, %u, %p)\n", instance, reason, reserved);

    switch (reason)
    {
        case DLL_WINE_PREATTACH:
            return FALSE;    /* prefer native version */
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(instance);
            NimMain();
            break;
    }

    return TRUE;
}
""".}
