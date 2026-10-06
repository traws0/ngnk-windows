#!../../k
\l ../../l/maths.k
x:0:"i/08"
i:"R"=*x                                    /instructions
(k;l;r):+`${3 3#x^" =(,)"}'2_x              /keys,left,right
t:k?(l;r)                                   /transition matrix
f:{*(~|/y=*|:){(1+*x;t[i(#i)!*x;*|x])}/0,x} /number of steps
f . k?`AAA`ZZZ                              /1
lcm/f\:/&'"AZ"=\:*|+$k                      /2
