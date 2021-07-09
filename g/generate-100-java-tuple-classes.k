#!../k
/https://codegolf.stackexchange.com/questions/70871/generate-100-java-tuple-classes/217017#217017
f:{,/("class Tuple";$x;" {public Object _";",_"/$!x;";}\n")}

\l 0.k
t[10;"class Tuple10 {public Object _0,_1,_2,_3,_4,_5,_6,_7,_8,_9;}\n"]
