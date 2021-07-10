#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#define idiv(x,y) ({TY(x)a=(x),b=(y);!b?a:a<0?-1-(-1-a)/b:a/b;})

#define hf(v,T,R,f) S T v(T x,T y)_(f)
#define hd(v,f,g) hf(v##b,B,B,f)hf(v##h,H,H,f)hf(v##i,I,I,f)hf(v##l,L,L,f)hf(v##d,D,D,g)
#define hc(v,f,g) hf(v##b,B,B,f)hf(v##h,H,B,f)hf(v##i,I,B,f)hf(v##l,L,B,f)hf(v##d,D,B,g)
#define h(v,f) hd(v,f,f)
h(dex,y)h(add,x+y)h(sub,x-y)h(mul,x*y)hd(dvd,idiv(x,y),x/y)hd(mod,x>0?(y%x+x)%x:idiv(y,-x),y-(L)(y/x)*x)
h(mnm,min(x,y))h(mxm,max(x,y))hc(ltn,x<y,cD(x,y)<0)hc(gtn,x>y,cD(x,y)>0)hc(eql,x==y,*(L*)&x==*(L*)&y)
#undef h
#undef hc
#undef hd
#undef hf

#define hF(f,T,R,e...) SN I f(O T*RE a,O T*RE b,R*RE r,Nn)_(e)
#define h0(v,t,T,R) SN I v##a##T(T*RE a,Nn,L*RE p,Nm,T*RE b,I d)_(i(m,Lj=p[i];P(!in(j,n),0)a[j]=v##t(a[j],b[d*i]))0)\
                                hF(v##s##T,T,R,R c=*a;i(PD(n,b),r[i]=c=v##t(c,b[i]))0)\
                                hF(v##p##T,T,R,T c=*a;i(PD(n,b),T d=b[i];r[i]=v##t(b[i],c);c=d);0)
#define ht(v,t,T,R) h0(v,t,T,R) hF(v##t##t,T,R,*r=v##t(*a,*b);0)\
                                hF(v##T##T,T,R,AL(a)AL(b)AL(r)      i(PD(n,a),*r++=v##t(*a++,*b++))0)\
                                hF(v##t##T,T,R,AL(b)AL(r)TY(*a)c=*a;i(PD(n,a),*r++=v##t(   c,*b++))0)
#define h1(v,t,T,R) ht(v,t,T,R) hF(v##T##t,T,R,AL(a)AL(r)TY(*b)c=*b;i(PD(n,a),*r++=v##t(*a++,   c))0)
#define h2(v,t,T,R) ht(v,t,T,R) hF(v##T##t,T,R,v##t##T(b,a,r,n))
h0(dex,b,B,B)h0(dex,h,H,H)h0(dex,i,I,I)h0(dex,l,L,L)h0(dex,d,D,D)
h0(add,b,B,B)h0(add,h,H,H)h0(add,i,I,I)h0(add,l,L,L)h0(add,d,D,D)
h0(sub,b,B,B)h0(sub,h,H,H)h0(sub,i,I,I)h0(sub,l,L,L)h0(sub,d,D,D)
h0(mul,b,B,B)h0(mul,h,H,H)h0(mul,i,I,I)h0(mul,l,L,L)h0(mul,d,D,D)
h1(dvd,b,B,B)h1(dvd,h,H,H)h1(dvd,i,I,I)h1(dvd,l,L,L)h1(dvd,d,D,D)
h1(mod,b,B,B)h1(mod,h,H,H)h1(mod,i,I,I)h1(mod,l,L,L)h1(mod,d,D,D)
h2(mnm,b,B,B)h2(mnm,h,H,H)h2(mnm,i,I,I)h2(mnm,l,L,L)h2(mnm,d,D,D)
h2(mxm,b,B,B)h2(mxm,h,H,H)h2(mxm,i,I,I)h2(mxm,l,L,L)h2(mxm,d,D,D)
h1(ltn,b,B,B)h1(ltn,h,H,H)h1(ltn,i,I,I)h1(ltn,l,L,L)h1(ltn,d,D,I)
h0(gtn,b,B,B)h0(gtn,h,H,H)h0(gtn,i,I,I)h0(gtn,l,L,L)h0(gtn,d,D,I)
h2(eql,b,B,B)h2(eql,h,H,H)h2(eql,i,I,I)h2(eql,l,L,L)h2(eql,d,D,I)

S OV*arf[][5][7]={//first dim: 0=atom-atom, 1=atom-list, 2=list-atom, 3=list-list
 {{dvdbb,modbb,mnmbb,mxmbb,ltnbb,0,eqlbb,},
  {dvdhh,modhh,mnmhh,mxmhh,ltnhh,0,eqlhh,},
  {dvdii,modii,mnmii,mxmii,ltnii,0,eqlii,},
  {dvdll,modll,mnmll,mxmll,ltnll,0,eqlll,},
  {dvddd,moddd,mnmdd,mxmdd,ltndd,0,eqldd,},},
 {{dvdbB,modbB,mnmbB,mxmbB,ltnbB,0,eqlbB,},
  {dvdhH,modhH,mnmhH,mxmhH,ltnhH,0,eqlhH,},
  {dvdiI,modiI,mnmiI,mxmiI,ltniI,0,eqliI,},
  {dvdlL,modlL,mnmlL,mxmlL,ltnlL,0,eqllL,},
  {dvddD,moddD,mnmdD,mxmdD,ltndD,0,eqldD,},},
 {{dvdBb,modBb,mnmBb,mxmBb,ltnBb,0,eqlBb,},
  {dvdHh,modHh,mnmHh,mxmHh,ltnHh,0,eqlHh,},
  {dvdIi,modIi,mnmIi,mxmIi,ltnIi,0,eqlIi,},
  {dvdLl,modLl,mnmLl,mxmLl,ltnLl,0,eqlLl,},
  {dvdDd,modDd,mnmDd,mxmDd,ltnDd,0,eqlDd,},},
 {{dvdBB,modBB,mnmBB,mxmBB,ltnBB,0,eqlBB,},
  {dvdHH,modHH,mnmHH,mxmHH,ltnHH,0,eqlHH,},
  {dvdII,modII,mnmII,mxmII,ltnII,0,eqlII,},
  {dvdLL,modLL,mnmLL,mxmLL,ltnLL,0,eqlLL,},
  {dvdDD,modDD,mnmDD,mxmDD,ltnDD,0,eqlDD,},},
};

#define h(v,T,R,Q) SN I v##r##T(R*RE a,T*RE b,Nn)_(R c=*a;i(n,c=v##Q(c,b[i]))*a=c;n)
h(dex,B,L,l)h(add,B,L,l)h(sub,B,L,l)h(mul,B,L,l)h(dvd,B,L,l)h(mod,B,L,l)h(mnm,B,L,l)h(mxm,B,L,l)h(ltn,B,L,l)h(gtn,B,L,l)h(eql,B,L,l)
h(dex,H,L,l)h(add,H,L,l)h(sub,H,L,l)h(mul,H,L,l)h(dvd,H,L,l)h(mod,H,L,l)h(mnm,H,L,l)h(mxm,H,L,l)h(ltn,H,L,l)h(gtn,H,L,l)h(eql,H,L,l)
h(dex,I,L,l)h(add,I,L,l)h(sub,I,L,l)h(mul,I,L,l)h(dvd,I,L,l)h(mod,I,L,l)h(mnm,I,L,l)h(mxm,I,L,l)h(ltn,I,L,l)h(gtn,I,L,l)h(eql,I,L,l)
h(dex,L,L,l)h(add,L,L,l)h(sub,L,L,l)h(mul,L,L,l)h(dvd,L,L,l)h(mod,L,L,l)h(mnm,L,L,l)h(mxm,L,L,l)h(ltn,L,L,l)h(gtn,L,L,l)h(eql,L,L,l)
h(dex,D,D,d)h(add,D,D,d)h(sub,D,D,d)h(mul,D,D,d)h(dvd,D,D,d)h(mod,D,D,d)h(mnm,D,D,d)h(mxm,D,D,d)h(ltn,D,D,d)h(gtn,D,D,d)h(eql,D,D,d)
#undef h

OV*arr[][11]={//reduce
 {dexrB,addrB,subrB,mulrB,0,modrB,mnmrB,mxmrB,ltnrB,gtnrB,eqlrB,},
 {dexrH,addrH,subrH,mulrH,0,modrH,mnmrH,mxmrH,ltnrH,gtnrH,eqlrH,},
 {dexrI,addrI,subrI,mulrI,0,modrI,mnmrI,mxmrI,ltnrI,gtnrI,eqlrI,},
 {dexrL,addrL,subrL,mulrL,0,modrL,mnmrL,mxmrL,ltnrL,gtnrL,eqlrL,},
 {dexrD,addrD,subrD,mulrD,0,modrD,mnmrD,mxmrD,ltnrD,gtnrD,eqlrD,},
};
OV*ars[][11]={//scan
 {dexsB,addsB,subsB,mulsB,0,modsB,mnmsB,mxmsB,ltnsB,gtnsB,eqlsB,},
 {dexsH,addsH,subsH,mulsH,0,modsH,mnmsH,mxmsH,ltnsH,gtnsH,eqlsH,},
 {dexsI,addsI,subsI,mulsI,0,modsI,mnmsI,mxmsI,ltnsI,gtnsI,eqlsI,},
 {dexsL,addsL,subsL,mulsL,0,modsL,mnmsL,mxmsL,ltnsL,gtnsL,eqlsL,},
 {dexsD,addsD,subsD,mulsD,0,modsD,mnmsD,mxmsD,ltnsD,gtnsD,eqlsD,},
};
OV*arp[][11]={//eachprior
 {dexpB,addpB,subpB,mulpB,0,modpB,mnmpB,mxmpB,ltnpB,gtnpB,eqlpB,},
 {dexpH,addpH,subpH,mulpH,0,modpH,mnmpH,mxmpH,ltnpH,gtnpH,eqlpH,},
 {dexpI,addpI,subpI,mulpI,0,modpI,mnmpI,mxmpI,ltnpI,gtnpI,eqlpI,},
 {dexpL,addpL,subpL,mulpL,0,modpL,mnmpL,mxmpL,ltnpL,gtnpL,eqlpL,},
 {dexpD,addpD,subpD,mulpD,0,modpD,mnmpD,mxmpD,ltnpD,gtnpD,eqlpD,},
};
OV*ara[][11]={//amend
 {dexaB,addaB,subaB,mulaB,0,modaB,mnmaB,mxmaB,ltnaB,gtnaB,eqlaB,},
 {dexaH,addaH,subaH,mulaH,0,modaH,mnmaH,mxmaH,ltnaH,gtnaH,eqlaH,},
 {dexaI,addaI,subaI,mulaI,0,modaI,mnmaI,mxmaI,ltnaI,gtnaI,eqlaI,},
 {dexaL,addaL,subaL,mulaL,0,modaL,mnmaL,mxmaL,ltnaL,gtnaL,eqlaL,},
 {dexaD,addaD,subaD,mulaD,0,modaD,mnmaD,mxmaD,ltnaD,gtnaD,eqlaD,},
};

S C tZx(Ax)_(xtdD?tD:xtL?tL:xtcC?tH:xtZ?xt:xtz?tZ(gl_(x)):tB)
C sup(A*p,A*q)_(Ax=*p,y=*q;Ct=max(tZx(x),tZx(y));*p=x=Ny(ct[t](x));*q=y=Nx(ct[t](y));t)
S A vv(Ax,Ay,Iv)_(P(xtmMA||ytmMA,eac2(av(v),x,y))N(sup(&x,&y));Ik=xtT<<1|ytT;El(k==3&&xn-yn,x,y)
 Ct=k?min(xt,yt):max(xt,yt);V*a=xtP?(V*)&x:xC,*b=ytP?(V*)&y:yC;int(*f)(V*,V*,V*,N)=arf[k][tT(t)-tB][v-4];
 Y(t>tD,t+=tD-td)Y(v>7&&t==tD,t=tI)Y(!k,t+=tc-tC;P(_tP(t),Iv=0;f(a,b,&v,1);x(y(az(v)))))
 Az=xt==t&&xr==1?x:yt==t&&yr==1?y:atn(t,k-1?xn:yn);f(a,b,zC,zn);x==z?y(z):y==z?x(z):x(y(z)))
S A ext(Ax,Nn)_(xtm?enl(x):xtt?rsh(az(n),x):x)
S A2(dct,x=ext(x,yN);y=ext(y,xN);El(xN-yN,x,y)am(x,y))

A2(dex,mr(x);y)
A2(add,adm(x,y,0))
A2(sub,add(x,Nx(neg(y))))
A2(mul,adm(x,y,1))
A2(dvd,vv(x,y,vi('%')))
A2(mod,P(xtl&&gl_(x)==NL,out(x(y)))Xzd(vv(x,y,vi('!')))dct(x,y))
A2(mnm,vv(x,y,vi('&')))
A2(mxm,vv(x,y,vi('|')))
A2(ltn,vv(x,y,vi('<')))
A2(gtn,ltn(y,x))
A2(eql,xtsS&&ytsS?eql(AT(xt+ti-ts,mut(x)),AT(yt+ti-ts,mut(y))):vv(x,y,vi('=')))
