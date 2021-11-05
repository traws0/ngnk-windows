#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#define idiv(x,y) ({TY(x)a=(x),b=(y);!b?a:a<0?-1-(-1-a)/b:a/b;})
#define hv(v,T,R,f) S T v(T x,T y)_(f)
#define hd(v,f,g) hv(v##b,B,B,f)hv(v##h,H,H,f)hv(v##i,I,I,f)hv(v##l,L,L,f)hv(v##d,D,D,g)
#define hc(v,f,g) hv(v##b,B,B,f)hv(v##h,H,B,f)hv(v##i,I,B,f)hv(v##l,L,B,f)hv(v##d,D,B,g)
#define h(v,f) hd(v,f,f)
h(dex,y)h(add,x+y)h(sub,x-y)h(mul,x*y)hv(dvdd,D,D,x/y)hd(mod,x>0?(y%x+x)%x:idiv(y,-x),x>0?y-(L)(y/x)*x:dvdd(y,-x))
h(mnm,min(x,y))h(mxm,max(x,y))hc(ltn,x<y,qD(x,y)<0)hc(gtn,x>y,ltn(y,x))hc(eql,x==y,*(L*)&x==*(L*)&y)
#undef h
#define hV(f,T,R,e...) SN I f(OV*RE p,OV*RE q,V*RE s,Ln)_(O T*a=p,*b=q;R*r=s;e)

#define htt(v,t,T,R) hV(v##t##t,T,R,*r=v##t(*a,*b);0)
#define htT(v,t,T,R) hV(v##t##T,T,R,LN(b)LN(r)TY(*a)c=*a;i(PD(n,a),*r++=v##t(   c,*b++))0)
#define hTT(v,t,T,R) hV(v##T##T,T,R,LN(a)LN(b)LN(r)      i(PD(n,a),*r++=v##t(*a++,*b++))0)
#define hTt(v,t,T,R) hV(v##T##t,T,R,LN(a)LN(r)TY(*b)c=*b;i(PD(n,a),*r++=v##t(*a++,   c))0)
#define hsw(v,t,T,R) hV(v##T##t,T,R,v##t##T(b,a,r,n))
#define h1(a...) htt(a)htT(a)hTT(a)hTt(a)
#define h2(a...) htt(a)htT(a)hTT(a)hsw(a)
                                                    h1(dvd,d,D,D)
h1(mod,b,B,B)h1(mod,h,H,H)h1(mod,i,I,I)h1(mod,l,L,L)h1(mod,d,D,D)
h2(mnm,b,B,B)h2(mnm,h,H,H)h2(mnm,i,I,I)h2(mnm,l,L,L)h2(mnm,d,D,D)
h2(mxm,b,B,B)h2(mxm,h,H,H)h2(mxm,i,I,I)h2(mxm,l,L,L)h2(mxm,d,D,D)
h1(ltn,b,B,B)h1(ltn,h,H,H)h1(ltn,i,I,I)h1(ltn,l,L,L)h1(ltn,d,D,I)
h2(eql,b,B,B)h2(eql,h,H,H)h2(eql,i,I,I)h2(eql,l,L,L)h2(eql,d,D,I)
U(aro,{{{    0,modbb,mnmbb,mxmbb,ltnbb,0,eqlbb},//atom+atom
        {    0,modhh,mnmhh,mxmhh,ltnhh,0,eqlhh},
        {    0,modii,mnmii,mxmii,ltnii,0,eqlii},
        {    0,modll,mnmll,mxmll,ltnll,0,eqlll},
        {dvddd,moddd,mnmdd,mxmdd,ltndd,0,eqldd}},
       {{    0,modbB,mnmbB,mxmbB,ltnbB,0,eqlbB},//atom+list
        {    0,modhH,mnmhH,mxmhH,ltnhH,0,eqlhH},
        {    0,modiI,mnmiI,mxmiI,ltniI,0,eqliI},
        {    0,modlL,mnmlL,mxmlL,ltnlL,0,eqllL},
        {dvddD,moddD,mnmdD,mxmdD,ltndD,0,eqldD}},
       {{    0,modBb,mnmBb,mxmBb,ltnBb,0,eqlBb},//list+atom
        {    0,modHh,mnmHh,mxmHh,ltnHh,0,eqlHh},
        {    0,modIi,mnmIi,mxmIi,ltnIi,0,eqlIi},
        {    0,modLl,mnmLl,mxmLl,ltnLl,0,eqlLl},
        {dvdDd,modDd,mnmDd,mxmDd,ltnDd,0,eqlDd}},
       {{    0,modBB,mnmBB,mxmBB,ltnBB,0,eqlBB},//list+list
        {    0,modHH,mnmHH,mxmHH,ltnHH,0,eqlHH},
        {    0,modII,mnmII,mxmII,ltnII,0,eqlII},
        {    0,modLL,mnmLL,mxmLL,ltnLL,0,eqlLL},
        {dvdDD,modDD,mnmDD,mxmDD,ltnDD,0,eqlDD}}})

S C tZx(Ax)_(XcC(tH)Xz(tZ(gl_(x)))Xd(tD)XZD(xt)XsS(tI)tB)
C sup(A*p,A*q)_(Ax=*p,y=*q;Ct=max(tZx(x),tZx(y));*p=x=Ny(cT[t](x));*q=y=Nx(cT[t](y));t)
S A ar2(Ax,Ay,Iv)_(P((1<<xt|1<<yt)&(1<<tm|1<<tM|1<<tA),eac2f(x,y,v2[v]))N(sup(&x,&y));Ik=xtT<<1|ytT;
 P(k==3&&xn-yn,el2(x,y))Ct=k?min(xt,yt):max(xt,yt);V*a=xtP?(V*)&x:xV,*b=ytP?(V*)&y:yV;V(f,aro[k][TT[t]-tB][v-4]);
 I(t>tD,t+=tD-td)I(v>MXM-av&&t==tD,t=tI)I(!k,t+=tc-tC;P(TP(t),Ii=0;f(a,b,&i,1);x(y(az(i)))))
 Az=xt==t&&xr==1?x:yt==t&&yr==1?y:atn(t,k-1?xn:yn);f(a,b,zV,zn);x-z?x(y-z?y(z):z):y(z))
S ALA(ext,XMT(x)rshN(n,xtm?enl(x):x))
A2(dct,P(rnk(x)<0,ed2(x,y))x=ext(yN,x);y=ext(xN,y);(xN-yN?el2:am)(x,y))

A2(dex,mr(x);y)
A2(add,adm(x,y,0))
A2(sub,add(x,Nx(neg(y))))
A2(mul,adm(x,y,1))
A2(dvd,ar2(Ny(cst(as('d'),x)),Nx(cst(as('d'),y)),DVD-av))
A2(mod,Xzc(ar2(x,y,MOD-av))dct(x,y))
A2(mnm,ar2(x,y,MNM-av))
A2(mxm,ar2(x,y,MXM-av))
A2(ltn,ar2(x,y,LTN-av))
A2(gtn,ltn(y,x))
A2(eql,xtsS&&ytsS?eql(AT(xt+ti-ts,mut(x)),AT(yt+ti-ts,mut(y))):ar2(x,y,EQL-av))

#define hf(v,T,R,Q) SN I v##r##T(V*RE p,OV*RE q,Ln)_(O T*b=q;R*a=p,c=*a;i(n,c=v##Q(c,b[i]))*a=c;n)
hf(add,B,L,l)hf(add,H,L,l)hf(add,I,L,l)hf(add,L,L,l)hf(add,D,D,d)
hf(sub,B,L,l)hf(sub,H,L,l)hf(sub,I,L,l)hf(sub,L,L,l)hf(sub,D,D,d)
hf(mul,B,L,l)hf(mul,H,L,l)hf(mul,I,L,l)hf(mul,L,L,l)hf(mul,D,D,d)
hf(mnm,B,L,l)hf(mnm,H,L,l)hf(mnm,I,L,l)hf(mnm,L,L,l)hf(mnm,D,D,d)
hf(mxm,B,L,l)hf(mxm,H,L,l)hf(mxm,I,L,l)hf(mxm,L,L,l)hf(mxm,D,D,d)
U(arrT,{{0,addrB,subrB,mulrB,0,0,mnmrB,mxmrB},
        {0,addrH,subrH,mulrH,0,0,mnmrH,mxmrH},
        {0,addrI,subrI,mulrI,0,0,mnmrI,mxmrI},
        {0,addrL,subrL,mulrL,0,0,mnmrL,mxmrL},
        {0,addrD,subrD,mulrD,0,0,mnmrD,mxmrD}})

#define hs(v,t,T,R) hV(v##s##T,T,R,R c=*a;i(PD(n,b),r[i]=c=v##t(c,b[i]))0)
hs(dex,b,B,B)hs(dex,h,H,H)hs(dex,i,I,I)hs(dex,l,L,L)hs(dex,d,D,D)
hs(add,b,B,B)hs(add,h,H,H)hs(add,i,I,I)hs(add,l,L,L)hs(add,d,D,D)
hs(sub,b,B,B)hs(sub,h,H,H)hs(sub,i,I,I)hs(sub,l,L,L)hs(sub,d,D,D)
hs(mul,b,B,B)hs(mul,h,H,H)hs(mul,i,I,I)hs(mul,l,L,L)hs(mul,d,D,D)
                                                    hs(dvd,d,D,D)
hs(mod,b,B,B)hs(mod,h,H,H)hs(mod,i,I,I)hs(mod,l,L,L)hs(mod,d,D,D)
hs(mnm,b,B,B)hs(mnm,h,H,H)hs(mnm,i,I,I)hs(mnm,l,L,L)hs(mnm,d,D,D)
hs(mxm,b,B,B)hs(mxm,h,H,H)hs(mxm,i,I,I)hs(mxm,l,L,L)hs(mxm,d,D,D)
hs(ltn,b,B,B)hs(ltn,h,H,H)hs(ltn,i,I,I)hs(ltn,l,L,L)hs(ltn,d,D,I)
hs(gtn,b,B,B)hs(gtn,h,H,H)hs(gtn,i,I,I)hs(gtn,l,L,L)hs(gtn,d,D,I)
hs(eql,b,B,B)hs(eql,h,H,H)hs(eql,i,I,I)hs(eql,l,L,L)hs(eql,d,D,I)
U(arsT,{{0,0,0,0,0,0,mnmsB,mxmsB},
        {0,0,0,0,0,0,mnmsH,mxmsH},
        {0,0,0,0,0,0,mnmsI,mxmsI},
        {0,0,0,0,0,0,mnmsL,mxmsL},
        {0,0,0,0,0,0,mnmsD,mxmsD}})

#define hp(v,t,T,R) hV(v##p##T,T,R,T c=*a;i(PD(n,b),T d=b[i];r[i]=v##t(b[i],c);c=d);0)
hp(mnm,b,B,B)hp(mnm,h,H,H)hp(mnm,i,I,I)hp(mnm,l,L,L)
hp(mxm,b,B,B)hp(mxm,h,H,H)hp(mxm,i,I,I)hp(mxm,l,L,L)
hp(ltn,b,B,B)hp(ltn,h,H,B)hp(ltn,i,I,B)hp(ltn,l,L,B)
hp(gtn,b,B,B)hp(gtn,h,H,B)hp(gtn,i,I,B)hp(gtn,l,L,B)
hp(eql,b,B,B)hp(eql,h,H,B)hp(eql,i,I,B)hp(eql,l,L,B)
S A3(dexp,cat(x,drp(-1,y)))
S A3(modp,eac2f(y,dexp(x,yR,av),mod))
S A3(mmmp,N(sup(&x,&y));Lv=gl(x);Ii=(z-MNM)<<2|Tz[yt];x=ax(y);CH(i,&mnmpB,mnmpH,mnmpI,mnmpL,mxmpB,mxmpH,mxmpI,mxmpL)(&v,yV,xV,yn);x)
S A3(cmpp,Ii=z-LTN,j=Tz[yt];Lv=gl(x);x=aB(yn);Cc=tZ(v)-tB<=j?2:!i?v>0:i==1?v<0:0;
 ye(CH(i<<2|j,&ltnpB,ltnpH,ltnpI,ltnpL,gtnpB,gtnpH,gtnpI,gtnpL,eqlpB,eqlpH,eqlpI,eqlpL)(&v,yV,xV,yn);I(c-2,*xB=c)x))
S A3(___p,v2[zv](y,dexp(x,yR,av)))
U(arp,{dexp,___p,___p,___p,___p,modp,mmmp,mmmp,cmpp,cmpp,cmpp})

#define ha(v,t,T) SN I v##a##T(V*RE p,Ln,O L*RE q,Lm,O V*RE r,I d)_(T*a=p;O T*b=r;i(m,Lj=q[i];P(!in(j,n),-1)a[j]=v##t(a[j],b[d*i]))0)
ha(dex,b,B)ha(dex,h,H)ha(dex,i,I)ha(dex,l,L)
                                 ha(add,l,L)ha(add,d,D)
                                 ha(sub,l,L)ha(sub,d,D)
                                 ha(mul,l,L)ha(mul,d,D)
ha(mnm,b,B)ha(mnm,h,H)ha(mnm,i,I)ha(mnm,l,L)ha(mnm,d,D)
ha(mxm,b,B)ha(mxm,h,H)ha(mxm,i,I)ha(mxm,l,L)ha(mxm,d,D)
U(araT,{{dexaB,    0,    0,    0,0,0,mnmaB,mxmaB},
        {dexaH,    0,    0,    0,0,0,mnmaH,mxmaH},
        {dexaI,    0,    0,    0,0,0,mnmaI,mxmaI},
        {dexaL,addaL,subaL,mulaL,0,0,mnmaL,mxmaL},
        {dexaL,addaD,subaD,mulaD,0,0,mnmaD,mxmaD}})
