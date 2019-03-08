\l 0.k
n:50000000
p:primes 1+_%n
a:(n>)#p*p
b:(n>)#a*(#a)#p
c:(n>)#b*(#b)#p
bc:(n>)#,/b+\:c
s:(n>)#,/a+/:bc
+/@[&n;s;:;1]
/1097343
