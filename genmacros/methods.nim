
type
  MethodDesc* = tuple
    name: string
    body: NimNode
  VTableDesc* = tuple
    name: string
    methods: seq[MethodDesc]
  APIDesc* = tuple
    pseudomethods: NimNode
    vtables: seq[VTableDesc]

from hashes import Hash, hash
from sequtils import mapIt
from macros import newStmtList, newTree, nnkBracket, quote, add, newLit,
                   prefix, newIdentNode

type
  MethodProc* = proc() {.cdecl.}
  VTablesList* = tuple
    hashes: seq[Hash]
    tables: seq[seq[MethodProc]]

proc convertToAST*(sink: NimNode, source: APIDesc): NimNode {.compileTime.} =
  result = newStmtList()
  result.add(source.pseudomethods)
  var hashes = newSeq[Hash]()
  var tables = newSeq[NimNode]()
  for vtable in source.vtables:
    let newhash = vtable.name.hash.int64.hash
    assert(newhash notin hashes, "Collision found: " & vtable.name)
    hashes.add(newhash)
    var methods = newSeq[NimNode]()
    for methoddesc in vtable.methods:
      let mbody = methoddesc.body
      let mname = newIdentNode(methoddesc.name)
      methods.add(mname)
      result.add quote do:
        proc `mname`*() {.asmNoStackFrame, noReturn, cdecl.} =
          `mbody`
    tables.add(newTree(nnkBracket, methods).prefix("@"))
  assert(hashes.len == tables.len, "Hashes does not match tables")
  let hashesNode = newTree(nnkBracket, hashes.mapIt(it.newLit)).prefix("@")
  let tablesNode = newTree(nnkBracket, tables).prefix("@")
  let vtablesdecl = quote do:
    const `sink`: VTablesList =
      (hashes: `hashesNode`, tables: `tablesNode`)
  result.add(vtablesdecl)

proc vtableByName*(self: VTablesList, name: cstring): pointer = 
  let thehash = name.hash.int64.hash()
  for i in 0..<self.hashes.len:
    if self.hashes[i] == thehash:
      return self.tables[i][0].unsafeaddr
  return nil
