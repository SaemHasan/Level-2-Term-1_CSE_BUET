import numpy as np
from matplotlib import pyplot as plt


def check(mat,column):
    for i in range(column-1):
        if mat[0][i]<0:
            return 0
    return 1
def MinIntercept(mat,row,column):
    for i in range(row):
        if mat[i][column-1]>0:
            Min=mat[i][column-1]
            idx=i
    for i in range(row):
        if mat[i][column-1]>0:
            if Min>mat[i][column-1]:
                Min=mat[i][column-1]
                idx=i
    return idx;
def SimplexMethod(var,slag,fun,a,b):
    fi=open("out2.txt","w");
    row=slag+1
    column=var+slag+3
    t=np.array(np.zeros([row,column],dtype=float))

    for i in range(row):
        for j in range(column):
            if j==0 and i ==0:
                t[i][j]=1
            elif j<var+1 and i==0:
                t[i][j]=-1*fun[j-1]
            elif i!=0 and j<var+1 and j!=0:
                t[i][j]=a[i-1][j-1]
            elif i!=0 and j==var+i:
                t[i][j]=1
            elif i!=0 and j==var+slag+1:
                t[i][j]=b[i-1]
            #t[i+1][var+slag+1]=b[i]
    #print("Z\tx1\tx2\ts1\ts2\ts3\ts4\tsolution Intercept")
    print("Z",end="\t")
    fi.write("Z\t")
    for i in range(var):
        print("x",i+1,end="\t")
        fi.write("x")
        fi.write(str(i+1))
        fi.write("\t")
    for i in range(slag):
        print("S",i+1,end="\t")
        fi.write("S")
        fi.write(str(i+1))
        fi.write("\t")
    print("Solution Intercept")
    fi.write("Soluton Intercept\n")
    for i in range(row):
        for j in range(column):
            fi.write("{0:.2f}".format(round(t[i][j],2)))
            fi.write("\t")
            print("{0:.2f}".format(round(t[i][j],2)),end="\t")
        print()
        fi.write("\n")
    fi.write("\n")
    print()
    itera=0
    while check(t,column)!=1:
        itera=itera+1
        print("Iteration : ",itera)
        mi=np.argmin(t[0])
        print(t[0][mi])
        for i in range(row):
            try:
                if t[i][mi]!=0:
                    t[i][column-1]=t[i][column-2]/t[i][mi]
                else:
                    t[i][column-1]=999999
            except ZeroDivisionError:
                t[i][column-1]=999999
        print("after dividing solution,we found intercept")
        fi.write("after dividing solution, found intercept\n")
        print("Z",end="\t")
        fi.write("Z\t")
        for i in range(var):
            print("x",i+1,end="\t")
            fi.write("x")
            fi.write(str(i+1))
            fi.write("\t")
        for i in range(slag):
            print("S",i+1,end="\t")
            fi.write("S")
            fi.write(str(i+1))
            fi.write("\t")
        print("Solution Intercept")
        fi.write("Soluton Intercept\n")
        for i in range(row):
            for j in range(column):
                fi.write("{0:.2f}".format(round(t[i][j],2)))
                fi.write("\t")
                print("{0:.2f}".format(round(t[i][j],2)),end="\t")
            print()
            fi.write("\n")
        fi.write("\n")
        print()
        mit=MinIntercept(t,row,column)
        print("min intercept : ",t[mit][column-1])
        print("after diving by min ",t[mit][mi])
        fi.write("min intercept : ")
        fi.write(str(t[mit][column-1]))
        fi.write("\n")
        fi.write("after diving by min ")
        fi.write(str(t[mit][mi]))
        fi.write("\n")
        d=t[mit][mi]
        for i in range(column):
            t[mit][i]=t[mit][i]/d
        print("Z",end="\t")
        fi.write("Z\t")
        for i in range(var):
            print("x",i+1,end="\t")
            fi.write("x")
            fi.write(str(i+1))
            fi.write("\t")
        for i in range(slag):
            print("S",i+1,end="\t")
            fi.write("S")
            fi.write(str(i+1))
            fi.write("\t")
        print("Solution Intercept")
        fi.write("Soluton Intercept\n")
        for i in range(row):
            for j in range(column):
                fi.write("{0:.2f}".format(round(t[i][j],2)))
                fi.write("\t")
                print("{0:.2f}".format(round(t[i][j],2)),end="\t")
            print()
            fi.write("\n")
        fi.write("\n")
        print()
        #print(t)
        for i in range(row):
            d=t[i][mi]
            print(" using gauss-jordan")
            fi.write(" using gauss-jordan")
            fi.write("\n")
            for j in range(column):
                d1=t[mit][j]
                if i != mit:
                    t[i][j]=t[i][j]+(-1*d)*d1
            print("Z",end="\t")
            fi.write("Z\t")
            for i in range(var):
                print("x",i+1,end="\t")
                fi.write("x")
                fi.write(str(i+1))
                fi.write("\t")
            for i in range(slag):
                print("S",i+1,end="\t")
                fi.write("S")
                fi.write(str(i+1))
                fi.write("\t")
            print("Solution Intercept")
            fi.write("Soluton Intercept\n")
            for i in range(row):
                for j in range(column):
                    fi.write("{0:.2f}".format(round(t[i][j],2)))
                    fi.write("\t")
                    print("{0:.2f}".format(round(t[i][j],2)),end="\t")
                print()
                fi.write("\n")
            fi.write("\n")
            print()
    print("\n\n")
    print("RESULT : \n")
    fi.write("RESULT : \n\n")
    print("MAX : ","{0:.2f}".format(round(t[0][column-2],2)))
    fi.write("MAX : ")
    fi.write("{0:.2f}".format(round(t[i][column-2],2)))
    fi.write("\n")
    
    for i in range(var):
        idx=1;
        for j in range(row):
            #print(i,j)
            if t[j][i+1]==1:
                #print(j,i+1,t[j][i+1]," 1 paisi")
                idx1=j
            if t[j][i+1] !=1 and t[j][i+1]!=0:
                #print(j,i+1,t[j][i+1],"onno value")
                idx=-1;
        if idx==1:
            print("x",i+1," : ","{0:.2f}".format(round(t[idx1][column-2],2)))
            fi.write("x")
            fi.write(str(i+1))
            fi.write(" : ")
            fi.write("{0:.2f}".format(round(t[idx1][column-2],2)))
            fi.write("\n")
        else:
            print("x",i+1," : ","0")
            fi.write("x")
            fi.write(str(i+1))
            fi.write(" : ")
            fi.write("{0:.2f}".format(round(0,2)))
            fi.write("\n")
    print("Iteration : ",itera )
    fi.write("Iteration : ")
    fi.write(str(itera))
    fi.write("\n")

def IntersectPoint(a,b):
    a1=float(a[0])
    b1=float(a[1])
    c1=float(a[2])
    
    a2=float(b[0])
    b2=float(b[1])
    c2=float(b[2])
    
    det=a1*b2-a2*b1
    if det==0:
        #print("no solution")
        return [-3,-3]
    else:
        x = (b2*c1 - b1*c2)/det
        y = (a1*c2 - a2*c1)/det
        return [x,y]
def InArea(p,c):    
    x=float(p[0])
    y=float(p[1])
    for i in range(len(c)-2):
        a1=float(c[i][0])
        b1=float(c[i][1])
        c1=float(c[i][2])
        
        if a1*x+b1*y > c1 or x<0 or y<0:
            return False
    return True

def findingAllpoint(c):
    f=[]
    for i in range(len(c)):
        for j in range(i+1,len(c)):
            p=IntersectPoint(c[i],c[j])
            area=InArea(p,c)
            if area==True:
                f.append(p)
                #print(p)
    return f
    
    
def plotting(c):
    a=np.array(c,dtype=float)
    M=np.amax(a)
    a1=np.amax(a,axis=1)
    #print(a1)
    for i in range(len(a1)):
        if a1[i]==M:
            idx=i
    a2=0
    a3=0
    if a[idx][0]!=0:    
        a2=M/a[idx][0]
    if a[idx][1]!=0:    
        a3=M/a[idx][1]
    if a2>a3:
        Max=a2
    elif a2<a3:
        Max=a3
    elif a2!=0 and a3!=0:
        Max=a2
    else:
        Max=M
    #print(Max)
    x= np.arange(-2,Max+1,0.1)
    y= np.arange(-2,Max+1,0.1)
    plt.xlim(-2,Max+1)
    plt.ylim(-2,Max+1)
    plt.hlines(0,-2,Max+1,color='k')
    plt.vlines(0,-2,Max+1,color='k')
    plt.grid(True)
    
    plt.xlabel('x-axis')
    plt.ylabel('y-axis')
    for i in range(len(c)-2):
        a1=float(c[i][0])
        b1=float(c[i][1])
        c1=float(c[i][2])
        if b1!=0 and a1!=0:
            y=(c1-a1*x)/b1
            s=str(a1)+"x"+"+"+str(b1)+"y"+"="+str(c1)
            #print(s)
            plt.plot(x,y,linewidth=1,color='red',label=s)
        elif b1==0 and a1!=0:
            y= np.arange(-2,Max+1,0.1)
            x=(c1-b1*y)/a1
            s=str(a1)+"x"+"="+str(c1)
            #print(s)
            plt.plot(x,y,linewidth=1,color='green',label=s)
        elif b1!=0 and a1==0:
            x= np.arange(-2,Max+1,0.1)
            y=(c1-a1*x)/b1
            s=str(b1)+"y"+"="+str(c1)
            plt.plot(x,y,linewidth=1,color='blue',label=s)
    plt.legend(loc="upper right")
def plotArea(c):
    plotting(c)
    f=findingAllpoint(c)
    def comp(X):
        ret=X[1]
        if(X[0]!=0):
            ret=-ret
        return [X[0],ret]
    f.sort(key=comp)
    #print(f)
    x=[]
    y=[]
    txt=[]
    for i in range(len(f)):
        x.append(f[i][0])
        y.append(f[i][1])
    for i in range(len(f)):
        f[i][0]='{0:.2f}'.format(f[i][0],2)
        f[i][1]='{0:.2f}'.format(f[i][1],2)
        str="("+f[i][0]+","+f[i][1]+")"
        txt.append(str)
    for i in range(len(f)):
        plt.annotate(txt[i], (x[i],y[i]))
    plt.fill_between(x,y)
    plt.savefig("area.pdf")

#main function
fi=open("in2.txt","r")
n=[]
n=fi.readline().split()
var=0;
fun=[]
for i in n:
    #print(i)
    fun.append(float(i))
    var=var+1
m=[]
c=[]
r=[]
slag=0
for i in fi:
    m=i.rsplit()
    #print(m)
    c.append(m)
    r.append(m[var])
    slag=slag+1
#print(c)
l =[[0 for x in range(var)] for y in range(slag)]
for i in range(slag):
    for j in range(var):
        l[i][j]=c[i][j]
#print(l)
SimplexMethod(var,slag,fun,l,r)
if var==2:
    c.append([1,0,0])
    c.append([0,1,0])    
    plotArea(c)
#print(c)