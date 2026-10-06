#!../../k
x:0:"i/04"        /input
r:`I$","\*x       /random order for bingo
b:.''1_'(&~#'x)_x /boards
m:r?b             /times at which the numbers on each board are marked
t:{&/|/'x,+x}'m   /times at which each board wins
s:r[t]*+//'b*t<m  /scores
s@:<t             /sort scores by time of winning
*s                /part1
*|s               /part2

/ https://github.com/rak1507/Advent-Of-Code-APL/blob/main/2021/Day04.dyalog
