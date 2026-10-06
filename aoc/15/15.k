#!../../k
p:{`I$(" "\x^",")2+2*!5}'0:"i/15" /ingredients*properties
r:+{$[1=x;,,y;,/((x-1)o'|i),''i:!1+y]}[#p;100] /ingredients*recipes
|/s:*/0|+/r*/:'-1_'p /part1
|/s@&500=+/r**|+p /part2
