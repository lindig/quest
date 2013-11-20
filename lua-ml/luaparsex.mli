type token =
  | EOF
  | COMMA
  | LBRA
  | RBRA
  | LT
  | GT
  | COLON
  | SEMI
  | HAT
  | STAR
  | SLASH
  | LPAR
  | RPAR
  | GETS
  | PLUS
  | MINUS
  | DOT
  | LSQ
  | RSQ
  | WRONGTOKEN
  | NIL
  | IF
  | THEN
  | ELSE
  | ELSEIF
  | WHILE
  | DO
  | REPEAT
  | UNTIL
  | CASE
  | GLOBMATCH
  | OF
  | END
  | RETURN
  | LOCAL
  | FUNCTION
  | DOTS
  | ARROW
  | NUMBER of (float)
  | STRING of (string)
  | NAME of (string)
  | DEBUG_PRAGMA of (int)
  | AND
  | OR
  | EQ
  | NE
  | LE
  | GE
  | CONC
  | UNARY
  | NOT

val chunks :
  (Lexing.lexbuf  -> token) -> Lexing.lexbuf -> Ast.chunk list
