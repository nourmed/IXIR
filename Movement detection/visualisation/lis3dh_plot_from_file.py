#import matplotlib.pyplot as plt
#import matplotlib.animation as animation
#import os
#import csv
#import numpy as np
#
#plottin =np.genfromtxt("test_7.csv",delimiter=",",names=["time","x","y","z"])
#plt.plot(plottin['time'],plottin['x'],plottin['y'],plottin['z'])
#plt.show()

import pandas as pd
df = pd.read_csv('test_7.csv')
df.head()