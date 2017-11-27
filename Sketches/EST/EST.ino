#include "SevSeg.h"
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;
 int a = 1;
const int buzzer = A0;
SevSeg sevseg; //Initiate a seven segment controller object

void setup() {
  Wire.begin();
  RTC.begin();
    
  RTC.adjust(DateTime(__DATE__, __TIME__));
  
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
 bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE; // See README.md for options
  bool updateWithDelays = true; // Default. Recommended
  bool leadingZeros = true; // Use 'true' if you'd like to keep the leading zeros
  
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(10);
pinMode(buzzer, OUTPUT);
}

void loop() {
  DateTime now = RTC.now();
  buzzerTime(now.second());
  sevseg.setNumber(getDecimalTime(), 2);
  sevseg.refreshDisplay(); // Must run repeatedly  
}

int getDecimalTime()
{
  DateTime now = RTC.now();
  int decimalTime = now.minute() * 100 + now.second();
  return decimalTime;
}
void buzzerTime(int seconds){
  if(seconds == 59){
    for (int i=0; i<500; i++) {  // generate a 1KHz tone for 1/2 second
  tone(buzzer, 100);
  delayMicroseconds(500);
  noTone(buzzer);
  delayMicroseconds(500);
 }
  }
}

