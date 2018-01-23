
NIMC             ?= nim
RM               ?= rm
SRCDIR           ?= $(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
DLLPARSER         = $(SRCDIR)/dllparser
SIGSEARCH         = $(SRCDIR)/sigsearch
BINUTILSVER      ?= $(shell ld -v | grep -o [0-9]\.[0-9][0-9])
ifeq "$(shell expr $(BINUTILSVER) \> 2.28)" "1"
  ADDITIONALARGS  = -d:post_binutils229
endif

all: $(SIGSEARCH) $(DLLPARSER)

clean:
	$(RM) -r $(SRCDIR)/nimcache $(SIGSEARCH) $(DLLPARSER)

$(SIGSEARCH):
	$(NIMC) c $(ADDITIONALARGS) -o:$(SIGSEARCH) $(SRCDIR)/sigsearch.nim

$(DLLPARSER):
	$(NIMC) c $(ADDITIONALARGS) -o:$(DLLPARSER) $(SRCDIR)/dllparser.nim
