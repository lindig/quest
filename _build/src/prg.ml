
# 37 "prg.nw"
type state = int

let rec apply n f x = if n <= 1 then f x else apply (n-1) f (f x) 
let step x          = x * 22695477 + 1 
let s               = ref 0     (* never used with this value *)
let state ()        = !s
let reset x         = s := x
let init            = reset

let int n =
    ( s := step !s
    ; ((!s lsr 16) land 16383) mod n
    )
