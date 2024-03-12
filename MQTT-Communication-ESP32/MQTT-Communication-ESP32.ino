#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "WIFI-NAME";
const char* password = "************";
const char* mqttServer = "IP-OFF-MQTT";
const int mqttPort = 1883;
const char* mqttUser = "USERNAME";
const char* mqttPassword = "**********";
const char* clientID = "esp_NAME";  // MQTT client ID

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  pinMode(19, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(18, INPUT_PULLUP);


  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  client.loop();

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP32Client", mqttUser, mqttPassword)) {
      Serial.println("connected");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
  if (digitalRead(19) == LOW) {
    client.publish("huis/Woonkamer/licht", "knop 1");
    delay(200);
  }
  if (digitalRead(4) == LOW) {
    client.publish("huis/Keuken/licht", "knop 2");
    delay(200);
  }
  if (digitalRead(5) == LOW) {
    client.publish("huis/Gang/licht", "knop 3");
    delay(200);
  }
  if (digitalRead(18) == LOW) {
    client.publish("huis/Slaapkamer/licht", "knop 4");
    delay(200);
  }


  client.disconnect();  // disconnect from the MQTT broker
}