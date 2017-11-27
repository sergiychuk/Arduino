void setup()  { 
  pinMode(9, OUTPUT);   // устанавливаем 9 ногу как выход 
  beep(50);
  beep(50);
  beep(50);
  delay(1000);
} 
 
void loop()  {
  int i = 10; 
 
  
  if(i < 255){
    i+=10;
  }
   beep(i); 
}
 
void beep(unsigned char delayms){
  analogWrite(9, delayms);
  delay(500);
}
