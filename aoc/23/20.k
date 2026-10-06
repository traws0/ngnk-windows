#!../../k
x:0:"i/20"
x:+" -> "\'x
(vt;vn):(*:';`$)@'+{(0,"a">*x)_x}'*x /names,types
vo:`$", "\'x 1
vn:?vn,,/vo
vt@:!#vn
vo:vn?`$", "\'x 1             /outputs
n:#vn
vo,:((#vo)-n)#,!0
vi:@[n#,!0;vo;,;!n]           /inputs
vm:vm0:@[&n;i;:;&'#'vi i:&"&"=vt] /memory
q:!0  /queue
r:0 0 /counter
b:*&vn=`broadcaster
rx:*&vn=`rx
p2ctr:0
pulse:{
 (i;j;p):*q /i:sender,j:receiver,p:pulse(0=low,1=high)
 /\,`pulse,vn[i],vn[j],p
 p2ctr+:(~p)&j=rx
 r[p]+:1
 q::1_q
 t:vt j
 :[j=b;                   q,:j,'vo[j],'p
   "%"=t;:[p;;            q,:j,'vo[j],'vm[j]=:0]
   "&"=t;[vm[j;vi[j]?i]:p;q,:j,'vo[j],'~&/vm j]
         ];}
push:{q::,(b;b;0);{#q}{pulse[]}/`};
push'!1000;
*/r /1

/vm:vm0
/pushctr:0
/{~p2ctr}{ \pushctr+:1;push[]}/0
