#
# Lua ML - an embeddable  Lua 2.5 interpreter implemented in Objective Caml
#

TOP =		..
LP =		$(TOP)/lipsum/lipsum.native
OCY =		ocamlyacc		

SRC =
SRC += lua.ml
SRC += lua.mli
SRC += luaast.ml
SRC += luaast.mli
SRC += luabaselib.ml
SRC += luabaselib.mli
SRC += luacamllib.ml
SRC += luacamllib.mli
SRC += luacode.mli
SRC += luafloat.mll
SRC += luahash.ml
SRC += luahash.mli
SRC += luainterp.ml
SRC += luainterp.mli
SRC += luaiolib.ml
SRC += luaiolib.mli
SRC += lualib.ml
SRC += lualib.mli
SRC += lualink.ml
SRC += lualink.mli
SRC += luamathlib.ml
SRC += luamathlib.mli
SRC += luaparser.mli
SRC += luaparser.mly
SRC += luarun.ml
SRC += luarun.mli
SRC += luascanner.mll
SRC += luasrcmap.ml
SRC += luasrcmap.mli
SRC += luastrlib.ml
SRC += luastrlib.mli
SRC += luavalue.ml
SRC += luavalue.mli

all:		src

clean: 
		rm -f *.ml *.mli *.mly *.mll
		rm -rf _build

%.ml:		%.nw
		$(LP) tangle -f cpp $@ $< > $@

%.mli:		%.nw
		$(LP) tangle -f cpp $@ $< > $@

luafloat.mll:   luavalue.nw
		$(LP) tangle -f cpp $@ $< > $@

luainterp.ml:   luastdinterp.nw
		$(LP) tangle -f cpp $@ $< > $@

luainterp.mli:  luastdinterp.nw
		$(LP) tangle -f cpp $@ $< > $@

luaparser.mli:  luasyntax.nw
		$(LP) tangle -f cpp $@ $< > $@

luaparser.mly:  luasyntax.nw
		$(LP) tangle -f cpp $@ $< > $@

luascanner.mll: luasyntax.nw
		$(LP) tangle -f cpp $@ $< > $@

src:		$(SRC)
		mv luaparser.mly luaparsex.mly
		$(OCY) luaparsex.mly
		mv luaparsex.ml luaparser.ml
		( sed '/^val/,$$d' luaparsex.mli ;\
		$(LP) tangle luaparser.mli luasyntax.nw ) > luaparser.mli
		rm -f luaparsex.mli

		
