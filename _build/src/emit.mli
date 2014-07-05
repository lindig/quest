
# 17 "emit.nw"
val standalone:  out_channel -> Tc.func list -> unit
val modularized: main:out_channel -> client:out_channel 
    -> Tc.func list -> unit
