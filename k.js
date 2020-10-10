let K,M,H,S,N='\n',O=_=>0,te=new TextEncoder('utf-8'),td=new TextDecoder('utf-8')
,uM=_=>M=new Uint8Array(K.memory.buffer)
,read=(_,a,n)=>{let s=S||prompt('stdin:')+N;S='';return te.encodeInto(s,M.subarray(a,a+n)).written}
,write=(_,a,n)=>{ta.value+=td.decode(M.subarray(a,a+n));let l=ta.value.length;ta.setSelectionRange(l,l);return n}
,mmap=(_,n)=>{H+=n;if(H>M.length){K.memory.grow((H-M.length-1>>>16)+1);uM()}return H-n}
WebAssembly.instantiateStreaming(fetch('k.wasm'),{env:{read,write,mmap,munmap:O,exit:O,hop:O,hcl:O,now:O,u0c:O,u1c:O,cmd:O,v0c:O,v1c:O,frk:O}})
           .then(x=>{K=x.instance.exports;uM();H=K.__heap_base;K.init()})
onload=_=>{ta.onkeydown=x=>{if(x.which===13){
 let s=ta.value+N,p=ta.selectionStart,q=ta.selectionEnd
 if(p===q){p=s.slice(0,p).lastIndexOf(N)+1;q+=s.slice(q).indexOf(N)+1}
 S=s.slice(p,q);ta.value+=q===s.length?N:S;K.rep();return!1}}}
