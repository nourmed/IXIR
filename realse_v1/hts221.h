#include <Wire.h>
#include <iostream>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

 int16_t Addr ;
 int arg1;


byte return_hts221( int16_t Addr,int arg1)
{
 byte value[8]={0,0,0,0,0,0,0,0};
  unsigned int data[2];
  unsigned int val[4];
  unsigned int H0, H1, H2, H3, T0, T1, T2, T3, raw;
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  //Serial.begin(115200);
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select average configuration register
  Wire.write(0x10);
  // Temperature average samples = 256, Humidity average samples = 512
  Wire.write(0x1B);
  // Stop I2C Transmission
  Wire.endTransmission();
 // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Select control register1
  Wire.write(0x20);
  // Power ON, Continuous update, Data output rate = 1 Hz
  Wire.write(0x85);
  // Stop I2C Transmission
  Wire.endTransmission();
  /////////////////////////////
  ///// void loop content//////
  ////////////////////////////
  // Humidity calliberation values
  for(int i = 0; i < 2; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Send data register
    Wire.write((48 + i));
    // Stop I2C Transmission
    Wire.endTransmission();

    // Request 1 byte of data
    Wire.requestFrom(Addr, 1);

    // Read 1 byte of data
    if(Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }

  // Convert Humidity data
  H0 = data[0] / 2;
  H1 = data[1] / 2;

  for(int i = 0; i < 2; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Send data register
    Wire.write((54 + i));
    // Stop I2C Transmission
    Wire.endTransmission();

    // Request 1 byte of data
    Wire.requestFrom(Addr,1);

    // Read 1 byte of data
    if(Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }
  // Convert Humidity data
  H2 = (data[1] * 256.0) + data[0];

  for(int i = 0; i < 2; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Send data register
    Wire.write((58 + i));
    // Stop I2C Transmission
    Wire.endTransmission();

    // Request 1 byte of data
    Wire.requestFrom(Addr,1);

    // Read 1 byte of data
    if(Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }
  // Convert Humidity data
  H3 = (data[1] * 256.0) + data[0];

  // Temperature calliberation values
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Send data register
  Wire.write(0x32);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr,1);

  // Read 1 byte of data
  if(Wire.available() == 1)
  {
    T0 = Wire.read();
  }

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Send data register
  Wire.write(0x33);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr,1);

  // Read 1 byte of data
  if(Wire.available() == 1)
  {
    T1 = Wire.read();
  }

  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Send data register
  Wire.write(0x35);
  // Stop I2C Transmission
  Wire.endTransmission();

  // Request 1 byte of data
  Wire.requestFrom(Addr, 1);

  // Read 1 byte of data
  if(Wire.available() == 1)
  {
    raw = Wire.read();
  }

  raw = raw & 0x0F;

  // Convert the temperature calliberation values to 10-bits
  T0 = ((raw & 0x03) * 256) + T0;
  T1 = ((raw & 0x0C) * 64) + T1;

  for(int i = 0; i < 2; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Send data register
    Wire.write((60 + i));
    // Stop I2C Transmission
    Wire.endTransmission();

    // Request 1 byte of data
    Wire.requestFrom(Addr,1);

    // Read 1 byte of data
    if(Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }
  // Convert the data
  T2 = (data[1] * 256.0) + data[0];

  for(int i = 0; i < 2; i++)
  {
    // Start I2C Transmission
    Wire.beginTransmission(Addr);
    // Send data register
    Wire.write((62 + i));
    // Stop I2C Transmission
    Wire.endTransmission();
    // Request 1 byte of data
    Wire.requestFrom(Addr,1);
    // Read 1 byte of data
    if(Wire.available() == 1)
    {
      data[i] = Wire.read();
    }
  }
  // Convert the data
  T3 = (data[1] * 256.0) + data[0];
  // Start I2C Transmission
  Wire.beginTransmission(Addr);
  // Send data register
  Wire.write(0x28 | 0x80);
  // Stop I2C Transmission
  Wire.endTransmission();
 // Request 4 bytes of data
  Wire.requestFrom(Addr,4);
  // Read 4 bytes of data
  // humidity msb, humidity lsb, temp msb, temp lsb
  if(Wire.available() == 4)
  {
    val[0] = Wire.read();
    val[1] = Wire.read();
    val[2] = Wire.read();
    val[3] = Wire.read();
  }
  // Convert the data
  float humidity = (val[1] * 256.0) + val[0];
  humidity = ((1.0 * H1) - (1.0 * H0)) * (1.0 * humidity - 1.0 * H2) / (1.0 * H3 - 1.0 * H2) + (1.0 * H0);
  int temp = (val[3] * 256) + val[2];
  int cTemp = (int)(((T1 - T0) / 8.0) * (temp - T2)) / (T3 - T2) + (T0 / 8.0);



value[0]=cTemp;
value[1]=humidity;
if ( arg1==1)
{ return value[0];
  }
  else if (arg1==2){return value[1];}



return 1;
}
