#!../../k
x:(|'.'" -> "\)'0:"i/14"
h:2+|/*+,/x /height
w:1000      /width
a:(&h*w){@[x;w/m+!1+(|/y)-m:&/y;:;1]}/,/2':'x /flat grid
d:0 /done? (fallen off the grid for part1)
:r:{$[d;0;a x;[d|:^a x;0];(a[x]:~d)+/o'x+w+0 -1 1]}500 /part1
r+{$[a x;0;(a[x]:1)+/o'0 -1 1+w+x]}500 /part2
