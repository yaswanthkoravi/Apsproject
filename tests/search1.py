import matplotlib.pyplot as plt
#inserting random values between 1-100000 and searching for element 100 repeatdely for different freqencies
x=[1,100,1000,10000]
y=[0.003,0.012,0.099,0.96]
x1=[1,100,1000,10000]
y1=[0.004,0.004,0.013,0.103]
plt.ylabel("Time(ms)")
plt.xlabel("frequency of search")
plt.title("Searching for a element repeatedly")
plt.plot(x,y,label="RB-Tree")
plt.plot(x1,y1,label="Splay-Tree")
plt.legend(loc="upper left")
plt.show()
