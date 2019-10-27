static const unsigned char PROGMEM  battery_empty[] =
{
B01111111, B11111111, B11100000,
B11000000, B00000000, B00011100,
B11110000, B00000000, B00001100,
B11110000, B00000000, B00001100,
B11110000, B00000000, B00001100,
B11110000, B00000000, B00001100,
B11000000, B00000000, B00011100,
B01111111, B11111111, B11100000
};

static const unsigned char PROGMEM  battery_1[] =
{
B01111111, B11111111, B11100000,
B11000000, B00000000, B00011100,
B11110111, B10000000, B00001100,
B11110111, B10000000, B00001100,
B11110111, B10000000, B00001100,
B11110111, B10000000, B00001100,
B11000000, B00000000, B00011100,
B01111111, B11111111, B11100000
};


static const unsigned char PROGMEM  battery_2[] =
{
B01111111, B11111111, B11100000,
B11000000, B00000000, B00011100,
B11110111, B10111100, B00001100,
B11110111, B10111100, B00001100,
B11110111, B10111100, B00001100,
B11110111, B10111100, B00001100,
B11000000, B00000000, B00011100,
B01111111, B11111111, B11100000
};


static const unsigned char PROGMEM  battery_3[] =
{
B01111111, B11111111, B11100000,
B11000000, B00000000, B00011100,
B11110111, B10111101, B11101100,
B11110111, B10111101, B11101100,
B11110111, B10111101, B11101100,
B11110111, B10111101, B11101100,
B11000000, B00000000, B00011100,
B01111111, B11111111, B11100000
};


static const unsigned char PROGMEM  Degree[] =
{
B01110111, B11000000,
B01010100, B00000000,
B01110100, B00000000,
B00000100, B00000000,
B00000100, B00000000,
B00000100, B00000000,
B00000111, B11000000,
B00000000, B00000000
};


static const unsigned char PROGMEM  mail[] =
{
B01111111, B11111110,
B11000000, B00000011,
B10110000, B00001101,
B10001100, B00110001,
B10000011, B11000001,
B10000000, B00000001,
B10000000, B00000001,
B01111111, B11111110
};


static const unsigned char PROGMEM  Clock[] =
{
B00001111, B11100000,
B00110000, B00011000,
B01000000, B00000100,
B01000001, B11100100,
B01000000, B10000100,
B00100000, B01001000,
B00011111, B11110000,
B00011000, B00110000
};

/*
static const unsigned char PROGMEM  LOGO_EN_CLOCK[] =
{
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B01111111, B11111100, B01111100, B00111000, B00000000, B00000000, B00000000, B00000000, B00011111, B11000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B01111111, B11111100, B01111100, B00111000, B00000000, B00000000, B00000000, B00000000, B01100000, B00110000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B01110000, B00000000, B01111100, B00111000, B00000000, B00000000, B00000000, B00000000, B10000000, B00001000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B01110000, B00000000, B01110011, B00111000, B00000000, B00000000, B00000000, B00000001, B00000000, B00000100, B00000000, B00000000, B00000000,

B00001100, B00000000, B00000000, B01110000, B00000000, B01110011, B00111000, B00000000, B00000000, B00000000, B00000001, B00000000, B01000100, B00000000, B00000000, B00110000,
B00000011, B00000000, B00000000, B01110000, B00000000, B01110011, B00111000, B00000000, B00000000, B00000000, B00000010, B00000000, B10000010, B00000000, B00000000, B11000000,
B00000000, B11000000, B00000000, B01110000, B00000000, B01110011, B00111000, B00000000, B00000000, B00000000, B00000010, B00000001, B00000010, B00000000, B00000011, B00000000,
B00000000, B00110000, B00000000, B01111111, B11000000, B01110000, B11111000, B00000000, B00000000, B00000000, B00000010, B00000010, B00000010, B00000000, B00001100, B00000000,
B00000000, B00110000, B00000000, B01111111, B11000000, B01110000, B11111000, B00000000, B00000000, B00000000, B00000010, B00000011, B11111010, B00000000, B00001100, B00000000,
B00000000, B11000000, B00000000, B01110000, B00000000, B01110000, B00111000, B00000000, B00000000, B00000000, B00000010, B00000000, B00000010, B00000000, B00000011, B00000000,
B00000011, B00000000, B00000000, B01110000, B00000000, B01110000, B00111000, B00000000, B00000000, B00000000, B00000010, B00000000, B00000010, B00000000, B00000000, B11000000,
B00001100, B00000000, B00000000, B01110000, B00000000, B01110000, B00111000, B00000000, B00000000, B00000000, B00000001, B00000000, B00000100, B00000000, B00000000, B00110000,

B00000000, B00000000, B00000000, B01110000, B00000000, B01110000, B00111000, B01000101, B11000100, B01100100, B00000001, B00000000, B00000100, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B01110000, B00000000, B01110000, B00111000, B01000100, B00101110, B10010100, B00000000, B10000000, B00001000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B01110000, B00000000, B01110000, B00111000, B01010100, B11100100, B10000111, B00000000, B01100000, B00110000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B01111111, B11111100, B01110000, B00111000, B01101101, B00100100, B10010100, B10000000, B00011111, B11000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B01111111, B11111100, B01110000, B00111000, B01000100, B11100010, B01100100, B10000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,
B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000, B00000000,

};
*/

static const unsigned char PROGMEM  LOGO_WATCHEN[] =
{/* 0X00,0X01,0X80,0X00,0X18,0X00, */
0XE0,0X78,0X1C,0X0F,0X07,0XFF,0XE0,0XFF,0X81,0XC0,0X39,0XC7,0XFF,0XBF,0XC0,0X00,
0XE0,0X78,0X1C,0X0F,0X07,0XFF,0XE0,0XFF,0XC1,0XC0,0X39,0XF7,0XFF,0XBF,0XE0,0X00,
0X60,0X78,0X1C,0X1F,0X07,0XFF,0XE1,0XF3,0XE1,0XC0,0X39,0XF7,0XFF,0XFF,0XE0,0X3C,
0X70,0X7C,0X18,0X1F,0X00,0X18,0X03,0X80,0XE1,0XC0,0X39,0XE7,0XFF,0XFF,0XE0,0X3F,
0X70,0X7C,0X18,0X1F,0X80,0X18,0X03,0X80,0XF1,0XC0,0X39,0XCF,0XFF,0XFF,0XF0,0X7F,
0X70,0XFC,0X38,0X1B,0X80,0X18,0X07,0X00,0X71,0XC0,0X39,0XC8,0X00,0X7F,0XF0,0X7F,
0X70,0XCC,0X38,0X39,0X80,0X18,0X07,0X00,0X01,0XC0,0X39,0XD8,0X00,0X7F,0XF8,0X7E,
0X30,0XCE,0X38,0X39,0XC0,0X18,0X07,0X00,0X01,0XC0,0X39,0XFC,0X00,0X7F,0XF8,0X7E,
0X30,0XCE,0X38,0X31,0XC0,0X18,0X07,0X00,0X01,0XC0,0X39,0XBF,0XFF,0X7F,0XF8,0X7E,
0X39,0XCE,0X30,0X71,0XC0,0X18,0X07,0X00,0X01,0XFF,0XF9,0XBF,0XFE,0X7E,0XFC,0X7E,
0X39,0XC6,0X70,0X70,0XE0,0X18,0X07,0X00,0X01,0XFF,0XF9,0XBF,0XFE,0X7E,0XFC,0X7E,
0X39,0XC6,0X70,0X70,0XE0,0X18,0X07,0X00,0X01,0XFF,0XF9,0XBF,0XFE,0X7E,0X7C,0X7E,
0X19,0X87,0X70,0XFF,0XE0,0X18,0X07,0X00,0X01,0XC0,0X39,0XBF,0XDA,0X7C,0X32,0XFE,
0X19,0X87,0X60,0XFF,0XE0,0X18,0X07,0X00,0X01,0XC0,0X39,0X78,0X00,0X78,0X10,0XFE,
0X19,0X87,0X60,0XFF,0XF0,0X18,0X07,0X00,0X61,0XC0,0X3B,0X78,0X00,0XF6,0X01,0XFE,
0X1F,0X83,0XE1,0XC0,0X70,0X18,0X07,0X00,0X71,0XC0,0X38,0X78,0X00,0XCC,0X39,0XFC,
0X1F,0X03,0XE1,0XC0,0X70,0X18,0X03,0X80,0X71,0XC0,0X39,0X7F,0XFF,0XEC,0X1F,0XFC,
0X0F,0X03,0XE1,0XC0,0X38,0X18,0X03,0X80,0XF1,0XC0,0X39,0X3F,0XFF,0XFC,0X1F,0XFC,
0X0F,0X03,0XC1,0XC0,0X38,0X18,0X01,0XC1,0XE1,0XC0,0X39,0XBF,0XFF,0XFC,0X0F,0XFC,
0X0F,0X03,0XC3,0X80,0X38,0X18,0X01,0XFF,0XC1,0XC0,0X39,0X3F,0XFF,0XFC,0X0F,0XFC,
0X0F,0X01,0XC3,0X80,0X3C,0X18,0X00,0XFF,0XC1,0XC0,0X39,0X7F,0XFF,0XFC,0X0F,0XFC,
0X0E,0X01,0XC3,0X80,0X1C,0X18,0X00,0X7F,0X01,0XC0,0X38,0X00,0X00,0X00,0X07,0XFC,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XF8,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};


//#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 5

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2


//#include <avr/wdt.h>            // library for default watchdog functions
#include <avr/interrupt.h>      // library for interrupts handling
#include <avr/sleep.h>          // library for sleep
#include <avr/power.h>          // library for power control
#include <DS3231.h>


#define top_button 2
#define  mid_button 4
#define  bot_button 3
#define  battery A0
#define  battery_LED 6
#define  buzzer 5
#define  alarm_pin 7
Adafruit_SSD1306 display(OLED_RESET);
DS3231  rtc(SDA, SCL);
///////////////////EDITABLE VARIABLES////////////////////
const int PROGMEM screen_on_time = 10000; //in ms
const int PROGMEM  Delay=100;    //Refresh rate
const int PROGMEM  screen_on_time_menu_1 = 5000;
///////////////////////////////////////////////////////////////////////////////////////////////


unsigned long previousMillis = 0;     //Variable used to count the 1s loop time
unsigned long prev_wake_up_millis = 0;
unsigned long prev_wake_up_serial_millis = 0;
unsigned long wake_up_millis = millis();
unsigned long prev_alarm_toggle_millis = 0;
int button_press_counter = 0;

//bool wake_up_serial = false;
bool wake_up = true;
bool bt_receive = false;
bool top_button_pressed = false;
bool bot_button_pressed = false;
bool mid_button_pressed = false;
bool buzz_beep = false;
bool beep_active = true;
bool beep_active_changed = false;
bool alarm_detected = false;
bool alarm_enabled = false;


byte menu_level = 0;
int select_menu = 0;
int set_hour_position = 0;
int menu_6_position = 0;


byte Twitter_msgs = 0;
byte Whatsapp_msgs = 0;
byte Gmail_msgs = 0;
byte Instagram_msgs = 0;
byte Youtube_msgs = 0;


void setup()   {
  analogReference(INTERNAL);
  Serial.begin(9600);
  PCICR |= B00000100;    //pcint 16 to 23  (pin D4 is PCINT20)
  PCMSK2 |= B00010001;   //Set pin D0, D4 and //D7 (button) and D0 to trigger an interrupt on state change.

  pinMode(top_button,INPUT);
  pinMode(mid_button,INPUT);
  pinMode(bot_button,INPUT);
  pinMode(battery,INPUT);
  pinMode(battery_LED,OUTPUT);
  digitalWrite(battery_LED,LOW);
  pinMode(buzzer,OUTPUT);
  analogWrite(buzzer,0);
  pinMode(alarm_pin,INPUT_PULLUP);

  rtc.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)
  delay(100);
  display.clearDisplay();
  display.display();
  delay(100);
  /*
  while(count_logo_loop > -8)
  {
  display.setTextSize(1);
  display.setCursor(30,0);
  display.setTextColor(WHITE);
  display.print("ELECTRONOOBS");
  display.drawBitmap(count_logo_loop, 8,  LOGO_EN_CLOCK, 128, 24, 1);
  display.display();
  count_logo_loop = count_logo_loop - 8;
  delay(10);
  display.clearDisplay();
  }
  delay(2000);
  // Clear the buffer.
  display.clearDisplay();
  */


  int loop_count = 32;

  while(loop_count > 7)
  {
  //display.setTextSize(1);
  //display.setCursor(30,0);
  //display.setTextColor(WHITE);
  //display.print("ELECTRONOOBS");
  display.drawBitmap(0, loop_count,  LOGO_WATCHEN, 128, 24, 1);
  display.display();
  loop_count = loop_count - 4;
  delay(10);
  display.clearDisplay();
  }
  delay(2000);
  // Clear the buffer.
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(30,12);
  display.setTextColor(WHITE);
  display.print("Version V2.3");
  display.display();
  delay(1000);
  display.clearDisplay();
}


void loop() {

  ////////////////////////////////////////RECEIVE AND PRINT BT///////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  if(bt_receive)
  {
    while(Serial.available() > 0)
    {
      //Received = Serial.readString();
      int Received_int = Serial.parseInt();

      if(Received_int == 23)
      {
      Twitter_msgs = Twitter_msgs + 1;
      //Serial.print(Twitter_msgs);  Serial.print("x ");  Serial.println("Twits");
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(40,12);
      display.print(Twitter_msgs);
      display.print("x Twits");
      display.display();
      }

      if(Received_int == 35)
      {
      Whatsapp_msgs = Whatsapp_msgs + 1;
      //Serial.print(Whatsapp_msgs);  Serial.print("x ");  Serial.println("WhatsApp");
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(40,12);
      display.print(Whatsapp_msgs);
      display.print("x WhatsApp");
      display.display();
      }

      if(Received_int == 47)
      {
      Gmail_msgs = Gmail_msgs + 1;
      //Serial.print(Gmail_msgs);  Serial.print("x ");  Serial.println("Gmail");
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(40,12);
      display.print(Gmail_msgs);
      display.print("x Gmail");
      display.display();
      }

      if(Received_int == 52)
      {
      Instagram_msgs = Instagram_msgs + 1;
      //Serial.print(Instagram_msgs);  Serial.print("x ");  Serial.println("Instagram");
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(40,12);
      display.print(Instagram_msgs);
      display.print("x Instagram");
      display.display();
      }

      if(Received_int == 69)
      {
      Youtube_msgs = Youtube_msgs + 1;
      //Serial.print(Youtube_msgs);  Serial.print("x ");  Serial.println("YouTube");
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(40,12);
      display.print(Youtube_msgs);
      display.print("x YouTube");
      display.display();
      }



    }
  }





  ///////////////////////////////TURN OFF SCREEN AFTER BT RECEIVE////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  if(bt_receive && !wake_up)
  {
  unsigned long wake_up_serial_millis = millis();
  if (wake_up_serial_millis - prev_wake_up_serial_millis >= 5000)
  {

    bt_receive = false;
    display.clearDisplay();
    display.display();
    prev_wake_up_serial_millis += 5000;
    //wake_up_serial = false;

    //We activate LOW power mode
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    cli();
    sleep_enable();
    sleep_bod_disable();
    //power_adc_disable();
    //power_spi_disable();
    //power_timer0_disable();            //millis() clock
    //power_timer1_enable();
    //power_timer2_disable();
    //power_twi_disable();
    sei();
    sleep_cpu();
  }
  }

  if(bt_receive && wake_up)
  {
    bt_receive = false;
  }



  ///////////////////////////////////////////SCREEN TURNED ON////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  if(wake_up && !alarm_detected)
  {
    unsigned long currentMillis = millis();

    if(buzz_beep && beep_active)
    {
      analogWrite(buzzer,200);
      delay(70);
      analogWrite(buzzer,LOW);
      buzz_beep=false;
    }



    if(currentMillis - previousMillis >= Delay)
    {
      if(menu_level == 0)
      {
        if(digitalRead(mid_button))
        {
          if(button_press_counter > 5)
          {
            menu_level = 1;
            select_menu = 0;  //START WITH NOTIFICATIONS MENU
            prev_wake_up_millis = millis();
            button_press_counter = 0;
            mid_button_pressed = true;
          }
          button_press_counter = button_press_counter + 1;
        }
      if(!digitalRead(mid_button) && !digitalRead(top_button) && !digitalRead(bot_button))
        {
          mid_button_pressed = false;
          button_press_counter = 0;
        }


     if(digitalRead(top_button))
      {
        if(beep_active)
        {
          analogWrite(buzzer,200);
          delay(70);
          analogWrite(buzzer,LOW);
        }
        Twitter_msgs = 0;
        Whatsapp_msgs = 0;
        Gmail_msgs = 0;
        Instagram_msgs = 0;
        Youtube_msgs = 0;
        top_button_pressed = true;
        prev_wake_up_millis = millis();


      }
      if(!digitalRead(top_button))
      {
        top_button_pressed = false;
      }


      if(digitalRead(bot_button))
      {

        if(button_press_counter > 5)
          {
            alarm_enabled = !alarm_enabled;
            button_press_counter = 0;
            if(beep_active)
            {
              analogWrite(buzzer,200);
              delay(70);
              analogWrite(buzzer,LOW);
            }
          }
        button_press_counter = button_press_counter + 1;
        bot_button_pressed = true;
        prev_wake_up_millis = millis();


      }
      if(!digitalRead(bot_button) && !digitalRead(top_button) && !digitalRead(mid_button) )
      {
        bot_button_pressed = false;
        button_press_counter = 0;
      }




      previousMillis += Delay;                                //Increase the loop counter by "Delay" time
      /*
      the_day = rtc.getDOWStr();
      the_date = rtc.getDateStr();
      the_time = rtc.getTimeStr();
      */
      int the_temp = int(rtc.getTemp());

      //temp_to_display[0] = the_temp[0];
      //temp_to_display[1] = the_temp[1];
      //////////////////////////////////////////////////////////////////////////////////////
      //Print the day of the week
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.print(rtc.getDOWStr());

      //////////////////////////////////////////////////////////////////////////////////////
      //Print the temperature
      display.setCursor(65,0);
      display.print(the_temp);
     //display.setCursor(71,0);
      //display.print(the_temp[1]);
      display.drawBitmap(76, 0,  Degree, 16, 8, 1);

      //////////////////////////////////////////////////////////////////////////////////////
      //Measure the battery level and print the battery icon
      int voltage_read = analogRead(battery);
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
        analogWrite(battery_LED,100);
      }
      else
      {
        analogWrite(battery_LED,LOW);
      }
      display.setCursor(100,0);
      display.print(battery_voltage);
      display.print("%");

      //////////////////////////////////////////////////////////////////////////////////////
      //Print the hour
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(15,9);
      display.print(rtc.getTimeStr());


      //////////////////////////////////////////////////////////////////////////////////////
      //If we have new messages print the mail
      if(Twitter_msgs > 0 || Whatsapp_msgs > 0 || Gmail_msgs > 0 || Instagram_msgs > 0 || Youtube_msgs > 0)
      {
      display.drawBitmap(1, 24,  mail, 16, 8, 1);
      }
      //////////////////////////////////////////////////////////////////////////////////////
      //Print the date
      display.setTextSize(1);
      display.setCursor(37,24);
      display.print(rtc.getDateStr());

      //////////////////////////////////////////////////////////////////////////////////////
      //Print the alarm icon
      if(alarm_enabled)
      {
      display.drawBitmap(113, 24,  Clock, 16, 8, 1);
      }

      display.display();
     }//end ofdelay loop
    }//end of menu_level = 0

    if(menu_level == 1)
    {
      if(digitalRead(top_button) && !top_button_pressed && (select_menu != 10 && select_menu != 12))
      {
        if(beep_active)
        {
          analogWrite(buzzer,200);
          delay(70);
          analogWrite(buzzer,LOW);
        }
        top_button_pressed = true;
        prev_wake_up_millis = millis();
        select_menu = select_menu - 1;
        if(select_menu < 0)
        {
          select_menu = 4;
        }
      }
      if(!digitalRead(top_button))
      {
        top_button_pressed = false;
      }

    if(digitalRead(bot_button) && !bot_button_pressed && (select_menu != 10 && select_menu != 12))
    {
      if(beep_active)
      {
        analogWrite(buzzer,200);
        delay(70);
        analogWrite(buzzer,LOW);
      }
      bot_button_pressed = true;
      prev_wake_up_millis = millis();
      select_menu = select_menu + 1;
      if(select_menu > 4)
      {
        select_menu = 0;
      }
     }

     if(!digitalRead(bot_button))
     {
      bot_button_pressed = false;
     }

     //////////////////////////////////////////MENU 0////////////////////////////////////////////
     ////////////////////////////////////////////////////////////////////////////////////////////
     if(select_menu == 0)
     {
       if(digitalRead(mid_button) && !mid_button_pressed)
       {
         if(beep_active)
         {
           analogWrite(buzzer,200);
           delay(70);
           analogWrite(buzzer,LOW);
         }
         select_menu = 10;             //menu 4 is to set time
         mid_button_pressed = true;
         prev_wake_up_millis = millis();
       }
      if(!digitalRead(mid_button))
      {
        mid_button_pressed = false;
      }

      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(55,0);
      display.setTextColor(WHITE);
      display.print("MENU");

      display.setCursor(10,8);
      display.setTextColor(BLACK,WHITE);
      display.print("SET TIME");
      display.setCursor(10,16);
      display.setTextColor(WHITE);
      display.print("NOTIFICATIONS");
      display.setCursor(10,24);
      if(alarm_enabled)
      {
      display.print("ALARM ACTIVE");
      }
      if(!alarm_enabled)
      {
      display.print("SET ALARM");
      }

      display.display();
     }

      //////////////////////////////////////////MENU 1////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////
      if(select_menu == 1)
      {
        if(digitalRead(mid_button) && !mid_button_pressed)
        {
         if(beep_active)
         {
           analogWrite(buzzer,200);
           delay(70);
           analogWrite(buzzer,LOW);
         }
         select_menu = 12;             //menu 6 is to set time
         menu_6_position = 0;
         delay(100);
         mid_button_pressed = true;
         prev_wake_up_millis = millis();
       }
        if(!digitalRead(mid_button))
        {
          mid_button_pressed = false;
        }
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(55,0);
        display.setTextColor(WHITE);
        display.print("MENU");

        display.setCursor(10,8);
        display.print("SET TIME");
        display.setCursor(10,16);
        display.setTextColor(BLACK,WHITE);
        display.print("NOTIFICATIONS");
        display.setTextColor(WHITE);
        display.setCursor(10,24);
        if(alarm_enabled)
        {
        display.print("ALARM ACTIVE");
        }
        if(!alarm_enabled)
        {
        display.print("SET ALARM");
        }
        display.display();
      }


      //////////////////////////////////////////MENU 2////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////
      if(select_menu == 2)
      {
        if(digitalRead(mid_button) && !mid_button_pressed)
        {
          if(beep_active)
          {
            analogWrite(buzzer,200);
            delay(70);
            analogWrite(buzzer,LOW);
          }
          select_menu = 2;                //Later change to 5 which is set alarm menu
          alarm_enabled = !alarm_enabled;
          mid_button_pressed = true;
          prev_wake_up_millis = millis();
        }

        if(!digitalRead(mid_button))
        {
          mid_button_pressed = false;
        }

        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(55,0);
        display.setTextColor(WHITE);
        display.print("MENU");

        display.setCursor(10,8);
        display.print("SET TIME");
        display.setCursor(10,16);
        display.print("NOTIFICATIONS");
        display.setCursor(10,24);
        display.setTextColor(BLACK,WHITE);
        if(alarm_enabled)
        {
        display.print("ALARM ACTIVE");
        }
        if(!alarm_enabled)
        {
        display.print("SET ALARM");
        }
        display.setTextColor(WHITE);
        display.display();
      }

      //////////////////////////////////////////MENU 3////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////
      if(select_menu == 3)
      {
        if(digitalRead(mid_button) && !mid_button_pressed)
        {
          if(beep_active && !beep_active_changed)
          {
            beep_active = false;
            beep_active_changed = true;
          }

          if(!beep_active && !beep_active_changed)
          {
            beep_active = true;
            beep_active_changed = true;
            analogWrite(buzzer,200);
            delay(70);
            analogWrite(buzzer,LOW);
          }
          mid_button_pressed = true;
          prev_wake_up_millis = millis();
        }

        if(!digitalRead(mid_button))
        {
          mid_button_pressed = false;
          beep_active_changed = false;
        }

        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(55,0);
        display.setTextColor(WHITE);
        display.print("MENU");

        display.setCursor(10,8);
        display.print("NOTIFICATIONS");
        display.setCursor(10,16);
        if(alarm_enabled)
        {
        display.print("ALARM ACTIVE");
        }
        if(!alarm_enabled)
        {
        display.print("SET ALARM");
        }
        display.setCursor(10,24);
        display.setTextColor(BLACK,WHITE);

        if(beep_active)
        {
          display.print("MUTE");
        }
        if(!beep_active)
        {
          display.print("SOUND");
        }

        display.display();
      }//end of menu 3






      //////////////////////////////////////////MENU 4////////////////////////////////////////////
      ////////////////////////////////////////////////////////////////////////////////////////////
      if(select_menu == 4)
      {
        if(digitalRead(mid_button) && !mid_button_pressed)
        {
          if(beep_active)
          {
            analogWrite(buzzer,200);
            delay(70);
            analogWrite(buzzer,LOW);
          }
          menu_level = 0;
          select_menu = 1;
          mid_button_pressed = true;
          prev_wake_up_millis = millis();
        }

        if(!digitalRead(mid_button))
        {
          mid_button_pressed = false;
        }

        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(55,0);
        display.setTextColor(WHITE);
        display.print("MENU");

        display.setCursor(10,8);
        if(alarm_enabled)
        {
        display.print("ALARM ACTIVE");
        }
        if(!alarm_enabled)
        {
        display.print("SET ALARM");
        }
        display.setCursor(10,16);

        if(beep_active)
        {
          display.print("MUTE");
        }
        if(!beep_active)
        {
          display.print("SOUND");
        }
        display.setTextColor(BLACK,WHITE);
        display.setCursor(10,24);
        display.print("EXIT");
        display.setTextColor(WHITE);


        display.display();
      }//end of menu 4
















     //////////////////////////////////////////MENU 10////////////////////////////////////////////
     ////////////////////////////////////////////////////////////////////////////////////////////
     if(select_menu == 10)
     {
      String the_day = rtc.getDOWStr();
      String the_date = rtc.getDateStr();
      String the_time = rtc.getTimeStr();
      int set_hour =     (10*(int(the_time[0]) - 48)) + (int(the_time[1]) - 48);
      int set_minute =   (10*(int(the_time[3]) - 48)) + (int(the_time[4]) - 48);
      int set_second =   (10*(int(the_time[6]) - 48)) + (int(the_time[7]) - 48);
      int set_day =      (10*(int(the_date[0]) - 48)) + (int(the_date[1]) - 48);
      int set_month =    (10*(int(the_date[3]) - 48)) + (int(the_date[4]) - 48);
      int set_year_1 = int(the_date[6]) - 48;
      int set_year_2 = int(the_date[7]) - 48;
      int set_year_3 = int(the_date[8]) - 48;
      int set_year_4 = int(the_date[9]) - 48;
      String set_week_day = "";
      int day_number = 1;

        if(the_day == "Sunday")
        {
          day_number = 7;
        }
        if(the_day == "Mondsy")
        {
          day_number = 1;
        }
        if(the_day == "Tuesday")
        {
          day_number = 2;
        }
        if(the_day == "Wednesday")
        {
          day_number = 3;
        }
        if(the_day == "Thursday")
        {
          day_number = 4;
        }
        if(the_day == "Friday")
        {
          day_number = 5;
        }
        if(the_day == "Saturday")
        {
          day_number = 6;
        }

        if(day_number == 7)
          {
            set_week_day = "SUNDAY";
          }
          if(day_number == 1)
          {
            set_week_day = "MONDAY";
          }
          if(day_number == 2)
          {
            set_week_day = "TUESDAY";
          }
          if(day_number == 3)
          {
            set_week_day = "WEDNESDAY";
          }
          if(day_number == 4)
          {
            set_week_day = "THURSDAY";
          }
          if(day_number == 5)
          {
            set_week_day = "FRIDAY";
          }
          if(day_number == 6)
          {
            set_week_day = "SATURDAY";
          }
      /////////////////////////////////////////////////////INCREASE TIME////////////////////////////////////////
      if(digitalRead(top_button) && !top_button_pressed)
      {
        if(beep_active)
        {
          analogWrite(buzzer,200);
          delay(70);
          analogWrite(buzzer,LOW);
        }
        top_button_pressed = true;
        prev_wake_up_millis = millis();

        if(set_hour_position == 1)
        {
          set_hour = set_hour + 1;
        }
        if(set_hour > 23)
        {
          set_hour = 0;
        }


        if(set_hour_position == 2)
        {
          set_minute = set_minute + 1;
        }
        if(set_minute > 59)
        {
          set_minute = 0;
        }

        if(set_hour_position == 3)
        {
          set_second = set_second + 1;
        }
        if(set_second > 59)
        {
          set_second = 0;
        }


        //////////////////////////////////////////SET THE DATE
        if(set_hour_position == 4)
        {
          set_day = set_day + 1;
        }
        if(set_day > 31)
        {
          set_day = 1;
        }


        if(set_hour_position == 5)
        {
          set_month = set_month + 1;
        }
        if(set_month > 12)
        {
          set_month = 1;
        }


        if(set_hour_position == 6)
        {
          set_year_1 = set_year_1 + 1;
        }
        if(set_year_1 > 9)
        {
          set_year_1 = 1;
        }

        if(set_hour_position == 7)
        {
          set_year_2 = set_year_2 + 1;
        }
        if(set_year_2 > 9)
        {
          set_year_2 = 0;
          set_year_1 = set_year_1 + 1;
          if(set_year_1 > 9)
          {
            set_year_1 = 1;
          }
        }

        if(set_hour_position == 8)
        {
          set_year_3 = set_year_3 + 1;
        }
        if(set_year_3 > 9)
        {
          set_year_3 = 0;
          set_year_2 = set_year_2 + 1;
          if(set_year_2 > 9)
          {
            set_year_2 = 0;
            set_year_1 = set_year_1 + 1;
            if(set_year_1 > 9)
            {
              set_year_1 = 1;
            }
          }
        }

        if(set_hour_position == 9)
        {
          set_year_4 = set_year_4 + 1;
        }
        if(set_year_4 > 9)
        {
          set_year_4 = 0;
          set_year_3 = set_year_3 + 1;
          if(set_year_3 > 9)
          {
            set_year_3 = 0;
            set_year_2 = set_year_2 + 1;
            if(set_year_2 > 9)
            {
              set_year_2 = 0;
              set_year_1 = set_year_1 + 1;
              if(set_year_1 > 9)
              {
                set_year_1 = 1;
              }
            }
          }
        }

        if(set_hour_position == 10)
        {
          day_number = day_number + 1;
        }
        if(day_number > 7)
        {
          day_number = 1;
        }

        if(day_number == 7)
          {
            set_week_day = "SUNDAY";
          }
          if(day_number == 1)
          {
            set_week_day = "MONDAY";
          }
          if(day_number == 2)
          {
            set_week_day = "TUESDAY";
          }
          if(day_number == 3)
          {
            set_week_day = "WEDNESDAY";
          }
          if(day_number == 4)
          {
            set_week_day = "THURSDAY";
          }
          if(day_number == 5)
          {
            set_week_day = "FRIDAY";
          }
          if(day_number == 6)
          {
            set_week_day = "SATURDAY";
          }


      }
      if(!digitalRead(top_button))
      {
        top_button_pressed = false;
      }
      /////////////////////////////////////////////////end increase time


      /////////////////////////////////////////////////////DECREAE TIME////////////////////////////////////////
      if(digitalRead(bot_button) && !bot_button_pressed)
      {
        if(beep_active)
        {
          analogWrite(buzzer,200);
          delay(70);
          analogWrite(buzzer,LOW);
        }
        bot_button_pressed = true;
        prev_wake_up_millis = millis();

        if(set_hour_position == 1)
        {
          set_hour = set_hour - 1;
        }
        if(set_hour < 0)
        {
          set_hour = 23;
        }

        if(set_hour_position == 2)
        {
          set_minute = set_minute - 1;
        }
        if(set_minute < 0)
        {
          set_minute = 59;
        }

        if(set_hour_position == 3)
        {
          set_second = set_second - 1;
        }
        if(set_second < 0)
        {
          set_second = 59;
        }


        //////////////////////////////////////////SET THE DATE
        if(set_hour_position == 4)
        {
          set_day = set_day - 1;
        }
        if(set_day < 1)
        {
          set_day = 31;
        }


        if(set_hour_position == 5)
        {
          set_month = set_month - 1;
        }
        if(set_month < 1)
        {
          set_month = 12;
        }

        if(set_hour_position == 6)
        {
          set_year_1 = set_year_1 - 1;
        }
        if(set_year_1 < 1)
        {
          set_year_1 = 9;
        }

        if(set_hour_position == 7)
        {
          set_year_2 = set_year_2 - 1;
        }
        if(set_year_2 < 0)
        {
          set_year_2 = 9;
          set_year_1 = set_year_1 - 1;
          if(set_year_1 < 1)
          {
            set_year_1 = 9;
          }
        }

        if(set_hour_position == 8)
        {
          set_year_3 = set_year_3 - 1;
        }
        if(set_year_3 < 0)
        {
          set_year_3 = 9;
          set_year_2 = set_year_2 - 1;
          if(set_year_2 < 0)
          {
            set_year_2 = 9;
            set_year_1 = set_year_1 - 1;
            if(set_year_1 < 1)
            {
              set_year_1 = 9;
            }
          }
        }

        if(set_hour_position == 9)
        {
          set_year_4 = set_year_4 - 1;
        }
        if(set_year_4 < 0)
        {
          set_year_4 = 9;
          set_year_3 = set_year_3 - 1;
          if(set_year_3 < 0)
          {
            set_year_3 = 9;
            set_year_2 = set_year_2 - 1;
            if(set_year_2 < 0)
            {
              set_year_2 = 9;
              set_year_1 = set_year_1 - 1;
              if(set_year_1 < 1)
              {
                set_year_1 = 9;
              }
            }
          }
        }

        if(set_hour_position == 10)
        {
          day_number = day_number - 1;
        }
        if(day_number < 1)
        {
          day_number = 7;
        }

          if(day_number == 7)
          {
            set_week_day = "SUNDAY";
          }
          if(day_number == 1)
          {
            set_week_day = "MONDAY";
          }
          if(day_number == 2)
          {
            set_week_day = "TUESDAY";
          }
          if(day_number == 3)
          {
            set_week_day = "WEDNESDAY";
          }
          if(day_number == 4)
          {
            set_week_day = "THURSDAY";
          }
          if(day_number == 5)
          {
            set_week_day = "FRIDAY";
          }
          if(day_number == 6)
          {
            set_week_day = "SATURDAY";
          }

      }
      if(!digitalRead(bot_button))
      {
        bot_button_pressed = false;
      }




       if(digitalRead(mid_button) && !mid_button_pressed)
       {
         if(beep_active)
         {
           analogWrite(buzzer,200);
           delay(70);
           analogWrite(buzzer,LOW);
         }
         set_hour_position = set_hour_position + 1;
         if(set_hour_position > 10)
         {
          display.clearDisplay();
          display.setTextSize(2);
          display.setCursor(35,10);
          display.setTextColor(WHITE);
          display.print("SAVED");
          display.display();
          //set_hour =    10*set_hour_1 + set_hour_2;
          //set_minute =  10*set_minute_1 + set_minute_2;
          //set_second =  10*set_second_1 + set_second_2;
          //set_day =     10*set_day_1 + set_day_2;
          //set_month =  10*set_month_1 + set_month_2;




          set_hour_position = 0;
          delay(2000);
          select_menu=1;
          menu_level = 0;
         }
         mid_button_pressed = true;
         prev_wake_up_millis = millis();
       }
      if(!digitalRead(mid_button))
      {
        mid_button_pressed = false;
      }

      if(set_hour_position <= 3)
      {
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(42,0);
        display.setTextColor(WHITE);
        display.print("SET TIME");
      }

      if(set_hour_position > 3 && set_hour_position <= 9)
      {
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(42,0);
        display.setTextColor(WHITE);
        display.print("SET DATE");
      }

      if(set_hour_position > 9)
      {
        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(47,0);
        display.setTextColor(WHITE);
        display.print("SET DAY");
      }


      if(set_hour_position == 0)
      {
        //Print the hour
        display.setTextSize(2);
        display.setTextColor(BLACK,WHITE);
        display.setCursor(15,9);
        display.print(set_hour);
        display.setTextColor(WHITE);
        display.print(the_time[2]);
        display.print(set_minute);
        display.print(the_time[5]);
        display.print(set_second);
        set_hour_position = 1;
        delay(40);
      }
      if(set_hour_position == 1)
      {
        //Print the hour
        display.setTextSize(2);
        display.setTextColor(BLACK,WHITE);
        display.setCursor(15,9);
        display.print(set_hour);
        display.setTextColor(WHITE);
        display.print(the_time[2]);
        display.print(set_minute);
        display.print(the_time[5]);
        display.print(set_second);
      }

      if(set_hour_position == 2)
      {
        //Print the hour
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(15,9);
        display.print(set_hour);
        display.print(the_time[2]);
        display.setTextColor(BLACK,WHITE);
        display.print(set_minute);
        display.setTextColor(WHITE);
        display.print(the_time[5]);
        display.print(set_second);

      }

      if(set_hour_position == 3)
      {
        //Print the hour
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(15,9);
        display.print(set_hour);
        display.print(the_time[2]);
        display.print(set_minute);
        display.print(the_time[5]);
        display.setTextColor(BLACK,WHITE);
        display.print(set_second);
        display.setTextColor(WHITE);
      }


      //PRINT THE DATE
      if(set_hour_position == 4)
      {
        //Print the hour
        display.setTextSize(2);
        display.setCursor(0,9);
        display.setTextColor(BLACK,WHITE);
        display.print(set_day);
        display.setTextColor(WHITE);
        display.print(the_date[2]);
        display.print(set_month);
        display.print(the_date[5]);
        display.print(set_year_1);
        display.print(set_year_2);
        display.print(set_year_3);
        display.print(set_year_4);
      }


      if(set_hour_position == 5)
      {
        //Print the hour
        display.setTextSize(2);
        display.setCursor(0,9);
        display.setTextColor(WHITE);
        display.print(set_day);
        display.print(the_date[2]);
        display.setTextColor(BLACK,WHITE);
        display.print(set_month);
        display.setTextColor(WHITE);
        display.print(the_date[5]);
        display.print(set_year_1);
        display.print(set_year_2);
        display.print(set_year_3);
        display.print(set_year_4);
      }


      if(set_hour_position == 6)
      {
        //Print the hour
        display.setTextSize(2);
        display.setCursor(0,9);
        display.setTextColor(WHITE);
        display.print(set_day);
        display.print(the_date[2]);
        display.print(set_month);
        display.print(the_date[5]);
        display.setTextColor(BLACK,WHITE);
        display.print(set_year_1);
        display.setTextColor(WHITE);
        display.print(set_year_2);
        display.print(set_year_3);
        display.print(set_year_4);
      }

      if(set_hour_position == 7)
      {
        //Print the hour
        display.setTextSize(2);
        display.setCursor(0,9);
        display.setTextColor(WHITE);
        display.print(set_day);
        display.print(the_date[2]);
        display.print(set_month);
        display.print(the_date[5]);
        display.print(set_year_1);
        display.setTextColor(BLACK,WHITE);
        display.print(set_year_2);
        display.setTextColor(WHITE);
        display.print(set_year_3);
        display.print(set_year_4);
      }

      if(set_hour_position == 8)
      {
        //Print the hour
        display.setTextSize(2);
        display.setCursor(0,9);
        display.setTextColor(WHITE);
        display.print(set_day);
        display.print(the_date[2]);
        display.print(set_month);
        display.print(the_date[5]);
        display.print(set_year_1);
        display.print(set_year_2);
        display.setTextColor(BLACK,WHITE);
        display.print(set_year_3);
        display.setTextColor(WHITE);
        display.print(set_year_4);
      }

      if(set_hour_position == 9)
      {
        //Print the hour
        display.setTextSize(2);
        display.setCursor(0,9);
        display.setTextColor(WHITE);
        display.print(set_day);
        display.print(the_date[2]);
        display.print(set_month);
        display.print(the_date[5]);
        display.print(set_year_1);
        display.print(set_year_2);
        display.print(set_year_3);
        display.setTextColor(BLACK,WHITE);
        display.print(set_year_4);
        display.setTextColor(WHITE);
      }

      if(set_hour_position == 10)
      {
        //Print the hour
        display.setTextSize(2);
        display.setCursor(0,9);
        display.setTextColor(BLACK,WHITE);
        display.print(set_week_day);
        display.setTextColor(WHITE);
      }
      display.display();
      int set_year =   1000*set_year_1 + 100*set_year_2 + 10*set_year_3 + set_year_4;
      rtc.setTime(set_hour, set_minute, set_second);     // Set the time to 12:00:00 (24hr format)
      rtc.setDate(set_day, set_month, set_year);   // Set the date to January 1st, 2014
      rtc.setDOW(day_number);     // Set Day-of-Week to SUNDAY
     }
     ////////////////////////////////////END OF MENU 4 which is set time



     if(select_menu == 12)
     {
      if(digitalRead(top_button) && !top_button_pressed)
        {
          if(beep_active)
          {
            analogWrite(buzzer,200);
            delay(70);
            analogWrite(buzzer,LOW);
          }
          menu_6_position = menu_6_position - 1;
          if(menu_6_position < 0)
          {
            menu_6_position = 6;
          }
          top_button_pressed = true;
          prev_wake_up_millis = millis();
        }

        if(!digitalRead(top_button))
        {
          top_button_pressed = false;
        }


        if(digitalRead(bot_button) && !bot_button_pressed)
        {
          if(beep_active)
          {
            analogWrite(buzzer,200);
            delay(70);
            analogWrite(buzzer,LOW);
          }
          menu_6_position = menu_6_position + 1;
          if(menu_6_position > 6)
          {
            menu_6_position = 0;
          }
          bot_button_pressed = true;
          prev_wake_up_millis = millis();
        }

        if(!digitalRead(bot_button))
        {
          bot_button_pressed = false;
        }


        if(digitalRead(mid_button) && !mid_button_pressed)
        {
          if(beep_active)
          {
            analogWrite(buzzer,200);
            delay(70);
            analogWrite(buzzer,LOW);
          }
          mid_button_pressed = true;
          prev_wake_up_millis = millis();

          if(menu_6_position == 0)
          {
            Twitter_msgs = 0;
            Whatsapp_msgs = 0;
            Gmail_msgs = 0;
            Instagram_msgs = 0;
            Youtube_msgs = 0;
            display.clearDisplay();
            display.setTextSize(2);
            display.setCursor(8,10);
            display.setTextColor(WHITE);
            display.print("ALL CLEAR");
            display.display();
            delay(1000);
            select_menu = 0;
            menu_level = 0;
          }

          if(menu_6_position == 1)
          {
            Twitter_msgs = 0;
          }

          if(menu_6_position == 2)
          {
            Whatsapp_msgs = 0;
          }

          if(menu_6_position == 3)
          {
            Gmail_msgs = 0;
          }

          if(menu_6_position == 4)
          {
            Instagram_msgs = 0;
          }

          if(menu_6_position == 5)
          {
            Youtube_msgs = 0;
          }

          if(menu_6_position == 6)
          {
            select_menu = 1;
          }

        }

        if(!digitalRead(mid_button))
        {
          mid_button_pressed = false;
        }


        display.clearDisplay();
        display.setTextSize(1);
        display.setCursor(20,0);
        display.setTextColor(WHITE);
        display.print("NOTIFICATIONS");

        if(menu_6_position == 0)
        {
          display.setTextSize(1);
          display.setCursor(0,8);
          display.setTextColor(BLACK,WHITE);
          display.print("CLEAR ALL");
          display.setCursor(0,16);
          display.setTextColor(WHITE);
          display.print("Twitter: "); display.print(Twitter_msgs);
          display.setCursor(0,24);
          display.print("Whatsapp: "); display.print(Whatsapp_msgs);
          display.display();
        }

        if(menu_6_position == 1)
        {
          display.setTextSize(1);
          display.setCursor(0,8);
          display.print("CLEAR ALL");
          display.setCursor(0,16);
          display.setTextColor(BLACK,WHITE);
          display.print("Twitter: "); display.print(Twitter_msgs);
          display.setTextColor(WHITE);
          display.setCursor(0,24);
          display.print("Whatsapp: "); display.print(Whatsapp_msgs);
          display.display();
        }

        if(menu_6_position == 2)
        {
          display.setTextSize(1);
          display.setCursor(0,8);
          display.print("CLEAR ALL");
          display.setCursor(0,16);
          display.print("Twitter: "); display.print(Twitter_msgs);
          display.setCursor(0,24);
          display.setTextColor(BLACK,WHITE);
          display.print("Whatsapp: "); display.print(Whatsapp_msgs);
          display.setTextColor(WHITE);
          display.display();
        }


        if(menu_6_position == 3)
        {
          display.setTextSize(1);
          display.setCursor(0,8);
          display.setTextColor(BLACK,WHITE);
          display.print("Instagram; "); display.print(Instagram_msgs);
          display.setTextColor(WHITE);
          display.setCursor(0,16);
          display.print("Mail: "); display.print(Gmail_msgs);
          display.setCursor(0,24);
          display.print("YouTube: "); display.print(Youtube_msgs);
          display.display();
        }

        if(menu_6_position == 4)
        {
          display.setTextSize(1);
          display.setCursor(0,8);
          display.print("Instagram; "); display.print(Instagram_msgs);
          display.setCursor(0,16);
          display.setTextColor(BLACK,WHITE);
          display.print("Mail: "); display.print(Gmail_msgs);
          display.setTextColor(WHITE);
          display.setCursor(0,24);
          display.print("YouTube: "); display.print(Youtube_msgs);
          display.display();
        }

        if(menu_6_position == 5)
        {
          display.setTextSize(1);
          display.setCursor(0,8);
          display.print("Instagram; "); display.print(Instagram_msgs);
          display.setCursor(0,16);
          display.print("Mail: "); display.print(Gmail_msgs);
          display.setCursor(0,24);
          display.setTextColor(BLACK,WHITE);
          display.print("YouTube: "); display.print(Youtube_msgs);
          display.setTextColor(WHITE);
          display.display();
        }


        if(menu_6_position == 6)
        {
          display.setTextSize(1);
          display.setCursor(0,8);
          display.print("Mail: "); display.print(Gmail_msgs);
          display.setCursor(0,16);
          display.print("YouTube: "); display.print(Youtube_msgs);
          display.setCursor(0,24);
          display.setTextColor(BLACK,WHITE);
          display.print("GO BACK");
          display.setTextColor(WHITE);
          display.display();
        }





     }//end of menu = 6 see notifications



    }//end of menu_level = 1


  }//end of wake up


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
  if(alarm_detected && wake_up)
    {
      wake_up_millis = millis();
      if (wake_up_millis - prev_wake_up_millis >= 60000)
      {
        alarm_detected = false;
        analogWrite(buzzer,0);
        display.clearDisplay();
        display.display();
        prev_wake_up_millis += 60000;
        //We activate LOW power mode
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        //set_sleep_mode(SLEEP_MODE_IDLE);
        cli();
        sleep_enable();
        sleep_bod_disable();
        power_adc_disable();
        power_spi_disable();
        //power_timer0_disable();            //millis() clock
        //power_timer1_disable();
        //power_timer2_disable();
        //power_twi_disable();
        sei();
        sleep_cpu();
      }


      /////////////////TOGGLE THE BUZZER
      if (wake_up_millis - prev_alarm_toggle_millis >= 1000)
      {
        display.clearDisplay();
        display.setTextSize(2);
        display.setCursor(35,9);
        display.setTextColor(WHITE);
        display.print("ALARM");
        display.display();

        prev_alarm_toggle_millis += 1000;
        analogWrite(buzzer,200);
        delay(70);
        analogWrite(buzzer,0);
        delay(70);
        analogWrite(buzzer,200);
        delay(70);
        analogWrite(buzzer,0);
      }//end of TOGGLE BUZZER
    }//end of alarm detected
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////




  ///////////////////////////////TURN OFF SCREEN if we are into MENU 0///////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  if(wake_up && !bt_receive && menu_level == 0)
  {
  wake_up_millis = millis();
  if (wake_up_millis - prev_wake_up_millis >= screen_on_time)
  {
    menu_level = 0;                   //get back to front menu
    button_press_counter = 0;
    wake_up = false;
    display.clearDisplay();
    display.display();
    prev_wake_up_millis += screen_on_time;


    //We activate LOW power mode
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    //set_sleep_mode(SLEEP_MODE_IDLE);
    cli();
    sleep_enable();
    sleep_bod_disable();

    power_adc_disable();
    power_spi_disable();
    //power_timer0_disable();            //millis() clock
    //power_timer1_disable();
    //power_timer2_disable();
    //power_twi_disable();

    sei();
    sleep_cpu();
  }
  }//end of turn off screen in menu 0



  ///////////////////////////////TURN OFF SCREEN if we are into MENU 1///////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  if(wake_up && !bt_receive && menu_level == 1)
  {
  wake_up_millis = millis();
  if (wake_up_millis - prev_wake_up_millis >= screen_on_time_menu_1)
  {
    menu_level = 0;                   //get back to front menu
    button_press_counter = 0;
    set_hour_position = 1;
    display.clearDisplay();
    display.display();
    prev_wake_up_millis = millis();

  }
  }//end of turn off screen in menu 0



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
  /////////////////////////////TURN OFF SCREEN after ALARM without screen ON/////////////////////////////
  ///////////////////////////////////////////////////////////////////////////////////////////////////////
  if(alarm_detected && !wake_up && !bt_receive && menu_level == 0)
  {
  wake_up_millis = millis();
  if (wake_up_millis - prev_wake_up_millis >= 60000)
  {
    alarm_detected = false;
    analogWrite(buzzer,0);
    display.clearDisplay();
    display.display();
    prev_wake_up_millis += 60000;
    //We activate LOW power mode
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    //set_sleep_mode(SLEEP_MODE_IDLE);
    cli();
    sleep_enable();
    sleep_bod_disable();
    power_adc_disable();
    power_spi_disable();
    //power_timer0_disable();            //millis() clock
    //power_timer1_disable();
    //power_timer2_disable();
    //power_twi_disable();
    sei();
    sleep_cpu();
  }

  /////////////////TOGGLE THE BUZZER
  if (wake_up_millis - prev_alarm_toggle_millis >= 1000)
  {
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(35,9);
    display.setTextColor(WHITE);
    display.print("ALARM");
    display.display();

    prev_alarm_toggle_millis += 1000;
    analogWrite(buzzer,200);
    delay(70);
    analogWrite(buzzer,0);
    delay(70);
    analogWrite(buzzer,200);
    delay(70);
    analogWrite(buzzer,0);
  }//end of TOGGLE BUZZER

 }//end of alarm active

*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////





}//end of void loop








ISR(PCINT2_vect)
{






  if(PIND & B00010000)
  {
    sleep_disable();
    power_adc_enable();
    wake_up = true;
    buzz_beep = true;
    prev_wake_up_millis = millis();
    alarm_detected = false;
  }//end of push button

  /*
  if(PIND & B10000000)  //Interruption on D7 from RTC  //D2
  {

    sleep_disable();
    alarm_detected = true;
    prev_alarm_toggle_millis = millis();

  }//end of RTC interruption
  */

  if(!(PIND & B00000001))
  {
    sleep_disable();
    power_adc_enable();
    bt_receive = true;
    //wake_up_serial = true;
    prev_wake_up_serial_millis = millis();
  }//end of serial RX interruption
}
