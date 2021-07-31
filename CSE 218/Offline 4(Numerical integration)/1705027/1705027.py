import numpy as np
from matplotlib import pyplot as plt
import matplotlib.patches as mpatches

def trapizoidal(x,f,idx):
    a=x[idx]
    b=x[idx+1]
    h=(b-a)/2.0
    i=h*(f[idx]+f[idx+1])
    
    return i

def simpson1by3(x,f,idx,n):
    a=x[idx]
    b=x[idx+n]
    h=(b-a)/(n*1.0)
    esum=0
    osum=0
    for k in np.arange(1,n,2):
        osum=osum+f[idx+k]
    for k in np.arange(2,n-1,2):
        esum=esum+f[idx+k]
    i=(h/3.0)*(f[idx]+4.0*osum+2.0*esum+f[idx+n])
    
    return i

def simpson3by8(x,f,idx,n):
    #print(idx,n)
    a=x[idx]
    b=x[idx+n]
    h=(b-a)/(n*1.0)
    esum=0.0
    osum=0.0
    osum1=0.0
    for k in np.arange(1,n-1,3):
        osum=osum+f[idx+k]
    for k in np.arange(2,n,3):
        esum=esum+f[idx+k]
    for k in np.arange(3,n-2,3):
        osum1=osum1+f[idx+k]
    
    i=((3.0*h)/8.0)*(f[idx]+3.0*osum+3.0*esum+2.0*osum1+f[idx+n])
    
    return i


#main function
fi=open("input.txt","r")
n=int(fi.readline())

x=[]
f=[]
itv=[]
for i in range(n):
    l=fi.readline().split()
    x.append(float(l[0]))
    f.append(float(l[1]))

for i in range(n-1):
    v='{0:.5f}'.format(abs(x[i+1]-x[i]),5)
    #print(v)
    itv.append(v)

plt.figure(figsize=(10,10))
plt.grid(color='grey', linestyle=':', linewidth=1)
mi=np.min(x)
ma=np.max(x)
mi1=np.min(f)
ma1=np.max(f)
plt.xlim(mi-1,ma+1)
plt.ylim(mi1,ma1)
plt.hlines(0,mi-2,ma+2,color='k')
plt.vlines(0,mi1-5,ma1+15,color='k')
plt.xlabel('value of x',fontsize=20)
plt.ylabel('value of y',fontsize=20)

plt.plot(x,f,linewidth=1,color='black')

for i in range(len(x)):
    plt.vlines(x[i],0,f[i])
    

i=0
s=0
t=0
s1=0
s3=0

while i<n-1:
    c=1
    for j in np.arange(i+1,n-1):
        if itv[i]==itv[j]:
            c=c+1
        else:
            break
    idx=i
    cn=c
    if c%3==0:
        kk=c
        ki=idx
        xc=[]
        yc=[]
        while c>0:
            for p in range(4):
                xc.append(x[idx+p])
                yc.append(f[idx+p])
            idx=idx+3
            c=c-3
            s3=s3+3
        if kk>2:
            s=s+simpson3by8(x,f,ki,kk)
            plt.fill_between(xc,yc,color="green")
            
    elif c%3==1:
        if c==1:
            xc=[]
            yc=[]
            for p in range(2):
                xc.append(x[idx+p])
                yc.append(f[idx+p])
            s=s+trapizoidal(x,f,idx)
            plt.fill_between(xc,yc,color="red")
            idx=idx+1
            c=c-1
            t=t+1
        
        kk=c-4
        ki=idx
        xc=[]
        yc=[]
        while c>4:
            for p in range(4):
                xc.append(x[idx+p])
                yc.append(f[idx+p])
            idx=idx+3
            c=c-3
            s3=s3+3
        if kk>4:
            s=s+simpson3by8(x,f,ki,kk)
            plt.fill_between(xc,yc,color="green")
        kk=c
        ki=idx
        xc=[]
        yc=[]
        while c>0:
            for p in range(3):
                xc.append(x[idx+p])
                yc.append(f[idx+p])
            idx=idx+2
            c=c-2
            s1=s1+2
        if kk>0:
            s=s+simpson1by3(x,f,ki,kk)
            plt.fill_between(xc,yc,color="grey")
    else:
        xc=[]
        yc=[]
        kk=c-2
        ki=idx
        while c>2:
            for p in range(4):
                xc.append(x[idx+p])
                yc.append(f[idx+p])
            idx=idx+3
            c=c-3
            s3=s3+3
        if kk>2:
            s=s+simpson3by8(x,f,ki,kk)
            plt.fill_between(xc,yc,color="green")
    
        xc=[]
        yc=[]
        for p in range(3):
            xc.append(x[idx+p])
            yc.append(f[idx+p])
        s=s+simpson1by3(x,f,idx,c)
        plt.fill_between(xc,yc,color="grey")
        idx=idx+2
        c=c-2
        s1=s1+2
        
    i=i+cn
    
gr=mpatches.Patch(color="green",label="3/8 Rule")
gy=mpatches.Patch(color="grey",label="1/3 Rule")
r=mpatches.Patch(color="red",label="Trapezoidal Rule")
plt.legend(handles=[gr,gy,r],fontsize=12)
plt.stem(x,f)
#plt.legend(loc="upper right",fontsize=15)
plt.savefig("graph.pdf")
plt.show()

print("Trapeziod: ",t," intervals")
print("1/3 rule: ",s1," intervals")
print("3/8 rule: ",s3," intervals")
print()
print("Integral value: ",s)
#print(s,t,s1,s3)