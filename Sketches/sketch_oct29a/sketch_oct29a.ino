#include <Stepper.h>
 
const int stepsPerRevolution = 2048;  //кол-во шагов на оборот
 
// initialize the stepper library on pins 2 3 4 5:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);        
  int previous=0;
void setup() {
  // set the speed at max 14 rpm:
  myStepper.setSpeed(10);
}
 
void loop()
{ 
  myStepper.step(10);
  delay(500);
}
