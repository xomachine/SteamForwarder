
SRCDIR                ?= $(PWD)
NIMC                  ?= nim
WINEDUMP              ?= winedump
RM                    ?= rm
MAKE                  ?= make
STEAMCLIENT           ?= $(SRCDIR)/steamclient.so
SIGNATURESFILE        ?= $(SRCDIR)/signatures.txt
SPECDIR               ?= $(SRCDIR)
ORIGINAL_SPECFILE     ?= steam_api_orig.spec
ORIGINAL_SPECPATH     ?= $(SPECDIR)/$(ORIGINAL_SPECFILE)
SPECFILE              ?= $(SPECDIR)/steam_api.spec
DLLPARSER             ?= $(SRCDIR)/tools/dllparser
SIGSEARCH             ?= $(SRCDIR)/tools/sigsearch
VERSIONSDIR           ?= $(SRCDIR)/versions

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

.PHONY: all tools clean fullclean

all: $(OUTPUTDLL)

tools: $(SIGSEARCH) $(DLLPARSER)

$(SIGSEARCH):
	$(MAKE) -C $(SRCDIR)/tools $(SIGSEARCH)

$(DLLPARSER):
	$(MAKE) -C tools $(DLLPARSER)

$(OUTPUTDLL): $(SPECFILE) $(SIGNATURESFILE)
	$(NIMC) c -d:specname=$(SPECFILE) -d:cdfile=$(SIGNATURESFILE) \
            --passC:"-m$(ARCH)" --passL:"-m$(ARCH)" --cpu:$(NIMARCH) \
            -o:$(OUTPUTDLL) steam_api.nim

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
