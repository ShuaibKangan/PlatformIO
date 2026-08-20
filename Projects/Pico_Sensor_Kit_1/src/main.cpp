#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1327.h>


#define Led_Pin 35
#define Button_Pin 14
#define buzzer 37
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SDA_PIN 17
#define SCL_PIN 18  

// creates an OLED display object using the I2C Wire connection.
Adafruit_SSD1327 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
//--------------------------------------------------My function for somplified code------------------------------------------------
//function for beep
void beep(int onPress, int pitch) {
  tone(buzzer, pitch);
  delay(onPress);
}

void RUNN(int startTimer) {
  for (int i = 0; i < 20; i++) {
    tone(buzzer, 500);
    delay(startTimer);

    noTone(buzzer);
    delay(startTimer);

    startTimer -= 50;
    if (startTimer < 20) {
      startTimer = 20;
    } 

  }

}

void timesUp() {
  tone(buzzer, 1000);
  delay(200);
  noTone(buzzer);

  tone(buzzer, 1000);
  delay(200);
  noTone(buzzer);

  tone(buzzer, 1000);
  delay(200);
  noTone(buzzer);

}

void greetings() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Hello!");
  display.println("+-+-+-+-+");
  display.display();
}

void analaysing() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("*analysing face(s)*");
  display.display();
  delay(2000);
}

void intruder() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print(".......");
  display.println("You're not my creator...");
  display.display();
}
void attack() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("PREPARE TO DIE!");
  display.println("Self Destruction.");
  display.display();
}

//--------------------------------------SETUP FUNCTION------------------------------------------------------
void setup() {
  //declareing system begin
  Serial.begin(115200);
  // Starts I2C communication using the selection SDA and SCL pins.
  Wire.begin(SDA_PIN,  SCL_PIN);

//--------------OLED Display part Begin----------------------- 
  //starts the OLED display.
  if (!display.begin(0x3C, true)) { 
    Serial.println("SSD1327 OLED allocation failed! Check wiring/address.");
  } else {
    Serial.println("OLED Initialized Successfully!");
  }

  //connecting LED and Button
  pinMode(Led_Pin, OUTPUT); 
  pinMode(Button_Pin, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);

  display.clearDisplay(); //clears anything and everything stored in the buffer.
  display.setTextColor(SSD1327_WHITE); //Sets text colour to white.
  display.setTextSize(1);  //Set the text size to 1 which is the smallest standard.

  display.display();

//----------------OLED Display part END-----------------------
  //beginning lights as off.

  //buzzer pin setup.
  
}

void loop() {
  
  //Declaring a new variable as an int.
  int buttonState = digitalRead(Button_Pin);

  if (buttonState == LOW) {
    digitalWrite(Led_Pin, HIGH);
    Serial.println("Button pressed");

    beep(200, 1000);
    noTone(buzzer);
    delay(200);
    //Evil robot awakens!
    greetings();
    delay(1000);

    analaysing();
    delay(1000);

    intruder();
    delay(1000);

    attack();
    RUNN(500);
    timesUp();



  } else {
    digitalWrite(Led_Pin, LOW);
    digitalWrite(buzzer, LOW);

  }
  

}