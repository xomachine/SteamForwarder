
from utils import parseFullSpec, SpecFile
from wrapper import wrapIfNecessary, unwrapClass
from generators import genTraceCall, genCall, genArgs
from wine import trace
from callback import wrap, unwrap, wrapToOrigin
import macros

type Dummy = object
  a: uint64
  ## The empty struct needed to be used as return value in some functions and
  ## cause the compiller to generate code for in-memory return (CSteamID).

macro generateLinuxDecls*(specs: static[SpecFile]): untyped =
  ## Generates the libsteam_api.so bindings using given SpecFile.
  result = newStmtList()
  if specs.libpath.isNil:
    error("Spec file was not generated by dllparser or it was not found " &
          "any suitable libsteam_api.so!")
  let linkopt = newStrLitNode("'" & specs.libpath & "'")
  result.add quote do:
    {.passL:`linkopt`.}
  for s in specs.symbols:
    let name = newIdentNode(s.realname)
    let actualname = newStrLitNode(s.realname)
    var params = newTree(nnkFormalParams, genArgs(s.nargs))
    if s.swap:
      params[0] = bindSym("Dummy")
    var decl = quote do:
      proc `name`() {.codegenDecl:"extern $# __attribute__((sysv_abi)) $#$#",
                      importc: `actualname`.}
    decl[3] = params
    result.add(decl)
  when defined(debug):
    echo(result.repr)

const toskip = ["SteamAPI_RunCallbacks_"]
  ## The list of symbols that should not be wrapped by debug output
  ## (they are being called very frequently).
const regcallback = @[
  "SteamAPI_RegisterCallback_",
  "SteamAPI_RegisterCallResult_",
]
  ## The list of symbols that take the CCallback object as a first argument.
  ## This object should be properly wrapped before forwarding.
const unregcallback = @[
  "SteamAPI_UnregisterCallback_",
  "SteamAPI_UnregisterCallResult_",
]
  ## The list of symbols that take the CCallback object as a first argument.
  ## Unlikely previous one this list contains the last usage of CCallback
  ## object, so the wrapped version of this object may be safely removed
  ## from memory.

macro generateWineDecls*(specs: static[SpecFile]): untyped =
  ## Generates wrapped functions for symbols in given SpecFile.
  ## NOTE, before the functions generated by this macro there should be
  ## the libsteam_api.so bindings generated by the `generateLinuxDecls` macro.
  result = newStmtList()
  for s in specs.symbols:
    let name = newIdentNode(s.name & "Lin")
    let exportname = newStrLitNode(s.name)
      ## The name to be exported in steam_api.dll.so
    var params = newTree(nnkFormalParams, genArgs(s.nargs))
    if s.swap:
      ## If the function should perform inmemory return we must tell the
      ## C compiler about it.
      params[0] = bindSym("Dummy")
    var decl = quote do:
      proc `name`*() {.cdecl, exportc: `exportname`.}
    decl[3] = params # Function arguments insertion to the declaration
    var call = genCall(s.realname, s.nargs)
    let tracecall = genTraceCall(s.nargs)
    if s.name in (regcallback & unregcallback):
      let warg1 = newIdentNode("wrappedarg")
      let arg1 = call[1] # A little modificaltion of original call to pass
      call[1] = warg1 # the wrapped object as the first argument
      decl.body = quote do:
        `tracecall`
        trace("\n")
        let `warg1` = wrap(`arg1`)
        trace("= %p\n", `call`)
        wrapToOrigin(`warg1`) # Copying object fields to original object
      if s.name in unregcallback: # If it was last usage of wrapped object
        decl.body.add quote do:
          unwrap(`arg1`) # remove it
    elif s.name in toskip:
      decl.body = call
    else:
      let resultidt = newIdentNode("result")
        # This one will be returned implicitly
      let checkarg =
        if s.nargs > 0:
          let originarg = call[1]
          let unwrappedarg = newIdentNode("unwrapped")
          call[1] = unwrappedarg
          quote do:
            let `unwrappedarg` = unwrapClass(`originarg`)
        else: newEmptyNode()
      decl.body = quote do:
        `tracecall`
        `checkarg`
        `resultidt` = `call`
        trace(" = %p\n", `resultidt`)
      if not s.swap: # Objects with vtables are never being returned inmemory
        decl.body.add quote do: # Check if return value is ISteam* object
          `resultidt` = wrapIfNecessary(`resultidt`)
    result.add(decl)
  when defined(debug):
    echo(result.repr)

