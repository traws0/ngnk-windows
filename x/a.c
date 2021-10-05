#include<stdio.h>
#include<dlfcn.h>

//function that will be visible from k
long sqr(long x){
 printf("sqr %ld\n",x);
 return x*x;
}

int main(int n,const char**a){
 setbuf(stdout,0);
 void*l=dlopen("../libk.so",RTLD_NOW);if(!l){printf("%s\n",dlerror());return 1;}
 void(*kinit)(int,const char**)      =dlsym(l,"kinit");
 void(*kf)(const char*,long(*)(long))=dlsym(l,"kf"   );
 long(*k)(const char*)               =dlsym(l,"k"    );
 kinit(n,a);
 kf("sqr",sqr); //export to k
 k("a:2;b:3");
 printf("%ld\n",k("sqr a+b")); //prints 25
 return 0;
}
