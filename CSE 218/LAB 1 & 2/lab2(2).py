def f(x):
    return x**2

def less_than_5(x):
    if(x<5):
        return True
    else:
        return False
    
k=range(0,10)
print(k)
l=[]
for i in k :
    l.append(f(i))
print(l[2])

m=list(map(f,k))
print(m)

n=list(filter(less_than_5,k))
print(n)

p=list(map(f,filter(less_than_5,k)))
print(p)
q=[x**2 for x in k]
print(q)
r=[x**3 for x in k if x<5]  #list comprehension
print(r)
