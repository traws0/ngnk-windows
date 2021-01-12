sy clear |sy sync fromstart |sy case match

fu!s:R(x)
 let x=a:x|let r=[['\<g=','matchgroup='],['\<s=','start='],['\<e=','end='],['\<c=','contains='],['\<sk=','skip=']]
 for[u,v]in r|let x=substitute(x,u,v,'g')|endfo
 exe 'sy region '.x
endf
com -nargs=1 H hi def link <args>
com -nargs=1 M sy match    <args>
com -nargs=1 K sy keyword  <args>
com -nargs=1 R cal   s:R(<f-args>)
M n_comment "//[^\r\n]*\|/\*\_.\{-}\*/"                                        |H n_comment comment
R n_h s="#" sk="\\\n" e="\r\|\n" c=n_comment                                   |H n_h preproc
M n_string /'\\\=.'\|"\([^\\"]\|\\.\)*"/ contains=n_e                          |H n_string string
M n_e "\\\(x\x\x\|.\)" contained                                               |H n_e special
K n_k TD S SN NO O ST __attribute__ asm enum do struct for extern              |H n_k statement
K n_t A0 A1 A2 A3 AA AX nextgroup=n_vv                                         |H n_t normal
K n_r return B continue                                                        |H n_r n_d_rr
R n_aa g=n_a s="("                       e=")" c=@n_x,n_a |M n_a "," contained |H n_a nontext
R n_bb g=n_b s="\["                      e="]" c=@n_x,n_b |M n_b "," contained |H n_b n_a
R n_cc g=n_c s="{"                       e="}" c=@n_x,n_c |M n_c "," contained |H n_c n_a
R n_pp g=n_p s="\v<(P|E[a-z]|[XY]\w+)\(" e=")" c=@n_x,n_p |M n_p "," contained |H n_p function
R n_ff g=n_f s="\<\([ijW]\)("            e=")" c=@n_x,n_f |M n_f "," contained |H n_f special
R n_ii g=n_i s="\<\(Y\|EY\=\)("          e=")" c=@n_x,n_i |M n_i "," contained |H n_i type
R n_vv g=n_v s="(\(\w\| \)*,"            e=")" c=@n_x contained                |H n_v statement
R n_uu g=n_u s="\<_("                    e=")" c=@n_x                          |H n_u n_v
sy cluster n_x contains=n_comment,n_h,n_string,n_k,n_t,n_r,n_aa,n_bb,n_cc,n_pp,n_ff,n_ii
delc H|delc M|delc K|delc R|delf!s:R
let b:current_syntax='n'
