#!../k
/ https://github.com/xpqz/dyalogk
/ https://problems.tryapl.org/psets/${YEAR}.html?goto=${PROBLEMNAME}

pi:3.14159265359;abc:_ABC:`c$"A"+!26;sq:{x*x};ave:{(+/x)%#x};gcd:*|(*:)(|!\)/,
ctr:{?[x$"";-2!x-:#y;y]} /center string y in width x, padding with spaces, where ~x>#y
rot:{@[x;(2!)#!#x;|:]}   /flip pairs at odd indices

p131:-1+1_2*!1+                              /P1_Seems_a_Bit_Odd_To_Me
p132:{100*(+/x>64)%#x}                       /P2_Making_The_Grade
p133:+/~0=#'" "\                             /P3_What_Is_In_a_Word
p134:{~(*|0,m)|/0>m:+\-/"()"=\:x}            /P4_Keeping_Things_In_Balance
p135:=                                       /P5_Identity_Crisis
p136:{x[0]-*|x@:>,/x}                        /P6_Home_On_The_Range
p137:{x=_x}_                                 /P7_Float_Your_Boat
p138:{v*/:v:1+!x}                            /P8_Go_Forth_And_Multiply
p139:{(+/'x'y)%x}                            /P9_It_Is_a_Moving_Experience

p141:{~-/*/2#,|x,y,z}                        /P1_It_Is_All_Right
p142:{(2(|1|':)/"0">x)|^"aeiou"?_x}#         /P2_How_Tweet_It_Is (via @chrispsn, @coltim)
p143:1_*+(|+\)\[;!2]@                        /P3_Tell_a_Fib
p143:{-1_*|+x(|+\)\1 1}                      /P3_Tell_a_Fib
p144:" "/(~#:')_" "\                         /P4_Space_The_Final_Frontier
p145:1=#|:\(~"a{"')#_:                       /P5_Mirror_Mirror
p146:{+(!x;.x)}@#'=+/1+!(),                  /P6_Roll_The_Dice
p147:%/gcd\,                                 /P7_Revolutionary_Thinking
p148:%+/*/2#,-/                              /P8_Go_The_Distance
/p149:{(x*x*`sin@2*y*pi%180)%9.8}            /P9_Going_Ballistic
p14X:100*|/1_-1+%':                          /P10_Sales_Are_Up

p151:~/{v@<v:l^(l:_x)^abc}'                  /P1_Nag_A_Ram
p152:|/{y*x+y}\>':(!0),                      /P2_Longest_Streak (via @coltim)
p153:{?(,!2),x@*'<==%/'x}1_+&+|\=1+          /P3_Farey_Tale (via @coltim)
p154:{((#x)#<<x,y)?(#y)#<<y,x}               /P4_PDI_Progessive_Dyadic_Iota
p155:{%(ave sq x)-sq ave x}                  /P5_Hes_so_mean_he_has_no_standard_deviation
p156:&/~=/2#+-2!<'+,/                        /P6_Hey_This_is_My_Space (via @ngn)
p157:~^?/_|:                                 /P7_Just_In_Upper_Case
p158:{@[x;&13=x;:;12.99]}                    /P8_Unlucky_13
p159:{(""/x@0,(|'0N 2#1+!-2+#x),-1+#x)^" "}  /P9_Id_Like_Mine_Scrambled_Please
p15X:{(--2!l+|/l:#'t)$t:`k'x(+':|0,)\1}      /P10_Blaiseing_a_Trail (via @ngn)

p161:{(+/x)%#x}                              /P1_Statistics_Mean
p162:{{(+/x)%#x}x[<x]@-2!(#x)-!2}            /P2_Statistics_Median (via @coltim)
p163:{&d=|/d:#'=x}                           /P3_Statistics_Mode
p164:{(,/x)@<,/(!#)'x}                       /P4_Just_Meshing_Around
p165:&1=#'=:                                 /P5_Youre_Unique_Just_Like_Everyone_Else
p166:{<x!#'x}                                /P6_Shorter_Ones_to_the_Front
p167:(|/~3 5!\:)#                            /P7_3s_and_5s (via @traws)
p168:{.|x@=x<0}                              /P8_Separating_Out_the_Negative (@coltim)
p169:{x\y}                                   /P9_Delimited_Text
p16X:+/*/                                    /P10_Order_Total_Dot_Product

p171:1+2*!:                                  /P1_What_an_Odd_Bunch (via @razetime)
p172:{x+2!x}                                 /P2_Good_Evening
p173:"\"\""/{2!!#x}_"\""\                    /P3_Miss_Quoted (@coltim)
p174:{(pi*r*r:y%2)%360%x}                    /P4_Slices_of_Pies
p175:{~#x^"ACGT"}                            /P5_DNA
p176:{?x'y}                                  /P6_k_mers
p177:+/'"ACGT"=\:                            /P7_Counting_DNA_Nucleotides
p178:>':|\1=                                 /P8_Be_the_First_1 (via @chrispsn)
p179:|=':|"",                                /P9_Double_Trouble (via @coltim)
p17X:{(s;s)#x@!s*s:-_-%#x}                   /P10_Squaring_Off (via @traws)

signsc:`Monkey`Rooster`Dog`Pig`Rat`Ox`Tiger`Rabbit`Dragon`Snake`Horse`Goat
cutoffs:+((1+!12);20 19 21 20 21 21 23 23 10 23 22 22)
signsw:`Capricorn`Aquarius`Pisces`Aries`Taurus`Gemini`Cancer`Leo`Virgo`Libra`Scorpio`Sagittarius`Capricorn
p181:#?|\                                    /P1_Oh_Say_Can_You_See
p182:{(f;x-f:_x)}                            /P2_Number_Splitting
p183:{" "/'+($'!m;.{x#"*"}'m:#'=+/1+!(),x)}  /P3_Rolling_Along
p184:{signsc@12!x+0>x}                       /P4_Whats_Your_Sign
p185:{signsw@({x@<x}cutoffs,,x)?x}           /P5_Whats_Your_Sign_Revisited
p186:{(~*|m)&&/~0>m:+\0^1 -1"<>"?x}          /P6_Whats_Your_Angle
p187:{0^y[(-x)+!#y]}                         /P7_Unconditionally_Shifty
/p8: very APL-specific; skipping             /P8_Making_a_Good_Argument
p189:{*(-/0<-:\(-/x)^0),0}                   /P9_Earlier_Later_or_the_Same
p18X:~/{{=x@<x}x^" "}'                       /P10_Anagrammatically_Correct

km:+,/'|:\2 1*1 -1@!2 2 /knight moves offsets (via @Traws)
tel:ABC!&0 0 3 3 3 3 3 4 3 4
nums:(`c$"0"+!10)!!10
p191:{(0N,x)#y}                              /P1_Chunky_Monkey
p192:"FDCBA"@0 65 70 80 90' /binsearch       /P2_Making_the_Grade (-4 via @coltim)
p193:{+(!t;.t;.0.1*_0.5+1000*t%+/t:0^"ABCDF"##'=x)} /P3_Grade_Distribution (-10, @coltim, @chrispsn)
p194:(&/'0<)#km+\:                           /P4_Knight_Moves
p195:(|/=':" ",)'                            /P5_Doubling_Up
p196:(tel,nums)@                             /P6_Telephone_Names
p197:{ctr[x]'{(x&#y)#y}[x]'y}                /P7_In_the_Center_of_It_All
p198:{+/%+/'{x*x}(*|x)-':x}                  /P8_Going_the_Distance (-4 via @coltim)
p199:{{x|-x}0.5*-/+/rot 1_*':rot (1+#x)#x}   /P9_Area_Code_a_la_Gauss
p19X:{(#;_)[;2!#:';x]}                       /P10_Odd_and_Evens (via @coltim)

p201:{$[x<0;o[x+#y;y];(x;x-#y)#\:y]}         /P1_Lets_Split
p202:{(&~{(~x<128)&~x>191}x)_x}              /P2_Characters
p203:{26/1+ABC?x}                            /P3_Columns
p204:{(~400!x)|(~4!x)&100!x}                 /P4_Take_a_Leap
p205:{(x<y)|:/(x-!x-y),x&y}                  /P5_Integer_Range (-4 via @bubbler)
p206:{,/(#;_)[;x=;y]}                        /P6_Move_To_Front
p207:{|/&/((#2\|/x)#2)\'x}                   /P7_Bits
p208:~|/1_+':-/0<-:\-':10\                   /P8_Zigzag
p209:{$[|/m:<':x;&/(m?1)_m;1]}               /P9_Rise_and_Fall
p20X:`k@ /very APL-specific                  /P10_Stacking_It_Up

p211:{100*(+/|/"GC"=\:x)%#x}                 /P11
p212:?                                       /P12
p213:{y@&'~x!\:y}                            /P13
p214:{(pi*r*r:x%2)-s*s:x%%2}                 /P14
p215:{a,_x%a:![;x](-1+)/_%x}                 /P15
p216:{(2!+/p"B")&~(<,/(p:=x)"KR")1}          /P16
p217:{1=#=+/'x,(+x),(,/'x*/:(i;|i:=#x))^\:0} /P17
p218:{x|-x}@-/0 24 60/'-3#'(&3),/:           /P18
p219:|/#'{(&~=':x)_x}@1_-/0<-:\-':           /P19
p21X:{(-x)$y}                                /P110


t:{[q;f;a;e] `1:`k$[q[e;r:f a];.;(`fail;f;q;a;e;r)]} /assert
M:t[~];E:t[=];A:t{1e-6>x|-x-:y};D:t{~/_1000000*(x;y)} /A:approx equal,D:approx float deep-match

M[p131].'((10;1 3 5 7 9 11 13 15 17 19);(1;,1);(0;!0));
E[p132].'((25 90 100 64 65;60);(,50;0);(80 90 100;100);(!0;0n)); /Dyalog wants 100% instead of 0n, but that makes no sense
E[p133].'(("Testing one, two, three";4);("";0);(" this vector has extra blanks ";5));
E[p134].'(("((2×3)+4)";1);("";1);("hello world!";1);(")(2×3)+4(";0);("(()";0);(")";0));
/skipping p135, as =: is a primitive k function
E[p136].'((19 -3 7.6 22;25);(,101;0);(2 3#10 20 30 40 50 60;50);(!0;0));
M[p137].'((14.2 9 -3 3.1 0 -1.1;14.2 3.1 -1.1);(1 3 5;!0);(3.1415;,3.1415));
M[p138].'((5;5 5#1 2 3 4 5 2 4 6 8 10 3 6 9 12 15 4 8 12 16 20 5 10 15 20 25);(1;1 1#1);(0;0 0#0));
sa:200 300 2700 3400 100 2000 400 2100 3500 3000 4700 4300 /sales
E[p139 .].'(((2;sa);250 1500 3050 1750 1050 1200 1250 2800 3250 3850 4500);((10;sa);1770 2220 2620);((1;sa);sa));
E[p141 .].'((3 4 5;1);(2 3 4;0));
M[p142].'(("if you can read this, it worked!";"if yu cn rd ths, it wrkd!");("APL is REALLY cool";"APL is RLLY cl"));
M[p142;,"a";,"a"] /dyalog wants it to work on raw scalars
M[p143].'((10;1 1 2 3 5 8 13 21 34 55);(1;,1);(0;!0));
M[p144].'((" this is a test ";"this is a test");("";"");("hello world!";"hello world!");("    ";""));
E[p145].'(("a man, a plan, a canal, panama!";1);("";1);("a";1);("APL";0));
M[p146].'((6 6;11 2#2 1 3 2 4 3 5 4 6 5 7 6 8 5 9 4 10 3 11 2 12 1);(6 4;9 2#2 1 3 2 4 3 5 4 6 4 7 4 8 3 9 2 10 1)
          (3;3 2#1 1 2 1 3 1));
E[p147 .].'((10 10;1);(10 5;2);(5 7;5));
E[p148].'((2 5;3);((2 2;5 6);5);(!0;0);((2 2 3 4;3 7 10 9);10));
/A[p149[100];45;1020.408163];A[p149[0];45;0];A[p149[100];90;0.0]
A[p14X].'((80 100 120 140;25);(3#123;0);(101 102 114 117 101 110 102 111 118 115 124 122;11.76470588);(200 180 160 140 120;-10));
E[p151].'((("anagram";"Nag A Ram");1);(("Dyalog APL";"Dog Pay All");1);(("";"  !#!");1);(("abcde";"zyxwvu");0));
E[p152].'((1 2 3 4 5 6 7 8 9;8);(1;0);(9 8 7 6 5 4;0);(1 5 3 4 2 6 7 8;3));
M[p153].'((0;,0 1);(1;(0 1;1 1));(5;(0 1;1 5;1 4;1 3;2 5;1 2;3 5;2 3;3 4;4 5;1 1)));
M[p154 .].'((("DYALOG APL";"AAALLLB");2 7 0N 3 9 0N 0N);(("";"test");4#0N);(("test";!0);!0));
A[p155].'((1 2 3 4 5;1.414213562);(10 10#1+!100;28.86607005));
E[p156].'((((1 1;5 5);(3 3;7 7));1);(((1 1;5 5);(5 5;1 1));1);(((1 1;3 3);(4 4;7 7));0);(((1.1 1.1;5.5 5.5);(3.3 3.3;4.4 4.4));1));
M[p157].'(($`dyalog`APL;001100b);($`bramley`HAMPSHIRE;0111010b));
M[p158].'((,13;,12.99);(10 11 12 13 14;(10;11;12;12.99;14));(13 130 13.13 1300;(12.99;130.0;13.13;1300.0)));
M[p159].'$(`argument`agrmunet;`this`tihs;`is`is;`awesome`aewosme);
M[p15X;10]("                 1"
           "                1 1"
           "               1 2 1"
           "              1 3 3 1"
           "             1 4 6 4 1"
           "           1 5 10 10 5 1"
           "         1 6 15 20 15 6 1"
           "        1 7 21 35 35 21 7 1"
           "      1 8 28 56 70 56 28 8 1"
           "    1 9 36 84 126 126 84 36 9 1"
           "1 10 45 120 210 252 210 120 45 10 1")
A[p161].'((1 2 3 4 5 6;3.5);(!0;0n);17 17;(5 3#1+!15;7 8 9.0)); /dyalog wants 0 instead of 0n, which makes no sense
E[p162].'((1+!9;5);(1 8 2 7 3 6 4 5;4.5);(!0;0.0);(,7;7));
M[p163].'((2 1 4 3 2 5 1 2;,2);(!0;,!0);(1 2 3 4 1 2;1 2)); /result ,!0 is dubious
M[p164].'($(`MENS`EKES;`MEEKNESS);$(`Dyalog`APL;`DAyPaLlog);$(`APL`Dyalog;`ADPyLalog)
 ((1 3 5 7;2 4 6 8);1 2 3 4 5 6 7 8);$(``Hello;`Hello));
M[p165].'((1+!5;1+!5);(1 2 3 4 5 4 3 2 1;,5);("hello world";"he wrd"));
M[p166].'($(`one`two`three`four`five`six;`one`two`six`four`five`three);((2 4 3;4 5;,1;7 3);(,1;4 5;7 3;2 4 3));(!0;!0)
 (("one";,2;"three";," ";"four";5 6 7 8);(,2;," ";"one";"four";5 6 7 8;"three"))); /fudge; soln incorrect for empty vectors
M[p167].'((1+!10;3 5 6 9 10);(!0;!0));
M[p168].'((0 1 -2 3 -4 -5 6 7 8 -9 10;(-2 -4 -5 -9;0 1 3 6 7 8 10))
          (1 2 3 4 5;,1 2 3 4 5) /this isn't the behaviour Dyalog wants, but unsure how that maps to k's array model
          (!0;()));              /same here
/skipping p169 as split is a built-in k verb
A[p16X].'(((5 0 2;2.99 4.99 1.99);18.93);((0 0 0;2.99 4.99 1.99);0));
M[p171].'((5;1 3 5 7 9);(1;,1);(0;!0));
M[p172].'((1 2 3 4 5;2 2 4 4 6);(!0;!0);(4 4#1+!16;(2 2 4 4;6 6 8 8;10 10 12 12;14 14 16 16)));
M[p173].'(("this \"is\" a test";"this \"\" a test");("this is a test";"this is a test")
          ("this \"is\" a \"test\"";"this \"\" a \"\"");("";""));
A[p174 .].'((60 12;18.84955592);(0 12;0);(60 0;0);((60;9 12 15);10.60287521 18.84955592 29.45243113)
 ((60 90 120;12);18.84955592 28.27433388 37.69911184);((60 90 120;9 12 15);10.60287521 28.27433388 58.90486225));
E[p175].'(("ATGCTTCAGAAAGGTCTTACG";1);("Dyalog";0);("";1);(,"T";1));
M[p176 .].'(((4;"ATCGAAGGTCGT");$`ATCG`TCGA`CGAA`GAAG`AAGG`AGGT`GGTC`GTCG`TCGT);((4;"AC");()));
M[p177].'(("AGCTTTTCATTCTGACTGCTGTCTTTAAAAAAAGAGTGTCTGATAGCAG";14 8 10 17);("CCAAATGGGG";3 2 4 1);("";&4);(,"G";0010b));
M[p178].'((0101001b;0100000b);(!0;!0);(0000b;0000b));
M[p179].'(("bookkeeper";0101010000b);("";"");("aaaaaa";111110b);("d";,0)); /"" as result arguably dogdy?
M[p17X].'((1 2 3 4;2 2#1 2 3 4);(1 2 3 4 5;3 3#1 2 3 4 5 0N 0N 0N 0N);("Dyalog APL";4 4#"Dyalog APL      "));
E[p181].'((5 5 2 10 3 15 10;3);(|5 5 2 10 3 15 10;2);(!0;0);(,10;1));
A[p182].'((1.234;1 0.234);(12;12 0);(0;0 0));
M[p183].'((6 6;"|"\"2 *|3 **|4 ***|5 ****|6 *****|7 ******|8 *****|9 ****|10 ***|11 **|12 *")
 (6;"|"\"1 *|2 *|3 *|4 *|5 *|6 *")
 (5 3 4;"|"\"3 *|4 ***|5 ******|6 *********|7 ***********|8 ***********|9 *********|10 ******|11 ***|12 *")
 (0;())); /Dyalog expects ("0 *") which is dubious
E[p184].'(2018,`Dog;1564,`Rat;-551,`Dog);
E[p185].'((2 23;`Pisces);(10 31;`Scorpio));
M[p186].'(("<name><first>Drake</first><last>Mallard</last></name>";1);("<math><relation>2<3</relation></math>";0)
          ("";0);(">stuff<>/stuff<";0)); /dyalog wants 1 for input "" -- not sure
M[p187 .].'(((3;10111011b);00010111b);((-3;10111011b);11011000b));
/skipping p188
E[p189].'(((ts;2018 4 1 16 45 12 800);-1);((ts;2018 4 1 12 34 56 789);0);((ts:2018 4 1 12 34 56 789;2017 4 1 12 34 56 789);1));
E[p18X].'((("ALBERT EINSTEIN";"TEN ELITE BRAINS");1);((,"";,"");1);((,"d";,"d");1);($`mesas`seam;0);($`apple`lapel;0));
M[p191 .].'(((3;1+!9);(1 2 3;4 5 6;7 8 9));((3;1+!11);(1 2 3;4 5 6;7 8 9;10 11));((10;"Dyalog");,"Dyalog")
 ((2;$`the`cat`in`the`hat`sat`pat);$(`the`cat;`in`the;`hat`sat;,`pat))
 (4 5;,,5)); /dyalog expects ,,5 but this seems inconsistent, as every other example returns vector of vectors
M[p192].'((0 64 65 69 70 79 80 89 90 100;"FFDDCCBBAA");(!0;());(2 3#71 82 81 82 84 59;$`CBB`BBF));
/floating point CT is too annoying at depth
tmp:+p193@{9 3 8 4 7}#"DABFC";M[::;tmp@0;"ABCDF"];M[::;tmp@1;3 8 7 9 4];A[::;tmp@2;9.7 25.8 22.6 29.0 12.9]
M[p194].'((5 4;(7 5;7 3;3 5;3 3;6 6;4 6;6 2;4 2));(1 1;(3 2;2 3)));
M[p195].'(($`I`feed`the`bookkeeper;0 1 0 1);(,"I";,0);(,"feed";,1);($`MY`LLAMAS`HAVE`BEEN`GOOD;01011b));
M[p196].'(("IAMYY4U";4 2 6 9 9 4 8);("";!0);("UR2CUTE";8 7 2 2 8 8 3));
M[p197 .;10,,$`APL`Problem`Solving`Competition;("   APL    ";" Problem  ";" Solving  ";"Competitio")]
A[p198].'(((1 -1;1 3);8);((1 1;1 2;2 2;2 1);4);(5 5;0);((1 1;3 3);5.656854249));
A[p199].'(((2 4;3 -8;1 2);7);(,1 1;0);((1 1;2 2);0));
M[p19X].'(($`the`plan`is`great;$(`the`great;`plan`is));($`all`odd;($`all`odd;()));($`only`even`here;(();$`only`even`here)));
M[p201 .].'(((9;"SplittingHairs");$`Splitting`Hairs);((-3;"DyalogAPL");$`Dyalog`APL);((10;1+!10);(1+!10;!0))
 ((1;$`works`with`words`also);$(,`works;`with`words`also)));
M[p202].'((68 194 165 226 141 186 226 140 138 240 159 148 178 57;(,68;194 165;226 141 186;226 140 138;240 159 148 178;,57))
 (68 121 97 108 111 103;+,68 121 97 108 111 103) /dyalog expects 68 121 97 108 111 103, but this seems inconsistent
 (!0;()));
E[p203].'(("A";1);("APL";1104));
M[p204].'(2020 1;(1901+10 10#!100;10 10#100#0001b));
M[p205 .].'((3 10;3 4 5 6 7 8 9 10);(4 -3;4 3 2 1 0 -1 -2 -3);(42 42;,42));
M[p206 .].'(((3;1 2 3 4 1 3 1 4 5);3 3 1 2 4 1 1 4 5);((3;,1);,1);((42;!0);!0));
M[p207].'((2 7;1);(4 11;0);(3 11;1);(4 0;0));
E[p208].'(123 0;31115 0;3141514131415 1); /A[p208;132;1] /FAIL FIX ME
E[p209].'((1 3 3 4 5 2 1;1);(,42;1);(1 3 2 4;0);(23 23 23;1)); /A[p209;!0;1] /dubious
/skipping p20X; too APL-specific
A[p211].'(("GCGCGCGCCCGGGGCCG";100);("ACGTACGTACGTACGT";50);("ACGT"@&10 12 16 10;58.33333333));
/skipping p212, as `?` is a k primitive
/M[p212["DYALOG"];"APL";2 0N 3]
/M[p212[5 5#ABC];("UVWXY";"FGHIJ";"XYZZY");4 1 0N]
M[p213 .].'(((2 4 7 3 9;5 7 8 1 12 10 20 16 11 4 2 15 3 18 14 19 13 9 17 6);(8 12 10 20 16 4 2 18 14 6;8 12 20 16 4;7 14;12 15 3 18 9 6;18 9))
 ((,3;1+!10);,3 6 9);((6 7;,42);(,42;,42));((2 3 5;!0);(!0;!0;!0));((!0;1+!10);()));
D[p214].'((2*1+!5;1.141592654 4.566370614 10.27433388 18.26548246 28.53981634)
 ((%2)*3 3#1+!9;3 3#0.5707963268 2.283185307 5.137166941 9.132741229 14.26990817 20.54866776 27.96902001 36.53096491 46.23450247));
M[p215].'((12;3 4);(16;4 4)),+(1+!19;(1 1;1 2;1 3;2 2;1 5;2 3;1 7;2 4;3 3;2 5;1 11;3 4;1 13;2 7;3 5;4 4;1 17;3 6;1 19));
M[p215].'((999999;999 1001);(1000000;1000 1000));
M[p216].'(("RNBQKBNR";1);("BBNRKNRQ";1);("RBBNQNRK";0);("BRBKRNQN";0));
M[p217].'((1 1#42;1);(3 3#4 9 2 3 5 7 8 1 6;1);(2 2#1 2 3 4;0));
E[p218].'(((2 30;5 15);165);((5 15;2 30);165);((1 0 0;,0);1440));
E[p219].'((1 2 3 5 5 5 6 4 3;3);(1 2 3 4 4 4 4 4 5 4 3;4);(1 2;1));
M[p21X .].'(((6;">");"     >")
            ((8;("K";"E";"Iverson"));("       K";"       E";" Iverson"))
            ((8;("Longer Phrase";"APL";"Parade"));("r Phrase";"     APL";"  Parade")));
`1:,"\n"
