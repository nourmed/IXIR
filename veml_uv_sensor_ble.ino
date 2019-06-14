#include <Wire.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>








bool _BLEClientConnected = false;
BLEDescriptor UVDescriptor(BLEUUID((uint16_t)0x2901));

BLECharacteristic UVCharacteristic(BLEUUID((uint16_t)0x2A76), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
#define I2C_ADDR 0x38 //0x38 and 0x39

//Integration Time
#define IT_1_2 0x0 //1/2T
#define IT_1   0x1 //1T
#define IT_2   0x2 //2T
#define IT_4   0x3 //4T
//BLE callback function
class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer* pServer) {
    _BLEClientConnected = true;
  };

  void onDisconnect(BLEServer* pServer) {
    _BLEClientConnected = false;
  }
};
//initiate BLE Server
void InitBLE() {
  BLEDevice::init("IXIR");

  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(BLEUUID((uint16_t)0x181A));

  UVDescriptor.setValue("UV index value");
  UVCharacteristic.addDescriptor(&UVDescriptor);
  // Create a BLE Descriptor
  HCharacteristic.addDescriptor(new BLE2902());
  TCharacteristic.addDescriptor(new BLE2902());

  pService->addCharacteristic(&UVCharacteristic);
  pService->start();
  // Start advertising
  pServer->getAdvertising()->start();
}
void setup()
{
  Serial.begin(9600);
  while(!Serial); //wait for serial port to connect (needed for Leonardo only)

  Wire.begin();

  Wire.beginTransmission(I2C_ADDR);
  Wire.write((IT_1<<2) | 0x02);
  Wire.endTransmission();
  delay(500);
  InitBLE();
}

void loop()
{
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
  uint8_t uvindex=random(1,9);
  Serial.printnln(uvindex);
  UVCharacteristic.setValue(uvindex,2);
  UVCharacteristic.notify();
  delay(1000);
}
