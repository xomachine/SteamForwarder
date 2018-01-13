--app:lib
--passL:"-m32"
--passL:"-mno-cygwin"
--passC:"-m32"
--passC:"-mno-cygwin"
--passC:"-D__WINESRC__"
--cpu:i386
--cc:gcc
--o:steam_api.dll.so
--os:windows
--noMain
switch("gcc.exe", "/usr/bin/winegcc")
switch("gcc.linkerexe", "/usr/bin/winegcc")
