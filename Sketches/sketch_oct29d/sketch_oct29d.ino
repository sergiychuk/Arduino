int ENA = 7; 
int IN1 = 9;
int IN2 = 5;
int ENB = 3; 
int IN3 = 6;
int IN4 = 10;
int pause = 100;


void setup() {
  pinMode(ENA, OUTPUT);    
  pinMode(IN1, OUTPUT); 
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);    
  pinMode(IN3, OUTPUT); 
  pinMode(IN4, OUTPUT);
}

void loop() {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  

  
for (int i=0; i <= 10; i++){
  digitalWrite(IN4, HIGH);
  digitalWrite(IN2, HIGH);
  delay(pause);
  digitalWrite(IN4, LOW);
  digitalWrite(IN2, LOW);
   
  
  digitalWrite(IN3, HIGH);
   digitalWrite(IN1, HIGH);
  delay(pause);
  digitalWrite(IN1, LOW);
  digitalWrite(IN3, LOW);
  pause -= 1;
  }
  
}
