import matplotlib.pyplot as plt
#deleteing random elements with given freqencies
x=[100,1000,5000,10000]
y=[0.085,0.835,3.95,8.53]
x1=[100,1000,5000,10000]
y1=[0.179,1.922,9.985,19.789]
plt.ylabel("Time(ms)")
plt.xlabel("frequency of Delete")
plt.title("Deleting random numbers")
plt.plot(x,y,label="RB-Tree")
plt.plot(x1,y1,label="Splay-Tree")
plt.legend(loc="upper left")
plt.show()