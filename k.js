const ba='ngn/k, (c) 2019-2020 ngn, GNU AGPLv3 - https://bitbucket.org/ngn/k/raw/master/LICENSE\n',pr=' ',
te=new TextEncoder('utf-8'),td=new TextDecoder('utf-8'),{min,max}=Math,
ap=s=>{ta.value+=s;let n=ta.value.length;ta.setSelectionRange(n,n)},
upd=_=>D=new DataView(K.memory.buffer),M=(p,n)=>new Uint8Array(K.memory.buffer).subarray(p,p+n),
g1=p=>D.getUint8(p),gb=p=>{let q=p;while(g1(q))q++;return M(p,q-p)},gs=p=>td.decode(gb(p)),
s4=(p,x)=>D.setUint32(p,x,1),S4=(p,a)=>{for(let i=0;i<a.length;i++)s4(p+4*i,a[i])},
rsz=(a,n)=>{let m=a.length,b=new a.constructor(n);b.set(m>n?a.subarray(0,n):a,min(m,n));return b}
E=x=>~console.error(x),N=x=>(alert(x='nyi:'+x),E(x)),log=x=>console.log(x),
popn=a=>{while(a.length&&a[a.length-1]==null)a.pop();return a},
S=(s,f)=>env[s]=(...a)=>{log(s+'('+popn(a)+')');let r=f(...a);log(s+'(..)='+r);return r} //strace
//S=(s,f)=>env[s]=f //no strace
fd=Array(8)/*[{p:path,o:offset}]*/,fs={}/*{path:Uint8Array(content)}*/,env={}
let K,D,H,I='' //K:wasmapp,D:dataview(memory),H:heappointer,I:pendinginput

S('mmap',(p,n,_,_1,f,o)=>{
 if(!p){H+=n;let m=K.memory,l=m.buffer.byteLength;if(H>l){try{m.grow((H-l-1>>>16)+1)}catch(e){return E('OOM')}}upd();p=H-n}
 if(f>=0){f=fd[f];if(!f)return E('BADF');let a=fs[f.p],b=M(p,n);for(let i=o;i<n;i++)b[i]=a[i]}return p})
S('munmap',_=>0)
S('read',(f,a,n)=>{if(f<3){let s=I||prompt('stdin:')+'\n';I='';return te.encodeInto(s,M(a,n)).written}
 f=fd[f];if(!f)return E('BADF');n=min(n,fs[f.p].length-f.o);return n<=0?0:M(a,n).set(fs[f.p].subarray(f.o,n))})
S('write',(f,a,n)=>{if(f<3)return(ap(td.decode(M(a,n))),n);f=fd[f];if(!f)return E('BADF')
 let{p,o}=f,l=fs[p].length;(fs[p]=rsz(fs[p],max(l,o+n))).set(M(a,n),o);f.o+=n;return n})
S('gettimeofday',x=>S4(x,[(x=Date.now())/1000|0,x%1000*1000])&0)
S('open',(p,u,_)=>{p=gs(p);let f=3;while(fd[f])f++;if(f>fd.length)return E('MFILE')
 if(!fs[p]&&~u&64/*O_CREAT*/)return E('NOENT')
 if(!fs[p]||u&512/*O_TRUNC*/)fs[p]=new Uint8Array(0)
 fd[f]={p,o:0};return f})
S('close',f=>fd[f]?fd[f]=0:E('BADF'))
S('lseek',(f,o,w)=>(f=fd[f])?f.o=o+(!w?0:w===1?f.o:fs[f.p].length):E('BADF'))
S('exit',x=>{alert(x='exit('+x+')');ta.disabled=1;throw Error(x)})
'dup2,pipe,execve,fork,socket,connect'.split(',').map(x=>S(x,_=>N(x)))

WebAssembly.instantiateStreaming(fetch('k.wasm'),{env})
           .then(x=>{K=x.instance.exports;upd();H=K.__heap_base;K.init();ta.disabled=0;ap(ba+pr);ta.focus()})
onload=_=>ta.onkeydown=x=>{if(x.which===13){
 let s=ta.value+'\n',p=ta.selectionStart,q=ta.selectionEnd
 if(p===q){p=s.slice(0,p).lastIndexOf('\n')+1;p+=pr.length*(s.slice(p,p+pr.length)===pr);q+=s.slice(q).indexOf('\n')+1}
 I=s.slice(p,q);ap(q===s.length?'\n':I);K.rep();ap(pr);return!1}}
