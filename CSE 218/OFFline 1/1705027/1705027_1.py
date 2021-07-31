import numpy as np
from matplotlib import pyplot as plt

def func(x,num):
    k=np.arange(1,num+1)
    idx=-1
    s=0;
    for i in k :
        idx=-idx
        v=(x**i)/i
        s=s+(idx*v)
    return s

def builtinPlot():
    x=np.arange(-.9,1.1,0.1)
    #print(x)
    y=np.log(1+x)
    plt.figure(0)
    plt.plot(x,y,linewidth=1,color="red",label="Built-In ln(1+x)")

def plot():
    x=np.arange(-.9,1.1,0.1)
    a=func(x,1)
    b=func(x,3)
    c=func(x,5)
    d=func(x,20)
    e=func(x,50)
    
    plt.figure(0)
    plt.plot(x,a,linewidth=1,color="grey",label="NO of Terms:1")
    plt.plot(x,b,linewidth=1,color="yellow",label="NO of Terms:3")
    plt.plot(x,c,linewidth=1,color="pink",label="NO of Terms:5")
    plt.plot(x,d,linewidth=1,color="green",label="NO of Terms:20")
    plt.plot(x,e,linewidth=1,color="blue",label="NO of Terms:50")
    plt.legend(loc="lower right")
    plt.title("Graph of ln(1+x)")
    plt.xlabel("value of x")
    plt.ylabel("ln((1+x)")
    plt.grid(color="grey",dashes=[10,2,2,2])
    plt.savefig("fig.pdf")
    
def calError(c,p):
    e=((abs(c-p))/c)*100
    return e
    
def errorPlot():
    pa=0
    ca=0
    l=[]
    k=np.arange(1,51,1)
    #print(k)
    for i in k:
        pa=func(.5,i-1)
        ca=func(.5,i)
        #print(pa)
        #print(ca)
        l.append(calError(ca,pa))
    plt.figure(1)
    plt.plot(k,l,linewidth=2,label="Percentage Relative Error")
    plt.legend(loc="upper right")
    plt.xlabel("No of Terms")
    plt.ylabel("Relative Error in %")
    plt.title("Percentage Relative Error Graph")
    plt.grid(color="grey",dashes=[10,2,2,2])
    plt.savefig("fig2.pdf")
    
if __name__ == '__main__' :
    builtinPlot()
    plot()
    errorPlot()
