#include <time.h>
#include <WiFi.h>
const char* ssid="Redmi Note 3";
const char* password="tanujdrall";
const char* ntpServer="pool.ntp.org";
const long gmtOffset_sec = 19800;
const int daylightOffset_sec = 0;

void printLocalTime(){
   //See time format from docs to get required day, time, month, weekday, etc.
   struct tm timestamp;// tm is predefined structure in time.h header file
   if(!getLocalTime(&timestamp)){
    Serial.println("Failed to obtain time");
    return;
   }
   Serial.println(&timestamp,"%c");
   Serial.println(&timestamp,"%X, %x");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.printf("Connecting to ",ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop() {
  // put your main code here, to run repeatedly:
  printLocalTime();
  delay(1000);
}
