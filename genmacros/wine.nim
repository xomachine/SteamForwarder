
#proc internalTrace(format: cstring)
#  {.header: "<wine/debug.h>", importc: "TRACE", varargs.}
#proc noop() {.header:"<stdarg.h>", codegenDecl: "".}



{.emit: """#include <stdarg.h>""".}
{.emit: """#include "windef.h"""".}
{.emit: """#include "winbase.h"""".}
{.emit: """#include "wine/debug.h"""".}
{.emit: "WINE_DEFAULT_DEBUG_CHANNEL(steam_api);".}
{.passC:"-I.".}
proc trace*(format: cstring)
  {.varargs, noDecl, importc: "TRACE", header: "debug.h".}

