// Include the libraries we need
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

/*------------PHOTORESISTOR---------------*/
int ldr = 0;
/*------------END PHOTORESISTOR---------------*/
/*------------RELAY---------------*/
int relay = 3;
/*------------END RELAY---------------*/
/*------------SOUND CLAP---------------*/
int sound_sensor = 4;
int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;
/*------------END SOUND CLAP---------------*/

LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

// arrays to hold device address
DeviceAddress insideThermometer;


/*
 * Setup function. Here we do the basics
 */
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  lcd.init();                     
  lcd.backlight();
  lcd.clear();

  pinMode(sound_sensor, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(13, OUTPUT);
  
  
  // locate devices on the bus
  Serial.print("Locating devices...");
  sensors.begin();
  Serial.print("Found ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" devices.");

  // report parasite power requirements
  Serial.print("Parasite power is: "); 
  if (sensors.isParasitePowerMode()) Serial.println("ON");
  else Serial.println("OFF");

  if (!sensors.getAddress(insideThermometer, 0)) Serial.println("Unable to find address for Device 0"); 
 
  printAddress(insideThermometer);

  // set the resolution to 9 bit (Each Dallas/Maxim device is capable of several different resolutions)
  sensors.setResolution(insideThermometer, 9);
  if(digitalRead(relay) == HIGH){
    digitalWrite(relay, LOW);
  }
}

// function to print the temperature for a device
void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  lcd.home();
  lcd.print("Temp C: ");
  lcd.print(tempC);
  lcd.print("  ");
  lcd.setCursor(0, 1);
  lcd.print("LUM:");
  lcd.print(analogRead(ldr));
  lcd.print(" ");
  lcd.print("Rele: ");
  lcd.print(digitalRead(relay));
  delay(100);
}
/*
 * Main function. It will request the tempC from the sensors and display on Serial.
 */
void loop(void)
{ 
  soundClap();
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  sensors.requestTemperatures(); // Send the command to get temperatures
 
  printTemperature(insideThermometer); // Use a simple function to print out the data
  if (analogRead(ldr) < 200) {
    
    lcd.backlight();
    digitalWrite(relay, LOW);
  }
  else {
    lcd.noBacklight();
    digitalWrite(relay, HIGH);
  }
  
}

// function to print a device address
void printAddress(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}

void soundClap(){
  int status_sensor = digitalRead(sound_sensor);
  if (status_sensor == 0)
  {
    if (clap == 0)
    {
      detection_range_start = detection_range = millis();
      clap++;
    }
    else if (clap > 0 && millis() - detection_range >= 50)
    {
      detection_range = millis();
      clap++;
    }
  }
  if (millis() - detection_range_start >= 350)
  {
    if (clap == 2)
    {
      if (digitalRead(relay) == 0)
      {
        digitalWrite(relay, LOW);
        delay(150);
        digitalWrite(relay, HIGH);
        delay(500);
        digitalWrite(relay, LOW);
        delay(150);
        digitalWrite(relay, HIGH);
      }
      else if (digitalRead(relay) == 1)
      {
        digitalWrite(relay, HIGH);
        delay(2000);
        digitalWrite(relay, LOW);
      }
      
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1500);
      digitalWrite(LED_BUILTIN, LOW);
    }
    clap = 0;
  }
}

