#!../k
/https://codegolf.stackexchange.com/questions/77095/palindromizing-the-strings/217007#217007
f:{t@*&{x~|x}'t:x,/:|',\x}

\l 0.k
t["abcb";"abcba"]
t["hello";"hellolleh"]
t["bonobo";"bonobonob"]
t["radar";"radaradar"]
t["hex";"hexeh"]
