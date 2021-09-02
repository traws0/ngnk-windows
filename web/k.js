'use strict' // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/blob/master/LICENSE
const{log,error}=console,{min,max}=Math,{now}=Date,U8=x=>new Uint8Array(x),doc=document,
T1=new TextEncoder,t1=x=>T1.encode(x),z1=pako.deflate,
T0=new TextDecoder,t0=x=>T0.decode(x),z0=pako.inflate,
c1=x=>{let r='';for(let i=0;i<x.length;i++)r+=String.fromCharCode(x[i]);return r},
c0=x=>{const r=U8(x.length);for(let i=0;i<x.length;i++)r[i]=x.charCodeAt(i);return r},
p0=x=>{try{return x?t0(z0(c0(atob(x)))):''}catch(x){error(x);return''}},
p1=x=>x?btoa(c1(z1(t1(x)))):'',
kc=x=>x.which+1000*(x.ctrlKey+10*(x.shiftKey+10*x.altKey)),
hsh=x=>x.split``.reduce((x,y)=>0|(x<<5)-x+y.charCodeAt(0),0),
hx8=x=>('0000000'+x.toString(16)).slice(-8),
rdy=f=>['complete','interactive'].indexOf(doc.readyState)<0?doc.addEventListener('DOMContentLoaded',f):setTimeout(f,1),
thr=(f,d)=>{let i,l=0,g=_=>{i=0;l=now();f()};return()=>i=i||setTimeout(g,max(1,l+d-now()))}

let kwasm,app,mem,heap,inp='',strace=0
const fd=Array(8/*[{p:path,o:offset}]*/),fs={/*{path:U8(content)}*/js:U8([])},
uMem=_=>mem=new DataView(app.memory.buffer),
M=(p,n)=>U8(app.memory.buffer).subarray(p,p+n),
g1=p=>mem.getUint8(p),
gb=p=>{let q=p;while(g1(q))q++;return M(p,q-p)},
gs=p=>t0(gb(p)),
s4=(p,x)=>mem.setUint32(p,x,1),
S4=(p,a)=>a.forEach((x,i)=>s4(p+4*i,x)),
ma=n=>{heap+=n;let m=app.memory,l=m.buffer.byteLength;heap>l&&m.grow((heap-l-1>>>16)+1);uMem();return heap-n},
ms=s=>{s=t1(s);let p=ma(s.length);M(p,s.length).set(s);return p},
wa=async f=>{if(!kwasm)kwasm=await(await fetch`k.wasm`).arrayBuffer()
 app=(await WebAssembly.instantiate(kwasm,{env})).instance.exports;uMem();heap=app.__heap_base;f()},
js_in=(a,n)=>{const s=inp||prompt`stdin:\n`;inp='';return T1.encodeInto(s,M(a,n)).written},
js_out=(a,n)=>(ap(t0(M(a,n))),n),
js_exit=x=>{throw Error('exit('+x+')')},
js_alloc=n=>{const p=4096,r=heap%p;r&&ma(p-r);return ma(n)},
js_time=now,
env={js_in,js_out,js_exit,js_alloc,js_time},
X=(s,f)=>env[s]=(...a)=>{if(strace){while(a.length&&a[a.length-1]==null)a.pop();log(s+'('+a+')')}let r
 try{r=f(...a)}catch(x){if(s==='exit')throw x;error(x);r=-1}strace&&log(s+'(..)='+r);return r},
E=(s,b=1)=>{if(b)throw Error(s)},BADF=(b=1)=>E('BADF',b),O_RDWR=2,O_CREAT=64,
rsz=(a,n)=>{const m=a.length,b=new a.constructor(n);b.set(m>n?a.subarray(0,n):a,min(m,n));return b}
X('open',(p,u,_)=>{p=gs(p);let f=3;while(fd[f])f++;E('MFILE',f>fd.length);E('NOENT:'+p,!fs[p]&&~u&O_CREAT)
 if(!fs[p]||u&512/*O_TRUNC*/)fs[p]=new Uint8Array(0);fd[f]={p,o:0};return f})
X('close',f=>fd[f]?fd[f]=0:BADF())
X('read',(f,a,n)=>{if(f<3)return js_in(a,n)
 f=fd[f];BADF(!f);n=max(0,min(n,fs[f.p].length-f.o));M(a,n).set(fs[f.p].subarray(f.o,f.o+n));f.o+=n;return n})
X('write',(f,a,n)=>{if(f<3)return js_out(a,n);f=fd[f];BADF(!f);let{p,o}=f,r=n;a=M(a,n)
 if(p==='js')a=t1(JSON.stringify(eval(t0(a)))||null)
 ;(fs[p]=rsz(fs[p],max(fs[p].length,o+a.length))).set(a,o);f.o=p==='js'?0:f.o+a.length;return r})
X('mmap',(p,n,_,_1,f,o)=>{p=p||ma(n);if(f>=0){f=fd[f];BADF(!f);M(p,n).set(fs[f.p].subarray(o,o+n))}return p})
X('munmap',_=>0)
X('lseek',(f,o,w)=>(f=fd[f])?f.o=o+(!w?0:w===1?f.o:fs[f.p].length):BADF())
//fstat:dev(8B),ino,mode(S_IFREG=0o100000),nlink,uid,gid,rdev(8B),size,blksize,blocks
X('fstat',(f,b)=>{f=fd[f]||BADF();let{n}=fs[f.p];S4(b,[0,0,0,0,1<<15,1,0,0,0,0,n,512,n+511>>9]);return 0})
X('gettimeofday',x=>S4(x,[(x=js_time())/1000|0,x%1000*1000])&0)
X('exit',x=>js_exit(x))
'dup2,pipe,execve,fork,socket,setsockopt,connect,getdents,chdir,ftruncate'.split`,`.map(s=>X(s,_=>{alert(s='nyi:'+s);E(s)}))

let out=ou;const PR=' ',skPR=i=>i+PR.length*(ed.value.slice(i,i+PR.length)===PR),cur=(ta,i)=>ta.setSelectionRange(i,i),
copy=x=>{let c=navigator.clipboard;c&&c.writeText(out.value)},ap=s=>{out.value+=s;cur(out,out.value.length)},
file=async f=>{fs[f]=fs[f]||t1(await(await fetch(f)).text())},
kstr=s=>s.replace(/[\0\t\n\r\"\\]/g,c=>'\\'+'0tnr"\\'['\0\t\n\r\"\\'.indexOf(c)])
if(location.hash==='#r'){ //repl mode
 rdy(_=>{doc.body.classList.add`repl`;ed.value='';out=ed;let ha=[''],hi=0 //ha,hi:history array and index
  wa(async _=>{await file`repl.k`;await file`LICENSE`
   let p=ms('k.wasm\0repl.k\0'),argv=ma(16);S4(argv,[p,p+7,0,0]);app.kinit(1,argv);inp='\\l repl.k\n';app.rep()})
  ed.onkeydown=x=>{const k=kc(x)
   if(k===38||k===40){let s=ed.value,i=s.lastIndexOf`\n`+1;ha[hi]=s.slice(i);hi=max(0,min(ha.length-1,hi+k-39))
    ed.value=s.slice(0,i)+ha[hi];cur(ed,skPR(i));return!1}
   if(k===13){let s=ed.value,p=ed.selectionStart,q=ed.selectionEnd
    if(p===q){p=s.slice(0,p).lastIndexOf`\n`+1;q=(s+'\n').indexOf('\n',q)}
    ha[hi]=s.slice(p,q);inp=s.slice(skPR(p),q)+'\n';let l=ha.length-1;hi<l&&(ha[l]=ha[hi]);hi=ha.push``-1
    ap(q-s.length?inp+'\n':'\n');inp=`repl.line@${inp.length-1?'':','}"${kstr(inp)}";\n`
    try{app.rep()}catch(x){ed.disabled=1;error(x)};return!1}}})}
else{ //editor mode
 const ubc=_=>{let s=ed.value,i=s.indexOf`\n\n`,r=[] //update byte count and return the counted part
  if(i>=0){s=s.slice(0,i);r.push`till empty line`}
  if(s.slice(0,2)==='f:'){s=s.slice(2);r.push`not counting initial "f:"`}
  bc.textContent=s.length+'bytes'+(r.length?`(${r.join`, `})`:'');return s}
 rdy(_=>{ed.value=p0(location.hash.slice(1).replace(/-$/,''));out.value=''
  btnEval.onclick=_=>{wa(async _=>{ubc();location.hash=p1(ed.value)+'-'
   const v=ed.value,s=v.slice(-1)==='\n'?v:v+'\n';out.value=''
   fs['a.k']='';const f=env.open(ms('a.k\0'),O_RDWR|O_CREAT,0o666);env.write(f,ms(s),s.length);env.close(f)
   const h=heap;heap+=T1.encodeInto('k\0a.k\0',M(heap,8)).written;const a=heap;S4(heap,[h,h+2,0,0]);heap+=16
   let e;try{app.main(2,a)}catch(x){e=x}
   location.hash=p1(ed.value);if(e&&e.message!=='exit(0)')throw e})}
  btnCGCC.onclick=_=>{const s=ed.value,h='ngn-'+hx8(hsh(s)),g=ubc()
   copy(out.value=`# [K (ngn/k)], ${g.length} bytes\n\n    ${g.replace(/\n/g,'\n    ')}\n\n[Try it online!][${h}]\n`+
    `\n[K (ngn/k)]: https://codeberg.org/ngn/k\n[${h}]: https://ngn.bitbucket.io/k#${p1(s)}\n`)}
  btnChat.onclick=_=>{const s=ed.value,g=ubc(),u=g.replace(/`/g,'\\`').replace(/\\$/,'\\ ')
   copy(out.value=`ngn/k, ${g.length} bytes: [\`${u}\`](https://ngn.bitbucket.io/k#${p1(s)})`)}
  ed.onkeydown=x=>{const b={1013:btnEval,1071:btnCGCC,1072:btnChat}[kc(x)];if(b){b.onclick();return!1}}
  ed.onkeyup=thr(ubc,1000)
  if(location.hash.slice(-1)!=='-')btnEval.onclick()})}
