#!../k
/https://gist.github.com/xpqz/73e9d57a7f1921f7d44704505a22fa3e
\l ../l/maths.k

p1:{(z*z)=+/*/2 2#x,y}             ; p1:{~-/*/2#,|x,y,z}
p2:{(2(|1|':)/"0">x)|^"aeiou"?_x}# ;
p3:{((x-1)(|+\)\1 1)[;1]}          ; p3:1_*+(|+\)\[;!2]@
p4:" "/(~#:')_" "\                 ;
p5:{{x~|x}l^(l:_x)^`c$"a"+!26}     ; p5:1=#|:\(~"a{"')#_:
p6:{+(!x;.x)}@#'=+/1+!(),          ; p6:+(!:;.:)@\:#'=+/1+!:
p7:{lcm[x;y]%y}                    ; p7:%/gcd\,
p8:{%+/d*d:-/x}                    ; p8:%+/*/2#,-/
p9:{(x*x*`sin@2*y*pi%180)%9.8}     ; p9:{x*x*`sin[y*pi%90]%9.8}
p10:100*|/1_0{(x-y)%y}':           ; p10:100*|/1_-1+%':

p:{`0:x:"p",$x;f::. x;} /prepare for testing problem x
e:{$[|/`d=(@x;@y);1e-5>d|-d:x-y;x~y]} /match, but approximate for floats
T:{ \$[e[y]r:f . x;;(`fail;x;y;r)];} /test (x:list of args; y:expected result)
t:{T[,x]y} /test (x:single arg; y:expected result)

p 1;T[3 4 5]1;T[2 3 4]0
p 2;t["if you can read this, it worked!"]"if yu cn rd ths, it wrkd!";t["k is REALLY cool"]"k is RLLY cl"
    t[""]"";t[,"a"]@,"a"
p 3;t[10]1 1 2 3 5 8 13 21 34 55;t[1]@,1;t[0]@!0
p 4;t[" this is a test "]"this is a test";t[""]"";t["hello world!"]"hello world!";t[," "]""
p 5;t["a man, a plan, a canal, panama!"]1;t[""]1;t[,"a"]1;t["APL"]0
p 6;t[6 6](2 1;3 2;4 3;5 4;6 5;7 6;8 5;9 4;10 3;11 2;12 1);t[6 4](2 1;3 2;4 3;5 4;6 4;7 4;8 3;9 2;10 1)
    t[,3](1 1;2 1;3 1) /t[!0]()
p 7;T[10 10]1.0;T[10 5]2.0;T[5 7]5.0
p 8;t[2 5]3.0;t[(2 2;5 6)]5.0;t[!0]0.0;t[(2 2 3 4;3 7 10 9)]10.0
/p 9;T[100 45]1020.408163;T[0 45]0;T[100 90]1.249639591e-13
p 10;t[80 100 120 140]25.0;t[123 123 123]0.0;t[101 102 114 117 101 110 102 111 118 115 124 122]11.76470588235294
     t[200 180 160 140 120] -10.0
