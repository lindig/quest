#
# Lua ML - an embeddable  Lua 2.5 interpreter implemented in Objective Caml
#

LP =		lipsum
OCY =		ocamlyacc		

all:		src

clean: 
		rm -f *.ml *.mli *.mly *.mll
		rm -rf _build
src:
		for f in *.nw; do $(LP) expand -f cpp '*.ml*' $$f; done
		mv luaparser.mly luaparsex.mly
		$(OCY) luaparsex.mly
		mv luaparsex.ml luaparser.ml
		( sed '/^val/,$$d' luaparsex.mli ;\
		$(LP) tangle luaparser.mli luasyntax.nw ) > luaparser.mli
		rm -f luaparsex.mli

		
