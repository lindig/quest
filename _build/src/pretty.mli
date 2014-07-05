
# 25 "pretty.nw"
type t                          (* a printable document *)

val empty : t                   (* empty document *)
val break:  t                   (* space or newline *)
val text:   string -> t         (* create document from string *)
val printf: ('a, unit, string, t) format4 -> 'a

# 39 "pretty.nw"
val cat : t -> t -> t       (* clients define let (^^) = Pretty.cat *)

# 51 "pretty.nw"
val nest : int -> t -> t

# 62 "pretty.nw"
val group : t -> t

# 69 "pretty.nw"
val to_string: int -> t -> string
val to_file:   out_channel -> int -> t -> unit
