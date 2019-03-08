files:{1_x,".k"}'$1001+!100;t0:`t[];0:'files;t1:`t[];1@"disk cache warm-up: ",($-1000!t1-t0),"ms\n";
t0:`t[];{1@(3#x)," ";e:*|0:x;e:$["/"~*e;1_e;"missing"];r:-1_`("../k";x);1@$[e~r;;"\nexpected:",e,"\nactual:",r,"\n"];}'files;t1:`t[]
1@"\ntime: ",($-1000!t1-t0),"ms\n";
\
