#include <WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();//To disconnect to any previous saved WiFi
  delay(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("New Scan Starting...");
  int n = WiFi.scanNetworks();
  if(n>0){
    for(int i=0; i<n; i++){
      Serial.print("WiFi Name       : ");
      Serial.println(WiFi.SSID(i));
      Serial.print("Signal Strength : ");
      Serial.print(WiFi.RSSI(i));
      Serial.println(" dB");
    } 
  }
  else Serial.println("No WiFi network found");
  delay(5000);
}
