from os import SEEK_END, kill, readlink
from os.path import isfile
from contextlib import contextmanager
from signal import SIGSTOP, SIGCONT
from glob import iglob

class FileReader:
  def __init__(self, link):
    self.file = link
    print("Using file to read steam response: " + link)

  @contextmanager
  def steamOut(self):
    with open(self.file, 'r') as fd:
      fd.seek(0, SEEK_END)
      yield fd

class PipeReader:
  def __init__(self, link, pipe):
    self.reader_pid = 0
    for p in iglob("/proc/*/fd/0"):
      if readlink(p) == link:
        self.reader_pid = int(p.split('/')[2])
        break
    if self.reader_pid == 0:
      raise Exception("Can not find a reader of steam's stderr pipe! "
                      "Please remove --steamnative and install steamcmd.")
    print("Intercepting steam stderr pipe to pid: " + str(self.reader_pid))
    self.pipe = pipe

  @contextmanager
  def steamOut(self):
    kill(self.reader_pid, SIGSTOP)
    with open(self.pipe, 'r') as fd:
      yield fd
    kill(self.reader_pid, SIGCONT)

def selectReader(pid):
  pipe = "/proc/"+pid+"/fd/2"
  link = readlink(pipe)
  if isfile(link):
    return FileReader(link)
  else:
    return PipeReader(link, pipe)
