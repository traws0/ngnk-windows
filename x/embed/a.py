#!/usr/bin/env python3
# https://gist.github.com/effbiae/8e0710bd689d2abfdc15cc432b0a52ad

# - a python3 translation of x/embed/a.c
# - does not work in python2
# $ make libk.so
# $ LD_LIBRARY_PATH=. python3 x/embed/a.py

from ctypes import *
import platform
os_name = platform.system()

if os_name.lower() == 'darwin':
  k=CDLL('libk.dylib')
else:
  k=CDLL('libk.so')

# declare the function signatures
K=c_void_p
K_p=POINTER(K)
K2f=CFUNCTYPE(K,K,K)
iK=k.iK;iK.restype=c_int;iK.argtypes=[K]
Ki=k.Ki;Ki.restype=K;    Ki.argtypes=[c_int]
KR=k.KR;KR.restype=K;    KR.argtypes=[c_char_p,K2f,c_int]
KC=k.KC;KC.restype=K;    KC.argtypes=[c_char_p,c_int]
K0=k.K0;K0.restype=K;    K0.argtypes=[K_p,c_char_p,K_p,c_int]

def add(x,y):
 print("add()")
 a=iK(x)
 b=iK(y)
 c=a+b
 return Ki(c)
addp=K2f(add)

def til(x):
 import numpy as np
 a=np.empty(x,np.int32)
 IK=k.IK;IK.argtypes=[np.ctypeslib.ndpointer(np.int32),K]
 b=(K*1)()     # args array
 b[0]=Ki(x)
 r=c_void_p()  # result
 IK(a,K0(byref(r),b"!:",b,1))
 return a

def main():
 print("kinit()"); k.kinit()
 print("KR()");    KR(b"add",addp,2)
 r=c_void_p()
 print("K0()");    K0(byref(r),b"`0:$add[2;3]",None,0)
 print("til(5)");  print(til(5))
 print("return");  return 0

if __name__=='__main__':
 main()
