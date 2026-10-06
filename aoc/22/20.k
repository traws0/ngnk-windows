#!../../k
b:!n:#a:`I$0:"i/20"

f:{i:x?y
   x_:i
   j:1+(n-1)!-1+i+a y
   (j#x),y,j_x}

g:{p:b f/,/x#,b
   +/a p n!1000 2000 3000+a[p]?0}

g 1 /part1
a*:811589153;g 10 /part2
