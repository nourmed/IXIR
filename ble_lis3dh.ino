#include <SparkFunLIS3DH.h>
#include "Wire.h"
#include "SPI.h"
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>




bool _BLEClientConnected = false;
LIS3DH myIMU( I2C_MODE, 0x18 );
BLEDescriptor xDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor yDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor zDescriptor(BLEUUID((uint16_t)0x2901));

BLECharacteristic XCharacteristic(BLEUUID((uint16_t)0x2FF1),BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic YCharacteristic(BLEUUID((uint16_t)0x2FF2),BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic ZCharacteristic(BLEUUID((uint16_t)0x2FF3),BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);

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

  xDescriptor.setValue("Xchar");
  yDescriptor.setValue("Ychar");
  zDescriptor.setValue("Zchar");

  XCharacteristic.addDescriptor(&xDescriptor);

  YCharacteristic.addDescriptor(&yDescriptor);

  ZCharacteristic.addDescriptor(&zDescriptor);



  // Create a BLE Descriptor
  XCharacteristic.addDescriptor(new BLE2902());
  YCharacteristic.addDescriptor(new BLE2902());
  ZCharacteristic.addDescriptor(new BLE2902());

  pACC->addCharacteristic(&XCharacteristic);
  pACC->addCharacteristic(&YCharacteristic);
  pACC->addCharacteristic(&ZCharacteristic);
  pACC->start();

  // Start advertising
  pServer->getAdvertising()->start();}



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000); //relax...
  Serial.println("Processor came out of reset.\n");

  //Call .begin() to configure the IMU
  myIMU.begin();
  InitBLE();

}


void loop() {
  //Get all parameters
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
  delay(1000);
}
