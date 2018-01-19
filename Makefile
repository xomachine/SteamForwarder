
SRCDIR                ?= $(PWD)
NIMC                  ?= nim
WINEDUMP              ?= winedump
RM                    ?= rm
MAKE                  ?= make
STEAMCLIENT           ?= $(SRCDIR)/steamclient.so
SIGNATURESFILE        ?= $(SRCDIR)/signatures.txt
ORIGINAL_SPECFILE     ?= $(SRCDIR)/steam_api.spec
SPECFILE              ?= $(SRCDIR)/steam_api.fixed.spec
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
DLL                    = steam_api$(LIB_POSTFIX).dll
OUTPUTDLL              = $(DLL).so

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
	$(WINEDUMP) spec $(DLL)
	$(RM) $(SRCDIR)/steam_api_main.c

$(SIGNATURESFILE): $(SIGSEARCH)
	$(SIGSEARCH) $(STEAMCLIENT) > $(SIGNATURESFILE)

fullclean: clean
	$(MAKE) -C tools clean
	$(RM) $(SIGNATURESFILE)

clean:
	$(RM) -r $(SRCDIR)/nimcache
	$(RM) $(SCRDIR)/$(OUTPUTDLL) $(SPECFILE) \
           $(ORIGINAL_SPECFILE) steam_api_main.c
