#!../k
n:10000
t:(n>)(10*)\1
P:`pri n*n
Q:{x=P@P'x} /is prime?
&/+/'3{,/y,/:'{x^x^y}/'x y}[(a@'1)@=*'a]/a:+p@d@\:&</d:&&/1+:\Q@p+(t*\:p)@1+t'p:1_`pri n
