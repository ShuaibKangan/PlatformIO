#include <Arduino.h>
#include <Wire.h>
// put function declarations here:

constexpr uint8_t ledPins[3] = {38, 39, 40};
constexpr uint8_t buttons[3] = {42, 41, 1};



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  for (int i = 0; i < 3; i++) {
   pinMode(buttons[i], INPUT_PULLUP);   // configures all 4 pins with one loop, not four pinMode() calls
  }

  
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);   // configures all 4 pins with one loop, not four pinMode() calls
  }
}


void lightSwitch() {
  for (int i = 0; i <= 2; i++) {
    if (digitalRead(buttons[i]) == LOW) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
   lightSwitch();

}



// put function definitions here: