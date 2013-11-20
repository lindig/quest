/* Christian Lindig <lindig@cs.uni-sb.de> Wed Feb  4 17:19:40 CET 2004
 * 
 * This code causes an internal compiler error on GCC 2.95.4 on x86 when
 * compiling with -O: gcc -O gcc-bug.c
 *
 * gcc-bug.c: In function `x_001_fun_2':
 * gcc-bug.c:28: fixed or forbidden register 0 (ax) was spilled for class AREG.
 * gcc-bug.c:28: This may be due to a compiler bug or to impossible asm
 * gcc-bug.c:28: statements or clauses.
 * gcc-bug.c:28: Internal compiler error:
 * gcc-bug.c:28: This is the instruction:
 * (insn 19 17 20 (parallel[ 
 *             (set (cc0)
 *                 (compare:CCFPEQ (reg:DF 8 %st(0))
 *                     (reg/v:DF 9 %st(1))))
 *             (clobber (scratch:HI))
 *         ] ) 28 {*cmpsf_cc_1-1} (insn_list 4 (insn_list 17 (nil)))
 *     (expr_list:REG_DEAD (reg:DF 8 %st(0))
 *         (expr_list:REG_DEAD (reg/v:DF 9 %st(1))
 *             (expr_list:REG_UNUSED (scratch:HI)
 *                 (nil)))))
 */ 

#include <stdio.h>

static int errors = 0;
double x_001_var_2 = 83769.642213;
double x_001_var_3 = 85338.019773;
union x_001_type_2 { float x_001_var_1; } x_001_var_4 = { 72872.946264 };
union x_001_type_1 {  } x_001_var_5 = {  };
double x_001_var_6 = 26485.663005;
static
void
x_001_fun_2(
    double a1,
    double a2,
    union x_001_type_2 a3,
    union x_001_type_1 a4,
    double a5
)
{
    if (x_001_var_2 !=  a1)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_001_var_3 !=  a2)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_001_var_4.x_001_var_1 !=  a3.x_001_var_1)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
    if (x_001_var_6 !=  a5)
    { printf ("failed in %s: %d\n", __FILE__, __LINE__); errors++; }
}
static void x_001_fun_1(  )
{
    x_001_fun_2
        (x_001_var_2,
        x_001_var_3,
        x_001_var_4,
        x_001_var_5,
        x_001_var_6);
}

int main( int argc, char **argv )
{
    x_001_fun_1 ();
    return errors; 
}    
