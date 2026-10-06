#!../../k
N:2*O:_5e6 /base and offset for coordinate-pair encoding
e:N/O+&2!0:"i/23" /elf positions
in:{x@:<x;y=x@x'y}
rot:{,/|(0,(#y)!x)_y}
D8:(-1-N;-N;1-N;1;1+N;N;-1+N;-1) /offsets of 8 neighbours
D4:4':7#(-N;N;-1;1)              /4 rotations of offsets of north,south,west,east
D6:0,'D4,'0                      /same as D4 but with leading and trailing 0s
I4:+'4':7#8!0 4 6 2+\:!3         /4 rotations of offsets of NW,N,NE; SW,S,SE; NW,W,SW; NE,E,SE

/State :: (time;encodedElfPositions)
/F:round[oldState] -> newState
F:{(t;e):x
 h:in[e]D8+\:e /neighbours
 i:4!t
 p:D6[i]@+/&\(,|/h),|/h I4 i /proposed
 E:e+p*(1=+/q=)'q:e+p /new elf positions
 (t+~e~E;E)}

{(*/1+(|/'x)-&/'x)-#*x}(-O)+N\*|10 F/0,,e /part1
1+*F/0,,e /part2
