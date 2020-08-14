#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#define U3(f,a) S U f(U x,U y,U z)_(a)
#define C(a...) (C[]){a}
TD UI U,(*U3)(U,U,U);U3(chx,x&y|~x&z)U3(chz,z&x|~z&y)U3(xor,x^y^z)U3(mf3,y^(x|~z))U3(maj,x&y^x&z^y&z)
S C rC(C x,U y)_(x<<y|x>>8-y)S U rI(U x,U y)_(x<<y|x>>32-y)S UL rL(UL x,U y)_(x<<y|x>>64-y) //rotations
S U bl(U x)_(x<<24|x<<8&0xff0000|x>>8&0xff00|x>>24)S UL bL(UL x)_(bl(x>>32)|(UL)bl(x)<<32)S U*bn(U*r,O U*a,U n)_(F(n,r[i]=bl(a[i]))r) //big-endian

S U md5k[64];S V md5i(){D a=.8414709848078965,b=.54030230586813977,s=a,c=b,t;F(64,md5k[i]=(1ll<<32)*(s<0?-s:s);t=b*s+a*c;c=b*c-a*s;s=t)}
S V md5h(U i,U3 f,U s,U m,U*b,O U*d){b[4-i&3]=b[5-i&3]+rI(b[4-i&3]+f(b[5-i&3],b[6-i&3],b[7-i&3])+md5k[i]+d[m],s);}
#define h(q,f,s0,s1,s2,s3,m) W(i<16*(q+1),md5h(i,f,s0,m,b,d);i++;md5h(i,f,s1,m,b,d);i++;md5h(i,f,s2,m,b,d);i++;md5h(i,f,s3,m,b,d);i++)
S V md5u(U*d,UL n,U*a){
 F(n,U i=0,b[4];mc(b,a,16);h(0,chx,7,12,17,22,i)h(1,chz,5,9,14,20,5*i+1&15)h(2,xor,4,11,16,23,3*i+5&15)h(3,mf3,6,10,15,21,7*i&15)F(4,a[i]+=b[i])d+=16)}
#undef h
S V sha1u(U*d,UL n,U*a){
 F(n,U x=*a,y=a[1],z=a[2],u=a[3],v=a[4],w[80];bn(w,d,16);F(64,w[i+16]=rI(w[i+13]^w[i+8]^w[i+2]^w[i],1))
  F(80,U t=rI(x,5)+(U3[]){chx,xor,maj,xor}[i/20](y,z,u)+v+(U[]){0x5a827999,0x6ed9eba1,0x8f1bbcdc,0xca62c1d6}[i/20]+w[i];v=u;u=z;z=rI(y,30);y=x;x=t)
  *a+=x;a[1]+=y;a[2]+=z;a[3]+=u;a[4]+=v;d+=16)}
S A mdc(A x,O V*iv,I nv,V(*f)(U*,UL,U*),I b)_(Et(!xtC)A u=aCn(iv,4*nv);UL n=xn,k=n/64,r=n%64,m=n+72&~63; //merkle-damgard construction with padding
 C c[128];m2(x,f(xi,k,ui);mc(c,xc+n-r,r));c[r]=128;ms(c+r+1,0,m-n-9);*(UL*)(V*)(c+m-n+r-8)=b?bL(8*n):8*n;f((V*)c,m/64-k,ui);Y(b,bn(ui,ui,nv))u)
S O U iv[]={0x67452301,0xefcdab89,0x98badcfe,0x10325476,0xc3d2e1f0};A1(md5,Y(!*md5k,md5i())mdc(x,iv,4,md5u,0))A1(sha1,mdc(x,iv,5,sha1u,1))

#define h(a,b,c,d,e,f,g,h) {d+=h+=(rI(e,26)^rI(e,21)^rI(e,7))+chx(e,f,g)+k[r]+w[r];h+=(rI(a,30)^rI(a,19)^rI(a,10))+maj(a,b,c);r++;}
S V sha256u(U*v,UL n,U*s){S O U k[]={0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,
 0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
 0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,
 0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,
 0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};
 F(n,U w[64];bn(w,v,16);F(48,U p=w[i+1],q=w[i+14];w[i+16]=w[i]+(rI(p,25)^rI(p,14)^p>>3)+w[i+9]+(rI(q,15)^rI(q,13)^q>>10))
  U a=*s,b=s[1],c=s[2],d=s[3],e=s[4],f=s[5],g=s[6],h=s[7],r=0;
  F(8,h(a,b,c,d,e,f,g,h)h(h,a,b,c,d,e,f,g)h(g,h,a,b,c,d,e,f)h(f,g,h,a,b,c,d,e)h(e,f,g,h,a,b,c,d)h(d,e,f,g,h,a,b,c)h(c,d,e,f,g,h,a,b)h(b,c,d,e,f,g,h,a))
  *s+=a;s[1]+=b;s[2]+=c;s[3]+=d;s[4]+=e;s[5]+=f;s[6]+=g;s[7]+=h;v+=16)}
A1(sha256,mdc(x,(U[]){0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19},8,sha256u,1))
#undef h

#define F5(a...) {{I i=0;a;}{I i=1;a;}{I i=2;a;}{I i=3;a;}{I i=4;a;}}
S V ks(UL*a){S O UL z=1<<15,y=1ll<<31,x=1ll<<63,t[]={1,z+130,x+z+138,x+y+z,z+139,y+1,x+y+z+129,x+z+9,138,136,y+z+9,y+10,y+z+139, //keccak sponge
                                                       x+139,x+z+137,x+z+3,x+z+2,x+128,z+10,x+y+10,x+y+z+129,x+z+128,y+1,x+y+z+8};
 F(24,UL s[7]={},b[25];F(5,F5(s[1+i]^=*a++))*s=s[5];s[6]=s[1];F5(s[i]^=rL(s[i+2],1))a-=25;F(5,F5(*a++^=s[i]))a-=25;   //θ
                       F(25,b[i]=rL(a[i],C(0,1,62,28,27,36,44,6,55,20,3,10,43,25,39,41,45,15,21,8,18,2,61,56,14)[i])) //ρ
                       F(25,a[i]=b[C(0,6,12,18,24,3,9,10,16,22,1,7,13,19,20,4,5,11,17,23,2,8,14,15,21)[i]])           //π
                       F(5,UL*r=a+5*i,x=*r,y=r[1];F5(UL z=r[4-i];r[4-i]^=~x&y;y=x;x=z))                               //χ
                       *a^=t[i])}                                                                                     //ι
#undef F5
S V kec(U r,O C*p,UL n,C s,C*z,U d){U b=0,i;C a[200];ms(a,0,Z a);W(n>0,b=min(n,r);F(b,a[i]^=p[i])p+=b;n-=b;Y(b==r,ks((V*)a);b=0))
 a[b]^=s;if((s&128)&&b==r-1)ks((V*)a);a[r-1]^=128;ks((V*)a);W(d>0,b=min(d,r);mc(z,a,b);z+=b;d-=b;Y(d>0,ks((V*)a)))}
A1(sha3_256,Et(!xtC,x)A u=aC(32);m2(x,kec(136,xc,xn,6,uc,un);u))

S C s0[256],s1[256];S C t0(C x)_(x<<1^27*(x>>7))S C t1(C x,C y)_(C r=(y&1)*x;F(4,x=t0(x);r^=(y>>i+1&1)*x)r)
S V aei(){C x=1,y=1;ms(s0,99,256);F(255,x^=t0(x);F(3,y^=y<<(1<<i))y^=(y>>7)*9;F(5,s0[x]^=rC(y,i)))F(256,s1[s0[i]]=i)}
S V x16(C*r,O C*x){F(16,r[i]^=x[i])}S V i16(C*r,O C*x,O C*y){F(16,r[i]=x[y[i]])}
S V kxp(V*w0,O V*k,U l){U*w=w0,t;mc(w,k,4*l);C*p=(V*)&t;
 F(3*l+28,t=w[i+l-1];
  Y(i%l==0,t=rI(t,24);Fj(4,p[j]=s0[p[j]])t^=C(141,1,2,4,8,16,32,64,128,27,54)[i/l+1])
  EY(l==8&&i%l==4,F(4,p[i]=s0[p[i]]))
  w[i+l]=w[i]^t)}
S V mx0(C*a){F(4,C t[4];F(4,t[i]=a[i]^a[i+1&3])C e=*t^t[2];F(4,a[i]^=t0(t[i])^e)a+=4)}
S V mx1(C*a){F(4,C t[4]={};F(4,Fj(4,t[i]^=t1(a[j],C(14,11,13,9)[j-i&3])))mc(a,t,4);a+=4)}
S V ae0(V*a,O V*w,U m){C b[16];F(m,x16(a,w+16*i);i16(b,s0,a);i16(a,b,C(0,5,10,15,4,9,14,3,8,13,2,7,12,1,6,11));i<m-1?mx0(a):x16(a,w+16*m))}
S V ae1(V*a,O V*w,U m){C b[16];x16(a,w+16*m);F(m,i16(b,a,C(0,13,10,7,4,1,14,11,8,5,2,15,12,9,6,3));mc(a,b,16);i16(a,s1,a);x16(a,w+16*(m-1-i));Y(i<m-1,mx1(a)))}
S V ecb(V*a,O V*k,U l,U d){C w[l+7<<4];kxp(w,k,l);(d?ae1:ae0)(a,w,l+6);}
S A aes(A x,U d)_(Y(!*s0,aei())Ed(!xtX||xn-2,x)A y=gkv(&x);Ed(!xtC||!ytC||xn-16||(yn-16&&yn-24&&yn-32))x=mut(x);ecb(xc,yc,yn/4,d);yr;x)
A1(aes0,aes(x,0))A1(aes1,aes(x,1))

#undef C
