#!../k
/ https://github.com/xpqz/dyalogk

/constants
pi:3.14159265359
abc:`c$"a"+!26 /lower-case letters
ABC:`c$"A"+!26 /upper-case letters
q:"\""

/helpers
sq:{x*x}
ave:{(+/x)%#x}
gcd:*|(*:)(|!\)/,
ctr:{?[x$"";-2!x-:#y;y]} /center string y in width x, padding with spaces, where ~x>#y
rot:{@[x;(2!)#!#x;|:]}   /flip pairs at odd indices

/ https://problems.tryapl.org/psets/2013.html
p131:-1+1_2*!1+                               / ?goto=P1_Seems_a_Bit_Odd_To_Me
p132:{100*(+/x>64)%#x}                        / ?goto=P2_Making_The_Grade
p133:+/~0=#'" "\                              / ?goto=P3_What_Is_In_a_Word
p134:{(0=#x)|(~*|m)&&/~0>m:+\0^1 -1"()"?x}    / ?goto=P4_Keeping_Things_In_Balance
p135:=                                        / ?goto=P5_Identity_Crisis
p136:{$[x~!0;0;{x|-x}(&/d)-|/d:,/x]}          / ?goto=P6_Home_On_The_Range
p137:{x=_x}_                                  / ?goto=P7_Float_Your_Boat
p138:{v*/:v:1+!x}                             / ?goto=P8_Go_Forth_And_Multiply
p139:{(+/'x'y)%x}                             / ?goto=P9_It_Is_a_Moving_Experience

/ https://problems.tryapl.org/psets/2014.html
p141:{~-/*/2#,|x,y,z}                         / ?goto=P1_It_Is_All_Right
p142:{(2(|1|':)/"0">x)|^"aeiou"?_x}#          / ?goto=P2_How_Tweet_It_Is (via @chrispsn, @coltim)
p143:1_*+(|+\)\[;!2]@                         / ?goto=P3_Tell_a_Fib
p143:{-1_*|+x(|+\)\1 1}                       / ?goto=P3_Tell_a_Fib
p144:" "/(~#:')_" "\                          / ?goto=P4_Space_The_Final_Frontier
p145:1=#|:\(~"a{"')#_:                        / ?goto=P5_Mirror_Mirror
p146:{+(!x;.x)}@#'=+/1+!(),                   / ?goto=P6_Roll_The_Dice
p147:%/gcd\,                                  / ?goto=P7_Revolutionary_Thinking
p148:%+/*/2#,-/                               / ?goto=P8_Go_The_Distance
/p149:{(x*x*`sin@2*y*pi%180)%9.8}             / ?goto=P9_Going_Ballistic
p1410:100*|/1_-1+%':                          / ?goto=P10_Sales_Are_Up

/ https://problems.tryapl.org/psets/2015.html
p151:~/{v@<v:l^(l:_x)^abc}'                   / ?goto=P1_Nag_A_Ram
p152:|/{y*x+y}\>':(!0),                       / ?goto=P2_Longest_Streak (via @coltim)
p153:{?(,!2),x@*'<==%/'x}1_+&+|\=1+           / ?goto=P3_Farey_Tale (via @coltim)
p154:{((#x)#<<x,y)?(#y)#<<y,x}                / ?goto=P4_PDI_Progessive_Dyadic_Iota
p155:{%(ave sq x)-sq ave x}                   / ?goto=P5_Hes_so_mean_he_has_no_standard_deviation
p156:&/~=/2#+-2!<'+,/                         / ?goto=P6_Hey_This_is_My_Space (via @ngn)
p157:~^?/_|:                                  / ?goto=P7_Just_In_Upper_Case
p158:{@[x;&13=x;:;12.99]}                     / ?goto=P8_Unlucky_13
p159:{(""/x@0,(|'0N 2#1+!-2+#x),-1+#x)^" "}   / ?goto=P9_Id_Like_Mine_Scrambled_Please
p1510:{(--2!l+|/l:#'t)$t:`k'x(+':|0,)\1}      / ?goto=P10_Blaiseing_a_Trail (via @ngn)

/ https://problems.tryapl.org/psets/2016.html
p161:{(+/x)%#x}                               / ?goto=P1_Statistics_Mean
p162:{{(+/x)%#x}x[<x]@-2!(#x)-!2}             / ?goto=P2_Statistics_Median (via @coltim)
p163:{&d=|/d:#'=x}                            / ?goto=P3_Statistics_Mode
p164:{(,/x)@<,/(!#)'x}                        / ?goto=P4_Just_Meshing_Around
p165:&1=#'=:                                  / ?goto=P5_Youre_Unique_Just_Like_Everyone_Else
p166:{<x!#'x}                                 / ?goto=P6_Shorter_Ones_to_the_Front
p167:(|/~3 5!\:)#                             / ?goto=P7_3s_and_5s (via @traws)
p168:{.|x@=x<0}                               / ?goto=P8_Separating_Out_the_Negative (@coltim)
p169:{x\y}                                    / ?goto=P9_Delimited_Text
p1610:+/*/                                    / ?goto=P10_Order_Total_Dot_Product

/ https://problems.tryapl.org/psets/2017.html
p171:1+2*!:                                   / ?goto=P1_What_an_Odd_Bunch (via @razetime)
p172:{x+2!x}                                  / ?goto=P2_Good_Evening
p173:(q;q)/{2!!#x}_q\                         / ?goto=P3_Miss_Quoted (@coltim)
p174:{(pi*r*r:y%2.0)%360.0%x}                 / ?goto=P4_Slices_of_Pies
p175:{~#x^"ACGT"}                             / ?goto=P5_DNA
p176:{?x'y}                                   / ?goto=P6_k_mers
p177:+/'"ACGT"=\:                             / ?goto=P7_Counting_DNA_Nucleotides
p178:{(!#x)=x?1}                              / ?goto=P8_Be_the_First_1 (via @chrispsn)
p179:|=':|"",                                 / ?goto=P9_Double_Trouble (via @coltim)
p1710:{(s;s)#x@!s*s:-_-%#x}                   / ?goto=P10_Squaring_Off (via @traws)

/ https://problems.tryapl.org/psets/2018.html
signsc:`Monkey`Rooster`Dog`Pig`Rat`Ox`Tiger`Rabbit`Dragon`Snake`Horse`Goat
cutoffs:+((1+!12);20 19 21 20 21 21 23 23 10 23 22 22)
signsw:`Capricorn`Aquarius`Pisces`Aries`Taurus`Gemini`Cancer`Leo`Virgo`Libra`Scorpio`Sagittarius`Capricorn
p181:#?|\                                            / ?goto=P1_Oh_Say_Can_You_See
p182:{(f;x-f:_x)}                                    / ?goto=P2_Number_Splitting
p183:{" "/'+($'!m;.{x#"*"}'m:#'=+/1+!(),x)}          / ?goto=P3_Rolling_Along
p184:{signsc@12!x+0>x}                               / ?goto=P4_Whats_Your_Sign
p185:{signsw@({x@<x}cutoffs,,x)?x}                   / ?goto=P5_Whats_Your_Sign_Revisited
p186:{(~*|m)&&/~0>m:+\0^1 -1"<>"?x}                  / ?goto=P6_Whats_Your_Angle
p187:{0^y[(-x)+!#y]}                                 / ?goto=P7_Unconditionally_Shifty
/p8: very APL-specific; skipping                     / ?goto=P8_Making_a_Good_Argument
p189:{*(-/0<-:\(-/x)^0),0}                           / ?goto=P9_Earlier_Later_or_the_Same
p1810:~/{{=x@<x}x^" "}'                              / ?goto=P10_Anagrammatically_Correct

/ https://problems.tryapl.org/psets/2019.html
km:+,/'|:\2 1*1 -1@!2 2 / knight moves offsets (via @Traws)
tel:ABC!({3 3 3 3 3 4 3 4}#2_!10)
nums:(`c$"0"+!10)!(!10)
p191:{(0N,x)#y}                                      / ?goto=P1_Chunky_Monkey
p192:"FDCBA"@0 65 70 80 90'          / binsearch     / ?goto=P2_Making_the_Grade (-4 via @coltim)
p193:{+(!t;.t;.0.1*_0.5+1000*t%+/t:0^"ABCDF"##'=x)}  / ?goto=P3_Grade_Distribution (-10, @coltim, @chrispsn)
p194:(&/'0<)#km+\:                                   / ?goto=P4_Knight_Moves
p195:(|/=':" ",)'                                    / ?goto=P5_Doubling_Up
p196:(tel,nums)@                                     / ?goto=P6_Telephone_Names
p197:{ctr[x]'{(x&#y)#y}[x]'y}                        / ?goto=P7_In_the_Center_of_It_All
p198:{+/%+/'{x*x}(*|x)-':x}                          / ?goto=P8_Going_the_Distance (-4 via @coltim)
p199:{{x|-x}0.5*-/+/rot 1_*':rot (1+#x)#x}           / ?goto=P9_Area_Code_a_la_Gauss
p1910:{(#;_)[;2!#:';x]}                              / ?goto=P10_Odd_and_Evens (via @coltim)

/ https://problems.tryapl.org/psets/2020.html
p201:{$[x<0;o[x+#y;y];(x;x-#y)#\:y]}                 / ?goto=P1_Lets_Split
p202:{(&~{(~x<128)&~x>191}x)_x}                      / ?goto=P2_Characters
p203:{26/1+ABC?x}                                    / ?goto=P3_Columns
p204:{(~400!x)|(~4!x)&100!x}                         / ?goto=P4_Take_a_Leap
p205:{(x<y)|:/(x-!x-y),x&y}                          / ?goto=P5_Integer_Range (-4 via @bubbler)
p206:{,/(#;_)[;x=;y]}                                / ?goto=P6_Move_To_Front
p207:{|/&/((#2\|/x)#2)\'x}                           / ?goto=P7_Bits
p208:~|/1_+':-/0<-:\-':10\                           / ?goto=P8_Zigzag
p209:{$[|/m:<':x;&/(m?1)_m;1]}                       / ?goto=P9_Rise_and_Fall
p2010:`k@    / very APL-specific                     / ?goto=P10_Stacking_It_Up

/ https://www.dyalogaplcompetition.com/?goto=P1Intro
p211:{100*(+/|/"GC"=\:x)%#x}                         / ?goto=P11
p212:?                                               / ?goto=P12
p213:{y@&'~x!\:y}                                    / ?goto=P13
p214:{(pi*r*r:x%2)-s*s:x%%2}                         / ?goto=P14
p215:{a,_x%a:![;x](-1+)/_%x}                         / ?goto=P15
p216:{(2!+/p"B")&~(<,/(p:=x)"KR")1}                  / ?goto=P16
p217:{1=#=+/'x,(+x),(,/'x*/:(i;|i:=#x))^\:0}         / ?goto=P17
p218:{x|-x}@-/0 24 60/'-3#'(&3),/:                   / ?goto=P18
p219:|/#'{(&~=':x)_x}@1_-/0<-:\-':                   / ?goto=P19
p2110:{(-x)$y}                                       / ?goto=P110

(≈):{1.0e-6>{x|-x}x-y}  / approx equal
(∆):{(_1000000*x)~_1000000*y} / approx float deep-match

assert:{[cmp;f;a;e]$[cmp[e;r:f a];;(`fail;cmp;a;e;r)]}

/ https://problems.tryapl.org/psets/2013.html

assert[~][p131;10;1 3 5 7 9 11 13 15 17 19]
assert[~][p131;1;,1]
assert[~][p131;0;!0]

assert[=][p132;25 90 100 64 65;60]
assert[=][p132;,50;0]
assert[=][p132;80 90 100;100]
assert[~][p132;!0;0n]               / Dyalog wants 100%, but that makes no sense

assert[=][p133;"Testing one, two, three";4]
assert[=][p133;"";0]
assert[=][p133;" this vector has extra blanks ";5]

assert[=][p134;"((2×3)+4)";1]
assert[=][p134;"";1]
assert[=][p134;"hello world!";1]
assert[=][p134;")(2×3)+4(";0]
assert[=][p134;"(()";0]
assert[=][p134;")";0]

/ skipping p135, as =: is a primitive k function

assert[=][p136;19 -3 7.6 22;25]
assert[=][p136;,101;0]
assert[=][p136;2 3#10 20 30 40 50 60;50]
assert[=][p136;!0;0]  / dubious

assert[~][p137;14.2 9 -3 3.1 0 -1.1;14.2 3.1 -1.1]
assert[~][p137;1 3 5;!0]
assert[~][p137;3.1415;,3.1415]

assert[~][p138;5;5 5#1 2 3 4 5 2 4 6 8 10 3 6 9 12 15 4 8 12 16 20 5 10 15 20 25]
assert[~][p138;1;1 1#1]
assert[~][p138;0;0 0#0]

sales:200 300 2700 3400 100 2000 400 2100 3500 3000 4700 4300
assert[=][p139[2];sales;250 1500 3050 1750 1050 1200 1250 2800 3250 3850 4500]
assert[=][p139[10];sales;1770 2220 2620]
assert[=][p139[1];sales;sales]

/ https://problems.tryapl.org/psets/2014.html

assert[=][p141[3;4];5;1]
assert[=][p141[2;3];4;0]

assert[~][p142;"if you can read this, it worked!";"if yu cn rd ths, it wrkd!"]
assert[~][p142;"APL is REALLY cool";"APL is RLLY cl"]
assert[~][p142;,"a";,"a"] / dyalog wants it to work on raw scalars

assert[~][p143;10;1 1 2 3 5 8 13 21 34 55]
assert[~][p143;1;,1]
assert[~][p143;0;!0]

assert[~][p144;" this is a test ";"this is a test"]
assert[~][p144;"";""]
assert[~][p144;"hello world!";"hello world!"]
assert[~][p144;"    ";""]

assert[=][p145;"a man, a plan, a canal, panama!";1]
assert[=][p145;"";1]
assert[=][p145;"a";1]
assert[=][p145;"APL";0]

assert[~][p146;6 6;11 2#2 1 3 2 4 3 5 4 6 5 7 6 8 5 9 4 10 3 11 2 12 1]
assert[~][p146;6 4;9 2#2 1 3 2 4 3 5 4 6 4 7 4 8 3 9 2 10 1]
assert[~][p146;3;3 2#1 1 2 1 3 1]

assert[=][p147[10];10;1]
assert[=][p147[10];5;2]
assert[=][p147[5];7;5]

assert[=][p148;2 5;3]
assert[=][p148;(2 2;5 6);5]
assert[=][p148;!0;0]
assert[=][p148;(2 2 3 4;3 7 10 9);10]

/assert[≈][p149[100];45;1020.408163]
/assert[=][p149[0];45;0]
/assert[≈][p149[100];90;0.0]

assert[≈][p1410;80 100 120 140;25]
assert[≈][p1410;123 123 123;0]
assert[≈][p1410;101 102 114 117 101 110 102 111 118 115 124 122;11.76470588]
assert[≈][p1410;200 180 160 140 120;-10]

/ https://problems.tryapl.org/psets/2015.html

assert[=][p151;("anagram";"Nag A Ram");1]
assert[=][p151;("Dyalog APL";"Dog Pay All");1]
assert[=][p151;("";"  !#!");1]
assert[=][p151;("abcde";"zyxwvu");0]

assert[=][p152;1 2 3 4 5 6 7 8 9;8]
assert[=][p152;1;0]
assert[=][p152;9 8 7 6 5 4;0]
assert[=][p152;1 5 3 4 2 6 7 8;3]

assert[~][p153;0;,0 1]
assert[~][p153;1;(0 1;1 1)]
assert[~][p153;5;(0 1;1 5;1 4;1 3;2 5;1 2;3 5;2 3;3 4;4 5;1 1)]

assert[~][p154["DYALOG APL"];"AAALLLB";2 7 0N 3 9 0N 0N]
assert[~][p154[""];"test";0N 0N 0N 0N]
assert[~][p154["test"];!0;!0]

assert[≈][p155;1 2 3 4 5;1.414213562]
assert[≈][p155;10 10#1+!100;28.86607005]

assert[=][p156;((1 1;5 5);(3 3;7 7));1]
assert[=][p156;((1 1;5 5);(5 5;1 1));1]
assert[=][p156;((1 1;3 3);(4 4;7 7));0]
assert[=][p156;((1.1 1.1;5.5 5.5);(3.3 3.3;4.4 4.4));1]

assert[~][p157;("dyalog";"APL");0 0 1 1 0 0]
assert[~][p157;("bramley";"HAMPSHIRE");0 1 1 1 0 1 0]

assert[~][p158;,13;,12.99]
assert[~][p158;10 11 12 13 14;(10;11;12;12.99;14)]
assert[~][p158;13 130 13.13 1300;(12.99;130.0;13.13;1300.0)]

assert[~][p159;"argument";"agrmunet"]
assert[~][{x};p159'("this";"is";"awesome");("tihs";"is";"aewosme")]

tmp:"                 1                1 1               1 2 1              1 3 3 1             1 4 6 4 1           1 5 10 10 5 1         1 6 15 20 15 6 1        1 7 21 35 35 21 7 1      1 8 28 56 70 56 28 8 1    1 9 36 84 126 126 84 36 9 11 10 45 120 210 252 210 120 45 10 1"
assert[~][{x};,/p1510@10;tmp]

/ https://problems.tryapl.org/psets/2016.html
assert[≈][p161;1 2 3 4 5 6;3.5]
assert[~][p161;!0;0n] / dyalog wants 0, which makes no sense
assert[≈][p161;17;17]
assert[~][p161;5 3#1+!15;7.0 8.0 9.0]

assert[=][p162;1+!9;5]
assert[=][p162;1 8 2 7 3 6 4 5;4.5]
assert[=][p162;!0;0.0]
assert[=][p162;,7;7]

assert[~][p163;2 1 4 3 2 5 1 2;,2]
assert[~][p163;!0;0#`] / ???
assert[~][p163;1 2 3 4 1 2;1 2]

assert[~][p164;("MENS";"EKES");"MEEKNESS"]
assert[~][p164;("Dyalog";"APL");"DAyPaLlog"]
assert[~][p164;("APL";"Dyalog");"ADPyLalog"]
assert[~][p164;(1 3 5 7;2 4 6 8);1 2 3 4 5 6 7 8]
assert[~][p164;("";"Hello");"Hello"]

assert[~][p165;1+!5;1+!5]
assert[~][p165;1 2 3 4 5 4 3 2 1;,5]
assert[~][p165;"hello world";"he wrd"]

assert[~][p166;("one";"two";"three";"four";"five";"six");("one";"two";"six";"four";"five";"three")]
assert[~][p166;(2 4 3;4 5;,1;7 3);(,1;4 5;7 3;2 4 3)]
assert[~][p166;!0;!0]
assert[~][p166;("one";,2;"three";," ";"four";5 6 7 8);(,2;," ";"one";"four";5 6 7 8;"three")] / fudge; soln incorrect for empty vectors

assert[~][p167;1+!10;3 5 6 9 10]
assert[~][p167;!0;!0]

assert[~][p168;0 1 -2 3 -4 -5 6 7 8 -9 10;(-2 -4 -5 -9;0 1 3 6 7 8 10)]
assert[~][p168;1 2 3 4 5;,1 2 3 4 5]  / this isn't the behaviour Dyalog wants, but unsure how that maps to k's array model
assert[~][p168;!0;()]                 / same here

/ skipping p169 as split is a built-in k verb

assert[≈][p1610;(5 0 2;2.99 4.99 1.99);18.93]
assert[≈][p1610;(0 0 0;2.99 4.99 1.99);0]

/ https://problems.tryapl.org/psets/2017.html

assert[~][p171;5;1 3 5 7 9]
assert[~][p171;1;,1]
assert[~][p171;0;!0]

assert[~][p172;1 2 3 4 5;2 2 4 4 6]
assert[~][p172;!0;!0]
assert[~][p172;4 4#1+!16;4 4#2 2 4 4 6 6 8 8 10 10 12 12 14 14 16 16]

assert[~][p173;"this \"is\" a test";"this \"\" a test"]
assert[~][p173;"this is a test";"this is a test"]
assert[~][p173;"this \"is\" a \"test\"";"this \"\" a \"\""]
assert[~][p173;"";""]

assert[≈][p174[60];12;18.84955592]
assert[≈][p174[0];12;0]
assert[≈][p174[60];0;0]
assert[≈][p174[60];9 12 15;10.60287521 18.84955592 29.45243113]
assert[≈][p174[60 90 120];12;18.84955592 28.27433388 37.69911184]
assert[≈][p174[60 90 120];9 12 15;10.60287521 28.27433388 58.90486225]

assert[=][p175;"ATGCTTCAGAAAGGTCTTACG";1]
assert[=][p175;"Dyalog";0]
assert[=][p175;"";1]
assert[=][p175;,"T";1]

assert[~][p176[4];"ATCGAAGGTCGT";("ATCG";"TCGA";"CGAA";"GAAG";"AAGG";"AGGT";"GGTC";"GTCG";"TCGT")]
assert[~][p176[4];"AC";()]

assert[~][p177;"AGCTTTTCATTCTGACTGCTGTCTTTAAAAAAAGAGTGTCTGATAGCAG";14 8 10 17]
assert[~][p177;"CCAAATGGGG";3 2 4 1]
assert[~][p177;"";0 0 0 0]
assert[~][p177;,"G";0 0 1 0]

assert[~][p178;0 1 0 1 0 0 1;0 1 0 0 0 0 0]
assert[~][p178;!0;!0]
assert[~][p178;0 0 0 0;0 0 0 0]

assert[~][p179;"bookkeeper";0 1 0 1 0 1 0 0 0 0]
assert[~][p179;"";""]  / arguably dogdy?
assert[~][p179;"aaaaaa";1 1 1 1 1 0]
assert[~][p179;"d";,0]

assert[~][p1710;1 2 3 4;2 2#1 2 3 4]
assert[~][p1710;1 2 3 4 5;3 3#1 2 3 4 5 0N 0N 0N 0N]
assert[~][p1710;"Dyalog APL";4 4#"Dyalog APL      "]

/ https://problems.tryapl.org/psets/2018.html

assert[=][p181;5 5 2 10 3 15 10;3]
assert[=][p181;|5 5 2 10 3 15 10;2]
assert[=][p181;!0;0]
assert[=][p181;,10;1]

assert[≈][p182;1.234;1 0.234]
assert[≈][p182;12;12 0]
assert[≈][p182;0;0 0]

assert[~][p183;6 6;("2 *";"3 **";"4 ***";"5 ****";"6 *****";"7 ******";"8 *****";"9 ****";"10 ***";"11 **";"12 *")]
assert[~][p183;6;("1 *";"2 *";"3 *";"4 *";"5 *";"6 *")]
assert[~][p183;5 3 4;("3 *";"4 ***";"5 ******";"6 *********";"7 ***********";"8 ***********";"9 *********";"10 ******";"11 ***";"12 *")]
assert[~][p183;0;()] / Dyalog expects ("0 *") which is dubious

assert[=][p184;2018;`Dog]
assert[=][p184;1564;`Rat]
assert[=][p184;-551;`Dog]

assert[=][p185;2 23;`Pisces]
assert[=][p185;10 31;`Scorpio]

assert[=][p186;"<name><first>Drake</first><last>Mallard</last></name>";1]
assert[=][p186;"<math><relation>2<3</relation></math>";0]
assert[~][p186;,"";!0] / dyalog wants 1 -- not sure
assert[=][p186;">stuff<>/stuff<";0]

assert[~][p187[3];1 0 1 1 1 0 1 1;0 0 0 1 0 1 1 1]
assert[~][p187[-3];1 0 1 1 1 0 1 1;1 1 0 1 1 0 0 0]

/ skipping p188

assert[=][p189;(2018 4 1 12 34 56 789;2018 4 1 16 45 12 800);-1]
assert[=][p189;(2018 4 1 12 34 56 789;2018 4 1 12 34 56 789);0]
assert[=][p189;(2018 4 1 12 34 56 789;2017 4 1 12 34 56 789);1]

assert[=][p1810;("ALBERT EINSTEIN";"TEN ELITE BRAINS");1]
assert[=][p1810;(,"";,"");1]
assert[=][p1810;(,"d";,"d");1]
assert[=][p1810;("mesas";"seam");0]
assert[=][p1810;("apple";"lapel");0]

/ https://problems.tryapl.org/psets/2019.html

assert[~][p191[3];1+!9;(1 2 3;4 5 6;7 8 9)]
assert[~][p191[3];1+!11;(1 2 3;4 5 6;7 8 9;10 11)]
assert[~][p191[10];"Dyalog";,"Dyalog"]
assert[~][p191[2];" "\"the cat in the hat sat pat";(("the";"cat");("in";"the");("hat";"sat");,"pat")]
assert[~][p191[4];5;,,5] / dyalog expects ,,5 but this seems inconsistent, as every other example returns vector of vectors

assert[~][p192;0 64 65 69 70 79 80 89 90 100;"FFDDCCBBAA"]
assert[~][p192;!0;()]
assert[~][p192;2 3#71 82 81 82 84 59;("CBB";"BBF")]

/ floating point CT is too annoying at depth
tmp:+p193@{9 3 8 4 7}#"DABFC"
assert[~][{x};*tmp;"ABCDF"]
assert[~][{x};tmp@1;3 8 7 9 4]
assert[≈][{x};tmp@2;9.7 25.8 22.6 29.0 12.9]

assert[~][p194;5 4;(7 5;7 3;3 5;3 3;6 6;4 6;6 2;4 2)]
assert[~][p194;1 1;(3 2;2 3)]

assert[~][p195;" "\"I feed the bookkeeper";0 1 0 1]
assert[~][p195;,"I";,0]
assert[~][p195;,"feed";,1]
assert[~][p195;" "\"MY LLAMAS HAVE BEEN GOOD";0 1 0 1 1]

assert[~][p196;"IAMYY4U";4 2 6 9 9 4 8]
assert[~][p196;"";!0]
assert[~][p196;"UR2CUTE";8 7 2 2 8 8 3]

assert[~][p197[10];" "\"APL Problem Solving Competition";("   APL    ";" Problem  ";" Solving  ";"Competitio")]

assert[≈][p198;(1 -1;1 3);8]
assert[≈][p198;(1 1;1 2;2 2;2 1);4]
assert[≈][p198;5 5;0]
assert[≈][p198;(1 1;3 3);5.656854249]

assert[≈][p199;(2 4;3 -8;1 2);7]
assert[≈][p199;,1 1;0]
assert[≈][p199;(1 1;2 2);0]

assert[~][p1910;" "\"the plan is great";(("the";"great");("plan";"is"))]
assert[~][p1910;" "\"all odd";(("all";"odd");())]
assert[~][p1910;" "\"only even here";(();("only";"even";"here"))]

/ https://problems.tryapl.org/psets/2020.html

assert[~][p201[9];"SplittingHairs";("Splitting";"Hairs")]
assert[~][p201[-3];"DyalogAPL";("Dyalog";"APL")]
assert[~][p201[10];1+!10;(1+!10;!0)]
assert[~][p201[1];" "\"works with words also";(,"works";("with";"words";"also"))]

assert[~][p202;68 194 165 226 141 186 226 140 138 240 159 148 178 57;(,68;194 165;226 141 186;226 140 138;240 159 148 178;,57)]
assert[~][p202;68 121 97 108 111 103;(,68;,121;,97;,108;,111;,103)] / dyalog expects 68 121 97 108 111 103, but this seems inconsistent
assert[~][p202;!0;()]

assert[=][p203;"A";1]
assert[=][p203;"APL";1104]

assert[~][p204;2020;1]
assert[~][p204;1900+10 10#1+!100;(0 0 0 1 0 0 0 1 0 0;0 1 0 0 0 1 0 0 0 1;0 0 0 1 0 0 0 1 0 0;0 1 0 0 0 1 0 0 0 1;0 0 0 1 0 0 0 1 0 0;0 1 0 0 0 1 0 0 0 1;0 0 0 1 0 0 0 1 0 0;0 1 0 0 0 1 0 0 0 1;0 0 0 1 0 0 0 1 0 0;0 1 0 0 0 1 0 0 0 1)]

assert[~][p205[3];10;3 4 5 6 7 8 9 10]
assert[~][p205[4];-3;4 3 2 1 0 -1 -2 -3]
assert[~][p205[42];42;,42]

assert[~][p206[3];1 2 3 4 1 3 1 4 5;3 3 1 2 4 1 1 4 5]
assert[~][p206[3];,1;,1]
assert[~][p206[42];!0;!0]

assert[=][p207;2 7;1]
assert[=][p207;4 11;0]
assert[=][p207;3 11;1]
assert[=][p207;4 0;0]

assert[=][p208;123;0]
/ assert[=][p208;132;1] / FAIL FIX ME
assert[=][p208;31115;0]
assert[=][p208;3141514131415;1]

assert[=][p209;1 3 3 4 5 2 1;1]
assert[=][p209;,42;1]
assert[=][p209;1 3 2 4;0]
assert[=][p209;23 23 23;1]
/ assert[=][p209;!0;1] / dubious

/ skipping p2010; too APL-specific

/ https://www.dyalogaplcompetition.com/?goto=P1Intro

assert[≈][p211;"GCGCGCGCCCGGGGCCG";100]
assert[≈][p211;"ACGTACGTACGTACGT";50]
assert[≈][p211;{10 12 16 10}#"ACGT";58.33333333]

/ skipping p212, as `?` is a k primitive
/ assert[~][p212["DYALOG"];"APL";2 0N 3]
/ assert[~][p212[5 5#ABC];("UVWXY";"FGHIJ";"XYZZY");4 1 0N]

assert[~][p213[2 4 7 3 9];5 7 8 1 12 10 20 16 11 4 2 15 3 18 14 19 13 9 17 6;(8 12 10 20 16 4 2 18 14 6;8 12 20 16 4;7 14;12 15 3 18 9 6;18 9)]
assert[~][p213[,3];1+!10;,3 6 9]
assert[~][p213[6 7];,42;(,42;,42)]
assert[~][p213[2 3 5];!0;(!0;!0;!0)]
assert[~][p213[!0];1+!10;()]

assert[∆][p214;2*1+!5;1.141592654 4.566370614 10.27433388 18.26548246 28.53981634]
assert[∆][p214;(%2)*3 3#1+!9;3 3#0.5707963268 2.283185307 5.137166941 9.132741229 14.26990817 20.54866776 27.96902001 36.53096491 46.23450247]

assert[~][p215;12;3 4]
assert[~][p215;16;4 4]
assert[~][{x};p215'1+!19;(1 1;1 2;1 3;2 2;1 5;2 3;1 7;2 4;3 3;2 5;1 11;3 4;1 13;2 7;3 5;4 4;1 17;3 6;1 19)]
assert[~][{x};p215'999999 1000000;(999 1001;1000 1000)]

assert[~][p216;"RNBQKBNR";1]
assert[~][p216;"BBNRKNRQ";1]
assert[~][p216;"RBBNQNRK";0]
assert[~][p216;"BRBKRNQN";0]

assert[~][p217;1 1#42;1]
assert[~][p217;3 3#4 9 2 3 5 7 8 1 6;1]
assert[~][p217;2 2#1 2 3 4;0]

assert[=][p218;(2 30;5 15);165]
assert[=][p218;(5 15;2 30);165]
assert[=][p218;(1 0 0;,0);1440]

assert[=][p219;1 2 3 5 5 5 6 4 3;3]
assert[=][p219;1 2 3 4 4 4 4 4 5 4 3;4]
assert[=][p219;1 2;1]

assert[~][p2110[6];">";"     >"]
assert[~][p2110[8];("K";"E";"Iversen");("       K";"       E";" Iversen")]
assert[~][p2110[8];("Longer Phrase";"APL";"Parade");("r Phrase";"     APL";"  Parade")]
