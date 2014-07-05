
# 35 "tc.nw"

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



# 35 "tc.nw"

val generate : Strategy.t -> n:int -> size:int -> t    list (* n elements *)
val generate': Strategy.t -> n:int -> size:int -> func list (* n elements *)
