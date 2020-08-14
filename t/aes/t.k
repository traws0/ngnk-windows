#!../../k
/please run ./download.sh first
t:{$[(x[2]~`aes@|2#x)&x[1]~`aes?x 2 0;; \`k[`FAIL,x],"\n"];}
f:{t'(`hex?'*|+" = "\'1_"\r\n"\)'2_"\r\n\r\n"\*"\r\n\r\n[DECRYPT]"\1: \x;}
f'("kat/ECBVarTxt128.rsp"
   "kat/ECBVarTxt192.rsp"
   "kat/ECBVarTxt256.rsp"
   "kat/ECBVarKey128.rsp"
   "kat/ECBVarKey192.rsp"
   "kat/ECBVarKey256.rsp"
   "kat/ECBKeySbox128.rsp"
   "kat/ECBKeySbox192.rsp"
   "kat/ECBKeySbox256.rsp"
   "kat/ECBGFSbox128.rsp"
   "kat/ECBGFSbox192.rsp"
   "kat/ECBGFSbox256.rsp");
