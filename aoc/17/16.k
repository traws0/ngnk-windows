#!../../k
X:","\*0:"i/16" /instructions
a:`c$"a"+!16 /initial position
f:{$["s"=*y;,/|(0,(#x)-.1_y)_x /apply instruction
     "x"=*y;@[x;i;:;x@|i:`I$"/"\1_y]
            @[x;i;:;x@|i:x?"/"\1_y]]}
g:f/[;X] /apply dance
`0:g a /part1
`0:((#g\a)!_1e9)g/a /part2 (#g\a is loop size)
