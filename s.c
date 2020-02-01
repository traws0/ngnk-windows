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
S C*sd_(C*s,D x)_(UL v=*(UL*)&x;I e=v<<1>>53;UL m=v<<12>>12;P(e==2047&&m,MC(s,"0n"))$(v>>63,*s++='-')P(e==2047,MC(s,"0w"))P(!e&&!m,MC(s,"0.0"))
 $(e,m|=1ll<<52)e-=1023+52;I t=0;$(e>0,F(e,$(m>=1ull<<62,t++;m=(m+2)/5)E(m*=2)))E(F(-e,$(m>=1ull<<60,m=(m+1)/2)E(t--;m*=5)))
 W(!(m%10),m/=10;t++)C*r=su(s+1,m);I l=r-s-1;t+=l-1;I d=1;$(0<=t&&t<7,d=t+1;t=0)F(d,$(s==r-1,*s++='0';r++)E(*s=s[1];s++))
 *s++='.';$(s==r,*s++='0')E(s=r)$(t,*s++='e';s=sl_(s,t))s)
S A sd(D v)_(C s[32];aCm(s,sd_(s,v)))
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
