#!../../k
/
x:("        ...#"
   "        .#.."
   "        #..."
   "        ...."
   "...#.......#"
   "........#..."
   "..#....#...."
   "..........#."
   "        ...#...."
   "        .....#.."
   "        .#......"
   "        ......#."
   ""
   "10R5L5R10L4R5L5")
\
x:0:"i/22"

D:,/-:\|=2 /cardinal directions
a:-2_x;a:a[;!|/#'a] /map
c:(&~=':c=_c)_c:*|x /commands
f:{Y:x+$[^a. x+y;(~^a.)(-x-)/y;y] /forward[delta;position]
   $["."=a. Y;Y;y]}
(d;p):(0;0,*<^*a){(d;p):x;$[|/"LR"=*y;(4!d+1-2*"L"=*y;p);(d;(.y)f[D d]/p)]}/c /d:direction;p:position
+/1 1000 4*d,1+p /part1
? /part2
