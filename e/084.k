n:200000 /number of moves to simulate
jmps:0 10 11 24 39 5 /GO,JAIL,C1,E3,H2,R1
c:&40;p:0;m:0 /c:counters, p:position, m:consecutive doubles
f:{c[p]+:1;d:1+2?4;m+:1;m*:=/d;p::(#c)!p+/d
   $[(p=30)|m>2;p::10                    /if on G2J, or got 3 consecutive doubles, go to JAIL
     ~^2 17 33?p;$[2>r:*1?16;p::jmps r;] /if on CC1 or CC2 or CC3, possibly go to GO or JAIL
     ~^i:7 22 36?p                       /if on CH1 or CH2 or CH3, go ...
     p::$[6>r:*1?16;jmps r               / to the corresponding square from jmps
          8>r;15 25 5 @i                 / to next R (railway company) - R1 or R2 or R3
          8=r;12 28 12@i                 / to next U (utility company) - U1 or U2 or U1(again)
          9=r;(#c)!p-3                   / back 3 squares
          p]];}
n f/0;
100/3#>c
/101524
