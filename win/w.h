#pragma once //posix for mingw-w64: every posix header mingw lacks is a one-line stub including this (see win/makefile, -Iwin)
#include<errno.h>
#include<io.h>
#include<fcntl.h>
#include<unistd.h>
#include<process.h>
#include<dirent.h>
#include<sys/stat.h>
#define PROT_READ 1
#define PROT_WRITE 2
#define MAP_SHARED 1
#define MAP_PRIVATE 2
#define MAP_FIXED 16
#define MAP_ANON 32
#define RTLD_LAZY 1
#define AF_INET 2
#define SOCK_STREAM 1
#define IPPROTO_TCP 6
#define TCP_NODELAY 1
#define RLIMIT_CPU 0
#define S_ISSOCK(m) 0
#define sysconf(x) 4096
#define pipe(p) _pipe(p,1<<16,_O_BINARY|_O_NOINHERIT)
#define fork() wsp((char**)a,p) //callers (i.c:frk, t/t.c:t) name argv "a" and pipes "p"; spawns the child, so their child branch is dead
#define execve(a...) -1
#define wait4(p,a...) wwt(p)
#define kill(p,s) wkl(p)
#define setrlimit(a...) (void)0
#define socket(a...) (errno=ENOSYS,-1)
#define setsockopt(a...) -1
#define connect(a...) -1
#undef fstat
#define fstat wfs
#define open(p,f,m...) wop(p,f)
typedef int socklen_t;struct sockaddr{int _;};struct sockaddr_in{short sin_family;unsigned short sin_port;struct{unsigned s_addr;}sin_addr;};struct rlimit{long rlim_cur,rlim_max;};
void*mmap(void*,size_t,int,int,int,long long),*dlopen(const char*,int),*dlsym(void*,const char*);char*dlerror(void);DIR*fdopendir(int);
int munmap(void*,size_t),wop(const char*,int),wfs(int,struct stat*),wsp(char**,int*),wwt(int),wkl(int);
