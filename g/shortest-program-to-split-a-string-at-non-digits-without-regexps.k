#!../k
/https://codegolf.stackexchange.com/questions/21841/shortest-program-to-split-a-string-at-non-digits-without-regexps/217235#217235
f:{x@.t@=t-!#t:&~^(,/$!10)?x}

\l 0.k
t["abc123def456";("123";"456")]
t["aitew034snk582:3c";("034";"582";,"3")]
t["as5493tax54\\430-52@g9.fc";("5493";"54";"430";"52";,"9")]
t["sasprs]tore\"re\\forz";()]
