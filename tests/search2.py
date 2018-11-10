import matplotlib.pyplot as plt
#searching random elements for differnt freqencies
x=[100,1000,5000,10000]
y=[0.025,0.303,1.587,3.497]
x1=[100,1000,5000,10000]
y1=[0.05,0.656,4.23,9.58]
plt.ylabel("Time(ms)")
plt.xlabel("frequency of search")
plt.title("Searching random numbers")
plt.plot(x,y,label="RB-Tree")
plt.plot(x1,y1,label="Splay-Tree")
plt.legend(loc="upper left")
plt.show()
