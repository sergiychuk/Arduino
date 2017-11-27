int val;
int flag;

void setup() {
  // put your setup code here, to run once:
// TCCR1B = TCCR1B & 0b11111000 | 0x01;
  
  Serial.begin(9600); // Задаем скорость обмена com-порта 9600
  pinMode(10, OUTPUT);//infrared transistor
  pinMode(A5, INPUT);//signal
  pinMode(9, OUTPUT);//infrared diode
  pinMode(3, OUTPUT);//power diode
  pinMode(4, OUTPUT);//signal diode
  
 
  flag = 0;
  digitalWrite(3, HIGH);
  digitalWrite(10,HIGH);
}

void loop() {
  
  // put your main code here, to run repeatedly:
    //digitalWrite(10,HIGH);
    digitalWrite(9,HIGH);
    val = analogRead(A5);
    digitalWrite(9,LOW);
    
        delay(1000);
  Serial.println(val);
 if (val<900)
 {
  if (flag==0)
  {
    Serial.print("Signal = ");
    Serial.print(val);
    Serial.print("\n");
    flag=1;
    digitalWrite(4, HIGH);
  }
 }
 else if (flag==1)
  {
    Serial.println("No signal");
    flag=0;
    digitalWrite(4, LOW);
  } 
  
}
