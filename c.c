#include"a.h" // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
#define F5(a...) {{Ii=0;a;}{Ii=1;a;}{Ii=2;a;}{Ii=3;a;}{Ii=4;a;}}
#define F8(a...) {F5(a){Ii=5;a;}{Ii=6;a;}{Ii=7;a;}}
#define U3(f,a) S U f(U x,U y,U z)_(a)
#define C(a...) (C[]){a}
#define R rot
TD UI U,(*U3)(U,U,U);U3(chx,x&y|~x&z)U3(chz,z&x|~z&y)U3(xor,x^y^z)U3(mf3,y^(x|~z))U3(maj,x&y^x&z^y&z)
S U bl(U x)_(x<<24|x<<8&0xff0000|x>>8&0xff00|x>>24)S UL bL(UL x)_(bl(x>>32)|(UL)bl(x)<<32) //big-endian
S U*bn(U*r,O U*a,Nn)_(i(n,r[i]=bl(a[i]))r)

S U m5k[64];S O U iv[]={0x67452301,0xefcdab89,0x98badcfe,0x10325476,0xc3d2e1f0};
S V m5i(){D a=.8414709848078965,b=.54030230586813977,s=a,c=b,t;i(64,m5k[i]=(1ll<<32)*(s<0?-s:s);t=b*s+a*c;c=b*c-a*s;s=t)}
S V m5h(Ni,U3 f,U s,Nm,U*b,O U*d){b[4-i&3]=b[5-i&3]+R(b[4-i&3]+f(b[5-i&3],b[6-i&3],b[7-i&3])+m5k[i]+d[m],s);}
#define h(q,f,s0,s1,s2,s3,m)\
 W(i<16*(q+1),m5h(i,f,s0,m,b,d);i++;m5h(i,f,s1,m,b,d);i++;m5h(i,f,s2,m,b,d);i++;m5h(i,f,s3,m,b,d);i++)
S V m5u(O U*d,Nn,U*a){
 i(n,U i=0,b[4];Mc(b,a,16);
  h(0,chx,7,12,17,22,i)h(1,chz,5,9,14,20,5*i+1&15)h(2,xor,4,11,16,23,3*i+5&15)h(3,mf3,6,10,15,21,7*i&15)
  i(4,a[i]+=b[i])d+=16)}
#undef h
S V s1u(O U*d,Nn,U*a){
 i(n,U x=*a,y=a[1],z=a[2],u=a[3],v=a[4],w[80];bn(w,d,16);i(64,w[i+16]=R(w[i+13]^w[i+8]^w[i+2]^w[i],1))
  i(80,U t=R(x,5)+CH(i/20,&chx,xor,maj,xor)(y,z,u)+v+CH(i/20,0x5a827999u,0x6ed9eba1,0x8f1bbcdc,0xca62c1d6)+w[i];
       v=u;u=z;z=R(y,30);y=x;x=t)
  *a+=x;a[1]+=y;a[2]+=z;a[3]+=u;a[4]+=v;d+=16)}
S A md(Ax/*1*/,OV*iv,N nv,void(*f)(O U*,N,U*),I b)_(Et(!xtC,x) //merkle-damgard construction with padding
 I a[nv];Cc[128]={};Mc(a,iv,SZ a);Nn=xn,k=n/64,r=n%64,m=n+72&~63;x2(f(xV,k,a);Mc(c,xV+n-r,r));c[r]=128;
 *(UL*)(V*)(c+m-n+r-8)=b?bL(8*n):8*n;f((V*)c,m/64-k,a);I(b,bn(a,a,nv))aCn((V*)a,SZ a))
A1(md5,I(!*m5k,m5i())md(x,iv,4,m5u,0))A1(sha1,md(x,iv,5,s1u,1))

#define h(a,b,c,d,e,f,g,h) {d+=h+=(R(e,26)^R(e,21)^R(e,7))+chx(e,f,g)+s2k[r]+w[r];h+=(R(a,30)^R(a,19)^R(a,10))+maj(a,b,c);r++;}
#define g(j) h(t[-j&7],t[1-j&7],t[2-j&7],t[3-j&7],t[4-j&7],t[5-j&7],t[6-j&7],t[7-j&7])
S O U s2k[]={0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,0xd807aa98,
  0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,0x0fc19dc6,
  0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,
  0xd5a79147,0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,
  0x92722c85,0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,0x19a4c116,
  0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,
  0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};
S V s2u(O U*v,Nn,U*s){U w[64],t[8],r;
 i(n,r=0;bn(w,v,16);i(48,U p=w[i+1],q=w[i+14];w[i+16]=w[i]+(R(p,25)^R(p,14)^p>>3)+w[i+9]+(R(q,15)^R(q,13)^q>>10))
     F8(t[i]=s[i])i(8,g(0)g(1)g(2)g(3)g(4)g(5)g(6)g(7))F8(s[i]+=t[i])v+=16)}
A1(sha256,md(x,(U[]){0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19},8,s2u,1))
#undef g
#undef h
S V ks(UL*a){S O UL z=1<<15,y=1ll<<31,x=1ll<<63,t[]={1,z+130,x+z+138,x+y+z,z+139,y+1,x+y+z+129, //keccak sponge
  x+z+9,138,136,y+z+9,y+10,y+z+139,x+139,x+z+137,x+z+3,x+z+2,x+128,z+10,x+y+10,x+y+z+129,x+z+128,y+1,x+y+z+8};
 i(24,UL s[7],b[25];Ms(s,0,SZ s);
  i(5,F5(s[1+i]^=*a++))*s=s[5];s[6]=s[1];F5(s[i]^=R(s[i+2],1))a-=25;i(5,F5(*a++^=s[i]))a-=25;   //theta
  i(25,b[i]=R(a[i],C(0,1,62,28,27,36,44,6,55,20,3,10,43,25,39,41,45,15,21,8,18,2,61,56,14)[i])) //rho
  i(25,a[i]=b[C(0,6,12,18,24,3,9,10,16,22,1,7,13,19,20,4,5,11,17,23,2,8,14,15,21)[i]])          //pi
  i(5,UL*r=a+5*i,x=*r,y=r[1];F5(UL z=r[4-i];r[4-i]^=~x&y;y=x;x=z))                              //chi
  *a^=t[i])}                                                                                    //iota
S V kec(U r,OC*p,Nn,C s,C*z,U d){U b=0,i;C a[200];Ms(a,0,SZ a);
 W(n>0,b=min(n,r);i(b,a[i]^=p[i])p+=b;n-=b;I(b==r,ks((V*)a);b=0))
 a[b]^=s;if((s&128)&&b==r-1)ks((V*)a);a[r-1]^=128;ks((V*)a);W(d>0,b=min(d,r);Mc(z,a,b);z+=b;d-=b;I(d>0,ks((V*)a)))}
A1(sha3_256,Et(!xtC,x)Ay=aC(32);x2(kec(136,xV,xn,6,yV,yn);y))

S C s0[256],s1[256];S C t0(Cc)_(c<<1^27*(c>>7))S C t1(Cc,Cd)_(Cv=c*(d&1);i(4,c=t0(c);v^=(d>>i+1&1)*c)v)
S V aei(){Cc=1,d=1;Ms(s0,99,256);i(255,c^=t0(c);i(3,d^=d<<(1<<i))d^=(d>>7)*9;i(5,s0[c]^=R(d,i)))i(256,s1[s0[i]]=i)}
S V x16(C*r,OC*p){i(16,r[i]^=p[i])}S V i16(C*r,OC*p,OC*q){i(16,r[i]=p[q[i]])}
S V kxp(V*w0,OV*k,U l){U*w=w0,t;Mc(w,k,4*l);C*p=(V*)&t;
 i(3*l+28,t=w[i+l-1];I(i%l==0,t=R(t,24);j(4,p[j]=s0[p[j]])t^=C(141,1,2,4,8,16,32,64,128,27,54)[i/l+1])
                     EI(l==8&&i%l==4,i(4,p[i]=s0[p[i]]))w[i+l]=w[i]^t)}
S V mx0(C*a){i(4,Ct[4];i(4,t[i]=a[i]^a[i+1&3])Cc=*t^t[2];i(4,a[i]^=t0(t[i])^c)a+=4)}
S V mx1(C*a){i(4,Ct[4]={};i(4,j(4,t[i]^=t1(a[j],C(14,11,13,9)[j-i&3])))Mc(a,t,4);a+=4)}
S V ae0(V*a,OV*w,U r){Cb[16];
 i(r,x16(a,w+16*i);i16(b,s0,a);i16(a,b,C(0,5,10,15,4,9,14,3,8,13,2,7,12,1,6,11));i<r-1?mx0(a):x16(a,w+16*r))}
S V ae1(V*a,OV*w,U r){Cb[16];x16(a,w+16*r);
 i(r,i16(b,a,C(0,13,10,7,4,1,14,11,8,5,2,15,12,9,6,3));Mc(a,b,16);i16(a,s1,a);x16(a,w+16*(r-1-i));I(i<r-1,mx1(a)))}
S V ecb(V*a,OV*k,U l,U d){C w[l+7<<4];kxp(w,k,l);(d?ae1:ae0)(a,w,l+6);}
S A aes(Ax,U d)_(I(!*s0,aei())Ed(!xtA||xn-2,x)
 Ay=kv(&x);Ed(!xtC||!ytC||xn-16||(yn-16&&yn-24&&yn-32))x=mut(x);ecb(xV,yV,yn/4,d);y(x))
A1(aes0,aes(x,0))A1(aes1,aes(x,1))
