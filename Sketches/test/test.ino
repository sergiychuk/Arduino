


void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(6, HIGH);
  delay(2000);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(2, HIGH);
  delay(2000);
  digitalWrite(2, LOW);
  delay(100);
  digitalWrite(8, HIGH);
  delay(5000);
  digitalWrite(8, LOW);
  delay(100);
}
