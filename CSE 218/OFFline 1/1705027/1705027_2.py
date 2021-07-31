import math
import numpy as np
from matplotlib import pyplot as plt

def func(x):
    if x<=-2:
        print("Minus inside the square root")
        return None
    if x==1:
        print("You are dividing by zero")
        return None
    a=(((x/(1-x))*math.sqrt(6/(2+x)))-0.05)
    return a

def graph_plot():
    x=np.arange(-1.99,1,0.01)
    l=[]
    for i in x:
        l.append(func(i))
    plt.plot(x,l,linewidth=1,color="red",label="Graph of func(x)")
    plt.legend(loc="upper left")
    plt.xlabel("value of x")
    plt.ylabel("value of function")
    plt.grid(color="grey",dashes=[10,2,2,2])
    plt.savefig("offline1_2.pdf")
    
def Secant_method(func,first_int,second_int,es, max_itr):
    i=0
    ea=1.1*es
    xl=first_int
    xu=second_int

    while ea>es and i<max_itr:
        try:   
            xr_old=xl
            xl=xu
            if func(xl) is None or func(xr_old) is None:
                print("Root is not found!!")
                return -1
            xu=xl-(func(xl)*(xr_old-xl))/(func(xr_old)-func(xl))
            ea=(abs((xu-xl)/xu))*100
            i=i+1
        except ZeroDivisionError:
            print("Sorry ! You are dividing by zero")
            print("Root is not found")
            return -1
        
    print("the root of the equation by Secant Method : ",xu)
    print("Number of Iteration in Secant method : ",i)
    print()
    

def False_Position(func,lower_bound,upper_bound,es,max_itr):
    i=0
    ea=1.1*es
    xl=lower_bound;
    xu=upper_bound;
    if func(xl) is None or func(xu) is None:
                print("Root is not found!!")
                return -1
    if (func(lower_bound) * func(upper_bound) >=0):
        print("Wrong Upper or lower Bound")
        print("Root is not found")
        return -1
    while ea>es and i<max_itr:
        try:
            if func(xl) is None or func(xu) is None:
                print("Root is not found!!")
                return -1
            xr=xu-(func(xu)*(xl-xu))/(func(xl)-func(xu))
            i=i+1
            if i!=1 and xr!=0:
                ea=(abs((xr-xr_old)/xr))*100
               # print("ea:",ea)
            t=func(xl)*func(xr)
            if t==0:
                ea=0
                #print("get it")
            elif t<0: 
                xu=xr
                xr_old=xr
            else:
                xl=xr
                xr_old=xr
        except ZeroDivisionError:
            print("Sorry ! You are dividing by zero")
            print("Root is not found")
            return -1
    print("the root of the equation by False position Method : ",xr)
    print("Number of Iteration in False position Method: ",i)
    print()
    #print(ea)


if __name__ == '__main__' :
    graph_plot()
    ui=input("Enter the lower bound for False Position Method :")
    ui2=input("Enter the lower bound for False Position Method :")
    try:
        l=float(ui)
        u=float(ui2)
        False_Position(func,l,u,.5,10000)
    except ValueError:
        print("Lower bound or Upper bound is not a number")
    
    ui=input("Enter the first initial guess for Secant Method :")
    ui2=input("Enter the second initial guess for Secant Method :")
    try:
        first=float(ui)
        second=float(ui2)
        Secant_method(func,first,second,.5,10000)
    except ValueError:
        print("Lower bound or Upper bound is not a number")