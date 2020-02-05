#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
#define MC(x,y)(mc(x,y,Z(y)-1)+Z(y)-1)
S O H*dt=(H*)"0001020304050607080910111213141516171819202122232425262728293031323334353637383940414243444546474849"
             "5051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899";
S C*S2(C*s,UI x)_(*(H*)s=dt[x];s+2)   S C*s2(C*s,UI x)_(x<10?(*s++='0'+x),s:S2(s,x))     S O UI T2=100;
S C*S4(C*s,UI x)_(S2(S2(s,x/T2),x%T2))S C*s4(C*s,UI x)_(x<T2?s2(s,x):S2(s2(s,x/T2),x%T2))S O UI T4=1e4;
S C*S8(C*s,UI x)_(S4(S4(s,x/T4),x%T4))S C*s8(C*s,UI x)_(x<T4?s4(s,x):S4(s4(s,x/T4),x%T4))S O UI T8=1e8;
S C*SX(C*s,UL x)_(S8(S8(s,x/T8),x%T8))S C*sX(C*s,UL x)_(x<T8?s8(s,x):S8(s8(s,x/T8),x%T8))S O UL TX=1e16;
S C*su(C*s,UL x)_(x<TX?sX(s,x):SX(s4(s,x/TX),x%TX))S C*sl(C*s,L x)_($(x<0,P(x==_0N,MC(s,"0N"))x=-x;*s++='-')su(s,x))
// github.com/ulfjack/ryu (apache2|boost license)
#if defined(__SIZEOF_INT128__)
 S UL msh(UL m,O UL*a,I i)_(__uint128_t g=m;((g**a>>64)+g*a[1])>>(i-64))
 S UL msha(UL m,O UL*a,I i,UL*v,UL*w,I sh)_(*v=msh(m+2,a,i);*w=msh(m-1-sh,a,i);msh(m,a,i))
#else
 S UL shr(UL l,UL h,UI d)_(h<<(64-d)|l>>d)
 S UL mult(UL a,UL b,UL*rh)_(UI al=a,ah=a>>32,bl=b,bh=b>>32,c=(UL)al*bl;UL u=(UI)(c>>32)+(UL)ah*bl,v=(UI)u+(UL)al*bh;
  *rh=(UI)(u>>32)+(UI)(v>>32)+(UL)ah*bh;v<<32|(UI)c)
 S UL msha(UL m,O UL*a,I i,UL*v,UL*w,I sh)_(m>>=1;UL t,l=mult(m,*a,&t),h,m0=t+mult(m,a[1],&h);h+=m0<t;
  UL l2=l+*a,m2=m0+a[1]+(l2<l),h2=h+(m2<m0);*v=shr(m2,h2,i-65);
  $(sh==1,UL l3=l-*a,m3=m0-a[1]-(l3>l),h3=h-(m3>m0);*w=shr(m3,h3,i-65))
  E(UL l3=l+l,m3=m0+m0+(l3<l),h3=h+h+(m3<m0),l4=l3-*a,m4=m3-a[1]-(l4>l3),h4=h3-(m4>m3);*w=shr(m4,h4,i-64))shr(m0,h,i-65))
#endif
S UL I5[667][2],(*P5)[2]=I5+341;S UL addcll(UL x,UL y,UL c,UL*p)_(UL u=x+y+c;*p=u<x||u<y;u) // or __builtin_addcll
SN V shr3(UL*x,UL*y,I d){F(2,x[i]=y[i]>>d|y[i+1]<<(64-d))x[2]=y[2]>>d;}
SN V pws5(UL(*a)[2],I n,L u,L v,L w){UL x[]={u,v,w},y[3],c;F(n,mc(a+i,x+1,16);shr3(y,x,2);c=0;F(3,x[i]=addcll(x[i],y[i],c,&c))$(x[2]>>61,shr3(x,x,1)))}
SN V init(){pws5(I5,P5-I5,0xebd5cf2016a52921,0x4ac7ca59a424c507,0x9558b4661b6565f8);**P5=0;P5[0][1]=1ll<<61;pws5(P5,I5+ZZ(I5)-P5,0,0,1ll<<61);}
S UI dm(UL*p)_(UL x=*p,q=x/10;*p=q;(UI)x-10*(UI)q)S I l10p2(I x)_(x*78913>>18)S I l10p5(I x)_(x*732923>>20)S I p5b(I x)_(x*1217359>>19)
S I mp5(UL x,UI p)_(F(p,UL q=x/5;P((UI)x-5*(UI)q,0)x=q)1)S I mp2(UL x,UI p)_(!(x&((1ll<<p)-1)))
S C*sd(C*s,L d)_(UL x=d,m=x<<12>>12;I e=x<<1>>53;P(m&&e==2047,MC(s,"0n"))$(x>>63,*s++='-')P(e==2047,MC(s,"0w"))P(!m&&!e,MC(s,"0.0"))
 m|=(UL)!!e<<52;e+=!e-1077;I t,ev=!(m&1),h=m<<12||e<-1075,u0=0,w0=0;UL u,v,w;m<<=2;$(!**I5,init())
 $(e>1,t=l10p2( e)-(e>7);u=msha(m,P5[-t],t-e+p5b( t)+125,&v,&w,h);$(t<22,!(m%5)?u0=mp5(m,t):ev?w0=mp5(m-1-h,t):(v-=mp5(m+2,t))))
 E(  t=e+l10p5(-e)-(e<3);u=msha(m,P5[-t],t-e-p5b(-t)+124,&v,&w,h);$(t<e+2,u0=1;ev?w0=h:--v)E$(t<e+63,u0=mp2(m,t-e)))
 $(w0||u0,UC d=0;W((v/=10)>w/10,w0&=!dm(&w);u0&=!d;d=dm(&u);t++)$(w0,W(!dm(&w),u0&=!d;d=dm(&u);t++))$(u0&&d==5&&!(u&1),d=4)u+=d>=5||(u==w&&!(ev||w0)))
 E(UC d=0;W((v/=10)>(w/=10),d=dm(&u);t++)u+=u==w||d>=5)
 s++;I l=su(s,u)-s-1;s[-1]=*s;t+=l;P(0<=t&&t<16,F(min(l,t),s[i]=s[i+1])ms(s+l,t-l,'0');s[t]='.';P(t<l,s+l+1)s[t+1]='0';s+t+2)
 P(-4<t&&t<0,t=-t;F(l+1,s[l+t-i]=s[l-i])s[-1]='0';*s='.';ms(s+1,t-1,'0')+l+t)
 $(l>0,*s++='.';s+=l)P(!t,s)*s++='e';$(t<0,*s++='-';t=-t)s4(s,t))
A1(str0,asrt(xtC);x=room(x,1);xc[xn]=0;x)
A1(str,P(xtl||xtd,UC l=xtl;L v=gl(x);A u=aC(24);AN((l?sl:sd)(uc,v)-uc,u))xtc?enl(x):xts?mR(symstr(gs(x))):xto?fir(AT(tX,x)):
 xtu||xtv?atnv(tC,1+(Av(x)>19)+xtu,(C[]){vc[Av(x)],':',':'}):xtw?atnv(tC,1+(Av(x)>2),(C[]){"'/\\'/\\"[Av(x)],':'}):xtt?kst(x):ea1(str,x))
S A kp(A x,I p)_(x=kst(x);p?apc(cat(ac('('),x),')'):x)S O C esc(C c)_(c?"tnr\"\\"[Ci("\t\n\r\"\\",c)]:'0')
S A1(kr,kp(x,                                    xtq||xtr||xtu||xtv||xtw))
S A1(kl,kp(x,xtX||xtC?xn==1:xtT?xn<=1:xtaA||     xtq||xtr||xtu||xtv||xtw))
S A1(ka,kp(x,xtX||xtC?xn==1:xtT?xn<=1:xtaA||xtp||xtq||               xtw))
A1(kst,P(x==av_plc,aC(0))P(xtl||xtd||xto||xtu||xtv||xtw,str(x))P(xtiI,apc(kst(gL(x)),'i'))P(xtT&&xn==1,cat(ac(','),kr(fir(x))))
 P(xts,x=str(x);C*s=xc;mr(pS(&s));cat(ac('`'),*s?kst(xn-1?x:fir(x)):x))
 P(xtcC,x=enla(x);I b=0,n=xn,m=n+2;F(n,C c=xci,e=esc(c);$(!C3(32,c,126)&&!e,b=1;B)m+=!!e)A z=aC(b?2+2*n:m);C*s=zc;
  $(b,s=MC(s,"0x");F(n,C c=xci;*s++=hex(c>>4&15);*s++=hex(c&15)))E(*s++='"';F(n,C c=esc(xci);$(c,*s++='\\';*s++=c)E(*s++=xci))*s='"')xr;z)
 P(xtT||xtA,K("{$[`X=t:@x;(0x28,0x3b/`k'x),0x29;`S=t;$[#x;,/`k'x;\"0#`\"];`A=t;\"+\",`k@+x;#x;0x20/`k'x;`D=t;\"0#0n\";`L=t;\"!0\";\"???\"]}",x))
 P(xta,A z=gkv(&x);cat(apc(kl(x),'!'),kr(z)))
 P(xtp,A z=xx;xn==3&&(ztv||ztr)&&xy-av_plc&&xz==av_plc?dex(x,cat(kl(mR(xy)),kst(zR))):K("{@[0x3b/x;#*x:`k'. x;0x5b],0x5d}",x))
 P(xtq,K(",/`k'.:",x))P(xtr,cat(ka(fir(AT(tX,x))),kst(aw(Av(x)))))xr;aCz("???"))
A1(out,K("{$[x~(::);x;(`X=@x)&1<#x;1(0x28,0x0a20/`k'x),0x290a;1`k[x],0x0a];x}",x))
