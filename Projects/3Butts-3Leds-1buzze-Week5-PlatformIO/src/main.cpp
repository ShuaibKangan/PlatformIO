#include <Arduino.h>
#include <Wire.h>
#include "pitches.h"
// put function declarations here:

constexpr uint8_t ledPins[3] = {38, 39, 40};
constexpr uint8_t buttons[3] = {42, 41, 1};
constexpr uint8_t speaker[1] = {11};



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  for (int i = 0; i < 3; i++) {
   pinMode(buttons[i], INPUT_PULLUP);
   pinMode(ledPins[i], OUTPUT);   // configures all 4 pins with one loop, not four pinMode() calls
  }


    pinMode(speaker[0], OUTPUT);

}

void moogcity2() {
  if(digitalRead(buttons[0]) == LOW) { 
  tone(speaker[0], 330);
  delay(250);
  tone(speaker[0], 392);
  delay(250);
  tone(speaker[0], 440);
  delay(250);
  tone(speaker[0], 494);
  delay(250);
  tone(speaker[0], 494);
  delay(250);
  tone(speaker[0], 587);
  delay(250);
  tone(speaker[0], 329);
  delay(250);
  tone(speaker[0], 392);
  noTone(speaker[0]);
  } else if(digitalRead(buttons[1]) == LOW) {
    noTone(speaker[0]);
    delay(200);
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
   moogcity2();

}



// put function definitions here: