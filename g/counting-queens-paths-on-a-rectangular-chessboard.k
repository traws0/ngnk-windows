/https://codegolf.stackexchange.com/questions/203430/counting-queens-paths-on-a-rectangular-chessboard/203448#203448
f:{(x~1 1)+/o'x-/:{|/~x,-/x}#1_+!x}
f:0+f@
\l 0.k
t[1 1;   1]
t[1 2;   1]
t[1 3;   2]
t[1 4;   4]
t[1 5;   8]
t[2 2;   3]
t[2 3;   7]
t[2 4;  17]
t[2 5;  40]
t[3 3;  22]
t[3 4;  60]
t[3 5; 158]
t[4 4; 188]
t[4 5; 543]
t[5 5;1712]
