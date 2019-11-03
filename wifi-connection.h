#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

int arg;

   String time(int arg)
   {
     const char* ssid     = "TT-Wingle-04C6";
     const char* password = "NHEY3tJj";
  // Define NTP Client to get time
    WiFiUDP ntpUDP;
    NTPClient timeClient(ntpUDP);

// Variables to save date and time
String formattedDate;
String dayStamp;
String timeStamp;
WiFi.begin(ssid,password);
  while (WiFi.status() != WL_CONNECTED) {
   delay(500);}
     timeClient.begin();
       timeClient.setTimeOffset(3600);
     while(!timeClient.update()) {
      timeClient.forceUpdate();}
  // The formattedDate comes with the following format:
  // 2018-05-28T16:00:13Z
  // We need to extract date and time
  formattedDate = timeClient.getFormattedDate();
  Serial.println(formattedDate);

  // Extract date
  int splitT = formattedDate.indexOf("T");
  dayStamp = formattedDate.substring(0, splitT);


  // Extract time
  timeStamp = formattedDate.substring(splitT+1, formattedDate.length()-1);
  if(arg==1){return dayStamp; }
  else if (arg==2){return timeStamp;}
  delay(1000);

   }
