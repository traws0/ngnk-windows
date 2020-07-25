#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#define MC(x,y) (mc(x,y,Z(y)-1)+Z(y)-1)
S O H*dt=(H*)"0001020304050607080910111213141516171819202122232425262728293031323334353637383940414243444546474849"
             "5051525354555657585960616263646566676869707172737475767778798081828384858687888990919293949596979899";
S C*S2(C*s,UI x)_(*(H*)s=dt[x];s+2)   S C*s2(C*s,UI x)_(x<10?(*s++='0'+x),s:S2(s,x))     S O UI T2=100;
S C*S4(C*s,UI x)_(S2(S2(s,x/T2),x%T2))S C*s4(C*s,UI x)_(x<T2?s2(s,x):S2(s2(s,x/T2),x%T2))S O UI T4=1e4;
S C*S8(C*s,UI x)_(S4(S4(s,x/T4),x%T4))S C*s8(C*s,UI x)_(x<T4?s4(s,x):S4(s4(s,x/T4),x%T4))S O UI T8=1e8;
S C*S0(C*s,UL x)_(S8(S8(s,x/T8),x%T8))S C*sX(C*s,UL x)_(x<T8?s8(s,x):S8(s8(s,x/T8),x%T8))S O UL TX=1e16;
S C*su(C*s,UL x)_(x<TX?sX(s,x):S0(s4(s,x/TX),x%TX))S C*sl(C*s,L x)_(Y(x<0,P(x==_0Nl,MC(s,"0N"))x=-x;*s++='-')su(s,x))
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
  Y(sh==1,UL l3=l-*a,m3=m0-a[1]-(l3>l),h3=h-(m3>m0);*w=shr(m3,h3,i-65))
  E(UL l3=l+l,m3=m0+m0+(l3<l),h3=h+h+(m3<m0),l4=l3-*a,m4=m3-a[1]-(l4>l3),h4=h3-(m4>m3);*w=shr(m4,h4,i-64))shr(m0,h,i-65))
#endif
S UL I5[342][2],P5[326][2];S UL addcll(UL x,UL y,UL c,UL*p)_(UL u=x+y+c;*p=u<x||u<y;u) // or __builtin_addcll
S V shr3(UL*x,UL*y,I d){F(2,x[i]=y[i]>>d|y[i+1]<<(64-d))x[2]=y[2]>>d;}S V shr2(UL*a){*a>>=1;*a|=a[1]<<63;a[1]>>=1;}S V inc2(UL*a){a[1]+=!++*a;}
S V pws5(UL(*a)[2],I n,L u,L v,L w){UL x[]={u,v,w},y[3],c;F(n,mc(a+i,x+1,16);shr3(y,x,2);c=0;F(3,x[i]=addcll(x[i],y[i],c,&c))Y(x[2]>>61,shr3(x,x,1)))}
S V initp5(){pws5(I5,ZZ(I5),0xebd5cf2016a52921,0x4ac7ca59a424c507,0x9558b4661b6565f8);pws5(P5,ZZ(P5),0,0,1ll<<61);
 I5[0][0]=0x0958f94b348498a0;I5[0][1]=0x12ab168cc36cacbf;shr2(I5[1]);shr2(I5[1]);shr2(I5[2]);shr2(I5[3]);F(ZZ(I5),inc2(&I5[i][0]))
 inc2(I5[ZZ(I5)-1]);shr2(P5[0]);}
S UI dm(UL*p)_(UL x=*p,q=x/10;*p=q;(UI)x-10*(UI)q)S I l10p2(I x)_(x*78913>>18)S I l10p5(I x)_(x*732923>>20)S I p5b(I x)_(x*1217359>>19)
S I mp5(UL x,UI p)_(F(p,UL q=x/5;P((UI)x-5*(UI)q,0)x=q)1)S I mp2(UL x,UI p)_(!(x&((1ll<<p)-1)))
S C*sd(C*s,L d)_(UL x=d,m=x<<12>>12;I e=x<<1>>53;P(m&&e==2047,MC(s,"0n"))Y(x>>63,*s++='-')P(e==2047,MC(s,"0w"))P(!m&&!e,MC(s,"0.0"))
 m|=(UL)!!e<<52;e+=!e-1077;I t,ev=!(m&1),h=m<<12||e<-1075,u0=0,w0=0;UL u,v,w;m<<=2;Y(!**I5,initp5())
 Y(e>1,t=l10p2(e)-(e>7);u=msha(m,I5[ZZ(I5)-1-t],t-e+p5b( t)+125,&v,&w,h);Y(t<22,!(m%5)?u0=mp5(m,t):ev?w0=mp5(m-1-h,t):(v-=mp5(m+2,t))))
 E( t=e+l10p5(-e)-(e<3);u=msha(m,P5[        -t],t-e-p5b(-t)+124,&v,&w,h);Y(t<e+2,u0=1;ev?w0=h:--v)EY(t<e+63,u0=mp2(m,t-e)))
 Y(w0||u0,C d=0;W((v/=10)>w/10,w0&=!dm(&w);u0&=!d;d=dm(&u);t++)Y(w0,W(!dm(&w),u0&=!d;d=dm(&u);t++))Y(u0&&d==5&&!(u&1),d=4)u+=d>=5||(u==w&&!(ev||w0)))
 E(C d=0;W((v/=10)>(w/=10),d=dm(&u);t++)u+=u==w||d>=5)
 s++;I l=su(s,u)-s-1;s[-1]=*s;t+=l;
 P(in(t,16),I k=l<t?l:t;mc(s,s+1,k);ms(s+l,'0',t-l);s+=t;*s++='.';s+=l-k;Y(t>=l,*s++='0')s)
 P(-4<t&&t<0,F(l+1,s[l-t-i]=s[l-i])s[-1]='0';*s++='.';ms(s,'0',-t-1)+l-t)
 Y(l>0,*s++='.';s+=l)*s++='e';Y(t<0,t=-t;*s++='-')s4(s,t))
A1(str0,asrt(xtC);x=room(x,1);xc[xn]=0;x)
A1(str,P(xtl||xtd,I l=xtl;L v=gl(x);A u=aC(24);AN((l?sl:sd)(uc,v)-uc,u))P(xts,aCz(syp(gs(x))))
 K("{$[`c=t:@x;,x;`i=t;$`l$x;|/`o`p`q`r`u`v`w=t;`k@x;$'x]}",x))
A1(kst,K("{p:{[a;b;c;x]$[|/a=t:@x;1=#x;|/b=t;2>#x;|/c=t]{0x28,x,0x29}/`k@x};" //p:parenthesize
 "l:p[`X`C;`I`L`D`S]`A`a`q`r`u`v`w;r:p[`;`]`q`r`u`v`w;w:p[`X`C;`I`L`D`S]`A`a`p`q`w;" //l:as left arg, r:as right arg, w:under an adverb
 "$[(|/`X`C`I`L`D`S=t:@x)&1=n:#x;0x2c,r@*x;`X=t;(0x28,0x3b/o'x),0x29;"
   "|/`C`c=t;$[&/</[x</:32 127]|~^(a:0x00090a0d225c)?x;(0x22,/((0x5c,'0x30746e72225c),x)(a,x)?x),0x22;\"0x\",`hex x];"
   "`I=t;$[n;(0x20/$`l$x),\"i\";\"!0i\"];`L=t;$[n;0x20/$x;\"!0\"];`D=t;$[n;0x20/$x;\"0#0n\"];`S=t;$[n;,/o'x;\"0#`\"];`A=t;0x2b,o@+x;"
   "`a=t;l[!x],0x21,r@.:x;`i=t;($x),\"i\";|/`l`d=t;$x;`s=t;0x60,$[*/-1/0x303a415b617b>\\:a:$x;a;(0x3a=*a)*/-1/0x2e3a415b617b>\\:1_a;a;(1=#a)_o@a];"
   "`o=t;*.:x;`p=t;$[$[~3=#a:.:x;0;~|/`v`r=@*a;0;</~[*|.(1+)]'1_a];l[a@1],$*a;@[0x3b/b;#*b:o'a;:;0x5b],0x5d];`q=t;,/o'.:x;`r=t;,/(w;$:)@'.:x;"
   "|/`u`v=t;$[(`u=t)&29=.:x;0x;\":+-*%!&|<>=~,^#_$?@.0123456789\"[i],((`u=t)+19<i:.:x)#0x3a];`w=t;0x272f5c[3!i],(2<i:.:x)#0x3a;\"???\"]}",x))
A1(out,K("{$[x~(::);x;(`X=@x)&1<#x;1(0x28,0x0a20/`k'x),0x290a;1`k[x],0x0a];x}",x))
A1(hex,K("\"0123456789abcdef\"@,/+16 16\\",x))
A1(unh,K("`c$16/+0N 2#0^\"0123456789abcdef\"?_:",x))
