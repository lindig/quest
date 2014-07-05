
# 30 "lualink.nw"
module LuaCee = struct
    module C   = Cee
    module PPC = Ppcee
    exception Error of string
    
    type 'a t           = C.ty
    let tname           = "C type"
    let eq _            = fun (x:Cee.ty) (y:Cee.ty) -> x = y
    let linewidth       = 72
    let to_string f t   = Pretty.to_string linewidth (PPC.ty t)

    let error fmt = Printf.kprintf (fun msg -> raise (Error msg)) fmt
    let signed t        = C.Int(t, C.Signed)

    let char            = signed C.Char
    let short           = signed C.Short
    let int             = signed C.IInt
    let long            = signed C.Long
    let llong           = signed C.LongLong

    let bitfield        = function
    | n when n > 0      -> C.Bitfield(n,C.Signed)
    | n                 -> error "Width in Cee.Bitfield(%d) not positive" n

    let float           = C.Float (C.FFloat)
    let double          = C.Float (C.Double)
    let ldouble         = C.Float (C.LongDouble)

    let pointer t           = C.Ptr(t)
    let array t size        = C.Array(t,size)
    let structure name ts   = C.Struct(name,ts)
    let union name ts       = C.Union(name,ts)
end    

# 69 "lualink.nw"
module LuaGen = struct
    type 'a t           = 'a Rtype.t
    let tname           = "generator"
    let eq _            = fun _ _ -> false
    let to_string f t   = "<generator>"
end

# 81 "lualink.nw"
module LuaTest = struct
    type 'a t           = Tc.func list
    let tname           = "testcases"
    let eq _            = fun x y -> x = y
    let to_string f t   = "<testcases>"
end

# 94 "lualink.nw"
module LuaUniq = struct
    type 'a t           = Unique.t
    let tname           = "unique"
    let eq _            = fun x y -> x = y
    let to_string f t   = "<unique>"
end

# 108 "lualink.nw"
module LuaFile = struct
    exception Error of string
    let error fmt = Printf.kprintf (fun msg -> raise (Error msg)) fmt
    
    let flag = function
        | "rdonly"  -> Open_rdonly      
        | "wronly"  -> Open_wronly      
        | "append"  -> Open_append      
        | "creat"   -> Open_creat       
        | "trunc"   -> Open_trunc       
        | "excl"    -> Open_excl        
        | "binary"  -> Open_binary      
        | "text"    -> Open_text        
        | "nonblock"-> Open_nonblock    
        | x         -> error "unknown file mode %s" x
end

# 134 "lualink.nw"
module T        = Lua.Lib.Combine.T5
                    (LuaCee) (LuaGen) (LuaTest) (Luaiolib.T) (LuaUniq)
module LuaCeeT  = T.TV1
module LuaGenT  = T.TV2
module LuaTestT = T.TV3
module LuaIOT   = T.TV4
module LuaUniqT = T.TV5
module W        = Lua.Lib.WithType (T)

module MakeLib 
    (LuaCeeV: Lua.Lib.TYPEVIEW with type 'a t        = 'a LuaCee.t)
    (LuaGenV: Lua.Lib.TYPEVIEW with type 'a t        = 'a LuaGen.t
                               and  type 'a combined = 'a LuaCeeV.combined)  
    (LuaTestV:Lua.Lib.TYPEVIEW with type 'a t        = 'a LuaTest.t
                               and  type 'a combined = 'a LuaCeeV.combined)  
    (InOutV : Lua.Lib.TYPEVIEW with type 'a t        = 'a Luaiolib.T.t    
                               and  type 'a combined = 'a LuaCeeV.combined)
    (LuaUniqV:Lua.Lib.TYPEVIEW with type 'a t        = 'a LuaUniq.t
                               and  type 'a combined = 'a LuaCeeV.combined)

    (* : Lua.Lib.USERCODE with type 'a userdata' = 'a LuaCeeV.combined*) =  struct

    type 'a userdata' = 'a LuaCeeV.combined
    module M (C: Lua.Lib.CORE with type 'a V.userdata' = 'a userdata') = struct
        module V = C.V
        let ( **->  )       = V.( **-> )
        let ( **->> ) x y   = x **-> V.result y
        
        let func f x    = try V.efunc f x with 
                            | LuaCee.Error msg  -> C.error msg
                            | Rtype.Error msg   -> C.error msg
                            | LuaFile.Error msg -> C.error msg
                            | Sys_error msg     -> C.error msg
        
# 192 "lualink.nw"
let ctype       = LuaCeeV.makemap  V.userdata V.projection
let tests       = LuaTestV.makemap V.userdata V.projection
let channel     = InOutV.makemap   V.userdata V.projection
let inchan      = Luaiolib.in'       channel  V.projection
let outchan     = Luaiolib.out       channel  V.projection
let uniq        = LuaUniqV.makemap V.userdata V.projection

# 206 "lualink.nw"
let listpair a b =
    let values = V.list V.value in
    { V.embed   = (fun ps -> values.V.embed
        (List.fold_right 
            (fun (x,y) t -> a.V.embed x :: b.V.embed y :: t) ps []))
    ; V.project = (fun l ->
        let rec cut = function
            | x :: y :: ps -> (a.V.project x, b.V.project y) :: cut ps
            | []           -> []
            | [x]          -> V.projection l "list of pairs" 
        in
            cut (values.V.project l))
    ; V.is = (fun l -> 
        values.V.is l && (List.length (values.V.project l) mod 2 = 0))
    }        

# 234 "lualink.nw"
let gen ty =
    let gen      = LuaGenV.makemap V.userdata V.projection in
    let (>>=)    = Rtype.bind   in
    let return   = Rtype.return in
        { V.embed = 
            (fun g -> gen.V.embed (g >>= fun x -> return (ty.V.embed x)))
        ; V.project = 
            (fun v -> gen.V.project v >>= fun x -> return (ty.V.project x))
        ; V.is = 
            (fun v -> gen.V.is v)
        }

# 251 "lualink.nw"
let genv  = gen V.value             (* value generator          *)
let geni  = gen V.int               (* int   generator          *)
let genc  = gen ctype               (* ctype generator          *)
let gencs = gen (V.list ctype)      (* (ctype list) generator   *)
let genb  = gen V.bool

# 263 "lualink.nw"
let strategy =
    let module S = Strategy in
    let str      = V.string.V.embed in
    let embed s  =
        V.Table (V.Table.of_list 
            [ "result",     genc.V.embed s.S.return
            ; "args",       gencs.V.embed s.S.args
            ; "varargs",    gencs.V.embed s.S.varargs
            ; "static",     genb.V.embed s.S.static
            
            ]) in
    let project v = match v with 
        | V.Table t ->
            { S.return     = genc.V.project  (V.Table.find t (str "result"))
            ; S.args       = gencs.V.project (V.Table.find t (str "args"))
            ; S.varargs    = gencs.V.project (V.Table.find t (str "varargs"))
            ; S.static     = genb.V.project  (V.Table.find t (str "static"))
            }
        | _ -> V.projection v "not a table as expected for a strategy" in
    { V.embed   = embed
    ; V.project = project
    ; V.is      = function V.Table _ -> true | _ -> false
    }


# 167 "lualink.nw"

        
# 301 "lualink.nw"
let init g = 
    C.register_module "Cee" 
    [ "char",       ctype.V.embed LuaCee.char
    ; "short",      ctype.V.embed LuaCee.short
    ; "int",        ctype.V.embed LuaCee.int
    ; "long",       ctype.V.embed LuaCee.long
    ; "longlong",   ctype.V.embed LuaCee.llong
    ; "float",      ctype.V.embed LuaCee.float
    ; "double",     ctype.V.embed LuaCee.double
    ; "bitfield",   func (V.int **->> ctype) LuaCee.bitfield
    ; "longdouble", ctype.V.embed LuaCee.ldouble
    ; "unsigned",   func    (ctype **->> ctype) Cee.unsigned
    ; "pointer",    V.efunc (ctype **->> ctype) LuaCee.pointer
    ; "array",      V.efunc (ctype **-> V.int **->> ctype) LuaCee.array
    ; "struct",     V.efunc (V.string **-> V.option (listpair V.string ctype)
                                      **->> ctype) LuaCee.structure
    ; "union",      V.efunc (V.string **-> V.option (listpair V.string ctype)
                                      **->> ctype) LuaCee.union
    
    ] g;
    
    C.register_module "Rand" 
    [ "unit",       V.efunc (V.value **->> genv) Rtype.return (* KW in Lua *)
    ; "bind",       V.efunc (genv **-> V.func (V.value **->> genv) **->> genv)
                         Rtype.bind
    ; "run",        V.efunc (genv **-> uniq **-> V.int **->> V.value) Rtype.run
    ; "smaller",    V.efunc (V.list genv **->> genv) 
                        (fun gens -> Rtype.smaller (Rtype.oneof gens))
    ; "iszero",     genb.V.embed Rtype.iszero
    ; "size",       geni.V.embed Rtype.size
    ; "integer",    V.efunc (V.int **->> geni) Rtype.integer
    ; "flip",       genb.V.embed Rtype.flip
    (* generic generators *)
    ; "choose",     V.efunc (V.int **-> V.int **->> geni) Rtype.choose 
    ; "elements",   V.efunc (V.list V.value **->> genv) Rtype.elements
    ; "oneof",      V.efunc (V.list genv **->> genv) Rtype.oneof
    ; "list",    V.efunc (geni **-> genv **->> gen (V.list V.value)) Rtype.list
    ; "freq",       V.efunc (listpair V.int genv **->> genv) Rtype.freq
    ; "concat",     V.efunc (V.list (gen (V.list V.value)) **->>
                        gen (V.list V.value)) Rtype.concat
    (* C generators *)
    ; "char",       genc.V.embed Rtype.char
    ; "short",      genc.V.embed Rtype.short
    ; "int",        genc.V.embed Rtype.int
    ; "long",       genc.V.embed Rtype.long
    ; "longlong",   genc.V.embed Rtype.longlong
    ; "unsigned",   func (genc **->> genc) Rtype.unsigned
    ; "float",      genc.V.embed Rtype.float
    ; "double",     genc.V.embed Rtype.double
    ; "longdouble", genc.V.embed Rtype.longdouble
    ; "any_int",    genc.V.embed Rtype.any_int
    ; "any_float",  genc.V.embed Rtype.any_float
    ; "bitfield",   V.efunc (geni **->> genc) Rtype.bitfield
    ; "array",      V.efunc (genc **-> geni **->> genc) Rtype.array
    ; "pointer",    V.efunc (genc **->> genc) Rtype.pointer
    ; "struct_",    V.efunc (genc **-> geni **->> genc) Rtype.structure'
    ; "union_",     V.efunc (genc **-> geni **->> genc) Rtype.union'
    ; "struct",     V.efunc (gencs **->> genc) Rtype.structure
    ; "union",      V.efunc (gencs **->> genc) Rtype.union
    ] g;

    C.register_module "Test"
    [ "generate",   V.efunc (strategy **-> V.int **-> V.int **->> tests) 
                            (fun s n size -> Tc.generate' s ~n ~size)
    ] g;

    C.register_module "Emit"
    [ "mono",       V.efunc (outchan **-> tests **->> V.unit) Emit.standalone 
    ; "stereo",     V.efunc (outchan **-> outchan **-> tests **->> V.unit) 
                    (fun main client tests -> 
                        Emit.modularized ~main ~client tests)
    ] g;
    
    C.register_module "Uniq"
    [ "make",       V.efunc (V.unit **->> uniq) Unique.make
    ] g;

    C.register_module "File"
    [ "stdout"    , outchan.V.embed stdout
    ; "stderr"    , outchan.V.embed stderr
    ; "stdin"     , inchan.V.embed  stdin
    ; "open_out"  , func (V.string **->> outchan) open_out
    ; "open_in"   , func (V.string **->> inchan ) open_in
    ; "close_out" , func (outchan  **->> V.unit ) close_out
    ; "close_in"  , func (inchan   **->> V.unit ) close_in
    ; "write"     , func (outchan  **-> V.string **->> V.unit) output_string
    ] g;

# 168 "lualink.nw"

    end (* M *)    
end (* MakeLib *)

module C = Lua.Lib.Combine.C5
        (Luaiolib.Make(LuaIOT))
        (Luacamllib.Make(LuaIOT))
        (W (Luastrlib.M))
        (W (Luamathlib.M))
        (MakeLib (LuaCeeT) (LuaGenT) (LuaTestT) (LuaIOT) (LuaUniqT))

module I = 
    Lua.MakeInterp
        (Lua.Parser.MakeStandard)
        (Lua.MakeEval (T) (C))
