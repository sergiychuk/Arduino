#include <EEPROM.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

uint8_t moneyCounter; //Здесь будем хранить чайевые
uint8_t money; //Здесь будем хранить чайевые

const int setButton = 2;
const int incButton = 3;
const int decrButton = 4;

int buttonSetState = 0;
int buttonIncState = 0;
int buttonDecrState = 0;

LiquidCrystal_I2C lcd(0x27,16,2);

void setup()
{
  pinMode(setButton, INPUT);
  pinMode(incButton, INPUT);
  pinMode(decrButton, INPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.clear();

}

void loop()
{
  buttonSetState = digitalRead(setButton);
  buttonIncState = digitalRead(incButton);
  buttonDecrState = digitalRead(decrButton);

  if(buttonSetState == HIGH){
    EEPROM.write(0, moneyCounter);
    buttonSetState = LOW;
    delay(100);
  }
  if(buttonIncState == HIGH){
    moneyCounter+=10;
    delay(100);
  }
  if(buttonDecrState == HIGH){
    moneyCounter-=10;
    delay(100);
  }
  lcd.setCursor(0, 0);
  lcd.print("Tea money: ");
  lcd.print(moneyCounter);
  lcd.setCursor(0, 1);
  lcd.print("Total money:");
  lcd.print(EEPROM.read(0));
}


