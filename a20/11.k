#!../k
a:0:"i/11" /b:seats,c:occupied,f[x;y]:solve[threshold;neighbours]
N:*/n:(#a;#*a);a:,/a,".";b:~"."=a;c:"#"=a;d:(1-!3 3)_'4
f:{+/{b*(~s+z)|z*x>s:+/z y}[x;y,'N]/c}
f[4;(N*~u)+(n/h)*u:&/(-1_b)*/:/:u:>/(n;0)>\:h:d+\:'!n]
f[5;,/(@[N#N;;:;]/'|:\(&b)@,/'1 -1_'\:.=)'(+/p;-/p),p:n\&b]
