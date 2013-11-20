/* gcc 3.2.3 -O3 produces a bug on this file:
 * Linux jacobs 2.4.20-3-686 #1 Sat Jun 7 22:34:55 EST 2003 i686 GNU/Linux
 * gcc-3.2 (GCC) 3.2.3 20030415 (Debian prerelease)
 * 
 * bugs/gcc-3.2.2.c: In function `main':
 * bugs/gcc-3.2.2.c:253: unable to find a register to spill in class `AREG'
 * bugs/gcc-3.2.2.c:253: this is the insn:
 * (jump_insn 39 31 474 (parallel[ 
 *             (set (pc)
 *                 (if_then_else (eq (reg/v:SF 8 st(0) [63])
 *                         (reg/v:SF 8 st(0) [63]))
 *                     (label_ref 62)
 *                     (pc)))
 *             (clobber (reg:CCFP 18 fpsr))
 *             (clobber (reg:CCFP 17 flags))
 *             (clobber (scratch:HI))
 *         ] ) 500 {*fp_jcc_5} (insn_list 27 (nil))
 *     (expr_list:REG_DEAD (reg/v:SF 8 st(0) [63])
 *         (expr_list:REG_UNUSED (reg:CCFP 18 fpsr)
 *             (expr_list:REG_UNUSED (reg:CCFP 17 flags)
 *                 (expr_list:REG_UNUSED (scratch:HI)
 *                     (expr_list:REG_BR_PROB (const_int 7000 [0x1b58])
 *                         (nil)))))))
 * bugs/gcc-3.2.2.c:253: confused by earlier errors, bailing out
 */

#include <stdio.h>

static int errors = 0;
float x_001_var_3 = 84914.071378;
struct x_001_type_2 { unsigned long int x_001_var_2; } *(*x_001_var_4)[1] =
    (struct x_001_type_2 *(*)[1]) 2055570138U;
union x_001_type_1 { unsigned int x_001_var_1; } x_001_var_5 =
    { 592548498U };
unsigned short int x_001_var_6[1] = { 63800 };
static
void
x_001_fun_2(
    float a1,
    struct x_001_type_2 *(*a2)[1],
    union x_001_type_1 a3,
    unsigned short int a4[1]
)
{
    if (x_001_var_3 !=  a1)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_001_var_4 !=  a2)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_001_var_5.x_001_var_1 !=  a3.x_001_var_1)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_001_var_6[0] !=  a4[0])
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
}
static void x_001_fun_1(  )
{ x_001_fun_2 (x_001_var_3, x_001_var_4, x_001_var_5, x_001_var_6); }
double x_002_var_11[0] = {  };
union x_002_type_7
{
    struct x_002_type_6
    {
        struct x_002_type_5
        { unsigned short int x_002_var_8; double x_002_var_7; }
        x_002_var_9;
        float x_002_var_6[1];
        union x_002_type_4
        { float x_002_var_4; unsigned short int x_002_var_3; }
        x_002_var_5;
    }
    x_002_var_10[1];
}
x_002_var_12
=
    { { { { 40087, 31326.630162 }, { 61253.497299 }, { 18578.365676 } } } };
union x_002_type_3 {  } x_002_var_13 = {  };
char *x_002_var_14 = (char *) 94711912U;
struct x_002_type_2
{ double x_002_var_2; float (**x_002_var_1)[1]; }
x_002_var_15
=
    { 92101.432155, (float (**)[1]) 1026256468U };
union x_002_type_1 {  } x_002_var_16 = {  };
static
void
x_002_fun_2(
    double a1[0],
    union x_002_type_7 a2,
    union x_002_type_3 a3,
    char *a4,
    struct x_002_type_2 a5,
    union x_002_type_1 a6
)
{
    if (x_002_var_12.x_002_var_10[0].x_002_var_9.x_002_var_8 !=
         a2.x_002_var_10[0].x_002_var_9.x_002_var_8)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_002_var_12.x_002_var_10[0].x_002_var_9.x_002_var_7 !=
         a2.x_002_var_10[0].x_002_var_9.x_002_var_7)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_002_var_12.x_002_var_10[0].x_002_var_6[0] !=
         a2.x_002_var_10[0].x_002_var_6[0])
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_002_var_12.x_002_var_10[0].x_002_var_5.x_002_var_4 !=
         a2.x_002_var_10[0].x_002_var_5.x_002_var_4)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_002_var_14 !=  a4)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_002_var_15.x_002_var_2 !=  a5.x_002_var_2)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_002_var_15.x_002_var_1 !=  a5.x_002_var_1)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
}
static void x_002_fun_1(  )
{
    x_002_fun_2
        (x_002_var_11,
        x_002_var_12,
        x_002_var_13,
        x_002_var_14,
        x_002_var_15,
        x_002_var_16);
}
char x_003_var_12 = '\x26';
double x_003_var_13[1] = { 48911.385537 };
union x_003_type_6
{
    union x_003_type_5
    {
        union x_003_type_4
        { double x_003_var_9; float x_003_var_8; }
        x_003_var_10;
        struct x_003_type_3
        { float x_003_var_6; float x_003_var_5; }
        x_003_var_7;
        unsigned short int x_003_var_4[1];
    }
    *x_003_var_11;
    unsigned int x_003_var_3;
    union x_003_type_2 { struct x_003_type_1 {  } x_003_var_1; } x_003_var_2;
}
x_003_var_14
=
    { (union x_003_type_5 *) 1259415576U };
unsigned char x_003_var_15 = '\x31';
static
void
x_003_fun_2( char a1, double a2[1], union x_003_type_6 a3, unsigned char a4 )
{
    if (x_003_var_12 !=  a1)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_003_var_13[0] !=  a2[0])
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_003_var_14.x_003_var_11 !=  a3.x_003_var_11)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_003_var_15 !=  a4)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
}
static void x_003_fun_1(  )
{ x_003_fun_2 (x_003_var_12, x_003_var_13, x_003_var_14, x_003_var_15); }
double x_004_var_11 = 86871.635830;
char x_004_var_12 = '\x52';
struct x_004_type_6 { unsigned char (*x_004_var_10)[0]; } x_004_var_13[1] =
    { { (unsigned char (*)[0]) 78681456U } };
union x_004_type_5
{
    struct x_004_type_4
    {
        union x_004_type_3
        { char x_004_var_7; unsigned long int x_004_var_6; }
        x_004_var_8;
        unsigned char *x_004_var_5;
        float *x_004_var_4;
    }
    x_004_var_9;
    union x_004_type_2 {  } x_004_var_3;
}
x_004_var_14[1]
=
    {
        {
            {
                { '\x3a' },
                (unsigned char *) 636353578U,
                (float *) 1607689224U
            }
        }
    };
short int x_004_var_15 = 9686;
struct x_004_type_1 { float x_004_var_2; char x_004_var_1; } x_004_var_16[2]
=
    { { 59793.886538, '\x4f' }, { 43826.628681, '\x75' } };
static
void
x_004_fun_2(
    double a1,
    char a2,
    struct x_004_type_6 a3[1],
    union x_004_type_5 a4[1],
    short int a5,
    struct x_004_type_1 a6[2]
)
{
    if (x_004_var_11 !=  a1)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_12 !=  a2)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_13[0].x_004_var_10 !=  a3[0].x_004_var_10)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_14[0].x_004_var_9.x_004_var_8.x_004_var_7 !=
         a4[0].x_004_var_9.x_004_var_8.x_004_var_7)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_14[0].x_004_var_9.x_004_var_5 !=
         a4[0].x_004_var_9.x_004_var_5)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_14[0].x_004_var_9.x_004_var_4 !=
         a4[0].x_004_var_9.x_004_var_4)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_15 !=  a5)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_16[1].x_004_var_2 !=  a6[1].x_004_var_2)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_16[0].x_004_var_2 !=  a6[0].x_004_var_2)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_16[1].x_004_var_1 !=  a6[1].x_004_var_1)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_004_var_16[0].x_004_var_1 !=  a6[0].x_004_var_1)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
}
static void x_004_fun_1(  )
{
    x_004_fun_2
        (x_004_var_11,
        x_004_var_12,
        x_004_var_13,
        x_004_var_14,
        x_004_var_15,
        x_004_var_16);
}
union x_005_type_4
{
    union x_005_type_3
    { double *x_005_var_4; double *x_005_var_3[1]; }
    x_005_var_5;
    union x_005_type_2 {  } x_005_var_2;
    float **x_005_var_1;
}
x_005_var_6
=
    { { (double *) 1359201249U } };
struct x_005_type_1 {  } x_005_var_7 = {  };
short int **x_005_var_8 = (short int **) 395538236U;
long int x_005_var_9 = 1075942156L;
static
void
x_005_fun_2(
    union x_005_type_4 a1,
    struct x_005_type_1 a2,
    short int **a3,
    long int a4
)
{
    if (x_005_var_6.x_005_var_5.x_005_var_4 !=  a1.x_005_var_5.x_005_var_4)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_005_var_8 !=  a3)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_005_var_9 !=  a4)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
}
static void x_005_fun_1(  )
{ x_005_fun_2 (x_005_var_6, x_005_var_7, x_005_var_8, x_005_var_9); }
int main( int argc, char **argv )
{
    x_001_fun_1 ();
    x_002_fun_1 ();
    x_003_fun_1 ();
    x_004_fun_1 ();
    x_005_fun_1 ();
    return errors;
}
