#include <Arduino.h>
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "ESP8266WebServer.h"
#include <FirebaseArduino.h>

#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

int stu = 0;
String conteudo = "";
String endereco = " 04 78 35 7a 4f 51 80";

const int pin = 4;

void setup() {
    Serial.begin(9600);
    pinMode(pin, OUTPUT);

    // connect to wifi.
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("conectando");

    while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }

    Serial.println();
    Serial.print("conectado no ip: ");
    Serial.println(WiFi.localIP());
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  }

void loop(){
  
  Serial.println(Firebase.getInt("status"));

  if(Firebase.getInt("status") == 1){
    digitalWrite(pin,0);
  }else{
    digitalWrite(pin,1);
  }
}

/*
Equivalencia das saidas Digitais entre nodeMCU e ESP8266 (na IDE do Arduino)
NodeMCU � ESP8266
D0 = 16;
D1 = 5;
D2 = 4;
D3 = 0;
D4 = 2;
D5 = 14;
D6 = 12;
D7 = 13;
D8 = 15;
D9 = 3;
D10 = 1;
*/

//Pino do NodeMCU que estara conectado ao rele