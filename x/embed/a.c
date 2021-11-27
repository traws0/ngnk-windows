#include<stdio.h>
#include"../../k.h" //new api
void kinit();void kf(const char*s,long long(*)(long long));long long k(const char*); //old api

K inc(K x){
 printf("inc()\n");
 return K2('+',Ki(1),x);}

int main(){
 setbuf(stdout,0);
 kinit();

 //1 2+3
 K x=KI((I[]){1,2},2),y=Ki(3),z=K2('+',x,y);int r[2];IK(r,z);size_t n=NK(z);
 for(int i=0;i<n;i++)printf("r[%d]:%d\n",i,r[i]);

 //inc 123
 x=KR(inc,1,"inc");
 KA("inc",x);
// k(" \\. 0#`");

 k("`0:$inc 123");

 return 0;
}
