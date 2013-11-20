/* $Id: gcc-3.3-00.c 3 2006-04-29 13:17:19Z lindig $ */
/* ./quest -test gcc -n 1 -seed -575334629 */

#include <stdarg.h>

#include <assert.h>

extern int printf (char *, ...);
static int errors = 0;
static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }
static unsigned short int av1 = 18961;
static
struct et1 { union dt1 { double iv1; } jv1; char kv1; } lv1 =
    { { 61419.451339 }, '\x59' };
static double mv1 = 18532.569061;
static
union ct1
{
    double *bv1;
    struct at1 { unsigned int cv1; unsigned int dv1; int ev1; } fv1;
    struct bt1 {  } gv1;
}
hv1
=
    { (double *) 2044420428U };
static unsigned short int callee_af1( struct et1 ap1, double bp1, ... )
{
    va_list ap;
    typedef union ct1 ad1;
    ad1 nv1;
    /* seed: -575334629 */
    va_start (ap, bp1);
    assert (lv1.jv1.iv1 ==  ap1.jv1.iv1);
    assert (lv1.kv1 ==  ap1.kv1);
    assert (mv1 ==  bp1);
    nv1 = va_arg (ap, ad1);
    assert (hv1.bv1 ==  nv1.bv1);
    va_end (ap);
    return av1;
}
static void caller_bf1(  )
{
    unsigned short int ov1;
    /* seed: -575334629 */
    ov1 = callee_af1 (lv1, mv1, hv1);
    assert (av1 ==  ov1);
}
int main( int argc, char **argv ) { caller_bf1 (); return errors; }

/*
bash-2.05b$ ./foo 
Assertion failed: EX, file foo.c, line 38
Abort
bash-2.05b$ gcc -v
Reading specs from /usr/freeware/lib/gcc-lib/mips-sgi-irix6.5/3.3/specs
Configured with: ../configure --prefix=/usr/freeware
--enable-version-specific-runtime-libs --disable-shared --enable-threads
--enable-haifa --enable-libgcj --disable-c-mbchar
Thread model: single
gcc version 3.3
*/
