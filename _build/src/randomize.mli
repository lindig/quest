
# 15 "randomize.nw"
type size = int
type 'a t  
val run:        'a t -> size -> 'a

# 23 "randomize.nw"
val return:     'a  -> 'a t
val (>>=):      'a t -> ('a -> 'b t) -> 'b t
val bind:       'a t -> ('a -> 'b t) -> 'b t

# 35 "randomize.nw"
val size:       int t
val smaller:    'a t -> 'a t
val iszero:     bool t

# 44 "randomize.nw"
val lift:       ('a -> 'b) -> ('a t -> 'b t)
val lift2:      ('a -> 'b -> 'c) -> ('a t -> 'b t -> 'c t)

# 75 "randomize.nw"
val int:        int -> int t                (* 0 .. n-1, requires n > 0 *)
val flip:       bool t
val choose:     int -> int -> int t         (* lo .. hi *)
val elements:   'a list -> 'a t

# 91 "randomize.nw"
val list:       int t -> 'a t -> 'a list t
val oneof:      ('a t) list -> 'a t
val freq:       (int * 'a t) list -> 'a t
val concat:     ('a list) t list -> 'a list t
