mo:0 0 31 59 90 120 151 181 212 243 273 304 334 /month offsets
iymd:{z+mo[y]+(365*x)--/-100 -4 -400!'x-3>y}. /int from (year;month;day)
ymdi:{k:&4 /(year;month;day) from int
 k[0]:-146097!  x               ;x-: 146097*k[0]
 k[1]: -36524!0|x-1             ;x-:( 36524*k[1])+ ~~k[1]
 k[2]:  -1461!  x+~~k[1]        ;x-:(  1461*k[2])-(~~k[2])&~~k[1]
 k[3]:   -365!0|x-(~~k[2])|~k[1];x-:(   365*k[3])+(~~k[3])&(~~k[2])|~k[1]
 Y:+/400 100 4 1*k
 l:(58<x)&2!+/~4 100 400!'Y
 m:mo'x-l
 (Y;m;1+x-mo[m]+l*2<m)}

/https://help.dyalog.com/latest/#Language/System%20Functions/dt.htm
dt:{$[y~1;iymd[z]-x;y~-1;ymdi x+z;`err"nyi"]}iymd 1899 12 31
