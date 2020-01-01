#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
#define nxt(x) A(x)[-2]
L mt,mu;S A mx[48];A syml,glb,cn[tn];S cold A em()_(write(1,"oom\n",4);exit(1);0)
S A ma(I b)_(asrt(4<b);P(b>47,em())mu+=1ll<<b;A x=mx[b];P(x,mx[b]=nxt(x);AB(b,x))L i=b+1;W(i<ZZ(mx)&&!mx[i],i++)
 $(i<ZZ(mx),x=mx[i];mx[i]=nxt(x))E(i=max(b,24);V*p=mmap_(0,1L<<i,3,0x22/*anon|priv*/,-1,0);P((L)p<=0,em())mt+=1L<<i;x=(A)(p+ZA))
 W(i>b,i--;A y=mx[i]=(A)(x+(1L<<i));nxt(y)=0)AB(b,x))
S A1(mf,asrt(!pkd(x));asrt(!Ar(x));UC b=xb;nxt(x)=mx[b];mx[b]=x;mu-=1ll<<b;0)A1(mut,P(pkd(x)||Ar(x)==1,x)xr;A y=atnv(xt,xn,xc);$(ref(y),mRa(y))y)
A1(mr,asrt(x);P(pkd(x),0)asrt(Ar(x)>0);$(!--Ar(x),mf(x);$(ref(x),mrn(xn,xa)))0)V mrn(L n,O A*a){F(n,mr(a[i]))}A1(mRa,F(xn,mR(xai))x)
A gkv(A*p)_(A x=*p;asrt(xn==2);P(--Ar(x),*p=mR(xx);mR(xy))mf(x);*p=xx;xy)I sym(A x/*1*/)_(L m=mu-((Ar(x)==1)<<Ab(x));A u=fpa(&syml,str0(x));mu=m;u)
A atn(UC t,L n)_(I b=67-__builtin_clzll((ZA>>3)+(t==tC?n>>3:n));A x=N(ma(b));Ar(x)=1;AN(n,AT(t,x)))
A atnv(UC t,L n,O V*v)_(A u=atn(t,n);mc(uc,v,n*tZ(t));u)A1(ax,Ar(x)>1?Ar(x)--,atn(xt,xn):x)A0(aa0,aa(enl(as(0)),enl(au0)))
A1(a1,atnv(tX,1,A_(x)))A2(a2,atnv(tX,2,A_(x,y)))A3(a3,atnv(tX,3,A_(x,y,z)))A2(aA,atnv(tA,2,A_(x,y)))A2(aa,atnv(ta,2,A_(x,y)))
A aCn(O C*s,L n)_(atnv(tC,n,s))V*mc(V*x,O V*y,L n)_(C*p=x;O C*q=y;F(n,p[i]=q[i])x)A aCm(O C*s,O C*t)_(aCn(s,t-s))V mz(V*x,L n)_(C*p=x;F(n,p[i]=0))
A aCz(O C*s)_(aCn(s,strlen(s)))I memcmp(O V*x,O V*y,L n)_(O C*p=x,*q=y;F(n,I d=*p++-*q++;P(d,d))0)L strlen(O C*x)_(O C*p=x;W(*p,p++)p-x)
S I line(C*p,C*q)_(A x=val(aCm(p,q));P(x,mr(out(x));1)epr();0)S C*skp(C*p)_(W(*p=='/'&&p[1]==10,p+=3;W(*p&&(p[-1]-10||p[-2]-'\\'||p[-3]-10),p++))p)
A1(ldf,x=str0(N(u1c(x)));C*p=xc;W(*p,C*q=p=skp(p);W(*q&&(*q-10||q[1]==32||q[1]=='}'),q++)Nx(line(p,q));p=q+!!*q)xr;au0)
asm(".globl _start\n_start:pop %rdi\nmov %rsp,%rsi\njmp main");
V main(L n,C**a)_(A x=syml=aX(5);F(xn,xai=aCn(&"_xyzo"[i],!!i))glb=aa0();cn[tX]=aX(0);cn[tC]=cn[tc]=ac(32);cn[tL]=cn[tl]=cn[tlx]=al(_0N);
 cn[tI]=cn[ti]=al(_0Ni);cn[tD]=cn[tdx]=ad(_0n);cn[tS]=cn[ts]=as(0);cn[to]=cn[tp]=cn[tq]=cn[tr]=cn[tu]=cn[tv]=cn[tw]=au0;mu=0;
 $(n>1,exit(!ldf(aCz(a[1]))))C b[256];L m=0,k;W(0<(k=read(0,b,256)),C*p=b,*q=p+m,*r=q+k;W(q<r,$(*q==10,line(p,q);p=q+1)q++)mc(b,p,m=q-p));exit(0))
