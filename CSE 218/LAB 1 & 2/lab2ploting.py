import numpy as np
from matplotlib import pyplot as plt

x=np.arange(0,5,0.1)
y=np.sin(x)
z=np.cos(x)

#font={}


plt.figure(figsize=(10,6))
plt.plot(x,y,linewidth=12,color="grey",label="sin",ls=':')
plt.plot(x,z,color="red",label="cos",dashes=[10,2,2,2,2,2])
#plt.scatter(x,z,s=5)
plt.legend(loc="upper left")
plt.title("Corelation of height and age")
plt.xlabel("Age of People")
plt.ylabel("Height")
plt.ylim(-1.1,1.5)
plt.grid(color="grey",dashes=[10,2,2,2])
plt.savefig("fig.pdf")
