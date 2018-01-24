#!/bin/env python3
import os
os.chdir(os.path.dirname(os.path.realpath(__file__)))
from urllib.request import urlopen, Request
from getpass import getpass
from collections import defaultdict
from installer.steamcmd import SteamCmdInterface
from installer.steaminterface import LaunchInfo
from installer.steam import SteamNativeInterface
from json import load, dump
import subprocess
import tempfile
import re
import argparse

def find_steamapi_dll(installdir):
  for root, dirs, files in os.walk(installdir):
    if "steam_api.dll" in files:
      return os.path.join(root, "steam_api.dll")
  print("Can not find steam_api.dll inside the game directory! Probably, " +
        "the game is incompatible with SteamForwarder")
  exit(1)

def get_app_config_http(appid):
  namere = re.compile("""<td itemprop="name">(?P<name>[^<>]+)</td>""")
  startinfore = re.compile("""<tr>[\n\s]*
                           <td>(?P<description>.*?)</td>[\n\s]*
                           <td>(?P<executable>[^<>]*)</td>[\n\s]*
                           <td>(?P<arguments>[^<>]*)</td>[\n\s]*
                           <td>(?P<type>.*?)</td>[\n\s]*
                           <td\ class="nowrap">[\n\s]*
                           (?P<os>
                           <i\ class="[^"]+"\ aria-label="Windows">[\n\s]*
                           </i>[\n\s]*)?
                           </td>[\n\s]*
                           <td>(?P<extra>[^<>]*)</td>[\n\s]*
                           </tr>""", re.X)

  installdirre = re.compile("""<tr>[\n\s]*
                          <td>installdir</td>[\n\s]*
                          <td>(?P<installdir>[^<>]+)</td>[\n\s]*
                          </tr>[\n\s]*
                          """, re.X)
  configurl = "http://steamdb.info/app/" + str(appid) + "/config/"
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


config = defaultdict(str)
configdir = os.getenv("HOME") + '/.config/SteamForwarder/'
try:
  with open(configdir + "config.json", "r") as f:
    newconfig = load(f)
    for k, v in newconfig.items():
      config[k] = v
except:
  print("Configuration file not found! Using default values... " +
        "You may change them at " + configdir)
  config['overlaypath'] = os.getenv("HOME")+"/.local/share/Steam/ubuntu12_32/"

  steamfolder = os.getenv('HOME') + '/.local/share/Steam'
  #print(steamfolder)
  if os.path.isdir(steamfolder):
    #print("is dir")
    for d in os.listdir(steamfolder):
      #print(d)
      if not re.match("[sS]team[aA]pps", d) is None:
        config['steamapps'] = steamfolder + '/' + d
  config['login'] = 'anonymous'
  os.makedirs(configdir, exist_ok=True)
  with open(configdir + "config.json", "w") as f:
    dump(config, f, indent=2)
if not 'steamcmdclient' in config:
  tmpsteamcmd = '/usr/share/steamcmd/linux32/steamclient.so'
  if os.path.isfile(tmpsteamcmd):
    config['steamcmdclient'] = tmpsteamcmd
  else:
    config['steamcmdclient'] = ''

class printvollist(argparse.Action):
  def __call__(self, parser, ns, values, ostring):
    steaminterface = SteamNativeInterface(config)
    for p in steaminterface.vollist:
      print(p)
    quit(0)

aparser = argparse.ArgumentParser(description="The windows steam games " +
                                  "installation script")
aparser.add_argument('--volumelist', nargs=0,
                      help='print the list of available volumes in your steam',
                      action=printvollist)
aparser.add_argument('appid', type=int, metavar='appID',
                     help="appid of the game to be installed")
aparser.add_argument('-w', '--wineprefix', type=str, dest='wineprefix',
                     help='path to wineprefix to be used to launch this app',
                     default=os.getenv('HOME') + '/.wine')
aparser.add_argument('-l', '--login', help='your login at steam', type=str,
                     dest='login', default=config['login'])
aparser.add_argument('--depot', help='download directly from steam depot',
                     dest='depot', default=False, action='store_true')
aparser.add_argument('--depot-path', type=str, default=config["depotpath"],
                      help='path where temporary data will be stored while ' +
                      'depot downloading (omited when --steamnative)',
                      dest='depotpath')
aparser.add_argument('--steamcmdclient', dest='steamclient', type=str,
                     help='path to steamclient.so related to steamcmd',
                     default=config["steamcmdclient"])
aparser.add_argument('-s', '--steamapps-dir', type=str, dest='steamapps',
                      help='path to the steamapps dir',
                      default=config["steamapps"])
aparser.add_argument('-o', '--overlay-dir', dest='overlaypath', type=str,
                      help='path to the gameoverlayrenderer.so and other ' +
                      'steam libs', default=config["overlaypath"])
aparser.add_argument('-p', '--password', dest='askPassword', default=False,
                      help='ask password of your steam account (may be ' +
                      'necessary for non-free apps). Note: password will ' +
                      'not be saved anywhere including configuration file',
                      action='store_true')
aparser.add_argument('--no-download', default=False, dest='nodl',
                      help='just generate steam_api.dll.so for existing game',
                      action='store_true')
aparser.add_argument('--store', default=False, dest='store',
                      help='save configuration for futher use as default',
                      action='store_true')
aparser.add_argument('--steamnative', default=False, dest='steamnative',
                      help='use native steam instead of steamcmd (experimental)',
                      action='store_true')
aparser.add_argument('-v', '--volume', type=int, dest='volume',
                      help='select steam volume index for game to download into (works only with --steamnative)' +
                      ' use --volumelist to get list of volumes',
                      default=int(config["volume"] or 0))

config_args = aparser.parse_args()
config['login'] = config_args.login
config['wineprefix'] = config_args.wineprefix
config['overlaypath'] = config_args.overlaypath
config['steamcmdclient'] = config_args.steamclient
config['depotpath'] = config_args.depotpath
config['volume'] = config_args.volume
appid = config_args.appid
config['appid'] = appid

if config_args.steamnative:
  steaminterface = SteamNativeInterface(config)
else:
  if config_args.steamapps == "":
    print('Can not find steam location... Please specify it using -s key')
    quit(1)
  if config['steamcmdclient'] == "" and not config_args.steamnative:
    print('Can not find steamcmd\'s steamclient.so location. Please specify ' +
          'it using --steamcmdclient option to unlock --depot option.')
    if config_args.depot:
      config_args.depot = False
      print("Depot downloading disabled. Falling back to default method.")
  config['steamapps'] = config_args.steamapps
  if config_args.askPassword:
    config['password'] = getpass()
  else:
    config['password'] = ""
  steaminterface = SteamCmdInterface(config)
if config_args.store:
  os.makedirs(configdir, exist_ok=True)
  with open(configdir + "config.json", "w") as f:
    dump(config, f, indent=2)



print("Obtaining app info...")
try:
  appinfos = steaminterface.getAppInfo()
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
if not config_args.nodl:
  print("Downloading " + appinfos["name"] + " via steamcmd...")
  if config_args.depot:
    steaminterface.depotDownload()
  else:
    steaminterface.appUpdate()

print("Generating the steam_api.dll wrapper just for this game...")
steamapidll = find_steamapi_dll(rs_location)
fixedspec = rs_location.replace(" ", "\\ ")+"steam_api.spec"
fixedspecfp = rs_location+"steam_api.spec"
subprocess.run(["make", "clean"])
with tempfile.TemporaryDirectory() as tmpdir:
  subprocess.run(["make", "DLL="+steamapidll.replace(" ", "\\ ")+"",
                  "SPECDIR="+rs_location.replace(" ", "\\ "),
                  "SPECFILE="+fixedspec,
                  "CACHEDIR="+tmpdir.replace(" ", "\\ ")])
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

