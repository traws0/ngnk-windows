const BA='ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE\n',
PR=' ',NL='\n',{log}=console,{min,max}=Math,te=new TextEncoder('utf-8'),td=new TextDecoder('utf-8'),
Q=(s,f)=>s.split(',').map(f),cur=i=>ta.setSelectionRange(i,i),ap=s=>{ta.value+=s;cur(ta.value.n)},
skpp=i=>/*skipprompt*/i+PR.n*(ta.value._(i,i+PR.n)===PR),upd=_=>D=new DataView(K.memory.buffer),
M=(p,n)=>new Uint8Array(K.memory.buffer).sa(p,p+n),s4=(p,x)=>D.setUint32(p,x,1),S4=(p,a)=>a.forEach((x,i)=>s4(p+4*i,x)),
g1=p=>D.getUint8(p),gb=p=>{let q=p;while(g1(q))q++;return M(p,q-p)},gs=p=>td.decode(gb(p)),
rsz=(a,n)=>{let m=a.n,b=new a.constructor(n);b.set(m>n?a.sa(0,n):a,min(m,n));return b}
popn=a=>{while(a.n&&a[a.n-1]==null)a.pop();return a},E=(s,b=1)=>{if(b)throw Error(s)}
X=(s,f)=>env[s]=(...a)=>{strace&&log(s+'('+popn(a)+')');let r;
 try{r=f(...a)}catch(x){if(s==='exit')throw x;console.error(x);r=-1}strace&&log(s+'(..)='+r);return r}
env={},fd=Array(8/*[{p:path,o:offset}]*/),fs={/*{path:Uint8Array(content)}*/}
let K,D,H,I='',strace=0 //K:wasmapp,D:dataview(memory),H:heappointer,I:pendinginput
;[Array,Uint8Array,String].forEach(x=>{
  Object.defineProperty(x.prototype,'n',{get:function(){return this.length}})
  Q('_:slice,sa:subarray,io:indexOf,lio:lastIndexOf',
   y=>{let[p,q]=y.split(':');if(x.prototype[q]!=null)x.prototype[p]=x.prototype[q]})})

X('mmap',(p,n,_,_1,f,o)=>{if(!p){H+=n;let m=K.memory,l=m.buffer.byteLength;H>l&&m.grow((H-l-1>>>16)+1);upd();p=H-n}
 if(f>=0){f=fd[f];E('BADF',!f);M(p,n).set(fs[f.p].sa(o,o+n))}return p})
X('munmap',_=>0)
X('read',(f,a,n)=>{if(f<3){let s=I||prompt('stdin:')+NL;I='';return te.encodeInto(s,M(a,n)).written}
 f=fd[f];E('BADF',!f);n=min(n,fs[f.p].n-f.o);return n<=0?0:M(a,n).set(fs[f.p].sa(f.o,n))})
X('write',(f,a,n)=>{if(f<3)return(ap(td.decode(M(a,n))),n);f=fd[f];E('BADF',!f)
 let{p,o}=f,l=fs[p].n;(fs[p]=rsz(fs[p],max(l,o+n))).set(M(a,n),o);f.o+=n;return n})
X('gettimeofday',x=>S4(x,[(x=Date.now())/1000|0,x%1000*1000])&0)
X('open',(p,u,_)=>{p=gs(p);let f=3;while(fd[f])f++;E('MFILE',f>fd.n);E('NOENT',!fs[p]&&~u&64/*O_CREAT*/)
 if(!fs[p]||u&512/*O_TRUNC*/)fs[p]=new Uint8Array(0);fd[f]={p,o:0};return f})
X('close',f=>fd[f]?fd[f]=0:E('BADF'))
X('lseek',(f,o,w)=>(f=fd[f])?f.o=o+(!w?0:w===1?f.o:fs[f.p].n):E('BADF'))
X('exit',x=>{ta.disabled=1;alert(x='exit('+x+')');throw Error(x)})
Q('dup2,pipe,execve,fork,socket,connect',s=>X(s,_=>{alert(s='nyi:'+s);E(s)}))

fetch('k.wasm').then(x=>x.arrayBuffer()).then(x=>WebAssembly.instantiate(x,{env}))
 .then(x=>{K=x.instance.exports;upd();H=K.__heap_base;K.init();ta.disabled=0;ap(BA+PR);ta.focus()})

let ha=[''],hi=0 //history array and index
onload=_=>ta.onkeydown=x=>{if(!x.ctrlKey&&!x.shiftKey&&!x.altKey){const k=x.which
 if(k===38||k===40){let s=ta.value,i=s.lio(NL)+1;ha[hi]=s._(i);hi=max(0,min(ha.n-1,hi+k-39))
  ta.value=s._(0,i)+ha[hi];cur(skpp(i));return!1}
 if(k===13){let s=ta.value,p=ta.selectionStart,q=ta.selectionEnd
  if(p===q){p=s._(0,p).lio(NL)+1;q=(s+NL).io(NL,q)}
  ha[hi]=s._(p,q);I=s._(skpp(p),q)+NL
  let l=ha.n-1;hi<l&&(ha[l]=ha[hi]);hi=ha.push('')-1;ap(q-s.n?I+NL:NL);K.rep();ap(PR);return!1}}}
