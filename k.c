#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#include"k.h"
#define Kx K x
#define Ky K y
C TK(Kx)_(Tk[xt])
N NK(Kx)_(xn)
V*dK(Kx)_(xV)
S V VK(Ct,V*a,Kx){x=cT[t](x);Mc(a,xV,xn*TZ[t]);}

//            constructors                                                  accessors
//    atom                     list                                 atom                 list
K Kc(Cv)_(ac(v))     K KC(C*a,Nn)_(aV(tC,n,a))                   C cK(Kx)_(xv)  V CK(C*a,Kx){VK(tC,a,x);}
K Ks(C*s)_(syP(s))   K KS(C**a,Nn)_(Ax=aS(n);i(n,xi=syP(a[i]))x)
K Ki(Iv)_(az(v))     K KI(I*a,Nn)_(aV(tI,n,a))                   I iK(Kx)_(xv)  V IK(I*a,Kx){VK(tI,a,x);}
K Kf(Dv)_(ad(v))     K KF(D*a,Nn)_(aV(tD,n,a))                   D fK(Kx)_(*xD) V FK(D*a,Kx){VK(tD,a,x);}
K Kp(V*p)_(al((L)p))

K K1(Cv,Kx)_(v1[si(vc,v)](x))
K K2(Cv,Kx,Ky)_(v2[si(vc,v)](x,y))
V KA(Qs,Kx){x=dmd(A(as(syP(s)),oA,av,x),4);if(x)mr(x);}
K KR(V*f,In,C*s)_(ae(f,n))

K ref(Kx)_(xR)
V unref(Kx){mr(x);}
