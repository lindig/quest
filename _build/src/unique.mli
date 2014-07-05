
# 19 "unique.nw"
type t                          (* name generator *)

val make:       unit -> t                   (* create a new generator *)
val func:       t -> string -> string       (* function, taking a hint *)
val variable:   t -> string
val parameter:  t -> string
val type_tag:   t -> string                 (* struct/union tag *)
val typedef:    t -> string                 (* typedef name  *)
