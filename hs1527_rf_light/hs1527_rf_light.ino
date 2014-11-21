#include "hs1527.h"

#define TXPIN 7 // Pin to transmit encoded data
HS1527 encoder(TXPIN);

#define LED_PIN 13


char *address = "\xBE\xA3\x90";

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(TXPIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(LED_PIN, HIGH);
    // Send multiple times to ensure the bulbs receive the message. 
    // They only toggle once.
    for (int j = 0; j < 5; j++) {
      encoder.sendMsg(address, i);
    }
    digitalWrite(LED_PIN, LOW);
    delay(250);
  }
  
  delay(1000);
}

