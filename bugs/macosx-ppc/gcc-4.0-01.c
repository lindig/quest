/* $Id: gcc-4.0-01.c 3 2006-04-29 13:17:19Z lindig $ */
/* ./quest apple.lua -test demo */

/*
: tmp; /scratch/lindig/bin/gcc -o foo -O2 gcc-4.0-ppc-bug.c 
: tmp; ./foo 
failed in gcc-4.0-ppc-bug.c: 612
: tmp; /scratch/lindig/bin/gcc -v
Using built-in specs.
Configured with: /scratch/lindig/src/gcc/gcc/configure
--cache-file=./config.cache --build=powerpc-apple-darwin7.6.0
--host=powerpc-apple-darwin7.6.0 --target=powerpc-apple-darwin7.6.0
--prefix=/scratch/lindig
--with-gcc-version-trigger=/scratch/lindig/src/gcc/gcc/version.c
--enable-languages=c --program-transform-name=s,y,y,
--srcdir=../../gcc/gcc
Thread model: posix
gcc version 4.0.0 20050103 (experimental)
*/

#include <stdarg.h>


extern int printf (char *, ...);

static int errors = 0;

static void failed( int line )
{ printf ("failed in %s: %d\n", __FILE__, line); errors++; }

static struct at1 { float *av1; } bv1 = { (float *) 956436061U };

static union dt1 {  } *hv1 = (union dt1 *) 2032179755U;

static float iv1 = 16035.725205;

static struct bt1 { float cv1[0]; } ev1 = { {  } };

static int fv1 = 1907503339;

static struct ct1 { int *dv1; } gv1 = { (int *) 528144992U };

static struct at1 callee_af1( union dt1 *ap1, float bp1, ... )
{
    va_list ap;
    typedef struct bt1 ad1;
    typedef int bd1;
    typedef struct ct1 cd1;
    ad1 jv1;
    bd1 kv1;
    cd1 lv1;
    va_start (ap, bp1);
    if (hv1 !=  ap1) failed (__LINE__);
    if (iv1 !=  bp1) failed (__LINE__);
    jv1 = va_arg (ap, ad1);
    kv1 = va_arg (ap, bd1);
    lv1 = va_arg (ap, cd1);
    if (fv1 !=  kv1) failed (__LINE__);
    if (gv1.dv1 !=  lv1.dv1) failed (__LINE__);
    va_end (ap);
    return bv1;
}

static void caller_bf1(  )
{
    struct at1 mv1;
    mv1 = callee_af1 (hv1, iv1, ev1, fv1, gv1);
    if (bv1.av1 !=  mv1.av1) failed (__LINE__);
}

static
struct ct2
{
    struct at2 { double av2; long long int bv2; } cv2;
    char *dv2;
    union bt2 { float ev2; double fv2; char gv2; } hv2;
}
iv2
=
    { { 99219.761992, 1319847140L }, (char *) 1669421882U, { 96081.801315 } };

static union gt2 { float tv2; } uv2[0] = {  };

static int qv2 = 452673373;

static
struct et2
{
    short int jv2[0];
    union dt2 { unsigned short int kv2; int lv2; double mv2; } nv2;
}
rv2
=
    { {  }, { 59338 } };

static
struct ft2 { float ov2; double pv2; } sv2 =
    { 8410.260605, 76877.476622 };

static struct ct2 callee_af2( union gt2 ap2[0], ... )
{
    va_list ap;
    typedef int ad2;
    typedef struct et2 bd2;
    typedef struct ft2 cd2;
    ad2 vv2;
    bd2 wv2;
    cd2 xv2;
    va_start (ap, ap2);
    vv2 = va_arg (ap, ad2);
    wv2 = va_arg (ap, bd2);
    xv2 = va_arg (ap, cd2);
    if (qv2 !=  vv2) failed (__LINE__);
    if (rv2.nv2.kv2 !=  wv2.nv2.kv2) failed (__LINE__);
    if (sv2.ov2 !=  xv2.ov2) failed (__LINE__);
    if (sv2.pv2 !=  xv2.pv2) failed (__LINE__);
    va_end (ap);
    return iv2;
}

static void caller_bf2(  )
{
    struct ct2 yv2;
    yv2 = callee_af2 (uv2, qv2, rv2, sv2);
    if (iv2.cv2.av2 !=  yv2.cv2.av2) failed (__LINE__);
    if (iv2.cv2.bv2 !=  yv2.cv2.bv2) failed (__LINE__);
    if (iv2.dv2 !=  yv2.dv2) failed (__LINE__);
    if (iv2.hv2.ev2 !=  yv2.hv2.ev2) failed (__LINE__);
}

static
union at3 { float av3; unsigned short int bv3; } *cv3 =
    (union at3 *) 1696381122U;

static double jv3 = 94259.805108;

static
struct ct3
{ unsigned long long int *gv3; long long int hv3[1]; double *iv3; }
kv3
=
    {
        (unsigned long long int *) 2048947701U,
        { 666494502L },
        (double *) 1082939379U
    };

static
struct bt3 { unsigned short int *dv3; unsigned long int ev3[0]; } fv3 =
    { (unsigned short int *) 826136243U, {  } };

static union at3 * callee_af3( double ap3, struct ct3 bp3, ... )
{
    va_list ap;
    typedef struct bt3 ad3;
    ad3 lv3;
    va_start (ap, bp3);
    if (jv3 !=  ap3) failed (__LINE__);
    if (kv3.gv3 !=  bp3.gv3) failed (__LINE__);
    if (kv3.hv3[0] !=  bp3.hv3[0]) failed (__LINE__);
    if (kv3.iv3 !=  bp3.iv3) failed (__LINE__);
    lv3 = va_arg (ap, ad3);
    if (fv3.dv3 !=  lv3.dv3) failed (__LINE__);
    va_end (ap);
    return cv3;
}

static void caller_bf3(  )
{
    union at3 *mv3;
    mv3 = callee_af3 (jv3, kv3, fv3); if (cv3 !=  mv3) failed (__LINE__);
}

static float av4 = 43366.375281;

static struct dt4 { unsigned int hv4; } kv4 = { 1069883446U };

static struct et4 { short int iv4; double jv4; } lv4 = { 1612, 7647.728792 };

static
struct ct4
{
    union at4
    { long long int bv4; float cv4; unsigned long long int dv4; }
    ev4;
    union bt4 {  } fv4;
}
gv4
=
    { { 957247338L }, {  } };

static float callee_af4( struct dt4 ap4, struct et4 bp4, ... )
{
    va_list ap;
    typedef struct ct4 ad4;
    ad4 mv4;
    va_start (ap, bp4);
    if (kv4.hv4 !=  ap4.hv4) failed (__LINE__);
    if (lv4.iv4 !=  bp4.iv4) failed (__LINE__);
    if (lv4.jv4 !=  bp4.jv4) failed (__LINE__);
    mv4 = va_arg (ap, ad4);
    if (gv4.ev4.bv4 !=  mv4.ev4.bv4) failed (__LINE__);
    va_end (ap);
    return av4;
}

static void caller_bf4(  )
{
    float nv4;
    nv4 = callee_af4 (kv4, lv4, gv4); if (av4 !=  nv4) failed (__LINE__);
}

static int av5 = 2042978826;

static unsigned long int *fv5 = (unsigned long int *) 1230110012U;

static int cv5 = 1440487094;

static struct bt5 { union at5 {  } bv5; } dv5 = { {  } };

static int ev5 = 669020685;

static int callee_af5( unsigned long int *ap5, ... )
{
    va_list ap;
    typedef int ad5;
    typedef struct bt5 bd5;
    typedef int cd5;
    ad5 gv5;
    bd5 hv5;
    cd5 iv5;
    va_start (ap, ap5);
    if (fv5 !=  ap5) failed (__LINE__);
    gv5 = va_arg (ap, ad5);
    hv5 = va_arg (ap, bd5);
    iv5 = va_arg (ap, cd5);
    if (cv5 !=  gv5) failed (__LINE__);
    if (ev5 !=  iv5) failed (__LINE__);
    va_end (ap);
    return av5;
}

static void caller_bf5(  )
{
    int jv5;
    jv5 = callee_af5 (fv5, cv5, dv5, ev5); if (av5 !=  jv5) failed (__LINE__);
}

static int av6 = 1106000788;

static struct bt6 {  } dv6 = {  };

static float (*ev6)[0] = (float (*)[0]) 186444415U;

static struct at6 { float bv6; } cv6 = { 59853.900577 };

static int callee_af6( struct bt6 ap6, float (*bp6)[0], ... )
{
    va_list ap;
    typedef struct at6 ad6;
    ad6 fv6;
    va_start (ap, bp6);
    if (ev6 !=  bp6) failed (__LINE__);
    fv6 = va_arg (ap, ad6);
    if (cv6.bv6 !=  fv6.bv6) failed (__LINE__);
    va_end (ap);
    return av6;
}

static void caller_bf6(  )
{
    int gv6;
    gv6 = callee_af6 (dv6, ev6, cv6); if (av6 !=  gv6) failed (__LINE__);
}

static
union bt7 { struct at7 { double av7; char bv7; } cv7; } dv7 =
    { { 47665.248860, '\x41' } };

static
union ft7
{ union dt7 { long long int gv7; } hv7; struct et7 { float iv7; } jv7; }
ov7
=
    { { 545942590L } };

static
struct ht7 { char *kv7; struct gt7 { char lv7; } mv7; long long int nv7; } pv7
=
    { (char *) 1297889645U, { '\x45' }, 1104327802L };

static struct ct7 { int *ev7; } fv7 = { (int *) 1899390613U };

static union bt7 callee_af7( union ft7 ap7, struct ht7 bp7, ... )
{
    va_list ap;
    typedef struct ct7 ad7;
    ad7 qv7;
    va_start (ap, bp7);
    if (ov7.hv7.gv7 !=  ap7.hv7.gv7) failed (__LINE__);
    if (pv7.kv7 !=  bp7.kv7) failed (__LINE__);
    if (pv7.mv7.lv7 !=  bp7.mv7.lv7) failed (__LINE__);
    if (pv7.nv7 !=  bp7.nv7) failed (__LINE__);
    qv7 = va_arg (ap, ad7);
    if (fv7.ev7 !=  qv7.ev7) failed (__LINE__);
    va_end (ap);
    return dv7;
}

static void caller_bf7(  )
{
    union bt7 rv7;
    rv7 = callee_af7 (ov7, pv7, fv7);
    if (dv7.cv7.av7 !=  rv7.cv7.av7) failed (__LINE__);
    if (dv7.cv7.bv7 !=  rv7.cv7.bv7) failed (__LINE__);
}

static
struct bt8 { struct at8 {  } av8; long long int bv8; } cv8 =
    { {  }, 1298525207L };

static
struct it8
{
    float pv8;
    char *qv8;
    struct ht8 { long int rv8; double sv8; unsigned long int tv8; } uv8;
}
vv8
=
    {
        32457.206222,
        (char *) 751974187U,
        { 2086329657L, 3123.418225, 1396389204UL }
    };

static
struct dt8
{ union ct8 { long int dv8; double ev8; double fv8; } gv8; double hv8; }
mv8
=
    { { 1063462940L }, 93231.334614 };

static
struct ft8 { union et8 { float iv8; unsigned long long int jv8; } kv8; } nv8 =
    { { 62072.346320 } };

static struct gt8 { unsigned char lv8; } ov8 = { '\x7a' };

static struct bt8 callee_af8( struct it8 ap8, ... )
{
    va_list ap;
    typedef struct dt8 ad8;
    typedef struct ft8 bd8;
    typedef struct gt8 cd8;
    ad8 wv8;
    bd8 xv8;
    cd8 yv8;
    va_start (ap, ap8);
    if (vv8.pv8 !=  ap8.pv8) failed (__LINE__);
    if (vv8.qv8 !=  ap8.qv8) failed (__LINE__);
    if (vv8.uv8.rv8 !=  ap8.uv8.rv8) failed (__LINE__);
    if (vv8.uv8.sv8 !=  ap8.uv8.sv8) failed (__LINE__);
    if (vv8.uv8.tv8 !=  ap8.uv8.tv8) failed (__LINE__);
    wv8 = va_arg (ap, ad8);
    xv8 = va_arg (ap, bd8);
    yv8 = va_arg (ap, cd8);
    if (mv8.gv8.dv8 !=  wv8.gv8.dv8) failed (__LINE__);
    if (mv8.hv8 !=  wv8.hv8) failed (__LINE__);
    if (nv8.kv8.iv8 !=  xv8.kv8.iv8) failed (__LINE__);
    if (ov8.lv8 !=  yv8.lv8) failed (__LINE__);
    va_end (ap);
    return cv8;
}

static void caller_bf8(  )
{
    struct bt8 zv8;
    zv8 = callee_af8 (vv8, mv8, nv8, ov8);
    if (cv8.bv8 !=  zv8.bv8) failed (__LINE__);
}

static union at9 { long int av9; } bv9 = { 448282545L };

static double kv9[0] = {  };

static
struct ct9 { unsigned long int cv9; union bt9 {  } dv9; } hv9 =
    { 1268369541UL, {  } };

static struct et9 { union dt9 {  } ev9; } iv9 = { {  } };

static
struct gt9 { unsigned int *fv9; union ft9 {  } gv9; } jv9 =
    { (unsigned int *) 2129600504U, {  } };

static union at9 callee_af9( double ap9[0], ... )
{
    va_list ap;
    typedef struct ct9 ad9;
    typedef struct et9 bd9;
    typedef struct gt9 cd9;
    ad9 lv9;
    bd9 mv9;
    cd9 nv9;
    va_start (ap, ap9);
    lv9 = va_arg (ap, ad9);
    mv9 = va_arg (ap, bd9);
    nv9 = va_arg (ap, cd9);
    if (hv9.cv9 !=  lv9.cv9) failed (__LINE__);
    if (jv9.fv9 !=  nv9.fv9) failed (__LINE__);
    va_end (ap);
    return bv9;
}

static void caller_bf9(  )
{
    union at9 ov9;
    ov9 = callee_af9 (kv9, hv9, iv9, jv9);
    if (bv9.av9 !=  ov9.av9) failed (__LINE__);
}

static union at10 {  } av10 = {  };

static char cv10 = '\x65';

static char dv10 = '\x1c';

static int bv10 = 157054077;

static union at10 callee_af10( char ap10, char bp10, ... )
{
    va_list ap;
    typedef int ad10;
    ad10 ev10;
    va_start (ap, bp10);
    if (cv10 !=  ap10) failed (__LINE__);
    if (dv10 !=  bp10) failed (__LINE__);
    ev10 = va_arg (ap, ad10);
    if (bv10 !=  ev10) failed (__LINE__);
    va_end (ap);
    return av10;
}

static void caller_bf10(  )
{ union at10 fv10; fv10 = callee_af10 (cv10, dv10, bv10); }

static
struct at11 { double av11; float bv11; unsigned short int cv11; } dv11 =
    { 76162.033139, 9320.981927, 39504 };

static long long int gv11 = 353840420L;

static struct bt11 { double ev11[1]; } fv11 = { { 22211.564528 } };

static struct at11 callee_af11( long long int ap11, ... )
{
    va_list ap;
    typedef struct bt11 ad11;
    ad11 hv11;
    va_start (ap, ap11);
    if (gv11 !=  ap11) failed (__LINE__);
    hv11 = va_arg (ap, ad11);
    if (fv11.ev11[0] !=  hv11.ev11[0]) failed (__LINE__);
    va_end (ap);
    return dv11;
}

static void caller_bf11(  )
{
    struct at11 iv11;
    iv11 = callee_af11 (gv11, fv11);
    if (dv11.av11 !=  iv11.av11) failed (__LINE__);
    if (dv11.bv11 !=  iv11.bv11) failed (__LINE__);
    if (dv11.cv11 !=  iv11.cv11) failed (__LINE__);
}

static int av12 = 1478899620;

static int ov12 = 650612396;

static int lv12 = 571425009;

static
struct bt12
{ union at12 { unsigned long int bv12; } cv12; float dv12[0]; }
mv12
=
    { { 2111794837UL }, {  } };

static
struct et12
{
    union ct12 { double ev12; float fv12; } gv12;
    union dt12 { unsigned char hv12; double iv12; double jv12; } kv12;
}
nv12
=
    { { 17257.259744 }, { '\x41' } };

static int callee_af12( int ap12, ... )
{
    va_list ap;
    typedef int ad12;
    typedef struct bt12 bd12;
    typedef struct et12 cd12;
    ad12 pv12;
    bd12 qv12;
    cd12 rv12;
    va_start (ap, ap12);
    if (ov12 !=  ap12) failed (__LINE__);
    pv12 = va_arg (ap, ad12);
    qv12 = va_arg (ap, bd12);
    rv12 = va_arg (ap, cd12);
    if (lv12 !=  pv12) failed (__LINE__);
    if (mv12.cv12.bv12 !=  qv12.cv12.bv12) failed (__LINE__);
    if (nv12.gv12.ev12 !=  rv12.gv12.ev12) failed (__LINE__);
    if (nv12.kv12.hv12 !=  rv12.kv12.hv12) failed (__LINE__);
    va_end (ap);
    return av12;
}

static void caller_bf12(  )
{
    int sv12;
    sv12 = callee_af12 (ov12, lv12, mv12, nv12);
    if (av12 !=  sv12) failed (__LINE__);
}

static double av13 = 79027.508908;

static struct bt13 {  } gv13 = {  };

static
struct ct13 { unsigned int dv13; unsigned char ev13; double fv13; } hv13[0] =
    {  };

static
struct at13 { double bv13[2]; } cv13 =
    { { 21663.181261, 78406.230924 } };

static double callee_af13( struct bt13 ap13, struct ct13 bp13[0], ... )
{
    va_list ap;
    typedef struct at13 ad13;
    ad13 iv13;
    va_start (ap, bp13);
    iv13 = va_arg (ap, ad13);
    if (cv13.bv13[1] !=  iv13.bv13[1]) failed (__LINE__);
    if (cv13.bv13[0] !=  iv13.bv13[0]) failed (__LINE__);
    va_end (ap);
    return av13;
}

static void caller_bf13(  )
{
    double jv13;
    jv13 = callee_af13 (gv13, hv13, cv13);
    if (av13 !=  jv13) failed (__LINE__);
}

static short int av14 = 25848;

static unsigned char kv14 = '\x6';

static
struct et14
{ short int gv14; double *hv14; struct dt14 { double iv14; } jv14; }
lv14
=
    { 21025, (double *) 354345342U, { 51101.594829 } };

static struct bt14 { struct at14 {  } bv14; } dv14 = { {  } };

static struct ct14 { float cv14; } ev14 = { 4425.892784 };

static int fv14 = 51928848;

static short int callee_af14( unsigned char ap14, struct et14 bp14, ... )
{
    va_list ap;
    typedef struct bt14 ad14;
    typedef struct ct14 bd14;
    typedef int cd14;
    ad14 mv14;
    bd14 nv14;
    cd14 ov14;
    va_start (ap, bp14);
    if (kv14 !=  ap14) failed (__LINE__);
    if (lv14.gv14 !=  bp14.gv14) failed (__LINE__);
    if (lv14.hv14 !=  bp14.hv14) failed (__LINE__);
    if (lv14.jv14.iv14 !=  bp14.jv14.iv14) failed (__LINE__);
    mv14 = va_arg (ap, ad14);
    nv14 = va_arg (ap, bd14);
    ov14 = va_arg (ap, cd14);
    if (ev14.cv14 !=  nv14.cv14) failed (__LINE__);
    if (fv14 !=  ov14) failed (__LINE__);
    va_end (ap);
    return av14;
}

static void caller_bf14(  )
{
    short int pv14;
    pv14 = callee_af14 (kv14, lv14, dv14, ev14, fv14);
    if (av14 !=  pv14) failed (__LINE__);
}

static int av15 = 1053346906;

static
struct bt15 { char dv15; char ev15[2]; } fv15 =
    { '\x49', { '\x18', '\x6d' } };

static struct at15 { long long int bv15; } cv15 = { 159927280L };

static int callee_af15( struct bt15 ap15, ... )
{
    va_list ap;
    typedef struct at15 ad15;
    ad15 gv15;
    va_start (ap, ap15);
    if (fv15.dv15 !=  ap15.dv15) failed (__LINE__);
    if (fv15.ev15[1] !=  ap15.ev15[1]) failed (__LINE__);
    if (fv15.ev15[0] !=  ap15.ev15[0]) failed (__LINE__);
    gv15 = va_arg (ap, ad15);
    if (cv15.bv15 !=  gv15.bv15) failed (__LINE__);
    va_end (ap);
    return av15;
}

static void caller_bf15(  )
{
    int hv15;
    hv15 = callee_af15 (fv15, cv15); if (av15 !=  hv15) failed (__LINE__);
}

static
struct bt16
{
    long long int *av16;
    union at16 { float bv16; long int cv16; float dv16; } ev16;
    double fv16;
}
gv16
=
    { (long long int *) 1630656096U, { 66623.759278 }, 65979.742636 };

static struct ft16 { double *ov16; } sv16 = { (double *) 199495395U };

static
union gt16 { double pv16; short int qv16; double *rv16; } tv16 =
    { 21555.138224 };

static int lv16 = 12225113;

static
struct dt16 { struct ct16 { double hv16; double iv16; } jv16; } mv16 =
    { { 5266.012127, 12225.672364 } };

static struct et16 { double kv16; } nv16 = { 87040.709543 };

static struct bt16 callee_af16( struct ft16 ap16, union gt16 bp16, ... )
{
    va_list ap;
    typedef int ad16;
    typedef struct dt16 bd16;
    typedef struct et16 cd16;
    ad16 uv16;
    bd16 vv16;
    cd16 wv16;
    va_start (ap, bp16);
    if (sv16.ov16 !=  ap16.ov16) failed (__LINE__);
    if (tv16.pv16 !=  bp16.pv16) failed (__LINE__);
    uv16 = va_arg (ap, ad16);
    vv16 = va_arg (ap, bd16);
    wv16 = va_arg (ap, cd16);
    if (lv16 !=  uv16) failed (__LINE__);
    if (mv16.jv16.hv16 !=  vv16.jv16.hv16) failed (__LINE__);
    if (mv16.jv16.iv16 !=  vv16.jv16.iv16) failed (__LINE__);
    if (nv16.kv16 !=  wv16.kv16) failed (__LINE__);
    va_end (ap);
    return gv16;
}

static void caller_bf16(  )
{
    struct bt16 xv16;
    xv16 = callee_af16 (sv16, tv16, lv16, mv16, nv16);
    if (gv16.av16 !=  xv16.av16) failed (__LINE__);
    if (gv16.ev16.bv16 !=  xv16.ev16.bv16) failed (__LINE__);
    if (gv16.fv16 !=  xv16.fv16) failed (__LINE__);
}

static struct at17 {  } av17 = {  };

static char ev17 = '\x52';

static struct ct17 {  } fv17 = {  };

static struct bt17 { short int *bv17; } cv17 = { (short int *) 1816912139U };

static int dv17 = 532210085;

static struct at17 callee_af17( char ap17, struct ct17 bp17, ... )
{
    va_list ap;
    typedef struct bt17 ad17;
    typedef int bd17;
    ad17 gv17;
    bd17 hv17;
    va_start (ap, bp17);
    if (ev17 !=  ap17) failed (__LINE__);
    gv17 = va_arg (ap, ad17);
    hv17 = va_arg (ap, bd17);
    if (cv17.bv17 !=  gv17.bv17) failed (__LINE__);
    if (dv17 !=  hv17) failed (__LINE__);
    va_end (ap);
    return av17;
}

static void caller_bf17(  )
{ struct at17 iv17; iv17 = callee_af17 (ev17, fv17, cv17, dv17); }

static unsigned int av18 = 2134463441U;

static
struct bt18 { float fv18; unsigned long int gv18; } hv18 =
    { 1704.703936, 1858792936UL };

static int dv18 = 1793268374;

static
struct at18 { double bv18; float *cv18; } ev18 =
    { 27679.962225, (float *) 342664961U };

static unsigned int callee_af18( struct bt18 ap18, ... )
{
    va_list ap;
    typedef int ad18;
    typedef struct at18 bd18;
    ad18 iv18;
    bd18 jv18;
    va_start (ap, ap18);
    if (hv18.fv18 !=  ap18.fv18) failed (__LINE__);
    if (hv18.gv18 !=  ap18.gv18) failed (__LINE__);
    iv18 = va_arg (ap, ad18);
    jv18 = va_arg (ap, bd18);
    if (dv18 !=  iv18) failed (__LINE__);
    if (ev18.bv18 !=  jv18.bv18) failed (__LINE__);
    if (ev18.cv18 !=  jv18.cv18) failed (__LINE__);
    va_end (ap);
    return av18;
}

static void caller_bf18(  )
{
    unsigned int kv18;
    kv18 = callee_af18 (hv18, dv18, ev18);
    if (av18 !=  kv18) failed (__LINE__);
}

static double av19 = 96338.130122;

static union dt19 {  } hv19 = {  };

static struct at19 { unsigned long long int bv19; } ev19 = { 1649370091UL };

static struct bt19 { double *cv19; } fv19 = { (double *) 839317276U };

static
struct ct19 { long long int *dv19; } gv19 =
    { (long long int *) 562586922U };

static double callee_af19( union dt19 ap19, ... )
{
    va_list ap;
    typedef struct at19 ad19;
    typedef struct bt19 bd19;
    typedef struct ct19 cd19;
    ad19 iv19;
    bd19 jv19;
    cd19 kv19;
    va_start (ap, ap19);
    iv19 = va_arg (ap, ad19);
    jv19 = va_arg (ap, bd19);
    kv19 = va_arg (ap, cd19);
    if (ev19.bv19 !=  iv19.bv19) failed (__LINE__);
    if (fv19.cv19 !=  jv19.cv19) failed (__LINE__);
    if (gv19.dv19 !=  kv19.dv19) failed (__LINE__);
    va_end (ap);
    return av19;
}

static void caller_bf19(  )
{
    double lv19;
    lv19 = callee_af19 (hv19, ev19, fv19, gv19);
    if (av19 !=  lv19) failed (__LINE__);
}

static
struct bt20
{ double *av20; struct at20 { long long int bv20; } cv20; double dv20; }
ev20
=
    { (double *) 483520306U, { 1371358188L }, 39821.488694 };

static
struct ct20 { unsigned short int gv20; unsigned int hv20; float iv20; } jv20 =
    { 8440, 355308554U, 56230.621670 };

static int fv20 = 1247466183;

static struct bt20 callee_af20( struct ct20 ap20, ... )
{
    va_list ap;
    typedef int ad20;
    ad20 kv20;
    va_start (ap, ap20);
    if (jv20.gv20 !=  ap20.gv20) failed (__LINE__);
    if (jv20.hv20 !=  ap20.hv20) failed (__LINE__);
    if (jv20.iv20 !=  ap20.iv20) failed (__LINE__);
    kv20 = va_arg (ap, ad20);
    if (fv20 !=  kv20) failed (__LINE__);
    va_end (ap);
    return ev20;
}

static void caller_bf20(  )
{
    struct bt20 lv20;
    lv20 = callee_af20 (jv20, fv20);
    if (ev20.av20 !=  lv20.av20) failed (__LINE__);
    if (ev20.cv20.bv20 !=  lv20.cv20.bv20) failed (__LINE__);
    if (ev20.dv20 !=  lv20.dv20) failed (__LINE__);
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
