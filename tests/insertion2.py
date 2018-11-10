import matplotlib.pyplot as plt
#inserting elements in rb tree in descending order
y=[0.26,0.43,0.75,0.94,4.618,50.39]
x=[500,1000,1500,2000,10000,100000]
#inserting elements into splay tree in descending order
y1=[0.095,0.217,0.298,0.422,1.77,14.42]
x1=[500,1000,1500,2000,10000,100000]
plt.ylabel("Time(ms)")
plt.xlabel("No of points")
plt.title("Inserting numbers in descending order")
plt.plot(x,y,label="RB-Tree")
plt.plot(x1,y1,label="Splay-Tree")
plt.legend(loc="upper left")
plt.show()
