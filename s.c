#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#define Mh(x,y) (Mc(x,y,Z(y)-1)+Z(y)-1)
S O H*dt=(H*)"0001020304050607080910111213141516171819202122232425262728293031323334353637383940414243444546474849"
             "5051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899";
S C*S2(C*s,UI x)_(*(H*)s=dt[x];s+2)   S C*s2(C*s,UI x)_(x<10?(*s++='0'+x),s:S2(s,x))     S O UI T2=100;
S C*S4(C*s,UI x)_(S2(S2(s,x/T2),x%T2))S C*s4(C*s,UI x)_(x<T2?s2(s,x):S2(s2(s,x/T2),x%T2))S O UI T4=1e4;
S C*S8(C*s,UI x)_(S4(S4(s,x/T4),x%T4))S C*s8(C*s,UI x)_(x<T4?s4(s,x):S4(s4(s,x/T4),x%T4))S O UI T8=1e8;
S C*S0(C*s,UL x)_(S8(S8(s,x/T8),x%T8))S C*sX(C*s,UL x)_(x<T8?s8(s,x):S8(s8(s,x/T8),x%T8))S O UL TX=1e16;
S C*su(C*s,UL x)_(x<TX?sX(s,x):S0(s4(s,x/TX),x%TX))C*sl(C*s,Lv)_(I(v<0,P(v==NL,Mh(s,"0N"))v=-v;*s++='-')su(s,v))
// github.com/ulfjack/ryu (apache2|boost license)
#if defined(__SIZEOF_INT128__)
 S UL msh(UL m,O UL*a,Ii)_(__uint128_t g=m;((g**a>>64)+g*a[1])>>(i-64))
 S UL msha(UL m,O UL*a,Ii,UL*v,UL*w,I sh)_(*v=msh(m+2,a,i);*w=msh(m-1-sh,a,i);msh(m,a,i))
#else
 S UL shr(UL l,UL h,UI d)_(h<<(64-d)|l>>d)
 S UL mult(UL a,UL b,UL*rh)_(UI al=a,ah=a>>32,bl=b,bh=b>>32;UL c=(UL)al*bl,u=(UI)(c>>32)+(UL)ah*bl,v=(UI)u+(UL)al*bh;
  *rh=(UI)(u>>32)+(UI)(v>>32)+(UL)ah*bh;v<<32|(UI)c)
 S UL msha(UL m,O UL*a,Ii,UL*v,UL*w,I sh)_(m>>=1;UL t,l=mult(m,*a,&t),h,m0=t+mult(m,a[1],&h);h+=m0<t;
  UL l2=l+*a,m2=m0+a[1]+(l2<l),h2=h+(m2<m0);*v=shr(m2,h2,i-65);
  I(sh==1,UL l3=l-*a,m3=m0-a[1]-(l3>l),h3=h-(m3>m0);*w=shr(m3,h3,i-65))
  E(UL l3=l+l,m3=m0+m0+(l3<l),h3=h+h+(m3<m0),l4=l3-*a,m4=m3-a[1]-(l4>l3),h4=h3-(m4>m3);*w=shr(m4,h4,i-64))shr(m0,h,i-65))
#endif
S UL I5[342][2],P5[326][2];S UL addcll(UL x,UL y,UL c,UL*p)_(UL u=x+y+c;*p=u<x||u<y;u) // or __builtin_addcll
S V shr3(UL*x,UL*y,I d){i(2,x[i]=y[i]>>d|y[i+1]<<(64-d))x[2]=y[2]>>d;}S V shr2(UL*a){*a>>=1;*a|=a[1]<<63;a[1]>>=1;}S V inc2(UL*a){a[1]+=!++*a;}
S V pws5(UL(*a)[2],In,L u,Lv,L w){UL x[]={u,v,w},y[3],c;i(n,Mc(a+i,x+1,16);shr3(y,x,2);c=0;i(3,x[i]=addcll(x[i],y[i],c,&c))I(x[2]>>61,shr3(x,x,1)))}
S V initp5(){pws5(I5,ZZ(I5),0xebd5cf2016a52921,0x4ac7ca59a424c507,0x9558b4661b6565f8);pws5(P5,ZZ(P5),0,0,1ll<<61);
 I5[0][0]=0x0958f94b348498a0;I5[0][1]=0x12ab168cc36cacbf;shr2(I5[1]);shr2(I5[1]);shr2(I5[2]);shr2(I5[3]);i(ZZ(I5),inc2(&I5[i][0]))
 inc2(I5[ZZ(I5)-1]);shr2(P5[0]);}
S UI dm(UL*p)_(UL x=*p,q=x/10;*p=q;(UI)x-10*(UI)q)S I l10p2(I x)_(x*78913>>18)S I l10p5(I x)_(x*732923>>20)S I p5b(I x)_(x*1217359>>19)
S I mp5(UL x,UI p)_(i(p,UL q=x/5;P((UI)x-5*(UI)q,0)x=q)1)S I mp2(UL x,UI p)_(!(x&((1ll<<p)-1)))
S C*sd(C*s,L d)_(UL x=d,m=x<<12>>12;I e=x<<1>>53;P(m&&e==2047,Mh(s,"0n"))I(x>>63,*s++='-')P(e==2047,Mh(s,"0w"))P(!m&&!e,Mh(s,"0.0"))
 m|=(UL)!!e<<52;e+=!e-1077;I t,ev=!(m&1),h=m<<12||e<-1075,u0=0,w0=0;UL u,v,w;m<<=2;I(!**I5,initp5())
 I(e>1,t=l10p2(e)-(e>7);u=msha(m,I5[ZZ(I5)-1-t],t-e+p5b( t)+125,&v,&w,h);I(t<22,!(m%5)?u0=mp5(m,t):ev?w0=mp5(m-1-h,t):(v-=mp5(m+2,t))))
 E( t=e+l10p5(-e)-(e<3);u=msha(m,P5[        -t],t-e-p5b(-t)+124,&v,&w,h);I(t<e+2,u0=1;ev?w0=h:--v)EI(t<e+63,u0=mp2(m,t-e)))
 I(w0||u0,Cd=0;W((v/=10)>w/10,w0&=!dm(&w);u0&=!d;d=dm(&u);t++)I(w0,W(!dm(&w),u0&=!d;d=dm(&u);t++))I(u0&&d==5&&!(u&1),d=4)u+=d>=5||(u==w&&!(ev||w0)))
 E(Cd=0;W((v/=10)>(w/=10),d=dm(&u);t++)u+=u==w||d>=5)
 s++;I l=su(s,u)-s-1;s[-1]=*s;t+=l;
 P(in(t,16),Ik=l<t?l:t;Mm(s,s+1,k);Ms(s+l,'0',max(0,t-l));s+=t;*s++='.';s+=l-k;I(t>=l,*s++='0')s)
 P(-4<t&&t<0,i(l+1,s[l-t-i]=s[l-i])s[-1]='0';*s++='.';Ms(s,'0',-t-1)+l-t)
 I(l>0,*s++='.';s+=l)*s++='e';I(t<0,t=-t;*s++='-')s4(s,t))
A1(str0,Q(xtC);Nn=xn;x=AN(n,room(x,n+1));xC[n]=0;x)
A1(str,Xzd(I d=xtd;Ay=aC(24);AN((d?sd:sl)(yC,gl(x))-yC,y))Xs(Lv=xv;aCz(syp(&v)))Xc(enl(x))XF(kst(x))K("$:'",x))

S A pre(Cc,Ax)_(cat(ac(c),x))A sur(Cc,Ax,Cd)_(apc(pre(c,x),d))S A1(par,sur('(',x,')'))
S A1(raz,rdc(CAT,A(x),1))S I esc(Cc)_(i(6,P(c=="\0\t\n\r\"\\"[i],i))-1)S A1(ek,eac1(x,kst))
S A1(kss,Nn=xn+2;Iv=1;i(xn,I e=esc(xc)>=0;n+=e;v&=e||c3(32,xc,126))P(!v,cat(aCz("0x"),hex(x)))
 Ay=aC(n);C*s=yC;*s++='"';i(xn,Ij=esc(xc);I(j<0,*s++=xc)E(*s++='\\';*s++="0tnr\"\\"[j]))*s++='"';x(y))
S A ksp(Ax,Qp,Qq,Qs)_(Ct=TS[xt];(SC(p,t)?xn==1:SC(q,t)?xn<2:!!SC(s,t))?par(kst(x)):kst(x))
A1(ksl,ksp(x,"AC","BHILDS","Mmqruvw"))A1(ksr,ksp(x,"","","qruvw"))A1(ksw,ksp(x,"AC","BHILDS","Mmpqw"))
A1(kst,P(xtT&&xn==1,pre(',',ksr(fir(x))))XA(par(jc(';',ek(x))))XcC(kss(enla(x)))
 XZD(xn?jc(32,eac1(x,str)):x(aCz(xtD?"0#0n":"!0")))XS(xn?raz(ek(x)):x(aCz("0#`")))XM(pre('+',kst(flp(x))))
 Xm(Ay=kv(&x);cat(apc(ksl(x),'!'),ksr(y)))Xzd(str(x))
 Xs(x=str(x);Iv=1;i(xn,v&=c09(xc)||cAz(xc))I(!v,x=kst(x);I(*xC==',',x=drp(1,x)))pre('`',x))Xo(x(_R(xx)))
 Xp(x=val(x);P(xn-3?0:!SC("vr",TS[_t(xx)])?0:xy-PLH&&xz==PLH,Ay=_R(xy);cat(ksl(y),kst(fir(x))))
    x=ek(x);Nm=_n(xx);x=apc(jc(';',x),']');Q(xr==1);xC[m]='[';x)
 Xq(raz(ek(val(x))))Xr(x=val(x);Ay=_R(xy);cat(ksw(fir(x)),str(y)))Xw(aCn(&"':/:\\:"[xv%3*2],1+xv/3))
 P(x==PLH,oC)Xu(apc(kst(au0^av0^x),':'))Xv(Ay=aCn(vc+xv,1);xv<20?y:apc(y,':'))aCz("???"))
A1(out,P(x==au0,x)dex(v0c(ai(1),xtA&&1<xn?par(jC("\n ",2,ek(xR))):kst(xR)),x))
S C u1(Cc)_(c09(c)?c-'0':cAf(c)?(c|32)-'a'+10:0)
A1(hex,Xc(hex(enl(x)))XC(Ay=aC(2*xn);C*s=yC;S Q h="0123456789abcdef";x2(i(xn,*s++=h[xc>>4];*s++=h[xc&15])y))et1(x))
A1(unh,XC(Nm=xn/2,r=xn%2;El(r,x)Ay=aC(m);x2(i(yn,yc=u1(xC[2*i])<<4|u1(xC[2*i+1]))y))et1(x))
