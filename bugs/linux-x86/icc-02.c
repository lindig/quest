/* $Id: icc-02.c 3 2006-04-29 13:17:19Z lindig $ */
/* ./quest -seed 95910364 gcc.lua -n 1 -test gcc */

#include <stdarg.h>

#include <assert.h>

extern int printf (char *, ...);
static int errors = 0;
static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }
static double av1 = 76007.294281;
static
union dt1
{ double kv1[2]; union ct1 { double hv1; float iv1; int jv1; } lv1; }
xv1
=
    { { 86455.456094, 39308.277537 } };
static long int *yv1 = (long int *) 1794127324U;
static double zv1 = 22556.727648;
static int bav1 = 1161273109;
static
struct et1 { double mv1; int nv1; unsigned char ov1; } *bbv1 =
    (struct et1 *) 1004882322U;
static
struct gt1
{
    unsigned int rv1[0];
    struct ft1 { short int pv1; float qv1; } sv1;
    unsigned short int tv1[0];
}
bcv1
=
    { {  }, { 16423, 43708.710403 }, {  } };
static
unsigned short int (*bdv1)[1] =
    (unsigned short int (*)[1]) 1652729901U;
static
struct ht1 { double uv1; unsigned long long int vv1; long long int wv1; } bev1
=
    { 18892.960851, 934217018UL, 746657498L };
static struct it1 {  } bfv1 = {  };
static
union bt1
{ union at1 { double bv1; float cv1; } dv1; double ev1; double fv1; }
gv1
=
    { { 37442.137331 } };
static
double
callee_af1(
    union dt1 ap1,
    long int *bp1,
    double cp1,
    int dp1,
    struct et1 *ep1,
    struct gt1 fp1,
    unsigned short int (*gp1)[1],
    struct ht1 hp1,
    struct it1 ip1,
    ...
)
{
    va_list ap;
    typedef union bt1 ad1;
    ad1 bgv1;
    /* seed: 95910364 */
    va_start (ap, ip1);
    assert (xv1.kv1[1] ==  ap1.kv1[1]);
    assert (xv1.kv1[0] ==  ap1.kv1[0]);
    assert (yv1 ==  bp1);
    assert (zv1 ==  cp1);
    assert (bav1 ==  dp1);
    assert (bbv1 ==  ep1);
    assert (bcv1.sv1.pv1 ==  fp1.sv1.pv1);
    assert (bcv1.sv1.qv1 ==  fp1.sv1.qv1);
    assert (bdv1 ==  gp1);
    assert (bev1.uv1 ==  hp1.uv1);
    assert (bev1.vv1 ==  hp1.vv1);
    assert (bev1.wv1 ==  hp1.wv1);
    bgv1 = va_arg (ap, ad1);
    assert (gv1.dv1.bv1 ==  bgv1.dv1.bv1);
    va_end (ap);
    return av1;
}
static void caller_bf1(  )
{
    double bhv1;
    /* seed: 95910364 */
    bhv1
    =
    callee_af1 (xv1, yv1, zv1, bav1, bbv1, bcv1, bdv1, bev1, bfv1, gv1);
    assert (av1 ==  bhv1);
}
int main( int argc, char **argv ) { caller_bf1 (); return errors; }

/*
 * : tmp; /scratch/lindig/opt/intel/bin/icc  -o icc-02 icc-02.c 
 * : tmp; ./icc-02 
 * icc-02: icc-02.c:82: callee_af1: Assertion `gv1.dv1.bv1 ==
 * bgv1.dv1.bv1' failed.
 * Aborted
 * : tmp; /scratch/lindig/opt/intel/bin/icc -v
 * Version 8.1 
 * : tmp; uname -a
 * Linux jacobs 2.4.26-1-686 #1 Sat May 1 18:04:05 EST 2004 i686
 * GNU/Linux
 */

