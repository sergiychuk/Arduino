int enB = 5;
int in3 = 7;
int in4 = 6;
#define ANAL A0
int k = 100;
void setup() {
  pinMode(ANAL, INPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  /*for (int i = 0; i < 256; i++)
  {
    analogWrite(enB, i);
    delay(20);
    Serial.println(analogRead(ANAL));
  } 
  for (int i = 256; i < 0; i--)
  {
    analogWrite(enB, i);
    delay(20);
    Serial.println(analogRead(ANAL));
  }*/
  
  k = map(k, 0, 100, 0, 225);
  analogWrite(enB, k);
  Serial.println(analogRead(ANAL));
  delay(125);
}
