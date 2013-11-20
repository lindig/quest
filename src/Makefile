# vim:ts=8 sw=4 noet:
#

TOP		:= ..

include		$(TOP)/config/config.mk

# Add here flags for profiling and debugging. On OS X, option -p (for
# time profiling) has no effect.

OCAMLC_FLAGS	:= -I $(TOP)/lua-ml -g
OCAMLOPT_FLAGS  := -I $(TOP)/lua-ml -p -ccopt -g
OCAMLOPT_FLAGS  := -I $(TOP)/lua-ml 

# -- high-level targets
.PHONY:	    all doc clean pdf test

all:	    $(QUEST_BINARY)
doc:	    pdf
clean:
	    rm -f *.cmx *.cmo *.cmi *.o *.ml *.mli quest.opt quest.byte
	    rm -f *.log *.pdf *.aux *.inc *.tex *.out
	    rm -f DEPEND
	    rm -f quest.c
	    rm -f quest.man
	    rm -f quest-main.* quest-callee.* quest-test
	    rm -f quest-test quest-test.c

$(TOP)/config/config.mk: $(TOP)/configure
	    @echo "Did you run $(TOP)/configure?"
	    exit 1

test:	    $(QUEST_BINARY)
	    ./$(QUEST_BINARY) -test ansi > /dev/null
	    ./$(QUEST_BINARY) -test gcc  > /dev/null
	    ./$(QUEST_BINARY) -test mips > /dev/null
	    ./$(QUEST_BINARY) -test demo > /dev/null
	    
	    ./$(QUEST_BINARY) -n 10 -s 3 -test ansi > quest-test.c
	    $(CC) -O3 -o quest-test quest-test.c
	    ./quest-test 
	    
	    $(CC) -O3 -DQUEST_FAILED -o quest-test quest-test.c
	    ./quest-test
	    
	    # rm -f quest-test quest-test.c
	    ./$(QUEST_BINARY) -2 -n 10 -s 3 -test ansi
	    $(CC) -O3 -c quest-main.c
	    $(CC) -O3 -c quest-callee.c
	    $(CC) -O3 -o quest-test quest-callee.o quest-main.o
	    ./quest-test
	    
	    $(CC) -O3 -DQUEST_FAILED -c quest-main.c
	    $(CC) -O3 -DQUEST_FAILED -c quest-callee.c
	    $(CC) -O3 -o quest-test quest-callee.o quest-main.o
	    ./quest-test
	    # rm -f quest-main.* quest-callee.* quest-test

# -- important files

ML :=       util.ml         \
	    prg.ml	    \
	    pretty.ml       \
	    randomize.ml    \
	    cee.ml          \
	    ppcee.ml	    \
	    randinit.ml     \
	    unique.ml       \
	    rtype.ml	    \
	    strategy.ml	    \
	    tc.ml	    \
	    emit.ml         \
	    lualink.ml	    \
	    luacode.ml	    \
	    main.ml         \

MLI :=      $(patsubst %.ml, %.mli, $(ML))
CMO :=      $(patsubst %.ml, %.cmo, $(ML))
CMX :=      $(patsubst %.ml, %.cmx, $(ML))
OBJ :=      $(patsubst %.ml, %.o  , $(ML))

TEX :=      $(patsubst %.ml, %.tex, $(ML))
INC :=      $(patsubst %.ml, %.inc, $(ML))
PDF :=      $(patsubst %.ml, %.pdf, $(ML))

# -- libraries

LIBCMO :=   unix.cma  lua-std.cma
LIBCMX :=   unix.cmxa lua-std.cmxa


# -- rules

%.ml:       %.nw
	    $(NOTANGLE) '-L# %L "%F"%N' -R$@ $< > $@

%.mli:      %.nw
	    $(NOTANGLE) '-L# %L "%F"%N' -R$@ $< > $@

%.sig:	    %.ml
	    $(OCAMLC) $(OCAMLC_FLAGS) -c -i $< > $@

%.cmo:      %.ml
	    $(OCAMLC) $(OCAMLC_FLAGS) -c $<

%.cmx:      %.ml
	    $(OCAMLOPT) $(OCAMLOPT_FLAGS) -c $<

%.cmi:      %.mli
	    $(OCAMLC) $(OCAMLC_FLAGS) -c $<

# -- special targets

quest.man:  $(TOP)/doc/quest.pod
	    pod2text $< > $@

# -- Lua source files. Order is important!

LUACODE	=   ../share/quest.lua	\
	    ../share/ansi.lua	\
	    ../share/cc.lua	\
	    ../share/gcc.lua	\
	    ../share/mips.lua	\
	    ../share/demo.lua	\

luacode.ml: quest.man Makefile $(LUACODE)
	    echo 'let quest = "'		    >  $@
	    sed 's/\\/\\\\/g;s/"/\\"/g' $(LUACODE)  >> $@
	    echo '"'				    >> $@
	    echo 'let manual = "'		    >> $@
	    sed 's/\\/\\\\/g;s/"/\\"/g' quest.man   >> $@
	    echo '"'				    >> $@
	    echo 'let date = "$(DATE)"'		    >> $@

# -- binaries

quest.byte: $(CMO)
	    $(OCAMLC) $(OCAMLC_FLAGS) -o $@ $(LIBCMO) $(CMO) 

quest.opt:  $(CMX)
	    $(OCAMLOPT) $(OCAMLOPT_FLAGS) -o $@ $(LIBCMX) $(CMX) 

	    
# -- documentation

RERUN =     Rerun (LaTeX|to get cross-references right)

pdf:	    $(PDF)

%.pdf:      %.tex
	    $(LATEX) "\\scrollmode \\input $<";\
	    log=$(basename $<).log ;\
	    ltxcount=3 ;\
	    while egrep -s "$(RERUN)" $$log && [ $$ltxcount -gt 0 ]; do \
		$(LATEX) "\\scrollmode \\input $<" ;\
		ltxcount=`expr $$ltxcount - 1` ;\
	    done

%.inc:      %.nw
	    $(NOWEAVE) -delay $< > $@

%.tex:	%.inc
	    echo "    \documentclass[11pt]{article}	"  > $@
	    echo "    \usepackage{a4wide}		" >> $@
	    echo "    \usepackage{hyperref}		" >> $@
	    echo "    \usepackage{noweb}		" >> $@
	    echo "    \noweboptions{breakcode}		" >> $@
	    echo "    \input{$(TOP)/config/macros.tex}	" >> $@
	    echo "    \begin{document}			" >> $@
	    echo "    \input{$<}			" >> $@
	    echo "    \end{document}			" >> $@

# -- dependencies

DEPEND:	    $(ML) $(MLI)
	    $(OCAMLDEP) $(ML) $(MLI) > DEPEND	

include	    DEPEND   		
