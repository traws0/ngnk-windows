\l 0.k
mod:{(- 10&#x)#x}
sqr:{mod mul[x;x]}
prd:{mod mul[x;y]}/
pow:{prd@((-1+#e)sqr\x)@&e:|2\y}
small mod add[big 1;mul[big 28433;pow[big 2;7830457]]] /28433*(2^7830457)+1 mod 10^10
/8739992577
