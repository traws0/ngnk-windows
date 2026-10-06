#!../../k
t:.*0:"i/20" /threshold

/try with n houses, return the house number on success or 0 on failure
/l:limit for the number of houses per elf
/p:presents per house
f:{[n;l;p]
 i:1+!n            /elf numbers
 v:i*1+!'l&(-i)!'n-1 /house visits
 *>(-1+(-p)!t)<@[&n;v;+;i]}

/keep doubling up n until the house is found
{$[r:f[x; x;10];r;o 2*x]}1 /part1
{$[r:f[x;50;11];r;o 2*x]}1 /part2
