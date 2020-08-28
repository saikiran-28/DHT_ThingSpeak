#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <DHT.h>
#define dpin D4

DHT dht(dpin,DHT11);
const char* ssid = "Virus infected Wi-Fi!"; //Your Network SSID
const char* password = "laddusai1"; //Your Network Password
WiFiClient client;
unsigned long myChannelNumber = 1015997; //Your Channel Number (Without Brackets)
const char* myWriteAPIKey = "3LG35OKDL0XJPQFS"; //Your Write API Key
void setup() {
  // put your setup code here, to run once:
    
WiFi.begin(ssid, password);
ThingSpeak.begin(client);
dht.begin();

Serial.begin(9600);

}
void loop() {
  // put your main code here, to run repeatedly:
float temp= dht.readTemperature();
float hum= dht.readHumidity();
delay(1000);
Serial.println("Temperature");
Serial.println(temp);
Serial.println("Humidity");
Serial.println(hum);

ThingSpeak.writeField(myChannelNumber, 1,temp, myWriteAPIKey); //Update in ThingSpeak
ThingSpeak.writeField(myChannelNumber, 2,hum, myWriteAPIKey);
delay(100);
}
