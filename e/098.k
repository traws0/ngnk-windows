\l 0.k
pairs:{,/{x@+c,'|c:cmb[2;#x]}'{1<#x}#x@.={x@<x}'x}
a:pairs@1_'-1_'","\1:"p098_words.txt"
m:|/#'*'a /max length
b:pairs@${x*x}@!1+_%*/m#10
enc:{m/,/(*x)?/:x}
|/.',/b@&~^(?enc'a)?enc'b
/18769
