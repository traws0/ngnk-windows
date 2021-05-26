#!../k
/https://codegolf.stackexchange.com/questions/226278/simplify-ijk-string/226279#226279
f:{(r,"-",'r:"1ijk")@{(8!A,4+A:a,'4+a:4 4#0,8\5717110953644)[x;y]}/1+3!x}
\l 0.k
t[,"i";"i"]
t[,"j";"j"]
t[,"k";"k"]
t["ij";"k"]
t["jk";"i"]
t["ki";"j"]
t["ji";"-k"]
t["kj";"-i"]
t["ik";"-j"]
t["ii";"-1"]
t["jj";"-1"]
t["kk";"-1"]
t["ijkj";"-j"]
t["iikkkkkjj";"k"]
t["kikjkikjk";"-k"]
t["kjijkjikijkjiki";"1"]
t["jikjjikjikjikjjjj";"j"]
