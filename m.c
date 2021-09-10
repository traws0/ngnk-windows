// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#include"a.h"
#include<sys/mman.h>
#ifndef MAP_NORESERVE
 #define MAP_NORESERVE 0
#endif
#define xU xC[-16]       //bucket
#define xX xA[-3]        //next
#define xZ ((ZA<<xU)-ZA) //capacity
S I nm;S ST{V*p;Ln;}m[8];SN A0(oom,die("oom\n"))
S V*mm(V*p,Nn,If)_(
 p=mmap(p,n,PROT_READ|PROT_WRITE,MAP_NORESERVE|(f>0&&!p?MAP_SHARED:MAP_PRIVATE)|(p?MAP_FIXED:0)|(f<0?MAP_ANON:0),f,0);
 P((L)p==-1,eo0();(V*)0)P(f>0,p)I(nm==ZZ(m),die("mmap lmt\n"))*(C*)p=nm;m[nm++]=(TY(*m)){p,n};p)
S A mu(V*p,Nn)_(munmap(p,n);i(ZZ(m),B(m[i].p==p,Mc(m+i,m+i+1,(--nm-i)*SZ m[0])));0)
S A mx(Nn)_(V*p=mm(0,n,-1);P(!p,oom())*(C*)p=0;(A)(p+ZA))
A mf(If,Nn)_(V*p=mm(0,ZP+n,-1);P(!p,0)Ax=(A)(p+ZP);*(C*)p=1;x=AT(tC,AN(n,x));xR;P(!mm(p+ZP,n,f),x(0))x)
V mw(If,Nn,Qs){ftruncate(f,n);V*p=mmap(0,n,PROT_READ|PROT_WRITE,MAP_SHARED,f,0);Mc(p,s,n);mu(p,n);}

S Az[SZ(N)==4?27:35];S I lck;
S A mb(Cb,Ax)_(xX=0;xr=0;DBG(AN(-1,AT(0,x)));xU=b;x)V mrn(Nn,OA*a){i(n,mr(a[i]))}A1(mRa,i(xn,_R(xa))x)
A1(m0,DBG(lck++);Q(x);XP(0)Q(xr>0);P(--xr,0)Cb=xU;P(!b,x=AT(tn,x))xX=z[b];z[b]=(A)xV;XR(mrn(xn,xA);x)x)
A1(m1,DBG(lck--);P(!x,0)P(xt==tn,mu(xV-ZP,xn+ZP))DBG(Ms(xV,0xab,xZ);DBG(AN(-1,AT(0,x))));0)A1(mr,m1(m0(x)))
A atn(Ct,Nn)_(Q(!lck);Q(c3(tA,t,tn-1));Q(!_tP(t));Cb=59-__builtin_clzll(ZA|ZA-1+n*TZ[t]);P(n>1ull<<ZZ(z)||b>ZZ(z)-2,oom())
 Ax=z[b];Ii=b;W(!z[i],i++)I(i<ZZ(z)-1,x=z[i];z[i]=xX)E(x=mb(b,mx(ZA<<(i=max(b,24)))))
 I(b<i,xU=b;W(b<i--,z[i]=mb(i,(A)x+(ZA<<i))))xr=1;AT(t,AN(n,x)))
A aV(Ct,Nn,OV*v)_(Ax=atn(t,n);Mc(xV,v,n*TZ[t]);x)A1(ax,xr>1?xr--,atn(xt,xn):x)A0(aa0,am(enl(as(0)),enl(au)))
A1(a1,aV(tA,1,A(x)))A2(a2,aV(tA,2,A(x,y)))A3(a3,aV(tA,3,A(x,y,z)))A2(aM,aV(tM,2,A(x,y)))A2(am,aV(tm,2,A(x,y)))
AL(aA,atn(tA,n))AL(aC,atn(tC,n))AL(aI,atn(tI,n))AL(aL,atn(tL,n))AL(aD,atn(tD,n))AL(aS,atn(tS,n))
A ac(Cv)_(AT(tc,v))A ai(Iv)_(AT(ti,v))A as(Iv)_(AT(ts,v))A al(Lv)_(aV(tl,1,&v))A ad(Dv)_(aV(td,1,&v))
A aCn(Qs,Nn)_(aV(tC,n,s))A aCm(Qp,Qq)_(aCn(p,q-p))AQ(aCz,aCn(s,Sn(s)))AQ(aCl,Qq=SC(s,10);q?aCm(s,q):aCz(s))
C tZ(Lv)_(v==(B)v?tB:v==(H)v?tH:v==(I)v?tI:tL)A kv(A*p)_(Ax=*p;Q(xn==2);P(xr>1,--xr;*p=_R(xx);_R(xy))*p=xx;AN(0,x);x(xy))
AL(az,n-(I)n?al(n):ai(n))A1(mut,XP(x)P(xr==1,x)x=x(aV(xt,xn,xV));XR(mRa(x))x)
ALA(room,P(xr==1&&n*xW<=xZ,AN(n,x))Ay=atn(xt,n);Mc(yV,xV,xn*xW);I(ytR,I(xr==1,AN(0,x))E(i(xn,_R(ya))))x(y))
L gl_(Ax)_(XP((I)x)*xL)L gl(Ax)_(Lv=gl_(x);x(0);v)D gd(Ax)_(Dv=*xD;x(0);v)

S B s0[1<<16],*s1=s0+1;C*syp(L*p)_(*p<0?s0-*p:(V*)p)
AQ(syP,In=Sn(s)+1;P(n<6&&(n<5||!(s[3]&128)),Lv=0;Mc(&v,s,n);as(v))Qp=s0+1;W(p<s1,P(!SQ(p,s),as(s0-p))p+=Sn(p)+1)
 P(s1+n>s0+SZ s0,die("syms oom\n"))Mc(s1,s,n);s1+=n;as(s0-s1+n))

S Q skp(Qs)_(W(!MQ(s,"/\n",2),Qp=SS(s+1,"\n\\\n");s=p?p+3:s+Sn(s))s)S I ln(Q,Q);S AQ(cmd_,en0())S AQ(cmdX,exit(0);0)
S AQ(cmdt,Ln=*s==':'?++s,pl(&s):1,t=now();Ax=N(cpl(N(prs(aCl(s)))));i(n,mr(Nx(app(x,0,0))))x(az((now()-t+500)/1000)))
AQ(cmdl,Ax=N(u1c(aCl(s)));Ed(!xn||xC[xn-1]-10,x)xC[xn-1]=0;Qp=xV;I(!MQ(p,"#!",2),p=SC0(p+2,10))
 W(*p,Qq=p=skp(p);W(*q&&(*q-10||si(" }",q[1])<2),q++)Nx(ln(p,q));p=q+!!*q)x(au))
A evs(Qs,Qq)_(P(*s-'\\',val(aCm(s,q)))Cc=s[1],d=s[2];P(c=='c'&&d=='d'&&SC("\n :",s[3]),cmdcd(s+3))
 P(SC("\n :",d),CH(si("ltm\\",c),&cmdl,cmdt,cmdm,cmdX,cmd_)(s+2+(d==32)))K("0x0a\\`x(,,\"/bin/sh\"),,:",aCl(s+1)))
S I ln(Qp,Qq)_(Ax=evs(p,q);x=x?out(x):0;x?x(1):epr(0))

A glb,cns,ce[tn],cn[tn],ci[2][5];Q*argv,*env;
I rep()_(Cb[256];Ln=read(0,b,SZ(b)-1);P(n<0,0)b[n]=0;Qp=b;W(*p,Qq=SC0(p,10);ln(p,q);p=q+1)1)I repl()_(W(rep());0)
V kinit(In,O char**a){argv=(Q*)a;env=(Q*)a+n+1;z[ZZ(z)-1]=1;Ax=AN(0,aA(32));glb=aa0();
 i(tS-tA+1,xq(ce[tA+i]=atn(tA+i,0)))xq(ce[tm]=am(oS,oA));
 cn[tA]=ce[tC];xq(cn[tB]=cn[tH]=cn[tI]=cn[tL]=al(NL));xq(cn[tD]=ad(ND));cn[tC]=ac(32);cn[tS]=as(0);
 Mc(cn+ti,cn+tI,(tS-tI+1)*SZ(A));i(tn-to,cn[to+i]=au)
    ci[0][0]=ai(0);    ci[0][1]=ai(1); xq(ci[0][2]=al(WL));xq(ci[0][3]=al(-WL));ci[0][4]=cn[tL];
 xq(ci[1][0]=ad(0));xq(ci[1][1]=ad(1));xq(ci[1][2]=ad(WD));xq(ci[1][3]=ad(-WD));ci[1][4]=cn[tD];cns=x;}

#define _m(x) ((I*)_V(x))[-7]
#define xm _m(x)
#define mms(a...) i(nm,V*p=m[i].p,*q=p+m[i].n;If=!!*(C*)p;a)
#define obs(a...) mms(Ax=(A)p+ZA+ZP*f,y=(A)q;W(x<y,a;x+=xZ+ZA))
#define xys(a...) obs(I(xtR&&xr,i(xn,Ay=xa;a)))
#define hs(x) {Mc(s,x,SZ(x)-1);s+=SZ(x)-1;}
#define hS(x,y) {hs(x);s=sl(s,y);}
#define hb(a...) {Cb[128],*s=b;a;hs("\n\0");write(1,b,s-b);}
C*h8(C*s,Lv)_(i(16,Cc=v>>4*(15-i)&15;*s++="0W"[9<c]+c)s)
A1(hx,hb(s=h8(s,x);hS(" U",xU);Ct=xC[-15];hs(" t");I(c3(1,t,tn),*s++=TS[t])E(s=sl(s,t))
 hS(" r",xr);hS("=",xm);hS(" n",xn)i(min(5,xZ/8),hs(" ");s=h8(s,xl)))x)
AQ(cmdm,obs(xm=0);xys(I(!ytP,_m(y)++));_m(glb)++;_m(cns)++;
// In=0;obs(hx(x);n++);hb(hS("nObjs:",n))
// hb(hs("cns:");s=h8(s,cns);hs(", glb:");s=h8(s,glb));
// hb(hs("mapped regions:"));mms(hb(s=h8(s,(L)p);hs("-");s=h8(s,(L)q);hS(" F",*(C*)p);hS(" N",q-p)))
 obs(I(!c3(tA,xt,tn-1)&&xr,hb(hs("bad type:"));hx(x)));
 obs(I(xr-xm,hb(hs("bad refc:"));hx(x)));
 xys(I(!yt,hb(hs("dngl ptr:"));hx(x);hx(y)));au)
