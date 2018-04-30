from os.path import join, dirname, isfile, abspath
from sys import stdout
from os import walk, listdir, symlink
from subprocess import run
from tempfile import TemporaryDirectory

def find_steamapi_dll(installdir):
  for root, dirs, files in walk(installdir):
    if "steam_api.dll" in files:
      return join(root, "steam_api.dll")
  print("Can not find steam_api.dll inside the game directory! Probably, " +
        "the game is incompatible with SteamForwarder")
  exit(1)

def read_spec(filepath):
  ## Reads spec file and returns a list of function names found in it
  result = set()
  with open(filepath, "r") as fd:
    for line in fd.readlines():
      if line.strip(" \n") == "" or line.startswith("#"):
        continue
      result.add(line.split()[2]) # №(0) stub(1) Name(2)
  return result

def compare_specs(gamespec, precompiledspec):
  ## Compares two specs and returns how many functions from first spec
  ## have found in second one relative to total amount of functions in the
  ## first spec
  gs = read_spec(gamespec)
  pcs = read_spec(precompiledspec)
  intersects = gs.intersection(pcs)
  return len(intersects)/len(gs)

def esc(path):
  return path.replace(" ", "\\ ")

def findMatchingLibrary(gamelocation, strict):
  if " " in gamelocation:
    with TemporaryDirectory() as tmpdir:
      newgamelocation = join(tmpdir, "thegame")
      if " " in newgamelocation:
        raise Exception("Can not handle the whitespaces in path. " +
                        "The temporary directory also contains whitespaces!")
      symlink(gamelocation, newgamelocation)
      return findMatchingLibrary(newgamelocation, strict)
  steamdll = find_steamapi_dll(gamelocation)
  print("Found steam_api.dll: "+steamdll)
  origspecfile = join(dirname(steamdll), "steam_api.orig_spec")
  print("Specfile will be generated: "+origspecfile)
  run(["make", "DLL="+esc(steamdll), esc(origspecfile)])
  if not isfile(origspecfile):
    raise Exception("Can not generate spec file for steam_api!" +
                    " Ensure that winedump exists in the system.")
  versionlist = listdir("versions")
  versionlist.sort()
  print("Searching for precompiled version of steam_api.dll.so...")
  totalcoverage = 0.0
  bestpath = ""
  for version in versionlist:
    stdout.write(version+"...")
    predir = join("versions", version)
    prefile = join(predir, "steam_api.orig_spec")
    if isfile(prefile):
      coverage = compare_specs(origspecfile, prefile)
      if coverage == 1.0:
        print("Found")
        return abspath(predir)
      elif coverage > totalcoverage:
        totalcoverage = coverage
        bestpath = abspath(predir)
      print("[%0.1f%% matching]" % (coverage * 100))
    else:
      print("No such file")
  if not strict and totalcoverage > 0:
    return bestpath
  run(["make", "DLL="+esc(steamdll), "clean"])
  fixedspec = join(gamelocation, "steam_api.spec")
  with TemporaryDirectory() as tmpdir:
    run(["make", "DLL="+esc(steamdll),
                 "SPECDIR="+esc(gamelocation),
                 "SPECFILE="+esc(fixedspec),
                 "CACHEDIR="+esc(tmpdir),
                 esc(steamdll+".so")])
  if not isfile(fixedspec):
    raise Exception("Failed to compile steam_api.dll.so!")
  with open(fixedspec, "r") as f:
    return dirname(f.readline().strip("# \n"))


