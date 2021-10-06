A:("####|##|###|## |###| ##|###"
   "    |##| # | ##|#  |## |  #")
T:&''3(|+:)\'(|/')#'+"#"="|"\'A /tetrominos by type and rotation
C:`cyan`yellow`magenta`green`blue`red`orange /colours by tetromino type
a:20 10#0 /grid (boolean matrix without the falling tetromino)
s:0 /score

/falling tetromino (p:position,t:type,r:rotation)
i:{f[3 0;*1?#T;*1?4];0}  /init
f:{$[*/~a ./:+|x+T[y]z   /try to set position,type,rotation
 [p::x;t::y;r::z;1];0]}  /return 1 for success, 0 for collision
d:{$[f[p+0 1;t;r];:1;]   /try to move it down. if successful, return 1
 a::a .[;;:;1]/+|p+T[t]r /freeze fallen blocks
 n:+/m:*/'a              /number of and mask of completed lines
 a::(0*n#a),a@&~m        /clear completed lines, replenish with empty
 (1&n)(`0:)/$s+:-1+*/n#2 /update score and print it if necessary
 i[]}                    /respawn
tick:d                   /periodically call d[]

/rendering
b:_256%#a                                 /block size
c:{"g.fillStyle='",($x),"';"}             /set colour
q:{"g.fillRect(",(","/$(b*x),b-1 1),");"} /draw a square(block)
draw:{`js@,//("g.clearRect(0,0,256,256);"
              c`"#80808020";q'+|&1|a      /semi-transparent grid background
              c C t;q'+p+T[t]r            /draw falling tetromino
              c`white;q'+|&a)}            /draw stationary blocks

/key down event handler
kd:{$[32=x;(::)d/1      /space(drop)
      37=x;f[p-1 0;t;r] /left
      38=x;f[p;t;4!1+r] /up(rotate)
      39=x;f[p+1 0;t;r] /right
      40=x;d[]]}        /down

i[];
`js"tickPeriod=500"; /tick[] will be called every half second
`js"hgr()";          /enter graphics mode

/for a similar language with more advanced graphics capabilities see:
/ https://johnearnest.github.io/ok/ike/ike.html
