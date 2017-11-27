#include <AccelStepper.h>

AccelStepper stepper; // Defaults to AccelStepper::FULL4WIRE (4 pins) on 2, 3, 4, 5

void setup()
{  
  pinMode(7, INPUT);
  digitalWrite(7, LOW);
   stepper.setMaxSpeed(675);
   stepper.setAcceleration(500);
   stepper.setSpeed(670);  
}

void loop()
{  
   stepper.move(0-stepper.currentPosition());
   while(stepper.distanceToGo() != 0){
    if(digitalRead(7)){
      stepper.setCurrentPosition(stepper.currentPosition()+stepper.distanceToGo() );
    }
    else {
      stepper.run();
    }
    }
   
}
