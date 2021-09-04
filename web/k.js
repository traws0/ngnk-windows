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

let kwasm,app,mem,heap,inp=''
const uMem=_=>mem=new DataView(app.memory.buffer),
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
env={
 js_in:(a,n)=>{const s=inp||prompt`stdin:\n`;inp='';return T1.encodeInto(s,M(a,n)).written},
 js_out:(a,n)=>(ap(t0(M(a,n))),n),
 js_log:a=>console.info(t0(gb(a))),
 js_time:(a,b)=>{const t=now();s4(a,t/1000);s4(b,t%1000*1000)},
 js_exit:x=>{throw Error(`exit(${x})`)},
 js_alloc:n=>{const p=4096,r=heap%p;r&&ma(p-r);return ma(n)}}

let out=ou;const PR=' ',skPR=i=>i+PR.length*(ed.value.slice(i,i+PR.length)===PR),cur=(ta,i)=>ta.setSelectionRange(i,i),
copy=x=>{let c=navigator.clipboard;c&&c.writeText(out.value)},ap=s=>{out.value+=s;cur(out,out.value.length)},
kstr=s=>s.replace(/[\0\t\n\r\"\\]/g,c=>'\\'+'0tnr"\\'['\0\t\n\r\"\\'.indexOf(c)])
if(location.hash==='#r'){ //repl mode
 rdy(_=>{doc.body.classList.add`repl`;ed.value='';out=ed;let ha=[''],hi=0 //ha,hi:history array and index
  wa(_=>{let p=ms('k.wasm\0repl.k\0'),argv=ma(16);S4(argv,[p,p+7,0,0]);app.kinit(1,argv);inp='\\l repl.k\n';app.rep()})
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
  btnEval.onclick=_=>{wa(_=>{ubc();location.hash=p1(ed.value)+'-'
   const v=ed.value,s=v.slice(-1)==='\n'?v:v+'\n';out.value=''
   const f=app.open(ms('a.k\0'),0x0202/*O_RDWR|O_CREAT*/,0o666);app.write(f,ms(s),s.length);app.close(f)
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
