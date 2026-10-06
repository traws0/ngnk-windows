#include<stdio.h>
#include"../../k.h"

K Fadd(K x,K y){
 printf("add()\n");
 int a=iK(x);
 int b=iK(y);
 int c=a+b;
 return Ki(c);
}

void init(){
 printf("kinit()\n"); kinit();
 printf("KR()\n");    KR("add",Fadd,2);
}

int main(){
 init();
 setbuf(stdout,0);
 printf("Kx()\n");   Kx("`0:$add[2;3]");
 printf("return\n"); return 0;
}
