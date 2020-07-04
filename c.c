#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#define U3(f,a) S U f(U x,U y,U z)_(a)
TD UI U,(*U3)(U,U,U);U3(ch,x&y|~x&z)U3(zch,z&x|~z&y)U3(xor,x^y^z)U3(md5f3,y^(x|~z))U3(maj,x&y^x&z^y&z)
S U rl(U x,U y)_(x<<y|x>>32-y)S UL rL(UL x,UL y)_(x<<y|x>>64-y)
S U b4(U x)_(x<<24|x<<8&0xff0000|x>>8&0xff00|x>>24)S UL b8(UL x)_(b4(x>>32)|(UL)b4(x)<<32)S U*b4n(U*r,O U*a,U n)_(F(n,r[i]=b4(a[i]))r)
S A mdc(A x,O V*iv,I nv,V(*f)(U*,UL,U*),I be)_(P(!xtC,et(x))A u=aCn(iv,4*nv);UL n=xn,k=n/64,r=n%64; //mdc:padding and merkle-damgard construction
 mr2(x,f(xi,k,ui);C c[128];UL m=n+72&~63;mc(c,xc+n-r,r);c[r]=128;ms(c+r+1,0,m-n-9);*(UL*)(V*)(c+m-n+r-8)=be?b8(8*n):8*n;f((V*)c,m/64-k,ui);0);
 Y(be,b4n(ui,ui,nv))u)

#define h1(q,f,x,y,z,u,s,m) x=y+rl(x+f(y,z,u)+k[i]+d[m],s);i++;
#define h(q,f,s0,s1,s2,s3,m) W(i<16*(q+1),h1(q,f,x,y,z,u,s0,m)h1(q,f,u,x,y,z,s1,m)h1(q,f,z,u,x,y,s2,m)h1(q,f,y,z,u,x,s3,m))
S O U iv[]={0x67452301,0xefcdab89,0x98badcfe,0x10325476,0xc3d2e1f0}; //md5&sha1
V md5i(U*k){D a=.8414709848078965,b=.54030230586813977,s=a,c=b,t;F(64,k[i]=(1ll<<32)*(s<0?-s:s);t=b*s+a*c;c=b*c-a*s;s=t)}
S V md5u(U*d,UL n,U*a){S U k[64];Y(!*k,md5i(k))
 F(n,U i=0,x=*a,y=a[1],z=a[2],u=a[3];h(0,ch,7,12,17,22,i)h(1,zch,5,9,14,20,5*i+1&15)h(2,xor,4,11,16,23,3*i+5&15)h(3,md5f3,6,10,15,21,7*i&15)
     *a+=x;a[1]+=y;a[2]+=z;a[3]+=u;d+=16)}
A1(md5,mdc(x,iv,4,md5u,0))
#undef h
#undef h1

S V sha1u(U*d,UL n,U*a){
 F(n,U x=*a,y=a[1],z=a[2],u=a[3],v=a[4],w[80];b4n(w,d,16);F(64,w[i+16]=rl(w[i+13]^w[i+8]^w[i+2]^w[i],1))
  F(80,U t=rl(x,5)+(U3[]){ch,xor,maj,xor}[i/20](y,z,u)+v+(U[]){0x5a827999,0x6ed9eba1,0x8f1bbcdc,0xca62c1d6}[i/20]+w[i];v=u;u=z;z=rl(y,30);y=x;x=t)
  *a+=x;a[1]+=y;a[2]+=z;a[3]+=u;a[4]+=v;d+=16)}
A1(sha1,mdc(x,iv,5,sha1u,1))

#define h(a,b,c,d,e,f,g,h) {d+=h+=(rl(e,26)^rl(e,21)^rl(e,7))+ch(e,f,g)+k[r]+w[r];h+=(rl(a,30)^rl(a,19)^rl(a,10))+maj(a,b,c);r++;}
S V sha256u(U*v,UL n,U*s){S O U k[]={0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,
 0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
 0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,
 0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,
 0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};
 F(n,U w[64];b4n(w,v,16);F(48,U p=w[i+1],q=w[i+14];w[i+16]=w[i]+(rl(p,25)^rl(p,14)^p>>3)+w[i+9]+(rl(q,15)^rl(q,13)^q>>10))
  U a=*s,b=s[1],c=s[2],d=s[3],e=s[4],f=s[5],g=s[6],h=s[7],r=0;
  F(8,h(a,b,c,d,e,f,g,h)h(h,a,b,c,d,e,f,g)h(g,h,a,b,c,d,e,f)h(f,g,h,a,b,c,d,e)h(e,f,g,h,a,b,c,d)h(d,e,f,g,h,a,b,c)h(c,d,e,f,g,h,a,b)h(b,c,d,e,f,g,h,a))
  *s+=a;s[1]+=b;s[2]+=c;s[3]+=d;s[4]+=e;s[5]+=f;s[6]+=g;s[7]+=h;v+=16)}
A1(sha256,mdc(x,(U[]){0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19},8,sha256u,1))
#undef h

#define Fj5(a...) {{I j=0;a;}{I j=1;a;}{I j=2;a;}{I j=3;a;}{I j=4;a;}}
S V kecp(UL*a){S O UL z=1<<15,y=1ll<<31,x=1ll<<63,t[]={1,z+130,x+z+138,x+y+z,z+139,y+1,x+y+z+129,x+z+9,138,136,y+z+9,y+10,y+z+139,
                                                       x+139,x+z+137,x+z+3,x+z+2,x+128,z+10,x+y+10,x+y+z+129,x+z+128,y+1,x+y+z+8};
 F(24,UL s[7]={},b[25];
  F(5,Fj5(s[1+j]^=*a++))*s=s[5];s[6]=s[1];Fj5(s[j]^=rL(s[j+2],1))a-=25;F(5,Fj5(*a++^=s[j]))a-=25;    //θ
  F(25,b[i]=rL(a[i],(C[]){0,1,62,28,27,36,44,6,55,20,3,10,43,25,39,41,45,15,21,8,18,2,61,56,14}[i])) //ρ
  F(25,a[i]=b[(C[]){0,6,12,18,24,3,9,10,16,22,1,7,13,19,20,4,5,11,17,23,2,8,14,15,21}[i]])           //π
  F(5,UL*r=a+5*i,x=*r,y=r[1];Fj5(UL z=r[4-j];r[4-j]^=~x&y;y=x;x=z))                                  //χ
  *a^=t[i])}                                                                                         //ι
#undef Fj5
S V kec(U r,O C*p,UL n,C s,C*z,U d){U b=0,i;C a[200];ms(a,0,Z a);W(n>0,b=min(n,r);F(b,a[i]^=p[i])p+=b;n-=b;Y(b==r,kecp((V*)a);b=0))
 a[b]^=s;if((s&128)&&b==r-1)kecp((V*)a);a[r-1]^=128;kecp((V*)a);W(d>0,b=min(d,r);mc(z,a,b);z+=b;d-=b;Y(d>0,kecp((V*)a)))}
A1(sha3_256,P(!xtC,et(x))A u=aC(32);mr2(x,kec(1088/8,xc,xn,6,uc,un);u))
