#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid = ".hello";
const char* password = "nope";

void setup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.setHostname("espD1.1");
  ArduinoOTA.setPassword((const char *)password);
  ArduinoOTA.begin();
}


void loop() {
  ArduinoOTA.handle();
  analogWrite(LED_BUILTIN, 1023-(exp(sin(millis()/2000.0*PI)) - 0.36787944)*435.0/3);
}
