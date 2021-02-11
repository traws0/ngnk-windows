#!../k
/https://codegolf.stackexchange.com/questions/216303/iterate-over-the-neighborhood-of-a-string/216579#216579
f:{?"ab"@?,/e'e"b"=x}
e:{?,/(~+x==#x;{y,x,z}.',/0 1,/:\:(0,'!1+#x)_\:x;x_/:!#x)}
\l 0.k
t["aaa";("aaa";"bba";"bab";"abaa";"baaa";"bbaa";"baba";"baab";"aa";"ba";"abb";"aaba";"abba";"abab";"ab";"aaab";"aabb";"aaaaa";"baaaa";"abaaa";"aabaa";"aaaba";"aaaab";"aaaa";"bbaaa";"babaa";"baaba";"baaab";"baa";"abbaa";"ababa";"abaab";"aba";"aabba";"aabab";"aab";"aaabb";,"a")]
