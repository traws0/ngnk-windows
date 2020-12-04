#!../k
X:{e:x y-1;1@$y;r:z@0:"i/",-2#$100+y;1@$[r~e;," ";`k[(`actual;r;`expected;e)]," "];}@."(",(";"/0:,"o"),")"

X[1;2 3{*/`l$y@/:(x##y)\*&2020i=(,/+\:)/x#,y}\:`i$.:']
X[2]{(m;c;s):+{(.'"-"\*x;*x 1;x 2)}'" "\'x;+/'1=+/'((+/'c=s)</:0 1++m;+c=s@'m-1)}
X[3]{r[1],*/r:`l${+/x[y*i]@'(#*x)!z*i:!1+(-y)!-1+#x}[2!x]/'(1 1;1 3;1 5;1 7;2 1)}

x:0:"i/04"
x:{!/@[;0;`$]@+":"\'" "\" "/x}'((0,&x~\:"")_x)^\:,""
f:{~|/^(!x)?`byr`iyr`eyr`hgt`hcl`ecl`pid}
+/f'x

Y:{$[~4=#x;0;~&/1=+/"/9"<\:x;0;~1=+/(y-1 0)<\:. x;0;1]}
g:{$[~f x;0
     ~Y[x`byr;1920 2002];0
     ~Y[x`iyr;2010 2020];0
     ~Y[x`eyr;2020 2030];0
     ~|/`cm`in~\:`$-2#x`hgt;0
     ~1=+/(`cm`in!(150 193;59 76)-\:1 0)[`$-2#x`hgt]<\:.-2_x`hgt;0
     ~"#"=*x`hcl;0
     ~(6#1)~2!+/"/9`f"<\:1_x`hcl;0
     ~|/`amb`blu`brn`gry`grn`hzl`oth=`$x`ecl;0
     ~9=#x`pid;0
     ~&/1=+/"/9"<\:x`pid;0
     1]}
+/g'x

/    byr (Birth Year) - four digits; at least 1920 and at most 2002.
/    iyr (Issue Year) - four digits; at least 2010 and at most 2020.
/    eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
/    hgt (Height) - a number followed by either cm or in:
/        If cm, the number must be at least 150 and at most 193.
/        If in, the number must be at least 59 and at most 76.
/    hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
/    ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
/    pid (Passport ID) - a nine-digit number, including leading zeroes.
/    cid (Country ID) - ignored, missing or not.
