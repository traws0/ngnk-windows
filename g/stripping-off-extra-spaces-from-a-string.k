#!../k
/https://codegolf.stackexchange.com/questions/50510/stripping-off-extra-spaces-from-a-string/215875#215875
f:" "/^[;,""]@" "\

\l 0.k
t["this  is  a    string   ";"this is a string"]
t["  blah blah    blah ";"blah blah blah"]
t["abcdefg";"abcdefg"]
t["           ";""]
t["12 34  ~5 6   (7, 8) - 9 -  ";"12 34 ~5 6 (7, 8) - 9 -"]
