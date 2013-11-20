#! /bin/sh
# 
# $Id: runcc.sh,v 1.1.1.1 2004-04-22 13:53:05 lindig Exp $
# 
# usage: run.sh *.c --  compiles and runs all *.c files.
# call as "env CC=gcc run.sh" to override options
#

#set -x     # uncomment to see what the script is doing

CC=${CC:=cc}            # CC=/path/to/cc
CFLAGS=${CFLAGS:=""}    # CFLAGS="-g"

LOG=${LOG:=quest.log}

rm -f $LOG
uname -a                        >  $LOG
date                            >> $LOG
hostname                        >> $LOG 
echo "CC=$CC CFLAGS=$CFLAGS"    >> $LOG

for f in $@; do
    f=`basename $f .c`
    for OPT in "" "-O" "-O2" "-O3"; do
        echo "$CC $CFLAGS -o $f $f.c" 
        $CC $CFLAGS -o $f $f.c 
        ./$f | tee -a $LOG
        rm -f $f
    done     
done
exit 0
    
