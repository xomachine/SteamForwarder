
proc trace*(format: cstring)
  {.varargs, noDecl, importc: "TRACE", header: """#include <stdarg.h>
#include "wine/debug.h"
WINE_DEFAULT_DEBUG_CHANNEL(steam_api);""".}
  ## Invoke TRACE macro from wine headers

