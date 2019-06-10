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
#define accelerometerService BLEUUID(0CEAE362-FB5D-49B8-B0DB-288D9273DD12);
BLECharacteristic XaxisChar(BLEUUID(7773C182-3081-4D74-88B4-9E30277649A8),BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic YaxisChar(BLEUUID(3A164435-D2A8-4628-AB0B-8A801798CA31),BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic ZaxisChar(BLEUUID(D6C57AEB-48BC-4B77-9D66-486E55075ABC),BLECharacteristic::PROPERTY_NOTIFY);
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

  BLEService *pACC = pServer->createService(accelerometerService);
  pACC->addCharacteristic(&XaxisChar);
  pACC->addCharacteristic(&YaxisChar);
  pACC->addCharacteristic(&ZaxisChar);
  AccelerometerDescriptor.setValue("Accelerometer value");
  XaxisChar.addDescriptor(&AccelerometerDescriptor);
  XaxisChar.addDescriptor(new BLE2902());
  YaxisChar.addDescriptor(&AccelerometerDescriptor);
  YaxisChar.addDescriptor(new BLE2902());
  ZaxisChar.addDescriptor(&AccelerometerDescriptor);
  ZaxisChar.addDescriptor(new BLE2902());


  pServer->getAdvertising()->addServiceUUID(accelerometerService);
  pACC->start();
  // Start advertising
  pServer->getAdvertising()->start();
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
y=myIMU.readFloatAccelY();
z=myIMU.readFloatAccelZ();

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
