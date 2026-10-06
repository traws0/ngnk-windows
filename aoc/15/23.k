#!../../k
a:0:"i/23" /instructions
f:{
 r::x
 (~(0,#a)'){
  c:" "\a[x]^"+,"
  i:-97+*c 1
  $["hlf"~*c;r[i]:-2!r i
    "tpl"~*c;r[i]*:3
    "inc"~*c;r[i]+:1
    "jmp"~*c;x+:         -1+`I$c 1
    "jie"~*c;x+:(~2!r i)*-1+`I$c 2
    "jio"~*c;x+:( 1=r i)*-1+`I$c 2]
  1+x}/0
 r 1}
f 0 0 /part1
f 1 0 /part2
