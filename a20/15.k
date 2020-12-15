#!../k
a:`i$.*0:"i/15"
f:{h::x#x;h[a]:1i+!n:`i$#a;0+(*|a){y-(h[x]:y)&h x}/n_!x}
f 2020i

c:"#include<stdio.h>\n#define N 30000000\ntypedef int I;I h[N],a[]={",(","/$a),"},n=",$#a
c,:";int main(){for(I i=0;i<n;i++)h[a[i]]=i+1;I i=n,l=a[n-1];while(i<N){I p=h[l];h[l]=i;l=p?i-p:0;i++;}printf(\"%d\",l);}"
.*."\\echo '",c,"'|tcc -run -"
