# vim:ts=8 sw=4 noet:
#
# See also:
# src/Makefile	    - does all the real work of compilation
#

PREFIX  = $(HOME)
BINDIR  = $(PREFIX)/bin
LP	= lipsum

OCB	= ocamlbuild
LIPSUM  = https://github.com/lindig/lipsum.git

all:	src	
	ocamlbuild -I lua-ml -I src -libs unix src/main.native	

src:
	$(MAKE) -C lua-ml all
	$(MAKE) -C src all

clean:
	ocamlbuild -clean

update: 
	git subtree pull --prefix lipsum $(LIPSUM) master --squash      

init:	
	git subtree add --prefix lipsum $(LIPSUM) master --squash       

FORCE:
