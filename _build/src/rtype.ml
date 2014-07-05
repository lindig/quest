
# 114 "rtype.nw"
module R = Randomize
module C = Cee
module U = Unique

# 132 "rtype.nw"
exception Error of string

type env    = U.t   (* source for unique names *)
type 'a t   = env -> 'a R.t 

# 66 "rtype.nw"
type ct         = Cee.ty t      (* C-type generator *)
type cts        = Cee.ty list t
type it         = int  t        (* int generator    *)    


# 136 "rtype.nw"


let error fmt = Printf.kprintf (fun str -> raise (Error str)) fmt
let (@@) f x  = f x
let liftM (r: 'a R.t) = fun env -> r

# 147 "rtype.nw"
let bind t f        = fun env -> R.bind (t env) (fun x -> f x env)
let (>>=)           = bind
let return x        = liftM (R.return x)
let fetch           = R.return
let run t env size  = R.run (t env) size

let lift  f m       = m  >>= fun x -> return (f x)
let lift2 f m1 m2   = m1 >>= fun x -> m2 >>= fun y -> return (f x y)

# 165 "rtype.nw"
let size            = liftM R.size
let iszero          = liftM R.iszero
let smaller m       = fun env -> R.smaller (m env)

let flip            = liftM R.flip
let integer n       = liftM (R.int n)
let choose lo hi    = liftM (R.choose lo hi)
let elements xs     = liftM (R.elements xs)
let list size ty    = fun env -> R.list (size env) (ty env)
let oneof rs        = fun env -> R.oneof (List.map (fun r -> r env) rs)
let freq pairs      = fun env -> R.freq (List.map (fun (x,r) -> x,r env) pairs)

let concat ts       = fun env -> R.concat (List.map (fun t -> t env) ts)

# 184 "rtype.nw"
let signed x        = C.Int(x,C.Signed)

let char            = return @@ signed C.Char
let short           = return @@ signed C.Short
let int             = return @@ signed C.IInt
let long            = return @@ signed C.Long
let longlong        = return @@ signed C.LongLong

let unsigned m =
    m >>= function
    | C.Int(x,_)      -> return @@ C.Int(x,C.Unsigned)
    | C.Bitfield(x,_) -> return @@ C.Bitfield(x,C.Unsigned)
    | _               -> error "applied unsigned() to a non-integer type"

let float           = return @@ C.Float(C.FFloat)
let double          = return @@ C.Float(C.Double)
let longdouble      = return @@ C.Float(C.LongDouble)

let bitfield n =    n >>= fun n -> return @@ C.Bitfield(n,C.Signed)


# 205 "rtype.nw"
let iwidth              = elements [C.Char; C.Short; C.IInt; C.Long]
let signed              = elements [C.Signed; C.Unsigned]
let fwidth              = elements [C.FFloat; C.Double]
let any_int             = lift2 (fun w s -> C.Int(w,s)) iwidth signed
let any_float           = lift  (fun w   -> C.Float(w)) fwidth

# 216 "rtype.nw"
let array     ctype n   = lift2 (fun t n -> C.Array(t,n)) ctype n
let pointer   ctype     = lift  (fun t -> C.Ptr(t)) ctype
let member    ctype     = ctype >>= fun t -> 
                          fetch >>= fun u -> return (U.variable u,t)
let members   ctype n   = list n @@ member ctype

let structure' ctype n = (* deprecated *)
    members ctype n >>= fun ms -> 
    fetch >>= fun u  ->
        return @@ C.Struct(U.type_tag u, Some ms)

let union' ctype n = (* deprecated *)
    members ctype n >>= fun ms ->
    fetch >>= fun u  ->
        return @@ C.Union(U.type_tag u, Some ms)

let structure ctypes =
    ctypes >>= fun ts ->
    fetch  >>= fun u  ->
        let members = List.map (fun t -> (U.variable u,t)) ts in
            return @@ C.Struct(U.type_tag u, Some members)

let union ctypes =
    ctypes >>= fun ts ->
    fetch  >>= fun u  ->
        let members = List.map (fun t -> (U.variable u,t)) ts in
            return @@ C.Union(U.type_tag u, Some members)

