import matplotlib.pyplot as plt
y=["a","b","c"]
z=[0,0,1]
a=plt.pie([1,2,4],labels=y,explode=z)
plt.title("chart")
plt.xlabel("distance")
plt.ylabel("velocity")
plt.show()