#include "t.h"

// Test support for up to 8 args
A1(Fadd1,Ki(iK(x)+1))
A2(Fadd2,Ki(iK(x)+iK(y)))
A3(Fadd3,Ki(iK(x)+iK(y)+iK(z)))
A4(Fadd4,Ki(iK(x)+iK(y)+iK(z)+iK(u)))
A5(Fadd5,Ki(iK(x1)+iK(x2)+iK(x3)+iK(x4)+iK(x5)))
A6(Fadd6,Ki(iK(x1)+iK(x2)+iK(x3)+iK(x4)+iK(x5)+iK(x6)))
A7(Fadd7,Ki(iK(x1)+iK(x2)+iK(x3)+iK(x4)+iK(x5)+iK(x6)+iK(x7)))
A8(Fadd8,Ki(iK(x1)+iK(x2)+iK(x3)+iK(x4)+iK(x5)+iK(x6)+iK(x7)+iK(x8)))

// Allocate with a null pointer
A2(FKC0,I n=iK(x);C v=cK(y);K r=KC(0,n);C* a=(C*) r;F(n,a[i]=v);r)
A2(FKI0,I n=iK(x);I v=iK(y);K r=KI(0,n);I* a=(I*) r;F(n,a[i]=v);r)
A2(FKF0,I n=iK(x);F v=fK(y);K r=KF(0,n);F* a=(F*) r;F(n,a[i]=v);r)
A2(FKL0,I n=iK(x);          K r=KL(0,n);K* a=(K*) r;F(n,a[i]=y;ref(y));y(r))

#define REG(a,n) KR(#a,F##a,n);

__attribute__((constructor)) void loadfns();
void loadfns(){REG(add1,1)REG(add2,2)REG(add3,3)REG(add4,4)
               REG(add5,5)REG(add6,6)REG(add7,7)REG(add8,8)
               REG(KC0,2)REG(KI0,2)REG(KF0,2)REG(KL0,2)}
