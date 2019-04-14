#include<sys/mman.h>
#include"k.h"
#define h(c) {hdr(tC,0,1,1),1,c},
 S I4 symstrs_[]={{hdr(tC,0,1,0),0},h('x')h('y')h('z')h('o')h('p')h('j')h('t')}; //pre-allocated `symbols
#undef h
#define h(i) (I)_A(symstrs_+i),
 S I symlist_[16]={hdr(0,0,0,8),8,h(0)h(1)h(2)h(3)h(4)h(5)h(6)h(7)}; //pre-allocated list of `symbols
#undef h
#define mn 24
S I mt=1L<<mn; //total memory managed by the mm (except pre-allocated objects)
S C mw[1L<<mn]__attribute__((aligned(pagesize))); //initial workspace
A mx[48]={[mn]=mw+ZHdr}; //buckets - mx[i] is a linked list of memory blocks of size 1<<i
A symlist=_A(symlist_); //list of '\0'-terminated strings for `symbols
A mm(I n){V*p=mmap_(0,n,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);$((I)p<0,e("mem"))mt+=n;R p+ZHdr;}
N A ma_(UC b){A x;I i=b+1;W(!((x=mx[i])),$(++i==ZZ(mx),i=max(b,mn);mx[i]=x=mm(1L<<i);B)) //allocate - split larger block
 mx[i]=nxt(x);W(i>b,i--;A y=mx[i]=(V*)x+(1L<<i);nxt(y)=0);R x;}
A ma(I h,I n){UC b=h;A x=mx[b];$(x,mx[b]=nxt(x))E(x=ma_(b))xi[-2]=h;xn=n;R x;} //allocate. h is bucket,type,refcount
N I m_used(){I n=mt;fi(ZZ(mx),A x=mx[i];W(x,n-=1<<i;x=nxt(x)))A y=symlist;n-=1<<yb;fi(yn,A z=yai;n-=1<<zb)R n;}
N V mdAll(A x){fi(xn,md(xai))}
N V miAll(A x){fi(xn,mi(xai))}
v1(mut){$(!xr||(1&(1<<tu|1<<tv|1<<tw)>>xt),R x)A y=atno(xt,xn,Ao(x));memcpy(yc,xc,(xn)*tz(xt));$(isRef(xt),miAll(y))R y;}
v1(mut01){ea(xn==2);$(xr,A y=atn(xt,2);yx=xx;yy=xy;mi(yy);R y)E(mo(xx);R x)} //make a 2-list mutable, make [0] unreffed
v1(mut10){ea(xn==2);$(xr,A y=atn(xt,2);yx=xx;yy=xy;mi(yx);R y)E(mo(xy);R x)} //make a 2-list mutable, make [1] unreffed
A acm(C*p,C*q){I n=q-p;A x=aC(n);memcpy(xc,p,n);R x;} //allocate a char list and fill its content from memory
I symidx(C*p,I n){A x=aC(n+1);--xn;memcpy(xc,p,n);xc[n]=0;R fndpa(&symlist,x);} //intern a `symbol and return its index
V*memcpy(V*x,O V*y,I n){C*p=x;O C*q=y;fi(n,*p++=*q++);R x;}
I strlen(O C*x){O C*p=x;W(*p,p++);R p-x;}
