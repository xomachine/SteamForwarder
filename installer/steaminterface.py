from json import loads
from locale import getlocale, normalize
from shutil import move, rmtree
from os.path import join, isdir, isfile
from os import remove, listdir
import re

def move_over(src, dst):
  print("Moving ", src, "to", dst)
  if isdir(dst) and isdir(src):
    print("Both dirs, recursing...")
    for p in listdir(src):
      dstdir = join(dst, p)
      srcdir = join(src, p)
      move_over(srcdir, dstdir)
    return
  if isdir(dst):
    rmtree(dst)
  elif isfile(dst):
    remove(dst)
  move(src, dst)

class LaunchInfo:
  def __init__(self, match_dict, install_dir):
    self.executable = install_dir + '/' + re.sub(r'\\', r'/',
                                                 match_dict['executable'])
    if 'arguments' in match_dict:
      self.arguments = match_dict["arguments"]
    else:
      self.arguments = ""
    self.description = match_dict["description"]
  def __repr__(self):
    return "(LaunchInfo: {0} {1} # {2})".format(self.executable,
                                                self.arguments,
                                                self.description)

class SteamInterface:
  def __init__(self, appid):
    self.appid = appid
  def getAppInfo(self):
    pass
  def appUpdate(self):
    pass
  def depotDownload(self):
    pass

colonre = re.compile(r'^(\s*"[^"]+")', re.MULTILINE)
commare = re.compile(r'("|})(\s*$\s*")', re.MULTILINE)

def quote(value, t="string"):
  if t == "string":
    return '"' + value.replace('\\', '\\\\').replace('"', '\"') + '"'
  elif t == "dword":
    more = max(8 - len(value), 0)
    return t + ":" + "0" * more + value
  else:
    return t + ":" + value.replace('\\', '\\\\').replace('"', '\\"')

def makeRegFile(reginfo, curlang):
  result = ""
  for k,v in reginfo.items():
    result += "[" + k + "]\n"
    for t ,d in v.items():
      for name, value in d.items():
        if type(value) is dict:
          if name == curlang:
            for n, vl in value.items():
              result += quote(n) + '=' + quote(vl, t) + "\n"
        else:
          result += quote(name) + '=' + quote(value, t) + "\n"
  return result

def parse_app_info(steam_json,  appid):
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
    if ((not 'config' in v) or (not 'oslist' in v['config']) or
        v['config']['oslist'] == 'windows'):
      if not 'description' in v:
        v['description'] = appinfos['name']
      name = v['description']
      appinfos['infos'][name] = LaunchInfo(v, installdir)
  if 'baselanguages' in appinfo['depots']:
    langs = appinfo['depots']['baselanguages'].split(',')
    curlang = ""
    curlocale = getlocale()[0]
    for lang in langs:
      localename = normalize(lang).split('.')[0]
      if localename == curlocale:
        print('Autoselected ' + lang + ' language based on locale settings')
        curlang = lang
    while not curlang in langs:
      curlang = input("Enter the translation you want to download: [" +
                       appinfo['depots']['baselanguages'] + "]\n")
  if 'install' in appinfo:
    installactions = appinfo['install']
    if 'Registry' in installactions:
      appinfos['regfile'] = makeRegFile(installactions['Registry'], curlang)
    appinfos['install'] = appinfo['install']
  for k, v in appinfo['depots'].items():
    if not 'config' in v:
      continue
    elif (('Language' in v['config'] and
           v['config']['Language'] == curlang) or
          (not 'oslist' in v['config']) or
          (v['config']['oslist'] == 'windows')):
      appinfos['depots'][k] = v
  return appinfos
