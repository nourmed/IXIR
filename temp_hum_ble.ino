#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <Wire.h>




#define Addr 0x5F
bool _BLEClientConnected = false;
BLEDescriptor HDescriptor(BLEUUID((uint16_t)0x2901));
BLEDescriptor TDescriptor(BLEUUID((uint16_t)0x2901));

BLECharacteristic HCharacteristic(BLEUUID((uint16_t)0x2A6F), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
BLECharacteristic TCharacteristic(BLEUUID((uint16_t)0x2A6E), BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);



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
	BLEService *pService = pServer->createService(BLEUUID((uint16_t)0x181A));

	HDescriptor.setValue("Humidity 0 to 100%");
	TDescriptor.setValue("Temperature -40-60°C");

	outHumidityCharacteristic.addDescriptor(&HyDescriptor);
	outTemperatureCharacteristic.addDescriptor(&TeDescriptor);


	// Create a BLE Descriptor
	HCharacteristic.addDescriptor(new BLE2902());
	TCharacteristic.addDescriptor(new BLE2902());

	pService->addCharacteristic(&HCharacteristic);
	pService->addCharacteristic(&TCharacteristic);
	pService->start();

	// Start advertising
	pServer->getAdvertising()->start();
}

void setup()
{
  // Initialise I2C communication as MASTER
  Wire.begin();
  // Initialise serial communication, set baud rate = 9600
  Serial.begin(115200);
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

  delay(1000);
  InitBLE();
}

void loop()
{
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
  float cTemp = (((T1 - T0) / 8.0) * (temp - T2)) / (T3 - T2) + (T0 / 8.0);
  float fTemp = (cTemp * 1.8 ) + 32;

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
  delay(2000);
  HCharacteristic.setValue(humidity);
  HCharacteristic.notify();
  TCharacteristic.setValue(ctemp);
  TCharacteristic.notify();
}
