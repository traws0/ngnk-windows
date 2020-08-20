/https://codegolf.stackexchange.com/questions/209860/expected-number-of-trailing-zeros/209872#209872
f:{1+x,x-+/2\x}
\l 0.k
t[0;1 1]
t[1;2 1]
t[2;3 2]
t[3;4 2]
t[256;257 256]
t[12345;12346 12340]
