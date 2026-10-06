'use strict' // ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://codeberg.org/ngn/k/raw/branch/master/LICENSE
const{min,max}=Math,{now}=Date,U8=x=>new Uint8Array(x),doc=document,win=window,
T1=new TextEncoder,t1=x=>T1.encode(x),z1=pako.deflate,
T0=new TextDecoder,t0=x=>T0.decode(x),z0=pako.inflate,
c1=x=>{let r='';for(let i=0;i<x.length;i++)r+=String.fromCharCode(x[i]);return r},
c0=x=>{const r=U8(x.length);for(let i=0;i<x.length;i++)r[i]=x.charCodeAt(i);return r},
p0=x=>{try{return x?t0(z0(c0(atob(x)))):''}catch(x){console.error(x);return''}},
p1=x=>x?btoa(c1(z1(t1(x)))):'',
kc=x=>x.which+1000*(x.ctrlKey+10*(x.shiftKey+10*x.altKey)),
hsh=x=>x.split``.reduce((x,y)=>0|(x<<5)-x+y.charCodeAt(0),0),
hx8=x=>('0000000'+x.toString(16)).slice(-8),
rdy=f=>['complete','interactive'].indexOf(doc.readyState)<0?doc.addEventListener('DOMContentLoaded',f):setTimeout(f,1),
thr=(f,d)=>{let i,l=0,g=_=>{i=0;l=now();f()};return()=>i=i||setTimeout(g,max(1,l+d-now()))},
lz=x=>{let i=7,n,c,r=[],S=-(1<<31),R=(x,a,n)=>{for(let j=0;j<n;j++)r.push(x[a+j]);return n},h=_=>x[i++]|x[i++]<<8,C=_=>{if(c===15)do c+=x[i];while(x[i++]==255)},
           d=n=>{while(i<n){let t=x[i++];c=t>>4;C();i+=R(x,i,c);if(i<n){c=t&15;let o=r.length-h();C();R(r,o,4+c)}}}
       while(n=h()|h()<<16){n&S?i+=R(x,i,n&~S):d(i+n)};return new Uint8Array(r)},
size=x=>{const cs=win.getComputedStyle(x),
 textsize=()=>{const d=doc.createElement('span');d.style.font=cs.font;d.style.position='absolute';d.style.visibility='hidden'
  d.style.whiteSpace='pre';d.textContent='A';doc.body.appendChild(d);const bd=d.getBoundingClientRect(),wpx=bd.width,h1px=bd.height
  d.textContent='A\nA';const h2px=d.getBoundingClientRect().height;doc.body.removeChild(d);return[wpx,h2px-h1px]},
 scrlsize=()=>{const e=doc.createElement("div");e.style.width="100px";e.style.height="100px";e.style.overflow="scroll"
  e.style.position="absolute";e.style.top="-101px";doc.body.appendChild(e);
  const scrlw=ed.scrollHeight>ed.clientHeight?0:e.offsetWidth-e.clientWidth;doc.body.removeChild(e);return scrlw},
 wh=textsize();return[x.clientWidth-scrlsize(),x.clientHeight].map((x,i)=>Math.floor(x/wh[i]))},
lc=_=>{const cl=size(ed);K(`repl.lc(${cl[1]};${cl[0]});`);ed.scrollTop=ed.scrollHeight;}

let app,heap,inp=''
const kw=fetch`k.wasm.lz4`.then(x=>x.arrayBuffer()),
M=(p,n)=>U8(app.memory.buffer).subarray(p,p+n),
g1=p=>new DataView(app.memory.buffer).getUint8(p),
gb=p=>{let q=p;while(g1(q))q++;return M(p,q-p)},
gs=p=>t0(gb(p)),
s4=(p,x)=>new DataView(app.memory.buffer).setUint32(p,x,1),
S4=(p,a)=>a.forEach((x,i)=>s4(p+4*i,x)),
ma=n=>{heap+=n;let m=app.memory,l=m.buffer.byteLength;heap>l&&m.grow((heap-l-1>>>16)+1);return heap-n},
msn=s=>{s=t1(s);let p=ma(s.length);M(p,s.length).set(s);return[p,s.length]},
ms=s=>msn(s)[0],
wa=_=>kw.then(x=>WebAssembly.instantiate(lz(new Uint8Array(x)),{env})),
env={sin:Math.sin,cos:Math.cos,log:Math.log,exp:Math.exp,
 js_in:(a,n)=>{const s=inp||prompt`stdin:\n`;inp='';return T1.encodeInto(s,M(a,n)).written},
 js_out:(a,n)=>(ap(t0(M(a,n))),n),
 js_log:a=>console.log(t0(gb(a))),
 js_time:(a,b)=>{const t=now();s4(a,t/1000);s4(b,t%1000*1000)},
 js_exit:x=>{throw Error(`exit(${x})`)},
 js_alloc:n=>{const p=4096,r=heap%p;r&&ma(p-r);return ma(n)},
 js_eval:(a,m,r,n)=>T1.encodeInto(''+eval(t0(M(a,m))),M(r,n)).written}

let w=wa(),out=ou;const cur=(ta,i)=>ta.setSelectionRange(i,i),
cpy=x=>{let c=navigator.clipboard;c&&c.writeText(out.value)},ap=s=>{out.value+=s;cur(out,out.value.length)},
kst=s=>s.replace(/[\0\t\n\r\"\\]/g,c=>'\\'+'0tnr"\\'['\0\t\n\r\"\\'.indexOf(c)])
rdy(_=>{
 if(location.hash==='#r'){ //repl mode
  doc.body.classList.add`repl`;ed.value='';out=ed;let ha=[''],hi=0 //ha,hi:history array and index
  w.then(x=>{app=x.instance.exports;heap=app.__heap_base
   let p=ms('kw\0repl.k\0'),argv=ma(16);S4(argv,[p,p+3,0,0]);app.kinit();app.kargs(1,argv);K('\\l repl.k');lc()})
  ed.onkeydown=x=>{const k=kc(x),skp/*skip prompt*/=i=>i+(ed.value[i]===' ')
   if(k===38||k===40){let s=ed.value,i=s.lastIndexOf`\n`+1;ha[hi]=s.slice(i);hi=max(0,min(ha.length-1,hi+k-39))
    ed.value=s.slice(0,i)+ha[hi];cur(ed,skp(i));return!1}
   if(k===13){let s=ed.value,p=ed.selectionStart,q=ed.selectionEnd
    if(p===q){p=s.slice(0,p).lastIndexOf`\n`+1;q=(s+'\n').indexOf('\n',q)}
    ha[hi]=s.slice(p,q);inp=s.slice(skp(p),q)+'\n';let l=ha.length-1;hi<l&&(ha[l]=ha[hi]);hi=ha.push``-1
    ap(q-s.length?inp+'\n':'\n');inp=`repl.line@${inp.length-1?'':','}"${kst(inp)}";\n`
    try{app.rep();lc();}catch(x){ed.disabled=1;console.error(x)};return!1}}}
 else{ //editor mode
  const ubc=_=>{let s=ed.value,i=s.indexOf`\n\n`,r=[] //update byte count and return the counted part
   if(i>=0){s=s.slice(0,i);r.push`till empty line`}
   if(s.slice(0,2)==='f:'){s=s.slice(2);r.push`not counting initial "f:"`}
   bc.textContent=s.length+'bytes'+(r.length?`(${r.join`, `})`:'');return s}
  out.value='';ed.value=p0(location.hash.slice(1).replace(/-$/,''))
  const ev=s=>w.then(x=>{app=x.instance.exports;heap=app.__heap_base;txt();out.value='';ubc()
   const O_RDWR=2,O_CREAT=64/*512 on freebsd*/
   const f=app.open(ms('a.k\0'),O_RDWR|O_CREAT,438/*0666*/),[q,nq]=msn(s);app.write(f,q,nq);app.close(f)
   const h=heap,a=heap+=T1.encodeInto('k\0a.k\0',M(heap,8)).written;S4(a,[h,h+2,0,0]);heap+=16;
   let e;try{app.main(2,a)}catch(x){e=x}if(e&&e.message!=='exit(0)')throw e;w=wa()})
  const evp=_=>{const v=ed.value,s=v.slice(-1)==='\n'?v:v+'\n',p=p1(v);location.hash=p+'-';ev(s).then(_=>location.hash=p)}
  bEval.onclick=evp;if(location.hash.slice(-1)!=='-')evp()
  bGolf.onclick=_=>{const s=ed.value,h='ngn-'+hx8(hsh(s)),g=ubc()
   cpy(out.value=`# [K (ngn/k)], ${g.length} bytes\n\n    ${g.replace(/\n/g,'\n    ')}\n\n[Try it online!][${h}]\n`+
    `\n[K (ngn/k)]: https://codeberg.org/ngn/k\n[${h}]: ${location.origin}/k#${p1(s)}\n`)}
  bLink.onclick=_=>{const s=ed.value,g=ubc(),u=g.replace(/`/g,'\\`').replace(/\\$/,'\\ ')
   cpy(out.value=`ngn/k, ${g.length} bytes: [\`${u}\`](${location.origin}/k#${p1(s)})`)}
  bHelp.onclick=_=>{ev('`0:,/(,80#"-"),/:2_\'(&"--"~/:2#\'x)_x:0:"repl.k"\n').then(_=>setTimeout(_=>{out.scrollTop=0},1))}
  selEx.onchange=_=>{const v=selEx.selectedOptions[0].value
   if(v){fetch(v).then(x=>x.text()).then(x=>{ed.value=x;evp();selEx.blur()})}}
  ed.onkeydown=x=>{const b={1013:bEval,1071:bGolf,1075:bLink,112:bHelp}[kc(x)];if(b){b.onclick();return!1}}
  ed.onkeyup=thr(ubc,1000)}})

let cnv,g,iid,tid,aid,tickPeriod=50,aud
const pi=Math.PI,tau=2*pi,S=s=>ms(s+'\0'),K=s=>app.evs(S(s)),gg=s=>[app.ggp(S(s)),app.ggn(S(s))],
tick=_=>K('tick[]'),
draw=_=>{K('draw[]');tid=setTimeout(raf,40)},
play=pn=>{if(aud)aud.onpause();const u8=M(...pn),blob=new Blob([u8],{type:'audio/wav'}),aurl=URL.createObjectURL(blob)
 aud=new Audio(aurl);aud.controls=true;aud.onpause=aud.onended=_=>{aud.remove();ed.focus()};doc.body.appendChild(aud)
 aud.focus();aud.play().catch(aud.onpause);},
raf=_=>aid=requestAnimationFrame(draw),
hgr=_=>{if(g)return;doc.body.appendChild(cnv=doc.createElement('canvas'));g=cnv.getContext('2d')
 onresize();g.font='0.05px monospace';iid=setInterval(tick,tickPeriod);raf()
 onkeydown=onkeyup=e=>g&&K('k'+e.type[3]+'@'+e.keyCode)
 onkeypress=e=>{if(g){let c=e.charCode;K('kx@'+c);(c===10||c===13)&&K('kr@10');c===8&&K('kb@8')}}
 cnv.oncontextmenu=_=>!1
 cnv.onmousedown=cnv.onmouseup=cnv.onmousemove=
  e=>{const r=cnv.getBoundingClientRect(),x=(e.clientX-r.x)/r.width,y=(e.clientY-r.y)/r.height
   K('m'+e.type[5]+'@`xy`buttons!('+x+' '+y+';'+e.buttons+')')}},
txt=_=>{if(!g)return;cnv.parentNode.removeChild(cnv);clearInterval(iid);clearTimeout(tid);cancelAnimationFrame(aid)
 cnv=g=iid=tid=aid=null}

onresize=_=>{if(!cnv||!out)return;let s=cnv.style,e=out;s.left=e.offsetLeft+'px';s.top=e.offsetTop+'px'
 const f=g.font;const k=cnv.width=cnv.height=min(e.offsetWidth,e.offsetHeight);g.scale(k,k);g.font=f}
