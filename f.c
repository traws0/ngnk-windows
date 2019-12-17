#include"k.h" // ngn/k, (c) 2019 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
//prng: xoshiro256+ (public domain) http://vigna.di.unimi.it/xorshift/
//seeded with bits from the central column of rule30, little-endian:  2/|+0N 64#{x n}'(n-1){(|(8#2)\30)@2/(0,-1_x;x;1_x,0)}\n=!1+2*n:256
SI UL rotl(UL x,I k)_(x<<k|x>>(64-k))
S A rndn(L n,L m)_(S UL a=-3050759188708220101,b=1159352424775454479,c=-9080974122485750305,d=-388592090067015233;
 $(n==_0N,n=-m)A x=aL(llabs(n));F(n,xli=a+d;O UL t=b<<17;c^=a;d^=b;b^=c;a^=d;c^=t;d=rotl(d,45))$(m&(m-1),F(xn,xli=(UL)xli%m))E$(m,F(xn,xli&=m-1))
 $(n<0,n=-n;P(n>m,el(x))F(n,L k=m-n+i;L v=((UL*)xl)[i]%=k+1;Fj(i,$(xlj==v,xli=k;B)))A y=rndn(n,0);F(n,L j=(UL)yli%(i+1);swp(xli,xlj))yr)x)
S A2(rnd,L n=gl(x);P(ytl,rndn(n,gl(y)))P(ytc,C c=gc(y);P('a'-(32|c),ed())
 A z=rndn(n,26),u=aC(n);F(n,uci=c+zli)zr;u)P(ytT,idx(y,Ny(rndn(n,yn))))et(y))
S L fnda(A x,A y/*0*/)_(asrt(xtX); F(xn,P(mtc_(xai,y),i))_0N)L fndpa(A*p,A v)_(A x=*p;L n=xn;F(n,P(mtc_(xai,v),mr(v),i))*p=apd(x,v);n)
S L fndc(A x,C v)_(asrt(tz(xt)==0);F(xn,P(xci==v,i))_0N)     L fndpc(A*p,C v)_(A x=*p;L n=xn;F(n,P(xci==v,i))*p=apv(x,&v);n)
  L fndl(A x,L v)_(asrt(tz(xt)==3);F(xn,P(xli==v,i))_0N)     L fndpl(A*p,L v)_(A x=*p;L n=xn;F(n,P(xli==v,i))*p=apv(x,&v);n)
A2(fnd,P(xtt,P(xtl,rnd(x,y))P(xts,C*s=C(symstr(gs(x)));*s=='j'&&!s[1]?json(y):ed(y))et(x,y))P(xta,A z=gkv(&x);idx(x,fnd(z,y)))P(xtA,en(x,y))
 P(ytt,fir(fnd(x,enl(y))))P(!xtX&&ytX,ear(cV('?'),A_(x,y),2))P(!xtX&&yt-xt,xr;rsh(len(y),mR(cn[tl])))
 A u=aL(yn);Y(tz(xt),UR,Q(ZR,F(un,A z=get(y,i);uli=fnda(x,z);zr))Q(0,F(un,uli=fndc(x,yci)))Q(3,F(un,uli=fndl(x,yli))))xr;yr;u)
