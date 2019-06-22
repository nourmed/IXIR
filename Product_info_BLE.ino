#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>


//intiate Server Status
bool _BLEClientConnected = false;
//Declare Descriptors
BLEDescriptor ManufNameDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor ModelNumberDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor SerialNumberDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor SystemIdDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor IEEE11073CertifDescriptor(BLEUUID((uint16_t)0x2901));


//Declare Characteristics
BLECharacteristic ManufNameChar(BLEUUID((uint16_t)0x2A29),BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic ModelNumberChar(BLEUUID((uint16_t)0x2A24),BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic SerialNumberChar(BLEUUID((uint16_t)0x2A25),BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic SystemIdChar(BLEUUID((uint16_t)0x2A23),BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic IEEE11073CertifChar(BLEUUID((uint16_t)0x2A2A),BLECharacteristic::PROPERTY_NOTIFY);


//BLE callback function
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
  BLEService *pDeviceInfoService = pServer->createService(BLEUUID((uint16_t)0x180A));
//Manufacture Name
  ManufNameDescriptor.setValue("Manufacture Name");
  ManufNameChar.addDescriptor(&ManufNameDescriptor);
  ManufNameChar.addDescriptor(new BLE2902());
//Model Name
  ModelNumberDescriptor.setValue("Model Name");
  ModelNumberChar.addDescriptor(&ModelNumberDescriptor);
  ModelNumberChar.addDescriptor(new BLE2902());
//Serial Number
  SerialNumberDescriptor.setValue("Serial Name");
  SerialNumberChar.addDescriptor(&SerialNumberDescriptor);
  SerialNumberChar.addDescriptor(new BLE2902());
//System ID
  SystemIdDescriptor.setValue("System ID");
  SystemIdChar.addDescriptor(&SystemIdDescriptor);
  SystemIdChar.addDescriptor(new BLE2902());
// IEEE-11073-20601 Certification
  IEEE11073CertifDescriptor.setValue("IEEE-11073-20601 Certification");
  IEEE11073CertifChar.addDescriptor(&IEEE11073CertifDescriptor);
  IEEE11073CertifChar.addDescriptor(new BLE2902());




  pDeviceInfoService->addCharacteristic(&ManufNameChar);
  pDeviceInfoService->addCharacteristic(&ModelNumberChar);
  pDeviceInfoService->addCharacteristic(&SerialNumberChar);
  pDeviceInfoService->addCharacteristic(&SystemIdChar);
  pDeviceInfoService->addCharacteristic(&IEEE11073CertifChar);
  pDeviceInfoService->start();
  // Start advertising
  pServer->getAdvertising()->start();
}
void setup()
{
  Serial.begin(115200);
  delay(500);
  InitBLE();
}
void loop()
{


ManufNameChar.setValue();
ManufNameChar.notify();

ModelNumberChar.setValue();
ModelNumberChar.notify();

SerialNumberChar.setValue();
SerialNumberChar.notify();

SystemIdChar.setValue();
SystemIdChar.notify();

IEEE11073CertifChar.setValue();
IEEE11073CertifChar.notify();



  delay(1000);
}
