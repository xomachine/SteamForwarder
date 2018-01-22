from installer.steaminterface import SteamInterface,  parse_app_info, move_over
from contextlib import contextmanager
from signal import SIGSTOP, SIGCONT
from glob import iglob
from select import select
import subprocess
import os

def findReader(pid):
  link = os.readlink("/proc/" + pid + "/fd/1")
  for p in iglob("/proc/*/fd/0"):
    if os.readlink(p) == link:
      rpid = int(p.split('/')[2])
      return rpid
  raise Exception("Reader not found")
  
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
    self.scriptheader = " +app_license_request " + str(self.appid)
    print("Connecting to steam instance...")
    self.pid = findSteamPid()
    if self.pid == None or self.pid == "":
      print("Can not find steam! Is it running?")
      quit(1)
    self.rpid = findReader(self.pid)
    if self.rpid == None or self.rpid == "":
      print("Can not find steam stdout reader! Is steam running from standart script?")
      quit(1)
    self.commandpipe = findInputPipe(self.pid)
    if self.commandpipe == None or self.commandpipe == "":
      print("Can not find steam input pipe (steam.pipe)! Did it renamed?")
      quit(1)
    self.vollist = list()
    self.volumes = self.getVolumes()
    print("Steam process found")
    print("PID:",  self.pid)
    print("Command pipe:",  self.commandpipe)
    print("Output reader PID:",  self.rpid)
    print("Volumes:", self.volumes)

  def getVolumes(self):
    result = list()
    with self.steamOut() as out:
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
    return result

  @contextmanager
  def steamOut(self):
    with open('/proc/'+self.pid+'/fd/1', "r") as fd:
      os.kill(self.rpid, SIGSTOP)
      yield fd
      os.kill(self.rpid, SIGCONT)
  def steamIn(self, commands):
    with open(self.commandpipe,  "w") as wfd:
      wfd.write("steam steam://open/console/ ")
      wfd.write(commands)
      wfd.write("\n")
      wfd.flush()
  def getAppInfo(self):
    answer = ""
    with self.steamOut() as fd:
      self.steamIn("+app_info_print "+str(self.appid))
      read = ""
      while (len(read) == 0 or read[0] != '"') and (len(select([fd], [], [], 1.0)[0]) > 0):
        read = fd.readline()
      answer+=read
      while (len(read) == 0 or read[0] != '}') and (len(select([fd], [], [], 1.0)[0]) > 0):
        read = fd.readline()
        answer+=read
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
  def depotDownload(self):
    if len(self.volumes) == 0:
      print("Can not obtain steam install folders! Please use steamcmd based method to download the game!")
      quit(1)
    elif "volume" in self.config and self.config["volume"] < len(self.volumes):
      vol = self.config["volume"]
    else:
      print("No volume specified, using default (0)")
      vol = 0
    rs_location = self.volumes[vol] + "/steamapps/common/" + self.appinfo["installdir"] + "/"
    script = ""
    depots = set()
    for k, v in self.appinfo["depots"].items():
      script += " +download_depot " + str(self.appid) + " " + str(k)
      depots.add(str(k))
    paths = []
    print(depots)
    with self.steamOut() as fd:
      self.steamIn(self.scriptheader + script)
      read = ""
      print("Waiting for steam to download the depot... It could take a LOT of time...")
      while True:
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
        elif read.find("depot") >= 0 or read.find("Depot") >= 0:
          print(read)
    os.makedirs(rs_location, exist_ok=True)
    for path in paths:
      #for sub in os.listdir(path):
      move_over(path, rs_location)
