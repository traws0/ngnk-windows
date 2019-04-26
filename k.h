#define dbg(x...) //x

#define B break
#define $(x,y...)  if(x){y;}
#define E(x...)    else{x;}
#define E$(x,y...) else if(x){y;}
#define N __attribute__((noinline))
#define O const
#define Q(x,a...)  case x:{a;B;}
#define Q2(x,a...) case x:Q(a)
#define Q3(x,a...) case x:Q2(a)
#define Q4(x,a...) case x:Q3(a)
#define Q5(x,a...) case x:Q4(a)
#define R return
#define S static
#define SI S inline
#define W(x,y...) while(x){y;}
#define DW(x,y) do{x;}while(y);
#define Y(x,y,z...) switch(x){default:{y;break;}z}
#define TD typedef
TD char      C;TD unsigned char      UC;
TD short     H;TD unsigned short     UH;
TD long long I;TD unsigned long long UI;
TD void V;TD double F;TD V*A __attribute__((align_value(16)));

#define A(x) ((A*)(x))
#define C(x) ((C*)(x))
#define I(x) ((I*)(x))
#define F(x) ((F*)(x))

#define fi(n,b...) for(I n_=(n),i=0;i<n_;i++){b;}
#define fj(n,b...) for(I n_=(n),j=0;j<n_;j++){b;}
#define min(x,y)   ({typeof(x)x_=(x),y_=(y);x_<y_?x_:y_;})
#define max(x,y)   ({typeof(x)x_=(x),y_=(y);x_>y_?x_:y_;})
#define abs(x)     ({typeof(x)x_=(x);x_<0?-x_:x_;})

#include<sys/syscall.h>
#define sc(f,regs...)      ({I r;asm volatile("syscall":"=a"(r):"0"(SYS_##f)regs:"cc","rcx","r11","memory");r;})
#define sc0(f      )       sc(f                      )
#define sc1(f,x    )       sc(f,,"D"(x)              )
#define sc2(f,x,y  )       sc(f,,"D"(x),"S"(y)       )
#define sc3(f,x,y,z)       sc(f,,"D"(x),"S"(y),"d"(z))
#define read(a...)         sc3(read  ,a)
#define write(a...)        sc3(write ,a)
#define open(a...)         sc3(open  ,a)
#define close(a...)        sc1(close ,a)
#define fstat(a...)        sc2(fstat ,a)
#define dup2(a...)         sc2(dup2  ,a)
#define execve(a...)       sc3(execve,a)
#define pipe2(a...)        sc2(pipe2 ,a)
#define fork()             sc0(fork)
#define munmap(a...)       sc2(munmap,a)
#define exit(a...)         sc1(exit  ,a)
#define gettimeofday(a...) sc2(gettimeofday,a)
#define mmap_(x,y,z,t,u,v) ({register I r10 asm("r10")=t,r8 asm("r8")=u,r9 asm("r9")=v;\
                             (V*)sc(mmap,,"D"(x),"S"(y),"d"(z),"r"(r10),"r"(r8),"r"(r9));})

#define tX  0 // ()
#define tC  1 // "ab"
#define tI  2 // 0 1
#define tS  3 // `a`b
#define tF  4 // 0.1 2.3
#define tA  5 // +`a`b!0 1
#define ta  6 // `a`b!0 1
#define tl  7 // {}
#define tp  8 // f[0;]
#define tq  9 // +:+
#define tr 10 // +/
#define tu 11 // +:
#define tv 12 // +
#define tw 13 // /
#define te 14 // `lib 2:(`f;1)
#define tn 15 // number of types
#define to tF // offset
#define tc (-tC) // "a"
#define ti (-tI) // 0
#define ts (-tS) // `a
#define tf (-tF) // 0.1
SI I isRef (C t){R 1&((1<<tX|1<<ta|1<<tA|1<<tl|1<<tp|1<<tq|1<<tr)>>t);}
SI I isFn  (C t){R t>=tl;}
SI I isAtom(C t){R t<0||t>=tl;}
SI C tInv  (C t){R -t;} //atom <-> list
SI C tList (C t){R abs(t);} //atom|list -> list

TD struct{C b,t;UH o;UI r:32;I n;}Hdr; //bucket,type,offset(or verb rank),refcount,length
TD struct{A s,b,l,g,c,m;}*L; //lambda:source,bytecode,locals,globals,constants,map
#define hdr(t,o,r,n) ((UC)(67-__builtin_clzll(((t)==tC?((n)+15)>>3:(n)+1)))|(UC)(t)<<8|(UI)(o)<<16|(UI)(r)<<32)

#define Ab(x) ((Hdr*)(x))[-1].b
#define At(x) ((Hdr*)(x))[-1].t
#define Ar(x) ((Hdr*)(x))[-1].r
#define An(x) ((Hdr*)(x))[-1].n
#define Ao(x) ((Hdr*)(x))[-1].o

#define xb Ab(x)
#define xt At(x)
#define xr Ar(x)
#define xn An(x)
#define yb Ab(y)
#define yt At(y)
#define yr Ar(y)
#define yn An(y)
#define zb Ab(z)
#define zt At(z)
#define zr Ar(z)
#define zn An(z)
#define ub Ab(u)
#define ut At(u)
#define ur Ar(u)
#define un An(u)

#define xc C(x)
#define xi I(x)
#define xf F(x)
#define xa A(x)
#define yc C(y)
#define yi I(y)
#define yf F(y)
#define ya A(y)
#define zc C(z)
#define zi I(z)
#define zf F(z)
#define za A(z)
#define uc C(u)
#define ui I(u)
#define uf F(u)
#define ua A(u)

#define xci xc[i]
#define xcj xc[j]
#define xii xi[i]
#define xij xi[j]
#define xfi xf[i]
#define xfj xf[j]
#define xai xa[i]
#define xaj xa[j]
#define yci yc[i]
#define ycj yc[j]
#define yii yi[i]
#define yij yi[j]
#define yfi yf[i]
#define yfj yf[j]
#define yai ya[i]
#define yaj ya[j]
#define zci zc[i]
#define zcj zc[j]
#define zii zi[i]
#define zij zi[j]
#define zfi zf[i]
#define zfj zf[j]
#define zai za[i]
#define zaj za[j]
#define uci uc[i]
#define ucj uc[j]
#define uii ui[i]
#define uij ui[j]
#define ufi uf[i]
#define ufj uf[j]
#define uai ua[i]
#define uaj ua[j]

#define xx xa[0]
#define xy xa[1]
#define yx ya[0]
#define yy ya[1]
#define zx za[0]
#define zy za[1]
#define ux ua[0]
#define uy ua[1]

#define pagesize 4096LL
#define Z sizeof
#define ZZ(x) (Z(x)/Z(*(x)))
#define ZV Z(V*)
#define ZC Z(C)
#define ZI Z(I)
#define ZF Z(F)
#define ZHdr Z(Hdr)
#define tz(t) tz_[to+(t)] //type size in bytes
extern O C tz_[];

#define W1 0 //1-byte data types
#define W8 1 //8-byte data types
#define W0 2 //ref types
#define h(t,w) ((I)w<<(((31&(t))<<1)))|
S O I tW_=h(tf,W8)h(ts,W8)h(ti,W8)h(tc,W1)h(tX,W0)h(tC,W1)h(tI,W8)h(tS,W8)h(tF,W8)
          h(ta,W0)h(tA,W0)h(tl,W0)h(tp,W0)h(tq,W0)h(tr,W0)h(tu,W8)h(tv,W8)h(tw,W8)h(te,W8)0;
#undef h
SI C tW(C t){R 3&tW_>>(63&((t)<<1));} //type size as one of W1 W8 W0

#define mstr(x) #x
#define xstr(x) mstr(x)
#define en e("nyi"dbg(":"__FILE__":"xstr(__LINE__)))
#define el e("len"dbg(":"__FILE__":"xstr(__LINE__)))
#define et e("typ"dbg(":"__FILE__":"xstr(__LINE__)))
#define ed e("dom"dbg(":"__FILE__":"xstr(__LINE__)))
#define er e("rnk"dbg(":"__FILE__":"xstr(__LINE__)))
#define ef e("fnc"dbg(":"__FILE__":"xstr(__LINE__)))
#define ei e("idx"dbg(":"__FILE__":"xstr(__LINE__)))
#define ez e("lmt"dbg(":"__FILE__":"xstr(__LINE__)))
#define ea(x) dbg($(!(x),e(__FILE__":"xstr(__LINE__)": "xstr(x)))) //assert
A e(C*); //error. gets source offset for the current bytecode instruction from the lambda's .m
V eo(C*,A,UH); //error with explicit source offset

//memory management
extern A symlist,mx[];
A mm(I),ma(I,I),acm(C*,C*);V miAll(A),mdAll(A),*memcpy(V*,O V*,I);I m_used(),sym(C*,I),strlen(O C*);
#define nxt(x) A(x)[-2]
SI V mf_(A x){ea(!xr);UC b=xb;nxt(x)=mx[b];mx[b]=x;} //free (non-recursive)
SI V mf(A x){$(isRef(xt),mdAll(x))mf_(x);} //free
SI A mi(A x){ea(xr>=0);xr++;R x;}      //ref
SI A mo(A x){ea(xr> 0);xr--;R x;}      //unref without consuming
SI V mu(A x){ea(xr>=0);$(!  xr,mf(x))} //consume
SI V md(A x){ea(xr> 0);$(!--xr,mf(x))} //unref and consume
SI A symstr(I i){R A(symlist)[i];}     //get the string corresponding to a `symbol. guranteed '\0' after last char

//constructors
SI A atnr(C t,I n,I r){R ma(hdr(t,0,r,n),n);}
SI A atno(C t,I n,UH o){R ma(hdr(t,o,0,n),n);}
SI A atn(C t,I n){R atnr(t,n,0);} //allocate with type and length
#define atv(t,v) ({A atv_r=atn((t),1);*(typeof(v)*)atv_r=(v);atv_r;}) //allocate with type and value
SI A ax(A x){R xr?atn(xt,xn):x;}  //allocate of the same type and length as x, attempting reuse
SI A aX(I n){R atn(tX,n);}        //allocate a generic list
SI A aC(I n){R atn(tC,n);} SI A ac(C v){R atv(tc,v);}
SI A aI(I n){R atn(tI,n);} SI A ai(I v){R atv(ti,v);}
SI A aS(I n){R atn(tS,n);} SI A as(I v){R atv(ts,v);}
SI A aF(I n){R atn(tF,n);} SI A af(F v){R atv(tf,v);}
SI A aA (A x,A y         ){mi(x);mi(y);      A u=atn (tA,2  );ux=x;uy=y;        R u;} //+x!y
SI A aa (A x,A y         ){mi(x);mi(y);      A u=atn (ta,2  );ux=x;uy=y;        R u;} //x!y
SI A a1 (A x             ){mi(x);            A u=atn (tX,1  );ux=x;             R u;} //,x
SI A a2 (A x,A y         ){mi(x);mi(y);      A u=atn (tX,2  );ux=x;uy=y;        R u;} //(x;y)
SI A a3 (A x,A y,A z     ){mi(x);mi(y);mi(z);A u=atn (tX,3  );ux=x;uy=y;ua[2]=z;R u;} //(x;y;z)
SI A a2o(A x,A y,    UH o){mi(x);mi(y);      A u=atno(tX,2,o);ux=x;uy=y;        R u;}
SI A a3o(A x,A y,A z,UH o){mi(x);mi(y);mi(z);A u=atno(tX,3,o);ux=x;uy=y;ua[2]=z;R u;}

#define v1(f) A f(A x)
#define v2(f) A f(A x,A y)
TD v1(v1);v1 sam,flp,neg,fst,sqr,til,whr,rev,asc,dsc,grp,not,enl,nul,cnt,flr,str,unq,typ,val,u0c,u1c,str0,prs,ldf,blw,sqz,cpl,json,out,nil,gl,gd,id_,cmd,mut,mut01,mut10,hopen,hclose,lst;
TD v2(v2);v2 dex,add,sub,mul,div,mod,mxm,mnm,ltn,gtn,eql,mtc,cat,xpt,rsh,cut,cst,fnd,ap1,app,v0c,v1c,v2c,sys,cps,idx,idx_,apd;
TD A vn(A,A*,I);vn eac,rdc,scn,eap,ear,eal;
A glb,apdc(A,C),apdi(A,I),apdf(A,F),apdx(A,A),apply(A,A*,I),prj(A,A*,I),run(L,A*,I),emptyctx(),amd(A*,I),dmd(A*,I),each(vn,A,A*,I,I);
I fndai(A,I),fndi(A,I),fnda(A,A),fndpc(A*,C),fndpi(A*,I),fndpa(A*,A),mtc_(A,A),tru(A);
V ___();

#define vrbval(x) (31&(((V*)(x)-cu0))/Z(*cuvw_))
SI V*vrbfnc(A x){ea(xt==tu||xt==tv||xt==tw);R(V*)xi[1];}
#define _A(x)  (ZHdr+(V*)(x))
#define cb(i)  _A(cb_[i])        //bools (ints 0 and 1)
#define cu(i)  _A(cuvw_[i])      //unary verbs
#define cv(i)  _A(cuvw_[32+(i)]) //binary verbs
#define cw(i)  _A(cuvw_[64+(i)]) //adverbs
#define cea    _A(cea_) //()
#define cu0    cu( 0) //::
#define cu_fst cu( 3) //*:
#define cu_rev cu( 7) //|:
#define cu_str cu(16) //$:
#define cu_cmd cu(31) //\cmd
#define cv0    cv( 0) //:
#define cv_add cv( 1) //+
#define cv_cat cv(12) //,
#define cv_cst cv(16) //$
#define cv_fnd cv(17) //?
#define cv_ap1 cv(18) //@
#define cv_app cv(19) //.
#define cv_plc cv(29) //placeholder in projections
#define cv_lis cv(30) //(x;y;z) create list
#define cv_cps cv(31) //'[+;*] compose
#define cn(t)  cn_[t] //nulls
#define _0W    0x7fffffffffffffffll
#define _0N    0x8000000000000000ll
#define _0n    (0.0/0.0)
#define _0w    (0.1/0.0)
extern O C cf[20];  //verb symbols
extern O I cii[11]; //integer identities for arithmetic verbs
extern O F cif[11]; //floating-point identities for arithmetic verbs
extern O A cn_[tn]; //nulls
TD I I4[4]__attribute__((aligned(32)));extern I4 cb_[2],cuvw_[32+32+6],c1h_,cea_; //pre-allocated objects, never freed
SI I isArith(A x){R cv0<=x&&x<cv(ZZ(cii));}

//indices of predefined symbols
#define s_x 1
#define s_y 2
#define s_z 3
#define s_o 4
#define s_p 5
#define s_j 6
#define s_t 7

SI I  gi(A x){mu(x);R*xi;}
SI F  gf(A x){mu(x);R*xf;}
SI UC gc(A x){mu(x);R*xc;}

#define arI(f,n,p)Y(f,,\
 Q( 0,fi(n,p ((V)a,b)                 ))\
 Q( 1,fi(n,p a+b                      ))\
 Q( 2,fi(n,p a-b                      ))\
 Q( 3,fi(n,p a*b                      ))\
 Q( 4,fi(n,p b?a/b:!a?_0N:a>0?_0W:-_0W))\
 Q( 5,fi(n,p a>0?(b%a+a)%a:a?b/-a:_0N ))\
 Q( 6,fi(n,p min(a,b)                 ))\
 Q( 7,fi(n,p max(a,b)                 ))\
 Q( 8,fi(n,p a<b                      ))\
 Q( 9,fi(n,p a>b                      ))\
 Q(10,fi(n,p a==b                     )))
#define arF(f,n,p)Y(f,,\
 Q( 0,fi(n,p ((V)a,b)                 ))\
 Q( 1,fi(n,p a+b                      ))\
 Q( 2,fi(n,p a-b                      ))\
 Q( 3,fi(n,p a*b                      ))\
 Q( 4,fi(n,p b?a/b:!a?_0n:a>0?_0w:-_0w))\
 Q( 5,fi(n,p ((V)a,(V)b,_0n) /*todo*/ ))\
 Q( 6,fi(n,p min(a,b)                 ))\
 Q( 7,fi(n,p max(a,b)                 ))\
 Q( 8,fi(n,p *(F*)cb(a<b)             ))\
 Q( 9,fi(n,p *(F*)cb(a>b)             ))\
 Q(10,fi(n,p *(F*)cb(a==b)            )))

//debugging
#define pv(x) pv_(#x,(I)(x));
#define pa(x) pa_(#x" ",(x));
#define nop {asm volatile("nop");}
#define P ps("["__FILE__":"xstr(__LINE__)"]");
SI C hex(I x){R x+(x>9?'a'-10:'0');}
SI V ps(C*x){write(2,x,strlen(x));}
SI V ph(I x){C s[17];s[16]=0;fi(16,s[15-i]=hex(x&15);x>>=4)write(2,s,17);}
SI V pd(I x){C b[32],*u=b+31;I m=x<0;$(m,x=-x)DW(*u--='0'+x%10;x/=10,x);$(m,*u--='-')write(2,u+1,b+31-u);}
SI I pv_(C*s,I x){ps(s);write(2,"           ",max(1,10-strlen(s)));ph((I)x);write(2,"\n",1);R x;}
SI V pa_(C*s,A x){ps(s);ph((I)x);ps(" b");pd(xb);ps("t");pd(xt);ps("r");pd(xr);ps("n");pd(xn);ps(" ");out(x);}
