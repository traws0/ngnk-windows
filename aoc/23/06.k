#!../../k
/x(t-x) ⩾ d
/x^2-tx+d ⩽ 0
f:{[t;d]            /t:time,d:distance
 D:(t*t)-4*d        /discriminant
 r:(t-%D;t+%D)%2    /roots
 1+-/(_r 1;-_-r 0)} /number of integer solutions

x:(1_*|":"\)'0:"i/06"
*/f..'x      /1
*/f..'x^'" " /2
