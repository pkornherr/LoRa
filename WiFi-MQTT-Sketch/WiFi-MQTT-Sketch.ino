#include <ESP8266WiFi.h>
#include <PicoMQTT.h>

PicoMQTT::Server mqtt;

void setup() {
    // Usual setup
    Serial.begin(115200);
    WiFi.softAP("meshtastic", "meshtastic");
    IPAddress IP = WiFi.softAPIP();
    mqtt.subscribe("#", [](const char * topic, const char * payload) {
        Serial.printf("Received message in topic '%s': %s\n", topic, payload);
    });
    mqtt.begin();
}
 
void loop() {
    mqtt.loop();
}