#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - http://bitbucket.org/ngn/k/raw/master/LICENSE
I mtc_(A x,A y/*x0y0*/)_(P(x==y,1)P(xt-yt||pkd(x)||xn-yn||(xtr&&Av(x)-Av(y)),0)P(!ref(x),!memcmp(xc,yc,xn*tZ(xt)))F(xn,P(!mtc_(xai,yai),0))1)
S I cmp_(A x,A y/*x0y0*/)_(P(x==y,0)I d=xt-yt;P(d,d)P(pkd(x),x>y?1:-1)L n=min(xn,yn);I r=(xn>yn)-(xn<yn);
 P(ref(x)   ,F(n,I d=cmp_(xai,yai);P(d,d))r)
 P(xtdD     ,F(n,D u=xdi,v=ydi;P(u!=v,u<v?-1:1))r)
 P(xtS      ,F(n,L u=xli,v=yli;P(u-v,cmp_(symstr(u),symstr(v))))r)
 P(tz(xt)==3,F(n,L u=xli,v=yli;P(u-v,u<v?-1:1))r)
 P(tz(xt)==0,F(n,C u=xci,v=yci;P(u-v,u<v?-1:1))r)UR;0)
S L bef(A*a,L i,L j,I d)_(L r=cmp_(a[i],a[j]);r?d*r<0:i<j)
S V sft(A*a,L*l,L i,L j,I d)_(W(1,L k=1+2*i;$(k>j,B)$(k+1<=j&&bef(a,l[k],l[k+1],d),k++)$(!bef(a,l[i],l[k],d),B)swp(l[i],l[k])i=k))
S A grd(A x/*1*/,I d)_(P(xtX,d=d?-1:1;A*a=xa,u=til(al(xn));L*l=ul,n=xn,i=n/2;W(i-->0,sft(a,l,i,n-1,d))i=n-1;W(i>0,swp(l[i],*l)sft(a,l,0,--i,d))xr;u)
 $(xtL||xtD,L n=xn;A y=ax(x);$(d,L m=_0N;F(n,$(xli>m,m=xli))F(n,yli=m-xli))E(L m=_0W;F(n,$(xli<m,m=xli))F(n,yli=xli-m))x=y;
  UC*a=(UC*)C(y=aC(n*Z(*a)));A z=aL(n),u=aL(n);L nc=1+(1<<8*Z(*a));L c[nc];mz(c,8*nc);
  F(n,a[i]=xli)F(n,c[a[i]+1]++)F((1<<8*Z(*a))-1,c[i+1]+=c[i])F(n,ul[c[a[i]]++]=i)
  Fj(8/Z(*a)-1,F(n,a[i]=xl[uli]>>(j+1)*8*Z(*a))mz(c,8*nc);F(n,c[a[i]+1]++)$(c[1+*a]-n,F((1<<8*Z(*a))-1,c[i+1]+=c[i])F(n,zl[c[a[i]]++]=uli)swp(z,u)))
  xr;yr;zr;R u)
 P(xtC||xtI,grd(N(gL(x)),d))P(xtS,grd(N(ea1(str,x)),d))P(xta,A y=gkv(&x);idx(x,N(grd(y,d))))et(x))
A1(grp,P(xtt,xtl?K("{(2#x)#1,&x}",x):et(x))P(xta,A u=grp(gkv(&x));asrt(Ar(u)==1);uy=idx(x,uy);u)A y=atn(xt,0),u=a0();UC w=tz(xt);
 F(xn,L j=w==ZR?fpa(&y,mR(xai)):!w?fpc(&y,xci):w==2?fpi(&y,xii):w==3?fpl(&y,xli):0;$(j==un,u=apd(u,aL(0)))uaj=apv(uaj,&i))xr;aa(y,u))
A2(mtc,I r=mtc_(x,y);xr;yr;ai(r))A1(asc,xts||xti?hop(x):grd(x,0))A1(dsc,xti?hcl(x):grd(x,1))
