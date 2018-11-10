import matplotlib.pyplot as plt
#inserting elements in rb tree in ascending order
y=[0.38,0.659,0.93,1.27,6.604,48.468]
x=[500,1000,1500,2000,10000,100000]
#inserting elements into splay tree in ascending order
y1=[0.14,0.278,0.362,0.44,2.022,13.32]
x1=[500,1000,1500,2000,10000,100000]
plt.ylabel("Time(ms)")
plt.xlabel("No of points")
plt.title("Inserting numbers in ascending order")
plt.plot(x,y,label="RB-Tree")
plt.plot(x1,y1,label="Splay-Tree")
plt.legend(loc="upper left")
plt.show()
