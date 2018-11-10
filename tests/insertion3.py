import matplotlib.pyplot as plt
#inserting random elements in rb tree
y=[0.303,0.681,0.936,1.415,5.466,74.908]
x=[500,1000,1500,2000,10000,100000]
#inserting random elements into splay tree
y1=[0.634,1.458,2.587,3.378,13.822,121.55]
x1=[500,1000,1500,2000,10000,100000]
plt.ylabel("Time(ms)")
plt.xlabel("No of points")
plt.title("Inserting random numbers")
plt.plot(x,y,label="RB-Tree")
plt.plot(x1,y1,label="Splay-Tree")
plt.legend(loc="upper left")
plt.show()
