
cd lua-ml
ocamlopt  -I std -c srcmap.mli
ocamlopt  -I std -c srcmap.ml
ocamlopt  -I std -c log.mli
ocamlopt  -I std -c log.ml
ocamlopt  -I std -c luahash.mli
ocamlopt  -I std -c luahash.ml
ocamlopt  -I std -c luafloat.ml
ocamlopt  -I std -c luavalue.mli
ocamlopt  -I std -c luavalue.ml
ocamlopt  -I std -c luaast.mli
ocamlopt  -I std -c luaast.ml
ocamlopt  -I std -c luaparser.mli
ocamlopt  -I std -c luaparser.ml
ocamlopt  -I std -c luascanner.ml
ocamlopt  -I std -c lualib.mli
ocamlopt  -I std -c lualib.ml
ocamlopt  -I std -c std/luainterp.mli
ocamlopt  -I std -c std/luainterp.ml
ocamlopt  -I std -c luabaselib.mli
ocamlopt  -I std -c luabaselib.ml
ocamlopt  -I std -c luarun.mli
ocamlopt  -I std -c luarun.ml
ocamlopt  -I std -c lua.mli
ocamlopt  -I std -c lua.ml
ocamlopt  -I std -c luastrlib.mli
ocamlopt  -I std -c luastrlib.ml
ocamlopt  -I std -c luamathlib.mli
ocamlopt  -I std -c luamathlib.ml
ocamlopt  -I std -c luaiolib.mli
ocamlopt  -I std -c luaiolib.ml
ocamlopt  -I std -c luacamllib.mli
ocamlopt  -I std -c luacamllib.ml
ocamlopt  -I std -a -o lua-std.cmxa srcmap.cmx log.cmx luahash.cmx luafloat.cmx luavalue.cmx luaast.cmx luaparser.cmx luascanner.cmx luabaselib.cmx lualib.cmx std/luainterp.cmx luarun.cmx lua.cmx luastrlib.cmx luamathlib.cmx luaiolib.cmx luacamllib.cmx

cd ../src
ocamlopt -I ../lua-ml -c util.mli
ocamlopt -I ../lua-ml -c util.ml
ocamlopt -I ../lua-ml -c prg.mli
ocamlopt -I ../lua-ml -c prg.ml
ocamlopt -I ../lua-ml -c pretty.mli
ocamlopt -I ../lua-ml -c pretty.ml
ocamlopt -I ../lua-ml -c randomize.mli
ocamlopt -I ../lua-ml -c randomize.ml
ocamlopt -I ../lua-ml -c cee.mli
ocamlopt -I ../lua-ml -c cee.ml
ocamlopt -I ../lua-ml -c prettycee.mli
ocamlopt -I ../lua-ml -c prettycee.ml
ocamlopt -I ../lua-ml -c randinit.mli
ocamlopt -I ../lua-ml -c randinit.ml
ocamlopt -I ../lua-ml -c unique.mli
ocamlopt -I ../lua-ml -c unique.ml
ocamlopt -I ../lua-ml -c rtype.mli
ocamlopt -I ../lua-ml -c rtype.ml
ocamlopt -I ../lua-ml -c strategy.mli
ocamlopt -I ../lua-ml -c strategy.ml
ocamlopt -I ../lua-ml -c testcase.mli
ocamlopt -I ../lua-ml -c testcase.ml
ocamlopt -I ../lua-ml -c emit.mli
ocamlopt -I ../lua-ml -c emit.ml
ocamlopt -I ../lua-ml -c lualink.mli
ocamlopt -I ../lua-ml -c lualink.ml
ocamlopt -I ../lua-ml -c luacode.mli
ocamlopt -I ../lua-ml -c luacode.ml
ocamlopt -I ../lua-ml -c main.mli
ocamlopt -I ../lua-ml -c main.ml
ocamlopt -a -o foo.cmxa util.cmx  prg.cmx  pretty.cmx  randomize.cmx  cee.cmx  prettycee.cmx  randinit.cmx  unique.cmx  rtype.cmx  strategy.cmx  testcase.cmx  emit.cmx  lualink.cmx  luacode.cmx 

ocamlopt -verbose -I ../lua-ml -o quest.exe unix.cmxa lua-std.cmxa foo.cmxa  main.cmx 
cd ..

