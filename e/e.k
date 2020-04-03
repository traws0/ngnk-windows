/number theory
pr:{$[x<10;:(x>)#o 10;]
 r:1+2*&@[(-2!x)#0x010000010001010001010001000001;!3;:;0x01]{$[x@-2!y;@[x;-2!y*y+2*!-2!2+(-y)+(-y)!-1+2*#x;:;0x00];x]}/7+2*!0|-2!-5+_%x
 r[0]:2;r}
isp:{p:2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61;$[x<62;:~^p?x;~&/p!'x;:0]
 q:{x!y*y}[x];&/(1=ad)||/(x-1)=(s-1)q\ad:(x!*)/((-1+#d)q\2 3 61)@&d:(s:*&b)_b:|2\x-1}
tot:{(!x){[x;r;p]i:p*1+!(-p)!x-1;r[i]:(-p)!r[i]*p-1;r}[x]/pr x}
sg1:{a:(x#1){[r;p]n:#r;m:1+(-p)!n-1;q:-1_(n>)(p*)\p;@[r;p*!m;*;@[m#p+1;(-1_q)*!'1+(--1_q)!'m-1;+;1_q]]}/p:pr 2+_%x /sigma1: sum of divisors
 p:(#p)_pr x;a[p*!'1+(-p)!'-1+#a]*:p+1;a[0]:0;a}
cf:{$[x=r*r:_%x;0;*|+(~(2*r)=*|:)({[x;r;m;d;a]m:(d*a)-m;d:(-d)!x-m*m;a:(-d)!r+m;m,d,a}[x;r].)\0 1,r]} /continued-fraction sqrt
gcd:*|(*:)(|!\)/,
/combinatorics
prm:{(x-1){,'/(!1+#x){(,(#*y)#x),y+y>x-1}\:x}/,,0};cmb:{$[x=1;,!y;(,&#'*'u),,'/u:i+(x-1)o'y-i:1+!1+y-x]};gon:{-2!y*4-x+y*2-x} /y-th x-agonal num

/bignum
big:10\;sml:10/;car:{(~**x)_x:((*x),0)+0,*|x:0 10\x}/;add:{car@+/(&'(|/l)-l:#'x),'x:(x;y)};mul:{car@[&-1+(#x)+#y;(!#x)+\:!#y;+;x*\:y]}
max:{$[(#x)<#y;y;(#y)<#x;x;0<*(x-y)^0;x;y]};lt:{$[d:(#x)-#y;d<0;*>(x;y)]};sqrt:{(1,&l){{$[lt[mul[Y;Y:@[y;z;+;1]];x];Y;y]}[x;;z]/y}[x]/!l:-2!-1+#x}

P:{1"P",($x),":";}

P 1;+/&|/~5 3!\:!1000
P 2;+/(~2!)#*+-1_(*4000000>)(|+\)\!2
P 3;|/{~x!n}#pr 2+_%n:600851475143
P 4;|/.'{x~|x}#$,/a*\:a:100_!1000
P 5;{x*(-gcd[x;y])!y}/1+!20
P 6;(b*b:+/a)-+/a*a:1+!100
P 7;pr[200000]10000
P 8;|/*/(-|i)_'(i:!13)_\:.',/0:"i/p008.txt"
P 9;|/*/(ab,,c)@\:&(+/ab*ab)=c*c:1000-+/ab:!2#1000
P 10;+/pr 2000000
P 11;|/,//*/''4''(a;+a;u,'a,'|u;(|u),'a,'u:&'!#a:.''" "\'0:"i/p011.txt")
P 12;-2!i*-1+i:*&500<@[;!2;:;1]@*/1++':'@[a;0;:;]0|-1+*a,:,~+/a:{@[&n;q*!'(-q:-1_(n>)(x*)\x)!'n;+;1]}'pr 2+_%n:100000
P 13;sml 10#add/(0:"i/p013.txt")-"0"
P 14;c:@[&n:1000000;1;:;1] /cached collatz chain lengths
     *>{$[v:0|c x;:v;];v:$[2!x;2+o@2+3*-2!x;1+o@-2!x];$[x<n;c[x]:v;v]}'@[!n;0;:;1] /if x is odd, take two steps at a time
P 15;*|n(+\)/(1+n:20)#1
P 16;+/1000{add[x;x]}/big 1
P 17;{+/(100*x;9*100*#"Hundred";9*99*#"And"
         10*+/(x;#"TenElevenTwelveThirteenFourteenFifteenSixteenSeventeenEighteenNineteen"
               10*#"TwentyThirtyFortyFiftySixtySeventyEightyNinety";8*x)
         #"OneThousand")}@#"OneTwoThreeFourFiveSixSevenEightNine"
P 18;*{y+1_|':x}/|.''" "\'0:"i/p018.txt"
P 19;+/6=7!(+/m)+\0,-1_,/100#(3#,m),,@[;1;+;1]m:31 28 31 30 31 30 31 31 30 31 30 31
P 20;+/mul/big'1+!100
P 21;+/&(i=s s)>i=s:sg1[n]-i:!n:10000
P 22;+/,/(1+!#a)*a@<a:(1-"A")+.'","\1:"i/p022_names.txt"
P 23;+/&@[n#1;a*n>a+:,\a:&sg1[n]>2*!n:1+28123;:;0] /abundant numbers
P 24;10/i{x(i_y),y}/(|1+i:!10)\999999
P 25;#{1000>#*x}{add\|x}\big'1 1
P 26;1+*>r:{m::x;(#a)-1+a?l:*|a:{l&2>+/x=l:*|x}{x,m!10**|x}/,1}'1+!1000
P 27;**/1_{(x;a;b):x;i:&isp'v:b+x*a+x;$[n<|/v;;~#i;(x;a;b);(x+1;a i;b i)]}/1,{x@'!#'x}(-1000+!2001;pr 1000)
P 28;+/+\1,/4#'2*1+!-2!1001
P 29;#?,/1_n(i mul')\i:big'2+!n:-1+100
P 30;-1+/&s=!#s:+/(*/5#,!10)@!6#10
P 31;1 2 5 10 20 50 100 200{a[y]+:0^a y-x}'\:!#a:~!201;*|a
P 32;+/?*|a@\:&a[2]=*/2#a:,'/10/''(0 2 5;0 1 5)_\:1+prm 9 /x*yyyy=zzzz or xx*yyy=zzzz
P 33;f:{(-gcd/x)!x} /lowest terms
     *|f@*/{(</x)>=/x}#?,/{a@&(&/'a>9)&(f x 1 2)~/:f'a:10/''x((0 1;0 2);(0 1;2 0);(1 0;0 2);(1 0;0 2))}'+!3#10
P 34;+/3_&(!#*a)=(+/(*\1|!10)a)-(#a)-&1,9*\1,(-1+#a:!6#10)#10
P 35;2+#{x^x^{.,/|0 1_$x}'x}/{~|/^"1379"?$x}#pr 1000000 /+2 because 2 and 5 don't match /[1379]+/
P 36;+/{x~|x:2\x}#{x~|x:$x}#!1000000
P 37;+/(7<)#{&/isp'.'|',\|$x}#,/{isp#,/(!10)+/:10*x}\2 3 5 7
P 38;d:,/$1+!9;|/.'{d~x@<x}#{9=#x}#,/,'\$+\9#,!10000
P 39;p@:i:&(l+1)>p:2*/+\mn:1+|cmb[2;l:1000] /primitive triples: a=m^2-n^2 b=2mn c=m^2+n^2 P=2m(m+n) where gcd(m,n)=1 and m>n>0
     p@:&1=gcd'/mn@\:i
     *>#'=,/p*1+!'(-p)!'l
P 40;*/.'(,/$!*|a)a:6(10*)\1
P 41;p:pr mp:_%10000
     isp1:{$[~&/2 3 5 7!'x;0;x<mp;~^p?x;&/p!'x]}
     |/,/{isp1#10/1+prm x}'4 7 /digit sum of other pandigitals is divisible by 3
P 42;+/~^({-2!x*1+x}@!1+-2!*|/a)?a:+/'(1-"A")+1_'-1_'","\1:"i/p042_words.txt"
P 43;+/10/p@\:&~+/pr[18]!'10/'3'1_p:prm 10
P 44;p@*&0<+/'&/0^@[&1+*|p;p;:;1](p+\:p;p+\:2*p:gon[5]1+!3000)
P 45;i:&#a:3 5 6  gon\:!1000000
     3{i+:1;{~x}{v:a@'i;$[&/v=*v;:*v;];i[*<v]+:1;0}/0}/0
P 46;*1_&@[(n+1)#!2;(n&(2*/2#,!1+_%-2!n)+\:p;p:pr n:10000);:;0]
P 47;*1-k-&(k-1)&':/(k:4)=(&n){x[y*!(-y)!-1+#x]+:1;x}/p:pr 2+_%n:1000000
P 48;h:_%m:10000000000;sqr:{m!b*(b:h!x)+2*h*(-h)!x};pow:{m!$[2!y;x;1]*$[y>1;m!sqr o[x;-2!y];1]}
     m!+/{pow[x;x]}'1+!1000
P 49;.,/$*^[;,1487 4817 8147]{=/1_-':x}#,/{x(+i)@&&/-1>':i:!3##x}'{2<#x}#p@.={x@<x}'$p:(999<)#pr 10000
P 50;a:!0;b:-1_p:pr n:1000000
     {x}{b+:(#b)#x_p;b::(n>)#b;a,:b;$[#b;x+1;0]}/1;
     *|(0|@[&n;p;:;1]@)#a
P 51;h:@[n#0x00;p:pr n:1000000;:;0x01] /sieve
     f:{a:10\x
        m:1_'-1_'!(#a)#2            /all patterns except "no stars" and "all stars"
        b:(10/m*a)+/:10/'(~m)*/:!10 /numbers to test for primality
        b[0;!-2!#*b]:0              /no leading zeroes
        &/c@&h c:,/b@\:&7<+/h b}    /min of the pr from 8+ families
     &/f'p
P 52;{x+1<#?{x@<x}'$2 3 4 5 6*x}/1
P 53;m:1000001;+/m=,/100{m&(0,x)+x,0}\1
P 54;p:{(s;r):("CDHS";"23456789TJQKA")?'|+x /suits ranks
        f:1=#?s           /flush?
        g:~#((!5)+&/r)^r  /straight?
        d:10/{x@>x}@#'=r  /rank distribution
        v:+/|\(f&g;d=41;d=32;f;g;d=311;d=221;d=2111;1) /9=StraightFlush(orRoyal) 8=FourOfAKind etc, 1=HighCard
        h:r@>r+13*+/r=\:r /ranks grouped and ordered by multiplicity
        100/v,h}
     +/(>/p'0 5_" "\)'0:"i/p054_poker.txt"
P 55;+/50{$[y~|y:add[y;|y];0;x;o[x-1;y];1]}'big'1_!10000
P 56;|/+/',/mul'\99#,big'1+!99
P 57;+/>/'#''1000{(add[s;x 1];s:add/x)}\big'1 1
P 58;c:1;n:0 /c:corner values, n:number of pr on diagonals so far
     1+2*{c+:2 4 6+8*x;n+:+/isp'c;x+(10*n)>4*x}/0 /x:current layer; side is 1+2*x; number of values on diagonals is 1+4*x
P 59;f:8167 1492 2782 4253 12702 2228 2015 6094 6966 153 772 4025 2406 6749 7507 1929 95 5987 6327 9056 2758 978 2360 150 1974 74 /a-z freqs
     F:@[&256;"aA"+\:!#f;:;2#,f]            /0x00-0xff freqs
     c:(8#2)\.'","\*0:"i/p059_cipher.txt" /ciphertext in binary
     a:{2/~c=(#*c)#'(8#2)\x}'"a"++!3#26   /all possible plaintexts
     +/*`c$a@&{x=|/x}@+/'F a              /best plaintext by sum-of-freqs score
P 60;h:(a@'1)@=*'a:.''{$[~isp@.,/x;0;isp@.,/|x]}#s@+{x@\:&</x}@!2##s:$1_pr 10000
     &/+/'3{,/x,/:'{x^x^y}/'h x}/a
P 61;a:{@[100#,!0;-100!x;,;100!x]}'(999<)#/:(10000>)#/:(3+!6)gon\:1+!140
     101*+/{x{*y x}\|a 5,y}/|*,/{(,x),/:&0|/'(!100)=,//'@/a 5,x}'+prm 5
P 62;*/3#**{5=#x}#.={x@<x}'($*/3#,!10000)-"0"
P 63;+//a=!#a:#''30(i mul')\(#i:big'1+!9)#,big 1
P 64;+/~2!#'cf'!10000
P 65;+/*(big'!2){(add[x 1;mul[*x;y]];*x)}/|big'n#2,/+(1;2*1+!n:1+100;1)
P 66;pell:{$[x=r*r:_%x;:,0;]
           c:-1_*|+(~(2*r)=*|:)({[x;r;m;d;a]m:(d*a)-m;d:(-d)!x-m*m;a:(-d)!r+m;m,d,a}[x;r].)\0 1,r /cfrac sqrt
           u:*|(big'!2){(x 1;add[*x;mul[y;x 1]])}/|big'c
           $[2!#c;add[big 1;add/2#,mul/2#,u];u]}
     *&a~\:max/a:pell'!1001
P 67;*{y+1_|':x}/|.'0:"i/p067_triangle.txt"
P 68;j:,/+i:(2*n)!0 1 3+\:2*!n:5
     |/((*/16#10)>)#{.,/$x j}'{1=#?+/x i}#+1+r@\:&&/(*r)</:(r:prm 2*n)2+2*!n-1
P 69;*>(-tot n)!'1000*!n:1000000
P 70;*{$[</x*|y;x;y]}/n,'t n:2_&=/+/'(9(10*)\1)(10\t:tot@*/N;!N:7#10)
P 71;*{$[>/x*|y;x;y]}/+(-7!-1+3*d;d:1+!1000000)
P 72;-1+/tot 1+1000000
P 73;t:~(n+1)#'~!'p:pr n:12000
     +/{a:-3!x+2;b:1+-2!x;+/*/a_'b#'t@&~p!'x}'4+!-3+n
P 74;a:+/(|\0<d)*(*\1|!10)d:!3,6#10
     +/60=1000000#{x&61&1+x a}/@[(#a)#61;169 363601 1454 871 45361 872 45362;:;3 3 3 2 2 2 2]
P 75;c:&1+m:1500000
     {x@:<x;l:+/x;$[l>m;:0;];c[l*!1+(-l)!m]+:1
      o'+/((1 2 2;- 1 2 2;1 2 2);(- 2 1 2;2 1 2;2 1 2);(2 2 3;2 2 3;2 2 3))*x;}3 4 5
     +/1=@[c;0;:;0]
P 76;-1+*|*|100{(-1_x),,+\+/x*|=#x:(x,'*|+x),0}/,,1
P 77;{{a[x+y]+:a y;}[x]'!0|n-x;}'p:pr@#a:~!n:100
     *&5000<a
P 78 /using the "pentagonal" recurrence relation from https://en.wikipedia.org/wiki/Partition_function_(number_theory)#Recurrence_relations
     /p(n) = sum (-1)^(k+1) * p(n-k(3k+1)/2),  -(sqrt(24n+1)-1)/6<=k<=(sqrt(24n+1)+1)/6, k!=0
     p:1 1;{p,:pn:1000000!+/(0|p x-gon[5;k])*(#k)#-1 1@2!2#k:e[0]+!1--/e:-6!(1-r;1+r:_%1+24*x);x+0<pn}/2
P 79;a:?.''0:"i/p079_keylog.txt"
     d:?,/a /there are 8 distinct digits in all attempts, so let's try 8-digit codes first
     e:?,/2''a /edges of a graph
     10/|{?x,d@&~+/'d=\:*'{2=#x}#e^\:x}/!0 /topological sorting, and the code turns out to be only 8 digits
P 80;+/{$[x=r*r:_%x;0;+/100#sqrt@(10\x),&200]}'1+!100
P 81;m:-2!0N-1;*|*|{x&a+(m,'-1_'x)&m,-1_x}/+\+\'a:.''","\'0:"i/p081_matrix.txt"
P 82;m:-2!0N-1;&/*|+{x&a+(1_x,m)&(m,-1_x)&m,'-1_'x}/+\'a:.''","\'0:"i/p082_matrix.txt"
P 83;m:-2!0N-1;*|*|{x&a+&/(m,-1_x;1_x,m;m,'-1_'x;1_'x,'m)}/+\+\'a:.''","\'0:"i/p083_matrix.txt"
P 84;n:200000;j:0 10 11 24 39 5;c:&40;p:0;m:0 /n:nr of moves to simulate, j:GO,JAIL,C1,E3,H2,R1, c:counters, p:position, m:consecutive doubles
     f:{c[p]+:1;d:1+2?4;m+:1;m*:=/d;p::(#c)!p+/d
        $[(p=30)|m>2;p::10                    /if on G2J or got 3 consecutive doubles, go to JAIL
          ~^2 17 33?p;$[2>r:*1?16;p::j r;]    /if on CC1|CC2|CC3, possibly go to GO|JAIL
          ~^i:7 22 36?p                       /if on CH1|CH2|CH3, go:
          p::$[6>r:*1?16;j r                  / to the corresponding square from j
               8>r;15 25 5 @i                 / to next R (railway company) - R1|R2|R3
               8=r;12 28 12@i                 / to next U (utility company) - U1|U2|U1(again)
               9=r;(#c)!p-3                   / back 3 squares
               p]];}
     n f/0;
     100/3#>c
P 85;*/2#,/&'a=&/&/a|:-a:2000000-t*\:t:-2!i*1+i:!2000
P 86;c:0;{c<1000000}{x{c+:$[~a=r*r:_%a:(y*y)+x*x;0;y>x;1+x--2!1+y;-2!y];}'3_!1+2*x+:1;x}/2
P 87;+/@[&n;;:;1]f#,/a+/:f#,/b+\:f#{x*(#x)#p}b:f#{x*(#x)#p}a:(f:n>)#p*p:pr 1+_%n:50000000
P 88;a:,/{,/x,/:'(*'|'x)_'!'1+(-*/'x)!'2*L}\,'2_!2*L:12000 /all factorisations up to 2L
     +/?2_@[0,L#0N-1;k*(L+1)>k:{(#x)+(*/x)-+/x}'a;&;*/'a]
P 89;r:(,(!10)#'"M"),($`CDM`XLC`IVX)@\:(!0;0;0 0;0 0 0;0 1;1;1 0;1 0 0;1 0 0 0;0 2)
     +/{(#x)-#,/r@'(4#10)\+/a*1-2*<':a:1 5 10 50 100 500 1000"IVXLCDM"?|x}'0:"i/p089_roman.txt"
P 90;sq:(+(f:{x+3*x=6})@10\i*i:1+!9)
     #&(&/|/(&/'|/''sq=\:)'1|:\)'+c cmb[2;#c:+f cmb[6;10]]
P 91;(*/2#n-1)+/(a[1]=+/a_1)&/0<a:(+/*/2#,:)'p,,-/p:0 2_!4#n:1+50
P 92;+/(7(+/n#'(&'a*a:!10),\:)/~i)*{$[x<2;0;x=89;1;o@+/x*x:.'$x]}'i:!n:1000
P 93;R:{$[1<*|x;(-gcd/x)!x;x]} /rational
     op:({(+/x*|y;*|x*y)};{(-/x*|y;*|x*y)};*;{x*|$[0>*y;-y;y]}) /+-*%
     br:{(a;b;c;d):x;(f;g;h):y /all bracket placements over 4 values x and 3 functions y
          fab:f[a;b];fbc:f[b;c];R'(h[g[fab;c];d];h[g[a;fbc];d];h[fab;g[c;d]];h[a;g[fbc;d]];h[a;g[b;f[c;d]]])}
     hf:{+/&\@[~!100;{(99&0|*x)*x[1]=1}@+,/,/(x@+prm 4)br/:\:op@+!3##op;:;1]} /how far
     10/*c@&v=|/v:hf'((!10),'1)c:+cmb[4;10]
P 94 /sides: (a+d;a;a) where d=1 or d=-1.  p=(3a+d)/2, S^2=p(p-a+d)(p-a)^2, a=2b+1
     /S^2=(3b+2)b(b+1)^2 or S^2=(3b+1)b^2(b+1);  (3b+1)^2-3m^2=1 or (3b+2)^2-3m^2=1, solve as pell equations
     l:1+-2!*/9#10;s:0;{l>*x}{s+:P*l>P:(3+6*-3!*x)+0N -1 1@3!*x:(+/2 3*x;+/1 2*x);x}/2 1;s
P 95;&/,/c@&l=|/l:#'c:(a@)\'?*(~~/)(b@')/b:@\2#,a:sg1[n]-!n:1000000
P 96;p,:,3/-3!p:!9 9
     +/{10/3#*(,x)(,/{@[x;y;:;]'(1+!9)^x@&|/p=p@'y}')/&~x:.',/1_"\n"\x}'1_"G"\1:"i/p096_sudoku.txt"
P 97;mod:{(- 10&#x)#x};sqr:{mod mul[x;x]};prd:{mod mul[x;y]}/;pow:{prd@((-1+#e)sqr\x)@&e:|2\y}
     sml mod add[big 1;mul[big 28433;pow[big 2;7830457]]] /28433*(2^7830457)+1 mod 10^10
P 98;p:{,/{x@+c,'|c:cmb[2;#x]}'{1<#x}#x@.={x@<x}'x}
     m:|/#'*'a:p 1_'-1_'","\1:"i/p098_words.txt"
     f:{m/,/(*x)?/:x}
     |/.',/b@&~^(?f'a)?f'b:p@${x*x}@!1+_%*/m#10
P 99;d:10 /precision
     fp:{x:big x;(#x;d#x,&d)}
     fmul:{r:mul[x 1;y 1];$[4<r d;r:car@@[r;d-1;+;1];];(x[0]+y[0]+(#r)-2*d;d#r)}
     fpow:{fmul/((-1+#e){fmul[x;x]}\fp x)@&e:|2\y}
     1+*&r~\:r@*>r:fpow/'.'0:"i/p099_base_exp.txt"
P 100 /k(k-1)/n(n-1)=1/2, x=2n-1, y=2k-1, x^2-2v^2=-1
     -2!1+*|{1000000000001>-2!1+*x}(2(+/(1 1;2 1)*)/)/1 1 /start with x=y=1; while n<=10^12, produce a new solution twice
