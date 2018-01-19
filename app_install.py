#!/bin/env python3

from urllib.request import urlopen, Request
from json import load, dump, loads
from getpass import getpass
import subprocess
import tempfile
import re
import argparse
import os
import shutil

namere = re.compile("""<td itemprop="name">(?P<name>[^<>]+)</td>""")
startinfore = re.compile("""<tr>[\n\s]*
                         <td>(?P<description>.*?)</td>[\n\s]*
                         <td>(?P<executable>[^<>]*)</td>[\n\s]*
                         <td>(?P<arguments>[^<>]*)</td>[\n\s]*
                         <td>(?P<type>.*?)</td>[\n\s]*
                         <td\ class="nowrap">[\n\s]*
                         (?P<os><i\ class="[^"]+"\ aria-label="Windows">[\n\s]*
                         </i>[\n\s]*)?
                         </td>[\n\s]*
                         <td>(?P<extra>[^<>]*)</td>[\n\s]*
                         </tr>""", re.X)

installdirre = re.compile("""<tr>[\n\s]*
                          <td>installdir</td>[\n\s]*
                          <td>(?P<installdir>[^<>]+)</td>[\n\s]*
                          </tr>[\n\s]*
                          """, re.X)

class LaunchInfo:
  def __init__(self, match_dict, install_dir):
    self.executable = install_dir + '/' + re.sub(r'\\', r'/', match_dict['executable'])
    if 'arguments' in match_dict:
      self.arguments = match_dict["arguments"]
    else:
      self.arguments = ""
    self.description = match_dict["description"]
  def __repr__(self):
    return "(LaunchInfo: {0} {1} # {2})".format(self.executable,
                                                self.arguments, self.description)

colonre = re.compile(r'^(\s*"[^"]+")', re.MULTILINE)
commare = re.compile(r'("|})(\s*$\s*")', re.MULTILINE)
def get_app_config(appid):
  result = subprocess.check_output(["steamcmd", "+app_info_print", str(appid),
                           "+quit"]).decode('utf-8')
  json_begin = re.search(colonre, result)
  if json_begin is None:
    print(result)
    raise
  json_begin = json_begin.start()
  steam_json = result[json_begin:]
  steam_json = re.sub(colonre, r'\1:', steam_json)
  steam_json = re.sub(commare, r'\1,\2', steam_json)
  appinfo = loads('{' + steam_json + '}')[str(appid)]
  appinfos = dict()
  appinfos['infos'] = dict()
  appinfos['depots'] = dict()
  appinfos['id'] = appid
  installdir = appinfo['config']['installdir']
  appinfos['installdir'] = installdir
  appinfos['name'] = appinfo['common']['name']
  for k, v in appinfo['config']['launch'].items():
    if (not 'config' in v) or (not 'oslist' in v['config']) or v['config']['oslist'] == 'windows':
      if not 'description' in v:
        v['description'] = appinfos['name']
      name = v['description']
      appinfos['infos'][name] = LaunchInfo(v, installdir)
  for k, v in appinfo['depots'].items():
    if not 'config' in v:
      continue
    elif v['config']['oslist'] == 'windows':
      appinfos['depots'][k] = v
  return appinfos

def find_steamapi_dll(installdir):
  for root, dirs, files in os.walk(installdir):
    if "steam_api.dll" in files:
      return os.path.join(root, "steam_api.dll")
  print("Can not find steam_api.dll inside the game directory! Probably, " +
        "the game is incompatible with SteamForwarder")
  exit(1)

def get_app_config_http(appid):
  configurl = "http://steamdb.info/app/" + str(appid) + "/config/"
  print(configurl)
  hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64)'}
  req = Request(configurl, headers = hdr)
  content = urlopen(req).read().decode('utf-8')
  startinfos = dict()
  startinfos["id"] = appid
  startinfos["infos"] = dict()
  startinfos["name"] = namere.search(content).groupdict()["name"]
  installdir = installdirre.search(content).groupdict()["installdir"]
  startinfos["installdir"] = installdir
  for startinfo_m in startinfore.finditer(content):
    match_dict = startinfo_m.groupdict()
    startinfo = LaunchInfo(match_dict, installdir)
    name = startinfo.description
    if '<' in name or name == "":
      name = startinfos["name"]
    startinfos["infos"][name] = startinfo
  return startinfos

def generate_manifest(appinfos):
  manifest = """
"AppState"
{
  "appid"               "%d"
  "Universe"            "1"
  "name"                "%s"
  "StateFlags"          "4"
  "installdir"          "%s"
  "AutoUpdateBehavior"  "1"
}
""" % (appinfos["id"], appinfos["name"], appinfos["installdir"])
  return manifest

def generate_runscript(appinfo: LaunchInfo, config, libsteamapi, installpath):
  print("...for " + appinfo.executable)
  runscript = """
#!/bin/bash
export WINEPREFIX="{0}"
export WINEDLLPATH+=":{4}"
export LD_LIBRARY_PATH+=":{5}:{8}"
export WINEDEBUG="trace+steam_api"
export WINEARCH="win32"
export WINEDLLOVERRIDES="*steam_api=b"
export SteamAppId="{6}"
export SteamControllerAppId="{6}"
export SteamGameId="{6}"
export SteamUser="{7}"
export SteamAppUser="{7}"
LD_PRELOAD="gameoverlayrenderer.so" wine "{1}/common/{2}" {3} &> "$(dirname "$0")/lastrun.log"
""".format(config['wineprefix'], config['steamapps'], appinfo.executable,
           appinfo.arguments, installpath, config['overlaypath'],
           config['appid'], config['login'], libsteamapi)
  return runscript

aparser = argparse.ArgumentParser(description="The windows steam games installation script")
aparser.add_argument('appid', type=int, help="appid of the game to be installed", metavar='appID')
aparser.add_argument('-w', '--wineprefix', help='path to wineprefix to be used to launch this app', type=str, dest='wineprefix', default=os.getenv('HOME') + '/.wine')

config = dict()
try:
  with open("steamforwarder.json", "r") as f:
    config = load(f)
except:
  print("Configuration file not found! Using default values... You may change them at steamforwarder.json")
  config['overlaypath'] = os.getenv("HOME") + "/.local/share/Steam/ubuntu12_32/"
  config['dllpath'] = os.getenv("PWD")

  steamfolder = os.getenv('HOME') + '/.local/share/Steam'
  #print(steamfolder)
  if os.path.isdir(steamfolder):
    #print("is dir")
    for d in os.listdir(steamfolder):
      #print(d)
      if not re.match("[sS]team[aA]pps", d) is None:
        config['steamapps'] = steamfolder + '/' + d
  config['login'] = 'anonymous'
  with open("steamforwarder.json", "w") as f:
    dump(config, f, indent=2)
if not 'steamapps' in config:
  config['steamapps'] = ""
if not 'depotpath' in config:
  config['depotpath'] = ""
if not 'steamcmdclient' in config:
  tmpsteamcmd = '/usr/share/steamcmd/linux32/steamclient.so'
  if os.path.isfile(tmpsteamcmd):
    config['steamcmdclient'] = tmpsteamcmd
  else:
    config['steamcmdclient'] = ''

aparser.add_argument('-l', '--login', help='your login at steam', type=str, dest='login', default=config['login'])
aparser.add_argument('--depot', help='download from steam depot directly', dest='depot', default=False, action='store_true')
aparser.add_argument('--depot-path', help='path where temporary data will be stored while depot downloading (A LOT of space should be available', dest='depotpath', default=config["depotpath"], type=str)
aparser.add_argument('--steamcmdclient', help='path to steamclient.so related to steamcmd', dest='steamclient', default=config["steamcmdclient"], type=str)
aparser.add_argument('-s', '--steamapps-dir', help='path to the steamapps dir', type=str, dest='steamapps', default=config["steamapps"])
aparser.add_argument('-d', '--dll-dir', help='path to the steam_api.dll.so and libsteam_api.so', type=str, dest='dllpath', default=config["dllpath"])
aparser.add_argument('-o', '--overlay-dir', help='path to the gameoverlayrenderer.so and other steam libs', type=str, dest='overlaypath', default=config["overlaypath"])
aparser.add_argument('-p', '--password', help='ask password of your steam account (may be necessary for non-free apps). Note: password will not be saved anywhere including configuration file', dest='askPassword', default=False, action='store_true')
aparser.add_argument('--store', help='save configuration for futher use as default', dest='store', default=False, action='store_true')
config_args = aparser.parse_args()
config['login'] = config_args.login
config['wineprefix'] = config_args.wineprefix
config['dllpath'] = config_args.dllpath
config['overlaypath'] = config_args.overlaypath
config['steamcmdclient'] = config_args.steamclient
config['depotpath'] = config_args.depotpath
if config_args.steamapps == "":
  print('Can not find steam location... Please specify it using -s key')
  quit(1)
if config['steamcmdclient'] == "":
  print('Can not find steamcmd\'s steamclient.so location. Please specify it using --steamcmdclient option to unlock --depot option.')
  if config_args.depot:
    config_args.depot = False
    print("Depot downloading disabled. Falling back to default method.")
config['steamapps'] = config_args.steamapps
if config_args.store:
  with open("steamforwarder.json", "w") as f:
    dump(config, f, indent=2)
if config_args.askPassword:
  config['password'] = getpass()
else:
  config['password'] = ""
appid = config_args.appid
config['appid'] = appid
  
print("Obtaining app info...")
try:
  appinfos = get_app_config(appid)
except Exception as e:
  print(e)
  print("Failed to get appinfo via steamcmd, falling back to http method...")
  appinfos = get_app_config_http(appid)
  if config_args.depot:
    print("Depot downloading is not available with http method!")
    config_args.depot = False
manifest = generate_manifest(appinfos)
manifest_location = config["steamapps"] + '/appmanifest_' + str(appid) + '.acf'
print("Generating manifest...")
with open(manifest_location, "w") as f:
  f.write(manifest)

rs_location = config["steamapps"] + '/common/' + appinfos["installdir"] + '/'
print("Downloading " + appinfos["name"] + " via steamcmd...")
steam_script = """
login {0} {1}
@sSteamCmdForcePlatformType windows
app_license_request {2}
""".format(config['login'], config['password'], str(appid))
if config_args.depot:
  print('Preparing depot downloader...')
  os.environ['LD_PRELOAD'] = config['depotpath'] + '/steamclient.so'
  os.symlink(config['steamcmdclient'], os.environ['LD_PRELOAD'], True)
  for k, v in appinfos['depots'].items():
    print('Adding depot ' + str(k) + ' to schedule...')
    steam_script += """
download_depot {0} {1}
""".format(str(appid), str(k))
else:
  print('Preparing classic downloader...')
  steam_script += """
app_update {0} validate
""".format(str(appid))
steam_script += "quit"
with tempfile.NamedTemporaryFile('w') as f:
  f.write(steam_script)
  f.flush()
  subprocess.run(["steamcmd", "+runscript", f.name])
if config_args.depot:
  # Cleanup and data moving after depot downloading
  os.environ['LD_PRELOAD'] = ""
  os.remove(config['depotpath'] + '/steamclient.so')
  os.makedirs(rs_location, exist_ok=True)
  for k, v in appinfos['depots'].items():
    path = config['depotpath'] + '/steamapps/content/app_{0}/depot_{1}/'.format(str(appid), str(k))
    for sub in os.listdir(path):
      shutil.move(path + sub, rs_location)
print("Generating the steam_api.dll wrapper just for this game...")
steamapidll = find_steamapi_dll(rs_location)
subprocess.run(["make", "clean"])
fixedspec = rs_location.replace(" ", "\\ ")+"steam_api.spec"
fixedspecfp = rs_location+"steam_api.spec"
subprocess.run(["make", "DLL="+steamapidll.replace(" ", "\\ ")+"",
                "SPECDIR="+rs_location.replace(" ", "\\ "),
                "SPECFILE="+fixedspec])
with open(fixedspecfp, 'r') as f:
  thefirstline = f.readline()
libsteamapi = os.path.dirname(thefirstline.strip('# \n'))
print("Generating runscripts...")
for name, appinfo in appinfos["infos"].items():
  runscript = generate_runscript(appinfo, config, libsteamapi, rs_location)
  runscript_location = (rs_location + name + '.sh')
  with open(runscript_location, "w") as f:
    f.write(runscript)
print("Placing steam_appid.txt to the game location...")
with open(rs_location + '/steam_appid.txt', "w") as f:
  f.write(str(appid))
print("Done! You may launch the game via scripts located at " + rs_location)

