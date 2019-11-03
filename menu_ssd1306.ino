#include "enumBitmaps.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
const int buttonPin = 2;
int counter = 0;
#define OLED_RESET 4
Adafruit_SSD1306 display(128, 32, &Wire, OLED_RESET);
bitmaps h;

void setup()
{
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //or 0x3C
    display.clearDisplay(); //for Clearing the display
    display.display();
}


void loop()
{
  int buttonState;
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) // light the LED
  {
    counter++;
    delay(150);
  }

  if (counter == 0)
  {
    Serial.println("menu 0");
   display.clearDisplay(); //for Clearing the display
    display.display();
  }

 else if (counter == 1)
  {
  Serial.println("menu 1");
  display.clearDisplay();
  display.drawBitmap(0, 0, hr, 128, 32, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
  display.display();
  }

 else if (counter == 2)
 { Serial.println("menu 2");
 display.clearDisplay();
 display.drawBitmap(0, 0, spo2, 128, 32, WHITE); // display.drawBitmap(x position, y position, bitmap data, bitmap width, bitmap height, color)
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
