
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT SwSerial


#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
    
#include <BlynkSimpleStream.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "903e6b1233d34b82aaeb356a3c2f72ee";

BlynkTimer timer;

WidgetLED led1(V0);

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

void setup()
{
  // Debug console
  SwSerial.begin(9600);
  pinMode(6, INPUT);
  digitalWrite(6, LOW);
  // Blynk will work through Serial
  // Do not read or write this serial manually in your sketch
  Serial.begin(9600);
  Blynk.begin(Serial, auth);
  
  // Setup a function to be called every second
  timer.setInterval(125L, ledControll);
  
}
void ledControll(){
  if(digitalRead(3) != 0){
    led1.on();
  }
  else led1.off();
}
void valControll(int value){
  if(digitalRead(3) != 0 && digitalRead(6) != 0){
    led1.on();
    Blynk.virtualWrite(V1, toString("LED IS ON"));
  }
  else {
    Blynk.virtualWrite(V1, "LED IS OFF");
    led1.off();
  }
}
BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  
  
  SwSerial.print("V1 Slider value is: ");
  SwSerial.println(pinValue);
  //ledControll(pinValue);
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}

