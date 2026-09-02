#include <Arduino.h>
#include <Wire.h>
// put function declarations here:

constexpr uint8_t ledPins[3] = {38, 39, 40};
constexpr uint8_t buttons[3] = {42, 41, 1};
constexpr uint8_t speaker[1] = {11};

uint16_t moogverse[7] = {30, 65, 86, 109, 120, 132, 150};


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
  tone(speaker[0], 230);
  delay(250);
  tone(speaker[0], 390);
  delay(250);
  tone(speaker[0], 440);
  delay(250);
  tone(speaker[0], 494);
  delay(250);
  tone(speaker[0], 515);
  delay(250);
  tone(speaker[0], 574);
  delay(250);
  tone(speaker[0], 620);
  delay(300);
  tone(speaker[0], 690);
  delay(350);
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

  if (digitalRead(buttons[0]) == LOW) {
  for (int d = 0; d < 6; d++) {
    for (int i = 0; i < 7; i++) {
      tone(speaker[0], moogverse[i] + (moogverse[i] * d));
      if (i == 6) {
        delay(350);
      } else if (i == 7) {
        delay(400);
      } else {
        delay(300);
      }
    }
      
  }
  noTone(speaker[0]);
  } else if (digitalRead(buttons[1]) == LOW) {
    noTone(speaker[0]);
    delay(200);
  }


}