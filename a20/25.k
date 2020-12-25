#!../k
(a;b):.'0:"i/25"
n:20201227 /modulus
g:7 /generator
G:(n>#:){x,n!(*|x)*(m&n-m:#x)#x}/,g /multiplicative group
l:1+G?a /discrete log
P:{(n!*)/((-1+#y)((n!*)/2#,:)\x)@&y:|2\y} /powmod
P[b;l]
