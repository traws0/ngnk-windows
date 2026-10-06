ts:`c`i!256,0N-1
mkn0:{z$x?y&ts z}
str0:{`c$x[0]+(y[0]+z?y[1]-y[0]-1)mkn0[;x[1]]\:`i}

char:str0[0 256]
salph:str0[("a";26)]
snum:str0[("0";10)]
salphnum:{`c$s+(-10+-/"a0")*"0:"'s:str0[("0";36);x;y]}

mkns:{`s$salph[x;y]}
SYMLENRNG:1 4
DCTLENRNG:2 4
mknt0:{$[`s~z;mkns[SYMLENRNG];`A~z;mkmx0[x;]'4+&:;`m~z;mkdt0[x;;`A]'DCTLENRNG[0]+?/|(--/DCTLENRNG),;mkn0[;ts z;z]]y}
mknt:mknt0[1]

mkmx0:{,/mknt0[x-1;1]'y?$[x>0;`c`s`i`A`m;`c`s`i]}
mkmx:mkmx0[1]

mkdt0:{mkns[1 4;y]!mknt0[x;y]z}
mkdt:mkdt0[0]

/
Examples:

char[3 6]2       / 2 char vectors with ascii values from 0-256 and length 3-6 (inclusive)
salph[3 7]5      / 5 (lowercase) alphabetic strings with length from 3 to 7 (inclusive)
snum[5 9]10      / 10 numeric strings with length from 5 to 9 (inclusive)
salphnum[5 8]15  / 10 alphanumeric strings with length from 5 to 9 (inclusive)

mkns[1 4]8       / make 8 symbols with lengths from 1-4 (inclusive)

mknt[5]'`c`s`i   / make 5 elements each of type char, symbol and int. (length of symbols governed by SYMLENRNG)

mkmx[5]          / make a mixed array of length 5
mkmx0[2]5        / make a mixed array of length 5 and max depth 2

mkmx0[0]'5+&8    / make a mixed array of length 8, depth 1 containing mixed arrays of length 5

mkdt[5]`c        / make 5 dicts of length 4 with chars as values
mkdt[5]`A        / make 5 dicts of length 4 with mixed arrays as values
