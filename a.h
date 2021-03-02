// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE
//#define DEBUG
#include<unistd.h>
#include"k.h"
#include"g.h"
#define   _(a...) {return({a;});}
#define W(x,a...) while(x){a;}
#define Y(x,a...) if(x){a;}
#define P(x,a...) Y(x,_(a))
#define  EY(a...) else Y(a)
#define   E(a...) else{a;}
#define   i(a...) F_(i,a)
#define   j(a...) F_(j,a)
#define F_(i,n,a...) for(TY(n)n_=(n),i=0;i<n_;i++){a;}
#define BR break
#define O const
#define S static
#define Z sizeof
#define ZZ(x) (Z(x)/Z(*(x)))
#define ZP 4096ll //page
#define ZA 32     //hdr
#define NO __attribute__((noinline))
#define SN S NO
#define TD typedef
#define TY __typeof__
#define ST struct
#define RE restrict
#define SWP(x,y) {TY(x)t_=x;x=y;y=t_;}
#define AL(x) {Q(!((L)x&ZA-1));x=__builtin_assume_aligned(x,ZA);}
#define PD(n,p) ((n)+ZA/Z(*p)-1&-ZA/Z(*p)) //pad
#define M1(x) #x
#define M2(x) M1(x)
#define A(a...) (A[]){a}
#define CH(x,y,a...) (TY(y)[]){y,a}[x] //choose
#ifdef DEBUG
 #define dbg(x) x
 #define Q(x) Y(!(x),die(__FILE__":"M2(__LINE__)": "M2(x))) //assert
 #define die(x) {write(1,x,Z(x));exit(1);}
#else
 #define dbg(x)
 #define Q(x)
#endif

TD void V;TD char B;TD char unsigned C,UC;TD short H;TD unsigned short UH;TD int I;TD unsigned int UI;TD long long L;
TD double D;TD unsigned long long UL,A,A0(),A1(A),A2(A,A),A3(A,A,A),AA(OA*,I),AX(A,OA*,I);
#define A0(f,b...) A f(          )_(b)
#define A1(f,b...) A f(Ax        )_(b)
#define A2(f,b...) A f(Ax,Ay     )_(b)
#define A3(f,b...) A f(Ax,Ay,Az  )_(b)
#define AX(f,b...) A f(Ax,OA*a,In)_(b) //doesn't consume x
#define AA(f,b...) A f(   OA*a,In)_(b)

#define extr(c,x,y) ({TY(x) x_=(x),y_=(y);x_ c y_?x_:y_;})
#define min(a...) extr(<,a)
#define max(a...) extr(>,a)
#define rot(x,y) ({TY(x) x_=(x),y_=(y);x_<<y_|x_>>Z(x)*8-y;})
S L absL(Lv)_(v<0?-v:v)S I c3(Cc,Cv,Cd)_(c<=v&&v<=d)S C hx1(Ii)_(i+(i>9?'a'-10:'0'))S I dgt(Cc)_(c3('0',c,'9'))
S I in(UL i,UL n)_(i<n)

#define ms(a...) __builtin_memset(a)
#define mv(a...) __builtin_memmove(a)
#define mc(a...) __builtin_memcpy(a)
#define mC(a...) __builtin_memcmp(a)
#define mn(a...) __builtin_strlen(a)
V*memcpy(V*,OV*,size_t),*memmove(V*,OV*,size_t),*memset(V*,I,size_t),exit(I);size_t strlen(OC*);
I strcmp(OC*,OC*),memcmp(OV*,OV*,size_t);

//         () "" ,1 ,2 ,3 ,d ,` +!  ! "c" 1  2  3 .3  ` {} 1+ ++ +/ +: +  /
enum      {tA,tC,tH,tI,tL,tD,tS,tM,tm,tc,th,ti,tl,td,ts,to,tp,tq,tr,tu,tv,tw,tn}; //types
#define TS "A""C""H""I""L""D""S""M""m""c""h""i""l""d""s""o""p""q""r""u""v""w" //their symbols
#define TZ  8, 1, 2, 4, 8, 8, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8  //size in bytes
#define Tz  4, 0, 1, 2, 3, 3, 2, 4, 4, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3  //log2(size) or 4=reftypes
#define tB tC
#define tb tc
extern OC Zt[],ZT[];S C At(A);S I _t(Ct)_(t>tm)S I _T(Ct)_(t<tM)S I _z(Ct)_(c3(th,t,tl))S I _Z(Ct)_(c3(tH,t,tL))
S I _F(Ct)_(t>=to)S I _P(Ct)_(c3(tc,t,ti)||t==ts||c3(tu,t,tw))S I _Q(Ct)_(c3(tc,t,ts))S I _R(Ct)_(Zt[t]==4)
S C tT(Ct)_(t==tm?tM:t>=to?tA:t>=tc?t+tC-tc:t) //tT():get corresponding list type

//header bytes: b.oorrrrnnnnnnnn (b=bucket,o=srcoffset,r=refcount,n=length)
//tagged ptr bits (t=type,v=verb,k=arity,o=srcoffset,x=ptr,0=alignment,i=value):
// tttttttt........xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tA,tC,tB,tH,tI,tL,tD,tS,tM,tm,tl,td
// tttttttt........................iiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii tc,tb,th,ti
// tttttttt........ooooooooooooooooiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii ts
// tttttttt.....kkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 to,tp,tq
// tttttttt..vvvkkkxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 tr
// ttttttttvvvvvkkk................................................ tu,tv,tw
#define dat(x) ((V*)((x)<<16>>16))
#define bkt(x) ((C*)dat(x))[-16]
#define Ar(x)  ((I*)dat(x))[-3]
#define _q(x,y) (x=apd(x,y)) //append

//getters                              setters
S  C At(Ax)_(x>>56)                    S A AT(UL t,Ax)_(Q(t<=tn);               x<<8>>8|t<<56)
S  C Av(Ax)_(x>>51&31)                 S A AV(UL v,Ax)_(Q(v<32);          x&~(31ll<<51)|v<<51)
S  C Ak(Ax)_(x>>48&7)                  S A AK(UL k,Ax)_(Q(k<9);           x&~( 7ll<<48)|k<<48)
S UH Ao(Ax)_(xts?x>>32:xtP?0:xH[-7])   S A AO(UL o,Ax)_(Xs(x&~(0xffffll<<32)|o<<32)xH[-7]=o;x)
S UL An(Ax)_(Ln=xL[-1];Q(n<1ll<<48);n) S A AN(UL n,Ax)_(Q(n<1ll<<48);              xL[-1]=n;x)
S A1(mR,Q(x);XP(x)Q(xr>=0);xr++;x)
#define tvk(t,v,k) (A)((UL)(t)<<56|(UL)(v)<<51|(UL)(k)<<48) //type,value,arity

A0 aa0;
A1 a1,aes0,aes1,asc,ax,blw,cf,cmd,cpl,des,dsc,enl,enla,epr,fir,flp,flr,frk,gB,gD,gH,gI,gL,gS,grp,hcl,hex,hop,jsr,jsw,
 kst,las,ldf,len,md5,mr,mr0,mr1,mRa,mut,neg,not,nul,out,prs,rev,sha1,sha256,sha3_256,sin,ser,sqr,sqz,str,str0,til,typ,
 u0c,u1c,unh,unq,val,whr;
A2 a2,add,aM,am,ap1,apn,apd,cat,com,cst,cut,dex,dvd,eql,fil,fnd,gtn,id_,idx,ltn,mnm,mod,mtc,mul,mxm,rsh,sub,v0c,v1c,xpt;
A3 a3,try;
AA amd,am1,dmd,dm1;
AX eac,rdc,scn,eap,ear,eal,app,prj,run;
A aCm(OC*,OC*),aCn(OC*,L),aCz(OC*),apc(A,C),apv(A,OV*),atn(C,L),atnv(C,L,OV*),az(L),catc(A,OC*,L),ea1(A1,A),
 e0(OC*),e1(OC*,A),e2(OC*,A,A),eN(OC*,I,OA*),get(A,L),getr(A,L),kv(A*),room(A,L),wdn(A,L,L,L);
V init(),mrn(I,OA*);
C*syp(I*),art(I,C);
I fB(OV*,I,OV*),fH(OV*,I,OV*),fI(OV*,I,OV*),fL(OV*,I,OV*),fAI(A,I),fpA(A*,A),fpB(A*,B),fpH(A*,H),fpI(A*,I),fpL(A*,L),
 si(OC*,I),eS(A,I),mtc_(A,A),sup(A*,A*),syP(OC*);
L _N(A),now(),pl(C**),pu(C**),tru(A);
TD V(*Fc)(OV*RE,V*RE,L);extern Fc wf[];extern A glb,ce[],cn[],ci[2][5];extern OC vc[];extern L mu;extern A1*ct[];
extern OV*vf[],*arf[][11][4],*arr[][11],*ars[][11],*arp[][11],*ara[][11];
#define m2(x,a...) ({A t_=mr0(x);TY(({a;}))r_=({a;});dbg(x=0);mr1(t_);r_;}) //two-phase free()

#define h(T) S A a##T(Ln)_(atn(t##T,n))
 h(A)h(C)h(B)h(H)h(I)h(L)h(D)h(S)
#undef h
S A ac(Cv)_(AT(tc,v))     S C gc (Ax)_(Q(xtc);x)
S A ab(Bv)_(AT(tb,v))     S B gb (Ax)_(Q(xtb);x)
S A ah(Hv)_(AT(th,v))     S H gh (Ax)_(Q(xth);x)
S A as(Iv)_(AT(ts,v))     S I gs (Ax)_(Q(xts);x)
S A ai(Iv)_(AT(ti,v))     S I gi (Ax)_(Q(xti||xts||xth||xtc);x)
S A al(Lv)_(atnv(tl,1,&v))S L gl_(Ax)_(Xh((H)x)XP((I)x)*xL)S L gl(Ax)_(L r=gl_(x);x(0);r)
S A ad(Dv)_(atnv(td,1,&v))S D gd_(Ax)_(Q(xtd);*xD)S D gd(Ax)_(Dv=*xD;x(0);v)
#define au(i) tvk(tu,i,1)
#define av(i) tvk(tv,i,2)
#define aw(i) tvk(tw,i,1)
#define vi(c) (c==':'?0:c=='+'?1:c=='-'?2:c=='*'?3:c=='%'?4:c=='!'?5:c=='&'?6:c=='|'?7:c=='<'?8:c=='>'?9:c=='='?10:\
 c=='~'?11:c==','?12:c=='^'?13:c=='#'?14:c=='_'?15:c=='$'?16:c=='?'?17:c=='@'?18:c=='.'?19:20+c-'0')
#define cu(c) au(vi(c))
#define cv(c) av(vi(c))
S OA au0=au(0),av0=av(0),OUT=au(25),CMD=au(28),PLH=au(29),PRG=au(30),COM=av(24),MKL=av(25);

#define ND (D)(0./0.)
#define WD __builtin_inf()
#define NL (1ll<<63)
#define WL (~NL)
#define NI (1<<31)
#define WI (~NI)
#define NH (H)(1<<15)
#define WH (~NH)
#define NB -128
#define WB 127

#define iut(t,v...) ({i(un,u##t=({v;}))u;})
#define iua(v...) iut(a,v)
#define iuc(v...) iut(c,v)
#define iuh(v...) iut(h,v)
#define iui(v...) iut(i,v)
#define iul(v...) iut(l,v)
#define iud(v...) iut(d,v)

#define EN(x,y,z,n,...) n
#define EF(f,x,a...) P(x,f(a))
#define E_(t,a...) EF(EN(a,e##t##2,e##t##1,e##t##0),a)
#define EA h(c,cpl)h(d,dom)h(i,idx)h(l,len)h(n,nyi)h(o,io)h(p,prs)h(r,rnk)h(s,stk)h(t,typ)h(v,val)h(z,lmt)
#define h(t,m) A0 e##t##0;A1 e##t##1;A2 e##t##2;S A e##t##n(In,OA*a)_(eN(#m,n,a))
 EA
#undef h
#define N_(r,a) ({A r_=(r);P(!r_,a;0)r_;}) //error pass-through
#define N(r)      N_(r,)
#define N1(x,r)   N_(r,x(0))
#define N2(x,y,r) N_(r,x(y(0)))
#define SF(x,y,s,f...) ({Li=gl(K(s"?",x));Ed(i<0,y);CH(i,&f)(y);})

#define ov(x) ov_(#x":",(L)(x))
#define ox(x) ox_(#x":",(A)(x))
#define oo os("["__FILE__":"M2(__LINE__)"]");
#define nop {asm volatile("fnop");}
S I os(OC*x)_(write(2,x,mn(x)))
S I oh(Ln)_(C s[17];s[16]=0;i(16,s[15-i]=hx1(n&15);n>>=4)write(2,s,17))
S I ol(Ln)_(C b[32],*u=b+31;L m=n<0;Y(m,n=-n)do{*u--='0'+n%10;n/=10;}while(n);Y(m,*u--='-')write(2,u+1,b+31-u))
S L ov_(C*s,Ln)_(os(s);write(2,"           ",max(1,10-mn(s)));oh(n);write(2,"\n",1);n)
S A ox_(C*s,Ax)_(os(s);oh((L)x);P(!x,0)Y(!xtP,os("t");ol(xt);os("r");ol(xr);os("n");ol(xn))os(" ");out(x))
