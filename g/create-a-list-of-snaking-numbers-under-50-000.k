/https://codegolf.stackexchange.com/questions/191016/create-a-list-of-snaking-numbers-under-50-000/191020#191020
f:{(x;#x:{*/1=3!5&+/x*x:+1_-':(+0 1,'2*!3 3)@10\x}#1+!50000)}
\l 0.k
g:f
f:{+/'g[]};t[0;10290494 670]
f:{12369 45201 1254 10102 1 12 987^*g[]};t[0;!0]
u:1238 159;f:{u^u^*g[]};t[0;!0] /1238 0001 0101 159 - leading 0s are ignored in k
