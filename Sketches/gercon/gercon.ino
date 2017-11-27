const int switchPin = 2;
const int ledPin = LED_BUILTIN;

void setup() {
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, HIGH);
  pinMode(ledPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int g = digitalRead(switchPin);
  digitalWrite(ledPin, g);
  Serial.println(g);
  delay(100);
}
