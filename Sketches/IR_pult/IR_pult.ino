#include <IRremote.h>
 
int RECV_PIN = 5;
 
IRrecv irrecv(RECV_PIN);
IRsend irsend;
 
decode_results results;
 
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
 
void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  
  irsend.sendNEC(0xFD00FF, 32);
        delay(40);
  
  /*if (Serial.available() > 0){
    int x = Serial.read();
    if(x == 1){
      
    }
    if(x == 2){
      
    }
    if(x == 3){
      
    }
  }*/
}
