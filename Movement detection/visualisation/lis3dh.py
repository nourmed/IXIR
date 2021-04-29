import serial
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import os
import csv
import numpy as np

print("print recording name")
file_name=input()
print(file_name)
x=list()
labels=['millis','x','y','z']
ser = serial.Serial('COM3',115200)
ser.close()
ser.open()
#plt.ion()
#fig = plt.figure()
#i=0
#with open("{0}.csv".format(file_name),"w") as f :
#	csv_writer = csv.writer(f, delimiter=',')
#	csv_writer.writerow(labels)
while True :
	data = ser.readline()
	x.append(data.decode())
	with open("{0}.csv".format(file_name),"a") as f :
		f.writelines(data.decode())
		print(data.decode())
		#plottin =np.genfromtxt("{0}.csv".format(file_name),delimiter=",",names=["time","x","y","z"])
		#plt.plot(plottin['time'],plottin['x'])
		#plt.show()
		#csv_writer = csv.writer(f, delimiter=',')
		#csv_writer.writerow(data.decode())
		#serial_out=data.decode().split('\t')
		#print("time in millis :{0} x: {1} y: {2} z: {3}".format(serial_out[0],serial_out[1],serial_out[2],serial_out[3]))
#while True:
#	data = ser.readline()
#	x.append(data.decode())
#	#print(data.decode())
#	#print(x)
#	for lines in x :
#		serial_out=lines.split('\t')
#		with open("{0}.csv".format(file_name),"a") as f :
#			csv_writer = csv.writer(f, delimiter=',')
#			#csv_writer.writerow(labels)
#			csv_writer.writerow(serial_out)
#			#f.writelines("time in millis :{0} x: {1} y: {2} z: {3}".format(serial_out[0],serial_out[1],serial_out[2],serial_out[3]))
#			print("time in millis :{0} x: {1} y: {2} z: {3}".format(serial_out[0],serial_out[1],serial_out[2],serial_out[3]))
	#serial_out=(data.decode()).split("\t")
	#print("time in millis :{0} x: {1} y: {2} z: {3}".format(serial_out[0],serial_out[1],serial_out[2],serial_out[3])
	#plt.plot(i,data.decode(),'ok')
	#plt.plot(i,int(data.decode()),color='red',linewidth=3)
	#for point in data :
		#plt.plot(i,point)
	#i += 1
	#plt.show()
	#plt.pause(0.1)


#data = ser.readline()
#ani = animation.FuncAnimation(fig, data.decode())
#plt.show()