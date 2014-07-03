$file "toy.lua"
$line 1

-- A generator for a toy C compiler that only knows int, char as base types
-- and pointers to these.

R    = Rand

TOY = {}

TOY.base = R.oneof
    { R.char
    , R.int
    }

TOY.members        = R.choose(1,3)  -- for structs, unions
TOY.argc           = R.choose(1,10) -- argv  length

function TOY.result_ (issimple)
    if issimple then
        return TOY.base
    else 
        return R.smaller 
        { R.char
        , R.int
        , R.pointer(TOY.result)
        }
    end     
end    
TOY.result = R.bind(R.iszero,TOY.result_)


function TOY.arg_ (issimple)
    if issimple then
        return TOY.base
    else 
        return R.smaller 
        { R.int
        , R.char
        , R.pointer(TOY.arg)
        }
    end     
end    
TOY.arg = R.bind(R.iszero,TOY.arg_)

function TOY.test () return
    { args       = R.list(TOY.argc,TOY.arg)
    , varargs    = R.list(R.unit(0),TOY.arg)
    , result     = TOY.result
    , static     = R.flip
    }
end

Test.toy = 
    { doc        = "Toy C, no structs"
    , test       = TOY.test
    }

