au bufread,bufnewfile *.{c,h} if getline(1).getline(2)=~'ngn'|se ft=n|en
