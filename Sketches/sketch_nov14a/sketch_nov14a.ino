#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,2);

void setup(){
  lcd.init();
  lcd.backlight();
   
  lcd.home();
  lcd.print("  THIS IS NOT");
  
  lcd.setCursor(0,1);  // ставим курсор на 1 символ второй строки
  lcd.print("  AMPETHAMINE"); // печатаем сообщение на второй строке
}

void loop(){
  
}
