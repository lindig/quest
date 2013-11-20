
# 90 "srcmap.nw"
type pos            = int
type rgn            = pos * pos

# 97 "srcmap.nw"
val null            : rgn

# 108 "srcmap.nw"
type location       = string    (* file   *)
                    * int       (* line   *)
                    * int       (* column *)

# 118 "srcmap.nw"
type map
val mk:             unit -> map (* empty map *)

# 131 "srcmap.nw"
val sync :          map -> pos -> location -> unit
val nl :            map -> pos -> unit

# 138 "srcmap.nw"
val last :          map -> location

# 145 "srcmap.nw"
val location :      map -> pos -> location
val dump:           map -> unit

# 152 "srcmap.nw"
type point          = map * pos
type region         = map * rgn

# 158 "srcmap.nw"
module Str:
sig
    val point       : point  -> string
    val region      : region -> string
end
