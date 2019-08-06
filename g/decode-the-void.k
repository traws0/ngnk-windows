/https://codegolf.stackexchange.com/questions/119994/decode-the-void#169659
e:{$[#x;2/,/1,'&:'o'x;0]};d:{$[x;o'|-1+-1-':&|2\x;()]}
\l 0.k
f:d@e@;{0N!t[x;x]}'(();,();(();());,,();(,();());(();,())); / test d(e(l)) is l
f:e@d@;{0N!t[x;x]}'!20; / test e(d(n)) for n in 0..19
