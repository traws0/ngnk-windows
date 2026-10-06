#!../../k
sgn:{(0<x)-0>x}
abs:{x|-x}
cyc:{(*|y)x':y} /cyclic eachprior
D:(-1 0;0 1;1 0;0 -1) /clockwise 0=north,1=east,2=south,3=west
L:"|-LJ7FS."!(0 2;1 3;0 1;0 3;2 3;1 2;!0;!0) /which directions do symbols like "L" connect

f:{                            /both parts
 p0:*+&"S"=x                   /initial position
 d0:*&0|/'2 3 0 1=L@x./:p0+/:D /initial direction
 t:{y+:D z;(y;*L[x. y]^4!2+z)}[x]. /next
 e:~p0~{x+D y}.                /stop condition
 (p;d):+e t\(p0;d0)            /path (positions;directions)
 n:-2!1+#p                     /part1
 s:abs[-2!+/*/(+;-)cyc'+p]     /area through the shoelace formula
 (n;s-n-1)}                    /for part2 - https://en.wikipedia.org/wiki/Pick%27s_theorem

`0:$f@0:"i/10"


t:{:[z~r:f[y]x-1;;(`fail;x;y;z;r)]} /test - x:part(1 or 2), y:input, z:expected

t[1;("....."
     ".S-7."
     ".|.|."
     ".L-J."
     ".....");4]

t[1;("-L|F7"
     "7S-7|"
     "L|7||"
     "-L-J|"
     "L|-JF");4]

t[1;("..F7."
     ".FJ|."
     "SJ.L7"
     "|F--J"
     "LJ...");8]

t[1;("7-F7-"
     ".FJ|7"
     "SJLL7"
     "|F--J"
     "LJ.LJ");8]

t[2;("..........."
     ".S-------7."
     ".|F-----7|."
     ".||.....||."
     ".||.....||."
     ".|L-7.F-J|."
     ".|..|.|..|."
     ".L--J.L--J."
     "...........");4]

t[2;(".F----7F7F7F7F-7...."
     ".|F--7||||||||FJ...."
     ".||.FJ||||||||L7...."
     "FJL7L7LJLJ||LJ.L-7.."
     "L--J.L7...LJS7F-7L7."
     "....F-J..F7FJ|L7L7L7"
     "....L7.F7||L7|.L7L7|"
     ".....|FJLJ|FJ|F7|.LJ"
     "....FJL-7.||.||||..."
     "....L---J.LJ.LJLJ...");8]

t[2;("FF7FSF7F7F7F7F7F---7"
     "L|LJ||||||||||||F--J"
     "FL-7LJLJ||||||LJL-77"
     "F--JF--7||LJLJ7F7FJ-"
     "L---JF-JLJ.||-FJLJJ7"
     "|F|F-JF---7F7-L7L|7|"
     "|FFJF7L7F-JF7|JL---7"
     "7-L-JL7||F7|L7F-7F7|"
     "L.L7LFJ|||||FJL7||LJ"
     "L7JLJL-JLJLJL--JLJ.L");10]
