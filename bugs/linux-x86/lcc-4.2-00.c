/* $Id: lcc-4.2-00.c 3 2006-04-29 13:17:19Z lindig $ */
/* /scratch/lindig/src/quest/src/quest -test ansi */



#include <stdarg.h>


extern int printf (char *, ...);

static int errors = 0;

static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }

static
union at8 { double av8; unsigned long int *bv8; } cv8 =
    { 58646.434730 };

static float ov8[1] = { 18794.291505 };

static
struct et8
{ struct dt8 { char kv8; } lv8; unsigned short int mv8[1]; char nv8[1]; }
pv8
=
    { { '\x26' }, { 48992 }, { '\x5' } };

static double hv8 = 40902.508205;

static int iv8 = 1589164829;

static
struct ct8 { union bt8 { double dv8; double ev8; float fv8; } gv8; } jv8 =
    { { 70716.689318 } };

static union at8 callee_af8( float ap8[1], struct et8 bp8, ... )
{
    va_list ap;
    double qv8;
    int rv8;
    struct ct8 sv8;
    va_start (ap, bp8);
    if (ov8[0] !=  ap8[0]) failed (__LINE__);
    if (pv8.lv8.kv8 !=  bp8.lv8.kv8) failed (__LINE__);
    if (pv8.mv8[0] !=  bp8.mv8[0]) failed (__LINE__);
    if (pv8.nv8[0] !=  bp8.nv8[0]) failed (__LINE__);
    qv8 = va_arg (ap, double);
    rv8 = va_arg (ap, int);
    sv8 = va_arg (ap, struct ct8);
    if (hv8 !=  qv8) failed (__LINE__);
    if (iv8 !=  rv8) failed (__LINE__);
    if (jv8.gv8.dv8 !=  sv8.gv8.dv8) failed (__LINE__);
    va_end (ap);
    return cv8;
}

static void caller_bf8(  )
{
    union at8 tv8;
    tv8 = callee_af8 (ov8, pv8, hv8, iv8, jv8);
    if (cv8.av8 !=  tv8.av8) failed (__LINE__);
}

int main( int argc, char **argv )
{
    caller_bf8 ();
    return errors;
}
