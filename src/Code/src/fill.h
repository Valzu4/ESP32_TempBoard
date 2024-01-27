#pragma once

#define DHTPIN 5      // ESP8266: 12 (D6), DEVBoard: 5
#define DHTTYPE DHT22 // DHT 22  (AM2302)
#define BATPIN 4      // ESP8266: A0 (A0), DEVBoard: 4
#define RED_LED_PIN 6
#define BLUE_LED_PIN 7

#define mqtt_server ""
#define mqtt_user ""
#define mqtt_password ""

#define mqtt_deviceName "esp_dht_outside"
#define mqtt_topic ""

#define wifi_hostname "ESP_DHT_OUT"
#define wifi_ssid ""
#define wifi_password ""

// Remove comment if on battery
#define ON_BAT

// Other modifyables

// Time between messages in ms (5000 ms = 5 sec)
#define TIME_BETWEEN_MESSAGES 6000

// Deepsleep time in microseconds
#define DEEPSLEEP_TIME 600e6