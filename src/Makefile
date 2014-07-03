# vim:ts=8 sw=4 noet:
#

TOP =	    ..
LP =	    $(TOP)/lipsum/lipsum.native

SRC =
SRC += cee.ml
SRC += cee.mli
SRC += emit.ml
SRC += emit.mli
SRC += main.ml
SRC += main.mli
SRC += ppcee.ml
SRC += ppcee.mli
SRC += pretty.ml
SRC += pretty.mli
SRC += prg.ml
SRC += prg.mli
SRC += randinit.ml
SRC += randinit.mli
SRC += randomize.ml
SRC += randomize.mli
SRC += rtype.ml
SRC += rtype.mli
SRC += strategy.ml
SRC += strategy.mli
SRC += tc.ml
SRC += tc.mli
SRC += testcase.ml
SRC += testcase.mli
SRC += unique.ml
SRC += unique.mli
SRC += util.ml
SRC += util.mli

# -- high-level targets
.PHONY:	    all src clean 

all:	    src

src:	    $(SRC) luacode.ml

%.ml:	    %.nw
	    $(LP) tangle -f cpp $@ $< > $@

%.mli:	    %.nw
	    $(LP) tangle -f cpp $@ $< > $@

clean:
	    rm -f quest.man luacode.ml
	    rm -f *.ml *.mli

# -- special targets

quest.man:  $(TOP)/doc/quest.pod
	    pod2text $< > $@

# -- Lua source files. Order is important!

LUACODE	=   
LUACODE +=  $(TOP)/share/quest.lua	
LUACODE +=  $(TOP)/share/ansi.lua
LUACODE +=  $(TOP)/share/cc.lua
LUACODE +=  $(TOP)/share/gcc.lua
LUACODE +=  $(TOP)/share/mips.lua
LUACODE +=  $(TOP)/share/demo.lua
LUACODE +=  $(TOP)/share/toy.lua

luacode.ml: quest.man Makefile $(LUACODE)
	    echo 'let quest = "'		    >  $@
	    sed 's/\\/\\\\/g;s/"/\\"/g' $(LUACODE)  >> $@
	    echo '"'				    >> $@
	    echo 'let manual = "'		    >> $@
	    sed 's/\\/\\\\/g;s/"/\\"/g' quest.man   >> $@
	    echo '"'				    >> $@
	    echo 'let date = "'`date`'"'	    >> $@


