let K,M,H,S
const N='\n',te=new TextEncoder('utf-8'),td=new TextDecoder('utf-8')
,uTA=_=>{let n=ta.value.length;ta.setSelectionRange(n,n)}
,uM=_=>M=new Uint8Array(K.memory.buffer)
,nyi=x=>(alert('nyi: '+x),-1)
,O=_=>0
,env={
  mmap:(_,n)=>{H+=n;if(H>M.length){K.memory.grow((H-M.length-1>>>16)+1);uM()}return H-n}
 ,read:(_,a,n)=>{let s=S||prompt('stdin:')+N;S='';return te.encodeInto(s,M.subarray(a,a+n)).written}
 ,write:(_,a,n)=>{ta.value+=td.decode(M.subarray(a,a+n));uTA();return n}
 ,open        :_=>nyi('open'        )
 ,close       :_=>nyi('close'       )
 ,lseek       :_=>nyi('lseek'       )
 ,dup2        :_=>nyi('dup2'        )
 ,pipe        :_=>nyi('pipe'        )
 ,execve      :_=>nyi('execve'      )
 ,munmap      :_=>nyi('munmap'      )
 ,fork        :_=>nyi('fork'        )
 ,exit        :_=>nyi('exit'        )
 ,gettimeofday:_=>nyi('gettimeofday')
 ,socket      :_=>nyi('socket'      )
 ,connect     :_=>nyi('connect'     )
 ,hop:O,hcl:O,now:O,u0c:O,u1c:O,cmd:O,v0c:O,v1c:O,frk:O}
WebAssembly.instantiateStreaming(fetch('k.wasm'),{env})
           .then(x=>{K=x.instance.exports;uM();H=K.__heap_base;K.init()})
onload=_=>{ta.onkeydown=x=>{if(x.which===13){
 let s=ta.value+N,p=ta.selectionStart,q=ta.selectionEnd
 if(p===q){p=s.slice(0,p).lastIndexOf(N)+1;q+=s.slice(q).indexOf(N)+1}
 S=s.slice(p,q);ta.value+=q===s.length?N:S;uTA();K.rep();return!1}}}
