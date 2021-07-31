import numpy as np
from matplotlib import pyplot as plt

def showgraph(n,x,y,l):
    c=[]
    r=[]
    a1=np.array(x)
    a2=np.array(y)
    for i in range(n+1):
        m=[]
        p=[]
        for j in range(n+1):
           m.append(np.sum(a1**(i+j)))
        for k in range(l):
            p.append((a1[k]**i)*a2[k])
        c.append(m)
        a3=np.array(p)
        r.append(np.sum(a3))
    #print(c)
    #print(r)
    a=np.linalg.solve(c,r)
    #print(a)
    arr=np.array(a)
    return arr



fi=open("data.txt","r")
fl =fi.readlines()
#print(len(fl))
#l=len(fl)
m=[]
x=[]
y=[]
for i in range(len(fl)):
    l=fl[i].split()
    x.append(float(l[0]))
    y.append(float(l[1]))
plt.figure(figsize=(20,10))
#plt.grid(True)
plt.grid(color='grey', linestyle=':', linewidth=1)
mi=np.min(x)
ma=np.max(x)
mi1=np.min(y)
ma1=np.max(y)
plt.xlim(mi-2,ma+2)
plt.ylim(mi1-5,ma1+15)
plt.hlines(0,mi-2,ma+2,color='k')
plt.vlines(0,mi1-5,ma1+15,color='k')
plt.xlabel('value of x',fontsize=20)
plt.ylabel('value of y',fontsize=20)

plt.plot(x,y,".",linewidth=1,color='red',label="Points")

arr = np.array(x)
l=int(np.sum(arr**0))

ar=showgraph(1,x,y,l)

a=np.arange(mi,ma+2,0.01)
b=ar[0]+ar[1]*a
lb="y = "+str('{0:.2f}'.format(ar[0],2))+"+"+str('{0:.2f}'.format(ar[1],2))+"*x"
plt.plot(a,b,linewidth=1,color="green",label=lb)
mean=np.mean(y)
#print(mean)
s=[]
t=[]
for i in range(l):
    s.append((y[i]-mean)**2)
    d=ar[0]+ar[1]*x[i]
    t.append((y[i]-d)**2)
st=np.sum(np.array(s))
sr=np.sum(np.array(t))
r2=(st-sr)/st
r=r2**(1/2)

print("For Order 1 : ")
print("a0 : ",ar[0])
print("a1 : ",ar[1]) 
print(lb)
print()
print("r : ",r)
print()

ar=showgraph(2,x,y,l)
b=ar[0]+ar[1]*a+ar[2]*(a**2)
lb="y = "+str('{0:.2f}'.format(ar[0],2))+"+"+str('{0:.2f}'.format(ar[1],2))+"*x+"+str('{0:.2f}'.format(ar[2],2))+"*x^2"
#print(s)
plt.plot(a,b,linewidth=1,color="blue",label=lb)
s=[]
t=[]
for i in range(l):
    s.append((y[i]-mean)**2)
    d=ar[0]+ar[1]*x[i]+ar[2]*(x[i]**2)
    t.append((y[i]-d)**2)
st=np.sum(np.array(s))
sr=np.sum(np.array(t))
r2=(st-sr)/st
r=r2**(1/2)

print("For Order 2 :")
print("a0 : ",ar[0])
print("a1 : ",ar[1])
print("a2 : ",ar[2])
print(lb) 
print()
print("r : ",r)
print()

ar=showgraph(3,x,y,l)
b=ar[0]+ar[1]*a+ar[2]*(a**2)+ar[3]*(a**3)
lb="y = "+str('{0:.2f}'.format(ar[0],2))+"+"+str('{0:.2f}'.format(ar[1],2))+"*x+"+str('{0:.2f}'.format(ar[2],2))+"*x^2+"+str('{0:.2f}'.format(ar[3],2))+"*x^3"
plt.plot(a,b,linewidth=1,color="black",label=lb)
s=[]
t=[]
for i in range(l):
    s.append((y[i]-mean)**2)
    d=ar[0]+ar[1]*x[i]+ar[2]*(x[i]**2)+ar[3]*(x[i]**3)
    t.append((y[i]-d)**2)
st=np.sum(np.array(s))
sr=np.sum(np.array(t))
r2=(st-sr)/st
r=r2**(1/2)

print("For Order 3 :")
print("a0 : ",ar[0])
print("a1 : ",ar[1])
print("a2 : ",ar[2])
print("a3 : ",ar[3])
print(lb) 
print()
print("r : ",r)
print()

plt.legend(loc="upper right",fontsize=15)
plt.savefig("curve.pdf")
plt.show()