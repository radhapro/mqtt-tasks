 #include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>

const char* ssid = "Robozz Lab";        // 👈 apna WiFi
const char* password = "Robotics@cloud";      // 👈 apna password

const char* mqtt_server = "8c77d38bb13146aeb2858d539a7cd2d0.s1.eu.hivemq.cloud";
const char* mqtt_user = "radha";
const char* mqtt_pass = "Radha@mqtt123";
const int mqtt_port = 8883;                     // HiveMQ Cloud ka port

WiFiClientSecure espClient;                     // Secure connection chahiye HiveMQ ke liye
PubSubClient client(espClient);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message aaya: ");
  for (int i = 0; i < length; i++) Serial.print((char)payload[i]);
  Serial.println();
}

void setup_wifi() {
  WiFi.begin(ssid, password);
  Serial.print("WiFi connect ho raha hai");
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nWiFi connected!");
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("MQTT connect ho raha hai...");
    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println("Connected!");
      client.subscribe("test/hello");
    } else {
      Serial.print("Failed rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  espClient.setInsecure();                      // Certificate skip karta hai (easy setup)
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) reconnect();
  client.loop();
  static unsigned long lastMsg = 0;
  if (millis() - lastMsg > 5000) {
    lastMsg = millis();
    client.publish("test/hello", "Hello from ESP32!");
    Serial.println("Message bheja!");
  }
}