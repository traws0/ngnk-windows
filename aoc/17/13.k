#!../../k
x:0:"i/13"
(d;w):`I$+": "\'x /depths;widths
p:2*w-1 /periods
+/d*w*~p!'d /part1

/part2
f:{*&@[x#1;d{y+z*!1+(-z)!x-1+y:z!-y}[x]'p;:;0]} /try to solve with sieve size x
{$[^r:f x;o@2*x;r]}1 /keep doubling the size until we get a result
