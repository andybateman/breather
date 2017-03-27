#include <ESP8266WiFi.h>
#include <ArduinoOTA.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic

const char* ssid = ".hello";
const char* password = "nope";

void setup() {
  WiFiManager wifiManager;
  wifiManager.autoConnect();
  ArduinoOTA.setHostname("espD1.2");
  ArduinoOTA.setPassword((const char *)password);
  ArduinoOTA.begin();
}


void loop() {
  ArduinoOTA.handle();
  analogWrite(LED_BUILTIN, 1023-(exp(sin(millis()/2000.0*PI)) - 0.36787944)*435.0/3);
}
