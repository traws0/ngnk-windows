#!../k
a:0:"i/11" /b:seats,c:occupied,f[x;y]:solve[threshold;neighbours]
N:*/n:`i$(#a;#*a);a:,/a,".";b:~"."=a;c:"#"=a;d:`i$(1-!3 3)_'4
f:{`l$+/{b*(~s+z)|z*x>s:+/z y}[`i$x;`i$y,'N]/c}
f[4;(N*~u)+(`i$n/h)*u:&/(-1_b)*/:/:u:>/(n;0i)>\:h:d+\:'`i$!n]
f[5;,/(@[N#N;;:;]/'|:\(`i$&b)@,/'1 -1_'\:.=)'(+/p;-/p),p:n\&b]
