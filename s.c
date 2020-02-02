#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
S O H*dt=(H*)"0001020304050607080910111213141516171819202122232425262728293031323334353637383940414243444546474849"
             "5051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899";
S C*S2(C*s,UI x)_(*(H*)s=dt[x];s+2)   S C*s2(C*s,UI x)_(x<10?(*s++='0'+x),s:S2(s,x))     S O UI T2=100;
S C*S4(C*s,UI x)_(S2(S2(s,x/T2),x%T2))S C*s4(C*s,UI x)_(x<T2?s2(s,x):S2(s2(s,x/T2),x%T2))S O UI T4=1e4;
S C*S8(C*s,UI x)_(S4(S4(s,x/T4),x%T4))S C*s8(C*s,UI x)_(x<T4?s4(s,x):S4(s4(s,x/T4),x%T4))S O UI T8=1e8;
S C*SX(C*s,UL x)_(S8(S8(s,x/T8),x%T8))S C*sX(C*s,UL x)_(x<T8?s8(s,x):S8(s8(s,x/T8),x%T8))S O UL TX=1e16;
                                      S C*su(C*s,UL x)_(x<TX?sX(s,x):SX(s4(s,x/TX),x%TX))
#define MC(x,y)(mc(x,y,Z(y)-1)+Z(y)-1)
S C*sl_(C*s,L x)_($(x<0,P(x==_0N,MC(s,"0N"))x=-x;*s++='-')su(s,x))S A sl(L v)_(C s[20];aCm(s,sl_(s,v)))

// github.com/ulfjack/ryu (apache2|boost license)
#if defined(__SIZEOF_INT128__)
 S UL msh(UL m,O UL*a,I j)_(__uint128_t g=m;((g**a>>64)+g*a[1])>>(j-64))
 S UL msha(UL m,O UL*a,I j,UL*v,UL*w,UI sh)_(*v=msh(m+2,a,j);*w=msh(m-1-sh,a,j);msh(m,a,j))
#else
 S UL shr(UL l,UL h,UI d)_(h<<(64-d)|l>>d)
 S UL mult(UL a,UL b,UL*rh)_(UI al=a,ah=a>>32,bl=b,bh=b>>32;UL b00=(UL)al*bl,b01=(UL)al*bh,b10=(UL)ah*bl,b11=(UL)ah*bh;
  UI b00l=b00,b00h=b00>>32;UL m1=b10+b00h;UI m1l=m1,m1h=m1>>32;UL m2=b01+m1l;UI m2l=m2,m2h=m2>>32;*rh=b11+m1h+m2h;(UL)m2l<<32|b00l)
 S UL msha(UL m,O UL*a,I j,UL*v,UL*w,UI sh)_(m>>=1;UL t;UL l=mult(m,*a,&t);UL h;UL m0=t+mult(m,a[1],&h);h+=m0<t;
  UL l2=l+*a,m2=m0+a[1]+(l2<l),h2=h+(m2<m0);*v=shr(m2,h2,j-65);
  $(sh==1,UL l3=l-*a,m3=m0-a[1]-(l3>l),h3=h-(m3>m0);*w=shr(m3,h3,j-65))
  E(UL l3=l+l,m3=m0+m0+(l3<l),h3=h+h+(m3<m0),l4=l3-*a,m4=m3-a[1]-(l4>l3),h4=h3-(m4>m3);*w=shr(m4,h4,j-64))
  shr(m0,h,j-65))
#endif
S UL addcll(UL x,UL y,UL c,UL*p)_(UL u=x+y+c;*p=u<x||u<y;u) // or __builtin_addcll
S UL POW5[326][2],INV5[342][2];S V set3(UL*x,O UL*y){mc(x,y,24);}S V shr3(UL*x,I d){F(2,x[i]=x[i]>>d|x[i+1]<<(64-d))x[2]>>=d;}
S V add3(UL*x,O UL*y){UL c=0;F(3,x[i]=addcll(x[i],y[i],c,&c));}S V ash3(UL*x,I d){UL y[3];set3(y,x);shr3(y,d);add3(x,y);}
SN V init(){UL x[]={[2]=1ll<<60};F(ZZ(POW5),mc(POW5+i,x+1,16);ash3(x,2);$(x[2]>>61&1,shr3(x,1)))
 *x=0;x[1]=1;x[2]=1ll<<61;F(ZZ(INV5),mc(INV5+i,x+1,16);ash3(x,1);Fj(4,ash3(x,4<<j))UL y[3]={x[1],x[2]};add3(x,y);
                                     *y=x[2];y[1]=0;add3(x,y);W(x[2]>>61,shr3(x,1)))}
S UI dm(UL*p)_(UL x=*p,q=x/10;*p=q;(UI)x-10*(UI)q)S UI l10p2(I x)_(x*78913>>18)S UI l10p5(I x)_(x*732923>>20)S I p5b(I x)_(x*1217359>>19)
S I mp5(UL x,UI p)_(F(p,UL q=x/5;P((UI)x-5*(UI)q,0)x=q)1)S I mp2(UL x,UI p)_(!(x&((1ll<<p)-1)))
S C*sd_(C*s,D x)_(UL b;mc(&b,&x,8);UL m=b<<12>>12;I e=b<<1>>53;P(m&&e==2047,MC(s,"0n"))$(b>>63,*s++='-')P(e==2047,MC(s,"0w"))
 m|=(UL)!!e<<52;e+=!e-1075;P(!m||(e<1&&e>-53&&mp2(m,-e)),MC(sX(s,m>>-e),".0")) // m*2^e = u*10^t
 UL u;I t;I ev=!(m&1);UI h=m<<12||e<-1073;UL v,w;I u0=0,w0=0;m<<=2;$(!INV5[1][0],init())
 $(e>1,t=l10p2(e-2)-(e>5);u=msha(m,INV5[ t],t-e+p5b( t)+127,&v,&w,h);$(t<22,!(m%5)?u0=mp5(m,t):ev?w0=mp5(m-1-h,t):(v-=mp5(m+2,t))))
 E(t=e-2+l10p5(2-e)-(e<1);u=msha(m,POW5[-t],t-e-p5b(-t)+126,&v,&w,h);$(t<e,u0=1;ev?w0=h:--v)E$(t<e+61,u0=mp2(m,t-e+2)))
 $(w0||u0,UC d=0;W((v/=10)>w/10,w0&=!dm(&w);u0&=!d;d=dm(&u);t++)$(w0,W(!dm(&w),u0&=!d;d=dm(&u);t++))$(u0&&d==5&&!(u&1),d=4)u+=d>=5||(u==w&&!(ev||w0)))
 E(UC d=0;W((v/=10)>(w/=10),d=dm(&u);t++)u+=u==w||d>=5)
 s++;UI l=su(s,u)-s;s[-1]=*s;$(l>1,*s='.';s+=l)t+=l-1;P(!t,s)*s++='e';$(t<0,*s++='-';t=-t)s4(s,t))
S A sd(D v)_(A u=aC(24);AN(sd_(uc,v)-uc,u))

A1(str0,asrt(xtC);x=room(x,1);xc[xn]=0;x)
A1(str,xtc?enl(x):xts?mR(symstr(gs(x))):xtl?sl(gl(x)):xtd?sd(gd(x)):xto?fir(AT(tX,x)):
 xtu||xtv?atnv(tC,1+(Av(x)>19)+xtu,(C[]){vc[Av(x)],':',':'}):xtw?atnv(tC,1+(Av(x)>2),(C[]){"'/\\'/\\"[Av(x)],':'}):xtt?kst(x):ea1(str,x))
S A kp(A x,I p)_(x=kst(x);p?apc(cat(ac('('),x),')'):x)S O C esc(C c)_(c?"tnr\"\\"[Ci("\t\n\r\"\\",c)]:'0')
S A1(kr,kp(x,                                    xtq||xtr||xtu||xtv||xtw))
S A1(kl,kp(x,xtX||xtC?xn==1:xtT?xn<=1:xtaA||     xtq||xtr||xtu||xtv||xtw))
S A1(ka,kp(x,xtX||xtC?xn==1:xtT?xn<=1:xtaA||xtp||xtq||               xtw))
A1(kst,P(x==av_plc,aC(0))P(xtl||xtd||xto||xtu||xtv||xtw,str(x))P(xtiI,apc(kst(gL(x)),'i'))P(xtT&&xn==1,cat(ac(','),kr(fir(x))))
 P(xts,x=str(x);C*s=xc;mr(pS(&s));cat(ac('`'),*s?kst(xn-1?x:fir(x)):x))
 P(xtcC,x=enla(x);I b=0,n=xn,m=n+2;F(n,C c=xci,e=esc(c);$(!C3(32,c,126)&&!e,b=1;B)m+=!!e)A z=aC(b?2+2*n:m);C*s=zc;
  $(b,*s='0';s[1]='x';s+=2;F(n,C c=xci;*s++=hex(c>>4&15);*s++=hex(c&15)))E(*s++='"';F(n,C c=esc(xci);$(c,*s++='\\';*s++=c)E(*s++=xci))*s='"')xr;z)
 P(xtT||xtA,K("{$[`X=t:@x;(0x28,0x3b/`k'x),0x29;`S=t;$[#x;,/`k'x;\"0#`\"];`A=t;\"+\",`k@+x;#x;0x20/`k'x;`D=t;\"0#0n\";`L=t;\"!0\";\"???\"]}",x))
 P(xta,A z=gkv(&x);cat(apc(kl(x),'!'),kr(z)))
 P(xtp,A z=xx;xn==3&&(ztv||ztr)&&xy-av_plc&&xz==av_plc?dex(x,cat(kl(mR(xy)),kst(zR))):K("{@[0x3b/x;#*x:`k'. x;0x5b],0x5d}",x))
 P(xtq,K(",/`k'.:",x))P(xtr,cat(ka(fir(AT(tX,x))),kst(aw(Av(x)))))xr;aCz("???"))
A1(out,K("{$[x~(::);x;(`X=@x)&1<#x;1(0x28,0x0a20/`k'x),0x290a;1`k[x],0x0a];x}",x))
