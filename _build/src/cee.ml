
# 189 "cee.nw"

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

# 189 "cee.nw"


# 197 "cee.nw"
let rec sizeof = function
    | Void              -> 0
    | Int(Char,_)       -> 1
    | Int(Short,_)      -> 2
    | Int(IInt,_)       -> 4
    | Int(Long,_)       -> 8
    | Int(LongLong,_)   -> 16
    | Bitfield(_,_)     -> 1
    | Float(FFloat)     -> 4
    | Float(Double)     -> 8
    | Float(LongDouble) -> 16
    | Ptr(_)            -> 4
    | Array(t,n)        -> n * sizeof t
    | Struct(_,None)    -> failwith "sizeof: struct reference"
    | Struct(_,Some ms) -> List.fold_left 
                            (fun s (n,t) -> s+(sizeof t)) 0 ms
    | Union(_,None)     -> failwith "sizeof: union rerefence"
    | Union(_,Some ms)  -> List.fold_left 
                            (fun s (n,t) -> max s (sizeof t)) 0 ms
    | Fun(_)            -> 4                        
    | TyName _          -> failwith "sizeof: named type"

# 227 "cee.nw"
let rec strip = function
    | Struct(n,Some ms) ->    Struct(n, None)
    | Union (n,Some ms) ->    Union (n, None)
    | Ptr(t)            ->    Ptr(strip t)
    | Array(t,n)        ->    Array(strip t,n)
    | Fun(f)            ->    Fun(strip_function_type f)
    | x                 ->    x  

and strip_function_type fty =
    { return  = strip fty.return
    ; args    = List.map (function name, ty -> name, strip ty) fty.args
    ; varargs = List.map strip fty.varargs
    }

# 243 "cee.nw"
let simple = function
    | Void      -> failwith "applied Cee.simple to Void"
    | Int(_)    -> true
    | Float(_)  -> true
    | _         -> false (* we consider pointers as complex types *)

# 251 "cee.nw"
let pointable = function
    | Array(_,_)    -> false
    | Fun(_)        -> false 
    | _             -> true

# 258 "cee.nw"
let variadic fty = fty.varargs <> []

# 264 "cee.nw"
let int     = Int(IInt, Signed)
let char    = Int(Char, Signed)
let string  = Ptr(char)

# 270 "cee.nw"
let unsigned = function
    | Int(t,_)  -> Int(t,Unsigned)
    | _         -> failwith "Cee.unsigned applied to non-integer type"

# 278 "cee.nw"
type header =
    { stdarg: bool
    }
    
let headers prg = 
    let scan header = function
        | Function({ty = {varargs=_::_}}) -> { header with stdarg = true }
        | _ -> header
    in
        List.fold_left scan { stdarg = false } prg

let include_headers prg =
    (* let prg = CPP("#include <assert.h>") :: prg in
     *)
    let h   = headers prg in
    let prg = if h.stdarg then 
                   CPP "#include <stdio.h>"
                :: CPP "#include <stdarg.h>" 
                :: prg 
              else   
                   CPP "#include <stdio.h>"
                :: prg 
    in             
        prg
    
