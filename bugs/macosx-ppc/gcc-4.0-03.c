/* $Id: gcc-4.0-03.c 3 2006-04-29 13:17:19Z lindig $ */
/* ./quest -lua quest.lua -n 2 -test demo */

/*
: tmp; /scratch/lindig/bin/gcc -v
Using built-in specs.
Configured with: /scratch/lindig/src/gcc/gcc/configure
--cache-file=./config.cache --build=powerpc-apple-darwin7.6.0
--host=powerpc-apple-darwin7.6.0 --target=powerpc-apple-darwin7.6.0
--prefix=/scratch/lindig
--with-gcc-version-trigger=/scratch/lindig/src/gcc/gcc/version.c
--enable-languages=c --program-transform-name=s,y,y,
--srcdir=../../gcc/gcc
Thread model: posix
gcc version 4.0.0 20050103 (experimental)
: tmp; vim apple-bug-varg.c 
: tmp; /scratch/lindig/bin/gcc -o foo -O2 apple-bug-varg-2.c 
: tmp; ./foo 
failed in apple-bug-varg-2.c: 43
failed in apple-bug-varg-2.c: 44
*/

#include <stdarg.h>


extern int printf (char *, ...);

static int errors = 0;

static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }

static unsigned long int *av2 = (unsigned long int *) 361451618U;

static struct bt2 { float fv2; } kv2 = { 3984.018652 };

static
struct dt2
{ char gv2; struct ct2 { unsigned char hv2; unsigned char iv2; } jv2; }
lv2
=
    { '\x4f', { '\x27', '\x20' } };

static struct at2 { short int bv2; char cv2; } dv2 = { 14855, '\x3d' };

static double ev2 = 67318.083071;

static unsigned long int * callee_af2( struct bt2 ap2, struct dt2 bp2, ... )
{
    va_list ap;
    struct at2 mv2;
    double nv2;
    va_start (ap, bp2);
    if (kv2.fv2 !=  ap2.fv2) failed (__LINE__);
    if (lv2.gv2 !=  bp2.gv2) failed (__LINE__);
    if (lv2.jv2.hv2 !=  bp2.jv2.hv2) failed (__LINE__);
    if (lv2.jv2.iv2 !=  bp2.jv2.iv2) failed (__LINE__);
    mv2 = va_arg (ap, struct at2);
    nv2 = va_arg (ap, double);
    if (mv2.bv2 !=  dv2.bv2) failed (__LINE__);
    if (mv2.cv2 !=  dv2.cv2) failed (__LINE__);
    if (nv2 !=  ev2) failed (__LINE__);
    va_end (ap);
    return av2;
}

static void caller_bf2(  )
{
    unsigned long int *ov2;
    ov2 = callee_af2 (kv2, lv2, dv2, ev2); if (av2 !=  ov2) failed (__LINE__);
}

static
union at1 { short int av1; double bv1; } *cv1 =
    (union at1 *) 440008236U;

static union bt1 { double *ev1; char fv1; } gv1 = { (double *) 68753118U };

static double dv1 = 37253.636691;

static union at1 * callee_af1( union bt1 ap1, ... )
{
    va_list ap;
    double hv1;
    va_start (ap, ap1);
    if (gv1.ev1 !=  ap1.ev1) failed (__LINE__);
    hv1 = va_arg (ap, double);
    if (hv1 !=  dv1) failed (__LINE__);
    va_end (ap);
    return cv1;
}

static void caller_bf1(  )
{
    union at1 *iv1;
    iv1 = callee_af1 (gv1, dv1); if (cv1 !=  iv1) failed (__LINE__);
}

int main( int argc, char **argv )
{ caller_bf2 (); caller_bf1 (); return errors; }
