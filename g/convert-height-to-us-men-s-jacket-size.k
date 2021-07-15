#!../k
/https://codegolf.stackexchange.com/questions/214796/convert-height-to-us-men-s-jacket-size/214802#214802
g:`XXXS`XXS`XS`M`L`XL`3XL`5XL`6XL@(159+\7\8689119)'

s:`XXXS`XXS`XS`S`M`L`XL`XXL`3XL`4XL`5XL`6XL /sizes
l:160 162 166 168 171 174 180 184 187 191 193 197 /lower bounds
u:164 166 170 173 176 182 186 189 193 194 198 200 /upper bounds
v:s!+(l;u)
f:&/{{x=y|z&x}.x,v g x}'

\l 0.k
t[160+!41;1]
