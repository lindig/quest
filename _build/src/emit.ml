
# 25 "emit.nw"
module C   = Cee
module T   = Tc
module PPC = Ppcee

# 45 "emit.nw"
let linewidth = 78

# 51 "emit.nw"
let sprintf         = Printf.sprintf
let (@@) f x        = f x
let call f args     = C.Call(C.Const f, args)
let id x            = C.ID x
let _file_          = id "__FILE__"
let _line_          = id "__LINE__"
let errors          = id "errors"
let str s           = C.Const ("\""^s^"\"")
let neq x y         = C.Infix(x,C.Neq,y)
let eq x y          = C.Infix(x,C.Eq,y)
let return x        = C.Return(Some x)
let stmt e          = C.Expr(e)
let callstmt f args = stmt @@ call f args
let (<--) x y       = stmt @@ C.Assign(id x,y)
let nop             = C.Nop

# 75 "emit.nw"
let failed =
    { C.name    = "failed"
    ; C.static  = true
    ; C.ty =
        { C.args    = ["line", C.int]
        ; C.return  = C.Void
        ; C.varargs = []
        }
    ; C.decls   = []
    ; C.body    =
        [ callstmt "printf" [str "failed in %s: %d\\n"; _file_; C.ID "line"]
        ; stmt (C.Postfix(errors, C.PostInc))
        ]
    }    

# 98 "emit.nw"
let cmp x y = C.IfThen(neq x y, stmt @@ call "failed" [_line_])
let cmp x y = stmt @@ call "QUEST_ASSERT" [eq x y]

# 105 "emit.nw"
let rec enum f n x = match n with   
    | 0 -> []
    | n -> f (n-1) x :: enum f (n-1) x

# 117 "emit.nw"
let rec rvalues exps = function
    | C.Fun(_)          -> failwith "rvalue: no rvalue for function"
    | C.Void            -> failwith "rvalue: no rvalue for void"
    | C.Struct(_,None)  -> failwith "rvalue: struct reference"
    | C.Union(_,None)   -> failwith "rvalue: union reference"
    | C.TyName(_)       -> failwith "rvalue: named type"
    | C.Union(_,Some [])-> []
    | C.Int(_)          -> exps
    | C.Bitfield(_)     -> exps
    | C.Float(_)        -> exps
    | C.Ptr(_)          -> exps
    | C.Array(ty,n) ->
        let access n e = C.Access(e,C.IntConst n) in
        let exps'      = List.map (enum access n) exps in
            rvalues (List.concat exps') ty
    | C.Struct(_,Some members) ->
        let select (n,ty) = rvalues (List.map (fun e -> C.Select(e,n)) exps) ty 
        in
            List.concat (List.map select members)
    | C.Union(_,Some ((n,ty)::_)) -> 
            rvalues (List.map (fun e -> C.Select(e,n)) exps) ty

# 146 "emit.nw"
let compare t x y =
    let left, right = rvalues [C.ID x] t, rvalues [C.ID y] t in
        List.map2 (fun l r -> cmp l r) left right

# 198 "emit.nw"
let cmp_args args =
    List.concat @@ List.map (fun (n,v) -> compare v.T.vty v.T.vname n) args 

let name_for idgen v = (idgen (), v)
let seed n = C.Comment (sprintf "seed: %d" n)

let callee: T.func -> bool -> C.fundef = fun t static ->
    let mk_param_id () = Unique.parameter t.T.funiq in
    let mk_var_id ()   = Unique.variable t.T.funiq in
    let name           = Unique.func t.T.funiq "callee" in (* name of callee *)
    let has_vargs      = t.T.fvarargs <> [] in
    let args         = List.map (name_for mk_param_id) t.T.fargs in
    let rtn          = return (id t.T.freturn.T.vname) in
    let formal x     = (x.T.vname, C.strip x.T.vty) in 
    if has_vargs then
        let mk_typedef ()= Unique.typedef  t.T.funiq in
        let mk v      = (mk_var_id (), v, mk_typedef()) in
        let vargs     = List.map mk t.T.fvarargs in
        let decl (n,v,t)  = C.VarDecl(n,C.TyName t ,None) in
        let tdecl (n,v,t) = match C.strip v.T.vty with
            | C.Array(ty,size)  -> C.Typedef(t, C.Ptr(ty))
            | ty                -> C.Typedef(t, ty) 
        in
        let last_arg  = fst @@ Util.last args in
        let decl_ap   = C.VarDecl("ap", C.TyName "va_list", None) in
        let va_start  = stmt @@ call "va_start" [id "ap"; id last_arg] in
        let va_end    = stmt @@ call "va_end" [id "ap"] in
        let va_arg (n,v,t) = n <-- call "va_arg" [id "ap"; C.Type (C.TyName t)]
        in
            { C.name    = name
            ; C.static  = static
            ; C.ty =
                { C.args    = List.map (fun (n,v) -> n, C.strip v.T.vty) args  
                ; C.varargs = List.map (fun x -> C.strip x.T.vty) t.T.fvarargs
                ; C.return  = C.strip t.T.freturn.T.vty
                }
            ; C.decls   = decl_ap :: List.map tdecl vargs @ List.map decl vargs
            ; C.body    =
                   seed t.T.fseed
                :: va_start 
                :: cmp_args args
                @  List.map va_arg vargs 
                @  cmp_args (List.map (fun (n,v,t) -> (n,v)) vargs)
                @  [va_end;rtn]
            }    
    else
            { C.name    = name
            ; C.static  = static
            ; C.ty =
                { C.return  = C.strip t.T.freturn.T.vty
                ; C.args    = List.map (fun (n,v) -> n,C.strip v.T.vty) args  
                ; C.varargs = List.map (fun x -> C.strip x.T.vty) t.T.fvarargs
                }
            ; C.decls   = []
            ; C.body    = seed t.T.fseed :: cmp_args args @ [rtn]
            }
        

# 262 "emit.nw"
let caller: T.func -> C.fundef -> C.fundef = fun testcase callee ->
    let ret   = Unique.variable testcase.T.funiq in   
    let args  = List.map (fun t -> id t.T.vname) 
                    (testcase.T.fargs @ testcase.T.fvarargs) in
    { C.name    = Unique.func testcase.T.funiq "caller"
    ; C.ty =
        { C.args    = []
        ; C.varargs = []
        ; C.return  = C.Void
        }
    ; C.static  = true  
    ; C.decls   = [C.VarDecl (ret,C.strip testcase.T.freturn.T.vty,None)]
    ; C.body    = 
          [ seed testcase.T.fseed
          ; ret <-- (call callee.C.name args)
          ]
          @ compare testcase.T.freturn.T.vty testcase.T.freturn.T.vname ret
    }

# 288 "emit.nw"
let errors: C.scope -> C.toplevel = fun scope ->
    let init = match scope with
    | C.Static | C.Public -> Some (C.SingleInit(C.IntConst 0))
    | C.Extern            -> None 
    in
        C.TopDecl(scope, C.VarDecl("errors", C.int, init))
    

# 302 "emit.nw"
let header =
    let t =
        { C.return  = C.int
        ; C.args    = ["fmt", C.string]
        ; C.varargs = [C.int]   (* this is a lie *)
        } 
    in C.TopDecl(C.Extern, C.VarDecl("printf", C.Fun(t), None))

# 317 "emit.nw"
let vardecl: C.scope -> T.value -> C.toplevel = fun scope t ->
    match scope with
    | C.Static | C.Public -> 
        C.TopDecl(scope,C.VarDecl(t.T.vname,t.T.vty, Some t.T.vinit))
    | C.Extern            -> 
        C.TopDecl(scope,C.VarDecl(t.T.vname,t.T.vty, None))

let vardecls: C.scope -> T.func -> C.toplevel list = fun s t -> 
    List.map (vardecl s) (t.T.freturn :: t.T.fargs @ t.T.fvarargs)

# 331 "emit.nw"
let fundecl: C.fundef-> C.toplevel = fun f ->
    let decl  = C.VarDecl(f.C.name, C.Fun(f.C.ty), None) in
    let scope = if f.C.static then C.Static else C.Extern in (*XXX*)
         C.TopDecl(scope, decl)

# 341 "emit.nw"
let main callers =
    let argc    = "argc", C.int in
    let argv    = "argv", C.Ptr(C.Ptr(C.char)) in
    let calls   = List.map (fun f -> stmt (call f.C.name [])) callers in
        { C.name    = "main"
        ; C.ty =
            { C.return = C.int
            ; C.args   = [argc; argv]
            ; C.varargs = []
            }
        ; C.static  = false
        ; C.decls   = []
        ; C.body    = calls @ [return (id "errors")] 
        }

# 28 "emit.nw"


module Standalone = struct
    
# 363 "emit.nw"
let testcase t =
    let vars     = vardecls C.Static t in
    let callee   = callee t t.T.fstatic in
    let caller   = caller t callee in
    let toplevel = vars @ [C.Function callee; C.Function caller] in 
        (toplevel, caller)

# 375 "emit.nw"
let emit channel ts =
    let code, callers = List.split (List.map testcase ts) in
    let prog = (* header 
            :: *) errors C.Static 
            :: C.Function(failed)  
            :: List.concat code 
             @ [C.Function(main callers)] in
    let prog = C.include_headers prog in
    let doc  = PPC.program prog in
        Pretty.to_file channel linewidth doc

# 31 "emit.nw"

end
module Modularized = struct
    
# 395 "emit.nw"
let client t =
    let vars        = vardecls C.Extern t in
    let callee      = callee t false (*not static*) in
    let toplevel    = vars @ [C.Function callee] in
        (toplevel,callee)

let provider t callee =
    let vars        = vardecls C.Public t in
    let callee'     = fundecl callee in 
    let caller      = caller t callee in
    let toplevel    = vars @ [callee']  @ [C.Function caller] in
        (toplevel,caller)

# 415 "emit.nw"
let testcase (clients,providers,callers) t =
    let clientcode, callee   = client t in
    let providercode, caller = provider t callee in
        (clientcode::clients, providercode::providers, caller::callers)


let emit_client channel clients =
    let prog = header 
            :: errors C.Extern 
            :: C.Function(failed)
            :: clients in
    let prog = C.include_headers prog in
    let doc  = PPC.program prog in
        Pretty.to_file channel linewidth doc

let emit_provider channel providers callers =
    let prog = header
             :: errors C.Public 
             :: C.Function(failed)
             :: providers 
              @ [C.Function(main callers)] in 
    let prog = C.include_headers prog in
    let doc  = PPC.program prog in
        Pretty.to_file channel linewidth doc

let emit ~main ~client ts = 
    let clients, providers, callers = List.fold_left testcase ([],[],[]) ts in 
        ( emit_client client (List.concat clients)
        ; emit_provider main (List.concat providers) callers
        )

# 34 "emit.nw"

end    

let standalone  = Standalone.emit  
let modularized = Modularized.emit
