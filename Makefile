
SRCDIR                ?= $(PWD)
NIMC                  ?= nim
WINEDUMP              ?= winedump
RM                    ?= rm
MAKE                  ?= make
CACHEDIR              ?= $(SRCDIR)
STEAMCLIENT           ?= $(SRCDIR)/steamclient.so
SIGNATURESFILE        ?= $(SRCDIR)/signatures.txt
SPECDIR               ?= $(SRCDIR)
ORIGINAL_SPECFILE     ?= steam_api_orig.spec
ORIGINAL_SPECPATH     ?= $(SPECDIR)/$(ORIGINAL_SPECFILE)
SPECFILE              ?= $(SPECDIR)/steam_api.spec
DLLPARSER             ?= $(SRCDIR)/tools/dllparser
SIGSEARCH             ?= $(SRCDIR)/tools/sigsearch
VERSIONSDIR           ?= $(SRCDIR)/versions
PREFIX                ?= /usr/local
INSTALL               ?= install -Dm 755
INSTALLDATA           ?= install -Dm 644

ARCH                  ?= 32
NOTUNE                ?= 0
ifeq ($(ARCH), 64)
  LIB_POSTFIX = 64
  NIMARCH = x86
else
  LIB_POSTFIX =
  NIMARCH = i386
endif
DLL                    ?= $(SRCDIR)/steam_api$(LIB_POSTFIX).dll
OUTPUTDLL               = $(DLL).so
NIMSRCS                 = $(wildcard $(SRCDIR)/genmacros/*.nim)

.PHONY: all tools clean fullclean install

all: $(OUTPUTDLL)

tools: $(SIGSEARCH) $(DLLPARSER)

install: tools $(SIGNATURESFILE)
	$(INSTALL) -t $(DESTDIR)$(PREFIX)/share/SteamForwarder/tools $(SIGSEARCH) \
	              $(DLLPARSER)
	$(INSTALL) $(SRCDIR)/app_install.py $(DESTDIR)$(PREFIX)/bin/app_install
	$(INSTALLDATA) -t $(DESTDIR)$(PREFIX)/share/SteamForwarder $(SIGNATURESFILE) \
	                  $(SRCDIR)/steam_api.nim \
                    $(SRCDIR)/steam_api.nims \
                    Makefile
	$(INSTALLDATA) -t $(DESTDIR)$(PREFIX)/share/SteamForwarder/genmacros \
	                  $(NIMSRCS)

$(SIGSEARCH):
	$(MAKE) -C $(SRCDIR)/tools $(SIGSEARCH)

$(DLLPARSER):
	$(MAKE) -C tools $(DLLPARSER)

$(OUTPUTDLL): $(SPECFILE) $(SIGNATURESFILE)
	$(NIMC) c -d:specname=$(SPECFILE) -d:cdfile=$(SIGNATURESFILE) \
            --passC:"-m$(ARCH)" --passL:"-m$(ARCH)" --cpu:$(NIMARCH) \
            --nimcache:$(CACHEDIR)/nimcache -o:$(OUTPUTDLL) steam_api.nim

$(SPECFILE): $(ORIGINAL_SPECFILE) $(DLLPARSER)
	$(DLLPARSER) $(VERSIONSDIR) < $(ORIGINAL_SPECFILE) > $(SPECFILE)

$(ORIGINAL_SPECFILE): tools
	cd $(SPECDIR)
	$(WINEDUMP) spec $(DLL) -o$(ORIGINAL_SPECFILE:.spec=.dll)
	$(RM) $(ORIGINAL_SPECFILE:%.spec=%_main.c) Makefile.in
	cd $(SRCDIR)

$(SIGNATURESFILE): $(SIGSEARCH)
	$(SIGSEARCH) $(STEAMCLIENT) > $(SIGNATURESFILE)

fullclean: clean
	$(MAKE) -C tools clean
	$(RM) $(SIGNATURESFILE)

clean:
	$(RM) -r $(SRCDIR)/nimcache
	$(RM) $(SCRDIR)/$(OUTPUTDLL) $(SPECFILE) \
           $(ORIGINAL_SPECFILE) steam_api_main.c
