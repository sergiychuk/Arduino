/*

  Adafruit Arduino - RGB светодиод подробная инструкция на сайте:

  arduino-diy.com

*/

int redPin = 6;

int greenPin = 5;

int bluePin = 3;

//уберите тег комментария со строки ниже, если вы используете светодиод с общим анодом

#define COMMON_ANODE

void setup()

{

  pinMode(redPin, OUTPUT);

  pinMode(greenPin, OUTPUT);

  pinMode(bluePin, OUTPUT);

}

void loop()

{

  setColor(255, 0, 0); // красный

  delay(1000);

  setColor(0, 255, 0); // зеленый

  delay(1000);

  setColor(0, 0, 255); // синий

  delay(1000);

  

}

void setColor(int red, int green, int blue)

{

#ifdef COMMON_ANODE

  red = 255 - red;

  green = 255 - green;

  blue = 255 - blue;

#endif

  analogWrite(redPin, red);

  analogWrite(greenPin, green);

  analogWrite(bluePin, blue);

}
