
# 12 "main.nw"
module T  = Lua.Lib.Combine.T1 (Luaiolib.T)
module WT = Lua.Lib.WithType (T)
module C  = Lua.Lib.Combine.C4 (Luaiolib.Make (T.TV1)) (Luacamllib.Make(T.TV1))
                               (WT(Luastrlib.M)) (WT(Luamathlib.M))
(*
module I = Lua.MakeInterp (Lua.Parser.MakeStandard) (Oldinterp.Make3 (T) (C))
*)

module T2  = Lua.Lib.Combine.T1 (T)
module T'  = Lualib.Lift (T) (T2.TV1)
module WT' = Lua.Lib.WithType (T2)
module C'  = Lua.Lib.Combine.C4 (Luaiolib.Make (T'.TV1)) (Luacamllib.Make(T'.TV1))
                               (WT'(Luastrlib.M)) (WT'(Luamathlib.M))
(*
module I' = Lua.MakeInterp (Lua.Parser.MakeStandard) (Oldinterp.Make3 (T2) (C'))
*)


module I'' = Lua.MakeInterp (Lua.Parser.MakeStandard) (Lua.MakeEval (T) (C))

module V = I''.Value
let ( **-> ) = V. ( **-> )
let ( **->> ) x y = x **-> V.result y
let my_atan2 = 
   let t = V.func (V.float **-> V.float **->> V.float) 
   in  t.V.embed atan2

type value = V.value
let my_atan2 = (my_atan2 : value)


module Go = Lua.Run(I'')
