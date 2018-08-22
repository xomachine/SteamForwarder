
SRCDIR                ?= $(CURDIR)
NIMC                  ?= nim
WINEDUMP              ?= winedump
WINEGCC               ?= /usr/bin/winegcc
MV                    ?= mv
RM                    ?= rm
MAKE                  ?= make
ARCH                  ?= 64
NOTUNE                ?= 0

STEAMCLIENT           ?= steamclient.so
SIGNATURESFILE        ?= signatures.txt
DLL                   ?= steam_api$(LIB_POSTFIX).dll
DLLPARSER             ?= tools/dllparser
SIGSEARCH             ?= tools/sigsearch
PREFIX                ?= /usr/local
DATAPATH               = $(DESTDIR)$(PREFIX)/share/SteamForwarder
INSTALL               ?= install -Dm 755
INSTALLDATA           ?= install -Dm 644

ifeq ($(NOTUNE), 1)
  TUNEOPTS = --opt:none --passC:'-mtune=generic'
else
  TUNEOPTS =
endif
# Info to build original specs
DLL                    ?= steam_api$(LIB_POSTFIX).dll
OUTPUTDLL               = $(DLL).so
NIMSRCS                 = $(wildcard genmacros/*.nim)
VERFILES                = $(wildcard versions/*/libsteam_api.so)
WINLIBS                 = $(wildcard versions/*/steam_api.dll)
PREORIGS                = $(WINLIBS:%.dll=%.orig_spec)
# Info to build specs with arguments
ORSPECS                 = $(wildcard versions/*/steam_api.orig_spec)
PRESPECS                = $(ORSPECS:%.orig_spec=%.spec)
PRETARGETS              = $(ORSPECS:%.orig_spec=%.dll.so)

ifneq ($(ARCH), 32)
  LIBS64                = $(wildcard versions64/*/libsteam_api.so)
  VERSIONS64            = $(dir $(subst versions64,versions,$(LIBS64)))
  PRESPECS64            = $(VERSIONS64:%/=%/steam_api64.spec)
  PRETARGETS           += $(PRESPECS64:%.spec=%.dll.so)
  PRESPECS             += $(PRESPECS64)
  VERFILES             += $(LIBS64)
endif
# Info for installation
INSTALLERSCRIPT         = $(wildcard installer/*.py)
# Original specs
INSTALLALL              = $(foreach path, $(VERFILES) $(ORSPECS) $(PRESPECS) $(PRETARGETS), $(INSTALLDATA) $(path) $(DATAPATH)/$(path);)

.PHONY: all tools clean fullclean install precompile prespec preorig signatures
.SECONDARY: $(PRESPECS)

all: precompile

tools: $(SIGSEARCH) $(DLLPARSER)

precompile: $(PRETARGETS)

prespec: $(PRESPECS)

preorig: $(PREORIGS)

signatures: $(SIGNATURESFILE)

install: tools $(ORSPECS) $(PRESPECS) $(SIGNATURESFILE) $(PRETARGETS)
	$(INSTALL) -t $(DATAPATH)/tools $(SIGSEARCH) $(DLLPARSER)
	$(INSTALL) sf_install $(DATAPATH)/sf_install
	$(INSTALLALL)
	$(INSTALLDATA) -t $(DATAPATH) $(SIGNATURESFILE) steam_api.nim steam_api.nims \
	                              Makefile
	$(INSTALLDATA) -t $(DATAPATH)/installer $(INSTALLERSCRIPT)
	$(INSTALLDATA) -t $(DATAPATH)/genmacros $(NIMSRCS)
	$(INSTALL) -d $(DESTDIR)$(PREFIX)/bin
	ln -s ../share/SteamForwarder/sf_install \
	      $(DESTDIR)$(PREFIX)/bin/sf_install

$(SIGSEARCH):
	$(MAKE) -C tools TUNEOPTS="$(TUNEOPTS)" $(abspath $(SIGSEARCH))

$(DLLPARSER):
	$(MAKE) -C tools $(abspath $(DLLPARSER))

%64.dll.so: %64.spec $(NIMSRCS) steam_api.nims steam_api.nim $(SIGNATURESFILE)
	$(NIMC) c -d:specname="$(abspath $<)" --newruntime\
	          -d:cdfile="$(abspath $(SIGNATURESFILE))" \
            --passC:"-m64" --passL:"-m64" --cpu:amd64 \
            $(TUNEOPTS) --gcc.exe:$(WINEGCC) --gcc.linkerexe:$(WINEGCC) \
            --nimcache:`mktemp -d --tmpdir=$(CACHEDIR) nimcache.XXXX` -o:$@ \
            steam_api.nim

%.dll.so: %.spec $(NIMSRCS) steam_api.nims steam_api.nim $(SIGNATURESFILE)
	$(NIMC) c -d:specname="$(abspath $<)" --newruntime\
	          -d:cdfile="$(abspath $(SIGNATURESFILE))" \
            --passC:"-m32" --passL:"-m32" --cpu:i386 \
            $(TUNEOPTS) --gcc.exe:$(WINEGCC) --gcc.linkerexe:$(WINEGCC) \
            --nimcache:`mktemp -d --tmpdir=$(CACHEDIR) nimcache.XXXX` -o:$@ \
            steam_api.nim

%64.spec: %.orig_spec | $(DLLPARSER)
	$(DLLPARSER) versions versions64 < $< > $@

%.spec: %.orig_spec | $(DLLPARSER)
	$(DLLPARSER) versions < $< > $@

%.orig_spec: %.dll
	cd "`dirname "$<"`"; \
	$(WINEDUMP) spec "$<"; \
	$(RM) $(@:%.orig_spec=%_main.c) Makefile.in; \
	$(MV) $(@:%.orig_spec=%.spec) $@

$(SIGNATURESFILE): | $(SIGSEARCH)
	$(SIGSEARCH) $(STEAMCLIENT) > $(SIGNATURESFILE)

fullclean: clean
	$(MAKE) -C tools clean
	$(RM) $(SIGNATURESFILE) $(PRETARGETS) $(PRESPECS)

clean:
	$(RM) -r $(CACHEDIR)/nimcache.*
	$(RM) -r /tmp/nimcache.*
	$(RM) $(OUTPUTDLL) steam_api_main.c
