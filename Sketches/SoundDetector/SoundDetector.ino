int sound_sensor = 4;
int relay = 5;

int clap = 0;
long detection_range_start = 0;
long detection_range = 0;
boolean status_lights = false;

void setup() {
  pinMode(sound_sensor, INPUT);
  pinMode(relay, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  if(digitalRead(relay) == HIGH){
    digitalWrite(relay, LOW);
  }
  
}

void loop() {
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
      if (!status_lights)
      {
        status_lights = true;
        digitalWrite(relay, HIGH);
      }
      else if (status_lights)
      {
        status_lights = false;
        digitalWrite(relay, LOW);
      }
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1500);
      digitalWrite(LED_BUILTIN, LOW);
    }
    clap = 0;
    
  }
}
