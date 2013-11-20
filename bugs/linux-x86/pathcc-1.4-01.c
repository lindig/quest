/* $Id: pathcc-1.4-01.c 3 2006-04-29 13:17:19Z lindig $ */
/* ./quest -n 1 -test ansi -seed -94691739 */

#include <stdarg.h>

#include <assert.h>

extern int printf (char *, ...);
static int errors = 0;
static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }
static float av1 = 69711.390376;
static
struct et1 { union dt1 { unsigned char lv1; } mv1; } tv1 =
    { { '\x78' } };
static
union gt1 { struct ft1 { unsigned int nv1; } ov1; long int pv1; } uv1 =
    { { 167291901U } };
static union ht1 { double qv1; float rv1; } vv1 = { 76057.892951 };
static union it1 { float sv1; } *wv1 = (union it1 *) 1138859006U;
static double hv1 = 5841.058769;
static int iv1 = 1582263342;
static float (*jv1)[2] = (float (*)[2]) 775195099U;
static
struct ct1
{
    union at1 { double bv1; double cv1; long int dv1; } ev1;
    union bt1 { double fv1; } gv1;
}
kv1
=
    { { 85745.508291 }, { 98895.905285 } };
static
float
callee_af1(
    struct et1 ap1,
    union gt1 bp1,
    union ht1 cp1,
    union it1 *dp1,
    ...
)
{
    va_list ap;
    typedef double ad1;
    typedef int bd1;
    typedef float (*cd1)[2];
    typedef struct ct1 dd1;
    ad1 xv1;
    bd1 yv1;
    cd1 zv1;
    dd1 bav1;
    /* seed: -94691739 */
    va_start (ap, dp1);
    assert (tv1.mv1.lv1 ==  ap1.mv1.lv1);
    assert (uv1.ov1.nv1 ==  bp1.ov1.nv1);
    assert (vv1.qv1 ==  cp1.qv1);
    assert (wv1 ==  dp1);
    xv1 = va_arg (ap, ad1);
    yv1 = va_arg (ap, bd1);
    zv1 = va_arg (ap, cd1);
    bav1 = va_arg (ap, dd1);
    assert (hv1 ==  xv1);
    assert (iv1 ==  yv1);
    assert (jv1 ==  zv1);
    assert (kv1.ev1.bv1 ==  bav1.ev1.bv1);
    assert (kv1.gv1.fv1 ==  bav1.gv1.fv1);
    va_end (ap);
    return av1;
}
static void caller_bf1(  )
{
    float bbv1;
    /* seed: -94691739 */
    bbv1 = callee_af1 (tv1, uv1, vv1, wv1, hv1, iv1, jv1, kv1);
    assert (av1 ==  bbv1);
}
int main( int argc, char **argv ) { caller_bf1 (); return errors; }

/*
 * : tmp; ./quest -n 1 -test ansi -seed -94691739 > pathcc-1.4-01.c:
 * tmp; pathcc -m32 -O2 -o pathcc-1.4-01 pathcc-1.4-01.c 
 * : tmp; ./pathcc-1.4-01 
 * pathcc-1.4-01: pathcc-1.4-01.c:55: callee_af1: Assertion `uv1.ov1.nv1
 * == bp1.ov1.nv1' failed.
 * Aborted
 */
/*
PathScale EKO Compiler Suite(TM): Version 1.4
Built on: 2004-09-29 17:33:11 -0700
gcc version 3.3.1 (PathScale 1.4 driver)
*/
