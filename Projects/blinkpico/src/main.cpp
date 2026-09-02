#include <Arduino.h>
const uint8_t LED_PIN = LED_BUILTIN;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // Turn LED on
  delay(500);                  // Wait 1 second

  digitalWrite(LED_PIN, LOW);   // Turn LED off
  delay(500);                  // Wait 1 second
}