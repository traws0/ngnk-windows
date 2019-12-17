sy clear|sy case match |se isk+=$
sy match   n_comment "//[^\r\n]*\|/\*\_.\{-}\*/"
sy region  n_pp start="#" skip="\\\n" end="\r\|\n" contains=n_comment
sy match   n_string /'\\\=.'\|"\([^\\"]\|\\.\)*"/ contains=n_es
sy match   n_es "\\\(x\x\x\|.\)" contained
sy keyword n_kw typedef TD if else switch Y default case while do struct static S SI SN NI __attribute__ asm extern XT const O enum
sy keyword n_tp A0 A1 A2 A3 AA AAA nextgroup=n_vv
sy keyword n_re R return B break continue
sy region  n_aa matchgroup=n_aam start="("                       end=")" contains=@n_all,n_aam
sy region  n_bb matchgroup=n_bbm start="\["                      end="]" contains=@n_all,n_bbm
sy region  n_cc matchgroup=n_ccm start="{"                       end="}" contains=@n_all,n_ccm
sy region  n_rr matchgroup=n_rrm start="\<P("                    end=")" contains=@n_all,n_rrm
sy region  n_ff matchgroup=n_ffm start="\<\(for\|F\|Fj\)("       end=")" contains=@n_all,n_ffm
sy region  n_ii matchgroup=n_iim start="\<\(\$\|E\$\=\|Q\d\=\)(" end=")" contains=@n_all,n_iim
sy region  n_ww matchgroup=n_wwm start="\<W("                    end=")" contains=@n_all,n_wwm
sy region  n_vv matchgroup=n_vvm start="(\(\w\| \)*"             end=")" contains=@n_all contained
sy region  n_uu matchgroup=n_uum start="\<_("                    end=")" contains=@n_all
sy match   n_aam "," contained
sy match   n_bbm "," contained
sy match   n_ccm "," contained
sy match   n_rrm "," contained
sy match   n_ffm "," contained
sy match   n_iim "," contained
sy match   n_wwm "," contained
sy cluster n_all contains=n_comment,n_pp,n_string,n_kw,n_tp,n_re,n_aa,n_bb,n_cc,n_rr,n_ff,n_ii,n_ww,n_sp,n_eq,n_ne,n_le,n_ge,n_sl,n_sr,n_or,n_an,n_ni,n_nf
hi def link n_comment comment
hi def link n_string  string
hi def link n_pp      preproc
hi def link n_es      special
hi def link n_kw      statement
hi def link n_tp      normal
hi def link n_re      n_d_rr
hi def link n_aam     nontext
hi def link n_bbm     nontext
hi def link n_ccm     nontext
hi def link n_rrm     special
hi def link n_ffm     type
hi def link n_iim     function
hi def link n_vvm     statement
hi def link n_uum     statement
hi def link n_wwm     identifier
let b:current_syntax='n'
