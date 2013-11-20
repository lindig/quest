
# 175 "srcmap.nw"
type pos            = int
type rgn            = pos * pos
type location       = string    (* file   *)
                    * int       (* line   *)
                    * int       (* column *)

# 181 "srcmap.nw"
let null = (0,0)

# 189 "srcmap.nw"
type syncpoint      = pos * location

# 213 "srcmap.nw"
type map =          { mutable points:       syncpoint array 
                    ; mutable top:          int
                    ; files :               (string, string) Hashtbl.t
                    }
type point          = map * pos
type region         = map * rgn

# 227 "srcmap.nw"
let size        =  2    (* small to test alloc *)
let undefined   =  (0, ("undefined", -1, -1))    


# 231 "srcmap.nw"
let mk () =
    { points  = Array.create size undefined 
    ; top     = 0
    ; files   = Hashtbl.create 17
    }    

# 244 "srcmap.nw"

let alloc srcmap =
    let length = Array.length srcmap.points in
        if   srcmap.top < length then 
            ()
        else 
            let points' = Array.create length undefined in
                srcmap.points <- Array.append srcmap.points points'

# 261 "srcmap.nw"
let sync srcmap pos (file,line,col) =
    let _     = alloc srcmap in
    let file' = try  Hashtbl.find srcmap.files file
                with Not_found -> ( Hashtbl.add srcmap.files file file
                                  ; file
                                  ) 
    in
    let location' = (file', line, col) in
    let top   = srcmap.top   in
        ( assert ((pos = 0) || (fst srcmap.points.(top-1) < pos))
        ; srcmap.points.(top) <- (pos,location')
        ; srcmap.top <- srcmap.top + 1
        )

# 280 "srcmap.nw"
let last map =
    ( assert (map.top > 0 && map.top <= Array.length map.points)
    ; snd map.points.(map.top-1)
    )

# 305 "srcmap.nw"
let nl srcmap pos =
    let _               = alloc srcmap  in
    let (file, line, _) = last srcmap   in
    let location' = (file, line+1,1) in
    let top   = srcmap.top   in
        ( assert ((pos = 0) || (fst srcmap.points.(top-1) < pos))
        ; srcmap.points.(top) <- (pos,location')
        ; srcmap.top <- srcmap.top + 1
        )

# 320 "srcmap.nw"
let cmp x (y,_) = compare x y

# 330 "srcmap.nw"
let search x array length cmp =
    let rec loop left right =
        if left > right then
            ( assert (0 <= right && right < Array.length array)
            ; array.(right)
            )
        else
            let pivot = (left + right)/2 in
            let res   = cmp x array.(pivot) in
            let _     = assert (0 <= pivot && pivot < Array.length array) in
                
                if res = 0 then 
                    array.(pivot)
                else if res < 0 then
                    loop left (pivot-1)
                else
                    loop (pivot+1) right
    in
        ( assert (length > 0)
        ; loop 0 (length-1)
        )

# 360 "srcmap.nw"
let location map pos =
    let pos',(file,line,col) = search pos map.points map.top cmp in
    (file,line,pos - pos' + col)

# 369 "srcmap.nw"
let dump map =
    let point (pos,(file,line,col)) = 
        Printf.printf "%5d: %-32s %4d %3d\n" pos file line col
    in
        for i=0 to map.top-1 do
            point map.points.(i)
        done

# 382 "srcmap.nw"
module Str = struct
    let point  (map,pos) =
      let (file,line,column) = location map pos in
      Printf.sprintf "File \"%s\", line %d, character %d" file line column

    
    let region (map,rgn) =
        match rgn with 
        | (0,0)        -> Printf.sprintf "<unknown location>"
        | (left,right) -> 
        let (file1,l1,col1) = location map left   in
        let (file2,l2,col2) = location map right  in
        let (=$=) : string -> string -> bool = Pervasives.(=) in
            if file1 =$= file2 && l1 = l2 then
                Printf.sprintf 
                "File \"%s\", line %d, characters %d-%d" file1 l1 col1 col2
            else if file1 =$= file2 then
                Printf.sprintf 
                "File \"%s\", line %d, character %d - line %d, character %d"
                file1 l1 col1 l2 col2
            else
                Printf.sprintf 
                "File \"%s\", line %d, character %d - file %s, line %d, character %d"
                file1 l1 col2 file2 l2 col2
end
