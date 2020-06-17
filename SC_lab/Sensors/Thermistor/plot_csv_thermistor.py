import numpy as np
import matplotlib.pyplot as plt

#data_file = "/Users/roberthart/Documents/Python/example.csv" 
data_file = "/Users/roberthart/Documents/Python/thermistor_10K_NTC.csv" 

data_set = np.loadtxt(data_file, delimiter=',')
T = data_set[:,0]
R = data_set[:,1]

z = np.polyfit(R, T, 3)
p = np.poly1d(z)
pfit=p(R)

plt.plot(R, T, 'ro')
#plt.plot(R,pfit)
plt.xlabel('R (Ohm)')
plt.ylabel('T (degree Celcius)')
plt.title('Thermistor Data for 10K NTC')
plt.show