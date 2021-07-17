#!../k
/https://codegolf.stackexchange.com/questions/216113/for-what-block-sizes-is-this-checksum-valid/216122#216122
f:{(|/2!+/#[;x]0N,)_&~(!#x)!'#x}

\l 0.k
t[1 1 0 0 1 0 0 0 0 1 0 0 0 0 0 0;1 2 4]
t[0 1 0 0 1 0 1 0 0 1 0 0;1 2 3]
t[0 0 0 0 0 0 0 0 0 0;1 2 5]
t[1 0 1 1 0 1 0 0 0;1 3]
t[1 0 0 1 0 1 1 0;1 2]
t[1 0 0 0 0 0 0 0;!0]
t[0 1 0 1 0 1 0;!0]
t[1 1;,1]
t[,1;!0]
t[!0;!0]
