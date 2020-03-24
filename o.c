#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
I mtc_(A x,A y/*x0y0*/)_(P(x==y,1)P(xt-yt||pkd(x)||xn-yn||(xtr&&xv-yv),0)P(!ref(x),F(xn*tZ(xt),P(xci-yci,0))1)F(xn,P(!mtc_(xai,yai),0))1)
S I cmpL(L x,L y)_(x<y?-1:x>y)
S I cmp_(A x,A y/*x0y0*/)_(P(x==y,0)I d=xt-yt;P(d,d)P(xti||xtc,(L)gi(x)-(L)gi(y))P(xtl,cmpL(gl_(x),gl_(y)))P(xtd,D u=gd_(x),v=gd_(y);u<v?-1:u>v?1:0)
 P(xts,strcmp(syp(gs(x)),syp(gs(y))))Y(!pkd(x),I r=cmpL(xn,yn);P(xtT,F(min(xn,yn),A z=get(x,i),u=get(y,i);I d=cmp_(z,u);zr;ur;P(d,d))r))cmpL(x,y))
A2(mtc,I r=mtc_(x,y);xr;yr;ai(r))
S L bef(A*a,L i,L j)_(I r=cmp_(a[i],a[j]);r?r<0:i<j)
S V sft(A*a,L*l,L i,L j)_(W(1,L k=1+2*i;Y(k>j,B)Y(k+1<=j&&bef(a,l[k],l[k+1]),k++)Y(!bef(a,l[i],l[k]),B)SWP(l[i],l[k])i=k))
A1(ascl,x=N(K("{x-&/x}",x));UC*a;L n=xn;A y=aC(n*Z(*a));a=(UC*)yc;A z=aL(n),u=aL(n);L nc=1+(1<<8*Z(*a));L c[nc];ms(c,0,8*nc);
 F(n,a[i]=xli)F(n,c[a[i]+1]++)F((1<<8*Z(*a))-1,c[i+1]+=c[i])F(n,ul[c[a[i]]++]=i)
 Fj(8/Z(*a)-1,F(n,a[i]=xl[uli]>>(j+1)*8*Z(*a))ms(c,0,8*nc);F(n,c[a[i]+1]++)Y(c[1+*a]-n,F((1<<8*Z(*a))-1,c[i+1]+=c[i])F(n,zl[c[a[i]]++]=uli)SWP(z,u)))
 xr;yr;zr;u)
A1(asc,P(xtX,A*a=xa,u=till(xn);L*l=ul,n=xn,i=n/2;W(i-->0,sft(a,l,i,n-1))i=n-1;W(i>0,SWP(l[i],*l)sft(a,l,0,--i))xr;u)P(xtL,ascl(x))
 P(xta,A y=gkv(&x);idx(x,N(asc(y))))xtC||xtI?asc(N(gL(x))):xtS?asc(N(ea1(str,x))):xtD?asc(blw(x)):xts||xti?hop(x):et(x))
A1(dsc,P(xti,hcl(x))P(xta,A y=gkv(&x);idx(x,N(dsc(y))))sub(al(len_(x)-1),rev(asc(rev(x)))))
A1(grp,P(xtt,xtil?K("{(2#x)#1i,`i$&x}",x):et(x))P(xta,A u=grp(gkv(&x));asrt(Ar(u)==1);uy=idx(x,uy);u)A y=atn(xt,0),u=a0();UC w=tz(xt);
 F(xn,L j=w==ZR?fpa(&y,mR(xai)):!w?fpc(&y,xci):w==2?fpi(&y,xii):w==3?fpl(&y,xli):0;Y(j==un,u=apd(u,aL(0)))uaj=apv(uaj,&i))xr;aa(y,u))
