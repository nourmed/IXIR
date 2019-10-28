
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>




#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// Replace with your network credentials
const char* ssid     = "Home";
const char* password = "houssem123";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;


void setup()   {

  Serial.begin(115200);
 display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
   delay(100);
   display.clearDisplay();
   display.display();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");}
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
   delay(2000);
   display.clearDisplay();
   display.display();
   delay(2000);
   Serial.println("WiFi connected.");
   display.print("wifi connected");
   display.display();
   timeClient.begin();
   timeClient.setTimeOffset(3600);

}


void loop() {

  ////////////////////////////////////////RECEIVE AND PRINT BT///////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
//
    while(!timeClient.update()) {
      timeClient.forceUpdate();
  }
  // The formattedDate comes with the following format:
  // 2018-05-28T16:00:13Z
  // We need to extract date and time
  formattedDate = timeClient.getFormattedDate();
  Serial.println(formattedDate);

  // Extract date
  int splitT = formattedDate.indexOf("T");
  dayStamp = formattedDate.substring(0, splitT);
  Serial.print("DATE: ");
  Serial.println(dayStamp);

  // Extract time
  timeStamp = formattedDate.substring(splitT+1, formattedDate.length()-1);
  Serial.print("HOUR: ");
  Serial.println(timeStamp);
  delay(1000);


      //Print the date
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.print(dayStamp);
      delay(2000);
   //Print the time
      //display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(40,15);
      display.print(timeStamp);
      //Measure the battery level and print the battery icon
      int voltage_read = 950;
      int battery_voltage = 0;
      if(voltage_read > 770 && voltage_read < 790)
      {
        battery_voltage = 5;
      }
      if(voltage_read > 790 && voltage_read < 830)
      {
        battery_voltage = 10;
      }
      if(voltage_read > 830 && voltage_read < 848)
      {
        battery_voltage = 30;
      }
      if(voltage_read > 848 && voltage_read < 872)
      {
        battery_voltage = 40;
      }
      if(voltage_read > 872 && voltage_read < 896)
      {
        battery_voltage = 50;
      }
      if(voltage_read > 896 && voltage_read < 920)
      {
        battery_voltage = 60;
      }
      if(voltage_read > 920 && voltage_read < 944)
      {
        battery_voltage = 70;
      }

      if(voltage_read > 944 && voltage_read < 968)
      {
        battery_voltage = 80;
      }

      if(voltage_read > 968 && voltage_read < 992)
      {
        battery_voltage = 90;
      }

      if(voltage_read > 992)
      {
        battery_voltage = 100;
      }

      if(battery_voltage < 15)
      {
        display.setCursor(64,0);
        display.print("low batt");
        display.display();
      }
      else
      {
        Serial.println("batt charged");
      }
      display.setCursor(100,0);
      display.print(battery_voltage);
      display.print("%");

   display.display();
     }//end ofdelay loop
