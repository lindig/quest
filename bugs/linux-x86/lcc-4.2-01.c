/* $Id: lcc-4.2-01.c 3 2006-04-29 13:17:19Z lindig $ */
/* /scratch/lindig/src/quest/src/quest -test ansi */

/*
: tmp; ./lcc-x86-bug 
failed in lcc-x86-bug.c: 604
failed in lcc-x86-bug.c: 605
failed in lcc-x86-bug.c: 606
: tmp; /scratch/lindig/lcc/lcc -v
/scratch/lindig/lcc/lcc $Id: lcc-4.2-01.c 3 2006-04-29 13:17:19Z lindig $
*/

#include <stdarg.h>


extern int printf (char *, ...);

static int errors = 0;

static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }

static
struct bt20 { double av20; struct at20 { long long int bv20; } cv20; } dv20 =
    { 94961.962459, { 915003742L } };

static int hv20 = 2006869855;

static long int ev20 = 847424207L;

static double fv20 = 84553.111005;

static long int gv20 = 99168688L;

static struct bt20 callee_af20( int ap20, ... )
{
    va_list ap;
    long int iv20;
    double jv20;
    long int kv20;
    va_start (ap, ap20);
    if (hv20 !=  ap20) failed (__LINE__);
    iv20 = va_arg (ap, long int);
    jv20 = va_arg (ap, double);
    kv20 = va_arg (ap, long int);
    if (ev20 !=  iv20) failed (__LINE__);
    if (fv20 !=  jv20) failed (__LINE__);
    if (gv20 !=  kv20) failed (__LINE__);
    va_end (ap);
    return dv20;
}

static void caller_bf20(  )
{
    struct bt20 lv20;
    lv20 = callee_af20 (hv20, ev20, fv20, gv20);
    if (dv20.av20 !=  lv20.av20) failed (__LINE__);
    if (dv20.cv20.bv20 !=  lv20.cv20.bv20) failed (__LINE__);
}

static
struct bt19
{ float *av19; union at19 { double bv19; } cv19; unsigned long int *dv19; }
ev19
=
    {
        (float *) 340005275U,
        { 34467.479835 },
        (unsigned long int *) 4180836U
    };

static unsigned long int jv19 = 1156797203UL;

static float kv19 = 14978.804799;

static long int fv19 = 1425387825L;

static long long int gv19 = 252384649L;

static int hv19 = 1671962309;

static int iv19 = 1079890614;

static struct bt19 callee_af19( unsigned long int ap19, float bp19, ... )
{
    va_list ap;
    long int lv19;
    long long int mv19;
    int nv19;
    int ov19;
    va_start (ap, bp19);
    if (jv19 !=  ap19) failed (__LINE__);
    if (kv19 !=  bp19) failed (__LINE__);
    lv19 = va_arg (ap, long int);
    mv19 = va_arg (ap, long long int);
    nv19 = va_arg (ap, int);
    ov19 = va_arg (ap, int);
    if (fv19 !=  lv19) failed (__LINE__);
    if (gv19 !=  mv19) failed (__LINE__);
    if (hv19 !=  nv19) failed (__LINE__);
    if (iv19 !=  ov19) failed (__LINE__);
    va_end (ap);
    return ev19;
}

static void caller_bf19(  )
{
    struct bt19 pv19;
    pv19 = callee_af19 (jv19, kv19, fv19, gv19, hv19, iv19);
    if (ev19.av19 !=  pv19.av19) failed (__LINE__);
    if (ev19.cv19.bv19 !=  pv19.cv19.bv19) failed (__LINE__);
    if (ev19.dv19 !=  pv19.dv19) failed (__LINE__);
}

static long int av18 = 857748052L;

static
struct at18 { double *ev18; unsigned int fv18[1]; } gv18 =
    { (double *) 623820879U, { 1307094329U } };

static long long int bv18 = 435273107L;

static int cv18 = 50449195;

static long int dv18 = 692302641L;

static long int callee_af18( struct at18 ap18, ... )
{
    va_list ap;
    long long int hv18;
    int iv18;
    long int jv18;
    va_start (ap, ap18);
    if (gv18.ev18 !=  ap18.ev18) failed (__LINE__);
    if (gv18.fv18[0] !=  ap18.fv18[0]) failed (__LINE__);
    hv18 = va_arg (ap, long long int);
    iv18 = va_arg (ap, int);
    jv18 = va_arg (ap, long int);
    if (bv18 !=  hv18) failed (__LINE__);
    if (cv18 !=  iv18) failed (__LINE__);
    if (dv18 !=  jv18) failed (__LINE__);
    va_end (ap);
    return av18;
}

static void caller_bf18(  )
{
    long int kv18;
    kv18 = callee_af18 (gv18, bv18, cv18, dv18);
    if (av18 !=  kv18) failed (__LINE__);
}

static
union bt17
{
    long long int *av17;
    long long int bv17;
    union at17 { double cv17; double dv17; float ev17; } fv17;
}
gv17
=
    { (long long int *) 655520748U };

static double nv17 = 5041.853985;

static
union ct17 { float lv17; short int mv17; } *ov17 =
    (union ct17 *) 220948713U;

static double pv17[1] = { 80887.536935 };

static double *qv17 = (double *) 1912553110U;

static double hv17 = 22972.027087;

static long long int iv17 = 1027409344L;

static double jv17 = 67064.823776;

static double *kv17 = (double *) 1804014008U;

static
union bt17
callee_af17(
    double ap17,
    union ct17 *bp17,
    double cp17[1],
    double *dp17,
    ...
)
{
    va_list ap;
    double rv17;
    long long int sv17;
    double tv17;
    double *uv17;
    va_start (ap, dp17);
    if (nv17 !=  ap17) failed (__LINE__);
    if (ov17 !=  bp17) failed (__LINE__);
    if (pv17[0] !=  cp17[0]) failed (__LINE__);
    if (qv17 !=  dp17) failed (__LINE__);
    rv17 = va_arg (ap, double);
    sv17 = va_arg (ap, long long int);
    tv17 = va_arg (ap, double);
    uv17 = va_arg (ap, double *);
    if (hv17 !=  rv17) failed (__LINE__);
    if (iv17 !=  sv17) failed (__LINE__);
    if (jv17 !=  tv17) failed (__LINE__);
    if (kv17 !=  uv17) failed (__LINE__);
    va_end (ap);
    return gv17;
}

static void caller_bf17(  )
{
    union bt17 vv17;
    vv17 = callee_af17 (nv17, ov17, pv17, qv17, hv17, iv17, jv17, kv17);
    if (gv17.av17 !=  vv17.av17) failed (__LINE__);
}

static
struct at16 { unsigned short int *av16; } bv16 =
    { (unsigned short int *) 2123487874U };

static struct ct16 { float *gv16; } mv16 = { (float *) 1943667081U };

static
struct et16
{
    union dt16 { float hv16; unsigned long int iv16; } jv16;
    double *kv16;
    short int lv16;
}
nv16
=
    { { 490.550381 }, (double *) 991575778U, 15580 };

static union bt16 { float cv16; } *dv16 = (union bt16 *) 151516471U;

static long long int ev16 = 763103077L;

static int fv16 = 1832408938;

static struct at16 callee_af16( struct ct16 ap16, struct et16 bp16, ... )
{
    va_list ap;
    union bt16 *ov16;
    long long int pv16;
    int qv16;
    va_start (ap, bp16);
    if (mv16.gv16 !=  ap16.gv16) failed (__LINE__);
    if (nv16.jv16.hv16 !=  bp16.jv16.hv16) failed (__LINE__);
    if (nv16.kv16 !=  bp16.kv16) failed (__LINE__);
    if (nv16.lv16 !=  bp16.lv16) failed (__LINE__);
    ov16 = va_arg (ap, union bt16 *);
    pv16 = va_arg (ap, long long int);
    qv16 = va_arg (ap, int);
    if (dv16 !=  ov16) failed (__LINE__);
    if (ev16 !=  pv16) failed (__LINE__);
    if (fv16 !=  qv16) failed (__LINE__);
    va_end (ap);
    return bv16;
}

static void caller_bf16(  )
{
    struct at16 rv16;
    rv16 = callee_af16 (mv16, nv16, dv16, ev16, fv16);
    if (bv16.av16 !=  rv16.av16) failed (__LINE__);
}

static double av15 = 45184.245493;

static unsigned long int dv15 = 1168717854UL;

static unsigned long int **ev15 = (unsigned long int **) 2075340080U;

static double fv15 = 45055.041098;

static long long int bv15 = 781619782L;

static long long int cv15 = 637100661L;

static
double
callee_af15(
    unsigned long int ap15,
    unsigned long int **bp15,
    double cp15,
    ...
)
{
    va_list ap;
    long long int gv15;
    long long int hv15;
    va_start (ap, cp15);
    if (dv15 !=  ap15) failed (__LINE__);
    if (ev15 !=  bp15) failed (__LINE__);
    if (fv15 !=  cp15) failed (__LINE__);
    gv15 = va_arg (ap, long long int);
    hv15 = va_arg (ap, long long int);
    if (bv15 !=  gv15) failed (__LINE__);
    if (cv15 !=  hv15) failed (__LINE__);
    va_end (ap);
    return av15;
}

static void caller_bf15(  )
{
    double iv15;
    iv15 = callee_af15 (dv15, ev15, fv15, bv15, cv15);
    if (av15 !=  iv15) failed (__LINE__);
}

static
union bt14
{
    double av14;
    union at14 { long int bv14; long long int cv14; } dv14;
    unsigned char ev14;
}
fv14
=
    { 26065.363316 };

static float kv14 = 94491.928849;

static double gv14 = 30861.510069;

static double hv14 = 95475.673560;

static double iv14 = 77635.906099;

static int jv14 = 1193218804;

static union bt14 callee_af14( float ap14, ... )
{
    va_list ap;
    double lv14;
    double mv14;
    double nv14;
    int ov14;
    va_start (ap, ap14);
    if (kv14 !=  ap14) failed (__LINE__);
    lv14 = va_arg (ap, double);
    mv14 = va_arg (ap, double);
    nv14 = va_arg (ap, double);
    ov14 = va_arg (ap, int);
    if (gv14 !=  lv14) failed (__LINE__);
    if (hv14 !=  mv14) failed (__LINE__);
    if (iv14 !=  nv14) failed (__LINE__);
    if (jv14 !=  ov14) failed (__LINE__);
    va_end (ap);
    return fv14;
}

static void caller_bf14(  )
{
    union bt14 pv14;
    pv14 = callee_af14 (kv14, gv14, hv14, iv14, jv14);
    if (fv14.av14 !=  pv14.av14) failed (__LINE__);
}

static
union at13 { long int av13; unsigned int bv13; float cv13; } *dv13 =
    (union at13 *) 965489950U;

static char fv13 = '\x3a';

static long int ev13 = 1575486899L;

static union at13 * callee_af13( char ap13, ... )
{
    va_list ap;
    long int gv13;
    va_start (ap, ap13);
    if (fv13 !=  ap13) failed (__LINE__);
    gv13 = va_arg (ap, long int);
    if (ev13 !=  gv13) failed (__LINE__);
    va_end (ap);
    return dv13;
}

static void caller_bf13(  )
{
    union at13 *hv13;
    hv13 = callee_af13 (fv13, ev13); if (dv13 !=  hv13) failed (__LINE__);
}

static unsigned short int *av12 = (unsigned short int *) 2064398799U;

static
struct bt12 { union at12 { float dv12; } ev12; unsigned int fv12[1]; } gv12 =
    { { 35547.761417 }, { 1648265964U } };

static double bv12 = 28996.020278;

static long long int cv12 = 1949857381L;

static unsigned short int * callee_af12( struct bt12 ap12, ... )
{
    va_list ap;
    double hv12;
    long long int iv12;
    va_start (ap, ap12);
    if (gv12.ev12.dv12 !=  ap12.ev12.dv12) failed (__LINE__);
    if (gv12.fv12[0] !=  ap12.fv12[0]) failed (__LINE__);
    hv12 = va_arg (ap, double);
    iv12 = va_arg (ap, long long int);
    if (bv12 !=  hv12) failed (__LINE__);
    if (cv12 !=  iv12) failed (__LINE__);
    va_end (ap);
    return av12;
}

static void caller_bf12(  )
{
    unsigned short int *jv12;
    jv12 = callee_af12 (gv12, bv12, cv12);
    if (av12 !=  jv12) failed (__LINE__);
}

static struct at11 { float *av11; } bv11 = { (float *) 1278529978U };

static float kv11 = 53905.406835;

static unsigned long long int *lv11 = (unsigned long long int *) 476895598U;

static unsigned long int mv11 = 467428557UL;

static
union ct11 { unsigned short int hv11; double iv11; float jv11; } nv11[1] =
    { { 21157 } };

static
struct bt11 { float cv11[1]; int dv11; unsigned int ev11; } fv11 =
    { { 59550.252285 }, 1420267274, 1694666723U };

static double gv11 = 47826.107546;

static
struct at11
callee_af11(
    float ap11,
    unsigned long long int *bp11,
    unsigned long int cp11,
    union ct11 dp11[1],
    ...
)
{
    va_list ap;
    struct bt11 ov11;
    double pv11;
    va_start (ap, dp11);
    if (kv11 !=  ap11) failed (__LINE__);
    if (lv11 !=  bp11) failed (__LINE__);
    if (mv11 !=  cp11) failed (__LINE__);
    if (nv11[0].hv11 !=  dp11[0].hv11) failed (__LINE__);
    ov11 = va_arg (ap, struct bt11);
    pv11 = va_arg (ap, double);
    if (fv11.cv11[0] !=  ov11.cv11[0]) failed (__LINE__);
    if (fv11.dv11 !=  ov11.dv11) failed (__LINE__);
    if (fv11.ev11 !=  ov11.ev11) failed (__LINE__);
    if (gv11 !=  pv11) failed (__LINE__);
    va_end (ap);
    return bv11;
}

static void caller_bf11(  )
{
    struct at11 qv11;
    qv11 = callee_af11 (kv11, lv11, mv11, nv11, fv11, gv11);
    if (bv11.av11 !=  qv11.av11) failed (__LINE__);
}

static double **av10 = (double **) 578933519U;

static
struct bt10 { int *ev10; short int fv10[1]; } jv10 =
    { (int *) 1485647290U, { 3981 } };

static unsigned short int kv10 = 41751;

static
struct dt10 { int *gv10; struct ct10 { double hv10; } iv10; } lv10 =
    { (int *) 1664053307U, { 84872.442939 } };

static unsigned long long int *mv10 = (unsigned long long int *) 1622474763U;

static long long int cv10 = 847312547L;

static union at10 { char *bv10; } dv10 = { (char *) 1561780656U };

static
double **
callee_af10(
    struct bt10 ap10,
    unsigned short int bp10,
    struct dt10 cp10,
    unsigned long long int *dp10,
    ...
)
{
    va_list ap;
    long long int nv10;
    union at10 ov10;
    va_start (ap, dp10);
    if (jv10.ev10 !=  ap10.ev10) failed (__LINE__);
    if (jv10.fv10[0] !=  ap10.fv10[0]) failed (__LINE__);
    if (kv10 !=  bp10) failed (__LINE__);
    if (lv10.gv10 !=  cp10.gv10) failed (__LINE__);
    if (lv10.iv10.hv10 !=  cp10.iv10.hv10) failed (__LINE__);
    if (mv10 !=  dp10) failed (__LINE__);
    nv10 = va_arg (ap, long long int);
    ov10 = va_arg (ap, union at10);
    if (cv10 !=  nv10) failed (__LINE__);
    if (dv10.bv10 !=  ov10.bv10) failed (__LINE__);
    va_end (ap);
    return av10;
}

static void caller_bf10(  )
{
    double **pv10;
    pv10 = callee_af10 (jv10, kv10, lv10, mv10, cv10, dv10);
    if (av10 !=  pv10) failed (__LINE__);
}

static float av9 = 77508.955604;

static unsigned short int *gv9 = (unsigned short int *) 504730594U;

static unsigned char hv9 = '\x51';

static
union bt9
{ double cv9; struct at9 { unsigned int dv9; } ev9; double fv9[2]; }
iv9
=
    { 99121.526558 };

static unsigned short int jv9[1] = { 24967 };

static double bv9 = 79761.340390;

static
float
callee_af9(
    unsigned short int *ap9,
    unsigned char bp9,
    union bt9 cp9,
    unsigned short int dp9[1],
    ...
)
{
    va_list ap;
    double kv9;
    va_start (ap, dp9);
    if (gv9 !=  ap9) failed (__LINE__);
    if (hv9 !=  bp9) failed (__LINE__);
    if (iv9.cv9 !=  cp9.cv9) failed (__LINE__);
    if (jv9[0] !=  dp9[0]) failed (__LINE__);
    kv9 = va_arg (ap, double);
    if (bv9 !=  kv9) failed (__LINE__);
    va_end (ap);
    return av9;
}

static void caller_bf9(  )
{
    float lv9;
    lv9 = callee_af9 (gv9, hv9, iv9, jv9, bv9);
    if (av9 !=  lv9) failed (__LINE__);
}

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

static double av7 = 10690.340898;

static
struct at7 { long long int *cv7; } fv7 =
    { (long long int *) 607919576U };

static
struct bt7 { float dv7; float ev7[1]; } gv7 =
    { 37312.167144, { 27464.987242 } };

static long long int bv7 = 521980166L;

static double callee_af7( struct at7 ap7, struct bt7 bp7, ... )
{
    va_list ap;
    long long int hv7;
    va_start (ap, bp7);
    if (fv7.cv7 !=  ap7.cv7) failed (__LINE__);
    if (gv7.dv7 !=  bp7.dv7) failed (__LINE__);
    if (gv7.ev7[0] !=  bp7.ev7[0]) failed (__LINE__);
    hv7 = va_arg (ap, long long int);
    if (bv7 !=  hv7) failed (__LINE__);
    va_end (ap);
    return av7;
}

static void caller_bf7(  )
{
    double iv7;
    iv7 = callee_af7 (fv7, gv7, bv7); if (av7 !=  iv7) failed (__LINE__);
}

static
struct at6 { float av6; unsigned short int bv6; } *cv6 =
    (struct at6 *) 487895826U;

static char jv6 = '\x11';

static
union bt6 { short int fv6; char gv6; float hv6; } kv6[1] =
    { { 19051 } };

static double *lv6[1] = { (double *) 1062221962U };

static union ct6 { unsigned long int iv6[1]; } mv6 = { { 496691885UL } };

static long int dv6 = 558716085L;

static double *ev6 = (double *) 758547388U;

static
struct at6 *
callee_af6( char ap6, union bt6 bp6[1], double *cp6[1], union ct6 dp6, ... )
{
    va_list ap;
    long int nv6;
    double *ov6;
    va_start (ap, dp6);
    if (jv6 !=  ap6) failed (__LINE__);
    if (kv6[0].fv6 !=  bp6[0].fv6) failed (__LINE__);
    if (lv6[0] !=  cp6[0]) failed (__LINE__);
    if (mv6.iv6[0] !=  dp6.iv6[0]) failed (__LINE__);
    nv6 = va_arg (ap, long int);
    ov6 = va_arg (ap, double *);
    if (dv6 !=  nv6) failed (__LINE__);
    if (ev6 !=  ov6) failed (__LINE__);
    va_end (ap);
    return cv6;
}

static void caller_bf6(  )
{
    struct at6 *pv6;
    pv6 = callee_af6 (jv6, kv6, lv6, mv6, dv6, ev6);
    if (cv6 !=  pv6) failed (__LINE__);
}

static double *av5 = (double *) 831502527U;

static double cv5 = 89397.176424;

static unsigned short int dv5 = 47419;

static long int bv5 = 824339327L;

static double * callee_af5( double ap5, unsigned short int bp5, ... )
{
    va_list ap;
    long int ev5;
    va_start (ap, bp5);
    if (cv5 !=  ap5) failed (__LINE__);
    if (dv5 !=  bp5) failed (__LINE__);
    ev5 = va_arg (ap, long int);
    if (bv5 !=  ev5) failed (__LINE__);
    va_end (ap);
    return av5;
}

static void caller_bf5(  )
{
    double *fv5;
    fv5 = callee_af5 (cv5, dv5, bv5); if (av5 !=  fv5) failed (__LINE__);
}

static struct at4 { double av4; } bv4 = { 68358.905795 };

static
struct ct4
{ long long int *iv4; unsigned long int jv4[1]; unsigned char *kv4; }
sv4
=
    {
        (long long int *) 449953478U,
        { 2007992816UL },
        (unsigned char *) 1989711874U
    };

static
union ft4
{
    float lv4;
    struct dt4 { char mv4; unsigned char nv4; int ov4; } pv4;
    struct et4 { double qv4; } rv4;
}
tv4
=
    { 98495.459005 };

static double fv4 = 6104.777747;

static long long int gv4 = 1133951346L;

static
struct bt4 { unsigned long int *cv4; float dv4[2]; int ev4; } hv4 =
    {
        (unsigned long int *) 695155970U,
        { 99464.984567, 26627.938037 },
        647888731
    };

static struct at4 callee_af4( struct ct4 ap4, union ft4 bp4, ... )
{
    va_list ap;
    double uv4;
    long long int vv4;
    struct bt4 wv4;
    va_start (ap, bp4);
    if (sv4.iv4 !=  ap4.iv4) failed (__LINE__);
    if (sv4.jv4[0] !=  ap4.jv4[0]) failed (__LINE__);
    if (sv4.kv4 !=  ap4.kv4) failed (__LINE__);
    if (tv4.lv4 !=  bp4.lv4) failed (__LINE__);
    uv4 = va_arg (ap, double);
    vv4 = va_arg (ap, long long int);
    wv4 = va_arg (ap, struct bt4);
    if (fv4 !=  uv4) failed (__LINE__);
    if (gv4 !=  vv4) failed (__LINE__);
    if (hv4.cv4 !=  wv4.cv4) failed (__LINE__);
    if (hv4.dv4[1] !=  wv4.dv4[1]) failed (__LINE__);
    if (hv4.dv4[0] !=  wv4.dv4[0]) failed (__LINE__);
    if (hv4.ev4 !=  wv4.ev4) failed (__LINE__);
    va_end (ap);
    return bv4;
}

static void caller_bf4(  )
{
    struct at4 xv4;
    xv4 = callee_af4 (sv4, tv4, fv4, gv4, hv4);
    if (bv4.av4 !=  xv4.av4) failed (__LINE__);
}

static struct at3 { double *av3; } bv3 = { (double *) 1765550684U };

static union dt3 { float jv3[1]; double kv3; } lv3 = { { 17598.791003 } };

static unsigned short int mv3 = 63472;

static
union ct3
{ int cv3[2]; union bt3 { unsigned short int dv3; } ev3; float *fv3; }
gv3
=
    { { 771656117, 1736314204 } };

static long long int **hv3 = (long long int **) 797646772U;

static double iv3 = 69042.368914;

static struct at3 callee_af3( union dt3 ap3, unsigned short int bp3, ... )
{
    va_list ap;
    union ct3 nv3;
    long long int **ov3;
    double pv3;
    va_start (ap, bp3);
    if (lv3.jv3[0] !=  ap3.jv3[0]) failed (__LINE__);
    if (mv3 !=  bp3) failed (__LINE__);
    nv3 = va_arg (ap, union ct3);
    ov3 = va_arg (ap, long long int **);
    pv3 = va_arg (ap, double);
    if (gv3.cv3[1] !=  nv3.cv3[1]) failed (__LINE__);
    if (gv3.cv3[0] !=  nv3.cv3[0]) failed (__LINE__);
    if (hv3 !=  ov3) failed (__LINE__);
    if (iv3 !=  pv3) failed (__LINE__);
    va_end (ap);
    return bv3;
}

static void caller_bf3(  )
{
    struct at3 qv3;
    qv3 = callee_af3 (lv3, mv3, gv3, hv3, iv3);
    if (bv3.av3 !=  qv3.av3) failed (__LINE__);
}

static union at2 { float *av2; float bv2; } cv2 = { (float *) 260954194U };

static float fv2 = 15982.974038;

static float gv2 = 58071.556862;

static double dv2 = 70574.193956;

static int ev2 = 1120153538;

static union at2 callee_af2( float ap2, float bp2, ... )
{
    va_list ap;
    double hv2;
    int iv2;
    va_start (ap, bp2);
    if (fv2 !=  ap2) failed (__LINE__);
    if (gv2 !=  bp2) failed (__LINE__);
    hv2 = va_arg (ap, double);
    iv2 = va_arg (ap, int);
    if (dv2 !=  hv2) failed (__LINE__);
    if (ev2 !=  iv2) failed (__LINE__);
    va_end (ap);
    return cv2;
}

static void caller_bf2(  )
{
    union at2 jv2;
    jv2 = callee_af2 (fv2, gv2, dv2, ev2);
    if (cv2.av2 !=  jv2.av2) failed (__LINE__);
}

static float av1 = 61812.417428;

static
struct bt1 { struct at1 { unsigned int cv1; int dv1; } ev1; double fv1; } gv1
=
    { { 1608905510U, 715599644 }, 18525.504566 };

static short int hv1 = 17253;

static double *bv1 = (double *) 835547177U;

static float callee_af1( struct bt1 ap1, short int bp1, ... )
{
    va_list ap;
    double *iv1;
    va_start (ap, bp1);
    if (gv1.ev1.cv1 !=  ap1.ev1.cv1) failed (__LINE__);
    if (gv1.ev1.dv1 !=  ap1.ev1.dv1) failed (__LINE__);
    if (gv1.fv1 !=  ap1.fv1) failed (__LINE__);
    if (hv1 !=  bp1) failed (__LINE__);
    iv1 = va_arg (ap, double *);
    if (bv1 !=  iv1) failed (__LINE__);
    va_end (ap);
    return av1;
}

static void caller_bf1(  )
{
    float jv1;
    jv1 = callee_af1 (gv1, hv1, bv1); if (av1 !=  jv1) failed (__LINE__);
}

int main( int argc, char **argv )
{
    caller_bf20 ();
    caller_bf19 ();
    caller_bf18 ();
    caller_bf17 ();
    caller_bf16 ();
    caller_bf15 ();
    caller_bf14 ();
    caller_bf13 ();
    caller_bf12 ();
    caller_bf11 ();
    caller_bf10 ();
    caller_bf9 ();
    caller_bf8 ();
    caller_bf7 ();
    caller_bf6 ();
    caller_bf5 ();
    caller_bf4 ();
    caller_bf3 ();
    caller_bf2 ();
    caller_bf1 ();
    return errors;
}
