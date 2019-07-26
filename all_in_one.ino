//libraries
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include <Wire.h>
#include <SparkFunLIS3DH.h>
#include "SPI.h"

//Declarations&variables
//BLE state intiate
bool _BLEClientConnected = false;
//heartRateService variables
byte flags = 0b00111110;
byte bpm;
byte heart[8] = { 0b00001110, 60, 0, 0, 0 , 0, 0, 0};
//bodyTempServicevariables
byte tempFlag = 00;
byte t;
byte tempb[8]={00,0,0,0,0,0,0,0};
//ultravioletSensor variables
#define I2C_ADDR 0x38 //0x38 and 0x39
#define IT_1_2 0x0 //1/2T
#define IT_1   0x1 //1T
#define IT_2   0x2 //2T
#define IT_4   0x3 //4T
//HTS221 variables(temp&humidity)
#define Addr 0x5F
//LIS3DH sensor variables
LIS3DH myIMU( I2C_MODE, 0x18 );
int delai=1000;
//BLEServices
//heartRateService (Characteristics&Descriptors)
#define heartRateService BLEUUID((uint16_t)0x180D)
BLECharacteristic heartRateMeasurementCharacteristics(BLEUUID((uint16_t)0x2A37), BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor heartRateDescriptor(BLEUUID((uint16_t)0x2901));
//health thermometer(Characteristics&Descriptors)
#define healthThermService BLEUUID((uint16_t)0x1809)
BLECharacteristic healthThermMeasurementCharacteristics(BLEUUID((uint16_t)0x2A1C), BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor healthThermDescriptor(BLEUUID((uint16_t)0x2901));
BLECharacteristic measrementItervalOfTemp(BLEUUID((uint16_t)0x2A21), BLECharacteristic::PROPERTY_NOTIFY);
//veml6070
BLEDescriptor UVDescriptor(BLEUUID((uint16_t)0x2901));
BLECharacteristic UVCharacteristic(BLEUUID((uint16_t)0x2A76), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
//HTS221
BLEDescriptor HDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor TDescriptor(BLEUUID((uint16_t)0x2901));
BLECharacteristic HCharacteristic(BLEUUID((uint16_t)0x2A6F), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic TCharacteristic(BLEUUID((uint16_t)0x2A6E), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
//LIS3DH
BLEDescriptor xDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor yDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor zDescriptor(BLEUUID((uint16_t)0x2901));
BLECharacteristic XCharacteristic(BLEUUID((uint16_t)0x2FF1),BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic YCharacteristic(BLEUUID((uint16_t)0x2FF2),BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic ZCharacteristic(BLEUUID((uint16_t)0x2FF3),BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
// server callbacks // connection state
class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      _BLEClientConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      _BLEClientConnected = false;
    }
};
void InitBLE() {
  BLEDevice::init("IXIR");
  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());
// Create the BLE Service
  //create heartRateService
  BLEService *pHeart = pServer->createService(heartRateService);
  pHeart->addCharacteristic(&heartRateMeasurementCharacteristics);
  heartRateDescriptor.setValue("PPG value");
  heartRateMeasurementCharacteristics.addDescriptor(&heartRateDescriptor);
  heartRateMeasurementCharacteristics.addDescriptor(new BLE2902());
 // create healthThermService
 BLEService *pHT = pServer->createService(healthThermService);
 pHT->addCharacteristic(&healthThermMeasurementCharacteristics);
 pHT->addCharacteristic(&measrementItervalOfTemp);
 healthThermDescriptor.setValue("Temp value");
 healthThermMeasurementCharacteristics.addDescriptor(&healthThermDescriptor);
 healthThermMeasurementCharacteristics.addDescriptor(new BLE2902());
 //veml6070 service
 BLEService *pService = pServer->createService(BLEUUID((uint16_t)0x181A));//valid for HTS221 and veml6070 (envirenmental sensors)
 UVDescriptor.setValue("UV index value");
 UVCharacteristic.addDescriptor(&UVDescriptor);
 UVCharacteristic.addDescriptor(new BLE2902());
 pService->addCharacteristic(&UVCharacteristic);
 //HTS221 service
HDescriptor.setValue("Humidity 0 to 100%");
TDescriptor.setValue("Temperature -40-60°C");
HCharacteristic.addDescriptor(&HDescriptor);
TCharacteristic.addDescriptor(&TDescriptor);
HCharacteristic.addDescriptor(new BLE2902());
TCharacteristic.addDescriptor(new BLE2902());
//LIS3DH service
BLEService *pACC = pServer->createService(BLEUUID((uint16_t)0x2FF0));
xDescriptor.setValue("Xchar");
yDescriptor.setValue("Ychar");
zDescriptor.setValue("Zchar");
XCharacteristic.addDescriptor(&xDescriptor);
YCharacteristic.addDescriptor(&yDescriptor);
ZCharacteristic.addDescriptor(&zDescriptor);
XCharacteristic.addDescriptor(new BLE2902());
YCharacteristic.addDescriptor(new BLE2902());
ZCharacteristic.addDescriptor(new BLE2902());
pACC->addCharacteristic(&XCharacteristic);
pACC->addCharacteristic(&YCharacteristic);
pACC->addCharacteristic(&ZCharacteristic);
//add service to advertise
  pServer->getAdvertising()->addServiceUUID(heartRateService);
  pServer->getAdvertising()->addServiceUUID(healthThermService);
  pACC->addCharacteristic(&XCharacteristic);
  pACC->addCharacteristic(&YCharacteristic);
  pACC->addCharacteristic(&ZCharacteristic);
  pService->addCharacteristic(&HCharacteristic);
  pService->addCharacteristic(&TCharacteristic);
  pService->addCharacteristic(&UVCharacteristic);
  pService->start();
  pHeart->start();
  pHT->start();
  pACC->start();
  // Start advertising
  pServer->getAdvertising()->start();
}
void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Start");
  Wire.beginTransmission(I2C_ADDR);
  Wire.write((IT_1<<2) | 0x02);  Wire.beginTransmission(Addr);
    Wire.write(0x10);
    Wire.write(0x1B);
    Wire.beginTransmission(Addr);
    Wire.write(0x20);
    Wire.write(0x85);
    Wire.endTransmission();
    myIMU.begin();
  InitBLE();

}
void loop() {
  // put your main code here, to run repeatedly:
//heartRate&BodyTemp
bpm=random(60,190);
heart[1] = (byte)bpm;
Serial.println(bpm);
t=random(36,40);
Serial.println(t);
//byte t=(byte)temperatureh;
tempb[1]=(byte)t;
//veml6070
byte msb=0, lsb=0;
uint16_t uv;

Wire.requestFrom(I2C_ADDR+1, 1); //MSB
delay(1);
if(Wire.available())
  msb = Wire.read();

Wire.requestFrom(I2C_ADDR+0, 1); //LSB
delay(1);
if(Wire.available())
  lsb = Wire.read();

uv = (msb<<8) | lsb;
Serial.println(uv, DEC); //output in steps (16bit)
int uvindex=random(1,9);
Serial.println(uvindex);
//HTS221
unsigned int data[2];
unsigned int val[4];
unsigned int H0, H1, H2, H3, T0, T1, T2, T3, raw;

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
float fTemp = (cTemp * 1.8 ) + 32;
 //uint8_t* temper=(uint8_t*)cTemp;
int te=(int)(cTemp*100);
int h=(int)(humidity*100);
//uint8_t* hum=(uint8_t*)h;
HCharacteristic.setValue(h);
HCharacteristic.notify();
TCharacteristic.setValue(te);
TCharacteristic.notify();
// Output data to serial monitor
Serial.print("Relative humidity : ");
Serial.print(humidity);
Serial.println(" % RH");
Serial.print("Temperature in Celsius : ");
Serial.print(cTemp);
Serial.println(" C");
Serial.print("Temperature in Fahrenheit : ");
Serial.print(fTemp);
Serial.println(" F");
//LIS3DH
Serial.print("\nAccelerometer:\n");

float x=(myIMU.readFloatAccelX());
Serial.println(x,4);

float y=(myIMU.readFloatAccelY());
Serial.println(y,4);

float z=(myIMU.readFloatAccelZ());
Serial.println(z,4);
XCharacteristic.setValue(x);
XCharacteristic.notify();
YCharacteristic.setValue(y);
YCharacteristic.notify();
ZCharacteristic.setValue(z);
ZCharacteristic.notify();
//veml6070 update BLE
UVCharacteristic.setValue(uvindex);
UVCharacteristic.notify();
//max86150&max30205 update
 //update values and notify client of HR mesurements
  heartRateMeasurementCharacteristics.setValue(heart,8);
  heartRateMeasurementCharacteristics.notify();
//update values and notify client of HT mesurements
  healthThermMeasurementCharacteristics.setValue(tempb,8);
  healthThermMeasurementCharacteristics.notify();
//set temp delay
 measrementItervalOfTemp.setValue(delai);
 measrementItervalOfTemp.notify();
  delay(1000);
}
