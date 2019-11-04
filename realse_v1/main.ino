#include "bitmaps.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "wifi-connection.h"
#include "hts221.h"

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
  {////display time and date
    Serial.println("menu 0");
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print(time(1));
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(40,15);
    display.print(timeStamp);
    display.setCursor(100,0);
    display.print(battery_voltage);
    display.print("%");
    display.display();
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

 else if (counter == 3)///menu 3 temperature
 {
  Serial.println("menu 3");
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(50,10);
  display.print(t);
  display.print("C");
  display.drawBitmap(0, 8, tempH, 80, 20, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
  display.display();
  }
 else if (counter == 4)/// menu 4 humidity
 {
   Serial.println("menu 4");
   display.clearDisplay();
   display.setTextSize(2);
   display.setTextColor(WHITE);
   display.setCursor(50,10);
   display.print(h);
   display.print("%");
   display.drawBitmap(0, 5, hum, 90, 30, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
   display.display();
   delay(1000);
  }
 else if (counter == 5)/// menu 5 uv
 {
   Serial.println("menu 5");
   display.clearDisplay();
   int uvi=random(3,4);
   display.setTextSize(2);
   display.setTextColor(WHITE);
   display.setCursor(50,10);
   display.print(uvi);
   display.drawBitmap(0, 5, uv, 100, 30, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
   display.display();
  }
  else
  {
    counter = 0;
  }
}
