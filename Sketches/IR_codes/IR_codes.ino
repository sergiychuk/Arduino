#include <IRremote.h>
 
int RECV_PIN = 11;
String lastVal;
 
IRrecv irrecv(RECV_PIN);
 
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    if(irrecv.decode(&results) != "FFFFFFFF"){
      lastVal = irrecv.decode(&results);
      Serial.println(results.value, HEX);
    }
    else {
      Serial.println(lastVal);
    }
    
    irrecv.resume(); // Receive the next value
  }
}
