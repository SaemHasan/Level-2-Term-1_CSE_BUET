import numpy as np
import math
from matplotlib import pyplot as plt

def func(x,y):
    s=((x+20.0*y)*(math.sin(x*y)))
    return s

def RKsecondOrder(x0,y0,end,h,a2,ck):
    x=x0
    y=y0
    a=1-a2
    p=1/(2*a2)
    q=1/(2*a2)
    #print(a2,p,q)
    px=[]
    py=[]
    px.append(x)
    py.append(y)
    while x<end:
        k1=func(x,y)
        k2=func(x+p*h,y+q*k1*h)
        y=y+(a*k1+a2*k2)*h
        x=x+h
        #x=float('{0:.2f}'.format(x,2))
        px.append(x)
        py.append(y)
    if ck==0:
        if h==.01:
            cl="black"
            lb="0.01 step size"
        elif h==.05:
            cl="green"
            lb="0.05 step size"
        elif h==.1:
            cl="blue"
            lb="0.1 step size"
        else:
            cl="red"
            lb="0.5 step size"
        if a2==(1.0/2.0):
            i=3
            ti="Heun's Method"
        elif a2==(1.0):
            i=4
            ti="Midpoint Method"
        else:
            i=5
            ti="Ralston's Method"
    else:
        if h==.01:
            i=6
            ti="Step Size 0.01"
        elif h==.05:
            i=7
            ti="Step Size 0.05"
        elif h==.1:
            i=8
            ti="Step Size 0.1"
        else:
            i=9
            ti="Step Size 0.5"
            
        if a2==(1.0/2.0):
            cl="green"
            lb="Heun's Method"
        elif a2==(1.0):
            cl="red"
            lb="Midpoint Method"
        else:
            cl="blue"
            lb="Ralston's Method"
    plt.grid(color='grey', linestyle=':', linewidth=1)
    plt.xlabel('value of x',fontsize=20)
    plt.ylabel('value of y',fontsize=20)
    plt.figure(i)
    plt.title(ti)
    plt.plot(px,py,linewidth=1,color=cl,label=lb)
    plt.legend(loc="best")
    return y

def Rkforth(x0,y0,end,h,ck):
    x=x0
    y=y0
    px=[]
    py=[]
    px.append(x)
    py.append(y)
    while x<end:
        k1=func(x,y)
        k2=func(x+0.5*h,y+0.5*k1*h)
        k3=func(x+0.5*h,y+0.5*k2*h)
        k4=func(x+h,y+k3*h)
        
        y=y+(1.0/6.0)*h*(k1+2.0*k2+2.0*k3+k4)
        x=x+h
        px.append(x)
        py.append(y)
    
    if ck==0:
        i=1
        ti="Rk Forth"
        if h==.01:
            cl="black"
            lb="0.01 step size"
        elif h==.05:
            cl="green"
            lb="0.05 step size"
        elif h==.1:
            cl="blue"
            lb="0.1 step size"
        else:
            cl="red"
            lb="0.5 step size"
    else:
        lb="Rk Forth Method"
        cl="black"
        if h==.01:
            i=6
            ti="Step Size 0.01"
        elif h==.05:
            i=7
            ti="Step Size 0.05"
        elif h==.1:
            i=8
            ti="Step Size 0.1"
        else:
            i=9
            ti="Step Size 0.5"
    plt.grid(color='grey', linestyle=':', linewidth=1)
    plt.xlabel('value of x',fontsize=20)
    plt.ylabel('value of y',fontsize=20)    
    plt.figure(i)
    plt.title(ti)
    plt.plot(px,py,linewidth=1,color=cl,label=lb)
    plt.legend(loc="best")
    return y

def EulerMethod(x0,y0,end,h,ck):
    x=x0
    y=y0
    px=[]
    py=[]
    px.append(x)
    py.append(y)
    while x<end:
        y=y+h*func(x,y)
        x=x+h
        px.append(x)
        py.append(y)
    if ck==0:
        i=2
        ti="Euler method"
        if h==.01:
            cl="black"
            lb="0.01 step size"
        elif h==.05:
            cl="green"
            lb="0.05 step size"
        elif h==.1:
            cl="blue"
            lb="0.1 step size"
        else:
            cl="red"
            lb="0.5 step size"
    else:
        lb="Euler Method"
        cl="grey"
        if h==.01:
            i=6
            ti="Step Size 0.01"
        elif h==.05:
            i=7
            ti="Step Size 0.05"
        elif h==0.1:
            i=8
            ti="Step Size 0.1"
        else:
            i=9
            ti="Step Size 0.5"
    plt.grid(color='grey', linestyle=':', linewidth=1)
    plt.xlabel('value of x',fontsize=20)
    plt.ylabel('value of y',fontsize=20)
    plt.figure(i)
    plt.title(ti)
    plt.plot(px,py,linewidth=1,color=cl,label=lb)
    plt.legend(loc="best")
    return y


#applying Euler
x0=0
y0=4
xn=10
EulerMethod(x0,y0,xn,0.01,0)
EulerMethod(x0,y0,xn,0.05,0)
EulerMethod(x0,y0,xn,0.1,0)
EulerMethod(x0,y0,xn,0.5,0)
#print(r1,r2,r3,r4)

#heun's Method
RKsecondOrder(x0,y0,xn,0.01,1/2,0)
RKsecondOrder(x0,y0,xn,0.05,1/2,0)
RKsecondOrder(x0,y0,xn,0.1,1/2,0)
RKsecondOrder(x0,y0,xn,0.5,1/2,0)
#print(r1,r2,r3,r4)

#midpoint method
RKsecondOrder(x0,y0,xn,0.01,1.0,0)
RKsecondOrder(x0,y0,xn,0.05,1.0,0)
RKsecondOrder(x0,y0,xn,0.1,1.0,0)
RKsecondOrder(x0,y0,xn,0.5,1.0,0)
#print(r1,r2,r3,r4)

#ralston's Method
RKsecondOrder(x0,y0,xn,0.01,2.0/3.0,0)
RKsecondOrder(x0,y0,xn,0.05,2.0/3.0,0)
RKsecondOrder(x0,y0,xn,0.1,2.0/3.0,0)
RKsecondOrder(x0,y0,xn,0.5,2.0/3.0,0)
#print(r1,r2,r3,r4)

#Rk 4th order
Rkforth(x0,y0,xn,.01,0)
Rkforth(x0,y0,xn,.05,0)
Rkforth(x0,y0,xn,.1,0)
Rkforth(x0,y0,xn,.5,0)
#print(r1,r2,r3,r4)

#step size 0.01
EulerMethod(x0,y0,xn,0.01,1)
RKsecondOrder(x0,y0,xn,0.01,1.0/2.0,1)
RKsecondOrder(x0,y0,xn,0.01,1.0,1)
RKsecondOrder(x0,y0,xn,0.01,2.0/3.0,1)
Rkforth(x0,y0,xn,.01,1)

#step size 0.05
EulerMethod(x0,y0,xn,0.05,1)
RKsecondOrder(x0,y0,xn,0.05,1.0/2.0,1)
RKsecondOrder(x0,y0,xn,0.05,1.0,1)
RKsecondOrder(x0,y0,xn,0.05,2.0/3.0,1)
Rkforth(x0,y0,xn,.05,1)

#step size 0.1
EulerMethod(x0,y0,xn,0.1,1)
RKsecondOrder(x0,y0,xn,0.1,1.0/2.0,1)
RKsecondOrder(x0,y0,xn,0.1,1.0,1)
RKsecondOrder(x0,y0,xn,0.1,2.0/3.0,1)
Rkforth(x0,y0,xn,0.1,1)

#step size 0.5
EulerMethod(x0,y0,xn,0.5,1)
RKsecondOrder(x0,y0,xn,0.5,1.0/2.0,1)
RKsecondOrder(x0,y0,xn,0.5,1.0,1)
RKsecondOrder(x0,y0,xn,0.5,2.0/3.0,1)
Rkforth(x0,y0,xn,0.5,1)




