#include "bitmaps.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

//wifi credential
const char* ssid     = "TT-Wingle-04C6";
const char* password = "NHEY3tJj";
// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);
//define time variables
String formattedDate;
String dayStamp;
String timeStamp;
const int buttonPin = 2;
int counter = 0;
#define OLED_RESET 4
Adafruit_SSD1306 display(128, 32, &Wire, OLED_RESET);
bitmaps h;

void setup()
{
  ////start serial
  Serial.begin(115200);
    ////intiate button 2 pwm touch 0
    pinMode(buttonPin, INPUT);
    ////display logo startup
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //or 0x3C
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(40,10);
    display.print("i");
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(76,10);
    display.print("ir");
    // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
    display.drawBitmap(13, 8, ixir_logo, 100, 20, WHITE);
    display.display();//start display
    delay(2000);
    ////end display logo
   ////connect to wifi
    WiFi.begin(ssid,password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(500);
   }

}
void loop()
{
  int buttonState;
  ///read button state
  buttonState = digitalRead(buttonPin);
 ///count button press
  if (buttonState == HIGH)
  {
    counter++;
    delay(150);
  }

  if (counter == 0)
  {
    Serial.println("menu 0");
   //display.clearDisplay(); //for Clearing the display
    //display.display();
  }

 else if (counter == 1)//menu 1 heart rate
  {
  Serial.println("menu 1");
  int bpm=random(90,98);
  delay(1000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(50,10);
  display.print(bpm);
  display.drawBitmap(10, 8, hr, 80, 20, WHITE);
  }

 else if (counter == 2)// menu 2 spo2
 { Serial.println("menu 2");
 int o2= random(90,92);
 delay(1000);
 display.clearDisplay();
 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(50,10);
 display.print(o2);
 display.setTextSize(2);
 display.setTextColor(WHITE);
 display.setCursor(75,10);
 display.print("%");
 display.drawBitmap(10, 8, spo2, 100, 20, WHITE);
 display.display();
  }

 else if (counter == 3)
 {
 Serial.println("menu 3");
 display.clearDisplay();
display.drawBitmap(0, 0, uv, 128, 32, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
  display.display();
  }
 else if (counter == 4)
 {
 Serial.println("menu 4");
 display.clearDisplay();
display.drawBitmap(10, 10, spo3, 32, 16, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
  display.display();
  }
 else if (counter == 5)
 {
 Serial.println("menu 5");
 display.clearDisplay();
display.drawBitmap(0, 0, spo4, 128, 32, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
  display.display();
  }
  else
  {
    counter = 0;
  }
}
