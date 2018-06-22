from installer.steaminterface import SteamInterface,  parse_app_info, move_over
import subprocess
import tempfile
import re
import os

colonre = re.compile(r'^(\s*"[^"]+")', re.MULTILINE)

class SteamCmdInterface(SteamInterface):
  def __init__(self, config):
    self.config = config
    self.steam_script_header = """
login {0} {1}
@sSteamCmdForcePlatformType windows
app_license_request {2}
""".format(config['login'], config['password'], str(config['appid']))
    self.appid = config['appid']
    self.vollist = list()
    self.volumes = self.getVolumes()

  def getAppInfo(self):
    result = subprocess.check_output(["steamcmd", "+app_info_print",
                                      str(self.appid), "+quit"]).decode('utf-8')
    json_begin = re.search(colonre, result)
    if json_begin is None:
      print(result)
      raise Exception("Incorrect app info received from steamcmd... Incorrect appID?")
    json_begin = json_begin.start()
    steam_json = result[json_begin:]
    self.appinfo = parse_app_info(steam_json, self.appid)
    return self.appinfo

  def appUpdate(self):
    print('Preparing classic downloader...')
    steam_script = self.steam_script_header + """
app_update {0} validate
""".format(str(self.appid))
    steam_script += "quit"
    do_script(steam_script)

  def getVolumes(self):
    result = list()
    vollist = subprocess.check_output(["steamcmd", "+install_folder_list",
                                      str(self.appid), "+quit"]).decode('utf-8')
    for line in vollist.splitlines():
      if line.startswith("Index"):
        self.vollist.append(line)
        startp = line.find('"')+1
        endp = line.rfind('"')
        path = line[startp:endp]
        result.append(path)
    return result

  def depotDownload(self, rs_location):
    print('Preparing depot downloader...')
    os.environ['LD_PRELOAD'] = self.config['depotpath'] + '/steamclient.so'
    os.symlink(self.config['steamcmdclient'], os.environ['LD_PRELOAD'], True)
    steam_script = self.steam_script_header
    for k, v in self.appinfo['depots'].items():
      if 'dlcappid' in v:
        print("DLC depot: " + str(k))
        if not (k in self.config['dlcs']):
          print("Skipping DLC " + str(k) + ", use --with-dlc to download it")
          continue
      elif self.config['dlconly']:
        print("Skipping the game depot " + k +
              " since --dlc-only option passed")
        continue
      print('Adding depot ' + str(k) + ' to schedule...')
      steam_script += """
download_depot {0} {1}
""".format(str(self.appid), str(k))
    steam_script += "quit"
    do_script(steam_script)
    # Cleanup and data moving after depot downloading
    os.environ['LD_PRELOAD'] = ""
    os.remove(self.config['depotpath'] + '/steamclient.so')
    os.makedirs(rs_location, exist_ok=True)
    for k, v in self.appinfo['depots'].items():
      path = self.config['depotpath'] + '/steamapps/content/app_{0}/depot_{1}/'.format(str(self.appid), str(k))
      #for sub in os.listdir(path):
      move_over(path, rs_location)

def do_script(steam_script):
  with tempfile.NamedTemporaryFile('w') as f:
    f.write(steam_script)
    f.flush()
    subprocess.run(["steamcmd", "+runscript", f.name])
