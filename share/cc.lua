$file "cc.lua"
$line 1
--
-- $Id: ansi.lua 3 2006-04-29 13:17:19Z lindig $
--
-- Quest generator for ANSI C.
--

R    = Rand

CC = {}

-- below is an alternative implementation of any_int; unlike R.any_int,
-- it does not generate long long ints.

CC.any_int = R.oneof
    { R.char
    , R.short
    , R.int
    , R.long
    , R.unsigned(R.char)
    , R.unsigned(R.short)
    , R.unsigned(R.int)
    , R.unsigned(R.long)
    -- , R.unsigned(R.longlong)
    }

CC.any_float      = R.any_float

CC.members        = R.choose(1,3)  -- for structs, unions
CC.argc           = R.choose(1,10) -- argv  length
CC.vargc          = R.oneof { R.unit(0), R.choose(1,4) } -- vargv length
CC.simple         = R.oneof { CC.any_int, CC.any_float }
CC.simple_varg    = R.oneof { R.int , R.long , R.double }
CC.array_size     = R.freq { 2, R.unit(1) , 1, R.unit(2) , 1, R.unit(3) }
CC.bitfields      = R.list(R.choose(0,4),R.bitfield(R.choose(2,12)))

function CC.result_ (issimple)
    if issimple then
        return CC.simple
    else 
        return R.smaller 
        { CC.any_int
        , CC.any_float
        , R.pointer(CC.result)
        , R.struct(R.list(CC.members,CC.arg))
        , R.union(R.list(CC.members,CC.arg))
        }
    end     
end    
CC.result = R.bind(R.iszero,CC.result_)

--
-- argument
--


function CC.arg_ (issimple)
    if issimple then
        return CC.simple
    else 
        return R.smaller 
        { CC.any_int
        , CC.any_float
        , R.pointer(CC.arg)
        , R.array(CC.arg,CC.array_size)
        , R.struct(R.concat{ R.list(CC.members,CC.arg)
                            , CC.bitfields
                            , R.list(CC.members,CC.arg)
                            })
        , R.union(R.list(CC.members,CC.arg))
        }
    end     
end    
CC.arg = R.bind(R.iszero,CC.arg_)

-- a var arg must not be smaller than an int or a double, according to
-- the CC C specification. I am not sure, but unsigned simple values,
-- are prohibited, too. However, all these types are allowed as part of
-- complex types.

function CC.varg_ (issimple)
    if issimple then
        return CC.simple_varg
    else return R.smaller
        { R.int
        , R.double
        , R.long
        -- , R.longlong
        , R.double
        , R.pointer(CC.varg)
        , R.array(CC.arg, CC.array_size)
        , R.struct(R.list(CC.members,CC.arg))
        , R.union(R.list(CC.members,CC.arg))
        }
    end
end
CC.varg = R.bind(R.iszero,CC.varg_)

-- Here we make the generator [[ansi]] available from the command line by
-- registering it within the [[Test]] table.  Because we have var args, we
-- need to have at least one regular parameter. Test.ansi is a function
-- such that variables like CC.argc are not immediately read. We
-- therefore have a chance to modify them on the command line before the
-- function is evaluated.

function CC.test () return
    { args       = R.list(CC.argc,CC.arg)
    , varargs    = R.list(CC.vargc,CC.varg)
    , result     = CC.result
    , static     = R.flip
    }
end

Test.cc = 
    { doc        = "CC C, including var args"
    , test       = CC.test
    }

