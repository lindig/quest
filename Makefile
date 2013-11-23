# vim:ts=8 sw=4 noet:
#
#

PREFIX  = $(HOME)
BINDIR  = $(PREFIX)/bin
OCB	= ocamlbuild

LIPSUM  = https://github.com/lindig/lipsum.git
LP	= ./lipsum/lipsum.native

all:	src	
	$(OCB) -I lua-ml -I src -libs unix src/main.native	

src:	FORCE
	$(MAKE) -C lipsum all
	$(MAKE) -C lua-ml all
	$(MAKE) -C src all

clean:
	$(OCB) -clean
	$(MAKE) -C lua-ml $@
	$(MAKE) -C src $@

update: 
	git subtree pull --prefix lipsum $(LIPSUM) master --squash      

init:	
	git subtree add --prefix lipsum $(LIPSUM) master --squash       

FORCE:
