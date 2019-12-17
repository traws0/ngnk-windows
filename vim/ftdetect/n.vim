au bufread,bufnewfile *.{c,h} if getline(1)=~'ngn'|se ft=n|en
