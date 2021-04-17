import serial
import matplotlib.pyplot as plt
import numpy as np
#from serial import Serial
plt.ion()
#fig=plt.figure()
i=0
x=list()
y=list()
i=0
ser = serial.Serial('COM3',57600)
ser.close()
ser.open()
while True:

    data = ser.readline()
    print(data)
    #print(data.decode())
    x.append(i)
    y.append(data.decode())
    #y.append(data)

    plt.plot(y)
    i += 1
    plt.show()
    plt.pause(0.0001)  # Note this correction
