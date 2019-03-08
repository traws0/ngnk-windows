\l 0.k
/using the "pentagonal" recurrence relation from
/https://en.wikipedia.org/wiki/Partition_function_(number_theory)#Recurrence_relations
/p(n) = sum (-1)^(k+1) * p(n-k(3k+1)/2),  -(sqrt(24n+1)-1)/6<=k<=(sqrt(24n+1)+1)/6, k!=0
p:1 1
{r:_%1+24*x
 ke:-6!(1-r;1+r)   /endpoints of k range
 k:ke[0]+!1--/ke
 s:(#k)#-1 1@2!2#k /signs 1 or -1
 p,:pn:1000000!+/s*0|p x-gon[5;k]
 x+0<pn}/2
/55374
