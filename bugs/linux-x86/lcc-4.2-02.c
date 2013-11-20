/* $Id: lcc-4.2-02.c 3 2006-04-29 13:17:19Z lindig $ */
/* ./quest -test ansi */

/*
 : tmp; /scratch/lindig/lcc/lcc -o lcc-x86-bug2 lcc-x86-bug2.c 
 <command line>:3:1: warning: "__STDC__" redefined
 : tmp; ./lcc-x86-bug2 
 failed in lcc-x86-bug2.c: 270
 : tmp; /scratch/lindig/lcc/lcc -v
 /scratch/lindig/lcc/lcc $Id: lcc-4.2-02.c 3 2006-04-29 13:17:19Z lindig $
*/ 

#include <stdarg.h>


extern int printf (char *, ...);

static int errors = 0;

static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }

static unsigned char av1 = '\x2b';

static long long int gv1 = 260327519L;

static struct bt1 { short int ev1; } hv1 = { 20025 };

static union ct1 { long int fv1; } iv1[1] = { { 511878119L } };

static struct at1 { float bv1; } *cv1 = (struct at1 *) 382833280U;

static double dv1 = 62249.883500;

static
unsigned char
callee_af1( long long int ap1, struct bt1 bp1, union ct1 cp1[1], ... )
{
    va_list ap;
    typedef struct at1 *ad1;
    typedef double bd1;
    ad1 jv1;
    bd1 kv1;
    va_start (ap, cp1);
    if (gv1 !=  ap1) failed (__LINE__);
    if (hv1.ev1 !=  bp1.ev1) failed (__LINE__);
    if (iv1[0].fv1 !=  cp1[0].fv1) failed (__LINE__);
    jv1 = va_arg (ap, ad1);
    kv1 = va_arg (ap, bd1);
    if (cv1 !=  jv1) failed (__LINE__);
    if (dv1 !=  kv1) failed (__LINE__);
    va_end (ap);
    return av1;
}

static void caller_bf1(  )
{
    unsigned char lv1;
    lv1 = callee_af1 (gv1, hv1, iv1, cv1, dv1);
    if (av1 !=  lv1) failed (__LINE__);
}

static
struct bt2 { union at2 { float av2; unsigned short int bv2; } cv2; } dv2 =
    { { 93064.692443 } };

static double nv2 = 24410.587823;

static double ov2 = 49240.315577;

static union ct2 { short int ev2; } *kv2 = (union ct2 *) 658491901U;

static double lv2 = 17226.363498;

static
union et2
{
    float fv2;
    struct dt2 { unsigned int gv2; float hv2; } iv2;
    unsigned long int jv2[2];
}
mv2
=
    { 74311.142743 };

static struct bt2 callee_af2( double ap2, double bp2, ... )
{
    va_list ap;
    typedef union ct2 *ad2;
    typedef double bd2;
    typedef union et2 cd2;
    ad2 pv2;
    bd2 qv2;
    cd2 rv2;
    va_start (ap, bp2);
    if (nv2 !=  ap2) failed (__LINE__);
    if (ov2 !=  bp2) failed (__LINE__);
    pv2 = va_arg (ap, ad2);
    qv2 = va_arg (ap, bd2);
    rv2 = va_arg (ap, cd2);
    if (kv2 !=  pv2) failed (__LINE__);
    if (lv2 !=  qv2) failed (__LINE__);
    if (mv2.fv2 !=  rv2.fv2) failed (__LINE__);
    va_end (ap);
    return dv2;
}

static void caller_bf2(  )
{
    struct bt2 sv2;
    sv2 = callee_af2 (nv2, ov2, kv2, lv2, mv2);
    if (dv2.cv2.av2 !=  sv2.cv2.av2) failed (__LINE__);
}

static int av3 = 783146031;

static
struct et3
{
    union bt3 { double iv3; unsigned char jv3; } kv3;
    struct ct3 { float lv3; unsigned long long int mv3; } nv3;
    union dt3 { double ov3; unsigned int pv3; double qv3; } rv3;
}
sv3
=
    { { 50363.550903 }, { 18506.459248, 857703306UL }, { 78874.422034 } };

static unsigned long int tv3 = 1099770540UL;

static long long int ev3 = 497498246L;

static int fv3 = 1539597811;

static int gv3 = 957244805;

static
struct at3 { float bv3; unsigned short int cv3; long long int dv3; } hv3[2] =
    {
        { 30161.818220, 32728, 1415603402L },
        { 45426.120930, 18072, 125378931L }
    };

static int callee_af3( struct et3 ap3, unsigned long int bp3, ... )
{
    va_list ap;
    typedef long long int ad3;
    typedef int bd3;
    typedef int cd3;
    typedef struct at3 *dd3;
    ad3 uv3;
    bd3 vv3;
    cd3 wv3;
    dd3 xv3;
    va_start (ap, bp3);
    if (sv3.kv3.iv3 !=  ap3.kv3.iv3) failed (__LINE__);
    if (sv3.nv3.lv3 !=  ap3.nv3.lv3) failed (__LINE__);
    if (sv3.nv3.mv3 !=  ap3.nv3.mv3) failed (__LINE__);
    if (sv3.rv3.ov3 !=  ap3.rv3.ov3) failed (__LINE__);
    if (tv3 !=  bp3) failed (__LINE__);
    uv3 = va_arg (ap, ad3);
    vv3 = va_arg (ap, bd3);
    wv3 = va_arg (ap, cd3);
    xv3 = va_arg (ap, dd3);
    if (ev3 !=  uv3) failed (__LINE__);
    if (fv3 !=  vv3) failed (__LINE__);
    if (gv3 !=  wv3) failed (__LINE__);
    if (hv3[1].bv3 !=  xv3[1].bv3) failed (__LINE__);
    if (hv3[0].bv3 !=  xv3[0].bv3) failed (__LINE__);
    if (hv3[1].cv3 !=  xv3[1].cv3) failed (__LINE__);
    if (hv3[0].cv3 !=  xv3[0].cv3) failed (__LINE__);
    if (hv3[1].dv3 !=  xv3[1].dv3) failed (__LINE__);
    if (hv3[0].dv3 !=  xv3[0].dv3) failed (__LINE__);
    va_end (ap);
    return av3;
}

static void caller_bf3(  )
{
    int yv3;
    yv3 = callee_af3 (sv3, tv3, ev3, fv3, gv3, hv3);
    if (av3 !=  yv3) failed (__LINE__);
}

static
struct at4 { double av4; float bv4; } cv4 =
    { 71305.920354, 82576.522629 };

static float *lv4[1] = { (float *) 240692462U };

static long int iv4 = 1841477506L;

static
struct dt4
{
    union bt4 { float dv4; } ev4;
    struct ct4 { short int fv4; double gv4; } hv4;
}
jv4
=
    { { 68162.837327 }, { 11460, 9521.797976 } };

static double kv4 = 32754.405146;

static struct at4 callee_af4( float *ap4[1], ... )
{
    va_list ap;
    typedef long int ad4;
    typedef struct dt4 bd4;
    typedef double cd4;
    ad4 mv4;
    bd4 nv4;
    cd4 ov4;
    va_start (ap, ap4);
    if (lv4[0] !=  ap4[0]) failed (__LINE__);
    mv4 = va_arg (ap, ad4);
    nv4 = va_arg (ap, bd4);
    ov4 = va_arg (ap, cd4);
    if (iv4 !=  mv4) failed (__LINE__);
    if (jv4.ev4.dv4 !=  nv4.ev4.dv4) failed (__LINE__);
    if (jv4.hv4.fv4 !=  nv4.hv4.fv4) failed (__LINE__);
    if (jv4.hv4.gv4 !=  nv4.hv4.gv4) failed (__LINE__);
    if (kv4 !=  ov4) failed (__LINE__);
    va_end (ap);
    return cv4;
}

static void caller_bf4(  )
{
    struct at4 pv4;
    pv4 = callee_af4 (lv4, iv4, jv4, kv4);
    if (cv4.av4 !=  pv4.av4) failed (__LINE__);
    if (cv4.bv4 !=  pv4.bv4) failed (__LINE__);
}

static double av5 = 80543.385333;

static float lv5[1][1] = { { 85373.923610 } };

static
union at5 { float cv5; short int *dv5; double ev5; } mv5 =
    { 4397.929683 };

static
struct ct5 { struct bt5 { float fv5; } gv5; } nv5 =
    { { 34061.300353 } };

static
struct et5
{ struct dt5 { short int hv5; short int iv5; unsigned short int jv5; } kv5; }
ov5
=
    { { 30541, 29792, 47026 } };

static double bv5 = 58272.744777;

static
double
callee_af5(
    float ap5[1][1],
    union at5 bp5,
    struct ct5 cp5,
    struct et5 dp5,
    ...
)
{
    va_list ap;
    typedef double ad5;
    ad5 pv5;
    va_start (ap, dp5);
    if (lv5[0][0] !=  ap5[0][0]) failed (__LINE__);
    if (mv5.cv5 !=  bp5.cv5) failed (__LINE__);
    if (nv5.gv5.fv5 !=  cp5.gv5.fv5) failed (__LINE__);
    if (ov5.kv5.hv5 !=  dp5.kv5.hv5) failed (__LINE__);
    if (ov5.kv5.iv5 !=  dp5.kv5.iv5) failed (__LINE__);
    if (ov5.kv5.jv5 !=  dp5.kv5.jv5) failed (__LINE__);
    pv5 = va_arg (ap, ad5);
    if (bv5 !=  pv5) failed (__LINE__);
    va_end (ap);
    return av5;
}

static void caller_bf5(  )
{
    double qv5;
    qv5 = callee_af5 (lv5, mv5, nv5, ov5, bv5);
    if (av5 !=  qv5) failed (__LINE__);
}

static long long int av6 = 1184890243L;

static float hv6 = 73211.874935;

static
struct at6 { float ev6; float fv6; long int gv6; } iv6[1] =
    { { 65795.083039, 72765.773672, 170235664L } };

static double bv6 = 30845.472600;

static long long int cv6 = 793902103L;

static double dv6 = 47017.917207;

static long long int callee_af6( float ap6, struct at6 bp6[1], ... )
{
    va_list ap;
    typedef double ad6;
    typedef long long int bd6;
    typedef double cd6;
    ad6 jv6;
    bd6 kv6;
    cd6 lv6;
    va_start (ap, bp6);
    if (hv6 !=  ap6) failed (__LINE__);
    if (iv6[0].ev6 !=  bp6[0].ev6) failed (__LINE__);
    if (iv6[0].fv6 !=  bp6[0].fv6) failed (__LINE__);
    if (iv6[0].gv6 !=  bp6[0].gv6) failed (__LINE__);
    jv6 = va_arg (ap, ad6);
    kv6 = va_arg (ap, bd6);
    lv6 = va_arg (ap, cd6);
    if (bv6 !=  jv6) failed (__LINE__);
    if (cv6 !=  kv6) failed (__LINE__);
    if (dv6 !=  lv6) failed (__LINE__);
    va_end (ap);
    return av6;
}

static void caller_bf6(  )
{
    long long int mv6;
    mv6 = callee_af6 (hv6, iv6, bv6, cv6, dv6);
    if (av6 !=  mv6) failed (__LINE__);
}

static long int av7 = 313338555L;

static int **tv7 = (int **) 984445591U;

static struct ct7 { float kv7; } uv7[1] = { { 78698.325647 } };

static
struct dt7 { double *lv7; short int *mv7; float nv7; } vv7 =
    { (double *) 672803576U, (short int *) 625312369U, 50903.872948 };

static
struct ft7
{
    union et7 { float ov7; unsigned int pv7; unsigned char qv7; } rv7;
    unsigned short int *sv7;
}
wv7
=
    { { 31236.038790 }, (unsigned short int *) 1680254576U };

static
union bt7
{
    long long int *bv7;
    union at7 { unsigned long long int cv7; float dv7; short int ev7; } fv7;
}
gv7
=
    { (long long int *) 1748828529U };

static unsigned long long int hv7[1] = { 1773795156UL };

static long int iv7 = 1270335563L;

static int jv7 = 859480274;

static
long int
callee_af7(
    int **ap7,
    struct ct7 bp7[1],
    struct dt7 cp7,
    struct ft7 dp7,
    ...
)
{
    va_list ap;
    typedef union bt7 ad7;
    typedef unsigned long long int *bd7;
    typedef long int cd7;
    typedef int dd7;
    ad7 xv7;
    bd7 yv7;
    cd7 zv7;
    dd7 bav7;
    va_start (ap, dp7);
    if (tv7 !=  ap7) failed (__LINE__);
    if (uv7[0].kv7 !=  bp7[0].kv7) failed (__LINE__);
    if (vv7.lv7 !=  cp7.lv7) failed (__LINE__);
    if (vv7.mv7 !=  cp7.mv7) failed (__LINE__);
    if (vv7.nv7 !=  cp7.nv7) failed (__LINE__);
    if (wv7.rv7.ov7 !=  dp7.rv7.ov7) failed (__LINE__);
    if (wv7.sv7 !=  dp7.sv7) failed (__LINE__);
    xv7 = va_arg (ap, ad7);
    yv7 = va_arg (ap, bd7);
    zv7 = va_arg (ap, cd7);
    bav7 = va_arg (ap, dd7);
    if (gv7.bv7 !=  xv7.bv7) failed (__LINE__);
    if (hv7[0] !=  yv7[0]) failed (__LINE__);
    if (iv7 !=  zv7) failed (__LINE__);
    if (jv7 !=  bav7) failed (__LINE__);
    va_end (ap);
    return av7;
}

static void caller_bf7(  )
{
    long int bbv7;
    bbv7 = callee_af7 (tv7, uv7, vv7, wv7, gv7, hv7, iv7, jv7);
    if (av7 !=  bbv7) failed (__LINE__);
}

static
union bt8
{
    union at8 { unsigned int av8; double bv8; } cv8;
    unsigned long long int *dv8;
}
ev8
=
    { { 522442945U } };

static float qv8 = 51382.002156;

static short int rv8 = 26351;

static
union ct8 { double hv8; int iv8; unsigned long int jv8[2]; } sv8 =
    { 53990.919310 };

static
union ft8
{
    union dt8 { double kv8; } lv8;
    float mv8[2];
    union et8 { long int nv8; double ov8; } pv8;
}
tv8
=
    { { 36387.240919 } };

static long int fv8 = 693555199L;

static double gv8 = 39520.485149;

static
union bt8
callee_af8( float ap8, short int bp8, union ct8 cp8, union ft8 dp8, ... )
{
    va_list ap;
    typedef long int ad8;
    typedef double bd8;
    ad8 uv8;
    bd8 vv8;
    va_start (ap, dp8);
    if (qv8 !=  ap8) failed (__LINE__);
    if (rv8 !=  bp8) failed (__LINE__);
    if (sv8.hv8 !=  cp8.hv8) failed (__LINE__);
    if (tv8.lv8.kv8 !=  dp8.lv8.kv8) failed (__LINE__);
    uv8 = va_arg (ap, ad8);
    vv8 = va_arg (ap, bd8);
    if (fv8 !=  uv8) failed (__LINE__);
    if (gv8 !=  vv8) failed (__LINE__);
    va_end (ap);
    return ev8;
}

static void caller_bf8(  )
{
    union bt8 wv8;
    wv8 = callee_af8 (qv8, rv8, sv8, tv8, fv8, gv8);
    if (ev8.cv8.av8 !=  wv8.cv8.av8) failed (__LINE__);
}

static unsigned long int *av9 = (unsigned long int *) 445344278U;

static unsigned long long int tv9 = 393511583UL;

static
struct et9 { char qv9; char rv9; double sv9; } *uv9 =
    (struct et9 *) 697865801U;

static int mv9 = 1671707462;

static long int nv9 = 112388702L;

static
struct bt9
{
    struct at9 { double bv9; double cv9; long long int dv9; } ev9;
    int fv9[1];
    short int gv9;
}
ov9
=
    { { 36446.493096, 80172.527839, 569557747L }, { 530423330 }, 7240 };

static
union dt9
{ union ct9 { double hv9; int iv9; unsigned short int jv9; } kv9; float lv9; }
pv9
=
    { { 24321.273357 } };

static
unsigned long int *
callee_af9( unsigned long long int ap9, struct et9 *bp9, ... )
{
    va_list ap;
    typedef int ad9;
    typedef long int bd9;
    typedef struct bt9 cd9;
    typedef union dt9 dd9;
    ad9 vv9;
    bd9 wv9;
    cd9 xv9;
    dd9 yv9;
    va_start (ap, bp9);
    if (tv9 !=  ap9) failed (__LINE__);
    if (uv9 !=  bp9) failed (__LINE__);
    vv9 = va_arg (ap, ad9);
    wv9 = va_arg (ap, bd9);
    xv9 = va_arg (ap, cd9);
    yv9 = va_arg (ap, dd9);
    if (mv9 !=  vv9) failed (__LINE__);
    if (nv9 !=  wv9) failed (__LINE__);
    if (ov9.ev9.bv9 !=  xv9.ev9.bv9) failed (__LINE__);
    if (ov9.ev9.cv9 !=  xv9.ev9.cv9) failed (__LINE__);
    if (ov9.ev9.dv9 !=  xv9.ev9.dv9) failed (__LINE__);
    if (ov9.fv9[0] !=  xv9.fv9[0]) failed (__LINE__);
    if (ov9.gv9 !=  xv9.gv9) failed (__LINE__);
    if (pv9.kv9.hv9 !=  yv9.kv9.hv9) failed (__LINE__);
    va_end (ap);
    return av9;
}

static void caller_bf9(  )
{
    unsigned long int *zv9;
    zv9 = callee_af9 (tv9, uv9, mv9, nv9, ov9, pv9);
    if (av9 !=  zv9) failed (__LINE__);
}

static unsigned short int av10 = 25414;

static
union bt10
{ float dv10; float ev10; union at10 { double fv10; double gv10; } hv10; }
iv10
=
    { 70732.305670 };

static long long int bv10[1][1] = { { 1188057994L } };

static int cv10 = 1576080052;

static unsigned short int callee_af10( union bt10 ap10, ... )
{
    va_list ap;
    typedef long long int (*ad10)[1];
    typedef int bd10;
    ad10 jv10;
    bd10 kv10;
    va_start (ap, ap10);
    if (iv10.dv10 !=  ap10.dv10) failed (__LINE__);
    jv10 = va_arg (ap, ad10);
    kv10 = va_arg (ap, bd10);
    if (bv10[0][0] !=  jv10[0][0]) failed (__LINE__);
    if (cv10 !=  kv10) failed (__LINE__);
    va_end (ap);
    return av10;
}

static void caller_bf10(  )
{
    unsigned short int lv10;
    lv10 = callee_af10 (iv10, bv10, cv10);
    if (av10 !=  lv10) failed (__LINE__);
}

static
struct at11 { short int *av11; unsigned char bv11; } cv11 =
    { (short int *) 1841586760U, '\x25' };

static unsigned int ov11[1][1] = { { 224650500U } };

static unsigned long int pv11 = 887624064UL;

static
union et11 { struct dt11 { double kv11; float lv11; float mv11; } nv11; } qv11
=
    { { 34922.369420, 35327.851101, 74084.074204 } };

static unsigned int rv11 = 392674981U;

static double iv11 = 44901.114552;

static
union ct11
{
    char dv11;
    struct bt11 { unsigned short int ev11; char fv11; int gv11; } hv11;
}
jv11
=
    { '\xe' };

static
struct at11
callee_af11(
    unsigned int ap11[1][1],
    unsigned long int bp11,
    union et11 cp11,
    unsigned int dp11,
    ...
)
{
    va_list ap;
    typedef double ad11;
    typedef union ct11 bd11;
    ad11 sv11;
    bd11 tv11;
    va_start (ap, dp11);
    if (ov11[0][0] !=  ap11[0][0]) failed (__LINE__);
    if (pv11 !=  bp11) failed (__LINE__);
    if (qv11.nv11.kv11 !=  cp11.nv11.kv11) failed (__LINE__);
    if (qv11.nv11.lv11 !=  cp11.nv11.lv11) failed (__LINE__);
    if (qv11.nv11.mv11 !=  cp11.nv11.mv11) failed (__LINE__);
    if (rv11 !=  dp11) failed (__LINE__);
    sv11 = va_arg (ap, ad11);
    tv11 = va_arg (ap, bd11);
    if (iv11 !=  sv11) failed (__LINE__);
    if (jv11.dv11 !=  tv11.dv11) failed (__LINE__);
    va_end (ap);
    return cv11;
}

static void caller_bf11(  )
{
    struct at11 uv11;
    uv11 = callee_af11 (ov11, pv11, qv11, rv11, iv11, jv11);
    if (cv11.av11 !=  uv11.av11) failed (__LINE__);
    if (cv11.bv11 !=  uv11.bv11) failed (__LINE__);
}

static unsigned long long int av12 = 329295977UL;

static double **gv12 = (double **) 1090523335U;

static float hv12 = 47423.568822;

static union bt12 { unsigned long int fv12[1]; } iv12 = { { 1590096357UL } };

static float jv12[1] = { 72514.251595 };

static double dv12 = 38368.224268;

static
struct at12 { double bv12; float cv12; } ev12 =
    { 37186.400587, 35643.126134 };

static
unsigned long long int
callee_af12( double **ap12, float bp12, union bt12 cp12, float dp12[1], ... )
{
    va_list ap;
    typedef double ad12;
    typedef struct at12 bd12;
    ad12 kv12;
    bd12 lv12;
    va_start (ap, dp12);
    if (gv12 !=  ap12) failed (__LINE__);
    if (hv12 !=  bp12) failed (__LINE__);
    if (iv12.fv12[0] !=  cp12.fv12[0]) failed (__LINE__);
    if (jv12[0] !=  dp12[0]) failed (__LINE__);
    kv12 = va_arg (ap, ad12);
    lv12 = va_arg (ap, bd12);
    if (dv12 !=  kv12) failed (__LINE__);
    if (ev12.bv12 !=  lv12.bv12) failed (__LINE__);
    if (ev12.cv12 !=  lv12.cv12) failed (__LINE__);
    va_end (ap);
    return av12;
}

static void caller_bf12(  )
{
    unsigned long long int mv12;
    mv12 = callee_af12 (gv12, hv12, iv12, jv12, dv12, ev12);
    if (av12 !=  mv12) failed (__LINE__);
}

static
struct at13 { long int *av13; int bv13; unsigned short int *cv13; } dv13 =
    {
        (long int *) 1292526539U,
        959890784,
        (unsigned short int *) 1182966623U
    };

static union ct13 { double jv13; double *kv13; } lv13 = { 23891.860962 };

static double mv13 = 33868.598275;

static float nv13 = 40580.379029;

static float ov13[1][1] = { { 67037.611770 } };

static
union bt13 { unsigned short int *ev13; unsigned long long int fv13[1]; } gv13
=
    { (unsigned short int *) 1860673033U };

static double hv13 = 18552.486856;

static long long int iv13 = 1323596490L;

static
struct at13
callee_af13( union ct13 ap13, double bp13, float cp13, float dp13[1][1], ... )
{
    va_list ap;
    typedef union bt13 ad13;
    typedef double bd13;
    typedef long long int cd13;
    ad13 pv13;
    bd13 qv13;
    cd13 rv13;
    va_start (ap, dp13);
    if (lv13.jv13 !=  ap13.jv13) failed (__LINE__);
    if (mv13 !=  bp13) failed (__LINE__);
    if (nv13 !=  cp13) failed (__LINE__);
    if (ov13[0][0] !=  dp13[0][0]) failed (__LINE__);
    pv13 = va_arg (ap, ad13);
    qv13 = va_arg (ap, bd13);
    rv13 = va_arg (ap, cd13);
    if (gv13.ev13 !=  pv13.ev13) failed (__LINE__);
    if (hv13 !=  qv13) failed (__LINE__);
    if (iv13 !=  rv13) failed (__LINE__);
    va_end (ap);
    return dv13;
}

static void caller_bf13(  )
{
    struct at13 sv13;
    sv13 = callee_af13 (lv13, mv13, nv13, ov13, gv13, hv13, iv13);
    if (dv13.av13 !=  sv13.av13) failed (__LINE__);
    if (dv13.bv13 !=  sv13.bv13) failed (__LINE__);
    if (dv13.cv13 !=  sv13.cv13) failed (__LINE__);
}

static unsigned long int **av14 = (unsigned long int **) 454452390U;

static float *fv14 = (float *) 132806771U;

static double dv14 = 95071.480825;

static
struct at14 { long long int bv14; double cv14; } ev14[1] =
    { { 1172424L, 71421.431218 } };

static unsigned long int ** callee_af14( float *ap14, ... )
{
    va_list ap;
    typedef double ad14;
    typedef struct at14 *bd14;
    ad14 gv14;
    bd14 hv14;
    va_start (ap, ap14);
    if (fv14 !=  ap14) failed (__LINE__);
    gv14 = va_arg (ap, ad14);
    hv14 = va_arg (ap, bd14);
    if (dv14 !=  gv14) failed (__LINE__);
    if (ev14[0].bv14 !=  hv14[0].bv14) failed (__LINE__);
    if (ev14[0].cv14 !=  hv14[0].cv14) failed (__LINE__);
    va_end (ap);
    return av14;
}

static void caller_bf14(  )
{
    unsigned long int **iv14;
    iv14 = callee_af14 (fv14, dv14, ev14);
    if (av14 !=  iv14) failed (__LINE__);
}

static
union at15 { unsigned short int av15; unsigned long long int bv15; } *cv15 =
    (union at15 *) 116987146U;

static long int ov15 = 980155203L;

static struct ct15 { float *jv15; } pv15 = { (float *) 1575715947U };

static
struct et15
{ double kv15; union dt15 { double lv15; } mv15; unsigned int nv15; }
qv15
=
    { 39191.525851, { 50245.588370 }, 1540156185U };

static double rv15 = 6658.086023;

static double gv15 = 75581.069554;

static
union bt15 { long long int *dv15; float ev15; float fv15; } hv15 =
    { (long long int *) 1215060U };

static long long int iv15 = 1359216497L;

static
union at15 *
callee_af15(
    long int ap15,
    struct ct15 bp15,
    struct et15 cp15,
    double dp15,
    ...
)
{
    va_list ap;
    typedef double ad15;
    typedef union bt15 bd15;
    typedef long long int cd15;
    ad15 sv15;
    bd15 tv15;
    cd15 uv15;
    va_start (ap, dp15);
    if (ov15 !=  ap15) failed (__LINE__);
    if (pv15.jv15 !=  bp15.jv15) failed (__LINE__);
    if (qv15.kv15 !=  cp15.kv15) failed (__LINE__);
    if (qv15.mv15.lv15 !=  cp15.mv15.lv15) failed (__LINE__);
    if (qv15.nv15 !=  cp15.nv15) failed (__LINE__);
    if (rv15 !=  dp15) failed (__LINE__);
    sv15 = va_arg (ap, ad15);
    tv15 = va_arg (ap, bd15);
    uv15 = va_arg (ap, cd15);
    if (gv15 !=  sv15) failed (__LINE__);
    if (hv15.dv15 !=  tv15.dv15) failed (__LINE__);
    if (iv15 !=  uv15) failed (__LINE__);
    va_end (ap);
    return cv15;
}

static void caller_bf15(  )
{
    union at15 *vv15;
    vv15 = callee_af15 (ov15, pv15, qv15, rv15, gv15, hv15, iv15);
    if (cv15 !=  vv15) failed (__LINE__);
}

static
struct ct16
{
    float av16;
    union at16 { char bv16; } cv16;
    union bt16 { float dv16; double ev16; } fv16;
}
gv16
=
    { 74963.916389, { '\x56' }, { 2383.458304 } };

static
struct dt16 { float *kv16; double lv16; } mv16 =
    { (float *) 1653715368U, 77991.740893 };

static unsigned long int nv16 = 890348596UL;

static long int hv16 = 150137079L;

static double *iv16[2] = { (double *) 1686511189U, (double *) 1668039411U };

static double jv16 = 86799.149855;

static
struct ct16
callee_af16( struct dt16 ap16, unsigned long int bp16, ... )
{
    va_list ap;
    typedef long int ad16;
    typedef double **bd16;
    typedef double cd16;
    ad16 ov16;
    bd16 pv16;
    cd16 qv16;
    va_start (ap, bp16);
    if (mv16.kv16 !=  ap16.kv16) failed (__LINE__);
    if (mv16.lv16 !=  ap16.lv16) failed (__LINE__);
    if (nv16 !=  bp16) failed (__LINE__);
    ov16 = va_arg (ap, ad16);
    pv16 = va_arg (ap, bd16);
    qv16 = va_arg (ap, cd16);
    if (hv16 !=  ov16) failed (__LINE__);
    if (iv16[1] !=  pv16[1]) failed (__LINE__);
    if (iv16[0] !=  pv16[0]) failed (__LINE__);
    if (jv16 !=  qv16) failed (__LINE__);
    va_end (ap);
    return gv16;
}

static void caller_bf16(  )
{
    struct ct16 rv16;
    rv16 = callee_af16 (mv16, nv16, hv16, iv16, jv16);
    if (gv16.av16 !=  rv16.av16) failed (__LINE__);
    if (gv16.cv16.bv16 !=  rv16.cv16.bv16) failed (__LINE__);
    if (gv16.fv16.dv16 !=  rv16.fv16.dv16) failed (__LINE__);
}

static long long int av17 = 1911695468L;

static struct dt17 { unsigned char jv17; } kv17 = { '\x4' };

static char lv17 = '\x1b';

static long long int **hv17 = (long long int **) 1544336677U;

static
struct ct17
{
    struct at17 { char bv17; } cv17;
    unsigned long int *dv17;
    union bt17 { double ev17; float fv17; } gv17;
}
iv17
=
    { { '\x2c' }, (unsigned long int *) 2008265158U, { 14488.810813 } };

static long long int callee_af17( struct dt17 ap17, char bp17, ... )
{
    va_list ap;
    typedef long long int **ad17;
    typedef struct ct17 bd17;
    ad17 mv17;
    bd17 nv17;
    va_start (ap, bp17);
    if (kv17.jv17 !=  ap17.jv17) failed (__LINE__);
    if (lv17 !=  bp17) failed (__LINE__);
    mv17 = va_arg (ap, ad17);
    nv17 = va_arg (ap, bd17);
    if (hv17 !=  mv17) failed (__LINE__);
    if (iv17.cv17.bv17 !=  nv17.cv17.bv17) failed (__LINE__);
    if (iv17.dv17 !=  nv17.dv17) failed (__LINE__);
    if (iv17.gv17.ev17 !=  nv17.gv17.ev17) failed (__LINE__);
    va_end (ap);
    return av17;
}

static void caller_bf17(  )
{
    long long int ov17;
    ov17 = callee_af17 (kv17, lv17, hv17, iv17);
    if (av17 !=  ov17) failed (__LINE__);
}

static
struct ct18
{
    struct at18 { double av18; float bv18; } cv18;
    struct bt18 { unsigned char dv18; double ev18; } fv18;
}
gv18
=
    { { 62482.239764, 27717.572109 }, { '\x7c', 5945.002326 } };

static float ov18 = 46499.772825;

static struct dt18 { float *hv18; } kv18 = { (float *) 127974051U };

static int lv18 = 1297414000;

static
struct et18 { float iv18; unsigned long int jv18; } mv18[1] =
    { { 27014.788829, 1206911789UL } };

static int nv18 = 538340784;

static struct ct18 callee_af18( float ap18, ... )
{
    va_list ap;
    typedef struct dt18 ad18;
    typedef int bd18;
    typedef struct et18 *cd18;
    typedef int dd18;
    ad18 pv18;
    bd18 qv18;
    cd18 rv18;
    dd18 sv18;
    va_start (ap, ap18);
    if (ov18 !=  ap18) failed (__LINE__);
    pv18 = va_arg (ap, ad18);
    qv18 = va_arg (ap, bd18);
    rv18 = va_arg (ap, cd18);
    sv18 = va_arg (ap, dd18);
    if (kv18.hv18 !=  pv18.hv18) failed (__LINE__);
    if (lv18 !=  qv18) failed (__LINE__);
    if (mv18[0].iv18 !=  rv18[0].iv18) failed (__LINE__);
    if (mv18[0].jv18 !=  rv18[0].jv18) failed (__LINE__);
    if (nv18 !=  sv18) failed (__LINE__);
    va_end (ap);
    return gv18;
}

static void caller_bf18(  )
{
    struct ct18 tv18;
    tv18 = callee_af18 (ov18, kv18, lv18, mv18, nv18);
    if (gv18.cv18.av18 !=  tv18.cv18.av18) failed (__LINE__);
    if (gv18.cv18.bv18 !=  tv18.cv18.bv18) failed (__LINE__);
    if (gv18.fv18.dv18 !=  tv18.fv18.dv18) failed (__LINE__);
    if (gv18.fv18.ev18 !=  tv18.fv18.ev18) failed (__LINE__);
}

static float av19 = 1128.075315;

static long long int gv19 = 233599494L;

static struct at19 { double fv19; } hv19 = { 71880.141257 };

static unsigned long int iv19 = 1413720807UL;

static double bv19 = 39405.920446;

static double cv19 = 91938.898444;

static long int dv19 = 1595029164L;

static int ev19 = 153904814;

static
float
callee_af19(
    long long int ap19,
    struct at19 bp19,
    unsigned long int cp19,
    ...
)
{
    va_list ap;
    typedef double ad19;
    typedef double bd19;
    typedef long int cd19;
    typedef int dd19;
    ad19 jv19;
    bd19 kv19;
    cd19 lv19;
    dd19 mv19;
    va_start (ap, cp19);
    if (gv19 !=  ap19) failed (__LINE__);
    if (hv19.fv19 !=  bp19.fv19) failed (__LINE__);
    if (iv19 !=  cp19) failed (__LINE__);
    jv19 = va_arg (ap, ad19);
    kv19 = va_arg (ap, bd19);
    lv19 = va_arg (ap, cd19);
    mv19 = va_arg (ap, dd19);
    if (bv19 !=  jv19) failed (__LINE__);
    if (cv19 !=  kv19) failed (__LINE__);
    if (dv19 !=  lv19) failed (__LINE__);
    if (ev19 !=  mv19) failed (__LINE__);
    va_end (ap);
    return av19;
}

static void caller_bf19(  )
{
    float nv19;
    nv19 = callee_af19 (gv19, hv19, iv19, bv19, cv19, dv19, ev19);
    if (av19 !=  nv19) failed (__LINE__);
}

static
union bt20
{
    long int *av20;
    struct at20
    { unsigned long long int bv20; long long int cv20; float dv20; }
    ev20;
    unsigned long int fv20;
}
gv20
=
    { (long int *) 1018105940U };

static unsigned int kv20 = 1796912411U;

static double lv20 = 14236.519597;

static
struct ct20 { float iv20; char jv20; } *mv20 =
    (struct ct20 *) 1896219343U;

static float nv20 = 49675.455846;

static long int hv20 = 767642090L;

static
union bt20
callee_af20(
    unsigned int ap20,
    double bp20,
    struct ct20 *cp20,
    float dp20,
    ...
)
{
    va_list ap;
    typedef long int ad20;
    ad20 ov20;
    va_start (ap, dp20);
    if (kv20 !=  ap20) failed (__LINE__);
    if (lv20 !=  bp20) failed (__LINE__);
    if (mv20 !=  cp20) failed (__LINE__);
    if (nv20 !=  dp20) failed (__LINE__);
    ov20 = va_arg (ap, ad20);
    if (hv20 !=  ov20) failed (__LINE__);
    va_end (ap);
    return gv20;
}

static void caller_bf20(  )
{
    union bt20 pv20;
    pv20 = callee_af20 (kv20, lv20, mv20, nv20, hv20);
    if (gv20.av20 !=  pv20.av20) failed (__LINE__);
}

int main( int argc, char **argv )
{
    caller_bf1 ();
    caller_bf2 ();
    caller_bf3 ();
    caller_bf4 ();
    caller_bf5 ();
    caller_bf6 ();
    caller_bf7 ();
    caller_bf8 ();
    caller_bf9 ();
    caller_bf10 ();
    caller_bf11 ();
    caller_bf12 ();
    caller_bf13 ();
    caller_bf14 ();
    caller_bf15 ();
    caller_bf16 ();
    caller_bf17 ();
    caller_bf18 ();
    caller_bf19 ();
    caller_bf20 ();
    return errors;
}
