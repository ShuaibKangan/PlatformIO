#include <Arduino.h>
#include <wire.h>
// put function declarations here:

constexpr uint8_t ledPin[3] = {33, 40, 18};
constexpr uint8_t buttonz[3] = {37, 42, 41};



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(ledPin[0, 1, 2], OUTPUT);
  pinMode(buttonz[0, 1, 2], INPUT_PULLUP);
  digitalWrite(ledPin[0, 1, 2], HIGH);


}

void loop() {
  // put your main code here, to run repeatedly:

}

void green(){
  
  if (digitalRead(buttonz[0]) == HIGH) {
        digitalWrite(ledPin[0], LOW);
  } else {
    digitalWrite(ledPin[0], HIGH);
  }
}


// put function definitions here: