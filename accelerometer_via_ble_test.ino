#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>
#include <SparkFunLIS3DH.h>
#include "Wire.h"
#include "SPI.h"

LIS3DH myIMU( I2C_MODE, 0x18 );
float x=0 , y=0 ,z=0;
bool _BLEClientConnected = false;
//#define accelerometerService BLEUUID((uint16_t)0x2FF0);
BLECharacteristic XaxisChar(BLEUUID((uint16_t)0x2FF1),BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic YaxisChar(BLEUUID((uint16_t)0x2FF2),BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic ZaxisChar(BLEUUID((uint16_t)0x2FF3),BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor AccelerometerDescriptor(BLEUUID((uint16_t)0x2901));

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

  BLEService *pACC = pServer->createService(BLEUUID((uint16_t)0x2FF0));
  pACC->addCharacteristic(&XaxisChar);

  pACC->addCharacteristic(&YaxisChar);

  pACC->addCharacteristic(&ZaxisChar);

  AccelerometerDescriptor.setValue("Accelerometer value");
  //XaxisChar.addDescriptor(&AccelerometerDescriptor);
  XaxisChar.addDescriptor(new BLE2902());
  //YaxisChar.addDescriptor(&AccelerometerDescriptor);
  YaxisChar.addDescriptor(new BLE2902());
  //ZaxisChar.addDescriptor(&AccelerometerDescriptor);
  ZaxisChar.addDescriptor(new BLE2902());


   pServer->getAdvertising()->start();
  // pACC->start();
  // Start advertising
   //pServer->getAdvertising()->start();
}
void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  InitBLE();
  myIMU.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
 x=myIMU.readFloatAccelX();
 Serial.println(x);
 y=myIMU.readFloatAccelY();
 Serial.println(y);
 z=myIMU.readFloatAccelZ();
 Serial.println(z);
 //update values and notify client of XaxisChar
  XaxisChar.setValue(x);
  XaxisChar.notify();
//update values and notify client of YaxisChar
  YaxisChar.setValue(y);
  YaxisChar.notify();
//update values and notify client of ZaxisChar
  ZaxisChar.setValue(z);
  ZaxisChar.notify();
  delay(1000);
}
//fatal error
