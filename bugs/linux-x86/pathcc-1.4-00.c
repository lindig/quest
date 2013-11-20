/* $Id: pathcc-1.4-00.c 3 2006-04-29 13:17:19Z lindig $ */
/* ./quest -n 1 -test gcc -seed 307702022 */

#include <assert.h>

extern int printf (char *, ...);
static int errors = 0;
static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }
static union bt1 { struct at1 {  } av1; } bv1 = { {  } };
static double kv1 = 60000.463169;
static union ct1 {  } lv1 = {  };
static struct et1 { struct dt1 { char cv1; } dv1; } mv1 = { { '\x28' } };
static float nv1 = 25863.683872;
static
struct gt1
{
    double ev1;
    union ft1 { int fv1; long int gv1; unsigned long long int hv1; } iv1;
    double jv1;
}
ov1
=
    { 27606.538296, { 1774572204 }, 35671.444353 };
static
union bt1
callee_af1(
    double ap1,
    union ct1 bp1,
    struct et1 cp1,
    float dp1,
    struct gt1 ep1
)
{
    /* seed: 307702022 */
    assert (kv1 ==  ap1);
    assert (mv1.dv1.cv1 ==  cp1.dv1.cv1);
    assert (nv1 ==  dp1);
    assert (ov1.ev1 ==  ep1.ev1);
    assert (ov1.iv1.fv1 ==  ep1.iv1.fv1);
    assert (ov1.jv1 ==  ep1.jv1);
    return bv1;
}
static void caller_bf1(  )
{
    union bt1 pv1;
    /* seed: 307702022 */ pv1 = callee_af1 (kv1, lv1, mv1, nv1, ov1);
}
int main( int argc, char **argv ) { caller_bf1 (); return errors; }

/*
 * pathcc -m32 -O2 -o pathcc-1.4-bug pathcc-1.4-bug.c 
 * ./pathcc-1.4-bug 
 * pathcc-1.4-bug: pathcc-1.4-bug.c:38: callee_af1: Assertion `nv1 == dp1' failed.
 * pathcc -v
 * PathScale EKO Compiler Suite(TM): Version 1.4
 * Built on: 2004-09-29 17:33:11 -0700
 * gcc version 3.3.1 (PathScale 1.4 driver)
 */

