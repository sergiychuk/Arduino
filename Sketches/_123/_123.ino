#include <Arduino.h>
#include <TM1637Display.h>
#include <Servo.h>

#define CLK 4
#define DIO 5
Servo myservo;
int rotSpeed = 0;
TM1637Display display(CLK, DIO);

int echoPin = 9;
int trigPin = 8;
bool isOpen;
bool showCm = true;
int duration, cm;

void ultrasonicSensor() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = duration / 58;
}

void printResult() {
  Serial.print(cm);
  Serial.println(" cm");
  delay(100);
  if (showCm) {
    display.showNumberDec(cm, false);
  }
  else {
    display.showNumberDec(duration, false);
  }
}

void servoMotor() {
  int pos;
  if (!isOpen) {
    for (pos = 5; pos <= 175; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(rotSpeed);    
      if(pos == 175){
        isOpen = true;
        return;
      }
    }
    
  }
  if (isOpen) {
    for (pos = 175; pos >= 5; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(rotSpeed); 
      if(pos == 5){
        isOpen = false;
        return;
      }
    }

  }
}

void setup() {

  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  display.setBrightness(7);
  myservo.attach(10);
  myservo.write(5);
  isOpen = false;
}
void loop() {
  ultrasonicSensor();
  if (cm > 0 && cm <= 10) {
    servoMotor();
  }
  printResult();
}
