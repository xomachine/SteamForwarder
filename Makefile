
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
DLL                   ?= $(SRCDIR)/steam_api$(LIB_POSTFIX).dll
DLLPARSER             ?= $(SRCDIR)/tools/dllparser
SIGSEARCH             ?= $(SRCDIR)/tools/sigsearch
VERSIONSDIR           ?= $(SRCDIR)/versions
PREFIX                ?= /usr/local
INSTALL               ?= install -Dm 755
INSTALLDATA           ?= install -Dm 644

OUTPUTDLL               = $(DLL).so
NIMSRCS                 = $(wildcard $(SRCDIR)/genmacros/*.nim)
VERFILES                = $(wildcard $(SRCDIR)/versions/*/libsteam_api.so)
WINLIBS                 = $(wildcard $(SRCDIR)/versions/*/steam_api.dll)
PREORIGS                = $(WINLIBS:%.dll=%.orig_spec)
ORSPECS                 = $(wildcard $(SRCDIR)/versions/*/steam_api.orig_spec)
PRESPECS                = $(ORSPECS:%.orig_spec=%.spec)
PRETARGETS              = $(ORSPECS:%.orig_spec=%.dll.so)
INSTALLERSCRIPT         = $(wildcard $(SRCDIR)/installer/*.py)
VERENDS                 = $(notdir $(VERFILES:%/libsteam_api.so=%))
VERAVAILABLE            = $(notdir $(ORSPECS:%/steam_api.orig_spec=%))
INSTALLVERLIBS          = $(foreach sf, $(VERENDS), $(INSTALLDATA) $(SRCDIR)/versions/$(sf)/libsteam_api.so $(DESTDIR)$(PREFIX)/share/SteamForwarder/versions/$(sf)/libsteam_api.so;)
INSTALLPRELIBS          = $(foreach sf, $(VERAVAILABLE), $(INSTALLDATA) $(SRCDIR)/versions/$(sf)/steam_api.dll.so $(DESTDIR)$(PREFIX)/share/SteamForwarder/versions/$(sf)/steam_api.dll.so;)
INSTALLVERSPECS          = $(foreach sf, $(VERAVAILABLE), $(INSTALLDATA) $(SRCDIR)/versions/$(sf)/steam_api.spec $(DESTDIR)$(PREFIX)/share/SteamForwarder/versions/$(sf)/steam_api.spec;)
INSTALLVERORSPECS        = $(foreach sf, $(VERAVAILABLE), $(INSTALLDATA) $(SRCDIR)/versions/$(sf)/steam_api.orig_spec $(DESTDIR)$(PREFIX)/share/SteamForwarder/versions/$(sf)/steam_api.orig_spec;)

.PHONY: all tools clean fullclean install tests precompile prespec preorig signatures

all: $(OUTPUTDLL)

tools: $(SIGSEARCH) $(DLLPARSER)

precompile: $(PRETARGETS)

prespec: $(PRESPECS)

preorig: $(PREORIGS)

signatures: $(SIGNATURESFILE)

install: tools $(ORSPECS) $(PRESPECS) $(SIGNATURESFILE) $(PRETARGETS)
	$(INSTALL) -t $(DESTDIR)$(PREFIX)/share/SteamForwarder/tools $(SIGSEARCH) \
	              $(DLLPARSER)
	$(INSTALLVERLIBS)
	$(INSTALLVERSPECS)
	$(INSTALLPRELIBS)
	$(INSTALLVERORSPECS)
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

%.dll.so: %.spec $(NIMSRCS) $(SRCDIR)/steam_api.nim $(SIGNATURESFILE)
	$(NIMC) c -d:specname=$< -d:cdfile=$(SIGNATURESFILE) \
            --passC:"-m$(ARCH)" --passL:"-m$(ARCH)" --cpu:$(NIMARCH) \
            --nimcache:$@.nimcache -o:$@ \
            steam_api.nim

%.spec: %.orig_spec | $(DLLPARSER)
ifeq ($(ARCH), 64)
	$(DLLPARSER) $(VERSIONSDIR) "$(VERSIONSDIR)64" < $< > $@
	sed -i 's/versions/versions64/' $@
else
	$(DLLPARSER) $(VERSIONSDIR) < $< > $@
endif

%.orig_spec: %.dll
	cd $(dir $<); \
	$(WINEDUMP) spec $<; \
	$(RM) $(@:%.orig_spec=%_main.c) Makefile.in; \
	$(MV) $(@:%.orig_spec=%.spec) $@

$(SIGNATURESFILE): | $(SIGSEARCH)
	$(SIGSEARCH) $(STEAMCLIENT) > $(SIGNATURESFILE)

fullclean: clean
	$(MAKE) -C tools clean
	$(RM) $(SIGNATURESFILE) $(PRETARGETS) $(PRESPECS)

clean:
	$(RM) -r $(CACHEDIR)/nimcache.*
	$(RM) $(SRCDIR)/$(OUTPUTDLL) steam_api_main.c
