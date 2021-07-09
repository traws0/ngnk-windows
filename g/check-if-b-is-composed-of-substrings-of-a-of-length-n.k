#!../k
/https://codegolf.stackexchange.com/questions/221420/check-if-b-is-composed-of-substrings-of-a-of-length-n/221441#221441
f:{i~?,/(x'i:!#z)@&~^(x'y)?x'z}

\l 0.k
T[(2;"abcdefg";"bcabcdebcdef");1]
T[(2;"abcdefg";"cdabfg");1]
T[(4;"abracadabra";"abrabrabrabra");1]
T[(1;"abcdefg";"ddbfeg");1]
T[(2;"ab";"abab");1]
T[(2;"bb";"bbbbb");1]
T[(5;"abcdefghijklmn";"defghabcdefghi");1]
T[(2;"abcdefg";"hijklmn");0]
T[(3;"abcdefg";"bcabcdebcdef");0]
T[(2;"abcdefg";"ddabfg");0]
T[(2;"ab";"aba");0]
T[(2;"abcdefg";,"a");0]
T[(4;"abracadabra";"brabrabrabra");0]
T[(6;"abcdefghijklmn";"defghabcdefghi");0]
