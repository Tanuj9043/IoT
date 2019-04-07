#include <WiFi.h>

const char* ssid     = "Redmi Note 3";
const char* password = "tanujdrall";

const char* host = "api.thingspeak.com";
WiFiClient client;
const int httpPort = 80;

void setup()
{
    Serial.begin(115200);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.print("connecting to ");
    Serial.println(host);

}

void loop()
{
    int sensorValue = analogRead(34);
    int percent = map(sensorValue, 0, 4095, 0, 100);
    Serial.print("Sending ");
    Serial.println(percent);
    String url = "/update?api_key=FB2KYCMP1EF8U1X9&field1=";
    //url = url + random(0,10);
    url = url + percent;

    Serial.print("Requesting URL: ");
    Serial.println(url);

    if (!client.connect(host, httpPort)) {
        Serial.println("connection failed");
        return;
    }
    
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");

    unsigned long timeout = millis();
    while (client.available() == 0) {
        if (millis() - timeout > 5000) {
            Serial.println(">>> Client Timeout !");
            client.stop();
            return;
        }
    }

    bool headerComplete = false;
    while(client.available()) {
        String line = client.readStringUntil('\r');
        if(headerComplete)
        {
          int dataCount = line.toInt();
          if(dataCount)//A positive integer is sent when data is uploaded successfully
            Serial.println("Data Uploaded");
          else
            Serial.println("Upload Failed");
        }
        if(line == "\n")
          headerComplete = true;

    }

    delay(20000);
}
