#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>
#include "DHT.h"

#define DHTPIN 13
#define DHTTYPE DHT22
#define LDRPIN 34

DHT dht(DHTPIN, DHTTYPE);

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const char* mqtt_server = "f95f77855cb6413cba27d33be6a30e44.s1.eu.hivemq.cloud";
const char* mqtt_user = "rm561786";
const char* mqtt_pass = "29012007Ma"; 

WiFiClientSecure espClient;
PubSubClient client(espClient);

void conectarWiFi() {
  Serial.print("Conectando WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi conectado!");
}

void conectarMQTT() {
  while (!client.connected()) {
    Serial.print("Conectando MQTT...");
    if (client.connect("ESP32_Marina_IOT", mqtt_user, mqtt_pass)) {
      Serial.println(" conectado!");
    } else {
      Serial.println(" erro, tentando novamente...");
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  delay(2000);
  espClient.setInsecure(); 
  conectarWiFi();
  client.setServer(mqtt_server, 8883);
}

void loop() {
  if (!client.connected()) {
    conectarMQTT();
  }
  client.loop();

  unsigned long agora = millis();
  
 
  static unsigned long ultimoEnvio = 0;
  if (agora - ultimoEnvio >= 5000) {
    ultimoEnvio = agora;

    float temperatura = dht.readTemperature();
    int luminosidade = analogRead(LDRPIN);

    if (isnan(temperatura)) {
      Serial.println("Erro ao ler DHT!");
      return;
    }

    char tempStr[10];
    char luzStr[10];
    dtostrf(temperatura, 1, 2, tempStr);
    sprintf(luzStr, "%d", luminosidade);

    client.publish("casa/temperatura", tempStr);
    client.publish("casa/luminosidade", luzStr);

    Serial.println("------ DADOS ------");
    Serial.print("Temperatura: ");
    Serial.println(tempStr);
    Serial.print("Luminosidade: ");
    Serial.println(luminosidade);
  }
}