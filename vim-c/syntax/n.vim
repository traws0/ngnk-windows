sy clear |sy case match
com -nargs=1 H hi def link <args>
sy match   n_comment "//[^\r\n]*\|/\*\_.\{-}\*/"                                                                |H n_comment comment
sy region  n_h start="#" skip="\\\n" end="\r\|\n" contains=n_comment                                            |H n_h preproc
sy match   n_string /'\\\=.'\|"\([^\\"]\|\\.\)*"/ contains=n_e                                                  |H n_string string
sy match   n_e "\\\(x\x\x\|.\)" contained                                                                       |H n_e special
sy keyword n_k TD S SN XT NO O ST __attribute__ asm enum do struct for                                          |H n_k statement
sy keyword n_t A0 A1 A2 A3 AA AX nextgroup=n_vv                                                                 |H n_t normal
sy keyword n_r return B continue                                                                                |H n_r n_d_rr
sy region  n_aa matchgroup=n_a start="("                  end=")" contains=@n_x,n_a |sy match n_a "," contained |H n_a nontext
sy region  n_bb matchgroup=n_b start="\["                 end="]" contains=@n_x,n_b |sy match n_b "," contained |H n_b n_a
sy region  n_cc matchgroup=n_c start="{"                  end="}" contains=@n_x,n_c |sy match n_c "," contained |H n_c n_a
sy region  n_pp matchgroup=n_p start="\<P(\|\<e[a-z]("    end=")" contains=@n_x,n_p |sy match n_p "," contained |H n_p function
sy region  n_ff matchgroup=n_f start="\<\([WF]\|F[j_]\)(" end=")" contains=@n_x,n_f |sy match n_f "," contained |H n_f special
sy region  n_ii matchgroup=n_i start="\<\(Y\|EY\=\)("     end=")" contains=@n_x,n_i |sy match n_i "," contained |H n_i type
sy region  n_vv matchgroup=n_v start="(\(\w\| \)*,"       end=")" contains=@n_x contained                       |H n_v statement
sy region  n_uu matchgroup=n_u start="\<_("               end=")" contains=@n_x                                 |H n_u n_v
sy cluster n_x contains=n_comment,n_h,n_string,n_k,n_t,n_r,n_aa,n_bb,n_cc,n_pp,n_ff,n_ii
delc H
let b:current_syntax='n'
