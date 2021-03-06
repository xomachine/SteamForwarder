from installer.steaminterface import SteamInterface,  parse_app_info, move_over
from installer.responsereader import selectReader
from os.path import isdir
from select import select
from glob import iglob
from time import sleep
import subprocess
import os

def findInputPipe(pid):
  for p in iglob("/proc/"+pid+"/fd/*"):
    link = os.readlink(p)
    if link.endswith("steam.pipe"):
      return link

def findSteamPid():
  result = subprocess.run(["pidof", "-s", "steam"], stdout=subprocess.PIPE)
  if result.returncode == 0:
    return result.stdout.strip().decode('utf-8')

class SteamNativeInterface(SteamInterface):
  def __init__(self, config):
    self.appid = config['appid']
    self.config = config
    self.scriptheader = " +app_license_request " + str(self.appid) + " "
    print("WARNING! You are using experimental feature --steamnative!")
    print("In case of any problems please remove --steamnative flag and install steamcmd.")
    print("Connecting to steam instance...")
    self.pid = findSteamPid()
    if self.pid == None or self.pid == "":
      print("Can not find steam! Is it running?")
      quit(1)
    print("Steam process found")
    print("PID:",  self.pid)
    self.reader = selectReader(self.pid)
    self.commandpipe = findInputPipe(self.pid)
    print("Command pipe:",  self.commandpipe)
    if self.commandpipe == None or self.commandpipe == "":
      print("Can not find steam input pipe (steam.pipe)! Did it renamed?")
      quit(1)
    self.vollist = list()
    self.volumes = self.getVolumes()
    print("Volumes:", self.volumes)

  def getVolumes(self):
    result = list()
    answered = False
    timer = 0
    with self.reader.steamOut() as out:
      self.steamIn("+install_folder_list")
      read = ""
      while len(select([out], [], [], 1.0)[0]) > 0:
        read = out.readline()
        if read.startswith("Index"):
          self.vollist.append(read)
          startp = read.find('"')+1
          endp = read.rfind('"')
          path = read[startp:endp]
          result.append(path)
          answered = True
        elif read == "":
          if answered:
            break
          if timer > 10:
            raise Exception("Timeout waiting answer from steam!")
          sleep(0.5)
          timer += 1
    return result

  def steamIn(self, commands):
    with open(self.commandpipe,  "w") as wfd:
      wfd.write("steam steam://open/console/ ")
      wfd.write(commands)
      wfd.write("\n")
      wfd.flush()
  def getAppInfo(self, again = False):
    answer = ""
    with self.reader.steamOut() as fd:
      self.steamIn("+app_info_print "+str(self.appid))
      read = ""
      while (len(read) == 0 or read[0] != '"') and (len(select([fd], [], [], 1.0)[0]) > 0):
        read = fd.readline()
      answer+=read
      while (len(read) == 0 or read[0] != '}') and (len(select([fd], [], [], 1.0)[0]) > 0):
        read = fd.readline()
        answer+=read
    if read[0] != '}' and not again:
      print("Waiting 10 seconds until steam will retrieve app info...")
      sleep(10)
      return self.getAppInfo(again=True)
    self.appinfo = parse_app_info(answer, self.appid)
    return self.appinfo

  def appUpdate(self):
    self.steamIn(self.scriptheader + "+@sSteamCmdForcePlatformType windows +app_install " +
                         str(self.appid) + " " + str(self.config["volume"]))
    print("Downloading started! Check out your steam. " +
              "When download is finished, run this script again with the same options " +
              "and additional --no-download argument.")
    self.steamIn( "+@sSteamCmdForcePlatformType linux")
    quit()

  def depotDownload(self, rs_location):
    if len(self.volumes) == 0:
      print("Can not obtain steam install folders! Please use steamcmd based method to download the game!")
      quit(1)
    elif "volume" in self.config and self.config["volume"] < len(self.volumes):
      vol = self.config["volume"]
    else:
      print("No volume specified, using default (0)")
      vol = 0
    script = ""
    depots = set()
    for k, v in self.appinfo["depots"].items():
      if 'dlcappid' in v:
        print("DLC depot: " + str(k))
        if not (k in self.config['dlcs']):
          print("Skipping DLC " + str(k) + ", use --with-dlc to download it")
          continue
      elif self.config['dlconly']:
        print("Skipping the game depot " + k +
              " since --dlc-only option passed")
        continue
      script += " +download_depot " + str(self.appid) + " " + str(k)
      depots.add(str(k))
    paths = []
    print(depots)
    with self.reader.steamOut() as fd:
      self.steamIn(self.scriptheader + script)
      read = ""
      print("Waiting for steam to download the depot... It could take a LOT of time...")
      while len(depots) > 0:
        if len(select([fd], [], [], 2.0)[0]) == 0:
          continue
        read = fd.readline()
        #print("Read:", read)
        if read.startswith("Depot download complete"):
          pstart = read.find('"')+1
          pend = read.rfind('"')
          path = read[pstart:pend].replace("\\", "/") 
          idstart = path.rfind("_")+1
          depotid = path[idstart:]
          if depotid in depots:
            print(depotid,  "downloaded")
            depots.remove(depotid)
            paths.append(path)
          if len(depots) == 0:
            break
        elif read.startswith("Depot download failed"):
          raise Exception(read)
        elif read.find("depot") >= 0 or read.find("Depot") >= 0:
          print(read)
    os.makedirs(rs_location, exist_ok=True)
    for path in paths:
      if not isdir(path):
        print("WARNING: Path " + path + " does not exist!")
        print("It is OK if there is an empty depot downloaded.")
        continue
      move_over(path, rs_location)
