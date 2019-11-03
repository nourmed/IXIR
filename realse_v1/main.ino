#include "bitmaps.h"
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
    display.drawBitmap(13, 8, ixir_logo, 100, 20, WHITE);
    display.display();
    delay(2000);
    ////end display logo
}
