#include <Servo.h>
#include <LiquidCrystal.h>

int button = 10;
int light = 9;
int buzzer = 11;
int motor = 3;
int pos = 0;
Servo baby;

void setup() {
  pinMode(button, INPUT);  //button
  pinMode(light, OUTPUT);  //light
  pinMode(buzzer, OUTPUT); //buzzer
  pinMode(motor, OUTPUT);  //motor
  baby.attach(motor);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(button) == HIGH) {
    digitalWrite(light, HIGH);  
    tone(buzzer, 1500, 1500);
    delay(800);
    tone(buzzer, 1200, 1000);
    
    for (pos = 0; pos <= 180; pos += 2) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      baby.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 0; pos -= 2) { // goes from 180 degrees to 0 degrees
      baby.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    
  }
  else { 
    digitalWrite(light, LOW);
    noTone(buzzer);
    baby.write(0);
  }
}
