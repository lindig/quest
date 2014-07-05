
# 36 "util.nw"
let foldn f n z = 
    let rec loop acc = function
    | k when k = n  -> acc
    | k             -> loop (f k acc) (k+1)
    in
        loop z 0

# 45 "util.nw"
let rec map3 f xs ys zs = match xs, ys, zs with
    | x::xs, y::ys, z::zs -> f x y z :: map3 f xs ys zs
    | []   , []   , []    -> []
    | _                   -> invalid_arg "Util.map3: lists of different lengths"

# 52 "util.nw"
let (@@) f x = f x

# 56 "util.nw"
let rec last = function
    | []    -> failwith "Util.last: empty list"
    | [x]   -> x
    | x::xs -> last xs
