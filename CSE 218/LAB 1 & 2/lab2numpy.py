import numpy as np

k=range(0,10)
np_array=np.array(k)
print(np_array)

np_array=np.arange(0,10,0.1)
print(np_array)

np_array=np.zeros(5)
print(np_array)

k=[[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
np_array=np.array(k)
print(np_array)
print(np_array.shape)

np_array=np.zeros((5,5))
print(np_array)

print(np_array[1,2])

k=[[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
np_array=np.array(k)
print(np_array[1,2])
print(np.dot(np_array,np_array.T))
print(np_array[0,:])
np_array[1,:]=np_array[1,:]-4*np_array[0,:]
print(np_array)