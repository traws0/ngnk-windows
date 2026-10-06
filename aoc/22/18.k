#!../../k
x:+.'0:"i/18"       /(xs;ys;zs)
x-:-1+&/'x          /translate origin; shift by 1 to make room for boundary
n:2+|/'x            /shape of brick; 2+ for boundary
h:n/'(,/-:\=3)+\:!n /column h[;i] is the 6 neighbours of i
a:@[&*/n;n/x;:;1]   /lava (all arrays flattened)

/part1
+/a*+/~a h

/part2
b:|/|:\|/~!n        /boundary
c:~a|b              /neither lava, nor boundary
s:b|{c*x|/x h}/b    /steam
+/a*+/s h           /like part1 but using s instead of ~a
