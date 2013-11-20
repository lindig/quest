/* $Id: gcc-3.3-00.c 3 2006-04-29 13:17:19Z lindig $ */
/* ./quest -lua quest.lua -test demo */

/*
Thread model: posix
gcc version 3.3 20030304 (Apple Computer, Inc. build 1495)

: macosx-ppc; gcc -o foo gcc-3.3-00.c 
: macosx-ppc; ./foo 
failed in gcc-3.3-00.c: 136
*/

#include <stdarg.h>


extern int printf (char *, ...);

static int errors = 0;

static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }

static unsigned short int av20 = 31241;

static float iv20 = 78683.394614;

static unsigned char *jv20[1] = { (unsigned char *) 1243725565U };

static
union ct20
{
    short int cv20[1];
    struct at20 { char dv20; float ev20; } fv20;
    struct bt20 { double gv20; } hv20;
}
kv20
=
    { { 29944 } };

static int bv20 = 1502175447;

static
unsigned short int
callee_af20( float ap20, unsigned char *bp20[1], union ct20 cp20, ... )
{
    va_list ap;
    int lv20;
    va_start (ap, cp20);
    if (iv20 !=  ap20) failed (__LINE__);
    if (jv20[0] !=  bp20[0]) failed (__LINE__);
    if (kv20.cv20[0] !=  cp20.cv20[0]) failed (__LINE__);
    lv20 = va_arg (ap, int);
    if (lv20 !=  bv20) failed (__LINE__);
    va_end (ap);
    return av20;
}

static void caller_bf20(  )
{
    unsigned short int mv20;
    mv20 = callee_af20 (iv20, jv20, kv20, bv20);
    if (av20 !=  mv20) failed (__LINE__);
}

static union at19 { double av19; } bv19 = { 3644.105538 };

static double pv19 = 76436.297161;

static double qv19 = 35673.341060;

static int mv19 = 1652571554;

static int nv19 = 2112898276;

static
struct et19
{
    union bt19 { float cv19; double dv19; unsigned long int ev19; } fv19;
    union ct19 { float gv19; } hv19;
    struct dt19 { double iv19; long long int jv19; float kv19; } lv19;
}
ov19
=
    {
        { 38617.934170 },
        { 58200.006766 },
        { 42960.392534, 1633187772L, 31470.522893 }
    };

static union at19 callee_af19( double ap19, double bp19, ... )
{
    va_list ap;
    int rv19;
    int sv19;
    struct et19 tv19;
    va_start (ap, bp19);
    if (pv19 !=  ap19) failed (__LINE__);
    if (qv19 !=  bp19) failed (__LINE__);
    rv19 = va_arg (ap, int);
    sv19 = va_arg (ap, int);
    tv19 = va_arg (ap, struct et19);
    if (rv19 !=  mv19) failed (__LINE__);
    if (sv19 !=  nv19) failed (__LINE__);
    if (tv19.fv19.cv19 !=  ov19.fv19.cv19) failed (__LINE__);
    if (tv19.hv19.gv19 !=  ov19.hv19.gv19) failed (__LINE__);
    if (tv19.lv19.iv19 !=  ov19.lv19.iv19) failed (__LINE__);
    if (tv19.lv19.jv19 !=  ov19.lv19.jv19) failed (__LINE__);
    if (tv19.lv19.kv19 !=  ov19.lv19.kv19) failed (__LINE__);
    va_end (ap);
    return bv19;
}

static void caller_bf19(  )
{
    union at19 uv19;
    uv19 = callee_af19 (pv19, qv19, mv19, nv19, ov19);
    if (bv19.av19 !=  uv19.av19) failed (__LINE__);
}

static
union at18 { char av18; double bv18; } *cv18 =
    (union at18 *) 1424983810U;

static
struct ct18 { char gv18; unsigned short int hv18[2]; } iv18 =
    { '\x50', { 35400, 16427 } };

static double ev18 = 8796.964971;

static struct bt18 { double *dv18; } fv18 = { (double *) 522886379U };

static union at18 * callee_af18( struct ct18 ap18, ... )
{
    va_list ap;
    double jv18;
    struct bt18 kv18;
    va_start (ap, ap18);
    if (iv18.gv18 !=  ap18.gv18) failed (__LINE__);
    if (iv18.hv18[1] !=  ap18.hv18[1]) failed (__LINE__);
    if (iv18.hv18[0] !=  ap18.hv18[0]) failed (__LINE__);
    jv18 = va_arg (ap, double);
    kv18 = va_arg (ap, struct bt18);
    if (jv18 !=  ev18) failed (__LINE__);
    if (kv18.dv18 !=  fv18.dv18) failed (__LINE__);
    va_end (ap);
    return cv18;
}

static void caller_bf18(  )
{
    union at18 *lv18;
    lv18 = callee_af18 (iv18, ev18, fv18);
    if (cv18 !=  lv18) failed (__LINE__);
}

static long long int av17 = 319239376L;

static unsigned int iv17 = 1128034662U;

static
struct ct17
{
    union bt17 { unsigned long int ev17; } fv17;
    unsigned char gv17[1];
    unsigned long long int hv17[1];
}
jv17
=
    { { 1666475663UL }, { '\x49' }, { 1599944461UL } };

static long int kv17[1] = { 690675042L };

static struct at17 { short int bv17; } cv17 = { 18305 };

static int dv17 = 1081824170;

static
long long int
callee_af17( unsigned int ap17, struct ct17 bp17, long int cp17[1], ... )
{
    va_list ap;
    struct at17 lv17;
    int mv17;
    va_start (ap, cp17);
    if (iv17 !=  ap17) failed (__LINE__);
    if (jv17.fv17.ev17 !=  bp17.fv17.ev17) failed (__LINE__);
    if (jv17.gv17[0] !=  bp17.gv17[0]) failed (__LINE__);
    if (jv17.hv17[0] !=  bp17.hv17[0]) failed (__LINE__);
    if (kv17[0] !=  cp17[0]) failed (__LINE__);
    lv17 = va_arg (ap, struct at17);
    mv17 = va_arg (ap, int);
    if (lv17.bv17 !=  cv17.bv17) failed (__LINE__);
    if (mv17 !=  dv17) failed (__LINE__);
    va_end (ap);
    return av17;
}

static void caller_bf17(  )
{
    long long int nv17;
    nv17 = callee_af17 (iv17, jv17, kv17, cv17, dv17);
    if (av17 !=  nv17) failed (__LINE__);
}

static double av16 = 72144.235468;

static float ev16[1] = { 26085.211599 };

static
struct bt16 { union at16 { float bv16; } cv16; } dv16 =
    { { 9157.577785 } };

static double callee_af16( float ap16[1], ... )
{
    va_list ap;
    struct bt16 fv16;
    va_start (ap, ap16);
    if (ev16[0] !=  ap16[0]) failed (__LINE__);
    fv16 = va_arg (ap, struct bt16);
    if (fv16.cv16.bv16 !=  dv16.cv16.bv16) failed (__LINE__);
    va_end (ap);
    return av16;
}

static void caller_bf16(  )
{
    double gv16;
    gv16 = callee_af16 (ev16, dv16); if (av16 !=  gv16) failed (__LINE__);
}

static char av15 = '\x55';

static
struct at15 { long long int dv15[2]; } fv15 =
    { { 1389779334L, 1968001853L } };

static double gv15 = 29350.137363;

static struct bt15 { double *ev15; } hv15 = { (double *) 1583682636U };

static int bv15 = 1569911392;

static double cv15 = 99941.551657;

static
char
callee_af15( struct at15 ap15, double bp15, struct bt15 cp15, ... )
{
    va_list ap;
    int iv15;
    double jv15;
    va_start (ap, cp15);
    if (fv15.dv15[1] !=  ap15.dv15[1]) failed (__LINE__);
    if (fv15.dv15[0] !=  ap15.dv15[0]) failed (__LINE__);
    if (gv15 !=  bp15) failed (__LINE__);
    if (hv15.ev15 !=  cp15.ev15) failed (__LINE__);
    iv15 = va_arg (ap, int);
    jv15 = va_arg (ap, double);
    if (iv15 !=  bv15) failed (__LINE__);
    if (jv15 !=  cv15) failed (__LINE__);
    va_end (ap);
    return av15;
}

static void caller_bf15(  )
{
    char kv15;
    kv15 = callee_af15 (fv15, gv15, hv15, bv15, cv15);
    if (av15 !=  kv15) failed (__LINE__);
}

static long int av14 = 10325239L;

static struct et14 { float lv14; } mv14 = { 48617.356107 };

static struct at14 { unsigned long long int bv14; } iv14 = { 200414592UL };

static double jv14 = 57980.770873;

static
struct dt14
{
    union bt14 { long int cv14; int dv14; } ev14;
    union ct14 { double fv14; } gv14;
    unsigned short int *hv14;
}
kv14
=
    { { 851933967L }, { 26948.424028 }, (unsigned short int *) 887870805U };

static long int callee_af14( struct et14 ap14, ... )
{
    va_list ap;
    struct at14 nv14;
    double ov14;
    struct dt14 pv14;
    va_start (ap, ap14);
    if (mv14.lv14 !=  ap14.lv14) failed (__LINE__);
    nv14 = va_arg (ap, struct at14);
    ov14 = va_arg (ap, double);
    pv14 = va_arg (ap, struct dt14);
    if (nv14.bv14 !=  iv14.bv14) failed (__LINE__);
    if (ov14 !=  jv14) failed (__LINE__);
    if (pv14.ev14.cv14 !=  kv14.ev14.cv14) failed (__LINE__);
    if (pv14.gv14.fv14 !=  kv14.gv14.fv14) failed (__LINE__);
    if (pv14.hv14 !=  kv14.hv14) failed (__LINE__);
    va_end (ap);
    return av14;
}

static void caller_bf14(  )
{
    long int qv14;
    qv14 = callee_af14 (mv14, iv14, jv14, kv14);
    if (av14 !=  qv14) failed (__LINE__);
}

static union at13 { unsigned long long int av13; } bv13 = { 1685362101UL };

static
union dt13 { double gv13[2]; double hv13; } nv13 =
    { { 23433.193582, 16963.417599 } };

static unsigned long long int ov13 = 1094719998UL;

static
struct ft13
{ char iv13; int jv13[2]; union et13 { short int kv13; double lv13; } mv13; }
pv13
=
    { '\x4e', { 925428556, 364080434 }, { 30984 } };

static
struct ct13 { union bt13 { long int cv13; } dv13; double ev13; } fv13 =
    { { 1072181025L }, 2214.775610 };

static
union at13
callee_af13(
    union dt13 ap13,
    unsigned long long int bp13,
    struct ft13 cp13,
    ...
)
{
    va_list ap;
    struct ct13 qv13;
    va_start (ap, cp13);
    if (nv13.gv13[1] !=  ap13.gv13[1]) failed (__LINE__);
    if (nv13.gv13[0] !=  ap13.gv13[0]) failed (__LINE__);
    if (ov13 !=  bp13) failed (__LINE__);
    if (pv13.iv13 !=  cp13.iv13) failed (__LINE__);
    if (pv13.jv13[1] !=  cp13.jv13[1]) failed (__LINE__);
    if (pv13.jv13[0] !=  cp13.jv13[0]) failed (__LINE__);
    if (pv13.mv13.kv13 !=  cp13.mv13.kv13) failed (__LINE__);
    qv13 = va_arg (ap, struct ct13);
    if (qv13.dv13.cv13 !=  fv13.dv13.cv13) failed (__LINE__);
    if (qv13.ev13 !=  fv13.ev13) failed (__LINE__);
    va_end (ap);
    return bv13;
}

static void caller_bf13(  )
{
    union at13 rv13;
    rv13 = callee_af13 (nv13, ov13, pv13, fv13);
    if (bv13.av13 !=  rv13.av13) failed (__LINE__);
}

static union at12 { float av12; char bv12; } cv12 = { 18439.678293 };

static float ev12[1] = { 27322.978150 };

static double dv12 = 30859.882861;

static union at12 callee_af12( float ap12[1], ... )
{
    va_list ap;
    double fv12;
    va_start (ap, ap12);
    if (ev12[0] !=  ap12[0]) failed (__LINE__);
    fv12 = va_arg (ap, double);
    if (fv12 !=  dv12) failed (__LINE__);
    va_end (ap);
    return cv12;
}

static void caller_bf12(  )
{
    union at12 gv12;
    gv12 = callee_af12 (ev12, dv12);
    if (cv12.av12 !=  gv12.av12) failed (__LINE__);
}

static
struct ct11
{
    union at11 { unsigned int av11; } bv11;
    struct bt11
    { unsigned short int cv11; unsigned long long int dv11; float ev11; }
    fv11;
    double gv11;
}
hv11
=
    { { 1541254240U }, { 29404, 117334096UL, 80643.514005 }, 83310.161943 };

static double ov11 = 91426.030953;

static double pv11[1][1] = { { 93506.740295 } };

static
union et11
{ union dt11 { unsigned short int lv11; long int mv11; } nv11; }
qv11
=
    { { 26963 } };

static int iv11 = 2004994197;

static int jv11 = 176690960;

static int kv11 = 470732209;

static
struct ct11
callee_af11( double ap11, double bp11[1][1], union et11 cp11, ... )
{
    va_list ap;
    int rv11;
    int sv11;
    int tv11;
    va_start (ap, cp11);
    if (ov11 !=  ap11) failed (__LINE__);
    if (pv11[0][0] !=  bp11[0][0]) failed (__LINE__);
    if (qv11.nv11.lv11 !=  cp11.nv11.lv11) failed (__LINE__);
    rv11 = va_arg (ap, int);
    sv11 = va_arg (ap, int);
    tv11 = va_arg (ap, int);
    if (rv11 !=  iv11) failed (__LINE__);
    if (sv11 !=  jv11) failed (__LINE__);
    if (tv11 !=  kv11) failed (__LINE__);
    va_end (ap);
    return hv11;
}

static void caller_bf11(  )
{
    struct ct11 uv11;
    uv11 = callee_af11 (ov11, pv11, qv11, iv11, jv11, kv11);
    if (hv11.bv11.av11 !=  uv11.bv11.av11) failed (__LINE__);
    if (hv11.fv11.cv11 !=  uv11.fv11.cv11) failed (__LINE__);
    if (hv11.fv11.dv11 !=  uv11.fv11.dv11) failed (__LINE__);
    if (hv11.fv11.ev11 !=  uv11.fv11.ev11) failed (__LINE__);
    if (hv11.gv11 !=  uv11.gv11) failed (__LINE__);
}

static double **av10 = (double **) 1387010491U;

static union et10 { double mv10; } nv10 = { 72977.502380 };

static int **ov10 = (int **) 191458304U;

static struct at10 { long int bv10; } iv10 = { 890866572L };

static struct bt10 { float cv10[1]; } jv10 = { { 65254.041203 } };

static double kv10 = 86230.708068;

static
struct dt10
{ struct ct10 { float dv10; short int ev10; double fv10; } gv10; int hv10; }
lv10
=
    { { 56604.658754, 10801, 23319.680954 }, 2028557859 };

static double ** callee_af10( union et10 ap10, int **bp10, ... )
{
    va_list ap;
    struct at10 pv10;
    struct bt10 qv10;
    double rv10;
    struct dt10 sv10;
    va_start (ap, bp10);
    if (nv10.mv10 !=  ap10.mv10) failed (__LINE__);
    if (ov10 !=  bp10) failed (__LINE__);
    pv10 = va_arg (ap, struct at10);
    qv10 = va_arg (ap, struct bt10);
    rv10 = va_arg (ap, double);
    sv10 = va_arg (ap, struct dt10);
    if (pv10.bv10 !=  iv10.bv10) failed (__LINE__);
    if (qv10.cv10[0] !=  jv10.cv10[0]) failed (__LINE__);
    if (rv10 !=  kv10) failed (__LINE__);
    if (sv10.gv10.dv10 !=  lv10.gv10.dv10) failed (__LINE__);
    if (sv10.gv10.ev10 !=  lv10.gv10.ev10) failed (__LINE__);
    if (sv10.gv10.fv10 !=  lv10.gv10.fv10) failed (__LINE__);
    if (sv10.hv10 !=  lv10.hv10) failed (__LINE__);
    va_end (ap);
    return av10;
}

static void caller_bf10(  )
{
    double **tv10;
    tv10 = callee_af10 (nv10, ov10, iv10, jv10, kv10, lv10);
    if (av10 !=  tv10) failed (__LINE__);
}

static double av9 = 50349.189465;

static char **ev9 = (char **) 663063294U;

static
struct at9 { float cv9; unsigned char dv9; } fv9 =
    { 29629.386431, '\x64' };

static double **bv9 = (double **) 1783845543U;

static double callee_af9( char **ap9, struct at9 bp9, ... )
{
    va_list ap;
    double **gv9;
    va_start (ap, bp9);
    if (ev9 !=  ap9) failed (__LINE__);
    if (fv9.cv9 !=  bp9.cv9) failed (__LINE__);
    if (fv9.dv9 !=  bp9.dv9) failed (__LINE__);
    gv9 = va_arg (ap, double **);
    if (gv9 !=  bv9) failed (__LINE__);
    va_end (ap);
    return av9;
}

static void caller_bf9(  )
{
    double hv9;
    hv9 = callee_af9 (ev9, fv9, bv9); if (av9 !=  hv9) failed (__LINE__);
}

static float av8 = 57731.670109;

static
struct bt8 { struct at8 { long int ev8; } fv8; } jv8 =
    { { 1669866454L } };

static
union ct8
{ unsigned long long int gv8; double hv8; unsigned char iv8; }
kv8[1]
=
    { { 1931237070UL } };

static double bv8 = 20767.554588;

static double cv8 = 75255.269833;

static double dv8 = 39085.567499;

static float callee_af8( struct bt8 ap8, union ct8 bp8[1], ... )
{
    va_list ap;
    double lv8;
    double mv8;
    double nv8;
    va_start (ap, bp8);
    if (jv8.fv8.ev8 !=  ap8.fv8.ev8) failed (__LINE__);
    if (kv8[0].gv8 !=  bp8[0].gv8) failed (__LINE__);
    lv8 = va_arg (ap, double);
    mv8 = va_arg (ap, double);
    nv8 = va_arg (ap, double);
    if (lv8 !=  bv8) failed (__LINE__);
    if (mv8 !=  cv8) failed (__LINE__);
    if (nv8 !=  dv8) failed (__LINE__);
    va_end (ap);
    return av8;
}

static void caller_bf8(  )
{
    float ov8;
    ov8 = callee_af8 (jv8, kv8, bv8, cv8, dv8);
    if (av8 !=  ov8) failed (__LINE__);
}

static unsigned short int av7 = 51025;

static
struct at7 { float dv7; long long int ev7; } fv7 =
    { 3504.960229, 259975393L };

static int bv7 = 1656694471;

static double cv7 = 50060.571175;

static unsigned short int callee_af7( struct at7 ap7, ... )
{
    va_list ap;
    int gv7;
    double hv7;
    va_start (ap, ap7);
    if (fv7.dv7 !=  ap7.dv7) failed (__LINE__);
    if (fv7.ev7 !=  ap7.ev7) failed (__LINE__);
    gv7 = va_arg (ap, int);
    hv7 = va_arg (ap, double);
    if (gv7 !=  bv7) failed (__LINE__);
    if (hv7 !=  cv7) failed (__LINE__);
    va_end (ap);
    return av7;
}

static void caller_bf7(  )
{
    unsigned short int iv7;
    iv7 = callee_af7 (fv7, bv7, cv7); if (av7 !=  iv7) failed (__LINE__);
}

static int av6 = 766215416;

static
union ft6 { union et6 { float lv6; double mv6; } nv6; } pv6 =
    { { 36287.050003 } };

static struct gt6 { short int ov6[1]; } qv6 = { { 24669 } };

static
struct ct6
{
    double bv6;
    union at6 { char cv6; } dv6;
    union bt6 { unsigned short int ev6; char fv6; } gv6;
    unsigned char hv6;
}
jv6
=
    { 19824.494535, { '\x17' }, { 13221 }, '\x5e' };

static struct dt6 { short int iv6[1]; } kv6 = { { 14835 } };

static int callee_af6( union ft6 ap6, struct gt6 bp6, ... )
{
    va_list ap;
    struct ct6 rv6;
    struct dt6 sv6;
    va_start (ap, bp6);
    if (pv6.nv6.lv6 !=  ap6.nv6.lv6) failed (__LINE__);
    if (qv6.ov6[0] !=  bp6.ov6[0]) failed (__LINE__);
    rv6 = va_arg (ap, struct ct6);
    sv6 = va_arg (ap, struct dt6);
    if (rv6.bv6 !=  jv6.bv6) failed (__LINE__);
    if (rv6.dv6.cv6 !=  jv6.dv6.cv6) failed (__LINE__);
    if (rv6.gv6.ev6 !=  jv6.gv6.ev6) failed (__LINE__);
    if (rv6.hv6 !=  jv6.hv6) failed (__LINE__);
    if (sv6.iv6[0] !=  kv6.iv6[0]) failed (__LINE__);
    va_end (ap);
    return av6;
}

static void caller_bf6(  )
{
    int tv6;
    tv6 = callee_af6 (pv6, qv6, jv6, kv6); if (av6 !=  tv6) failed (__LINE__);
}

static float *av5 = (float *) 367559462U;

static
union ct5 { union bt5 { double hv5; float iv5; float jv5; } kv5; } mv5 =
    { { 24241.404916 } };

static
struct dt5 { double lv5; } nv5[2] =
    { { 5880.924893 }, { 8474.122316 } };

static
struct at5
{
    unsigned long long int bv5;
    float cv5;
    unsigned long long int dv5;
    unsigned char ev5;
}
*fv5
=
    (struct at5 *) 1580332799U;

static int gv5 = 606165445;

static float * callee_af5( union ct5 ap5, struct dt5 bp5[2], ... )
{
    va_list ap;
    struct at5 *ov5;
    int pv5;
    va_start (ap, bp5);
    if (mv5.kv5.hv5 !=  ap5.kv5.hv5) failed (__LINE__);
    if (nv5[1].lv5 !=  bp5[1].lv5) failed (__LINE__);
    if (nv5[0].lv5 !=  bp5[0].lv5) failed (__LINE__);
    ov5 = va_arg (ap, struct at5 *);
    pv5 = va_arg (ap, int);
    if (ov5 !=  fv5) failed (__LINE__);
    if (pv5 !=  gv5) failed (__LINE__);
    va_end (ap);
    return av5;
}

static void caller_bf5(  )
{
    float *qv5;
    qv5 = callee_af5 (mv5, nv5, fv5, gv5); if (av5 !=  qv5) failed (__LINE__);
}

static float av4 = 28374.976225;

static float fv4 = 4226.567456;

static
struct at4 { long long int dv4; double ev4; } *gv4 =
    (struct at4 *) 1262007871U;

static double bv4 = 3625.455315;

static double cv4 = 3212.712299;

static float callee_af4( float ap4, struct at4 *bp4, ... )
{
    va_list ap;
    double hv4;
    double iv4;
    va_start (ap, bp4);
    if (fv4 !=  ap4) failed (__LINE__);
    if (gv4 !=  bp4) failed (__LINE__);
    hv4 = va_arg (ap, double);
    iv4 = va_arg (ap, double);
    if (hv4 !=  bv4) failed (__LINE__);
    if (iv4 !=  cv4) failed (__LINE__);
    va_end (ap);
    return av4;
}

static void caller_bf4(  )
{
    float jv4;
    jv4 = callee_af4 (fv4, gv4, bv4, cv4); if (av4 !=  jv4) failed (__LINE__);
}

static unsigned short int av3 = 51497;

static float ev3[1] = { 62101.613022 };

static struct at3 { char dv3; } fv3[1] = { { '\x5d' } };

static float gv3[2] = { 3340.587330, 47380.215975 };

static int bv3 = 394716714;

static double cv3 = 59335.789510;

static
unsigned short int
callee_af3( float ap3[1], struct at3 bp3[1], float cp3[2], ... )
{
    va_list ap;
    int hv3;
    double iv3;
    va_start (ap, cp3);
    if (ev3[0] !=  ap3[0]) failed (__LINE__);
    if (fv3[0].dv3 !=  bp3[0].dv3) failed (__LINE__);
    if (gv3[1] !=  cp3[1]) failed (__LINE__);
    if (gv3[0] !=  cp3[0]) failed (__LINE__);
    hv3 = va_arg (ap, int);
    iv3 = va_arg (ap, double);
    if (hv3 !=  bv3) failed (__LINE__);
    if (iv3 !=  cv3) failed (__LINE__);
    va_end (ap);
    return av3;
}

static void caller_bf3(  )
{
    unsigned short int jv3;
    jv3 = callee_af3 (ev3, fv3, gv3, bv3, cv3);
    if (av3 !=  jv3) failed (__LINE__);
}

static float av2 = 69039.186808;

static unsigned long int bv2 = 2012599326UL;

static float cv2 = 71060.174522;

static float callee_af2( unsigned long int ap2, float bp2 )
{
    if (bv2 !=  ap2) failed (__LINE__);
    if (cv2 !=  bp2) failed (__LINE__);
    return av2;
}

static void caller_bf2(  )
{
    float dv2;
    dv2 = callee_af2 (bv2, cv2); if (av2 !=  dv2) failed (__LINE__);
}

static double av1 = 87231.727844;

static unsigned short int kv1 = 34614;

static int hv1 = 900101093;

static double iv1 = 12121.790127;

static
struct bt1
{
    union at1 { long long int bv1; double cv1; double dv1; } ev1;
    unsigned short int *fv1;
    short int gv1[1];
}
jv1
=
    { { 2146114434L }, (unsigned short int *) 977550002U, { 19058 } };

static double callee_af1( unsigned short int ap1, ... )
{
    va_list ap;
    int lv1;
    double mv1;
    struct bt1 nv1;
    va_start (ap, ap1);
    if (kv1 !=  ap1) failed (__LINE__);
    lv1 = va_arg (ap, int);
    mv1 = va_arg (ap, double);
    nv1 = va_arg (ap, struct bt1);
    if (lv1 !=  hv1) failed (__LINE__);
    if (mv1 !=  iv1) failed (__LINE__);
    if (nv1.ev1.bv1 !=  jv1.ev1.bv1) failed (__LINE__);
    if (nv1.fv1 !=  jv1.fv1) failed (__LINE__);
    if (nv1.gv1[0] !=  jv1.gv1[0]) failed (__LINE__);
    va_end (ap);
    return av1;
}

static void caller_bf1(  )
{
    double ov1;
    ov1 = callee_af1 (kv1, hv1, iv1, jv1); if (av1 !=  ov1) failed (__LINE__);
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
