$file "ansi.lua"
$line 1
--
-- $Id: ansi.lua 3 2006-04-29 13:17:19Z lindig $
--
-- Quest generator for ANSI C.
--

R    = Rand

ANSI = {}

-- below is an alternative implementation of any_int; unlike R.any_int,
-- it does not generate long long ints.

ANSI.any_int = R.oneof
    { R.char
    , R.short
    , R.int
    , R.long
    , R.unsigned(R.char)
    , R.unsigned(R.short)
    , R.unsigned(R.int)
    , R.unsigned(R.long)
    }

ANSI.any_int        = R.any_int
ANSI.any_float      = R.any_float

ANSI.members        = R.choose(1,3)  -- for structs, unions
ANSI.argc           = R.choose(1,10) -- argv  length
ANSI.vargc          = R.oneof { R.unit(0), R.choose(1,4) } -- vargv length
ANSI.simple         = R.oneof { ANSI.any_int, ANSI.any_float }
ANSI.simple_varg    = R.oneof { R.int , R.long , R.longlong , R.double }
ANSI.array_size     = R.freq { 2, R.unit(1) , 1, R.unit(2) , 1, R.unit(3) }
ANSI.bitfields      = R.list(R.choose(0,4),R.bitfield(R.choose(2,12)))

function ANSI.result_ (issimple)
    if issimple then
        return ANSI.simple
    else 
        return R.smaller 
        { ANSI.any_int
        , ANSI.any_float
        , R.pointer(ANSI.result)
        , R.struct(R.list(ANSI.members,ANSI.arg))
        , R.union(R.list(ANSI.members,ANSI.arg))
        }
    end     
end    
ANSI.result = R.bind(R.iszero,ANSI.result_)

--
-- argument
--


function ANSI.arg_ (issimple)
    if issimple then
        return ANSI.simple
    else 
        return R.smaller 
        { ANSI.any_int
        , ANSI.any_float
        , R.pointer(ANSI.arg)
        , R.array(ANSI.arg,ANSI.array_size)
        , R.struct(R.concat{ R.list(ANSI.members,ANSI.arg)
                            , ANSI.bitfields
                            , R.list(ANSI.members,ANSI.arg)
                            })
        , R.union(R.list(ANSI.members,ANSI.arg))
        }
    end     
end    
ANSI.arg = R.bind(R.iszero,ANSI.arg_)

-- a var arg must not be smaller than an int or a double, according to
-- the ANSI C specification. I am not sure, but unsigned simple values,
-- are prohibited, too. However, all these types are allowed as part of
-- complex types.

function ANSI.varg_ (issimple)
    if issimple then
        return ANSI.simple_varg
    else return R.smaller
        { R.int
        , R.double
        , R.long
        , R.longlong
        , R.double
        , R.pointer(ANSI.varg)
        , R.array(ANSI.arg, ANSI.array_size)
        , R.struct(R.list(ANSI.members,ANSI.arg))
        , R.union(R.list(ANSI.members,ANSI.arg))
        }
    end
end
ANSI.varg = R.bind(R.iszero,ANSI.varg_)

-- Here we make the generator [[ansi]] available from the command line by
-- registering it within the [[Test]] table.  Because we have var args, we
-- need to have at least one regular parameter. Test.ansi is a function
-- such that variables like ANSI.argc are not immediately read. We
-- therefore have a chance to modify them on the command line before the
-- function is evaluated.

function ANSI.test () return
    { args       = R.list(ANSI.argc,ANSI.arg)
    , varargs    = R.list(ANSI.vargc,ANSI.varg)
    , result     = ANSI.result
    , static     = R.flip
    }
end

Test.ansi = 
    { doc        = "ANSI C, including var args"
    , test       = ANSI.test
    }

