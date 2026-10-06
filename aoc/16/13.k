#!../../k
d:`I$*0:"i/13"                            /"designer's favourite number"
f:{2!+/2\d+(x*3+x+2*y)+y*1+y}             /pseudo-random formula
a:@[;-1+n*1+!n;:;1]@f/!2#n:50             /grid
D,:-D:1,n                                 /cardinal directions
w:{v:x@*y;y:(x@)_,/D+\:y;x[y]:1+v;(x;y)}. /wave
i:n/1 1                                   /initial location
(*w/(a;,i))@n/31 39                       /part1
+/1<,/*50 w/(@[a;i;:;2];,i)               /part2
