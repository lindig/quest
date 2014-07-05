
# 90 "luasrcmap.nw"
type pos            = int
type rgn            = pos * pos

# 97 "luasrcmap.nw"
val null            : rgn

# 108 "luasrcmap.nw"
type location       = string    (* file   *)
                    * int       (* line   *)
                    * int       (* column *)

# 118 "luasrcmap.nw"
type map
val mk:             unit -> map (* empty map *)

# 131 "luasrcmap.nw"
val sync :          map -> pos -> location -> unit
val nl :            map -> pos -> unit

# 138 "luasrcmap.nw"
val last :          map -> location

# 145 "luasrcmap.nw"
val location :      map -> pos -> location
val dump:           map -> unit

# 152 "luasrcmap.nw"
type point          = map * pos
type region         = map * rgn

# 158 "luasrcmap.nw"
module Str:
sig
    val point       : point  -> string
    val region      : region -> string
end
