#!../../k
sb:,'/(s;b):|'2 2#`I$+{(" "\x^",:xy=")2 3 8 9}'0:"i/15"
abs:{x|-x}
d:+/abs s-b

/part1
(-#?sb[1;&r=*sb])+/-/|+0N 2#|\,/+{x@\:<*x}s[1]+/:{(-x;1+x)}d-abs s[0]-r:2000000

//part2 (recursive)
/{$[|/&/~d</:+/'abs s-/:,/,/:\:/+x-!2;0
/   -2<&/-/x;4000000/|*x
/   |/o'+',/,/:\:/,''2':'+(*x;-2!+/x;*|x)]}2#'0 4000001

//part2 (intersection of 4 shifted outlines)
//https://codeberg.org/ovs/aoc2022/src/branch/master/15.k
/l:_4e6
/D:1+d
/vi:D=+/abs s-
/v:{(,/'x)@\:&,/&/(~l<|/x;-1<&/x;vi x;+vi@+'x)}
/(f;c;g;e):D+/:t,-t:(-/s;+/s)
/(p;q):v'-2!((c-/:g;c+/:g);(f-/:e;-f+/:e))
/l/|p@\:*&&/~^q?'p

/part2
4000000/|-2!(+;-).\:(*{x^x^y}/(d+1;-d+1)+\:)'(+/s;-/s)
