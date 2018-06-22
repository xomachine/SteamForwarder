from os.path import join, dirname, isfile, abspath
from sys import stdout
from os import walk, listdir, symlink
from subprocess import run
from tempfile import TemporaryDirectory

def find_steamapi_dlls(installdir):
  result = list()
  for root, dirs, files in walk(installdir):
    if "steam_api.dll" in files:
      result.append(join(root, "steam_api.dll"))
    if "steam_api64.dll" in files:
      result.append(join(root, "steam_api64.dll"))
  if len(result) > 0:
    return result
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
  steamdlls = find_steamapi_dlls(gamelocation)
  result = list()
  for steamdll in steamdlls:
    print("Found steam_api.dll: " + steamdll)
    result.append(findForLib(gamelocation, steamdll, strict))
  return result

def findForLib(gamelocation, steamdll, strict):
  postfix = ""
  if steamdll.endswith("64.dll"):
    postfix = "64"
  origspecfile = join(dirname(steamdll), "steam_api"+postfix+".orig_spec")
  print("Specfile will be generated: "+origspecfile)
  run(["make", "DLL="+esc(steamdll), esc(origspecfile)])
  if not isfile(origspecfile):
    raise Exception("Can not generate spec file for steam_api!" +
                    " Ensure that winedump exists in the system.")
  verdir = "versions" + postfix
  versionlist = listdir(verdir)
  versionlist.sort()
  print("Searching for precompiled version of steam_api" + postfix +
        ".dll.so...")
  totalcoverage = 0.0
  bestversion = ""
  for version in versionlist:
    stdout.write(version+"...")
    predir = join("versions", version)
    prefile = join(predir, "steam_api.orig_spec")
    if isfile(join(verdir, version, "libsteam_api.so")) and isfile(prefile):
      coverage = compare_specs(origspecfile, prefile)
      if coverage > totalcoverage:
        totalcoverage = coverage
        bestversion = version
        if coverage == 1.0:
          print("Found")
          break
      print("[%0.1f%% matching]" % (coverage * 100))
    else:
      print("No such file")
  if totalcoverage == 1.0 or (not strict and totalcoverage > 0):
    print("The best matching version is " + bestversion)
    thepath = abspath(join(verdir, bestversion))
    if len(postfix) > 0:
      thepath += ":" + abspath(join("versions", bestversion))
    return thepath
  run(["make", "DLL="+esc(steamdll), "clean"])
  fixedspec = join(gamelocation, "steam_api" + postfix + ".spec")
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
