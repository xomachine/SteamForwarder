
SRCDIR                ?= $(CURDIR)
NIMC                  ?= nim
WINEDUMP              ?= winedump
MV                    ?= mv
RM                    ?= rm
MAKE                  ?= make
ARCH                  ?= 32
NOTUNE                ?= 0
ifeq ($(ARCH), 64)
  LIB_POSTFIX = 64
  NIMARCH = amd64
else
  LIB_POSTFIX =
  NIMARCH = i386
endif
CACHEDIR              ?= $(SRCDIR)
STEAMCLIENT           ?= $(SRCDIR)/steamclient.so
SIGNATURESFILE        ?= $(SRCDIR)/signatures.txt
SPECDIR               ?= $(SRCDIR)
ORIGINAL_SPECFILE     ?= steam_api_orig.spec
DLL                   ?= $(SRCDIR)/steam_api$(LIB_POSTFIX).dll
ORIGINAL_SPECPATH     ?= $(SPECDIR)/$(ORIGINAL_SPECFILE)
SPECFILE              ?= $(DLL:%.dll=%.spec)
DLLPARSER             ?= $(SRCDIR)/tools/dllparser
SIGSEARCH             ?= $(SRCDIR)/tools/sigsearch
VERSIONSDIR           ?= $(SRCDIR)/versions
PREFIX                ?= /usr/local
INSTALL               ?= install -Dm 755
INSTALLDATA           ?= install -Dm 644

OUTPUTDLL               = $(DLL).so
NIMSRCS                 = $(wildcard $(SRCDIR)/genmacros/*.nim)
VERFILES                = $(wildcard $(SRCDIR)/versions/*/libsteam_api.so)
INSTALLERSCRIPT         = $(wildcard $(SRCDIR)/installer/*.py)
VERENDS                 = $(notdir $(VERFILES:%/libsteam_api.so=%))
INSTALLVERLIBS          = $(foreach sf, $(VERENDS), $(INSTALLDATA) $(SRCDIR)/versions/$(sf)/libsteam_api.so $(DESTDIR)$(PREFIX)/share/SteamForwarder/versions/$(sf)/libsteam_api.so;)

.PHONY: all tools clean fullclean install tests
.NOTPARALLEL:

all: $(OUTPUTDLL)

tools: $(SIGSEARCH) $(DLLPARSER)

tests:
	cp tests/testspec.spec $(ORIGINAL_SPECPATH)
	$(MAKE) -C $(SRCDIR) ORIGINAL_SPECPATH=$(ORIGINAL_SPECPATH) $(OUTPUTDLL)

install: tools $(SIGNATURESFILE)
	$(INSTALL) -t $(DESTDIR)$(PREFIX)/share/SteamForwarder/tools $(SIGSEARCH) \
	              $(DLLPARSER)
	$(INSTALLVERLIBS)
	$(INSTALL) $(SRCDIR)/sf_install \
	           $(DESTDIR)$(PREFIX)/share/SteamForwarder/sf_install
	$(INSTALLDATA) -t $(DESTDIR)$(PREFIX)/share/SteamForwarder $(SIGNATURESFILE) \
	                  $(SRCDIR)/steam_api.nim \
                    $(SRCDIR)/steam_api.nims \
                    Makefile
	$(INSTALLDATA) -t $(DESTDIR)$(PREFIX)/share/SteamForwarder/installer \
	                  $(INSTALLERSCRIPT)
	$(INSTALLDATA) -t $(DESTDIR)$(PREFIX)/share/SteamForwarder/genmacros \
	                  $(NIMSRCS)
	$(INSTALL) -d $(DESTDIR)$(PREFIX)/bin
	ln -s ../share/SteamForwarder/sf_install \
	      $(DESTDIR)$(PREFIX)/bin/sf_install

$(SIGSEARCH):
	$(MAKE) -C $(SRCDIR)/tools $(SIGSEARCH)

$(DLLPARSER):
	$(MAKE) -C tools $(DLLPARSER)

$(OUTPUTDLL): $(SPECFILE) $(SIGNATURESFILE)
	$(NIMC) c -d:specname=$(SPECFILE) -d:cdfile=$(SIGNATURESFILE) \
            --passC:"-m$(ARCH)" --passL:"-m$(ARCH)" --cpu:$(NIMARCH) \
            --nimcache:$(CACHEDIR)/nimcache -o:$(OUTPUTDLL) steam_api.nim

$(SPECFILE): $(ORIGINAL_SPECPATH) $(DLLPARSER)
	$(DLLPARSER) $(VERSIONSDIR) < $(ORIGINAL_SPECPATH) > $(SPECFILE)
ifeq ($(ARCH), 64)
	sed -i 's/versions/versions64/' $(SPECFILE)
endif

$(ORIGINAL_SPECPATH):
	cd $(SPECDIR); \
	$(WINEDUMP) spec $(DLL); \
	$(RM) $(ORIGINAL_SPECFILE:%.spec=%_main.c) Makefile.in; \
	$(MV) "$(SPECFILE)" "$@"

$(SIGNATURESFILE): $(SIGSEARCH)
	$(SIGSEARCH) $(STEAMCLIENT) > $(SIGNATURESFILE)

fullclean: clean
	$(MAKE) -C tools clean
	$(RM) $(SIGNATURESFILE)

clean:
	$(RM) -r $(SRCDIR)/nimcache
	$(RM) $(SCRDIR)/$(OUTPUTDLL) $(SPECFILE) \
           $(ORIGINAL_SPECFILE) steam_api_main.c
