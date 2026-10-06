pi:3.14159265359
abs:|/1-:\
sgn:-/0<1-:\
gcd:*|(*:)(|!\)/,
lcm:{x*(-gcd[x]y)!y}
prm:{$[x~*x;;:x@o@#x];(x-1){,/'((,(#*x)##x),x)m*(!l)+&\m:~=l:1+#x}/0} /permutations(non-lexicographic)
cmb:{$[y~*y;;:y@o[x;#y]];*|(y-x){((,(1|#*x)#-1+**y),x),'y}\/,''y+!'-!1+x} /combinations(lexicographic)
isp:{p:2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 /is x prime?
 $[x<62;~^p?x;+/~p!'x;0;&/(1=a)|/x=1+(s-1)q\a:(x!*)/((-1+#d)(q:x!*/2#,:)\2 7 61)@&d:(s:*&b)_b:|2\x-1]}
mmu:(+/*)\: /matrix multiplication
inv:{y!*|{x-y*(-*y)!*x}/[1<**:;y,0;x,1]} /multiplicative inverse of x modulo y (extended Euclidean algorithm)
det:{0f^*(#x){(r;x):x;c:h@j:*>h|-h:*x;(r*c*1 -1@2!j;{[j;hc;xi](xi_j)+hc*xi@j}[j;(h_j)%-c]'1_x)}/(1f;x)} /determinant
