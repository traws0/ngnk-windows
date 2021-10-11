crv:{{.[x;y,z;:;1]}/[(1+|/'x)#0]. x-:&/'x}@+\' /curve as (dxs;dys) -> bool matrix
brl:{,/'u8''10240++/''0N 2#/:+/'0N 4#x*(#x)#(#*x)#'(1 8;2 16;4 32;64 128)} /bool matrix -> braille
u8:{`c$(0x00c0e0f0[c],c#128)+(0,64+&c:1+128 2048 65536'x)\x} /utf8 encode
f:`0:brl@ /display

f@~=\\&64                                 /sierpinski triangle
f@*/*/:'/2#,~1=!4#3                       /cantor dust
f@crv 11{x,'|'|-1 1*x}/!2                 /dragon curve
f@6{+2(x,(,~!#*x),|:')/x}/1               /peano curve
f@5{b,'1_'|'b:,/(|+x,0;,a,0;x,'a:~!#x)}/1 /hilbert curve
f@n{(|(8#2)\30)@2/+3'0,x,0}\n=!2*n:32     /rule30
f@1>n#+/*/2#,12((|3*-0.5 -0.7+(!n)%n:2#64)+{(-/x*x;2*/x)}@)/0 /mandelbrot set
