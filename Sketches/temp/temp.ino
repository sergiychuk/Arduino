#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 2

long lastTemp = 0;
float tempC;

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

DeviceAddress insideThermometer;

/*
 * Setup function. Here we do the basics
 */
void setup(void)
{
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  digitalWrite(3, HIGH);
  sensors.begin();
  sensors.setResolution(insideThermometer, 9);
  digitalWrite(3, LOW);
}

void loop(void)
{ 
  digitalWrite(3, HIGH);
  delay(100);
  sensors.requestTemperatures(); // Send the command to get temperatures
  getTemperature(insideThermometer);
  if(lastTemp != tempC){
    
    lastTemp = tempC;
  }
  digitalWrite(3, LOW);
}

void getTemperature(DeviceAddress deviceAddress)
{
  tempC = sensors.getTempC(deviceAddress);
  Serial.print("Temperature C: ");
    Serial.println(tempC);
}
