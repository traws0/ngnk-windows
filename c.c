#include"a.h" // ngn/k, (c) 2019-2024 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
Z L ms[3][3]={{0xFF00FF00FF00FF00,0xFFFFFFFFFFFFFFFF,0xFFFFFFFFFFFFFFFF},{0xFFFFFF00FFFFFF00,0xFFFF0000FFFF0000,0xFFFFFFFFFFFFFFFF},{0xFFFFFFFFFFFFFF00,0xFFFFFFFFFFFF0000,0xFFFFFFFF00000000}};
#define abn V*RES a,CO V*RES b,U n
#define M(x,y,z) Z V c##x##y(abn){x*r=AL(a);CO y*p=AL(b);F(n+((1<<z)-1)>>z,Fj(1<<z,*r++=*p++))}
 M(H,G,4)M(G,H,4)M(H,I,3)M(I,H,3)M(G,I,3)M(I,G,3)M(H,L,2)M(L,I,2)M(I,L,2)M(G,L,2)//cHG cGH cHI cIH cGI cIG cHL cLI cIL cGL
#undef M
Z V cFL(abn){F*r=AL(a);CO L*p=AL(b);F(n+3>>2,Fj(4,*r++=*p==NL?NF:*p;p++))}
Z V cLF(abn){L*r=AL(a);CO F*p=AL(b);F(n+3>>2,Fj(4,*r++=*p!=*p?NL:*p;p++))}
Z V cGB(abn){W VS(32)*r=AL(a);CO UC VS(4)*p=AL(b);F(n+31>>5,W v VS(32)=CVV(*p++,TY(v));v|=v<<28;v|=v<<14;v|=v<<7;*r++=v&0x0101010101010101)}
Z V cBG(abn){UC VS(4)*r=AL(a);CO W VS(32)*p=AL(b);F(n+31>>5,W v VS(32)=*p++&0x0101010101010101;v|=v>>7;v|=v>>14;v|=v>>28;*r++=CVV(v,TY(*r)))}
Z V cLA(abn){L*r=AL(a);CO A*p=AL(b);F(n,*r++=gl_(*p++))}
Z A2(cT,UC t=xv,u=yt,i=t-tB,j=u-tB;Q(i<8);P(j>6,et(y))
 Z CO TY(&cBG)a[][8]={{0,cBG,0,0,0,0,cBG},{cGB,0,cGH,cGI,cGL,0,0},{0,cHG,0,cHI,cHL,0,cHG},{0,cIG,cIH,0,cIL,0,cIG},{0,0,0,cLI,0,cLF,0},{0,0,0,0,cFL,0,0},{},{}};
 TY(&cBG)f=a[i][j];P(f,A z=an(yn,t);f(zV,yV,zn);y(z))
 P(t==tS,u==tC?(y=str0(y),y(sym(yV))):et(y))
 P((1<<t|1<<u)==(1<<tG|1<<tC),AT(t,mut(y)))
 cT(t,N(cT(u==tB?tG:G(tG,tI,tI,tL,tI,tL,tG,tC)[i],y))))
NI A2(ct,UC t=xv,u=yt;Q(xti||x==t)Q(tB<=t&&t<=tS)P(t==TT[u],y)
 Y(RmMA(r2f(ct,ai(t),y))RE(cT(x,gZ(y)))Rf(ct(x,al(gf(y))))Rilc(L v=gl(y);S(t,RB(ai(v&1))R3(tG,tH,tI,ai(v))RC(ac(v))RL(al(v))RF(af(v))RS(u==tc?as(yv):et0()))0)R_(cT(x,y)))et(y))
A1(cB,ct(ai(tB),x))A1(cG,ct(ai(tG),x))A1(cH,ct(ai(tH),x))A1(cI,ct(ai(tI),x))A1(cL,ct(ai(tL),x))A1(cF,ct(ai(tF),x))A1(cC,ct(ai(tC),x))A1(cS,ct(ai(tS),x))
Z X1(csti,RmMA(e1f(csti,x))RF(sqzZ(cL(x)))Rf(az(gf(x)))RC(cG(x))Rc(ai(xv))Ruvw(ai(xv))RilEGHIL(x)R_(et(x)))
Z X1(prsB,RmMA(e1f(prsB,x))Rc(prsB(enl(x)))RC(A u=aV(tL,xn+7>>3,xV);uT=tB;un=xn<<3;x(u))Ril(x=mut(ct(ai(tL),x));xT=tB;xn<<=6;x)RGHIL(x=cL(x);A u=aV(tL,xn,xV);uT=tB;un<<=6;x(u))R_(et(x)))

Z X1(prsI,RmMA(e1f(prsI,x))Rc(prsI(enl(x)))RC(x=str0(x);S s=xV;P(!*s,x(_R(cn[tl])))L v=pl(&s);x(*s?_R(cn[tl]):az(v)      ))
     RB(N n=(xn-1+(1<<6))>>6,m=xn;A u=MINE(x)?xR:aV(tL,n,xV);uT=tL;un=n;I(m%64,uL[un-1]&=-1+(1ull<<(m%64u)));x(u))R_(et(x)))
Z X1(prsF,RmMA(e1f(prsF,x))Rc(prsF(enl(x)))RC(x=str0(x);S s=xV;P(!*s,x(_R(cn[tf])))L v=pf(&s);x(*s?_R(cn[tf]):aV(tf,1,&v)))R_(et(x)))
Z X1(prsC,RmMA(e1f(prsC,x))Rc(prsC(enl(x)))RB(N n=xn;A u=MINE(x)?xR:aV(tB,n,xV);uT=tC;un=n+7>>3;I(n%8u,uC[un-1]&=-1+(1<<(n%8u)));x(u))R_(et(x)))
Z Y2(pad,RmMA(e2f(pad,x,y))RC(K2("{y@(!x)+(x<0)*#y}",x,y))Rc(dlr(x,enl(y)))R_(et(y)))
X2(dlr,Rs(I v=xv;P(v-(C)v,ed(y))G(&csti,cF,cC,cS,cB,prsB,prsC,prsI,prsF,ed)[si("ifcsbBCIF",v|'s'*!v)](y))Ril(pad(x,y))R_(et(y)))
A1(sqzZ,XB(x)XG(x)C r=0,t=xT;U n=xN,w=Tw[t]-3;L *m=ms[w-1];CO L*y=AL(xV);MS(xG+(n<<w),0,-n%(1u<<5-w)<<w);
   F((n-1+(1<<5-w))>>5-w,W(1,L h=0;Fj(4,L v=yL[4*i+j];h|=m[r]&v+(~m[r]&v))B(!h)P(++r==w,x)))ct(ai(4+r),x))
Z A sqzA(A x,C t)_(U n=xn,w=Tw[t];Q(w-3<4u)P(w==6,A y=an(n,t);cLA(yV,xV,n);x(y))A y=an(n,w==5?t:tI);cIL(yV,xV,n);x(0);ct(ai(t),y))
A1(sqz,P(!xtA,x)U n=xn;A y=xx;C t=yt;
 Y(Ril(B l=0;F(n,A y=xa;I(ytl,l=1)E(P(!yti,x)))
       P(l,sqzA(x,tL))
       A z=an(n,tI);cIL(zV,xV,n);x=x(z);
       I a=0;F(n,I v=xi;a|=v^v>>31)t=tZ(a);P(t==tI,x)
       A y=an(n,t);G(&cGI,cHI)[t-tG](yV,xV,n);x(y))
   R3(tf,tc,ts,F(n,P(_t(xa)-t,x))sqzA(x,TT[t]))
   Rm(P(!n,x)F(n,P(_t(xa)-tm||!mtc_(yx,_x(xa)),x))y=aM(_R(yx),blw(e1f(rs0,_R(yy))));F(n,PSH(y,_R(xa)))x(y))
   R_(x))0)
X1(blw,RA(x)Rt(aA1(x))Rm(et(x))R_(U n=xN;A y=aA(n);F(n|!n,ya=ii(x,i))x(0);I(!n,yx=mkn(yx))y))
A1(gZ,Lij x(0);P(i<0,x=az(i);x(add(x,gZ(aE(0,j-i)))))C t=MAX(tZ(i),tZ(j-1));x=an(j-i,t);tilV(xV,i,j-i,t-tG);x)
