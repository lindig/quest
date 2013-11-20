$file "demo.lua"
$line 1

--
-- $Id: demo.lua 3 2006-04-29 13:17:19Z lindig $
--
-- Sample Generator for Quest. 

R = Rand

Demo = {}
Demo.members        = R.choose(1,3) -- for structs, unions
Demo.argc           = ANSI.argc
Demo.vargc          = ANSI.vargc
Demo.simple         = ANSI.simple
Demo.simple_varg    = ANSI.simple_varg
Demo.array_size     = R.freq { 2, R.unit(0)
                             , 2, R.unit(1) 
                             , 1, R.unit(2) 
                             , 1, R.unit(3) 
                             }

-- result type
-- no arrays, because this would be illegal in C

function Demo.result_ (issimple)
    if issimple then
        return Demo.simple
    else 
        return R.smaller 
        { R.any_int
        , R.any_float
        , R.pointer(Demo.result)
        , R.struct(R.list(Demo.members,Demo.arg))
        , R.union(R.list(Demo.members,Demo.arg))
        }
    end     
end    
Demo.result = R.bind(R.iszero,Demo.result_)

--
-- argument
-- regular function argument

function Demo.arg_ (issimple)
    if issimple then
        return Demo.simple
    else 
        return R.smaller 
        { R.any_int
        , R.any_float
        , R.pointer(Demo.arg)
        , R.array(Demo.arg,Demo.array_size)
        , R.struct(R.list(Demo.members,Demo.arg))
        , R.union(R.list(Demo.members,Demo.arg))
        }
    end     
end    
Demo.arg = R.bind(R.iszero,Demo.arg_)

-- var arg
-- 
-- a var arg must not be smaller than an int or a double, according to
-- the ANSI C specification. I am not sure, but unsigned simple values,
-- are prohibited, too. However, all these types are allowed as part of
-- complex types.

Demo.small = R.oneof -- illegal types for varargs
    { R.char 
    , R.unsigned(R.char)
    , R.short
    , R.unsigned(R.short)
    , R.float
    }

function Demo.varg_ (issimple)
    if issimple then
        return R.int
    else return R.smaller
        { R.struct(R.list(Demo.members,Demo.arg))
        , R.union(R.list(Demo.members,Demo.arg))
        }
    end
end
Demo.varg = R.bind(R.iszero,Demo.varg_)

--
-- This function assembles the different generators into one table
-- and returns it. Because it is a function we can change the values of
-- global variables (like Demo.argc) from the command line before the
-- function is evaluated.
--

function Demo.test () return
    { args       = R.list(R.choose(1,4),Demo.arg)
    , varargs    = R.list(R.choose(1,2),Demo.simple)
    , result     = Demo.result
    , static     = R.flip
    }

end

-- 
-- The following assignment makes the new generator visible
-- for the -list and -test command line options and hence registers the
-- new generator. 

Test.demo =
    { doc        = "ANSI C, for experiments"
    , test       = Demo.test
    }


