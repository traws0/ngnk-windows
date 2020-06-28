#include"k.h" // ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE
#define U3(f,a) S UI f(UI x,UI y,UI z)_(a)
TD UI(*U3)(UI,UI,UI);U3(ch,x&y|~x&z)U3(zch,z&x|~z&y)U3(xor,x^y^z)U3(md5f3,y^(x|~z))U3(maj,x&y^x&z^y&z)
S UI rol(UI x,UI y)_(x<<y|x>>32-y)S UL roL(UL x,UL y)_(x<<y|x>>64-y)
S UI be4(UI x)_(x<<24|x<<8&0xff0000|x>>8&0xff00|x>>24)S UL be8(UL x)_(be4(x>>32)|(UL)be4(x)<<32)S UI*be4n(UI*r,O UI*a,UI n)_(F(n,r[i]=be4(a[i]))r)
S A mdc(A x,O V*iv,I nv,V(*f)(UI*,UL,UI*),I be)_(P(!xtC,et(x))A u=aCn(iv,4*nv);UL n=xn,k=n/64,r=n%64; //mdc:padding and merkle-damgard construction
 mr2(x,f(xi,k,ui);C c[128];UL m=n+72&~63;mc(c,xc+n-r,r);c[r]=128;ms(c+r+1,0,m-n-9);*(UL*)(V*)(c+m-n+r-8)=be?be8(8*n):8*n;f((V*)c,m/64-k,ui);0);
 Y(be,be4n(ui,ui,nv))u)

#define h1(q,f,x,y,z,u,s,m) x=y+rol(x+f(y,z,u)+k[i]+d[m],s);i++;
#define h(q,f,s0,s1,s2,s3,m) W(i<16*(q+1),h1(q,f,x,y,z,u,s0,m)h1(q,f,u,x,y,z,s1,m)h1(q,f,z,u,x,y,s2,m)h1(q,f,y,z,u,x,s3,m))
S O UI iv[]={0x67452301,0xefcdab89,0x98badcfe,0x10325476,0xc3d2e1f0}; //md5&sha1
S V md5u(UI*d,UL n,UI*a){S O UI k[]={0xd76aa478,0xe8c7b756,0x242070db,0xc1bdceee,0xf57c0faf,0x4787c62a,0xa8304613,0xfd469501,0x698098d8,0x8b44f7af,
 0xffff5bb1,0x895cd7be,0x6b901122,0xfd987193,0xa679438e,0x49b40821,0xf61e2562,0xc040b340,0x265e5a51,0xe9b6c7aa,0xd62f105d,0x02441453,0xd8a1e681,0xe7d3fbc8,
 0x21e1cde6,0xc33707d6,0xf4d50d87,0x455a14ed,0xa9e3e905,0xfcefa3f8,0x676f02d9,0x8d2a4c8a,0xfffa3942,0x8771f681,0x6d9d6122,0xfde5380c,0xa4beea44,0x4bdecfa9,
 0xf6bb4b60,0xbebfbc70,0x289b7ec6,0xeaa127fa,0xd4ef3085,0x04881d05,0xd9d4d039,0xe6db99e5,0x1fa27cf8,0xc4ac5665,0xf4292244,0x432aff97,0xab9423a7,0xfc93a039,
 0x655b59c3,0x8f0ccc92,0xffeff47d,0x85845dd1,0x6fa87e4f,0xfe2ce6e0,0xa3014314,0x4e0811a1,0xf7537e82,0xbd3af235,0x2ad7d2bb,0xeb86d391};
 F(n,UI i=0,x=*a,y=a[1],z=a[2],u=a[3];h(0,ch,7,12,17,22,i)h(1,zch,5,9,14,20,5*i+1&15)h(2,xor,4,11,16,23,3*i+5&15)h(3,md5f3,6,10,15,21,7*i&15)
     *a+=x;a[1]+=y;a[2]+=z;a[3]+=u;d+=16)}
A1(md5,mdc(x,iv,4,md5u,0))
#undef h
#undef h1

S V sha1u(UI*d,UL n,UI*a){
 F(n,UI x=*a,y=a[1],z=a[2],u=a[3],v=a[4],w[80];be4n(w,d,16);F(64,w[i+16]=rol(w[i+13]^w[i+8]^w[i+2]^w[i],1))
  F(80,UI t=rol(x,5)+(U3[]){ch,xor,maj,xor}[i/20](y,z,u)+v+(UI[]){0x5a827999,0x6ed9eba1,0x8f1bbcdc,0xca62c1d6}[i/20]+w[i];v=u;u=z;z=rol(y,30);y=x;x=t)
  *a+=x;a[1]+=y;a[2]+=z;a[3]+=u;a[4]+=v;d+=16)}
A1(sha1,mdc(x,iv,5,sha1u,1))

#define h(x0,x1,x2,x3,x4,x5,x6,x7) {UI t=x7+(rol(x4,26)^rol(x4,21)^rol(x4,7))+ch(x4,x5,x6)+k[r]+w[r],u=(rol(x0,30)^rol(x0,19)^rol(x0,10))+maj(x0,x1,x2);x3+=t;x7=t+u;r++;}
S V sha256u(UI*d,UL n,UI*a){S O UI k[]={0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,0xd807aa98,0x12835b01,
 0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
 0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,
 0x81c2c92e,0x92722c85,0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,
 0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2};
 F(n,UI w[64];be4n(w,d,16);F(48,UI p=w[i+1],q=w[i+14];w[i+16]=w[i]+(rol(p,25)^rol(p,14)^p>>3)+w[i+9]+(rol(q,15)^rol(q,13)^q>>10))
  UI x0=*a,x1=a[1],x2=a[2],x3=a[3],x4=a[4],x5=a[5],x6=a[6],x7=a[7],r=0;
  F(8,h(x0,x1,x2,x3,x4,x5,x6,x7)h(x7,x0,x1,x2,x3,x4,x5,x6)h(x6,x7,x0,x1,x2,x3,x4,x5)h(x5,x6,x7,x0,x1,x2,x3,x4)
      h(x4,x5,x6,x7,x0,x1,x2,x3)h(x3,x4,x5,x6,x7,x0,x1,x2)h(x2,x3,x4,x5,x6,x7,x0,x1)h(x1,x2,x3,x4,x5,x6,x7,x0))
  *a+=x0;a[1]+=x1;a[2]+=x2;a[3]+=x3;a[4]+=x4;a[5]+=x5;a[6]+=x6;a[7]+=x7;d+=16)}
A1(sha256,mdc(x,(UI[]){0x6a09e667,0xbb67ae85,0x3c6ef372,0xa54ff53a,0x510e527f,0x9b05688c,0x1f83d9ab,0x5be0cd19},8,sha256u,1))
#undef h

#define Fj5(a...) {{I j=0;a;}{I j=1;a;}{I j=2;a;}{I j=3;a;}{I j=4;a;}}
S V kecp(UL*a){C l=1;F(24,
 {UL b[7]={};F(5,Fj5(b[1+j]^=*a++))*b=b[5];b[6]=b[1];Fj5(b[j]^=roL(b[j+2],1))a-=25;F(5,Fj5(*a++^=b[j]))a-=25;} //θ
 UL b[25];F(25,b[i]=roL(a[i],(C[]){0,1,62,28,27,36,44,6,55,20,3,10,43,25,39,41,45,15,21,8,18,2,61,56,14}[i]))  //ρ
 F(25,a[i]=b[(C[]){0,6,12,18,24,3,9,10,16,22,1,7,13,19,20,4,5,11,17,23,2,8,14,15,21}[i]])                      //π
 F(5,UL*b=a+5*i,x=*b,y=b[1];Fj5(UL z=b[4-j];b[4-j]^=~x&y;y=x;x=z))                                             //χ
 F(7,I r=l&1;Y(l&128,l<<=1;l^=113)E(l<<=1)Y(r,*a^=1ll<<(1<<i)-1)))}                                            //ι
#undef Fj5
S V kec(UI r,O C*p,UL n,C s,C*z,UI d){UI b=0,i;C a[200];ms(a,0,Z a);W(n>0,b=min(n,r);F(b,a[i]^=p[i])p+=b;n-=b;Y(b==r,kecp((V*)a);b=0))
 a[b]^=s;if((s&128)&&b==r-1)kecp((V*)a);a[r-1]^=128;kecp((V*)a);W(d>0,b=min(d,r);mc(z,a,b);z+=b;d-=b;Y(d>0,kecp((V*)a)))}
A1(sha3_256,P(!xtC,et(x))A u=aC(32);mr2(x,kec(1088/8,xc,xn,6,uc,un);u))
