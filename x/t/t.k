`"libt.dylib"2:(`loadfns;1);

/ test support for up to 8 args
(add1[0]
 add2[1;2]
 add3[1;2;3]
 add4[1;2;3;4]
 add5[1;2;3;4;5]
 add6[1;2;3;4;5;6]
 add7[1;2;3;4;5;6;7]
 add8[1;2;3;4;5;6;7;8])~+\1+!8

/ test allocating K vectors with a null pointer
(KC0[3;"k"]
 KI0[2;79]
 KF0[5;9.342]
 KL0[4;1 9 13])~("kkk"
 79 79
 9.342 9.342 9.342 9.342 9.342
 (1 9 13;1 9 13;1 9 13;1 9 13))
