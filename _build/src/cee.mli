
# 9 "cee.nw"

# 17 "cee.nw"
type size           = int
type name           = string
type signed         = Signed | Unsigned
type iwidth         = Char | Short  | IInt | Long | LongLong
type fwidth         = FFloat  | Double | LongDouble

type function_type =
    { return:       ty
    ; args:         (name * ty) list
    ; varargs:      ty list
    }

and ty =
    | Void
    | Int           of iwidth * signed
    | Float         of fwidth 
    | Ptr           of ty
    | Array         of ty * size
    | Struct        of name * (name * ty) list option
    | Union         of name * (name * ty) list option
    | Fun           of function_type
    | TyName        of string
    | Bitfield      of int * signed

# 57 "cee.nw"
type infix   = Eq | Neq | Mult | Add    (* many more missing *)
type prefix  = Not                      (* many more missing *)
type postfix = PostDec | PostInc        (* many more missing *)


# 62 "cee.nw"
type expr = 
    | ID            of string
    | IntConst      of int
    | Const         of string (* char, int, float, string *)
    | Call          of expr * expr list
    | Assign        of expr * expr
    | Access        of expr * expr  (* array , index *) 
    | Select        of expr * name  (* struct or union, member *)
    | Arrow         of expr * name
    | Deref         of expr 
    | AddrOf        of expr
    | Infix         of expr * infix * expr
    | Prefix        of prefix * expr
    | Postfix       of expr * postfix
    | Cast          of ty   * expr
    | Type          of ty 

# 84 "cee.nw"
type init = 
    | SingleInit    of expr
    | CompoundInit  of init list

type decl = 
    | VarDecl of name * ty * init option
    | Typedef of name * ty

# 95 "cee.nw"
type stmt =
    | Expr          of expr
    | Block         of decl list * stmt list
    | Return        of expr option
    | IfThen        of expr * stmt
    | IfThenElse    of expr * stmt * stmt
    | Comment       of string
    | Nop
    (* incomplete *)

# 109 "cee.nw"
type fundef =
    { name:     name                    (* name of this function *)
    ; static:   bool
    ; ty:       function_type
    ; decls:    decl list               (* variable declarations in body *)
    ; body:     stmt list               (* statements in body *)
    }

# 120 "cee.nw"
type scope    = Static | Extern | Public
type toplevel =
    | TopDecl   of scope * decl
    | Function  of fundef
    | CPP       of string   (* C Preprocessor statement *)

type program = toplevel list

# 9 "cee.nw"


# 47 "cee.nw"
val unsigned: ty -> ty

# 134 "cee.nw"
val sizeof: ty -> int       (* not negative *)

# 142 "cee.nw"
val strip: ty -> ty

# 152 "cee.nw"
val variadic: function_type -> bool

# 165 "cee.nw"
val pointable: ty -> bool

# 171 "cee.nw"
val int:    ty     
val char:   ty
val string: ty

# 183 "cee.nw"
val include_headers: program -> program

# 10 "cee.nw"

