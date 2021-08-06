#!../k
/https://codegolf.stackexchange.com/questions/217328/help-stack-exchange-transpose-tables/217343#217343
f:{,/'+({"|",'n$(*x;(n:|/#'x)#"-"),1_x}(~#:')_{(-^*|x)_(^*x)_x}/'"|"\)'x_1}

\l 0.k
out1:("|A header      |First|Second";"|--------------|-----|------";"|Another header|row  |row   ");
out2:("|A header        |First            |Second    ";"|----------------|-----------------|----------";"|Another header  |0                |row       ";"|Last column here|more content here|that's it!");
t[("| A header | Another header |";"| -------- | -------------- |";"| First    | row            |";"| Second   | row            |");out1]
t[("| A header | Another header";"| -------- | --------------";"| First    | row           ";"| Second   | row            ");out1]
t[("|A header|Another header|";"|--------|--------------|";"|First   |row           |";"|Second  |row           | ");out1]
t[("|A header|Another header";"|--------|--------------";"|First   |row           ";"|Second  |row           ");out1]
t[("| A header | Another header | Last column here  |";"| -------- | -------------- | ----------------- |";"| First    | 0              | more content here |";"| Second   | row            | that's it!        |");out2]
t[("| A header | Another header | Last column here ";"| -------- | -------------- | -----------------";"| First    | 0              | more content here";"| Second   | row            | that's it!       ");out2]
t[("|A header|Another header|Last column here |";"|--------|--------------|-----------------|";"|First   |0             |more content here|";"|Second  |row           |that's it!       |");out2]
t[("|A header|Another header|Last column here";"|--------|--------------|-----------------";"|First   |0             |more content here";"|Second  |row           |that's it!");out2]
