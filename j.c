#include"k.h" // ngn/k, (c) 2019 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
A1(json,x=str0(x);A y=0,h[16];I n=0;C*s=xc,c; //no validation or error handling
 W((c=*s++),
  $( c=='[',asrt(!y);h[n++]=a0())
  E$(c=='{',asrt(!y);h[n++]=aS(0);h[n++]=a0())
  E$(c==',',asrt( y);h[n-1]=apd(h[n-1],y);y=0)
  E$(c==':',asrt( y);asrt(ytC);h[n-2]=apd(h[n-2],as(sym(y)));y=0)
  E$(c==']',asrt( n);$(y,h[n-1]=apd(h[n-1],y);y=0)y=h[--n])
  E$(c=='}',asrt( n);$(y,h[n-1]=apd(h[n-1],y);y=0)y=aa(h[n-2],h[n-1]);n-=2)
  E$(c=='f',asrt(!y);s+=4;y=al(0))
  E$(c=='t',asrt(!y);s+=3;y=al(1))
  E$(c=='n',asrt(!y);s+=3;y=mR(cn[tl]))
  E$(c=='-'||C3('0',c,'9'),asrt(!y);s--;y=al(pl(&s)))
  E$(c=='"',asrt(!y);y=aC(0);
   W('"'-((c=*s++)),asrt(c);$(c=='\\',c=*s++;C d=0;F(5,$(c=="bfnrt"[i],d="\b\f\n\r\t"[i];c=0;B))c=d;P(!c,yr;ern(n,h)))y=apv(y,&c)))
  E$(c-32&&c-9&&c-10&&c-13,mrn(n,h);$(y,yr)R en(x)))
 asrt(y);asrt(!n);xr;y)
