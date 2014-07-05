
# 43 "tc.nw"
module R  = Randomize
module RT = Rtype
module S  = Strategy
module C  = Cee


# 9 "tc.nw"
type storage = Static | Automatic

type t = 
    { ty:       Cee.ty
    ; storage:  storage
    ; seed:     int         (* seed for this test case *)
    ; uniq:     Unique.t    (* source for names *)
    }

type value  =  
    { vty:      Cee.ty              (* type of this value *)
    ; vinit:    Cee.init            (* value that matches ty *)
    ; vname:    Cee.name            (* globally unqiue *)
    }

type func = 
    { funiq:    Unique.t        (* source for names *)
    ; fseed:    int             (* seed used for this testcase *)
    ; fstatic:  bool            (* function under test static or not? *)
    ; fargs:    value list      (* parameters *)
    ; fvarargs: value list      (* varargs following args *)
    ; freturn:  value           (* return value *)
    }



# 48 "tc.nw"


let (@@) f x = f x
let fail fmt = Printf.kprintf failwith fmt

# 58 "tc.nw"
let pair_with_name uniq tys = List.map (fun ty -> Unique.parameter uniq, ty) tys

let testcase strategy size =
    let uniq        = Unique.make () in
    let seed        = Prg.state ()   in (* obtain actual seed *)
    let fty =
        { C.return  = RT.run strategy.S.return uniq size 
        ; C.args    = pair_with_name uniq @@ RT.run strategy.S.args uniq size
        ; C.varargs = RT.run strategy.S.varargs uniq size 
        } 
    in  { ty        = C.Fun(fty)
        ; storage   = if RT.run strategy.S.static uniq size 
                      then Static
                      else Automatic
        ; seed      = seed
        ; uniq      = uniq
        }

let arg_value uniq (name,ty) = 
    { vty   = ty
    ; vinit = Randinit.init ty
    ; vname = Unique.variable uniq
    }

let vararg_value uniq ty =
    { vty   = ty
    ; vinit = Randinit.init ty
    ; vname = Unique.variable uniq
    }

let return_value = vararg_value

let to_func t =
    let uniq = t.uniq in
    let return, args, varargs = match t.ty with
        | C.Fun({C.args=a; C.varargs=va; C.return=r}) -> r,a,va
        | _ -> fail "to.func: expected function type" 
    in
    { funiq    = t.uniq
    ; fseed    = t.seed
    ; fstatic  = t.storage = Static
    ; fargs    = List.map (arg_value uniq)    args
    ; fvarargs = List.map (vararg_value uniq) varargs
    ; freturn  = return_value uniq return
    }
    

let rec collect f = function
    | 0 -> []
    | n -> f () :: collect f (n-1)

let generate  strategy ~n ~size = 
    collect (fun () -> testcase strategy size) n
let generate' strategy ~n ~size = 
    collect (fun () -> to_func @@ testcase strategy size) n
