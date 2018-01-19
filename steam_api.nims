--app:lib
--passL:"-mno-cygwin"
--passC:"-mno-cygwin"
--passC:"-D__WINESRC__"
--cc:gcc
--gc:v2
--d:useMalloc
--os:windows
--noMain
switch("gcc.exe", "/usr/bin/winegcc")
switch("gcc.linkerexe", "/usr/bin/winegcc")
