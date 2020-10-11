let K,D,M,H,S
const N='\n',te=new TextEncoder('utf-8'),td=new TextDecoder('utf-8')
,uTA=_=>{let n=ta.value.length;ta.setSelectionRange(n,n)}
,uMD=_=>{let b=K.memory.buffer;M=new Uint8Array(b);D=new DataView(b)}
,s4=(x,y)=>D.setUint32(x,y,1)
,S4=(x,y)=>{for(let i=0;i<y.length;i++){s4(x,y);x+=4}}
,nyi=x=>(alert('nyi: '+x),-1)
,env={
  mmap:(_,n)=>{H+=n;if(H>M.length){try{K.memory.grow((H-M.length-1>>>16)+1);uMD()}catch(e){alert('OOM')}}return H-n}
 ,munmap:_=>0
 ,read:(_,a,n)=>{let s=S||prompt('stdin:')+N;S='';return te.encodeInto(s,M.subarray(a,a+n)).written}
 ,write:(_,a,n)=>{ta.value+=td.decode(M.subarray(a,a+n));uTA();return n}
 ,gettimeofday:x=>{let t=Date.now();S4(x,[t/1000|0,t%1000*1000]);return 0}
 ,open   :_=>nyi('open'   )
 ,close  :_=>nyi('close'  )
 ,lseek  :_=>nyi('lseek'  )
 ,dup2   :_=>nyi('dup2'   )
 ,pipe   :_=>nyi('pipe'   )
 ,execve :_=>nyi('execve' )
 ,fork   :_=>nyi('fork'   )
 ,exit   :_=>nyi('exit'   )
 ,socket :_=>nyi('socket' )
 ,connect:_=>nyi('connect')}
WebAssembly.instantiateStreaming(fetch('k.wasm'),{env})
 .then(x=>{K=x.instance.exports;uMD();H=K.__heap_base;K.init()})
onload=_=>{ta.onkeydown=x=>{if(x.which===13){
 let s=ta.value+N,p=ta.selectionStart,q=ta.selectionEnd
 if(p===q){p=s.slice(0,p).lastIndexOf(N)+1;q+=s.slice(q).indexOf(N)+1}
 S=s.slice(p,q);ta.value+=q===s.length?N:S;uTA();K.rep();return!1}}}
