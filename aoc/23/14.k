#!../../k
x:0:"i/14"
n:#x

roll:{@[x;(0;n)+\:&&/".O"=(-n;n)_\:x;:;"O."]}
tilt:roll/
load:+/(n-&n#n)*"O"=
load tilt@,/x /1

rot:@[;n/|{|y}\!2#n]
cyc:4(rot tilt@)/
rho:{t:cyc@*|x;:[^x?t;x,,t;x]}/,,/x
s:rho?cyc@*|rho /loop start
l:(#rho)-s      /loop length
load rho s+l!1000000000-s /2
