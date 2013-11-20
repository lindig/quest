
# 61 "luaclient.nw"

# 111 "luaclient.nw"

# 126 "luaclient.nw"

# 177 "luaclient.nw"
module LuaChar = struct
    type 'a t	    = char
    let tname	    = "char"
    let eq _	    = fun x y -> x = y
    let to_string   = fun _ c -> String.make 1 c 
end

# 200 "luaclient.nw"
module Pair = struct
    type 'a t	    = 'a * 'a
    let tname	    = "pair"
    let eq _	    = fun x y -> x = y
    let to_string   = fun f (x,y) -> Printf.sprintf "(%s,%s)" (f x) (f y)
    let mk  x y     = (x,y)
    let fst         = fst
    let snd         = snd
end

module T =			    (* new types *)
    Lua.Lib.Combine.T3              (* T3 == link 3 modules *)
	(LuaChar)                   (* TV1 *)
	(Pair)                      (* TV2 *)    
	(Luaiolib.T)                (* TV3 *)

module LuaCharT     = T.TV1
module PairT        = T.TV2
module LuaioT       = T.TV3

# 146 "luaclient.nw"

# 222 "luaclient.nw"
module MakeLib 
    (CharV: Lua.Lib.TYPEVIEW with type 'a t        = 'a LuaChar.t)
    (PairV: Lua.Lib.TYPEVIEW with type 'a t        = 'a Pair.t
                             and  type 'a combined = 'a CharV.combined)
	: Lua.Lib.USERCODE with type 'a userdata' = 'a CharV.combined = struct
	
    type 'a userdata' = 'a PairV.combined
    module M (C: Lua.Lib.CORE with type 'a V.userdata' = 'a userdata') = struct
	module V = C.V
	let ( **-> ) = V.( **-> )
	let ( **->> ) x y = x **-> V.result y
        
        # 246 "luaclient.nw"
        module Map = struct
            let pair = PairV.makemap V.userdata V.projection
            let char = CharV.makemap V.userdata V.projection
        end    
        
        let init g = 
            
            # 267 "luaclient.nw"
            C.register_module "Pair"
                [ "mk", V.efunc (V.value **-> V.value **->> Map.pair) Pair.mk
                ; "fst",V.efunc (Map.pair **->> V.value)              Pair.fst
                ; "snd",V.efunc (Map.pair **->> V.value)              Pair.snd
                ] g;
            
            # 285 "luaclient.nw"
            C.register_module "Char"
                [ "mk", V.efunc (V.string **->> Map.char)
                        (function 
                        | "" -> C.error "Char.mk: empty string"   
                        | s  -> s.[0]
                        )
                ] g;         
            
            # 301 "luaclient.nw"
            C.register_module "Example" 
                ["argv",   (V.list V.string).V.embed (Array.to_list Sys.argv);
                 "getenv", V.efunc (V.string **->> V.string) Sys.getenv;
                ] g;
    end (* M *)
end (* MakeLib *)
module W = Lua.Lib.WithType (T)
module C  =
    Lua.Lib.Combine.C5  (* C5 == combine 4 code modules *)
	(Luaiolib.Make(LuaioT))
        (Luacamllib.Make(LuaioT))
	(W (Luastrlib.M))
	(W (Luamathlib.M))
	(MakeLib (LuaCharT) (PairT))

module I =			    (* interpreter *)  
    Lua.MakeInterp
	(Lua.Parser.MakeStandard)
	(Lua.MakeEval (T) (C))

let main () =
    let argv    = Array.to_list Sys.argv in
    let this    = Filename.basename (List.hd argv) in
    let args    = List.tl argv in
    let state   = I.mk () in (* fresh Lua interpreter *)
    let eval e  = ignore (I.dostring state e) in
       ( List.iter eval args
       ; exit 0
       )

let _ = main ()         (* alternatively use: module G = Lua.Run(I) *)
