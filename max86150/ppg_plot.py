import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation


x=list()
ser = serial.Serial('COM3',57600)
ser.close()
ser.open()
plt.ion()
fig = plt.figure()
i=0
while True:
	data = ser.readline()
	x.append(data.decode())
	print(data.decode())
	plt.plot(i,data.decode(),'ok')
	#plt.plot(i,int(data.decode()),color='red',linewidth=3)
	#for point in data :
		#plt.plot(i,point)
	i += 1
	plt.show()
	plt.pause(0.1)


#data = ser.readline()
#ani = animation.FuncAnimation(fig, data.decode())
#plt.show()