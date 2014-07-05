
# 18 "rtype.nw"
exception Error of string

type 'a t       (* generates value of type 'a when run *)

val bind:       'a t -> ('a -> 'b t) -> 'b t
val return:     'a -> 'a t
val run:        'a t -> Unique.t -> Randomize.size -> 'a

# 35 "rtype.nw"
val size:       int t                   (* access actual size *)
val smaller:    'a t -> 'a t            (* decrease size *)
val iszero:     bool t

# 48 "rtype.nw"
val flip:       bool t                      (* equal chance of true/false *)
val integer:    int -> int t                (* integer in [0,x]     *)      
val choose:     int -> int -> int t         (* integer in [lo,hi]   *)
val elements:   'a list -> 'a t             (* pick item from list  *)
val list:       int t -> 'a t -> 'a list t  (* list of lenght i using gen *)
val oneof:      ('a t) list -> 'a t         (* pick a generator     *)
val freq:       (int * 'a t) list -> 'a t   (* weighted pick of generator *)
val concat:     'a list t list -> 'a list t 

# 71 "rtype.nw"

# 66 "rtype.nw"
type ct         = Cee.ty t      (* C-type generator *)
type cts        = Cee.ty list t
type it         = int  t        (* int generator    *)    


# 71 "rtype.nw"


val char:       ct
val short:      ct
val int:        ct
val long:       ct
val longlong:   ct

val unsigned:   ct -> ct        (* must be applied to integer type *)
val bitfield:   it -> ct

val float:      ct
val double:     ct
val longdouble: ct

val any_int:    ct              
val any_float:  ct

# 97 "rtype.nw"
val array:      ct -> it -> ct
val pointer:    ct -> ct
val structure': ct -> it -> ct  (* deprecated *)
val union':     ct -> it -> ct  (* deprecated *)

# 107 "rtype.nw"
val structure: cts -> ct
val union:     cts -> ct
