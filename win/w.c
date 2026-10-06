#define WIN32_LEAN_AND_MEAN //posix for mingw-w64, see w.h
#define _WIN32_WINNT 0x600
#include"w.h"
#include<windows.h>
#include<stdio.h>
#undef IN
#undef OUT
#undef open
#undef fstat
#include"a.h"
#define IP intptr_t
#define MP MAX_PATH
#define CH CloseHandle
#define BN _O_BINARY
#define MF (V*)-1               //mmap failed
#define hd(f) (HANDLE)_get_osfhandle(f)
#define ph(p) (HANDLE)(IP)(p)   //pid->process handle
#define fa(s) (GetFileAttributesA(s)+1)//0:missing
#define dr(a) ((a)&FILE_ATTRIBUTE_DIRECTORY)
#define sk(f,o) _lseeki64(f,o,0)
#define eq(a,b) !strcmp(a,b)
#define er(e) (errno=e,-1)
#define O(c) *q++=(c)

__attribute__((constructor))Z V ini(){_fmode=BN;F(3,I(i||!_isatty(0),_setmode(i,BN)))//console input stays text: \r\n->\n
 P(__argc-2||!eq(__argv[1],"-sh"))C b[32768]="\"";N n=1+fread(b+1,1,SZ b-3,stdin);W(n>1&&LH(10,b[n-1],13),n--)MC(b+n,"\"",2);//"k -sh" is /bin/sh (see wsp):
 FILE*f=_popen(b,"rt");I c;W((c=fgetc(f))!=EOF,putchar(c))exit(_pclose(f));}                                               //run stdin with cmd /c, \r\n->\n
#define ML(f) EX double(*__imp_##f)(double);double f(double x)_(__imp_##f(x))
ML(sin)ML(cos)ML(exp)ML(log)//msvcrt's libm: 4x faster and closer than mingw's x87 one
V*memmem(CO V*p,N m,CO V*q,N n)_(S s=p;W(m>=n,P(!memcmp(s,q,n),(V*)s)s++;m--)(V*)0)

Z ST{C*p;I f;N n;}ms;//the MAP_SHARED map, written back by munmap
V*mmap(V*a,N n,I p,I fl,I f,L o)_(I(!(fl&MAP_FIXED),P(!(a=VirtualAlloc(0,n,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE)),MF))P(f<0,a)P(sk(f,o)<0,MF)
 I(fl&MAP_SHARED,ms=(TY(ms)){a,f,n})C*s=a;W(n,L k=read(f,s,MIN(n,1<<30));P(k<=0,MF)s+=k;n-=k)a)
I munmap(V*a,N n)_(I(a==ms.p,sk(ms.f,0);write(ms.f,a,ms.n);ms.p=0)-!VirtualFree(a,0,MEM_RELEASE))

Z B fx(C*r,S s)_(N n=SL(s);P(n>MP-5,0)F(n+1,r[i]=s[i]=='/'?92:s[i])fa(r)||(MC(r+n,".exe",5),fa(r)))                    //r:path or path.exe
Z B de;Z V*dl(V*p)_(de=!p;p)
V*dlopen(S s,I f)_(C r[MP];dl(LoadLibraryA(fx(r,s)?r:s)))V*dlsym(V*l,S s)_(dl((V*)GetProcAddress(l,s)))
C*dlerror()_(Z C b[32];P(!de,(C*)0)de=0;sprintf(b,"winerror %lu",GetLastError());b)

I wop(S p,I f)_(I r=open(p,f,0666);U a=fa(p);r<0&&a&&dr(a-1)?_open_osfhandle((IP)CreateFileA(p,GENERIC_READ,7,0,OPEN_EXISTING,FILE_FLAG_BACKUP_SEMANTICS,0),0):r)//dirs via a handle
I wfs(I f,ST stat*s)_(I r=fstat(f,s);BY_HANDLE_FILE_INFORMATION i;I(!r&&GetFileInformationByHandle(hd(f),&i)&&dr(i.dwFileAttributes),s->st_mode=S_IFDIR)r)
DIR*fdopendir(I f)_(C b[MP];U n=GetFinalPathNameByHandleA(hd(f),b,MP,0);n-1<MP-1?opendir(b):0)

Z C c[32768],*q;Z V qa(S s){O('"');W(1,N b=0;W(*s==92,s++;b++)b=!*s?2*b:*s=='"'?2*b+1:b;F(b,O(92))B(!*s)O(*s++))O('"');O(32);}//msvcrt argv quoting
I wsp(C**a,I*p)_(N n=MP;C**v=a;W(*v,n+=2*SL(*v++)+3)P(n>SZ c,er(E2BIG))C r[MP],h[MP]={0},*e=0;FILE*f;S s;q=c;          //"fork": run a[0] with stdin p[0], stdout p[3]
 I(eq(*a,"/bin/sh"),GetModuleFileNameA(0,r,MP);e=r;strcpy(c,"k -sh"))
 E(I((f=fopen(*a,"rb")),fgets(h,MP,f);fclose(f))I(*h=='#'&&h[1]=='!'&&(s=strtok(h+2," \t\r\n")),P(!fx(r,s),er(ENOENT))e=r;qa(s))//#!interpreter
  E(I(strpbrk(*a,"/\\")&&fx(r,*a),e=r))W(*a,qa(*a++))q[-1]=0)
 F(2,SetHandleInformation(hd(p[3*i]),HANDLE_FLAG_INHERIT,1))PROCESS_INFORMATION o;                                       //callers close p[0] p[3] next
 STARTUPINFOA t={SZ t,.dwFlags=STARTF_USESTDHANDLES,.hStdInput=hd(*p),.hStdOutput=hd(p[3]),.hStdError=GetStdHandle(STD_ERROR_HANDLE)};
 P(!CreateProcessA(e,c,0,0,1,0,0,0,&t,&o),er(ENOENT))CH(o.hThread);(I)(IP)o.hProcess)
I wwt(I p)_(WaitForSingleObject(ph(p),INFINITE);-!CH(ph(p)))I wkl(I p)_(TerminateProcess(ph(p),9);wwt(p))
