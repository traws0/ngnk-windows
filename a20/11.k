#!../k
a:0:"i/11" /b:seats,c:occupied,f[x;y]:solve[threshold;neighbourhood]
N:*/n:(#a;#*a);a:(,/a),".";b:~"."=a;c:"#"=a;D:(1-!3 3)_'4
f:{+/{b*(~s+z)|z*x>s:+/z y}[x;y]/c}
f[4]((N*~u)+(n/h)*u:&/(-1_b)*/:/:u:>/(n;0)>\:h:D+\:'!n),'N
f[5;,/{u:B 1 -1_'\:.=x;@[N,N#N;;:;]/'(u;|u)}'(+/p;-/p),p:n\B:&b]
