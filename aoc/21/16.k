#!../../k
x:*0:"i/16"                            /hex
b:,/+(4#2)\-48+x-7*64<x                /bits
i:0                                    /pointer in b
r:{i+:x;2/b i+!-x}                     /read x bits
l:{16/,[;r 4]1_{r 1}{r 4}\0}           /read literal value
O:{$[r 1;p'!r 11;1_{i<y}[;i+r 15]p\0]} /read operator
p:{x,$[4=*|x:r'3 3;l;O][]}             /read packet

x:p x
{$[4=x 1;0;+/o'2_x]+*x}x               /part1
{$[4=x 1;x 2;(."+*&|:><="x 1)/o'2_x]}x /part2
