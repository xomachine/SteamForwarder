from json import loads
import re
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
  for k, v in appinfo['depots'].items():
    if not 'config' in v:
      continue
    elif v['config']['oslist'] == 'windows':
      appinfos['depots'][k] = v
  return appinfos
