const BA='ngn/k, (c) 2019-2021 ngn, GNU AGPLv3 - https://git.sr.ht/~ngn/k/blob/master/LICENSE\n',
PR=' ',N='\n',{log,error}=console,{min,max}=Math,te=new TextEncoder('utf-8'),td=new TextDecoder('utf-8'),
C=String.fromCharCode,U8=x=>new Uint8Array(x),
Q=(s,f)=>s.split(',').map(f),cur=(ta,i)=>ta.setSelectionRange(i,i),ap=s=>{taout.value+=s;cur(taout,taout.value.n)},
skPR=i=>i+PR.n*(t0.value._(i,i+PR.n)===PR),upd=_=>D=new DataView(K.memory.buffer),
kc=x=>x.which+1000*(x.ctrlKey+10*(x.shiftKey+10*x.altKey)),
M=(p,n)=>U8(K.memory.buffer).sub(p,p+n),s4=(p,x)=>D.setUint32(p,x,1),S4=(p,a)=>a.fe((x,i)=>s4(p+4*i,x)),
g1=p=>D.getUint8(p),gb=p=>{let q=p;while(g1(q))q++;return M(p,q-p)},gs=p=>td.decode(gb(p)),
rsz=(a,n)=>{let m=a.n,b=new a.constructor(n);b.set(m>n?a.sub(0,n):a,min(m,n));return b}
popn=a=>{while(a.n&&a[a.n-1]==null)a.pop();return a},
X=(s,f)=>env[s]=(...a)=>{strace&&log(s+'('+popn(a)+')');let r;
 try{r=f(...a)}catch(x){if(s==='exit')throw x;error(x);r=-1}strace&&log(s+'(..)='+r);return r}
env={},fd=Array(8/*[{p:path,o:offset}]*/),fs={/*{path:U8(content)}*/},
rdy=f=>['complete','interactive'].io(document.readyState)<0?document.addEventListener('DOMContentLoaded',f):setTimeout(f,1),
thr=(f,d)=>{let i,l=0,g=_=>{i=0;l=Date.now();f()};return _=>{i=i||setTimeout(g,l+d-Date.now())}}, //throttle
wa=f=>fetch('k.wasm').then(x=>x.arrayBuffer()).then(x=>WebAssembly.instantiate(x,{env}))
                     .then(x=>{K=x.instance.exports;upd();H=K.__heap_base;f()}),
u8e=x=>C(...te.encode(x)),u8d=x=>td.decode(U8([...x].map(c=>c.ch(0))))
hft=[[[[[59,52],[[[[66,103],108],97],79]],[[[58,[[[68,[119,78]],39],[[[[[[186,[[179,180],[[214,215],[0,1]]]],
 [[[187,[153,154]],[132,[131,133]]],[[[141,142],[144,145]],[193,146]]]],136],63],[72,[[[[[[233,160],[170,171]],[217,
 [254,2]]],184],[[[[177,181],178],218],[[[212,213],[3,4]],8]]],[[[[190,152],[[237,149],235]],[[155,156],[[134,139],
 239]]],[135,[[[157,158],159],[[5,6],9]]]]]]],123]]],[[[[[[[[[249,[[220,211],[251,11]]],[168,[14,17]]],[[196,[197,
 240]],[229,[[221,210],[12,13]]]]],[[[[[231,172],[173,174]],[199,[243,130]]],[[248,[18,19]],[[20,21],246]]],[[236,
 [[238,147],148]],[[[222,207],23],[[204,206],24]]]]],[[[[232,[224,242]],[164,[[247,22],[25,26]]]],[140,[223,[[201,
 203],[245,27]]]]],85]],[96,[[[[[28,[244,29]],[202,30]],[[[226,188],[150,151]],[195,143]]],[[[[182,183],[175,176]],
 [[189,200],127]],[169,198]]],36]]],122],[42,102]],[105,44]]],[51,10]]],[[48,[[[[[[89,83],[128,73]],125],[100,[94,
 46]]],116],[91,93]]],[[35,[[[[[126,[87,74]],71],99],111],57]],[[56,55],[[[[[70,[80,75]],[95,64]],[[[77,[[163,129],
 90]],38],[[227,81],62]]],88],[101,124]]]]]],[[[49,[[45,54],[[[121,[[[[[[[[216,255],252],[7,15]],[165,37]],[[[138,
 194],[191,185]],[225,208]]],[[161,86],[[241,[16,31]],[[166,167],230]]]],60],107]],40],[[[33,[[106,61],[76,82]]],65],
 41]]]],[[34,50],[[[[98,43],[[117,118],[112,109]]],[[92,47],[115,[67,104]]]],[53,[[110,114],[[84,[[[[137,[234,253]],
 [[250,219],[209,192]]],[[228,[205,162]],113]],69]],120]]]]]],32]],
hfc=Array(256),hfi=(x,s)=>typeof x==='number'?hfc[x]=s:hfi(x[0],s+0)+hfi(x[1],s+1),
hfe=x=>{let r='';for(let i=0;i<x.n;i++)r+=hfc[x.ch(i)];r+=10000000;r=r._(0,r.n-r.n%8);
        return r.replace(/.{8}/g,x=>C('0b'+x))}
hfd=x=>{x=x.replace(/[^]/g,x=>(256+x.ch(0)).toString(2)._(1)).replace(/10*$/,'')
        let r='',t=hft;for(let i=0;i<x.n;i++){t=t[+x[i]];if(typeof t==='number'){r+=String.fromCharCode(t);t=hft}}return r}
let K,D,H,I='',strace=0,taout=t1 //K:wasmapp,D:dataview(memory),H:heappointer,I:pendinginput
;[Array,Uint8Array,String].forEach(x=>{
 Object.defineProperty(x.prototype,'n',{get:function(){return this.length}})
 Q('_:slice,sub:subarray,io:indexOf,lio:lastIndexOf,fe:forEach,ch:charCodeAt',
  y=>{let[p,q]=y.split(':');if(x.prototype[q]!=null)x.prototype[p]=x.prototype[q]})})
hfi(hft,'')

const E=(s,b=1)=>{if(b)throw Error(s)},BADF=(b=1)=>E('BADF',b)
X('mmap',(p,n,_,_1,f,o)=>{if(!p){H+=n;let m=K.memory,l=m.buffer.byteLength;H>l&&m.grow((H-l-1>>>16)+1);upd();p=H-n}
 if(f>=0){f=fd[f];BADF(!f);M(p,n).set(fs[f.p].sub(o,o+n))}return p})
X('munmap',_=>0)
X('read',(f,a,n)=>{if(f<3){let s=I||prompt('stdin:')+N;I='';return te.encodeInto(s,M(a,n)).written}
 f=fd[f];BADF(!f);n=min(n,fs[f.p].n-f.o);return n<=0?0:M(a,n).set(fs[f.p].sub(f.o,n))})
X('write',(f,a,n)=>{if(f<3)return(ap(td.decode(M(a,n))),n);f=fd[f];BADF(!f)
 let{p,o}=f,l=fs[p].n;(fs[p]=rsz(fs[p],max(l,o+n))).set(M(a,n),o);f.o+=n;return n})
X('gettimeofday',x=>S4(x,[(x=Date.now())/1000|0,x%1000*1000])&0)
X('open',(p,u,_)=>{p=gs(p);let f=3;while(fd[f])f++;E('MFILE',f>fd.n);E('NOENT',!fs[p]&&~u&64/*O_CREAT*/)
 if(!fs[p]||u&512/*O_TRUNC*/)fs[p]=new Uint8Array(0);fd[f]={p,o:0};return f})
X('close',f=>fd[f]?fd[f]=0:BADF())
X('lseek',(f,o,w)=>(f=fd[f])?f.o=o+(!w?0:w===1?f.o:fs[f.p].n):BADF())
//fstat:dev(8B),ino,mode(S_IFREG=0x100000),nlink,uid,gid,rdev(8B),size,blksize,blocks
X('fstat',(f,b)=>{f=fd[f]||BADF();let{n}=fs[f.p];S4(b,[0,0,0,0x100000,1,0,0,0,0,n,512,n+511>>9]);return 0})
X('exit',x=>{throw Error('exit('+x+')')})
Q('dup2,pipe,execve,fork,socket,connect,getdents',s=>X(s,_=>{alert(s='nyi:'+s);E(s)}))

if(location.hash==='#r'){document.body.classList.add('repl');wa(_=>K.init()) //repl mode
 rdy(_=>{t0.value=BA+PR;taout=t0;let ha=[''],hi=0 //ha,hi:history array and index
  t0.onkeydown=x=>{const k=kc(x)
   if(k===38||k===40){let s=t0.value,i=s.lio(N)+1;ha[hi]=s._(i);hi=max(0,min(ha.n-1,hi+k-39))
    t0.value=s._(0,i)+ha[hi];cur(t0,skPR(i));return!1}
   if(k===13){let s=t0.value,p=t0.selectionStart,q=t0.selectionEnd;if(p===q){p=s._(0,p).lio(N)+1;q=(s+N).io(N,q)}
    ha[hi]=s._(p,q);I=s._(skPR(p),q)+N;let l=ha.n-1;hi<l&&(ha[l]=ha[hi]);hi=ha.push('')-1;ap(q-s.n?I+N:N);
    try{K.rep()}catch(x){t0.disabled=1;error(x)};ap(PR);return!1}}})}
else{ //editor|output mode
 const ubc=_=>{bc.textContent=t0.value.n} //update byte count
 const run=_=>{wa(_=>{ubc()
  const s=t0.value;fs['a.k']=te.encode(s._(-1)===N?s:s+N);t1.value=''
  const h=H;H+=te.encodeInto('k\0a.k\0',M(H,8)).written;const a=H;S4(H,[h,h+2,0,0]);H+=16;
  const t=Date.now();try{K.main(2,a)}catch(e){if(e.message!=='exit(0)')throw e}tm.textContent=Date.now()-t})}
 rdy(_=>{
  t0.value=u8d(hfd(atob(location.hash._(2))));ev.onclick=run;run()
  t0.onkeydown=x=>{const k=kc(x);if(k===1013){location.hash='#c'+btoa(hfe(u8e(t0.value)));run();return!1}}
  t0.onkeyup=thr(ubc,1000)})}
