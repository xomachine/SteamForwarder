from strutils import rfind, `%`, splitLines, join
from sequtils import map
from parseopt import getopt, cmdShortOption, cmdArgument, cmdLongOption
from os import walkFiles
from osproc import execProcess
from ospaths import extractFilename, changeFileExt, `/`
from re import re, match
from spec import parseSpec, writeSpec, filterSpec
from call import parseFuncs
from class import parseClasses, toDeclaration, toImplementation,
                  toTestImplementation, makeTest

const headerHead = """
#include <steam_api_.h>
"""

let includere = re"""^#\s+([0-9]+)\s+"(.*?)"\s+([0-9])\s*$"""
proc getFileContent(filename: string): string =
  let basename = extractFilename(filename)
  let preprocessed = execProcess("gcc " &
                                 "-DUSE_BREAKPAD_HANDLER -E $1" % filename)
  var matches = newSeq[string](3)
  var skipping = false
  result = ""
  for line in preprocessed.splitLines():
    if line.match(includere, matches):
      let lineno = matches[0]
      let sourcename = matches[1]
      let action = matches[2]
      if skipping and sourcename == basename and action == "2":
        skipping = false
      elif sourcename != basename and action == "1" and lineno == "1" and
           not skipping:
        skipping = true
    elif not skipping:
      result &= line & "\n"

var
  sourcedir = ""
  target = ""
  testtarget = ""
  specfile = ""
const helpmsg = "Use -h switch to get help"
for t, k, v in getopt():
  case t
  of cmdShortOption, cmdLongOption:
    case k
    of "s", "source":
      sourcedir = v
    of "t", "target":
      target = v
    of "testtarget":
      testtarget = v
    of "spec":
      specfile = v
    of "h", "help":
      echo "-s, --source - set steamapi headers folder"
      echo "--spec       - set spec file location"
      echo "-t, --target - set classes destination folder"
      echo "--testtarget - set destination of test files"
    else:
      echo helpmsg
  else:
    echo helpmsg

if sourcedir.len == 0 or target.len == 0 or specfile == "":
  quit("Use options to set spec file, steamapi headers" &
       " and target folders")
var thespec = parseSpec(specfile)
let funcs = parseFuncs(getFileContent(sourcedir / "steam_api.h")) &
            parseFuncs(getFileContent(sourcedir / "steam_api_internal.h")) &
            parseFuncs(getFileContent(sourcedir / "steam_api_flat.h"))
let filtered_funcs = thespec.filterSpec(funcs)
## TODO: steam_api.cpp generation
let head = open(target / "steam_api_.h", fmWrite)
#let forbidden_files = [
#  "isteammasterserverupdater.h",
#  "isteamappticket.h",
#  "isteamgamecoordinator.h",
#  "isteamps3overlayrenderer.h"
#]
head.writeLine """
#include <steam_api.h>
"""

for f in walkFiles(sourcedir / "isteam*.h"):
  let filename = f.extractFilename()
  let wrapped_name = "wrap_" & filename
  let wrapped_cpp_name = wrapped_name.changeFileExt(".cpp")
  let classes = f.getFileContent().parseClasses()
  let header_content = classes.map(toDeclaration).join("\n")
  (target / wrapped_name).writeFile(headerHead & header_content)
  head.writeLine """#include <$1>""" % wrapped_name
  let impl_generator =
    if testtarget != "": toImplementation
    else: toTestImplementation
  let implementation = headerHead & classes.map(impl_generator).join("\n\n")
  (target / wrapped_cpp_name).writeFile(implementation)
  if testtarget != "":
    let test = classes.map(makeTest).join("\n")
    ## TODO: tests framing code (initialization, includes, etc...
    (testtarget / "call_" & wrapped_cpp_name).writeFile(test)
head.close()
writeSpec(specfile.changeFileExt("auto.spec"), thespec)



