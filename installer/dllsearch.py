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

def compare_specs(gamespec, precompiledspec):
  with open(gamespec, "r") as gamespecfd:
    with open(precompiledspec, "r") as prefd:
      for line in gamespecfd.readlines():
        if line.strip(" \n") == "" or line.startswith("#"):
          continue
        fname = line.split()
        preline = ""
        while preline.strip("\n ") == "" or preline.startswith("#"):
          preline = prefd.readline()
        prefname = preline.split()
        if fname != prefname:
          return False
  return True

def esc(path):
  return path.replace(" ", "\\ ")

def findMatchingLibrary(gamelocation):
  if " " in gamelocation:
    with TemporaryDirectory() as tmpdir:
      newgamelocation = join(tmpdir, "thegame")
      if " " in newgamelocation:
        raise Exception("Can not handle the whitespaces in path. " +
                        "The temporary directory also contains whitespaces!")
      symlink(gamelocation, newgamelocation)
      return findMatchingLibrary(newgamelocation)
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
  for version in versionlist:
    stdout.write(version+"...")
    predir = join("versions", version)
    prefile = join(predir, "steam_api.orig_spec")
    if isfile(prefile) and compare_specs(origspecfile, prefile):
      print("Found")
      return abspath(predir)
    print("MISS")
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


