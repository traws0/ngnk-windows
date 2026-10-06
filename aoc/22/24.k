#!../../k
x:0:"i/24"          /input
x:2(+-1_1_)/x       /strip border
n:(#x;#*x)          /shape
a:,/x               /flat x
D:+,/1-:\=2         /directions
h:n/0|(n-1)&D+\:'!n /neighbours
b:&'"v>^<"=\:a      /blizzards
l:-1+#a             /lower-right cell

/state=(time;maskOfPossiblePositionsOfExpedition)
/f:step[x:source;y:destination;z:state] -> state
f:{(t;e):z;$[e y;z;(1+t;@[;n/n!'(D*1+t)+n\b;:;0]@[;x;:;1]e|/e h)]}

/g:go[x:source;y:destination;z:oldTime] -> newTime
g:{1+*f[x;y]/(z;&#a)}

g[0;l]0             /part1
g[0;l]g[l;0]g[0;l]0 /part2
