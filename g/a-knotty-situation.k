/https://codegolf.stackexchange.com/questions/170567/a-knotty-situation/171410#171410
f:{!N::2*n:#x;{+/d,'x,'d:&:'-2!(|/n)-n:#:'x}(+/1-2*s){j::+,/y;,/(&0|2*x;(-1+#?{x[j]&:x@|j;x}/!N){-(d,x)+x,d:&4}/,1;&0|-2*x)}'(N!{(x,'|1+x;x+/:!2)}'((2*!n),'-1+x|-x)@'0 1=/:x>0)@'/:+~(y<0)=s:!n#2}

F:{p[k],'-(_(#p)%2)-k:&~~p:f[x;y]} /wrapper to convert result
t:{$[x[2]~r:F/2#x;`ok;(`fail;x;r)]} /test function
t(!0;!0;,1 0;"unknot")
t(,2;,1;,-1 3;"unknot with a half-twist (positive crossing)")
t(,2;,-1;,-1 -3;"unknot with a half-twist (negative crossing)")
t(2 4;1 1;,1 6;"unknot with two half-twists (positive crossings)")
t(4 6 2;1 1 1;(1 -7;-1 -3;-1 5);"right-handed trefoil knot, 3_1")
t(4 6 8 2;-1 1 -1 1;(1 -8;-1 -4;1 0;-1 4;1 8);"figure-eight knot, 4_1")
t(6 8 10 2 4;-1 -1 -1 -1 -1;(-1 -7;-1 1;1 5;-1 9;1 13);"pentafoil knot, 5_1")
t(6 8 10 4 2;-1 -1 -1 -1 -1;(-1 -11;1 -7;-2 -3;1 1;-1 5;1 9);"three-twist knot, 5_2")
t(4 8 10 2 12 6;1 1 -1 1 -1 -1;(-1 -12;2 -8;-2 -4;3 0;-2 4;2 8;-1 12);"6_3")
t(4 6 2 10 12 8;-1 -1 -1 -1 -1 -1;(1 -10;2 -2;-2 2;1 6;-2 10;1 14);"granny knot (sum of two identical trefoils)")
t(4 6 2 -10 -12 -8;1 1 1 1 1 1;(1 -14;-2 -10;1 -6;-2 -2;2 2;1 10);"square knot (sum of two mirrored trefoils)")
t(6 -12 2 8 -4 -10;-1 -1 -1 1 -1 1;(1 -2;1 6;-1 10);"example knot")
