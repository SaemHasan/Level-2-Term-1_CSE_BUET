import numpy as np
from matplotlib import pyplot as plt

def LUDecompisition(mat,n,b):
    lower =[[0 for x in range(n)] for y in range(n)]
    upper =[[0 for x in range(n)] for y in range(n)]

    for i in range(n):
        for j in range(n):
            upper[i][j]=mat[i][j]
            lower[i][j]=mat[i][j]
    v=[]
    diByzero=-1
    for i in range(n):
        l=range(i)
        for k in l:
            if k<i:
                sum=0;
                d=upper[i][k]
                if upper[k][k]!=0:
                    v.append(d/upper[k][k])
                    for j in range(n):
                        sum=(upper[k][j]/upper[k][k])*d
                        upper[i][j]=upper[i][j]-sum
                else:
                    v.append(float("inf"))
                    upper[i][j]=float("inf")
                    diByzero=1
                    
    #print(v)
    m=0
    fi=open("out1.txt","w");
    for i in range(n):
        l=range(n)
        for k in l:
            if k==i:
                lower[i][k]=1
            if k>i:
                lower[i][k]=0
            if k<i:
                lower[i][k]=v[m]
                m=m+1
    if diByzero!=1:
        det=np.linalg.det(upper)
    else:
        det=0
    #print(det)
    #lower
    print("Lower")
    for i in range(n):
        for j in range(n):
            fi.write("{0:.4f}".format(round(lower[i][j],2)))
            fi.write(" ")
            print("{0:.4f}".format(round(lower[i][j],2)),end=" ")
            #print(upper[i][j],end="\t")
        print("")
        fi.write("\n")
    fi.write("\n")


    # Upper
    print("Upper")
    for i in range(n):
        for j in range(n):
            fi.write("{0:.4f}".format(round(upper[i][j],2)))
            fi.write(" ")
            print("{0:.4f}".format(round(upper[i][j],2)),end=" ")
            #print(upper[i][j],end="\t")
        print("")
        fi.write("\n")
    fi.write("\n")
    if det == 0 or diByzero==1:
        print()
        print("No unique solution")
        fi.write("No unique solution")
    elif det !=0:
        y=[0 for x in range(n)]
        for i in range(n):
            sub=0
            for j in range(i):
                sub=sub+lower[i][j]*y[j]
            y[i]=b[i]-sub
        
        
        x=[0 for x in range(n)]
        i=n-1
        while i>=0:
            k=n-1
            sub=0
            while k>i:
                sub=sub+upper[i][k]*x[k]
                k=k-1
            x[i]=(y[i]-sub)/upper[i][i]
            i=i-1
            
        print("Y:")
        for k in range(n):
            fi.write("{0:.4f}".format(round(y[k],2)))
            fi.write("\n")
            print("{0:.4f}".format(round(y[k],2)))
        fi.write("\n")
        
        print("X:")
        for k in range(n):
            fi.write("{0:.4f}".format(round(x[k],2)))
            fi.write("\n")
            print("{0:.4f}".format(round(x[k],2)))
        fi.write("\n")

#main function
fi=open("in1.txt","r")
#fl =fi.readlines()
n=int(fi.readline())
m=[]
for i in range(n):
    l=fi.readline().split()
    m.append([float(v) for v in l])
    
mat=[[0 for x in range(n)] for y in range(n)]
mat=m

m=[]

for i in range(n):
    m.append(float(fi.readline()))
b=m

LUDecompisition(mat,n,b); 
    

