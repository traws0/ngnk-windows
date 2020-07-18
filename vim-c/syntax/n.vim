sy clear |sy case match
sy match   n_comment "//[^\r\n]*\|/\*\_.\{-}\*/"                                                            |hi def link n_comment comment
sy region  n_h start="#" skip="\\\n" end="\r\|\n" contains=n_comment                                        |hi def link n_h preproc
sy match   n_string /'\\\=.'\|"\([^\\"]\|\\.\)*"/ contains=n_e                                              |hi def link n_string string
sy match   n_e "\\\(x\x\x\|.\)" contained                                                                   |hi def link n_e special
sy keyword n_k TD S XT NI O __attribute__ asm enum do struct for                                            |hi def link n_k statement
sy keyword n_t A0 A1 A2 A3 AA AX nextgroup=n_vv                                                             |hi def link n_t normal
sy keyword n_r return B continue                                                                            |hi def link n_r n_d_rr
sy region  n_aa matchgroup=n_a start="("              end=")" contains=@n_x,n_a |sy match n_a "," contained |hi def link n_a nontext
sy region  n_bb matchgroup=n_b start="\["             end="]" contains=@n_x,n_b |sy match n_b "," contained |hi def link n_b n_a
sy region  n_cc matchgroup=n_c start="{"              end="}" contains=@n_x,n_c |sy match n_c "," contained |hi def link n_c n_a
sy region  n_pp matchgroup=n_p start="\<P(\|\<E\w("   end=")" contains=@n_x,n_p |sy match n_p "," contained |hi def link n_p function
sy region  n_ff matchgroup=n_f start="\<\(W\|Fj\=\)(" end=")" contains=@n_x,n_f |sy match n_f "," contained |hi def link n_f special
sy region  n_ii matchgroup=n_i start="\<\(Y\|EY\=\)(" end=")" contains=@n_x,n_i |sy match n_i "," contained |hi def link n_i type
sy region  n_vv matchgroup=n_v start="(\(\w\| \)*,"   end=")" contains=@n_x contained                       |hi def link n_v statement
sy region  n_uu matchgroup=n_u start="\<_("           end=")" contains=@n_x                                 |hi def link n_u n_v
sy cluster n_x contains=n_comment,n_h,n_string,n_k,n_t,n_r,n_aa,n_bb,n_cc,n_pp,n_ff,n_ii
let b:current_syntax='n'
