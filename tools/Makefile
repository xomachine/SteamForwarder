
NIMC             ?= nim
RM               ?= rm
SRCDIR           ?= $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
DLLPARSER         = $(SRCDIR)/dllparser
SIGSEARCH         = $(SRCDIR)/sigsearch

all: $(SIGSEARCH) $(DLLPARSER)

clean:
	$(RM) -r $(SRCDIR)/nimcache $(SIGSEARCH) $(DLLPARSER)

$(SIGSEARCH):
	$(NIMC) c -o:$(SIGSEARCH) $(SRCDIR)/sigsearch.nim

$(DLLPARSER):
	$(NIMC) c -o:$(DLLPARSER) $(SRCDIR)/dllparser.nim
