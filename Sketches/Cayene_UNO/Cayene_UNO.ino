#include <OneWire.h>
#include <DallasTemperature.h>

// If you're not using the Ethernet W5100 shield, change this to match your connection type. See Communications examples.
#include <CayenneSerial.h>

// Virtual Pin of the DS18B20 widget.
#define VIRTUAL_PIN V1

// Digital pin the DS18B20 is connected to. Do not use digital pins 0 or 1 since those conflict with the use of Serial.
const int tmpPin = 0;

OneWire oneWire(tmpPin);
DallasTemperature sensors(&oneWire);

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "e6vprxxbrt";

void setup()
{
  Cayenne.begin(token);
  sensors.begin();
}

void loop()
{
  Cayenne.run();
}

// This function is called when the Cayenne widget requests data for the Virtual Pin.
CAYENNE_OUT(VIRTUAL_PIN)
{
  // Send the command to get temperatures.
  sensors.requestTemperatures();
  // This command writes the temperature in Celsius to the Virtual Pin.
  Cayenne.celsiusWrite(VIRTUAL_PIN, sensors.getTempCByIndex(0));
  // To send the temperature in Fahrenheit use the corresponding code below.
  //Cayenne.fahrenheitWrite(VIRTUAL_PIN, sensors.getTempFByIndex(0));
}
