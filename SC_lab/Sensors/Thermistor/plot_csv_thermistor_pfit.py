import numpy as np
import matplotlib.pyplot as plt

#data_file = "/Users/roberthart/Documents/Python/example.csv" 
data_file = "/Users/roberthart/Documents/Python/thermistor_10K_NTC.csv" 

data_set = np.loadtxt(data_file, delimiter=',')
T = data_set[:,0]
R = data_set[:,1]

a1=3.354e-3
b1=2.5698e-4
rref = 10000

Tmod = 1/(a1 + b1*np.log(R/rref))

plt.plot(R, T, 'ro')

plt.xlabel('R (Ohm)')
plt.ylabel('T (degree Celcius)')
plt.title('Thermistor Data for 10K NTC')
plt.show