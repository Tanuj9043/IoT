#include <time.h>
#include <WiFi.h>
const char* ssid="VentureSky";
const char* password="qwertyuiop";
const char* host="www.nsit.ac.in";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Connecting to ");
  Serial.println(host);
  
  WiFiClient client;
  const int httpPort = 80;
  if(!client.connect(host,httpPort)){
    Serial.println("Connection Failed");
    return;    
  }

  String url = "/";

  Serial.print("Requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n");

  unsigned long timeout = millis();
  while(client.available()==0){
    if(millis()-timeout>5000){
      Serial.println(">>> Connection Timeout!");
      client.stop();
      return;
    }
  }

  while(client.available()){
    String line = client.readStringUntil('\r');
    int n = line.indexOf("fa-calendar");
    if(n>0){
      Serial.println(line.substring(n+17,n+27));
    }
    Serial.println();
    Serial.print(line);
  }

  client.stop();
  Serial.println("Connection closed");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
}

void loop() {
  // put your main code here, to run repeatedly:

}
