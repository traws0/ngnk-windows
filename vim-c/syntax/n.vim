sy clear |sy case match
com -nargs=1 H hi def link <args>
com -nargs=1 M sy match    <args>
com -nargs=1 R sy region   <args>
com -nargs=1 K sy keyword  <args>
M n_comment "//[^\r\n]*\|/\*\_.\{-}\*/"                                                         |H n_comment comment
R n_h start="#" skip="\\\n" end="\r\|\n" contains=n_comment                                     |H n_h preproc
M n_string /'\\\=.'\|"\([^\\"]\|\\.\)*"/ contains=n_e                                           |H n_string string
M n_e "\\\(x\x\x\|.\)" contained                                                                |H n_e special
K n_k TD S SN XT NO O ST __attribute__ asm enum do struct for                                   |H n_k statement
K n_t A0 A1 A2 A3 AA AX nextgroup=n_vv                                                          |H n_t normal
K n_r return B continue                                                                         |H n_r n_d_rr
R n_aa matchgroup=n_a start="("                  end=")" contains=@n_x,n_a |M n_a "," contained |H n_a nontext
R n_bb matchgroup=n_b start="\["                 end="]" contains=@n_x,n_b |M n_b "," contained |H n_b n_a
R n_cc matchgroup=n_c start="{"                  end="}" contains=@n_x,n_c |M n_c "," contained |H n_c n_a
R n_pp matchgroup=n_p start="\<P(\|\<e[a-z]("    end=")" contains=@n_x,n_p |M n_p "," contained |H n_p function
R n_ff matchgroup=n_f start="\<\([WF]\|F[j_]\)(" end=")" contains=@n_x,n_f |M n_f "," contained |H n_f special
R n_ii matchgroup=n_i start="\<\(Y\|EY\=\)("     end=")" contains=@n_x,n_i |M n_i "," contained |H n_i type
R n_vv matchgroup=n_v start="(\(\w\| \)*,"       end=")" contains=@n_x contained                |H n_v statement
R n_uu matchgroup=n_u start="\<_("               end=")" contains=@n_x                          |H n_u n_v
sy cluster n_x contains=n_comment,n_h,n_string,n_k,n_t,n_r,n_aa,n_bb,n_cc,n_pp,n_ff,n_ii
delc H|delc M|delc K|delc R
let b:current_syntax='n'
