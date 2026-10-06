#!../../k
x:0:"i/03"
d:~"0:"'       /is digit?
D:1-!3 3       /3x3 neighbourhood
n:d x          /numbers mask
p:~n|"."=x     /parts mask
m*:+\0>':m:,/n /number each run of 1s
u:.(,0)_=m     /for each number: positions of its digits
v:`I$(,/x)u    /values of numbers
t:{3|/':0,x,0} /OR with left and right neighbour
+/v@-1+(?m*,/t't p)^0 /1

s:#'1*:\x      /shape
g:&"*"=,/x     /gear coordinates
h:+m@s/(s-1)&0|D+\:'s\g /for each gear: adjacent number values
+/{*/v[r-1]*2=#r:(?x)^0}'h /2
