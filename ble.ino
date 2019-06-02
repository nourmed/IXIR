
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>



byte flags = 0b00111110;
byte bpm;
byte heart[8] = { 0b00001110, 60, 0, 0, 0 , 0, 0, 0};

//initiate connection state
bool _BLEClientConnected = false;
//define characteristic and descriptor
#define heartRateService BLEUUID((uint16_t)0x180D)
BLECharacteristic heartRateMeasurementCharacteristics(BLEUUID((uint16_t)0x2A37), BLECharacteristic::PROPERTY_NOTIFY);
BLEDescriptor heartRateDescriptor(BLEUUID((uint16_t)0x2901));



// server callbacks // connection state
class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      _BLEClientConnected = true;
    };

    void onDisconnect(BLEServer* pServer) {
      _BLEClientConnected = false;
    }
};
//initiate ble server
void InitBLE() {
  BLEDevice::init("IXIR");
  // Create the BLE Server
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pHeart = pServer->createService(heartRateService);

  pHeart->addCharacteristic(&heartRateMeasurementCharacteristics);
  heartRateDescriptor.setValue("PPG value");
  heartRateMeasurementCharacteristics.addDescriptor(&heartRateDescriptor);
  heartRateMeasurementCharacteristics.addDescriptor(new BLE2902());

 //add service to advertise
  pServer->getAdvertising()->addServiceUUID(heartRateService);

  pHeart->start();
  // Start advertising
  pServer->getAdvertising()->start();
}

void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  InitBLE();

}

void loop() {
  // put your main code here, to run repeatedly:
bpm=random(60,190);
heart[1] = (byte)bpm;
Serial.println(bpm);
 //update values and notify client of HR mesurements
  heartRateMeasurementCharacteristics.setValue(heart,8);
  heartRateMeasurementCharacteristics.notify();


  delay(1000);
}
