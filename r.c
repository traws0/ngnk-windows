#include<math.h> // ngn/k, (c) 2019-2024 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
#include"a.h"
///prng: xoshiro256++ (public domain) http://vigna.di.unimi.it/xorshift/ seeded with the central column of rule30, little-endian:
//s:2/|+4 64#(n{(|(8#2)\30)@2/'3':0,x,0}\n=!2*n)@'n:256
//R:{,/|(0,(#y)!x)_y} /rotate
//X:{*`I$~=/`B$'(x;y)} /xor
//d:`B$|'(0x180ec6d33cfd0aba;0xd5a61266f0c9392c;0xa9582618e03fc9aa;0x39abdc4529b1661c) /big endian
//f:{r:+/x 0 3;t:x[1]*(*/17#2);x[2]:X/x 2 0;x[3]:X/x 3 1;x[1]:X/x 1 2;x[0]:X/x 0 3;x[2]:X[x 2]t;x[3]:2/R[45]@(64#2)\x 3;x} /next
//l:{r:{t:$[y;X'/x;*x];(t;f x 1)}/[(&4;x);,//d];*r} /long jump
//`0:",\n"/{x/"{}"}'","/'"0x",/:/:`hex@|''`C$''`B$''+3 l\s
#define M 4
Z W s[][M]={{0xd5a986ae75c9a33b,0x77788d12d7c3f90a,0x9bb25b5d47975e04,0xa3aa79088ad4f6e6},{0x1016d8e3483a8f0f,0x8480d0401b60cca6,0x7a98b60bcc8d9aac,0xfe26edc783fd076a},
            {0x81f9e6260eb8e5df,0x84b0c73f92967168,0xdea3ef04291616cd,0xc59aa1a597d9ccc7},{0xfa9b718d8d0769bf,0x699d3c097d2a746d,0xad6944fed639d10b,0x993752ab8d4d5eba}};//prng state
Z W b[M];Z U nb;//buf
Z V h(U x,U y){Wx4* r=(Wx4*)s;r[x]^=r[y];}
Z V r4(){nb=M;Wx4 t;Wx4* r=(Wx4*)s;Wx4 c=r[0]+r[3];c=(c<<23)|(c>>41);c+=r[0];*(Wx4*)b=c;t=r[1]<<17;h(2,0);h(3,1);h(1,2);h(0,3);r[2]^=t;r[3]=(r[3]<<45)|(r[3]>>19);}//next 4*64 bits
Z W r()_(I(nb<4,r4())b[--nb])//random 64 bits
 Z V jps(){CO W jp[]={0x180ec6d33cfd0aba,0xd5a61266f0c9392c,0xa9582618e03fc9aa,0x39abdc4529b1661c};W a[4];F(4,a[i]=s[i][0])
  F_(r_,3,Lx4 n[M]={0};Lx4* r=(Lx4*)s; F(4,r[i]=SHUF(r[i],(Lx4){0,0,1,2}))
  Fj(L(jp),F_(k,64,I(jp[j]&(1ull<<k),F_(l,4,n[l]^=r[l]))r4()))MC(s,n,SZ(n));F(4,s[i][0]=a[i]));nb=0;}
X1(prng,Ru(x=an(M,tL);F(M,xl=s[i][0])x)REGHIL(P(xn-M,el(x))F(M,s[i][0]=xl)jps();nb=0;x(au))Ril(W v=gl(x);I(!v,A u=sym("/dev/random");P(u=fr(u,0,32),F(M,s[i][0]=ul)jps();nb=0;u(au))v=now())F(M,s[i][0]=v=v*6364136223846793005+1442695040888963407/*knuth mmix*/)jps();au)R_(et(x)))
Z U ri(W m)_((U)r()*m>>32)//random int mod m
Z W rw(W m)_(m>>32?r()%m:ri(m))
Z F rf()_(W v=1023ll<<52|(r()&-1ull>>12);-1+*(F*)&v)//random float 0..1

Z A rt(U n,C t)_(A x=an(n,t);F(((W)n<<Tw[t])+255>>8,r4();MC(xV+(i<<5),b,32))x)//roll n full-range (including negative) items of type t (int of a specific width or char)
Z CO W msk[]={0xffffffffffffffffll,0x5555555555555555ll,0x1111111111111111ll,0x0101010101010101ll,0x0001000100010001ll,0x0000000100000001ll,0x0000000000000001ll};
Z A ro(U n,W m)_(P(!(m&m-1),P(!m,rt(n,tL))C t=tZ(m-1);A x=rt(n,t);L v=(m-1)*msk[Tw[t]];L*p=xL;F((n-1+(1<<8-Tw[t]))>>8-Tw[t],Fj(4,*p++&=v))x)
                 C t=tZ(m-1);A x=an(n,t);S4(t-tG,F(n,xg=ri(m)),F(n,xh=ri(m)),F(n,xi=ri(m)),F(n,xl=r())I(m,F(n,xl%=m)))x)//roll
Z A ded(U n,U m)_(A x=an(m,tZ(m));tilV(xV,0,m,xw-3);S4(xw-3,F(n,U j=ri(m-i)+i;SW(xG[i],xG[j])),F(n,U j=ri(m-i)+i;SW(xH[i],xH[j])),F(n,U j=ri(m-i)+i;SW(xI[i],xI[j])),)rsz(n,x))//dense deal
Z A dsp(U n,W m)_(A x=aL(n);L*a=xL;F(n,a[i]=i)W t=1ll<<(66-CLZ(n));A y=aL(t);L*h=yL;L*v=h+1;MS(h,0,t<<3);//sparse
 W b=t-2;F(n,W j=rw(m-i)+i;
  I(j<(W)n,SW(a[i],a[j]))
  E(W p=2*j;W s=j;W(1,W hp=h[p&=b];B(!hp,h[p]=j)B(hp==j,s=v[p])p+=2)v[p]=a[i];a[i]=s))y(ct(ai(tZ(m)),x)))//linear probe
Z A de(U n,W m)_(n>m?el0():!(m>>31)&&n+64>m>>4?ded(n,m):dsp(n,m))//deal
Z A rd(L n,L m)_(m<0?(n<0?ed0():rt(n,tZ(m))):n==NL?rd(-m,m):n-(I)n?ez0():n<0?de(-n,m):ro(n,m))//roll or deal
A rndF(L n)_(P(n<0,ed0())A x=aF(n);F(n,xf=rf())x)//random floats 0..1
A rnd(L n,A x)_(X(Ril(rd(n,gl(x)))Rc(P((32|xv)=='a',cC(add(x,Nx(rd(n,26)))))rt(n,tC))Rf(x(mul(x,Nx(rndF(n)))))RMT(x(x1(Nx(rd(n,xN)))))R_(et(x)))0)
