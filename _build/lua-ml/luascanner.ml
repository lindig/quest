# 251 "lua-ml/luascanner.mll"
 
    module P = Luaparser     (* tokens are defined here *)
    
    exception Scan of string
    
    let error msg   = raise (Scan msg)

    (* called at *every* newline in the source code *)
    let nl lexbuf map =
        let next = (Lexing.lexeme_start lexbuf) + 1     in
            Luasrcmap.nl map next
            
    let location lexbuf map =
        Luasrcmap.location map (Lexing.lexeme_start lexbuf)
         
    let get         = Lexing.lexeme
    let getchar     = Lexing.lexeme_char
    let strlen      = String.length
    let pos_start   = Lexing.lexeme_start
    let pos_end     = Lexing.lexeme_end

    let keywords    = Hashtbl.create 27
    let keyword s   = Hashtbl.find keywords s
    let _ = Array.iter (fun (str,tok) -> Hashtbl.add keywords str tok)
      [| ("and"         , P.AND)
      ;  ("case"        , P.CASE)
      ;  ("do"          , P.DO)
      ;  ("else"        , P.ELSE)
      ;  ("elseif"      , P.ELSEIF)
      ;  ("end"         , P.END)
      ;  ("function"    , P.FUNCTION)
      ;  ("globmatch"   , P.GLOBMATCH)
      ;  ("if"          , P.IF)
      ;  ("local"       , P.LOCAL)
      ;  ("nil"         , P.NIL)
      ;  ("not"         , P.NOT)
      ;  ("of"          , P.OF)
      ;  ("or"          , P.OR)
      ;  ("repeat"      , P.REPEAT)
      ;  ("return"      , P.RETURN)
      ;  ("then"        , P.THEN)
      ;  ("until"       , P.UNTIL)
      ;  ("while"       , P.WHILE) 
      |]


# 49 "lua-ml/luascanner.ml"
let __ocaml_lex_tables = {
  Lexing.lex_base = 
   "\000\000\212\255\214\255\215\255\217\255\218\255\219\255\220\255\
    \001\000\225\255\226\255\227\255\018\000\230\255\231\255\232\255\
    \233\255\234\255\003\000\035\000\066\000\063\000\083\000\084\000\
    \094\000\244\255\117\000\001\000\006\000\255\255\118\000\030\000\
    \047\000\049\000\045\000\055\000\214\000\215\000\049\000\057\000\
    \220\000\221\000\088\000\070\000\085\000\222\000\223\000\089\000\
    \116\000\117\000\127\000\137\000\230\000\231\000\133\000\141\000\
    \236\000\248\000\150\000\133\000\148\000\251\000\000\001\222\000\
    \241\000\251\000\005\001\015\001\037\001\047\001\057\001\212\000\
    \240\255\239\255\237\255\238\255\236\255\235\255\010\000\213\255\
    \011\000\253\255\249\000\255\255\015\001\253\255\016\001\255\255\
    \069\001\253\255\079\001\255\255\089\001\253\255\099\001\255\255\
    \066\001\251\255\067\001\194\000\194\000\255\255\254\255\253\255\
    \151\001\251\255\152\001\073\000\254\255\255\255\253\255";
  Lexing.lex_backtrk = 
   "\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \034\000\255\255\255\255\255\255\026\000\255\255\255\255\255\255\
    \255\255\255\255\043\000\033\000\032\000\031\000\027\000\013\000\
    \012\000\255\255\004\000\002\000\001\000\255\255\003\000\255\255\
    \255\255\255\255\255\255\255\255\255\255\005\000\255\255\255\255\
    \255\255\006\000\255\255\255\255\255\255\255\255\007\000\255\255\
    \255\255\255\255\255\255\255\255\255\255\008\000\255\255\255\255\
    \255\255\009\000\255\255\255\255\255\255\255\255\010\000\255\255\
    \255\255\013\000\255\255\013\000\255\255\013\000\255\255\014\000\
    \255\255\255\255\255\255\255\255\255\255\255\255\039\000\255\255\
    \255\255\255\255\001\000\255\255\255\255\255\255\001\000\255\255\
    \255\255\255\255\001\000\255\255\255\255\255\255\001\000\255\255\
    \255\255\255\255\003\000\003\000\003\000\255\255\255\255\255\255\
    \255\255\255\255\003\000\005\000\255\255\255\255\255\255";
  Lexing.lex_default = 
   "\001\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \255\255\000\000\000\000\000\000\255\255\000\000\000\000\000\000\
    \000\000\000\000\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\000\000\255\255\255\255\255\255\000\000\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \000\000\000\000\000\000\000\000\000\000\000\000\078\000\000\000\
    \082\000\000\000\082\000\000\000\086\000\000\000\086\000\000\000\
    \089\000\000\000\255\255\000\000\093\000\000\000\255\255\000\000\
    \098\000\000\000\098\000\255\255\255\255\000\000\000\000\000\000\
    \106\000\000\000\106\000\110\000\000\000\000\000\000\000";
  Lexing.lex_trans = 
   "\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\028\000\027\000\000\000\000\000\028\000\000\000\028\000\
    \000\000\000\000\000\000\028\000\255\255\081\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \028\000\000\000\002\000\025\000\026\000\030\000\028\000\003\000\
    \017\000\016\000\015\000\014\000\013\000\012\000\022\000\011\000\
    \023\000\023\000\023\000\023\000\023\000\023\000\023\000\023\000\
    \023\000\023\000\010\000\009\000\021\000\020\000\019\000\078\000\
    \077\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\008\000\079\000\007\000\006\000\024\000\
    \076\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\005\000\073\000\004\000\018\000\075\000\
    \074\000\071\000\063\000\042\000\023\000\023\000\023\000\023\000\
    \023\000\023\000\023\000\023\000\023\000\023\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \038\000\064\000\034\000\035\000\036\000\039\000\040\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\064\000\043\000\044\000\045\000\024\000\058\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\047\000\031\000\048\000\032\000\054\000\050\000\037\000\
    \037\000\049\000\033\000\037\000\037\000\041\000\041\000\046\000\
    \046\000\041\000\041\000\046\000\046\000\051\000\052\000\053\000\
    \053\000\055\000\056\000\053\000\053\000\057\000\037\000\037\000\
    \059\000\057\000\060\000\061\000\041\000\041\000\046\000\046\000\
    \029\000\057\000\072\000\255\255\062\000\057\000\053\000\053\000\
    \062\000\062\000\255\255\083\000\057\000\062\000\067\000\067\000\
    \067\000\067\000\067\000\067\000\067\000\067\000\067\000\067\000\
    \057\000\085\000\255\255\062\000\066\000\103\000\066\000\102\000\
    \062\000\065\000\065\000\065\000\065\000\065\000\065\000\065\000\
    \065\000\065\000\065\000\065\000\065\000\065\000\065\000\065\000\
    \065\000\065\000\065\000\065\000\065\000\065\000\065\000\065\000\
    \065\000\065\000\065\000\065\000\065\000\065\000\065\000\067\000\
    \067\000\067\000\067\000\067\000\067\000\067\000\067\000\067\000\
    \067\000\255\255\000\000\000\000\097\000\255\255\000\000\000\000\
    \070\000\000\000\070\000\000\000\068\000\069\000\069\000\069\000\
    \069\000\069\000\069\000\069\000\069\000\069\000\069\000\069\000\
    \069\000\069\000\069\000\069\000\069\000\069\000\069\000\069\000\
    \069\000\069\000\069\000\069\000\069\000\069\000\069\000\069\000\
    \069\000\069\000\069\000\000\000\068\000\090\000\090\000\090\000\
    \090\000\090\000\090\000\090\000\090\000\090\000\090\000\090\000\
    \090\000\090\000\090\000\090\000\090\000\090\000\090\000\090\000\
    \090\000\094\000\094\000\094\000\094\000\094\000\094\000\094\000\
    \094\000\094\000\094\000\094\000\094\000\094\000\094\000\094\000\
    \094\000\094\000\094\000\094\000\094\000\099\000\255\255\100\000\
    \255\255\108\000\255\255\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\105\000\255\255\000\000\000\000\000\000\105\000\255\255\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\107\000\255\255\000\000\000\000\000\000\
    \000\000\255\255\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\087\000\
    \255\255\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\101\000\255\255\000\000\091\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\095\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\109\000\
    \255\255";
  Lexing.lex_check = 
   "\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\000\000\000\000\255\255\255\255\000\000\255\255\028\000\
    \255\255\255\255\255\255\028\000\078\000\080\000\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \000\000\255\255\000\000\000\000\000\000\027\000\028\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\012\000\
    \018\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\008\000\000\000\000\000\000\000\
    \019\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\000\
    \000\000\000\000\000\000\000\000\021\000\000\000\000\000\020\000\
    \020\000\022\000\023\000\031\000\023\000\023\000\023\000\023\000\
    \023\000\023\000\023\000\023\000\023\000\023\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \032\000\023\000\033\000\034\000\035\000\038\000\039\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\023\000\042\000\043\000\044\000\024\000\047\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\024\000\024\000\024\000\024\000\024\000\024\000\024\000\
    \024\000\026\000\030\000\026\000\030\000\048\000\049\000\036\000\
    \037\000\026\000\030\000\036\000\037\000\040\000\041\000\045\000\
    \046\000\040\000\041\000\045\000\046\000\050\000\051\000\052\000\
    \053\000\054\000\055\000\052\000\053\000\056\000\036\000\037\000\
    \058\000\056\000\059\000\060\000\040\000\041\000\045\000\046\000\
    \000\000\057\000\071\000\082\000\061\000\057\000\052\000\053\000\
    \061\000\062\000\078\000\080\000\056\000\062\000\063\000\063\000\
    \063\000\063\000\063\000\063\000\063\000\063\000\063\000\063\000\
    \057\000\084\000\086\000\061\000\064\000\099\000\064\000\100\000\
    \062\000\064\000\064\000\064\000\064\000\064\000\064\000\064\000\
    \064\000\064\000\064\000\065\000\065\000\065\000\065\000\065\000\
    \065\000\065\000\065\000\065\000\065\000\066\000\066\000\066\000\
    \066\000\066\000\066\000\066\000\066\000\066\000\066\000\067\000\
    \067\000\067\000\067\000\067\000\067\000\067\000\067\000\067\000\
    \067\000\107\000\255\255\255\255\096\000\098\000\255\255\255\255\
    \068\000\255\255\068\000\255\255\067\000\068\000\068\000\068\000\
    \068\000\068\000\068\000\068\000\068\000\068\000\068\000\069\000\
    \069\000\069\000\069\000\069\000\069\000\069\000\069\000\069\000\
    \069\000\070\000\070\000\070\000\070\000\070\000\070\000\070\000\
    \070\000\070\000\070\000\255\255\067\000\088\000\088\000\088\000\
    \088\000\088\000\088\000\088\000\088\000\088\000\088\000\090\000\
    \090\000\090\000\090\000\090\000\090\000\090\000\090\000\090\000\
    \090\000\092\000\092\000\092\000\092\000\092\000\092\000\092\000\
    \092\000\092\000\092\000\094\000\094\000\094\000\094\000\094\000\
    \094\000\094\000\094\000\094\000\094\000\096\000\098\000\096\000\
    \098\000\104\000\106\000\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\104\000\106\000\255\255\255\255\255\255\104\000\106\000\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\104\000\106\000\255\255\255\255\255\255\
    \255\255\082\000\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\084\000\
    \086\000\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\096\000\098\000\255\255\088\000\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\092\000\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\255\
    \255\255\255\255\255\255\255\255\255\255\255\255\255\255\104\000\
    \106\000";
  Lexing.lex_base_code = 
   "";
  Lexing.lex_backtrk_code = 
   "";
  Lexing.lex_default_code = 
   "";
  Lexing.lex_trans_code = 
   "";
  Lexing.lex_check_code = 
   "";
  Lexing.lex_code = 
   "";
}

let rec token lexbuf =
    __ocaml_lex_token_rec lexbuf 0
and __ocaml_lex_token_rec lexbuf __ocaml_lex_state =
  match Lexing.engine __ocaml_lex_tables __ocaml_lex_state lexbuf with
      | 0 ->
# 318 "lua-ml/luascanner.mll"
                ( fun map ->  P.EOF )
# 287 "lua-ml/luascanner.ml"

  | 1 ->
# 319 "lua-ml/luascanner.mll"
                ( fun map ->  token lexbuf map )
# 292 "lua-ml/luascanner.ml"

  | 2 ->
# 320 "lua-ml/luascanner.mll"
                ( fun map -> nl lexbuf map ; token lexbuf map )
# 297 "lua-ml/luascanner.ml"

  | 3 ->
# 322 "lua-ml/luascanner.mll"
                ( fun map -> (* skip pragma line *)
                  ( nl lexbuf map
                  ; skip lexbuf map
                  )
                )
# 306 "lua-ml/luascanner.ml"

  | 4 ->
# 327 "lua-ml/luascanner.mll"
                ( fun map -> (* skip pragma line *) 
                  if Lexing.lexeme_start lexbuf = 0 then 
                    skip lexbuf map     
                  else
                    error "illegal character" 
                )
# 316 "lua-ml/luascanner.ml"

  | 5 ->
# 334 "lua-ml/luascanner.mll"
                    ( fun map -> line_pragma  lexbuf map )
# 321 "lua-ml/luascanner.ml"

  | 6 ->
# 335 "lua-ml/luascanner.mll"
                    ( fun map -> file_pragma  lexbuf map )
# 326 "lua-ml/luascanner.ml"

  | 7 ->
# 336 "lua-ml/luascanner.mll"
                    ( fun map -> debug_pragma lexbuf map )
# 331 "lua-ml/luascanner.ml"

  | 8 ->
# 338 "lua-ml/luascanner.mll"
                ( fun map -> 
                  if Lexing.lexeme_start lexbuf = 0 then 
                    line_pragma lexbuf map 
                  else 
                    error "illegal $line pragma" 
                )
# 341 "lua-ml/luascanner.ml"

  | 9 ->
# 344 "lua-ml/luascanner.mll"
                ( fun map -> 
                  if Lexing.lexeme_start lexbuf = 0 then
                    file_pragma lexbuf map 
                  else 
                    error "illegal $file pragma"
                )
# 351 "lua-ml/luascanner.ml"

  | 10 ->
# 351 "lua-ml/luascanner.mll"
                 ( fun map -> 
                   if Lexing.lexeme_start lexbuf = 0 then 
                     debug_pragma lexbuf map 
                   else 
                     error "illegal $debug pragma" 
                 )
# 361 "lua-ml/luascanner.ml"

  | 11 ->
# 357 "lua-ml/luascanner.mll"
                ( fun map ->  (* skip # line if it's the first line *)
                  if Lexing.lexeme_start lexbuf = 0 then 
                    skip lexbuf map     
                  else
                    error "illegal character" 
                )
# 371 "lua-ml/luascanner.ml"

  | 12 ->
# 363 "lua-ml/luascanner.mll"
                ( fun map ->  let s = get lexbuf in
                    try keyword s with Not_found -> P.NAME s
                )
# 378 "lua-ml/luascanner.ml"

  | 13 ->
# 367 "lua-ml/luascanner.mll"
                ( fun map ->  
                  let s = get lexbuf in P.NUMBER (float_of_string s) 
                )
# 385 "lua-ml/luascanner.ml"

  | 14 ->
# 371 "lua-ml/luascanner.mll"
                ( fun map ->  P.CONC  )
# 390 "lua-ml/luascanner.ml"

  | 15 ->
# 372 "lua-ml/luascanner.mll"
                ( fun map ->  P.DOTS  )
# 395 "lua-ml/luascanner.ml"

  | 16 ->
# 373 "lua-ml/luascanner.mll"
                ( fun map ->  P.LE    )
# 400 "lua-ml/luascanner.ml"

  | 17 ->
# 374 "lua-ml/luascanner.mll"
                ( fun map ->  P.EQ    )
# 405 "lua-ml/luascanner.ml"

  | 18 ->
# 375 "lua-ml/luascanner.mll"
                ( fun map ->  P.ARROW )
# 410 "lua-ml/luascanner.ml"

  | 19 ->
# 376 "lua-ml/luascanner.mll"
                ( fun map ->  P.GE    )
# 415 "lua-ml/luascanner.ml"

  | 20 ->
# 377 "lua-ml/luascanner.mll"
                ( fun map ->  P.NE    )
# 420 "lua-ml/luascanner.ml"

  | 21 ->
# 378 "lua-ml/luascanner.mll"
                ( fun map ->  P.LPAR  )
# 425 "lua-ml/luascanner.ml"

  | 22 ->
# 379 "lua-ml/luascanner.mll"
                ( fun map ->  P.RPAR  )
# 430 "lua-ml/luascanner.ml"

  | 23 ->
# 380 "lua-ml/luascanner.mll"
                ( fun map ->  P.STAR  )
# 435 "lua-ml/luascanner.ml"

  | 24 ->
# 381 "lua-ml/luascanner.mll"
                ( fun map ->  P.PLUS  )
# 440 "lua-ml/luascanner.ml"

  | 25 ->
# 382 "lua-ml/luascanner.mll"
                ( fun map ->  P.COMMA )
# 445 "lua-ml/luascanner.ml"

  | 26 ->
# 383 "lua-ml/luascanner.mll"
                ( fun map ->  P.MINUS )
# 450 "lua-ml/luascanner.ml"

  | 27 ->
# 384 "lua-ml/luascanner.mll"
                ( fun map ->  P.DOT   )
# 455 "lua-ml/luascanner.ml"

  | 28 ->
# 385 "lua-ml/luascanner.mll"
                ( fun map ->  P.SLASH )
# 460 "lua-ml/luascanner.ml"

  | 29 ->
# 386 "lua-ml/luascanner.mll"
                ( fun map ->  P.COLON )
# 465 "lua-ml/luascanner.ml"

  | 30 ->
# 387 "lua-ml/luascanner.mll"
                ( fun map ->  P.SEMI  )
# 470 "lua-ml/luascanner.ml"

  | 31 ->
# 388 "lua-ml/luascanner.mll"
                ( fun map ->  P.LT    )
# 475 "lua-ml/luascanner.ml"

  | 32 ->
# 389 "lua-ml/luascanner.mll"
                ( fun map ->  P.GETS  )
# 480 "lua-ml/luascanner.ml"

  | 33 ->
# 390 "lua-ml/luascanner.mll"
                ( fun map ->  P.GT    )
# 485 "lua-ml/luascanner.ml"

  | 34 ->
# 391 "lua-ml/luascanner.mll"
                ( fun map ->  P.LSQ   )
# 490 "lua-ml/luascanner.ml"

  | 35 ->
# 392 "lua-ml/luascanner.mll"
                ( fun map ->  P.RSQ   )
# 495 "lua-ml/luascanner.ml"

  | 36 ->
# 393 "lua-ml/luascanner.mll"
                ( fun map ->  P.HAT   )
# 500 "lua-ml/luascanner.ml"

  | 37 ->
# 394 "lua-ml/luascanner.mll"
                ( fun map ->  P.LBRA  )
# 505 "lua-ml/luascanner.ml"

  | 38 ->
# 395 "lua-ml/luascanner.mll"
                ( fun map ->  P.RBRA  )
# 510 "lua-ml/luascanner.ml"

  | 39 ->
# 402 "lua-ml/luascanner.mll"
                ( fun map ->  token lexbuf map )
# 515 "lua-ml/luascanner.ml"

  | 40 ->
# 403 "lua-ml/luascanner.mll"
                ( fun map ->  shortstring lexbuf map "'" (Buffer.create 80) )
# 520 "lua-ml/luascanner.ml"

  | 41 ->
# 404 "lua-ml/luascanner.mll"
                ( fun map ->  shortstring lexbuf map "\"" (Buffer.create 80) )
# 525 "lua-ml/luascanner.ml"

  | 42 ->
# 405 "lua-ml/luascanner.mll"
                ( fun map ->  longstring  lexbuf 1 map (Buffer.create 160) )
# 530 "lua-ml/luascanner.ml"

  | 43 ->
# 407 "lua-ml/luascanner.mll"
                ( fun map ->  error     
                                ( Printf.sprintf 
                                  "illegal character `%s' at character %d" 
                                  (Char.escaped (Lexing.lexeme_char lexbuf 0))
                                  (Lexing.lexeme_start lexbuf)
                                )  
                )
# 541 "lua-ml/luascanner.ml"

  | __ocaml_lex_state -> lexbuf.Lexing.refill_buff lexbuf; __ocaml_lex_token_rec lexbuf __ocaml_lex_state

and skip lexbuf =
    __ocaml_lex_skip_rec lexbuf 80
and __ocaml_lex_skip_rec lexbuf __ocaml_lex_state =
  match Lexing.engine __ocaml_lex_tables __ocaml_lex_state lexbuf with
      | 0 ->
# 416 "lua-ml/luascanner.mll"
                ( fun map ->  P.EOF        )
# 552 "lua-ml/luascanner.ml"

  | 1 ->
# 417 "lua-ml/luascanner.mll"
                ( fun map ->  skip lexbuf map )
# 557 "lua-ml/luascanner.ml"

  | 2 ->
# 418 "lua-ml/luascanner.mll"
                ( fun map ->  nl lexbuf map ; token lexbuf map )
# 562 "lua-ml/luascanner.ml"

  | 3 ->
# 419 "lua-ml/luascanner.mll"
                ( fun map ->  error     
                                ( Printf.sprintf 
                                  "illegal character `%s' at character %d" 
                                  (Char.escaped (Lexing.lexeme_char lexbuf 0))
                                  (Lexing.lexeme_start lexbuf)
                                )  
                )
# 573 "lua-ml/luascanner.ml"

  | __ocaml_lex_state -> lexbuf.Lexing.refill_buff lexbuf; __ocaml_lex_skip_rec lexbuf __ocaml_lex_state

and file_pragma lexbuf =
    __ocaml_lex_file_pragma_rec lexbuf 84
and __ocaml_lex_file_pragma_rec lexbuf __ocaml_lex_state =
  match Lexing.engine __ocaml_lex_tables __ocaml_lex_state lexbuf with
      | 0 ->
# 428 "lua-ml/luascanner.mll"
                ( fun map -> error "illegal $file pragma" )
# 584 "lua-ml/luascanner.ml"

  | 1 ->
# 429 "lua-ml/luascanner.mll"
                ( fun map -> 
                    let file = get lexbuf in
                    let loc  = (file, 1, 1) in
                    let pos  = Lexing.lexeme_start lexbuf in 
                        ( Luasrcmap.sync map pos loc
                        ; token lexbuf map
                        )
                )
# 596 "lua-ml/luascanner.ml"

  | 2 ->
# 437 "lua-ml/luascanner.mll"
                ( fun map ->  error     
                                ( Printf.sprintf 
                                  "illegal character `%s' at character %d" 
                                  (Char.escaped (Lexing.lexeme_char lexbuf 0))
                                  (Lexing.lexeme_start lexbuf)
                                )  
                )
# 607 "lua-ml/luascanner.ml"

  | __ocaml_lex_state -> lexbuf.Lexing.refill_buff lexbuf; __ocaml_lex_file_pragma_rec lexbuf __ocaml_lex_state

and line_pragma lexbuf =
    __ocaml_lex_line_pragma_rec lexbuf 88
and __ocaml_lex_line_pragma_rec lexbuf __ocaml_lex_state =
  match Lexing.engine __ocaml_lex_tables __ocaml_lex_state lexbuf with
      | 0 ->
# 445 "lua-ml/luascanner.mll"
                ( fun map -> error "illegal $line pragma" )
# 618 "lua-ml/luascanner.ml"

  | 1 ->
# 446 "lua-ml/luascanner.mll"
                ( fun map -> 
                    let s       = get lexbuf in
                    let line    = int_of_string s in
                    let line    = line - 1 in   (* fencepost error *)
                    let pos     = Lexing.lexeme_start lexbuf in 
                    let (f,l,c) = Luasrcmap.last map in
                        ( Luasrcmap.sync map pos (f,line,1)
                        ; token lexbuf map
                        )
                )
# 632 "lua-ml/luascanner.ml"

  | 2 ->
# 456 "lua-ml/luascanner.mll"
                ( fun map ->  error     
                                ( Printf.sprintf 
                                  "illegal character `%s' at character %d" 
                                  (Char.escaped (Lexing.lexeme_char lexbuf 0))
                                  (Lexing.lexeme_start lexbuf)
                                )  
                )
# 643 "lua-ml/luascanner.ml"

  | __ocaml_lex_state -> lexbuf.Lexing.refill_buff lexbuf; __ocaml_lex_line_pragma_rec lexbuf __ocaml_lex_state

and debug_pragma lexbuf =
    __ocaml_lex_debug_pragma_rec lexbuf 92
and __ocaml_lex_debug_pragma_rec lexbuf __ocaml_lex_state =
  match Lexing.engine __ocaml_lex_tables __ocaml_lex_state lexbuf with
      | 0 ->
# 467 "lua-ml/luascanner.mll"
                ( fun map -> error "illegal $debug pragma" )
# 654 "lua-ml/luascanner.ml"

  | 1 ->
# 468 "lua-ml/luascanner.mll"
                ( fun map -> 
                    let s       = get lexbuf in
                    let debug   = int_of_string s in
                    P.DEBUG_PRAGMA debug
                )
# 663 "lua-ml/luascanner.ml"

  | 2 ->
# 473 "lua-ml/luascanner.mll"
                ( fun map ->  error     
                                ( Printf.sprintf 
                                  "illegal character `%s' at character %d" 
                                  (Char.escaped (Lexing.lexeme_char lexbuf 0))
                                  (Lexing.lexeme_start lexbuf)
                                )  
                )
# 674 "lua-ml/luascanner.ml"

  | __ocaml_lex_state -> lexbuf.Lexing.refill_buff lexbuf; __ocaml_lex_debug_pragma_rec lexbuf __ocaml_lex_state

and longstring lexbuf =
    __ocaml_lex_longstring_rec lexbuf 96
and __ocaml_lex_longstring_rec lexbuf __ocaml_lex_state =
  match Lexing.engine __ocaml_lex_tables __ocaml_lex_state lexbuf with
      | 0 ->
# 484 "lua-ml/luascanner.mll"
                ( fun n map buf -> error "end of file in [[..]] string" )
# 685 "lua-ml/luascanner.ml"

  | 1 ->
# 485 "lua-ml/luascanner.mll"
                ( fun n map buf ->
                    if n = 1 then P.STRING (Buffer.contents buf) 
                    else ( Buffer.add_string buf "]]"
                         ; longstring lexbuf (n-1) map buf
                         )
                )
# 695 "lua-ml/luascanner.ml"

  | 2 ->
# 491 "lua-ml/luascanner.mll"
                ( fun n map buf ->
                    ( Buffer.add_string buf "[["
                    ; longstring lexbuf (n+1) map buf
                    )
                )
# 704 "lua-ml/luascanner.ml"

  | 3 ->
# 498 "lua-ml/luascanner.mll"
                ( fun n map buf -> 
                  let s = get lexbuf in
                  ( Buffer.add_string buf s
                  ; longstring lexbuf n map buf
                  )
                )
# 714 "lua-ml/luascanner.ml"

  | 4 ->
# 504 "lua-ml/luascanner.mll"
                ( fun n map buf -> 
                   ( Buffer.add_char buf '\n'
                   ; nl lexbuf map
                   ; longstring lexbuf n map buf
                   )
                )
# 724 "lua-ml/luascanner.ml"

  | 5 ->
# 510 "lua-ml/luascanner.mll"
                ( fun n map buf ->  error     
                                ( Printf.sprintf 
                                  "illegal character `%s' at character %d" 
                                  (Char.escaped (Lexing.lexeme_char lexbuf 0))
                                  (Lexing.lexeme_start lexbuf)
                                )  
                )
# 735 "lua-ml/luascanner.ml"

  | __ocaml_lex_state -> lexbuf.Lexing.refill_buff lexbuf; __ocaml_lex_longstring_rec lexbuf __ocaml_lex_state

and shortstring lexbuf =
    __ocaml_lex_shortstring_rec lexbuf 104
and __ocaml_lex_shortstring_rec lexbuf __ocaml_lex_state =
  match Lexing.engine __ocaml_lex_tables __ocaml_lex_state lexbuf with
      | 0 ->
# 519 "lua-ml/luascanner.mll"
                ( fun map eos buf -> 
                  error ("end of file in string: " ^ Buffer.contents buf) )
# 747 "lua-ml/luascanner.ml"

  | 1 ->
# 521 "lua-ml/luascanner.mll"
                ( fun map eos buf ->
                  error ("end of line in string: " ^ Buffer.contents buf) )
# 753 "lua-ml/luascanner.ml"

  | 2 ->
# 523 "lua-ml/luascanner.mll"
                ( fun map eos buf -> 
                  let c = getchar lexbuf 1 in
                  let k = match c with
                      | 'n'  -> '\n'
                      | 't'  -> '\t'
                      | 'r'  -> '\r'
                      | '\n' -> '\n'
                      | '0'  -> '\000'
                      | _    -> c
                  in   
                     ( Buffer.add_char buf k
                     ; shortstring lexbuf map eos buf
                     )
                 )
# 771 "lua-ml/luascanner.ml"

  | 3 ->
# 538 "lua-ml/luascanner.mll"
                 ( fun map eos buf -> 
                   let s = get lexbuf  in
                     ( Buffer.add_string buf s
                     ; shortstring lexbuf map eos buf
                     )
                 )
# 781 "lua-ml/luascanner.ml"

  | 4 ->
# 544 "lua-ml/luascanner.mll"
                 ( fun map eos buf ->
                   let s = get lexbuf in
                      if s = eos then
                        P.STRING (Buffer.contents buf)
                      else
                        ( Buffer.add_string buf s
                        ; shortstring lexbuf map eos buf
                        )
                  )
# 794 "lua-ml/luascanner.ml"

  | 5 ->
# 553 "lua-ml/luascanner.mll"
                  ( fun map eos buf -> assert false )
# 799 "lua-ml/luascanner.ml"

  | __ocaml_lex_state -> lexbuf.Lexing.refill_buff lexbuf; __ocaml_lex_shortstring_rec lexbuf __ocaml_lex_state

;;

# 558 "lua-ml/luascanner.mll"
 
        let tok2str = function
          | P.AND         -> "AND"
          | P.ARROW       -> "ARROW"
          | P.CASE        -> "CASE"
          | P.COLON       -> "COLON"
          | P.COMMA       -> "COMMA"
          | P.CONC        -> "CONC"
          | P.DEBUG_PRAGMA n-> "DEBUG_PRAGMA" ^ (string_of_int n)
          | P.DO          -> "DO"
          | P.DOT         -> "DOT"
          | P.DOTS        -> "DOTS"
          | P.ELSE        -> "ELSE"
          | P.ELSEIF      -> "ELSEIF"
          | P.END         -> "END"
          | P.EOF         -> "EOF"
          | P.EQ          -> "EQ"
          | P.FUNCTION    -> "FUNCTION"
          | P.GE          -> "GE"
          | P.GETS        -> "GETS"
          | P.GLOBMATCH   -> "GLOBMATCH"
          | P.GT          -> "GT"
          | P.HAT         -> "HAT"
          | P.IF          -> "IF"
          | P.LBRA        -> "LBRA"
          | P.LE          -> "LE"
          | P.LOCAL       -> "LOCAL"
          | P.LPAR        -> "LPAR"
          | P.LSQ         -> "LSQ"
          | P.LT          -> "LT"
          | P.MINUS       -> "MINUS"
          | P.NAME x      -> "NAME("^x^")"  
          | P.NE          -> "NE"
          | P.NIL         -> "NIL"
          | P.NOT         -> "NOT"
          | P.NUMBER _    -> "NUMBER" 
          | P.OF          -> "OF"
          | P.OR          -> "OR"
          | P.PLUS        -> "PLUS"
          | P.RBRA        -> "RBRA"
          | P.REPEAT      -> "REPEAT"
          | P.RETURN      -> "RETURN"
          | P.RPAR        -> "RPAR"
          | P.RSQ         -> "RSQ"
          | P.SEMI        -> "SEMI"
          | P.SLASH       -> "SLASH"
          | P.STAR        -> "STAR"
          | P.STRING x    -> "STRING("^x^")" 
          | P.THEN        -> "THEN"
          | P.UNARY       -> "UNARY"
          | P.UNTIL       -> "UNTIL"
          | P.WHILE       -> "WHILE"
          | P.WRONGTOKEN  -> "WRONGTOKEN"
    
# 860 "lua-ml/luascanner.ml"
