#!../../k
a:0:"i/02"       /input lines
C:4!*'a          /commands 0=down,1=up,2=forward
X:-48+*'|'a      /units
d:+/D:X*1 -1 0@C /depth (D:deltas)
h:+/H:X*2=C      /horizontal positions (H:deltas)
h*d              /part1
h*+/H*+\D        /part2
