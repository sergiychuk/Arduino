#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <OneWire.h>
#include <DallasTemperature.h>

// If you're not using the Ethernet W5100 shield, change this to match your connection type. See Communications examples.
#include <CayenneEthernet.h>

// Virtual Pin of the DS18B20 widget.
#define VIRTUAL_PIN V1

// Digital pin the DS18B20 is connected to. Do not use digital pins 0 or 1 since those conflict with the use of Serial.
const int tmpPin = 2;

OneWire oneWire(tmpPin);
DallasTemperature sensors(&oneWire);

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "0b4yzazjmd";

void setup()
{
  Serial.begin(9600);
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
