#!/../k
/ https://codegolf.stackexchange.com/questions/251864/re-name-all-identifiers-to-a-single-letter
f:{$[x~*x;`s$`c$97+(s::?s,x)?x;[t:s;r:o'x;s::t;r]]};s:!0

\l 0.k
t[,`rudolf                    ;,`a                    ]
t[`mousetail`mousetail        ;`a`a                   ]
t[`cart`fish                  ;`a`b                   ]
t[`no`and`no                  ;`a`b`a                 ]
t[(`burger;`and`fries)        ;(`a;`b`c)              ]
t[(`burger;`or`burger)        ;(`a;`b`a)              ]
t[(`let;`bob`and;`bob`let)    ;(`a;`b`c;`b`a)         ]
t[(`let;(`a;(`fish;,`let)))   ;(`a;(`b;(`c;,`a)))     ]
t[(`kor;`kor`kor;`kor`kor)    ;(`a;`a`a;`a`a)         ]
t[(,`kor;`kor)                ;(,`a;`a)               ]
t[(`aa;`ab`ac`ad;`ad`ad;`ad)  ;(`a;`b`c`d;`b`b;`b)    ]
t[(`aa;`not;`ab`ac`ad;`ad`ad) ;(`a;`b;`c`d`e;`c`c)    ]
t[((((,`do;`re);`mi);`fa);`so);((((,`a;`a);`a);`a);`a)]
t[(`do;(`re;(`mi;(`fa;,`so))));(`a;(`b;(`c;(`d;,`e))))]
t[(`mark`sam;`sam)            ;(`a`b;`a)              ]
