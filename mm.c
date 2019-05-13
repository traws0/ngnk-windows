#include<sys/mman.h>
#include"k.h"
#define mn 24
S I mt=1L<<mn; //total memory managed (except pre-allocated objects)
S C mw[1L<<mn]__attribute__((aligned(pagesize))); //initial workspace
A mx[48]={[mn]=mw+ZHdr}; //buckets - mx[i] is a linked list of memory blocks of size 1<<i
A symlist=csymlist; //list of '\0'-terminated strings for `symbols
A mm(I n){V*p=mmap_(0,n,PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);$((I)p<0,e("mem"))mt+=n;R p+ZHdr;}
N A ma_(UC b){A x;I i=b+1;W(!((x=mx[i])),$(++i==ZZ(mx),i=max(b,mn);mx[i]=x=mm(1L<<i);B)) //allocate - split larger block
 mx[i]=nxt(x);W(i>b,i--;A y=mx[i]=(V*)x+(1L<<i);nxt(y)=0);R x;}
A ma(I h,I n){UC b=h;A x=mx[b];$(x,mx[b]=nxt(x))E(x=ma_(b))xi[-2]=h;xn=n;R x;} //allocate. h is bucket,type,refcount
N I m_used(){I n=mt;fi(ZZ(mx),A x=mx[i];W(x,n-=1<<i;x=nxt(x)))A y=symlist;n-=1<<yb;fi(yn,A z=yai;n-=1<<zb)R n;}
N V mdAll(A x){fi(xn,md(xai))}
N V miAll(A x){fi(xn,mi(xai))}
v1(mut){$(!xr||(1&(1<<tu|1<<tv|1<<tw)>>xt),R x)A y=atno(xt,xn,Ao(x));memcpy(yc,xc,(xn)*tz(xt));$(isRef(xt),miAll(y))R y;}
v1(mut10){asrt(xn==2);$(xr,A y=atn(xt,2);yx=xx;yy=xy;mi(yx);R y)E(mo(xy);R x)} //make a 2-list mutable and unref x[1]
A acm(C*p,C*q){I n=q-p;A x=aC(n);memcpy(xc,p,n);R x;} //allocate a char list and fill its content from memory
I sym(C*p,I n){A x=aC(n+1);--xn;memcpy(xc,p,n);xc[n]=0;R fndpa(&symlist,x);} //intern a `symbol and return its index
V*memcpy(V*x,O V*y,I n){C*p=x;O C*q=y;fi(n,*p++=*q++);R x;}
I strlen(O C*x){O C*p=x;W(*p,p++);R p-x;}
