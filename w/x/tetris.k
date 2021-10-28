A:("####|##|###|## |###| ##|###"
   "    |##| # | ##|#  |## |  #")
T:&''3(|+:)\'(|/')#'+"#"="|"\'A /tetrominos by type and rotation
C:`cyan`yellow`magenta`green`blue`red`orange /colours by piece type
a:20 10#0 /grid (boolean matrix without the falling piece)
g:0N?#T /randomized bag of 0..6
s:0 /score

/falling piece (p:position,t:type,r:rotation)
i:{$[g;;g::0N?#T];f[3 0;*g;3];g::1_g;0} /init
f:{$[*/~a ./:+|x+T[y]z   /try to set position,type,rotation
 [p::x;t::y;r::z;1];0]}  /return 1 for success, 0 for collision
d:{$[f[p+0 1;t;r];:1;]   /try to move it down. if successful, return 1
 a::a .[;;:;1]/+|p+T[t]r /freeze fallen blocks
 n:+/m:*/'a              /number of and mask of completed lines
 a::(0*n#a),a@&~m        /clear completed lines, replenish with empty
 s+:-1+*/n#2             /update score
 i[]}                    /respawn
tick:d                   /periodically call d[]

/rendering
b:0.9*B:1%#a                             /block size
c:{"g.fillStyle='",($x),"';"}            /set colour
q:{"g.fillRect(",(","/$(B*x),2#b),");"}  /draw a square(block)
w:{"g.fillText(",(","/(,`k[x]),$y),");"} /write text
draw:{`js@,//("g.clearRect(0,0,1,1);"
              c`"#80808020";q'+|&1|a     /semi-transparent grid background
              c C t;q'+p+T[t]r           /draw falling piece
              c C@*g;q'+(2+#*a;4)+T[*g]3 /shadow piece
              c`white;q'+|&a             /draw stationary blocks
              w["score:",$s;1%2 16])}    /draw score

/key down event handler
kd:{$[32=x;(::)d/1      /space(drop)
      37=x;f[p-1 0;t;r] /left
      38=x;f[p;t;4!1+r] /up(rotate)
      39=x;f[p+1 0;t;r] /right
      40=x;d[]]}        /down

i[];
`js"tickPeriod=500";     /tick[] will be called every half second
`js"hgr()";              /enter graphics mode

/for a similar language with more advanced graphics capabilities see:
/ https://johnearnest.github.io/ok/ike/ike.html
