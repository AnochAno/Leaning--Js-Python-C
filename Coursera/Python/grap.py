import matplotlib.pyplot as plt


x = [0, 2, 3, 4, 5]
y = [2, 4, 6, 1, 10]


plt.plot(x, y, label='Sample Line')


plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.title('Simple Graph in Python')


plt.legend()


plt.show()
