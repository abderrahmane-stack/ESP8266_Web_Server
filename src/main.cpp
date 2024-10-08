#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <FS.h>
//#include "index.h" //Our HTML webpage contents with javascripts
//#include "DHTesp.h" //DHT11 Library for ESP
#define LED 2 //On board LED
//SSID and Password of your WiFi router
const char* ssid = "*********";
const char* password = "*********";
ESP8266WebServer server(80); //Server on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
float humidity, temperature;
void handleTH() {
String data = "{\"Temperature\":\""+ String(temperature) +"\", \"Humidity\":\""+ String(humidity) +"\"}";
server.send(200, "text/plane", data); //Send ADC value, temperature and humidity JSON to client ajax request
humidity +=1.;// dht.getHumidity();
temperature +=2.;// dht.getTemperature();
Serial.print(humidity, 1);
Serial.println(temperature, 1);
//Serial.print(dht.toFahrenheit(temperature), 1);
}


void setup()
{

//make the LED pin output and initially turned off
pinMode(LED, OUTPUT);
digitalWrite(LED, LOW);
Serial.begin(115200);
Serial.println();

if(!SPIFFS.begin()){
Serial.println("An Error has occurred while mounting SPIFFS");
return;
}

WiFi.begin(ssid, password); //Connect to your WiFi router
Serial.println("");
//Onboard LED port Direction output

// Wait for connection
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}

//If connection successful show IP address in serial monitor
Serial.println("");
Serial.print("Connected to ");
Serial.println(ssid);
Serial.print("IP address: ");
Serial.println(WiFi.localIP()); //IP address assigned to your ESP
server.on("/LEDOn", [](){
digitalWrite(LED, LOW);

Serial.println("on");
});
server.on("/LEDOff", [](){
digitalWrite(LED, HIGH);
Serial.println("off");
});
server.serveStatic("/css", SPIFFS, "/css");
server.serveStatic("/js", SPIFFS, "/js");
server.serveStatic("/", SPIFFS, "/index.html");
server.on("/readTH", handleTH); //This page is called by java Script AJAX
server.begin(); //Start server
Serial.println("HTTP server started");
}
void loop()
{
server.handleClient(); //Handle client requests
}
