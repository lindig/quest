$file "demo.lua"
$line 1

--
-- $Id: mips.lua 3 2006-04-29 13:17:19Z lindig $
--
-- Sample Generator for Quest. 

R = Rand

Mips = {}
Mips.members        = R.choose(1,4) -- for structs, unions
Mips.argc           = R.choose(1,8)
Mips.vargc          = R.oneof { R.unit(0), R.choose(1,4) } -- vargv length
Mips.simple         = ANSI.simple
Mips.simple_varg    = ANSI.simple_varg
Mips.array_size     = R.freq { 2, R.unit(1) 
                             , 1, R.unit(2) 
                             , 1, R.unit(3) 
                             }
--
-- argument
-- regular function argument

function Mips.arg_ (issimple)
    if issimple then
        return Mips.simple
    else 
        return R.smaller{ R.freq 
        {  2, R.any_int
        ,  2, R.any_float
        ,  1, R.pointer(Mips.arg)
        ,  1, R.array(Mips.arg,Mips.array_size)
        ,  3, R.struct(R.list(Mips.members,Mips.arg))
        ,  3, R.union (R.list(Mips.members,Mips.arg))
        }}
    end     
end    
Mips.arg = R.bind(R.iszero,Mips.arg_)

-- var arg
-- 
-- a var arg must not be smaller than an int or a double, according to
-- the ANSI C specification. I am not sure, but unsigned simple values,
-- are prohibited, too. However, all these types are allowed as part of
-- complex types.

Mips.small = R.oneof -- illegal types for varargs
    { R.char 
    , R.unsigned(R.char)
    , R.short
    , R.unsigned(R.short)
    , R.float
    }

Mips.big = R.oneof
    { R.int
    , R.unsigned(R.int)
    , R.long
    , R.unsigned(R.long)
    , R.longlong
    , R.unsigned(R.longlong)
    , R.double
    }

function Mips.varg_ (issimple)
    if issimple then
        return Mips.big
    else return R.smaller
        { Mips.big
        , R.pointer(Mips.arg)
        , R.struct(R.list(Mips.members,Mips.arg))
        , R.union (R.list(Mips.members,Mips.arg))
        }
    end
end
Mips.varg = R.bind(R.iszero,Mips.varg_)

-- result type
-- no arrays, because this would be illegal in C

function Mips.result_ (issimple)
    if issimple then
        return Mips.simple
    else 
        return R.smaller 
        { R.any_int
        , R.any_float
        , R.pointer(Mips.result)
        , R.struct(R.list(Mips.members,Mips.arg))
        , R.union (R.list(Mips.members,Mips.arg))
        }
    end     
end    
Mips.result = R.bind(R.iszero,Mips.result_)


--
-- This function assembles the different generators into one table
-- and returns it. Because it is a function we can change the values of
-- global variables (like Mips.argc) from the command line before the
-- function is evaluated.
--

function Mips.test () return
    { args       = R.list(Mips.argc,Mips.arg)
    , varargs    = R.list(Mips.vargc,Mips.varg)
    , result     = Mips.result
    , static     = R.flip
    }

end

-- 
-- The following assignment makes the new generator visible
-- for the -list and -test command line options and hence registers the
-- new generator. 

Test.mips =
    { doc        = "ANSI C, tuned for MIPS"
    , test       = Mips.test
    }


