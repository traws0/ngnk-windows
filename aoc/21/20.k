#!../../k
(a;b):2!(0,1+&~#'x)_x:0:"i/20" /input
a:,/a
b:4(+|0,)/b /surround image with 0s
f:{x/(2+#y)':p,y,p:2#*y} /base encode 3-windows of one dimension
g:{+//x(a f[8]2 f')/b} /enhance x times
g 2  /part1
g 50 /part2
