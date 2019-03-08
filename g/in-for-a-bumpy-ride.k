/https://codegolf.stackexchange.com/questions/167924/in-for-a-bumpy-ride/167933#167933
f:. s:"{*/ 0 >1_ *':1_ -': x }"

/` 0:1_'(,\(1+#s)#"|"),'$0+s,,""
/` 0:"-=+"3,1+(0<d)-0>d:1_-':0+s
/` 0:(s;"";"tests:")

t:{$[y~r:f x;`ok;(`fail;x;y;r)]}
t[1 2 0 3 2  ;1]
t[4 2 3 0 1  ;1]
t[1 2 0 0 3 1;0]
t[1 2 3 1    ;0]
t[s          ;1]
