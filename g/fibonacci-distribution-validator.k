#!../k
/https://codegolf.stackexchange.com/questions/18887/fibonacci-distribution-validator/214256#214256
f:{(+\|:)/[(#x)>+/;!2]~+/'~:\=/"/9"<\:x}

\l 0.k
t["2";1]
t["1x";1]
t["x86";1]
t["x'48656C6C6F20776F726C642121'||'!'";1]
t["ab123";1]
t["";0]
t["12";0]
t["1xx";0]
t["x";0]
t["x123";0]
t["abc123";0]
