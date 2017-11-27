#include <Servo.h>  //подключение библиотеки servo


Servo servoMotor;  

String inputString = "";         // переменная типа string для сохранения входных данных

//------функция получения и обробки данных с Serial порта--------//
void serialEvent() {
  while (Serial.available()) {
    // получить новый байт данных:
    char inChar = (char)Serial.read();
    
    // добавить новый байт к строковой переменной inputString:
    inputString += inChar;
  }
}

//------функция получения и обробки данных с Serial порта--------//


void setup() {
  servoMotor.attach(11); //выбираем девятый управляющий дискретный выход контроллера для управления моторчиком
  //инициализация последовательного порта:
  servoMotor.write(180);
  delay(1500);
  Serial.begin(9600);
  pinMode(2, INPUT);
  // получить 200 байтов и записать в переменную inputString:
  inputString.reserve(200);
  if(digitalRead(2) == HIGH){
    servoMotor.write(0);
  }
  if(digitalRead(2) == LOW){
    servoMotor.write(90); //выставляем изначальное положение серво в 0 градусов
  }
}


void loop() {
  serialEvent(); //вызов нашей коммуникационной функции
  Serial.println(inputString);
  delay(1050);
}



