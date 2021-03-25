// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
#include"a.h"
#include<sys/mman.h>
#ifndef MAP_NORESERVE
 #define MAP_NORESERVE 0 //freebsd
#endif

S I nm;S ST{V*p;Ln;}m[8];SN A0(oom,die("oom\n"))
S V*mm(V*p,Nn,If)_(p=mmap(p,n,PROT_READ|PROT_WRITE,MAP_NORESERVE|MAP_PRIVATE|(f<0?MAP_ANON:MAP_FIXED),f,0);
 P((L)p==-1,eo0();(V*)0)P(f>0,p)Y(nm==ZZ(m),die("mmap lmt\n"))*(C*)p=nm;m[nm++]=(TY(m[0])){p,n};p)
S A mu(V*p,Nn)_(munmap(p,n);i(ZZ(m),Y(m[i].p==p,mc(m+i,m+i+1,(--nm-i)*Z m[0]);BR));0)
S A mx(Nn)_(V*p=mm(0,n,-1);P(!p,oom())*(C*)p=0;(A)(p+ZA))
A mf(If,Nn)_(V*p=mm(0,ZP+n,-1);P(!p,0)Ax=(A)(p+ZP);*(C*)p=1;x=AT(tC,AN(n,x));xR;P(!mm(p+ZP,n,f),x(0))x)

#define xX xA[-3]
S Au[35];L mU;S I lck;S A mb(Cb,Ax)_(xX=0;dbg(AN(-1,AT(0,x)));bkt(x)=b;x)V mrn(In,OA*a){i(n,mr(a[i]))}A1(mRa,i(xn,mR(xa))x)
A1(m0,dbg(lck++);Q(x);XP(0)Q(xr>0);P(--xr,0)Cb=bkt(x);P(!b,x=AT(tn,x))xX=u[b];u[b]=(A)xC;Y(xtR,mrn(xn,xA))x)
A1(m1,dbg(lck--);P(!x,0)P(xt==tn,mu(xC-ZP,xn+ZP))dbg(ms(xC,0xab,cap(x));dbg(AN(-1,AT(0,x))));0)A1(mr,m1(m0(x)))
A atn(Ct,Nn)_(Q(!lck);Q(c3(tA,t,tn-1));Q(!_P(t));
 Cb=59-__builtin_clzll(ZA|ZA+n*ZT[t]);P(b>ZZ(u)-2,oom())Ax=u[b];Ii=b;W(!u[i],i++)
 Y(i<ZZ(u)-1,x=u[i];u[i]=xX)E(x=mb(b,mx(ZA<<(i=max(b,24)))))Y(b<i,bkt(x)=b;W(b<i--,u[i]=mb(i,(A)x+(ZA<<i))))
 xr=1;AT(t,AN(n,x)))
A atnv(Ct,Nn,OV*v)_(Ax=atn(t,n);mc(xC,v,n*ZT[t]);x)A1(ax,xr>1?xr--,atn(xt,xn):x)A0(aa0,am(enl(as(0)),enl(au0)))
A1(a1,atnv(tA,1,A(x)))A2(a2,atnv(tA,2,A(x,y)))A3(a3,atnv(tA,3,A(x,y,z)))A2(aM,atnv(tM,2,A(x,y)))A2(am,atnv(tm,2,A(x,y)))
A aCn(OC*s,Nn)_(atnv(tC,n,s))A aCm(OC*s,OC*t)_(aCn(s,t-s))A aCz(OC*s)_(aCn(s,mn(s)))A az(Lv)_(Ct=tZ(v);t==tL?al(v):ai(v))
C tZ(Lv)_(v==(B)v?tB:v==(H)v?tH:v==(I)v?tI:tL)A kv(A*p)_(Ax=*p;Q(xn==2);P(xr>1,--xr;*p=mR(xx);mR(xy))*p=xx;AN(0,x);x(xy))
A1(mut,XP(x)P(xr==1,x)x=x(atnv(xt,xn,xC));Y(xtR,mRa(x))x)
A room(Ax,Nm)_(Q(xtC);Nn=xn;P(xr==1&&n+m<=cap(x),x)Ay=AN(n,aC(n+m));mc(yC,xC,n);x(y))

S C s0[1<<16],*s1=s0+1;C*syp(L*p)_(*p<0?s0-*p:(V*)p)
I syP(OC*s)_(In=mn(s)+1;P(n<6,Lv=0;mc(&v,s,n);v)OC*p=s0+1;W(p<s1,P(!strcmp(p,s),s0-p)p+=mn(p)+1)
 P(s1+n>s0+Z s0,die("syms oom\n"))mc(s1,s,n);s1+=n;s0-s1+n)

S I ln(C*p,C*q)_(Ax=val(aCm(p,q));Y(x,x=out(x))P(x,mr(x);1)epr(0))
S C*skp(C*p)_(W(*p=='/'&&p[1]==10,p+=3;W(*p&&(p[-1]-10||p[-2]-'\\'||p[-3]-10),p++))p)
A1(cmdl,x=N(u1c(x));Ed(!xn||xC[xn-1]-10,x)xC[xn-1]=0;C*p=xC;Y(*p=='#'&&p[1]=='!',p+=2;W(*p&&*p-10,p++))
 W(*p,C*q=p=skp(p);W(*q&&(*q-10||q[1]==32||q[1]=='}'),q++)Nx(ln(p,q));p=q+!!*q)x(au0))
A glb,cns,ce[tn],cn[tn],ci[2][5];C**argv,**env;
V init(In,C**a){argv=a;env=a+n+1;u[ZZ(u)-1]=1;Ax=AN(0,aA(20));glb=aa0();
 i(tS-tA+1,xq(ce[tA+i]=atn(tA+i,0)))xq(ce[tm]=am(aS0,aA0));
 cn[tA]=ce[tA];cn[tC]=ac(32);xq(cn[tB]=cn[tH]=cn[tI]=cn[tL]=al(NL));xq(cn[tD]=ad(ND));cn[tS]=as(0);
 mc(cn+tc,cn+tC,(tS-tC+1)*Z(*cn));i(tn-to,cn[to+i]=au0)
    ci[0][0]=ab(0);    ci[0][1]=ab(1); xq(ci[0][2]=al(WL));xq(ci[0][3]=al(-WL));ci[0][4]=cn[tL];
 xq(ci[1][0]=ad(0));xq(ci[1][1]=ad(1));xq(ci[1][2]=ad(WD));xq(ci[1][3]=ad(-WD));ci[1][4]=cn[tD];
 cns=x;}
I rep()_(S Cb[256];Lm=0,k=read(0,b,256);P(k<0,0)C*p=b,*q=p+m,*r=q+k;W(q<r,Y(*q==10,ln(p,q);p=q+1)q++)mc(b,p,m=q-p);1)
V repl(){W(rep())}

#define _m(x) ((I*)dat(x))[-7]
#define xm _m(x)
#define mms(a...) i(nm,V*p=m[i].p,*q=p+m[i].n;If=!!*(C*)p;a)
#define obs(a...) mms(Ax=(A)p+ZA+ZP*f,y=(A)q;W(x<y,a;x+=cap(x)+ZA))
#define xys(a...) obs(Y(xtR&&xr,i(xn,Ay=xa;a)))
#define hs(x) {mc(s,x,Z(x)-1);s+=Z(x)-1;}
#define hS(x,y) {hs(x);s=sl(s,y);}
#define hb(a...) {Cb[128],*s=b;a;hs("\n\0");write(1,b,s-b);}
C*h8(C*s,Lv)_(i(16,Cc=v>>4*(15-i)&15;*s++="0W"[9<c]+c)s)
A1(hx,hb(s=h8(s,x);hS(" b",bkt(x));Ct=xC[-15];hs(" t");Y(c3(1,t,tn),*s++=TS[t])E(s=sl(s,t))hS(" r",xr);hS("=",xm);hS(" n",xn)
 i(min(5,cap(x)/8),hs(" ");s=h8(s,xl)))x)
A1(cmdm,x(0);obs(xm=0);xys(Y(!ytP,_m(y)++));_m(glb)++;_m(cns)++;
// In=0;obs(hx(x);n++);hb(hS("nObjs:",n))
 hb(hs("cns:");s=h8(s,cns);hs(", glb:");s=h8(s,glb));
// hb(hs("mapped regions:"));mms(hb(s=h8(s,(L)p);hs("-");s=h8(s,(L)q);hS(" F",*(C*)p);hS(" N",q-p)))
 obs(Y(!c3(tA,xt,tn-1)&&(xr||xt),hb(hs("bad type:"));hx(x)));
 obs(Y(xr-xm,hb(hs("bad refc:"));hx(x)));
 xys(Y(!yt,hb(hs("dngl ptr:"));hx(x);hx(y)));
 hb(hs("-----------"));au0)
