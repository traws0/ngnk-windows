#include"a.h" // ngn/k, (c) 2019-2024 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#define M(o,f,T) NI V f(CO V*RES a,CO V*RES b,V*RES c,U n){CO T*x=AL(a),*y=b;T*r=AL(c);F(n+3>>2,Fj(4,*r++=*x++o*y++))}
 M(+,aFF,F)M(-,sFF,F)M(*,mFF,F)M(/,dFF,F)
#undef M
ZN A bitBB(A x,A y,U f)_(A z=MINE(y)?yR:aB(yn);L VS(32)*a=xV,*b=yV,*c=zV;F(xn+255>>8,
 S(f,C(3,c[i]=a[i]&b[i])C(6,c[i]=a[i]&b[i])C(7,c[i]=a[i]|b[i])C(8,c[i]=b[i]&~a[i])C(9,c[i]=a[i]&~b[i])C(10,c[i]=~a[i]^b[i])R_(z(y(en(x))))))x(y(z)))
ZN A amdFF(A x,A y,U f)_(U n=xn;P(n-yn,el(y))A z=MINE(y)?y:aF(n);G(&aFF,sFF,mFF,dFF)[f-1](xV,yV,zV,n);y-z?y(x(z)):x(z))
Z L VS(32) msk(U n,C w)_(G m VS(32)={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
       m>>=w-3;m=m<=(G)(n-1&31>>w-3);*(L VS(32)*)&m)

// note: clang and GCC don't respect the alignment annotation unless it's done in a typedef
#define M(tx,ty,tz,o) R(CTZ(SZ(tx))<<2|CTZ(SZ(ty)),TD ty __attribute__((vector_size(32*SZ(ty)/SZ(tz)),aligned(SZ(ty)))) tyv;F(n*SZ(tz)+31>>5, \
               tz VS(32)a=CVV(((tx VS(32*SZ(tx)/SZ(tz))*)x)[i],TY(a)),b=CVV(((tyv*)y)[i],TY(b))^(tz)-s, \
               c=a+b+(tz)s;((tz VS(32)*)zV)[i]=c;I(o,L t VS(32);*(TY(c)*)&t=((a^c)&(b^c))<0;I(i==n_-1,t&=k);I(t[0]|t[1]|t[2]|t[3],goto ovf)))z)
NI A asuZZ_(CO V*RES x,CO V*RES y,U n,U wx,U wy,U f)_(I s=f==2;U w=MAX(wx,wy);A z=an(n,tG+w-3);L VS(32)k=msk(n,w);
  S(wx-3<<2|wy-3,M(G,G,G,1)M(G,H,H,1)M(G,I,I,1)M(G,L,L,0)M(H,G,H,1)M(H,H,H,1)M(H,I,I,1)M(H,L,L,0)
                 M(I,G,I,1)M(I,H,I,1)M(I,I,I,1)M(I,L,L,0)M(L,G,L,0)M(L,H,L,0)M(L,I,L,0)M(L,L,L,0))
  ovf:z=an(n,z(tG+(++w)-3));
  S(wx-3<<2|wy-3,M(G,G,H,0)M(G,H,I,0)M(G,I,L,0)M(H,G,I,0)M(H,H,I,0)M(H,I,L,0)M(I,G,L,0)M(I,H,L,0)M(I,I,L,0))0)
Z A asuZZ(A x,A y,U f)_(I(xtB,x=cG(x);y=cG(y))x(y(asuZZ_(xV,yV,xn,xw,yw,f))))
#undef M

// note: clang and GCC don't respect the alignment annotation unless it's done in a typedef
#define M(tx,ty,to,tz,o) R(CTZ(SZ(tx))<<2|CTZ(SZ(ty)),TD ty __attribute__((vector_size(32*SZ(ty)/SZ(tz)),aligned(SZ(ty))))tyv;F(n*SZ(tz)+31>>5, \
               tz VS(32)a=CVV(((tx VS(32*SZ(tx)/SZ(tz))*)x)[i],TY(a)),b=CVV(((tyv*)y)[i],TY(b)), \
        c=a*b,d=(c<0)^CVV(CVV(a,to VS(32*SZ(to)/SZ(tz)))*CVV(b,to VS(32*SZ(to)/SZ(tz)))>>8*(SZ(to)-SZ(tz)),TY(d)); \
               ((TY(c)*)zV)[i]=c;I(o,L t VS(32);*(TY(d)*)&t=d;I(i==n_-1,t&=k)I(t[0]|t[1]|t[2]|t[3],goto ovf)))z)
NI A mulZZ_(CO V*RES x,CO V*RES y,U n,U wx,U wy,U f)_(U w=MAX(wx,wy);A z=an(n,tG+w-3);L VS(32)k=msk(n,w);I(wx<wy,SW(x,y);SW(wx,wy))
 S(wx-3<<2|wy-3,M(G,G,H,G,1)M(H,G,I,H,1)M(H,H,I,H,1)M(I,G,L,I,1)M(I,H,L,I,1)M(I,I,L,I,1)M(L,G,L,L,0)M(L,H,L,L,0)M(L,I,L,L,0)M(L,L,L,L,0))
 ovf:z=an(n,z(zt+1));
 S(wx-3<<2|wy-3,M(G,G,H,H,0)M(H,G,I,I,0)M(H,H,I,I,0)M(I,G,L,L,0)M(I,H,L,L,0)M(I,I,L,L,0))0)
Z A mulZZ(A x,A y,U f)_(I(xtB,x=cG(x);y=cG(y))x(y(mulZZ_(xV,yV,xn,xw,yw,f))))
#undef M

#define M(ty,tz,o) R(CTZ(SZ(tz))<<2|CTZ(SZ(ty)),F(zn*SZ(tz)+31>>5, \
        tz VS(32)b=CVV(((ty VS(32*SZ(ty)/SZ(tz))*)yV)[i],TY(b))^(tz)-s,c=(tz)(v+s)+b;((TY(b)*)zV)[i]=c; \
        I(o,L t VS(32);*(TY(b)*)&t=(((tz)v^c)&(b^c))<0;I(i==n_-1,t&=k)I(t[0]|t[1]|t[2]|t[3],goto ovf)))y(z))
Z A asuzZ(L v,A y,U f)_(P(f==1&&!v,P(ytC,ct(ai(tG),y))sqzZ(y))I s=f==2;A z=an(yn,tG+MAX(tZ(v)-tG,yw-3));L VS(32) k=msk(zn,zw);
 S(zw-3<<2|yw-3,M(G,G,1)M(G,H,1)M(H,H,1)M(G,I,1)M(H,I,1)M(I,I,1)M(G,L,0)M(H,L,0)M(I,L,0)M(L,L,0))
 ovf:z=an(yn,z(zt+1));
 S(zw-3<<2|yw-3,M(G,H,0)M(G,I,0)M(H,I,0)M(G,L,0)M(H,L,0)M(I,L,0))0)
#undef M

#define M(ty,tz,o) R(CTZ(SZ(tz))<<2|CTZ(SZ(ty)),F(zn*SZ(tz)+31>>5, \
        tz VS(32)b=CVV(((ty VS(32*SZ(ty)/SZ(tz))*)yV)[i],TY(b));((tz VS(32)*)zV)[i]=(tz)v*b; \
        I(o,L t VS(32);*(TY(b)*)&t=(b<(tz)l|(tz)h<b);I(i==n_-1,t&=k);I(t[0]|t[1]|t[2]|t[3],goto ovf)))y(z))
Z A mulzZ(L v,A y,U f)_(P(!v,whr(ai(y(yn))))P(v==1,y)P(v==-1,neg(y))A z=an(yn,tG+MAX(tZ(v)-tG,yw-3));
 L m=-1LL<<(1<<zw)-1,l=m/v,h=~m/v;I(v<0,SW(l,m));L VS(32) k=msk(zn,zw);
 S(zw-3<<2|yw-3,M(G,G,1)M(G,H,1)M(H,H,1)M(G,I,1)M(H,I,1)M(I,I,1)M(G,L,0)M(H,L,0)M(I,L,0)M(L,L,0))
 ovf:z=an(yn,z(zt+1));
 S(zw-3<<2|yw-3,M(G,H,0)M(G,I,0)M(H,I,0)M(G,L,0)M(H,L,0)M(I,L,0))0)
#undef M

#define M(ty,tz) R(CTZ(SZ(ty))<<2|CTZ(SZ(tz)),F(zn*SZ(ty)+31>>5, \
        ty v VS(32)=((ty VS(32)*)yV)[i],s VS(32)=v<0,r VS(32); \
        S4(p<<1|o,r=(s^(s^v)%(ty)m)+(s&(ty)m),r=s^(v^s)/(ty)m,r=v&(ty)m,r=v>>m) \
        ((tz VS(32*SZ(tz)/SZ(ty))*)zV)[i]=CVV(r,tz VS(32*SZ(tz)/SZ(ty))))y(z))
Z A modzZ(L m,A y,U f)_(P(!m,ytC?cG(y):y)P(tZ(m)>tG+yw-3,A z=ltn(y,ai(0));P(m>0,asuZZ(y,mulzZ(m,z,3),1))y(neg(z)))
  U o=m<0;I(o,m=-m);U t=o?tZ(~(-1LL<<(1<<yw)-1)/m):tZ(m-1),p=!(m&m-1);I(p,m=o?CTZ(m):m-1)
  A z=an(yn,t);S(yw-3<<2|zw-3,M(G,G)M(H,G)M(H,H)M(I,G)M(I,H)M(I,I)M(L,G)M(L,H)M(L,I)M(L,L))0)
#undef M

Z A modzf(L n,A y,U f)_(P(!n,y)P(n<0,en(y))A u=az(n);u(K2("{y-x*(-x)!_y}",u,y)))
Z A mmmzZ(L v,A y,U f)_(C t=tZ(v),u=tG+yw-3;I(u<t||u-yt,y=ct(ai(t),y))E(t=u)U n=yn;A z=MINE(y)?y:an(n,t);C w=t-tG;n+=31>>w;L m=-(f==7);v^=m;
 S4(w,F(n&~31,zg=m^MIN(v,m^yg)),F(n&~15,zh=m^MIN(v,m^yh)),F(n&~7,zi=m^MIN(v,m^yi)),F(n&~3,zl=m^MIN(v,m^yl)))y-z?y(z):z)

#define M(tx,ty) R(CTZ(SZ(tx))<<2|CTZ(SZ(ty)),TD ty __attribute__((vector_size(32*SZ(ty)/SZ(tx)),aligned(SZ(ty)))) tyv;F(n*SZ(tx)+31>>5, \
               tx VS(32)a=((tx VS(32)*)x)[i],b=CVV(((tyv*)y)[i],TY(b));((tx VS(32)*)zV)[i]=a^(((tx)m^(a>b))&(a^b)))z)
NI A mmmZZ_(CO V*RES x,CO V*RES y,U n,U wx,U wy,U f)_(L m=-(f==7);I(wx<wy,SW(x,y);SW(wx,wy))A z=an(n,tG+wx-3);
 S(wx-3<<2|wy-3,M(G,G)M(H,G)M(H,H)M(I,G)M(I,H)M(I,I)M(L,G)M(L,H)M(L,I)M(L,L))0)
#undef M
Z A mmmZZ(A x,A y,U f)_(XB(bitBB(x,y,f))x(y(mmmZZ_(xV,yV,xn,xw,yw,f))))
 

// note: clang and GCC don't respect the alignment annotation unless it's done in a typedef
#define M(tx,ty) R(CTZ(SZ(tx))<<2|CTZ(SZ(ty)),TD ty __attribute__((vector_size(32*SZ(ty)/SZ(tx)),aligned(SZ(ty))))tyv;F(n*SZ(tx)+31>>5, \
        tx VS(32)a=((tx VS(32)*)x)[i],b=CVV(((tyv*)y)[i],TY(b)); \
               G VS(32*SZ(G)/SZ(tx))c=CVV(1&(f==10?a==b:(tx)(f==9)^s?b<a:a<b),TY(c));((G VS(32*SZ(G)/SZ(tx))*)zV)[i]=c)z)
NI A cmpZZ_(CO V*RES x,CO V*RES y,U n,U wx,U wy,U f)_(A z=aG(n);C s=wx<wy;I(s,SW(x,y);SW(wx,wy));
 S(wx-3<<2|wy-3,M(G,G)M(H,G)M(H,H)M(I,G)M(I,H)M(I,I)M(L,G)M(L,H)M(L,I)M(L,L))0)
#undef M
Z A cmpZZ(A x,A y,U f)_(XB(bitBB(x,y,f))x(y(cmpZZ_(xV,yV,xn,xw,yw,f))));

TD G G4[4],G8[8],G16[16],G32[32];TD H H16[16];TD I I8[8];TD L L4[4];
ZN V ltng(L v,CO V*RES a,V*RES b,U n){G w=v;CO G32*p=a;G32*r=b;F(n+31>>5,Fj(32,r[i][j]=w< p[i][j]))}
ZN V ltnh(L v,CO V*RES a,V*RES b,U n){H w=v;CO H16*p=a;G16*r=b;F(n+15>>4,Fj(16,r[i][j]=w< p[i][j]))}
ZN V ltni(L v,CO V*RES a,V*RES b,U n){I w=v;CO I8 *p=a;G8 *r=b;F(n+ 7>>3,Fj( 8,r[i][j]=w< p[i][j]))}
ZN V ltnl(L v,CO V*RES a,V*RES b,U n){L w=v;CO L4 *p=a;G4 *r=b;F(n+ 3>>2,Fj( 4,r[i][j]=w< p[i][j]))}
ZN V gtng(L v,CO V*RES a,V*RES b,U n){G w=v;CO G32*p=a;G32*r=b;F(n+31>>5,Fj(32,r[i][j]=w> p[i][j]))}
ZN V gtnh(L v,CO V*RES a,V*RES b,U n){H w=v;CO H16*p=a;G16*r=b;F(n+15>>4,Fj(16,r[i][j]=w> p[i][j]))}
ZN V gtni(L v,CO V*RES a,V*RES b,U n){I w=v;CO I8 *p=a;G8 *r=b;F(n+ 7>>3,Fj( 8,r[i][j]=w> p[i][j]))}
ZN V gtnl(L v,CO V*RES a,V*RES b,U n){L w=v;CO L4 *p=a;G4 *r=b;F(n+ 3>>2,Fj( 4,r[i][j]=w> p[i][j]))}
ZN V eqlg(L v,CO V*RES a,V*RES b,U n){G w=v;CO G32*p=a;G32*r=b;F(n+31>>5,Fj(32,r[i][j]=w==p[i][j]))}
ZN V eqlh(L v,CO V*RES a,V*RES b,U n){H w=v;CO H16*p=a;G16*r=b;F(n+15>>4,Fj(16,r[i][j]=w==p[i][j]))}
ZN V eqli(L v,CO V*RES a,V*RES b,U n){I w=v;CO I8 *p=a;G8 *r=b;F(n+ 7>>3,Fj( 8,r[i][j]=w==p[i][j]))}
ZN V eqll(L v,CO V*RES a,V*RES b,U n){L w=v;CO L4 *p=a;G4 *r=b;F(n+ 3>>2,Fj( 4,r[i][j]=w==p[i][j]))}
Z A cmpzZ(L v,A y,U f)_(U w=yw-3;P(tG+w<tZ(v),y(rsz(yn,ai(f==8?v<0:f==9?v>0:0))))
 U n=yn;A z=aG(n);A(&ltng,ltnh,ltni,ltnl,gtng,gtnh,gtni,gtnl,eqlg,eqlh,eqli,eqll)[f-8<<2|w](v,yV,zG,n);y(z))

Z A addzE(L v,A x)_(Lij x(0);aE(i+v,j+v))
Z A subfF(F v,A y,U f)_(A z=MINE(y)?y:aF(yn);U n=zn+3&-4;F(n,zf=v-yf)y-z?y(z):z)
Z A addfF(F v,A y,U f)_(A z=MINE(y)?y:aF(yn);U n=zn+3&-4;F(n,zf=v+yf)y-z?y(z):z)
Z A mulfF(F v,A y,U f)_(A z=MINE(y)?y:aF(yn);U n=zn+3&-4;F(n,zf=v*yf)y-z?y(z):z)
Z A admfF(F v,A y,U f)_((f==3?mulfF:f==2?subfF:addfF)(v,y,f))
Z A dvdfF(F v,A y,U f)_(A z=MINE(y)?y:aF(yn);U n=zn+3&-4;F(n,zf=v/yf)y-z?y(z):z)
Z A dvdFf(A x,F v,U f)_(A z=aF(xn);F(xn,zf=xf/v)x(z))
Z A dvdzZ(L v,A y,U f)_(dvdfF(v,cF(y),f))
Z A dvdZZ(A x,A y,U f)_(x=cF(x);amdFF(x,cF(y),f))
Z A arizz(L a,L b,U f)_(P(f==4,af((F)a/b))az(f==1?a+b:f==2?a-b:f==3?a*b:f==5?(!a?b:a<0?(b<0?-1-~b/-a:b/-a):b<0?(a-1-~b%a):b%a):f==6?MIN(a,b):f==7?MAX(a,b):f==8?a<b:f==9?a>b:f==10?a==b:0))
Z A arizZ(L v,A y,U f)_(YB(P((W)v>2|f/3-2,arizZ(v,cG(y),f))P(v^(f==7),y)y=mut(y);F(yn+63>>6,yl=-v)y)A(&asuzZ,asuzZ,mulzZ,dvdzZ,modzZ,mmmzZ,mmmzZ,cmpzZ,cmpzZ,cmpzZ)[f-1](v,y,f))
Z A ariZZ(A x,A y,U f)_(P(xn-yn,Nx(el(y)))I(!(xtB&&ytB),x=xtB?cG(x):x;y=ytB?cG(y):y)A(&asuZZ,asuZZ,mulZZ,dvdZZ,0,mmmZZ,mmmZZ,cmpZZ,cmpZZ,cmpZZ)[f-1](x,y,f))
ZN A ariz(A x,A y,U f){S(xtT<<1|ytT,R(0,arizz(gl(x),gl(y),f))R(1,arizZ(gl(x),y,f))R(2,P(f==4,x=xtB?cG(x):x;ari(x,cF(y)))P(f==2,arizZ(-gl(y),x,1))arizZ(gl(y),x,f-8<2u?f^1:f))R_(ariZZ(x,y,f)))}
ZN A arif(A x,A y,U f)_(C t=xt,u=yt;
 P(f==5,xtz?modzf(gl(x),y,f):et(y))
 P(t-tf&&t-tF,x=Ny(cF(x));ari(x,y))
 P(u-tf&&u-tF,ari(x,Nx(cF(y))))
 P(f<5,U k=(t<tM)<<1|(u<tM);S(k,
  R(0,F a=*xF,b=gf(y);x(af(f==1?a+b:f==2?a-b:f==3?a*b:a/b)))
  R(1,x(f<4?admfF(*xF,y,f):dvdfF(*xF,y,f)))
  R(2,f==2?addfF(-gf(y),x,f):f<4?admfF(gf(y),x,f):dvdFf(x,gf(y),f))
  R_(amdFF(x,y,f)))0)
  P(f==10,ariz(x,y,f))
 x=of1(x);y=ari(x,of1(y));f<8&&y?of0(y):y)

Z U f;//0=dex,1=add,2=sub,3=mul,4=dvd,5=mod,6=mnm,7=mxm,8=ltn,9=gtn,10=eql
A ari_(A x,A y,B c)_(C t=xt,u=yt;U v=1<<t|1<<u;
 P(!(v&~(1<<tB|1<<tG|1<<tH|1<<tI|1<<tL|1<<tC|1<<ti|1<<tl|1<<tc)),ariz(c?x:xR,y,f))
 P(v&(1<<tA),y=e2f(v2[f],x,y);c?x(y):y)
 P(v&(1<<tm|1<<tM),P(f==2,N(y=neg(y),x=c&&x(0));y=e2f(add,x,y);c?x(y):y)y=e2f(v2[f],x,y);c?x(y):y)
 P(t==tE,P(f==1&&ytzc,addzE(gl(y),c?x:xR))x=gZ(c?x:xR);ari(x,y))
 P(u==tE,P(f==1&&xtzc,addzE(c?gl(x):gl_(x),y))ari_(x,gZ(y),c))
 P(v&(1<<tf|1<<tF),arif(c?x:xR,y,f))
 I(f-8<3u,
  P(v&1<<tS,P(f==10&&!(v&~(1<<ts|1<<tS)),ariz(c?x:xR,y,f))y=e2f(ari,x,y);c?x(y):y)
  P(v&1<<ts,v^1<<ts?et(y):ai(f==8?qA(x,y)<0:f==9?qA(x,y)>0:xv==yv)))
 et(y))
A2(ari,ari_(x,y,1))

#define M(s,i) A2(s,U o=f;f=i;x=ari_(x,y,0);f=o;x)
 M(add,1)M(sub,2)M(mul,3)M(dvd,4)M(mod,5)M(mnm,6)M(mxm,7)M(ltn,8)M(gtn,9)M(eql,10)
#undef M
A2(dex,y)X2(exc,RMT(ytm||rnk(x)<0?ed(y):ytt?exc(x,rsz(xN,y)):xN-yN?el(y):am(xR,y))Rs(x=rsz(yN,x);x(exc(x,y)))Rilc(mod(x,y))R_(et(y)))
