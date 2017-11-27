int pirPin =4;
int ledPin = 2;
int timer;
bool setTime = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); //указываем, что светодиод - выход
  pinMode(pirPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  long nowTie;
  digitalWrite(ledPin, digitalRead(pirPin));
  // put your main code here, to run repeatedly:
  if(digitalRead(pirPin) == HIGH){
    
    setTime = true;
  }
  else nowTie = (millis() - timer)/1000;
  Serial.println(nowTie);
  if(setTime){
    timer = millis();
    setTime = false;
  }
}
