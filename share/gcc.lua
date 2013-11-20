$file "gcc.lua"
$line 1

--
-- $Id: gcc.lua 3 2006-04-29 13:17:19Z lindig $
--
-- Generator for GCC, uses empty structs, unions, and arrays.
--
-- This file depends on ansi.lua, which must be loaded first!
--

GCC = {}
GCC.members        = R.choose(0,3) -- for structs, unions
GCC.argc           = ANSI.argc
GCC.vargc          = ANSI.vargc
GCC.simple         = ANSI.simple
GCC.simple_varg    = ANSI.simple_varg
GCC.array_size     = R.freq { 2, R.unit(0)
                            , 2, R.unit(1) 
                            , 1, R.unit(2) 
                            , 1, R.unit(3) 
                            }
GCC.bitfields      = ANSI.bitfields

GCC.any_int = R.oneof
    { R.char
    , R.short
    , R.int
    , R.long
    , R.longlong
    , R.unsigned(R.char)
    , R.unsigned(R.short)
    , R.unsigned(R.int)
    , R.unsigned(R.long)
    , R.unsigned(R.longlong)
    }

GCC.any_float = R.oneof
    { R.float
    , R.double
    -- , R.longdouble -- GCC emits warning, so let's not use it
    }

function GCC.result_ (issimple)
    if issimple then
        return GCC.simple
    else 
        return R.smaller 
        { GCC.any_int
        , GCC.any_float
        , R.pointer(GCC.result)
        , R.struct(R.list(GCC.members,GCC.arg))
        , R.union(R.list(GCC.members,GCC.arg))
        }
    end     
end    
GCC.result = R.bind(R.iszero,GCC.result_)

--
-- argument
--

function GCC.arg_ (issimple)
    if issimple then
        return GCC.simple
    else 
        return R.smaller 
        { GCC.any_int
        , GCC.any_float
        , R.pointer(GCC.arg)
        , R.array(GCC.arg,GCC.array_size)
        , R.struct(R.concat{ R.list(GCC.members,GCC.arg)
                            , GCC.bitfields
                            , R.list(GCC.members,GCC.arg)
                            })
        , R.union(R.list(GCC.members,GCC.arg))
        }
    end     
end    
GCC.arg = R.bind(R.iszero,GCC.arg_)

-- a var arg must not be smaller than an int or a double, according to
-- the GCC C specification. I am not sure, but unsigned simple values,
-- are prohibited, too. However, all these types are allowed as part of
-- complex types.

function GCC.varg_ (issimple)
    if issimple then
        return GCC.simple_varg
    else return R.smaller
        { R.int
        , R.double
        , R.long
        , R.longlong
        , R.double
        -- , R.longdouble -- GCC emits a warning
        , R.pointer(GCC.varg)
        , R.array(GCC.arg, R.choose(1,2))
        , R.struct(R.list(GCC.members,GCC.arg))
        , R.union(R.list(GCC.members,GCC.arg))
        }
    end
end
GCC.varg = R.bind(R.iszero,GCC.varg_)

function GCC.test () return 
    { args       = R.list(GCC.argc,GCC.arg)
    , varargs    = R.list(GCC.vargc,GCC.varg)
    , result     = GCC.result
    , static     = R.flip
    }
end

Test.gcc =
    { doc        = "code for GCC, including var args, empty structs"
    , test       = GCC.test
    }

