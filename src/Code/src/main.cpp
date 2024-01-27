#include "fill.h"

#include "core.hpp"

int chk;
float hum;  // Stores humidity value
float temp; // Stores temperature value
float bat;
long lastMsg = -60000;

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  WiFi.hostname(wifi_hostname);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  dht.begin();

  pinMode(BATPIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

float readBat() {
#ifdef ON_BAT
  float read = analogRead(BATPIN);
  float state =
      (read * 3.1 / 4095.0) * 1.6; // esp 8266: read / 4095.0 * 5.25; with 220k
  return state;
#else
  return 0;
#endif
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  long now = millis();
  if (now - lastMsg > TIME_BETWEEN_MESSAGES) {
    lastMsg = now;

    hum = dht.readHumidity();
    temp = dht.readTemperature();
    bat = readBat();

    if (temp < 0) {
      temp = (INT16_MAX - temp * -10) * -0.1;
    }
    publishData(temp, hum, bat);

    // Print temp and humidity values to serial monitor
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.print(" Celsius, Bat: ");
    Serial.print(bat);
    Serial.println("V ");

    delay(100);

#ifdef ON_BAT
    Serial.println("Going to sleep");
    ESP.deepSleep(DEEPSLEEP_TIME);
#endif
  }
  // Read data and store it to variables hum and temp
}