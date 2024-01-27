#pragma once

#include <Arduino.h>
#include <ArduinoJson.h>
#include <DHT.h>
// #include <ESP8266WebServer.h>
// #include <ESP8266WiFi.h>
#include <PubSubClient.h>
// #include <WiFiManager.h>
#include <WiFi.h>
#include <stdio.h>
#include <string.h>


#include "fill.h"

extern WiFiClient espClient;
extern PubSubClient client;
extern DHT dht;

void setup_wifi();
void reconnect();

void publishData(float p_temperature, float p_humidity, float p_battery);

// function called when a MQTT message arrived
void callback(char *p_topic, byte *p_payload, unsigned int p_length);
