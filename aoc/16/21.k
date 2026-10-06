#!../../k
s:{@[y;x;:;|y x]}   /swap
r:{,/|(0,(#y)!x)_y} /rotate

sp1:sp2:{s`I$x 2 5}                              /swap position X with position Y
sl1:sl2:{s[y?*'x 2 5]y}                          /swap letter X with letter Y
rl1:rr2:{r`I$x 2}                                /rotate left X steps
rr1:rl2:{r@-`I$x 2}                              /rotate right X steps
rb1:{r[-({x+1+3<x}'!#y)@y?x.6 0]y}               /rotate based on position of letter X
rb2:{c:(-1+#y)r[1]\y;c@(rb1[x]'c)?y}
rp1:rp2:{(i;j):`I$x 2 4;i+:!1+j-i;@[y;i;:;|y i]} /reverse positions X through Y
mp:{y[*x]/(0,*|x)_y_*x}                          /move position X to position Y
mp1:{mp[`I$x 2 5;y]}
mp2:{|mp[(#y)-1+`I$x 5 2;|y]}

a:0:"i/21";f:{(.*'(2#z),x)[z:" "\z]y}
`0:"abcdefgh"f[$1]/ a /part1
`0:"fbgdceah"f[$2]/|a /part2
