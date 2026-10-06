#include<windows.h> //graphics for k through the ffi: a window showing a w*h list of 0xrrggbb ints, or a glsl fragment shader. see gdi.k, reticulum*.k
#include<GL/gl.h>
#include<stdlib.h>
#include<stdio.h>
#include"k.h"         //k.h types C I S F K... so only a few a.h-like macros here
#define Z static
#define SZ sizeof
#define _(a...) {return({a;});}
#define P(x,a...) if(x)_(a)
Z HWND hw;Z I w,h,*px,ev[6],mx,my;Z DWORD lt,t0;//ev: open,mouse x,mouse y,mouse buttons,key pressed since last poll,ms since win
Z BITMAPINFO bi={{SZ(BITMAPINFOHEADER),0,0,1,32}};
Z HDC dc;Z HGLRC rc;Z GLuint pg;Z GLint un[3];//gl mode: context, program, uniforms frame size mouse

Z LRESULT CALLBACK wp(HWND a,UINT m,WPARAM p,LPARAM l){RECT r;GetClientRect(a,&r);I cw=r.right?r.right:1,ch=r.bottom?r.bottom:1;//image is stretched to the window
 if(m>=WM_MOUSEMOVE&&m<=WM_MBUTTONDBLCLK)mx=(short)LOWORD(l),my=(short)HIWORD(l),ev[1]=mx*w/cw,ev[2]=my*h/ch,ev[3]=p&(MK_LBUTTON|MK_RBUTTON|MK_MBUTTON);
 if(m==WM_KEYDOWN)ev[4]=p;if(m==WM_DESTROY)wglMakeCurrent(0,0),wglDeleteContext(rc),rc=0,pg=0,hw=0;
 P(m==WM_PAINT,PAINTSTRUCT s;HDC d=BeginPaint(a,&s);if(!rc)SetStretchBltMode(d,COLORONCOLOR),StretchDIBits(d,0,0,cw,ch,0,0,w,h,px,&bi,DIB_RGB_COLORS,SRCCOPY);EndPaint(a,&s);0)
 return DefWindowProcA(a,m,p,l);}

K poll(K x)_(unref(x);MSG m;while(PeekMessageA(&m,0,0,0,PM_REMOVE))TranslateMessage(&m),DispatchMessageA(&m);ev[0]=!!hw;ev[5]=GetTickCount()-t0;K r=KI(ev,6);ev[4]=0;  //poll 0: ev, at most ~60/s
 DWORD n=GetTickCount()-lt;if(!rc&&n<16)Sleep(16-n);lt=GetTickCount();r)                                                                 //gl: vsync paces
K draw(K x)_(P(!hw,unref(x);KE("closed"))P(NK(x)!=(N)w*h,unref(x);KE("length"))IK(px,x);InvalidateRect(hw,0,0);UpdateWindow(hw);poll(Kv()))           //draw w*h#colors, then poll
K win(K x,K y,K z,K t)_(P(hw,unref(t);KE("open"))w=iK(x);h=iK(y);I k=iK(z);C s[256]={0};P(w<1||h<1||k<1||NK(t)>=SZ s,unref(t);KE("domain"))CK(s,t);//win[w;h;scale;title]
 free(px);px=calloc((N)w*h,4);bi.bmiHeader.biWidth=w;bi.bmiHeader.biHeight=-h;RECT r={0,0,w*k,h*k};
 WNDCLASSA c={CS_HREDRAW|CS_VREDRAW|CS_OWNDC,wp,0,0,GetModuleHandleA(0),0,LoadCursor(0,IDC_ARROW),0,0,"k"};RegisterClassA(&c);AdjustWindowRect(&r,WS_OVERLAPPEDWINDOW,0);
 t0=GetTickCount();hw=CreateWindowA("k",s,WS_OVERLAPPEDWINDOW|WS_VISIBLE,CW_USEDEFAULT,CW_USEDEFAULT,r.right-r.left,r.bottom-r.top,0,0,c.hInstance,0);poll(Kv()))

//gl mode: opengl32.dll ships with windows, the driver supplies glsl. the entry points past gl 1.1 come from wglGetProcAddress
#define G(r,f,a...) Z r(APIENTRY*f)(a);
#define GL G(GLuint,glCreateShader,GLenum)G(void,glShaderSource,GLuint,GLsizei,const char**,const GLint*)G(void,glCompileShader,GLuint)G(void,glGetShaderiv,GLuint,GLenum,GLint*)\
 G(void,glGetShaderInfoLog,GLuint,GLsizei,GLsizei*,char*)G(GLuint,glCreateProgram,void)G(void,glAttachShader,GLuint,GLuint)G(void,glLinkProgram,GLuint)G(void,glUseProgram,GLuint)\
 G(GLint,glGetUniformLocation,GLuint,const char*)G(void,glUniform1f,GLint,GLfloat)G(void,glUniform2f,GLint,GLfloat,GLfloat)G(BOOL,wglSwapIntervalEXT,int)
GL
#undef G
#define G(r,f,a...) f=(V*)wglGetProcAddress(#f);
Z S gl()_(P(rc,(S)0)dc=GetDC(hw);PIXELFORMATDESCRIPTOR f={SZ f,1,PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER,PFD_TYPE_RGBA,32};SetPixelFormat(dc,ChoosePixelFormat(dc,&f),&f);
 P(!(rc=wglCreateContext(dc))||!wglMakeCurrent(dc,rc),"opengl")GL P(!glCreateShader,"glsl")if(wglSwapIntervalEXT)wglSwapIntervalEXT(1);(S)0)//context on first glsl, vsync
K glsl(K x)_(P(!hw,unref(x);KE("closed"))S e=gl();P(e,unref(x);KE(e))N n=NK(x);C*s=malloc(n+14);memcpy(s,"#version 130\n",13);CK(s+13,x);s[n+13]=0;      //glsl src: compile fragment shader
 GLuint f=glCreateShader(0x8B30);glShaderSource(f,1,(const char**)&s,0);glCompileShader(f);free(s);GLint k;glGetShaderiv(f,0x8B81,&k);              //uniforms: frame size mouse, like specialk
 P(!k,C l[4096];glGetShaderInfoLog(f,SZ l,0,l);fputs(l,stderr);KE("glsl"))pg=glCreateProgram();glAttachShader(pg,f);glLinkProgram(pg);glUseProgram(pg);
 S u[]={"frame","size","mouse"};for(I i=0;i<3;i++)un[i]=glGetUniformLocation(pg,u[i]);Kv())
K shade(K x)_(P(!pg,unref(x);KE("glsl"))RECT r;GetClientRect(hw,&r);glViewport(0,0,r.right,r.bottom);glUniform1f(un[0],fK(x));unref(x);                //shade frame: draw one frame, then poll
 glUniform2f(un[1],r.right,r.bottom);glUniform2f(un[2],mx,r.bottom-my);glRecti(-1,-1,1,1);SwapBuffers(dc);poll(Kv()))

//vcos x, vsin x: simd cos/sin of floats for array code (k's go through libm one at a time). |error|<1e-10. needs -fno-trapping-math to vectorize floor
Z F cs(F x){F q=__builtin_floor(x*0.3183098861837907+0.5),r=x-q*3.141592653589793-q*1.2246467991473532e-16,y=r*r;                                  //x=q*pi+r, |r|<=pi/2
 return(1+y*(-1./2+y*(1./24+y*(-1./720+y*(1./40320+y*(-1./3628800+y*(1./479001600+y*(-1./87178291200.))))))))*(1-2*(q-2*__builtin_floor(q*0.5)));}//taylor to r^14, sign of q
__attribute__((noinline))Z V tv(F*restrict p,long n,F o){for(long i=0;i<n;i++)p[i]=cs(p[i]-o);}
Z K tr(K x,F o){Z C ta,ti,tg;if(!tg){K e[2]={Kf(0),Ki(0)},a=KL(e,2);tg=TK(a);ta=TK(e[0]);ti=TK(e[1]);unref(a);}                               //learn float/int atom, general list types
 C t=TK(x);if(t==ta||t==ti){F v=t==ta?fK(x):iK(x);unref(x);return Kf(cs(v-o));}N n=NK(x);                                                         //atom
 if(t==tg){K r=KL(0,n),*s=(K*)dK(x),*d=(K*)dK(r);for(N i=0;i<n;i++)d[i]=tr(ref(s[i]),o);unref(x);return r;}                                    //list of lists: each
 K r=KF(0,n);FK(dK(r),x);tv(dK(r),n,o);return r;}                                                                                       //numeric list
K vcos(K x)_(tr(x,0))
K vsin(K x)_(tr(x,1.5707963267948966))
