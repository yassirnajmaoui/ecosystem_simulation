import numpy as np
import matplotlib.pyplot as plt

data = np.genfromtxt("data.csv", delimiter=",")
plt.plot(data[:,0], color="green", label="herbs")
plt.plot(data[:,1], color="blue", label="herbivores")
plt.plot(data[:,2], color="red", label="predators")
plt.legend()
plt.show()
