
# 22 "randinit.nw"
module R = Random
module C = Cee

let sprintf  = Printf.sprintf
let (@@) f x = f x

# 36 "randinit.nw"
let int width signed = match width,signed with
    | C.Char,  C.Signed     -> sprintf "'\\x%x'" (R.int 128)   
    | C.Char,  C.Unsigned   -> sprintf "'\\x%x'" (R.int 128) 
    | C.Short, C.Signed     -> sprintf "%d"     (R.int  32768)
    | C.Short, C.Unsigned   -> sprintf "%d"     (R.int  65536)
    | C.IInt,  C.Unsigned   -> sprintf "%ldU"   (R.int32 Int32.max_int)
    | C.IInt,  C.Signed     -> sprintf "%ld"    (R.int32 Int32.max_int)
    | C.Long,  C.Unsigned   -> sprintf "%ldUL"  (R.int32 Int32.max_int)
    | C.Long,  C.Signed     -> sprintf "%ldL"   (R.int32 Int32.max_int)
    | _     ,  C.Unsigned   -> sprintf "%ldUL"  (R.int32 Int32.max_int)
    | _     ,  C.Signed     -> sprintf "%ldL"   (R.int32 Int32.max_int)
    
let float = function
    | _                     -> sprintf "%5.2f"  (R.float 100000.0)


# 57 "randinit.nw"
let bitmask n =
    assert (n >= 0);
    let rec loop x = function
        | 0 -> x
        | n -> loop ((x lsl 1) lor 1) (n-1)
    in
        loop 0 n

let bitfield width sign = 
    assert (width > 0);
    match sign with
    | C.Signed      -> sprintf "%d" @@ R.int (bitmask (width-1) +1)
    | C.Unsigned    -> sprintf "%d" @@ R.int (bitmask  width    +1)


# 72 "randinit.nw"
let rec init = function
    | C.Int(w,s)              -> C.SingleInit (C.Const(int w s))
    | C.Bitfield(w,s)         -> C.SingleInit (C.Const(bitfield w s))
    | C.Float(w)              -> C.SingleInit (C.Const(float w))
    | C.Ptr(_) as ptr         -> let v = C.Const(int C.IInt C.Unsigned) in
                                 C.SingleInit (C.Cast(ptr,v)) 
    | C.Array(t,n)            -> C.CompoundInit(inits t n)
    | C.Struct(n, Some xs)    -> let vs = List.map (fun (n,t) -> init t) xs in
                                 C.CompoundInit vs
    | C.Union(n, Some (x::xs))-> C.CompoundInit ([init (snd x)])
    | C.Union(n, Some [])     -> C.CompoundInit []    (* legal? *)
    | C.Struct(n, None)       -> failwith "init: struct reference"
    | C.Union (n, None)       -> failwith "init: union reference"
    | C.Void                  -> failwith "init: void"
    | C.Fun(_)                -> failwith "init: function"
    | C.TyName(_)             -> failwith "init: named type"  


and inits t n =
    let rec loop = function
    | 0             -> []
    | n             -> init t :: loop (n-1)
    in
        loop n

# 27 "randinit.nw"

