#! /bin/sh

while true; do
    ./main.native -2 -test ansi 
    gcc -O2 -c quest-callee.c
    gcc -O2 -c quest-main.c
    gcc -O2 -o foo quest-callee.o quest-main.o || break
    ./foo || break
    /bin/echo -n .
done


