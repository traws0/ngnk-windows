#!../../k
x:0:"i/22" /input
i:^x@'2 /instructions (0=off,1=on)
x:(0 1+`I$+(".."\*|)'"="\'","\)'x /cuboids (start-inclusive end-exclusive)
s:{y@\:\:&&/</y:(|;&)@'/(x;y)} /intersections
g:--/(+/*/-/)'{@[;0;,'';y#''z]x,'''s[z]'|x}/[2 2 3 0#0;i;]@ /solve
g -50|51&x /part1
g x        /part2

/ https://copy.sh/k/aoc21/22.k
