#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
S Qs;S A0 jv;S C jw()_(W(si(" \n\t\r",*s)<4,++s)*s)S A0(je,0)
S A0(jd,Im=*s=='-';s+=m;Cc=*s++;P(!c09(c),0)Dv=c-'0';W(c09(*s),v*=10;v+=*s++-'0')
 I(*s=='.',s++;D t=1;W(c09(*s),t/=10;v+=(*s++-'0')*t))
 I((*s|32)=='e',s++;s+=*s=='+';L e=pl(&s);D t=10;I(e<0,e=-e;t=.1)P(e>308,0)i(e,v*=t))ad(m?-v:v))
S A1(ju,Iv=0;i(4,UC c=*s++;v=16*v+(c09(c)?c-'0':cAf(c)?(c|32)-'a'+10:99999);P(v<0,s--;0))
 P(v<128,apc(x,v))P(v<2048,x=cts(x,(C[]){192|v>>6,128|63&v},2))x=cts(x,(C[]){224|v>>12,128|63&v>>6,128|63&v},3))
S A0(js,s++;Ax=oC;W(1,Qp=s;UC c=*s++;W(c-'"'&&c-'\\'&&c>31,c=*s++)P(c<32,s--;x(0))x=cts(x,p,s-1-p);P(c=='"',x)c=*s++;
                       Ii=si("\"\\/bfnrtu",c);P(i>8,s--;x(0))x=i<8?apc(x,"\"\\/\b\f\n\r\t"[i]):ju(x);p=s)0)
S A0(ja,s++;Ax=oA;P(jw()==']',s++;x)W(1,xq(Nx(jv()));P(*s==']',s++;x)Nx(*s==',');s++)0)
S A0(jo,s++;Ax=am(oS,oA);Cc=jw();P(c=='}',s++;x)
 W(1,Nx(c=='"');_q(xx,cS(Nx(js())));Nx(jw()==':');s++;_q(xy,Nx(jv()));P(*s=='}',s++;x)Nx(*s==',');s++;c=jw())0)
S A jr(Qp,Lv)_(Cc;W((c=*p++),P(c-*s,0)s++)az(v))S A0(jt,jr("true",1))S A0(jf,jr("false",0))S A0(jN,jr("null",NL))
S A0(jv,Cc=jw();Ii=si("-ftn[{\"",c)*!c09(c);Ax=CH(i,&jd,jf,jt,jN,ja,jo,js,je)();jw();x)
A1(js0,XC(x=str0(x);s=xV;Ay=jv();I(y&&*s,y=y(0))P(!y,eS(x,s-(Q)xV);ep0())x(y))Xc(js0(enl(x)))et1(x))

A1(js1,Xz(Lv=gl(x);Qs=!v?"false":v==1?"true":v==NL?"null":0;s?aCz(s):js1(ad(v)))
 Xd(str(x))Xc(js1(enl(x)))XC(xn-1?kst(x):kst(fir(x)))
 XMT(sur('[',jc(',',N(eac1(x,js1))),']'))Xm(Ay=kv(&x);sur('{',jc(',',N(K("{(`j'x),'\":\",'`j'y}",x,y))),'}'))js1(str(x)))
