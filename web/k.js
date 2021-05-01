'use strict';const BA='ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE\n'
;[Array,Uint8Array,String].forEach(x=>{
 Object.defineProperty(x.prototype,'n',{get:function(){return this.length}})
 '_:slice,sub:subarray,io:indexOf,lio:lastIndexOf,fe:forEach,ch:charCodeAt'.split(',')
  .map(y=>{let[p,q]=y.split(':');if(x.prototype[q]!=null)x.prototype[p]=x.prototype[q]})})
const c1=x=>{let r='';for(let i=0;i<x.n;i++)r+=chr(x[i]);return r},
c0=x=>{const r=U8(x.n);for(let i=0;i<x.n;i++)r[i]=x.ch(i);return r},
T1=new TextEncoder,T0=new TextDecoder,t1=x=>T1.encode(x),t0=x=>T0.decode(x),z1=pako.deflate,z0=pako.inflate,
p1=x=>x?btoa(c1(z1(t1(x)))):'',p0=x=>{try{return x?t0(z0(c0(atob(x)))):''}catch(x){error(x);return''}},
{log,error}=console,{min,max}=Math,U8=x=>new Uint8Array(x),N='\n',chr=String.fromCharCode,
thr=(f,d)=>{let i,l=0,g=_=>{i=0;l=Date.now();f()};return _=>{i=i||setTimeout(g,l+d-Date.now())}},
doc=document,kc=x=>x.which+1000*(x.ctrlKey+10*(x.shiftKey+10*x.altKey)),
rdy=f=>['complete','interactive'].io(doc.readyState)<0?doc.addEventListener('DOMContentLoaded',f):setTimeout(f,1),
hsh=x=>x.split('').reduce((x,y)=>0|(x<<5)-x+y.ch(0),0),hex8=x=>('0000000'+x.toString(16))._(-8)

let kwasm,app,mem,heap,inp='',strace=0;const env={},fd=Array(8/*[{p:path,o:offset}]*/),fs={/*{path:U8(content)}*/},
uMem=_=>mem=new DataView(app.memory.buffer),M=(p,n)=>U8(app.memory.buffer).sub(p,p+n),g1=p=>mem.getUint8(p),
gb=p=>{let q=p;while(g1(q))q++;return M(p,q-p)},gs=p=>t0(gb(p)),ms=s=>{let p=ma(s.n);M(p,s.n).set(t1(s));return p},
s4=(p,x)=>mem.setUint32(p,x,1),S4=(p,a)=>a.fe((x,i)=>s4(p+4*i,x)),
ma=n=>{heap+=n;let m=app.memory,l=m.buffer.byteLength;heap>l&&m.grow((heap-l-1>>>16)+1);uMem();return heap-n},
rsz=(a,n)=>{const m=a.n,b=new a.constructor(n);b.set(m>n?a.sub(0,n):a,min(m,n));return b},
kstr=s=>s.replace(/[\0\t\n\r\"\\]/g,c=>'\\'+'0tnr"\\'['\0\t\n\r\"\\'.io(c)]),
wa=async f=>{if(!kwasm)kwasm=await(await fetch('k.wasm')).arrayBuffer()
 app=(await WebAssembly.instantiate(kwasm,{env})).instance.exports;uMem();heap=app.__heap_base;f()},
E=(s,b=1)=>{if(b)throw Error(s)},BADF=(b=1)=>E('BADF',b),popn=a=>{while(a.n&&a[a.n-1]==null)a.pop();return a},
X=(s,f)=>env[s]=(...a)=>{strace&&log(s+'('+popn(a)+')');let r;
 try{r=f(...a)}catch(x){if(s==='exit')throw x;error(x);r=-1}strace&&log(s+'(..)='+r);return r}
X('mmap',(p,n,_,_1,f,o)=>{p=p||ma(n);if(f>=0){f=fd[f];BADF(!f);M(p,n).set(fs[f.p].sub(o,o+n))}return p})
X('read',(f,a,n)=>{if(f<3){let s=inp||prompt('stdin:')+N;inp='';return T1.encodeInto(s,M(a,n)).written}
 f=fd[f];BADF(!f);n=min(n,fs[f.p].n-f.o);return n<=0?0:(M(a,n).set(fs[f.p].sub(f.o,n)),n)})
X('write',(f,a,n)=>{if(f<3)return(ap(t0(M(a,n))),n);f=fd[f];BADF(!f)
 let{p,o}=f,l=fs[p].n;(fs[p]=rsz(fs[p],max(l,o+n))).set(M(a,n),o);f.o+=n;return n})
X('gettimeofday',x=>S4(x,[(x=Date.now())/1000|0,x%1000*1000])&0)
X('open',(p,u,_)=>{p=gs(p);let f=3;while(fd[f])f++;E('MFILE',f>fd.n);E('NOENT:'+p,!fs[p]&&~u&64/*O_CREAT*/)
 if(!fs[p]||u&512/*O_TRUNC*/)fs[p]=new Uint8Array(0);fd[f]={p,o:0};return f})
X('lseek',(f,o,w)=>(f=fd[f])?f.o=o+(!w?0:w===1?f.o:fs[f.p].n):BADF())
//fstat:dev(8B),ino,mode(S_IFREG=0o100000),nlink,uid,gid,rdev(8B),size,blksize,blocks
X('fstat',(f,b)=>{f=fd[f]||BADF();let{n}=fs[f.p];S4(b,[0,0,0,0,1<<15,1,0,0,0,0,n,512,n+511>>9]);return 0})
X('munmap',_=>0);X('close',f=>fd[f]?fd[f]=0:BADF());X('exit',x=>{throw Error('exit('+x+')')})
'dup2,pipe,execve,fork,socket,setsockopt,connect,getdents'.split(',').map(s=>X(s,_=>{alert(s='nyi:'+s);E(s)}))

let out=ou;const PR=' ',skPR=i=>i+PR.n*(ed.value._(i,i+PR.n)===PR),cur=(ta,i)=>ta.setSelectionRange(i,i),
file=async f=>{fs[f]=fs[f]||t1(await(await fetch(f)).text())},ap=s=>{out.value+=s;cur(out,out.value.n)}
if(location.hash==='#r'){ //repl mode
 rdy(_=>{doc.body.classList.add('repl');ed.value='';out=ed;let ha=[''],hi=0 //ha,hi:history array and index
  wa(async _=>{await file('repl.k');await file('golf.k')
   let p=ms('k.wasm\0repl.k\0'),argv=ma(16);S4(argv,[p,p+7,0,0]);app.kinit(1,argv);inp='\\l repl.k\n';app.rep()})
  ed.onkeydown=x=>{const k=kc(x)
   if(k===38||k===40){let s=ed.value,i=s.lio(N)+1;ha[hi]=s._(i);hi=max(0,min(ha.n-1,hi+k-39))
    ed.value=s._(0,i)+ha[hi];cur(ed,skPR(i));return!1}
   if(k===13){let s=ed.value,p=ed.selectionStart,q=ed.selectionEnd;if(p===q){p=s._(0,p).lio(N)+1;q=(s+N).io(N,q)}
    ha[hi]=s._(p,q);inp=s._(skPR(p),q)+N;let l=ha.n-1;hi<l&&(ha[l]=ha[hi]);hi=ha.push('')-1;ap(q-s.n?inp+N:N);
    inp='repl.line"'+kstr(inp)+'";\n';try{app.rep()}catch(x){ed.disabled=1;error(x)};return!1}}})}
else{ //editor mode
 const ubc=_=>{let s=ed.value,i=s.io(N+N),r=[] //update byte count and return the counted part
  if(i>=0){s=s._(0,i);r.push('till empty line')}
  if(s._(0,2)==='f:'){s=s._(2);r.push('not counting initial "f:"')}
  bc.textContent=s.n+'bytes'+(r.n?`(${r.join(', ')})`:'');return s}
 rdy(_=>{ed.value=p0(location.hash._(1))
  ev.onclick=_=>{wa(async _=>{ubc();location.hash=p1(ed.value);await file('golf.k');await file('repl.k')
   const s='\\l golf.k\n'+ed.value;fs['a.k']=t1(s._(-1)===N?s:s+N);out.value=''
   const h=heap;heap+=T1.encodeInto('k\0a.k\0',M(heap,8)).written;const a=heap;S4(heap,[h,h+2,0,0]);heap+=16;
   const t=Date.now();try{app.main(2,a)}catch(e){if(e.message!=='exit(0)')throw e}tm.textContent=Date.now()-t})}
  cg.onclick=_=>{const s=ed.value,h='ngn-'+hex8(hsh(s)),g=ubc()
   out.value=`# [K (ngn/k)], ${g.n} bytes\n\n    ${g.replace(/\n/g,'\n    ')}\n\n[Try it online!][${h}]\n`+
    `\n[K (ngn/k)]: https://git.sr.ht/~ngn/k\n[${h}]: https://ngn.bitbucket.io/k#${p1(s)}\n`
   navigator.clipboard.writeText(out.value)}
  ed.onkeydown=x=>{const k=kc(x);if(k===1013){ev.onclick();return!1}if(k===1071){cg.onclick();return!1}}
  ed.onkeyup=thr(ubc,1000)
  ev.onclick()})}
