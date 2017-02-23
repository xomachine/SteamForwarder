#!/bin/env python3

from urllib.request import urlopen, Request
from json import load, dump
import re
import argparse
import os

namere = re.compile("""<td itemprop="name">(?P<name>[^<>]+)</td>""")
startinfore = re.compile("""<tr>[\n\s]*
                         <td>(?P<description>[^<>]*)</td>[\n\s]*
                         <td>(?P<executable>[^<>]*)</td>[\n\s]*
                         <td>(?P<arguments>[^<>]*)</td>[\n\s]*
                         <td>(?P<type>[^<>]*)</td>[\n\s]*
                         <td\ class="nowrap">[\n\s]*
                         <i\ class="[^"]+"\ aria-label="Windows">[\n\s]*
                         </i>[\n\s]*
                         </td>[\n\s]*
                         <td>(?P<extra>[^<>]*)</td>[\n\s]*
                         </tr>""", re.X)

installdirre = re.compile("""<tr>[\n\s]*
                          <td>installdir</td>[\n\s]*
                          <td>(?P<installdir>[^<>]+)</td>[\n\s]*
                          </tr>[\n\s]*
                          """, re.X)


def showhelp():
  print("""Usage: app_install.py <appid>""")

def get_app_config(appid):
  configurl = "http://steamdb.info/app/" + str(appid) + "/config/"
  print(configurl)
  hdr = {'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64)'}
  req = Request(configurl, headers = hdr)
  content = urlopen(req).read().decode('utf-8')
  startinfo = startinfore.search(content).groupdict()
  startinfo["installdir"] = installdirre.search(content).groupdict()["installdir"]
  startinfo["id"] = appid
  startinfo["name"] = namere.search(content).groupdict()["name"]
  startinfo["executable"] = re.sub(r'\\', r'/', startinfo['executable'])
  return startinfo

def generate_manifest(appinfo):
  manifest = """
"AppState"
{
  "appid"        "%d"
  "Universe"     "1"
  "name"         "%s"
  "StateFlags"   "4"
  "installdir"   "%s"
}
""" % (appinfo["id"], appinfo["name"], appinfo["installdir"])
  return manifest

def generate_runscript(appinfo, config):
  print(appinfo['executable'])
  runscript = """
#!/bin/bash
export WINEPREFIX="{0}"
export WINEDLLPATH+=":{4}"
export LD_LIBRARY_PATH+=":{5}:{4}"
export WINEDEBUG="trace+steam_api"
LD_PRELOAD="gameoverlayrenderer.so" wine {1}/common/{6}/{2} {3} &> $(dirname $0)/lastrun.log
""".format(config['wineprefix'], config['steamapps'], appinfo['executable'],
           appinfo['arguments'], config['dllpath'], config['overlaypath'],
           appinfo['installdir'])
  return runscript

aparser = argparse.ArgumentParser(description="Steam windows game installation script")
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
  config['steamapps'] = os.getenv('HOME') + '/.local/share/Steam/steamapps'
  config['login'] = 'anonymous'
  with open("steamforwarder.json", "w") as f:
    dump(config, f, indent=2)

aparser.add_argument('-l', '--login', help='your login at steam', type=str, dest='login', default=config['login'])
aparser.add_argument('-s', '--steamapps-dir', help='path to the steamapps dir', type=str, dest='steamapps', default=config["steamapps"])
aparser.add_argument('-d', '--dll-dir', help='path to the steam_api.dll.so and libsteam_api.so', type=str, dest='dllpath', default=config["dllpath"])
aparser.add_argument('-o', '--overlay-dir', help='path to the gameoverlayrenderer.so and other steam libs', type=str, dest='overlaypath', default=config["overlaypath"])
aparser.add_argument('--store', help='save configuration for futher use as default', dest='store', default=False, action='store_true')
config_args = aparser.parse_args()
config['login'] = config_args.login
config['wineprefix'] = config_args.wineprefix
config['dllpath'] = config_args.dllpath
config['overlaypath'] = config_args.overlaypath
config['steamapps'] = config_args.steamapps
if config_args.store:
  with open("steamforwarder.json", "w") as f:
    dump(config, f, indent=2)
config['appid'] = config_args.appid
  
print("Obtaining app info...")
appinfo = get_app_config(config["appid"])
manifest = generate_manifest(appinfo)
manifest_location = config["steamapps"] + '/appmanifest_' + str(config['appid']) + '.acf'
print("Generating manifest...")
with open(manifest_location, "w") as f:
  f.write(manifest)

print("Downloading " + appinfo["name"] + " via steamcmd...")
os.spawnlp(os.P_WAIT, "steamcmd", "steamcmd",  "+login", config["login"], "+@sSteamCmdForcePlatformType", "windows", "+app_update", str(config["appid"]), "verify", "+quit")
print("Generating runscript...")
runscript = generate_runscript(appinfo, config)
runscript_location = config["steamapps"] + '/common/' + appinfo["installdir"] + '/' + appinfo["installdir"] + '.sh'
with open(runscript_location, "w") as f:
  f.write(runscript)
print("Done! You may launch the game via script located at " + runscript_location)

