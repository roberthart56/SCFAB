```python
    import numpy as np
    import matplotlib.pyplot as plt

    #Data for P2.  Beta = 1.06.  Nearly symmetric.
    rps_1 = np.array([0.59, 0.81, 0.95, 1.16, 1.235, 1.29, 1.37, 1.48, 1.60, 1.82, 2.03, 2.27, 2.55, 2.72,
                      2.825, 3.00])
    times_1 = np.array([[1.0, 1.1, 1.1, 1.3, 0.9],
                        [1.3, 1.3, 1.1, 2.5, 1.1],
                        [1.1, 1.9, 1.1, 1.1, 1.1],
                        [2.7, 4.1, 2.4, 2.5, 2.4],
                        [6.4, 16.3, 7.5, 10.1, 16.0],
                        [18.9, 17.3, 17.2, 19.6, 19.9],
                        [27.5, 22.4, 22.7, 26.8, 22.2],
                        [40.0, 27.5, 31.3, 27.5, 29.3],
                        [26.2, 36.7, 25.1, 29.5, 36.5],
                        [24.0, 31.4, 37.7, 23.5, 28.8],
                        [26.7, 29.7, 46.8, 24.6, 35.5],
                        [28.9, 25.0, 21.3, 17.9, 31.6],
                        [48.4, 33.7, 27.2, 23.3, 30.6],
                        [23.2, 25.3, 32.2, 25.6, 17.5],
                        [27.2, 16.9, 31.3, 23.1, 19.4],
                        [18.2, 24.0, 25.3, 16.7, 20.3]])
    
    mean_times_1 = np.mean(times_1, axis = 1)
    error_bars_1 = np.std(times_1, axis = 1)/np.sqrt(5)
    #mean_times_1
    
    
    #Data for P3. Beta approx = 2.64
    rps_2 = np.array([0.66, 0.83, 0.96, 1.16, 1.23, 1.29, 1.40, 1.54, 1.68, 1.815, 2.03, 2.20, 2.50, 2.76, 3.00])
    times_2 = np.array([[1.5, 2.3, 1.9, 1.5, 1.9],
                        [1.5, 1.9, 1.6, 1.4, 1.5],
                        [1.7, 1.5, 2.4, 1.4, 1.5],
                        [2.0, 2.4, 2.1, 2.6, 2.1],
                        [10.2, 7.1, 7.5, 7.3, 10.3],
                        [11.6, 14.7, 14.5, 14.6, 11.6],
                        [18.6, 20.8, 19.0, 21.3, 21.5],
                        [21.8, 20.6, 22.2, 19.0, 21.5],
                        [27.5, 24.8, 27.6, 26.8, 29.9],
                        [28.2, 28.4, 29.2, 27.1, 31.3],
                        [25.7, 29.4, 24.9, 28.4, 24.7],
                        [28.7, 25.4, 30.1, 30.8, 27.9],
                        [20.8, 23.5, 24.3, 26.8, 24.8],
                        [23.1, 24.7, 25.2, 30.8, 23.2],
                        [26.1, 24.6, 25.1, 23.5, 21.7]])
    
    mean_times_2 = np.mean(times_2, axis = 1)
    error_bars_2 = np.std(times_2, axis = 1)/np.sqrt(5)
    #mean_times_2
    
   
    #mean_times_2
    
    #fig = plt.figure()
    fig = plt.figure(figsize=(12, 8))
    plt.title('Trapping time vs. frequency B=1.06(red) and B=2.64(blue)')
    plt.xlabel('Rotation speed (RPS)')
    plt.ylabel('Trapping time (s)')
    plt.errorbar(rps_1, mean_times_1,   yerr=error_bars_1, fmt='or')
    plt.errorbar(rps_2, mean_times_2,   yerr=error_bars_2, fmt='ob')
    #plt.errorbar(rps_3, mean_times_3,   yerr=error_bars_3, fmt='oy')
    
    #plt.plot(rps_1, mean_times_1, 'ro')
    
    plt.show()
```


    
![png](output_0_0.png)
    



```python

```
