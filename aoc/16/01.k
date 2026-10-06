#!../../k
x:", "\*0:"i/01"
d:(0 1 0 -1;1 0 -1 0)@\:4!+\-1 1"R"=*'x /directions
s:`I$1_'x                               /steps
O:{+/x|-x}                              /distance from origin
O@+/'d*\:s                              /part1
b:2#1000;O@b\*&1<#'=b/+\'{s}#'d         /part2
