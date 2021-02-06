#!../k
a:{`$(&1,-1_~|/"ns"=\:x)_x}'0:"i/24"
N:1+2*n:101+|/#'a
D:`e`w`ne`nw`se`sw!d:(1;-1;1-N;-N;N;N-1)
h:(-1+N*N)&0|d+\:!N*N /neighbour indices in flattened matrix
+/p:2!#'=+/'D@/:a /part1
+/100{(x&1=k)|2=k:+/x h}/@[&N*N;(&p)+N/2#n;:;1] /part2
