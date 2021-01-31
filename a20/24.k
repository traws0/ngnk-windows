#!../k
a:{`$(&1i,-1_~|/"ns"=\:x)_x}'0:"i/24"
N:1+2*n:101+|/#'a
D:`e`w`ne`nw`se`sw!d:(1;-1;1-N;-N;N;N-1)
h:(-1+N*N)&0|d+\: \!N*N /neighbour indices in flattened matrix
+/p:2!#'=+/'D@/:a /part1
`l$+/100{(x&1i=k)|2i=k:+/x h}/@[(N*N)#0i;(&p)+N/2#n;:;1i] /part2
