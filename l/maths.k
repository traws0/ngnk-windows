pi:3.14159265359
abs:|/-:\
sgn:-/0<-:\
gcd:*|(*:)(|!\)/,
lcm:{x*(-gcd[x]y)!y}
prm:{$[x~*x;;:x@o@#x];(x-1){,/'((,(#*x)##x),x)(~i=\:i)*i+i<\:i:!1+#x}/0} /permutations(non-lexicographic)
cmb:{$[y~*y;;:y@o[x;#y]];*|(y-x){((,(1|#*x)#-1+**y),x),'y}\/,''y+!'-!1+x} /combinations(lexicographic)
pri:{$[x<10;(x>)#o 10 /primes <x
 @[;0;:;2]1+2*&@[(-2!x)#1 0 0 1 0 1 1 0 1 1 0 1 0 0 1;!3;:;1]{$[x@-2!y;@[x;-2!y*y+2*!-2!2+(-y)+(-y)!-1+2*#x;:;0];x]}/7+2*!0|-2!-5+_%x]}
isp:{p:2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 /is x prime?
 $[x<62;~^p?x;+/~p!'x;0;&/(1=a)|/x=1+(s-1)q\a:(x!*)/((-1+#d)(q:x!*/2#,:)\2 7 61)@&d:(s:*&b)_b:|2\x-1]}
mmu:(+/*)\: /matrix multiplication
