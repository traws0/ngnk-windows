// ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#define DBG(a...) //a
#include<unistd.h>
#include"g.h"
#define   _(a...) {return({a;});}
#define W(x,a...) while(x){a;}
#define V(x,a...) TY(a)x=(a);
#define B(x,a...) I(x,a;break)
#define P(x,a...) I(x,_(a))
#define I(x,a...) if(x){a;}
#define Y(x,a...) switch(x){a}
#define C(x,a...) case x:return({a;});
#define T(x,a...) (TY(x)[]){x,a}
#define   J(a...) else I(a)
#define   E(a...) else{a;}
#define   A(a...) (A[]){a}
#define   i(a...) ij(i,a)
#define   j(a...) ij(j,a)
#define ij(i,n,a...) for(TY(n)n_=(n),i=0;i<n_;i++){a;}
#define O const
#define S static
#define SZ sizeof
#define ZZ(x) (SZ(x)/SZ((x)[0]))
#define ZP 4096ll //page
#define ZA 32ll   //hdr
#define NI __attribute__((noinline))
#define SN S NI
#define TD typedef
#define TY __typeof__
#define ST struct
#define RE restrict
#define SWP(x,y) {TY(x)t_=x;x=y;y=t_;}
#define LN(x) {Q(!((L)x&ZA-1));x=__builtin_assume_aligned(x,ZA);} //alignment
#define PD(n,p) ((n)+ZA/SZ(*p)-1&-ZA/SZ(*p)) //pad
#define M1(x) #x
#define M2(x) M1(x)
#define EX extern
#define Q(x) DBG(I(!(x),die(__FILE__":"M2(__LINE__)": "M2(x)"\n"))) //assert
#define Ab8 A b[8];
#define Ms(a...) __builtin_memset(a)
#define Mm(a...) __builtin_memmove(a)
#define Mc(a...) __builtin_memcpy(a)
#define MQ(a...) __builtin_memcmp(a)
#define MC(a...) __builtin_memchr(a)
#define Sn(a...) __builtin_strlen(a)
#define SC(a...) __builtin_strchr(a)
#define SS(a...) __builtin_strstr(a)
#define SQ(a...) __builtin_strcmp(a)
#define MM(a...) memmem(a)
#define SC0(a...) strchrnul(a)
#define min(x,y) extr(x,y,<)
#define max(x,y) extr(x,y,>)
#define extr(x,y,c) ({TY(x) x_=(x),y_=(y);x_ c y_?x_:y_;})
#define rot(x,y) ({TY(x) x_=(x);TY(y) y_=(y);y?x_<<y_|x_>>SZ(x)*8-y_:x;})
#define in(i,n) ((i)<(UL)(n))
#define c3(x,y,z) ((y)-(x)<=(UI)((z)-(x)))
#define c09(c) c3('0',c,'9')
#define cAz(c) c3('a',(c)|32,'z')
#define cA9(c) (cAz(c)||c09(c))

TD void V;TD char B;TD char unsigned C,UC;TD O char*Q;TD short H;TD unsigned short UH;TD int I;TD unsigned int UI;
TD long long L;TD double D;TD size_t N;
TD unsigned long long UL,A,A0(),A1(A),A2(A,A),A3(A,A,A),A4(A,A,A,A),AA(OA*,I),AX(A,OA*,I),AL(L),ALA(L,A),AAL(A,L),AQ(Q);
#define  A0(f,b...) A f(           )_(b)
#define  A1(f,b...) A f(Ax         )_(b)
#define  A2(f,b...) A f(Ax,Ay      )_(b)
#define  A3(f,b...) A f(Ax,Ay,Az   )_(b)
#define  A4(f,b...) A f(Ax,Ay,Az,Au)_(b)
#define  AX(f,b...) A f(Ax,OA*a,In )_(b) //doesn't consume x
#define  AA(f,b...) A f(   OA*a,In )_(b)
#define  AL(f,b...) A f(Ln         )_(b)
#define ALA(f,b...) A f(Ln,Ax      )_(b)
#define AAL(f,b...) A f(Ax,Li      )_(b)
#define  AQ(f,b...) A f(Qs         )_(b)
A1 a1,asc,ax,cA,cC,cD,cH,cI,cL,cS,des,dsc,enl,enla,epr,fir,flp,flr,frk,grp,hex,js0,js1,kst,ksin,kcos,klog,kexp,las,
 len,mr,m0,m1,mRa,mut,neg,not,nul,opn,out,prng,prs,rev,ser,spl,sqr,sqz,sqzZ,str,str0,til,typ,u0c,u1c,unh,unq,val,whr,_R;
A2 a2,add,aM,am,ap1,dot,apd,bin,cat,cst,cut,dct,dex,dvd,eql,fil,fnd,gtn,id_,idx,ltn,mnm,mod,mtc,mul,mxm,que,fld1,
 hsh,sub,v0c,v1c,exc,_1;
A0 aa0;A3 a3,arf,arp,ars,cpl,try,ear2,_2;A4 ara,dm4;ALA drp,room,rsh;AAL ii;AX adv,eac,fld,prj,run,_8;AA am8,dmd,dm8,ins;
AL aA,aB,aC,aI,aL,aD,aS,al,az,cls,tilL,rndD;AQ aCz,cmdl,cmdm,die,evs,pk,syP;
A ac(C),ai(I),as(I),ad(D),adm(A,A,I),aCm(Q,Q),aCn(Q,N),apc(A,C),apv(A,OV*),an(C,N),aV(C,N,OV*),cts(A,Q,N),eac1f(A,A1),
 eac2f(A,A,A2),e1(A,Q),K0(A*,Q,OA*,I),jc(C,A),jC(Q,N,A),kv(A*),mf(I,N),mnd(OA*,I,AA*),pen(A,A1*),sur(C,A,C),wdn(A,N,N,N),
 AT(UL,A),AV(UL,A),AW(C,A),AK(C,A),AO(UC,A),AN(N,A);
V dir(I,void(*)(V*,Q),V*),exit(I),kinit(),*memchr(OV*,I,N),*memcpy(V*,OV*,N),*memmem(OV*,N,OV*,N),*memmove(V*,OV*,N),
 *memset(V*,I,N),mrn(N,OA*),mRn(N,OA*),tilV(V*,L,I);
D gd(A);N strlen(Q),_N(A);C*sl(C*,L),sup(A*,A*),*syp(L*),tZ(L);char*strchr(O char*,I),*strchrnul(O char*,I),*strstr(Q,Q);
I _K(A),qD(D,D),eS(A,I),js_eval(C*,I,C*,I),memcmp(OV*,OV*,N),mtc_(A,A),repl(),si(Q,I),strcmp(Q,Q),rnk(A);
L cfm(OA*,I),gl_(A),gl(A),now(),pl(Q*),pu(Q*),tru(A),fI(OV*,N,L),fL(OV*,N,L),fAI(A,I),fpI(A*,I);
EX I gn,gk[];EX A gv[],cns,ce[],cn[],ci[2][5];EX A1*v1[],*cT[];EX A2*v2[];EX AA*v8[];EX Q*argv,*env;EX OC vc[],Tz[],TZ[],TT[];

//            () ,3 ,4 ,5 ,6 ,d "" ,` +!  !  5  6 .6 "c" ` {} 1+ ++ +/ +:  +  / 2:
enum       {tA=1,tB,tH,tI,tL,tD,tC,tS,tM,tm,ti,tl,td,tc,ts,to,tp,tq,tr,tu,tv,tw,te,tn}; //types
#define TS "?""A""I""I""I""I""D""C""S""M""m""i""i""d""c""s""o""p""q""r""u""v""w""e"     //their symbols
#define TZv 0, 8, 1, 2, 4, 8, 8, 1, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8      //item size in bytes
#define Tzv 0, 4, 0, 1, 2, 3, 3, 0, 2, 4, 4, 3, 3, 3, 3, 3, 4, 4, 4, 4, 3, 3, 3, 3      //log2(size) or 4=reftypes
#define TTv 0,tA,tB,tH,tI,tL,tD,tC,tS,tM,tM,tI,tL,tD,tC,tS,tA,tA,tA,tA,tA,tA,tA,tA      //corresponding list type
#define TP(t) ((1<<ti|1<<tc|1<<ts|1<<tu|1<<tv|1<<tw|1<<te)>>(t)&1)
#define TF(t) ((t)>=to)

//header bytes: Ut.orrrrnnnnnnnn (U=bucket,t=type,o=srcoffset(or:w=adverb,k=arity),r=refcount,n=length)
//tagged ptr bits (t=type,v=value,o=srcoffset,x=ptr):
// tttttttt........................vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv tc,ti,tu,tv,tw
// tttttttt................oooooooovvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv ts
// tttttttt........xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx te
// ................xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx00000 other
#define _V(x) (V*)(x)          //ptr to data
#define _W(x) TZ[_t(x)]        //item size in bytes
#define _k(x) _C(x)[-13]       //arity(for funcs)
#define _n(x) _L(x)[-1]        //length
#define _o(x) (_ts(x)?(x)>>32:_tP(x)?0u:_B(x)[-13]) //srcoffset
#define _q(x,y) (x=apd(x,y))   //append
#define _r(x) ((I*)_V(x))[-3]  //refcount
#define _t(x) ({Ct=_t0(x);t?t:_t1(x);}) //type
#define _t0(x) ((x)>>56)       //type(tag)
#define _t1(x) _C(x)[-15]      //type(hdr)
#define _tF(x) TF(_t(x))       // func?
#define _tP(x) TP(_t(x))       // packed?
#define _tR(x) (Tz[_t(x)]==4)  // ref?
#define _tT(x) (_t(x)<tM)      // list?
#define _tZ(x) c3(tB,_t(x),tL) // intlist?
#define _tt(x) (_t(x)>tm)      // atom?
#define _tz(x) c3(ti,_t(x),tl) // intatom?
#define _v(x) (I)(x)           //value
#define _w(x) _C(x)[-14]       //adverb(for tr)
#define _U(x) _C(x)[-16]       //bucket
#define _X(x) _A(x)[-3]        //next
#define _Z(x) ((ZA<<_U(x))-ZA) //capacity
#define _e(x,a...) ({A t_=m0(x);TY(({a;}))r_=({a;});DBG(x=0);m1(t_);r_;}) //two-phase free()

#define Lt(t) (L)t<<56
#define ac(v) (Lt(tc)|(UC)(v))
#define ai(v) (Lt(ti)|(UI)(v))
#define as(v) (Lt(ts)|(UI)(v))
#define VS \
  A1*v1[]={sam,flp,neg,fir,sqr,til,whr,rev,asc,dsc,grp,not,enl,nul,len,flr,str,unq,typ,val,u0c,u1c,sam,sam,las,out};\
  A2*v2[]={dex,add,sub,mul,dvd,mod,mnm,mxm,ltn,gtn,eql,mtc,cat,exc,hsh,cut,cst,que,ap1,dot,v0c,v1c,dex,com,dex,dex};\
  AA*v8[]={er8,er8,er8,er8,er8,er8,er8,er8,er8,er8,er8,er8,er8,er8,er8,er8,er8,ins,am8,dmd,er8,er8,er8,er8,er8,er8};\
  OC vc[]={':','+','-','*','%','!','&','|','<','>','=','~',',','^','#','_','$','?','@','.','0','1','2','3','4','5'};
enum{au=Lt(tu),FLP,NEG,FIR,SQR,TIL,WHR,REV,ASC,DSC,GRP,NOT,ENL,NUL,LEN,FLR,STR,UNQ,TYP,VAL,U0C,U1C,U2C,U3C,LAS,OUT,
     av=Lt(tv),ADD,SUB,MUL,DVD,MOD,MNM,MXM,LTN,GTN,EQL,MTC,CAT,EXC,RSH,CUT,CST,QUE,AP1,DOT,V0C,V1C,V2C,COM,MKL,PLH,
     aw=Lt(tw),PRG=PLH};
#define ND (D)(0./0.)
#define WD __builtin_inf()
#define NL (1ll<<63)
#define WL (~NL)
#define K(s,a...) ({S A f;K0(&f,s,A(a),ZZ(A(a)));})

#define EA h(c,compile)h(d,domain)h(i,index)h(l,length)h(n,nyi)h(o,io)h(p,parse)h(r,rank)h(s,stack)h(t,type)h(v,value)h(z,limit)
#define h(t,m) A0 e##t##0;A1 e##t##1;A2 e##t##2;AA e##t##8;
 EA
#undef h
#define N(x,a...) ({A r_=(x);P(!r_,a;0)r_;}) //error pass-through

#define ov(x) ov_(#x":",(L)(x))
#define oo os("["__FILE__":"M2(__LINE__)"]");
#define nop {asm volatile("fnop");}
I os(Q);L ov_(Q,N);
