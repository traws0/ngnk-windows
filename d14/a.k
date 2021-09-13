#!../k
/https://gist.github.com/xpqz/73e9d57a7f1921f7d44704505a22fa3e
/https://problems.tryapl.org/psets/2014.html

gcd:*|(*:)(|!\)/,
lcm:{x*(-gcd[x]y)!y}
pi:3.14159265359
abc:"abcdefghijklmnopqrstuvwxyz"

p1:{(z*z)=+/*/2 2#x,y}
p2:{(2(|1|':)/"0">x)|^"aeiou"?_x}#
p3:{((x-1)(|+\)\1 1)[;1]}
p4:" "/(~#:')_" "\
p5:{{x~|x}l^(l:_x)^abc}
p6:{+(!x;.x)}@#'=+/1+!(),
p7:{lcm[x;y]%y}
p8:{%+/d*d:-/x}
p9:{(x*x*`sin@2*y*pi%180)%9.8}
p10:100*|/1_0{(x-y)%y}':
