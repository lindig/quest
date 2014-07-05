
# 9 "prg.nw"
val init:   int  -> unit            (* initialze generator with seed *)
val int:    int  -> int             (* random in in range 0,..,n-1   *)

# 20 "prg.nw"
type state = int                         
val state:  unit  -> state                   (* observe state *)
val reset:  state -> unit
