# vim:ts=8 sw=4 noet:
#
# See also:
# src/Makefile	    - does all the real work of compilation
#


TOP	:=  .

# this include file defines important variables and is created
# by the ./configure script
include	    $(TOP)/config/config.mk

BINDIR	:=  $(PREFIX)/bin
MAN1DIR :=  $(PREFIX)/man/man1

DIR	:=  quest-$(DATE)
DIRARCH :=  quest-$(DATE)-$(ARCH)
TAR	:=  $(DIR).tar.gz
BINDIST :=  quest-$(DATE)-$(ARCH).tar.gz
DEB	:=  quest_1.1.0-1
DEBMAIL	:=  lindig@cs.uni-sb.de

# -- high-level targets
.PHONY:	    all doc install clean tar test-tar debian bindist osx

all:	    doc src/$(QUEST_BINARY)

doc:	    doc/quest.1 doc/quest.html doc/lua-2.5.pdf

install:    src/$(QUEST_BINARY) doc/quest.1
	    test -d $(BINDIR)  || mkdir -p $(BINDIR)
	    test -d $(MAN1DIR) || mkdir -p $(MAN1DIR)
	    install -s  src/$(QUEST_BINARY) $(BINDIR)/quest
	    cp doc/quest.1 $(MAN1DIR) && gzip -9 $(MAN1DIR)/quest.1

tar:	    $(TAR)
bindist:    $(BINDIST)    

clean:	    
	    cd src && $(MAKE) clean
	    cd lua-ml && $(MAKE) -f Makefile.alone clean
	    rm -f doc/quest.1 doc/quest.html
	    rm -f pod2htm*
	    rm -f $(DIR)
	    rm -f ChangeLog.bak
	    rm -f $(TAR) 
	    rm -f configure-stamp build-stamp 
	    rm -rf mac-osx/root mac-osx/quest.pkg*
	    rm -rf $(DEB).orig.tar.gz
	    rm -rf $(DEB)

distclean:  clean
	    rm -f config/config.mk
	    rm -f FILES
	    rm -f $(DEB).dsc $(DEB).orig.tar.gz $(DEB).tar.gz *.deb *.changes

osx:	    doc src/quest.opt
	    mkdir -p mac-osx/root/bin mac-osx/root/man/man1
	    cp src/quest.opt mac-osx/root/bin/quest
	    cp doc/quest.1   mac-osx/root/man/man1

debian:	    $(DEB)-1.deb

# -- Debian

$(DEB).orig.tar.gz: $(TAR)
	    ln -s $< $@
	    
$(DEB)-1.deb: $(DEB).orig.tar.gz
	tar zxvf $(DEB).orig.tar.gz
	mv $(DIR) $(DEB)		
	chmod +x $(DEB)/debian/rules
	(cd $(DEB) && dpkg-buildpackage -rfakeroot -sd -us -e$(DEBMAIL))
	rm -rf $(DEB)

# -- configure creates config/config.mk

$(TOP)/config/config.mk: $(TOP)/configure
	@echo "Did you run $(TOP)/configure?"
	@exit 1

# -- individual targets

src/quest.opt: ALWAYS
	$(MAKE) lua-ml/lua-std.cmxa
	$(MAKE) -C src quest.opt
	
src/quest.byte: ALWAYS
	$(MAKE) lua-ml/lua-std.cma
	$(MAKE) -C src quest.byte

doc/quest.1: doc/quest.pod 
	pod2man -r "http://www.cs.uni-sb.de/~lindig"  $< > $@
	    
doc/quest.html: doc/quest.pod
	pod2html $< > $@
	
ChangeLog:  
	svn log > $@
	     
# A dependency on ALWAYS forces a rule to execute the body. Used for
# rules that invoke Make in a subdirectory.

ALWAYS:


# -- Lua-ML
# Lua-ML is part of the C-- project (www.cminusminus.org). The latest
# version can be found there. However, to make this source code more
# self contained, I am now including Lua-ML here.
#

lua-ml/lua-std.cmxa: lua-ml ALWAYS
	make -C lua-ml -f Makefile.alone OCAMLO=$(OCAMLOPT) all.opt
	
lua-ml/lua-std.cma: lua-ml ALWAYS
	make -C lua-ml -f Makefile.alone OCAMLC=$(OCAMLC) all
	
lua-ml.tar.gz:
	$(WGET) $(WGET_OPTS) http://www.cminusminus.org/rsync/dist/lua-ml.tar.gz

# -- binary distribution packaging

$(BINDIST): src/quest.opt doc/quest.1
	rm -rf $(DIRARCH)
	mkdir $(DIRARCH)
	cp src/quest.opt $(DIRARCH)/quest
	cp doc/quest.1   $(DIRARCH)
	cp README	     $(DIRARCH)
	tar zcvf $(BINDIST) $(DIRARCH)
	rm -rf $(DIRARCH)

# -- source-distribution packaging 

FILES:	clean ChangeLog lua-ml.tar.gz
	    find . \
	         -name 'lua-ml.tar.gz' -print   \
	      -o \( -path "*/CVS/*"		\
	      -o -path "*/.*"			\
	      -o -path "./local/*"		\
	      -o -path "./www/*"		\
	      -o -path "./bugs/*"		\
	      -o -path "./tmp/*"		\
	      -o -path "./mac-osx/*"		\
	      -o -name "quest_*"		\
	      -o -name "*.tar*"			\
	      -o -name "*.deb"			\
	      -o -name "./FILES"		\
	      -o -type l			\
	      \) -prune				\
	      -o -path "./lua-ml/std"       	\
	      -o -type f -print | sort   > $@

$(TAR):	FILES
	    ln -s . $(DIR)
	    D=$(DIR); tar czvhf $(TAR) `sed "s+^\./+$$D/+" FILES` 
	    rm -f $(DIR) 

test-tar: $(TAR)
	    tar zxvf $(TAR)
	    cd $(DIR) && ./configure && $(MAKE) all
	    rm -rf $(DIR)

