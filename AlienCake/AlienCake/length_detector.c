#include "length_detector.h"


length_detector *length_detector_create(int trig_pin, int echo_pin)
{
  length_detector * detector = malloc(sizeof(length_detector));
  detector->trig_pin = trig_pin;
  detector->echo_pin = echo_pin;
  length_detector_init(detector);
  return detector;
}

void length_detector_init(length_detector * detector)
{
  pinMode(detector->trig_pin, OUTPUT);
  pinMode(detector->echo_pin, INPUT);
}

void length_detector_ping(int trig_pin)
{
  digitalWrite(trig_pin, HIGH);
  delay(10);
  digitalWrite(trig_pin, LOW);
}

int length_detector_measure(length_detector * detector)
{
  length_detector_ping(detector->trig_pin);
  
  //wait for high state, it can never occure. Wait for few milisekonds. Maybe try tree times before returning -1
  if(digitalRead(detector->echo_pin) != HIGH)
  {
    return -1;
  }
  
  int time = 0;  
  while(digitalRead(detector->echo_pin) != LOW) {
    time++;
    delay(1);
  }
  
  return (time * 34) / 2000;
}

void length_detector_free(length_detector *detector)
{	
	free(detector);
}
