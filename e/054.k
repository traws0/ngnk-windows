p:{x:("CDHS";"23456789TJQKA")?'|+x
   s:x 0;r:x 1       /s:suits r:ranks
   f:1=#?s           /flush?
   g:~#((!5)+&/r)^r  /straight?
   d:10/{x@>x}@#'=r  /rank distribution
   v:+/|\(f&g;d=41;d=32;f;g;d=311;d=221;d=2111;1) /9=StraightFlush(orRoyal) 8=FourOfAKind etc, 1=HighCard
   h:r@>r+13*+/r=\:r /ranks grouped and ordered by multiplicity
   100/v,h}
+/{>/p'0 5_" "\x}'0:"p054_poker.txt"
/376
