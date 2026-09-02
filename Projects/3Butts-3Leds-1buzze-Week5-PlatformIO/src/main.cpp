#include <Arduino.h>
#include <Wire.h>
#include "pitches.h"
// put function declarations here:

constexpr uint8_t ledPins[3] = {38, 39, 40};
constexpr uint8_t buttons[3] = {42, 41, 1};
constexpr uint8_t speaker[1] = {14};



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  for (int i = 0; i < 3; i++) {
   pinMode(buttons[i], INPUT_PULLUP);   // configures all 4 pins with one loop, not four pinMode() calls
  }

  
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);   // configures all 4 pins with one loop, not four pinMode() calls
  }

  for(int s = 0; s < 1; s++) {
    pinMode(speaker[s], OUTPUT);
  }
}

void moogcity2() {
  if(digitalRead(buttons[0]) == LOW) {
    tone(speaker[0], NOTE_E4, 100);
  delay(300);
  tone(speaker[0], NOTE_G4, 100);
  delay(300);
  tone(speaker[0], NOTE_B4, 100);
  delay(300);
  tone(speaker[0], NOTE_D5, 100);
  delay(300);
  tone(speaker[0], NOTE_B4, 100);
  delay(300);
  tone(speaker[0], NOTE_G4, 100);
  delay(300);
  tone(speaker[0], NOTE_E4, 100);
  delay(300);
  tone(speaker[0], NOTE_G4, 100);
  } else if (digitalRead(buttons[1]) == LOW){
    noTone(speaker[0]);
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