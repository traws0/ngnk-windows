/https://codegolf.stackexchange.com/questions/194835/spelling-on-a-grid/194838#194838
f:{,/(|4,&0|,/-:\)'-':+(0,y)\x-97}
\l 0.k
s:{"!"/{x@<"DRUL"?x}'"!"\x} /sort !-separated groups
g:f;f:{s"DRUL!"g[x;y]} /make f use DRUL! instead of 0 1 2 3 4
T[("dog";4);s"RRR!LDDD!UU!"]
T[("dog";3);s"D!DDDRR!LLUU!"]
T[("hello";6);s"RD!RRRU!RD!!DLLL!"]
T[("codegolf";10);s"RR!RRD!LU!R!RR!LLD!LLL!URRRR!"]
T[("acegikmoqsuwy";2);s"!D!D!D!D!D!D!D!D!D!D!D!D!"]
