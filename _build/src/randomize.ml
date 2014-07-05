
# 103 "randomize.nw"
type size = int
type 'a t = int -> 'a

let (@@) f x        = f x
let return a        = fun size -> a
let (>>=) m k       = fun size -> let m' = k (m size) in m' size
let bind            = (>>=)
let lift  f m       = m  >>= fun a -> return (f a)
let lift2 f m1 m2   = m1 >>= fun a -> m2 >>= fun b -> return (f a b)
let run m s         = m s
let random_int n    = assert (n>=1); Random.int n
let random_int n    = assert (n>=1); Prg.int n
let size            = fun size -> size
let smaller m       = fun size -> m (size-1)
let iszero          = fun size -> size = 0

let int limit       = fun size -> random_int limit
let flip            = fun size -> match random_int 2 with
                      | 0   -> false
                      | _   -> true

let concat (ts: 'a t list) = fun size ->
                        let xs = List.map (fun t -> t size) ts in
                            List.concat xs

let choose lo hi =
    let lo,hi = if hi < lo then hi,lo else lo,hi in
    fun size -> lo + random_int (hi-lo+1)

# 134 "randomize.nw"
let list size t = 
    size >>= fun n ->  
    fun size ->
    let rec loop i = 
        if i <= 0 then [] else t size :: loop (i-1) 
    in
        List.rev @@ loop n

let elements xs =
    let a   = Array.of_list xs in
    let len = Array.length a   in 
        lift (Array.get a) (int len)

let oneof ts = elements ts >>= (fun x -> x)

let freq pairs = 
    let sum  = List.fold_left (fun s pair -> s + fst pair) 0 pairs in
    let rec pick n = function
        | []                    -> assert false
        | (k,x)::xs when n <= k -> x
        | (k,x)::xs             -> pick (n-k) xs
    in
        int sum >>= fun n -> pick n pairs
