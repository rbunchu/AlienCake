#include <LengthSensor.h>


LengthSensor::LengthSensor(int echoPin, int trigPin)
{
	m_echoPin = echoPin;
	m_trigPin = trigPin;
	
	pinMode(m_echoPin, INPUT);
	pinMode(m_trigPin, OUTPUT);
}

void LengthSensor::Ping()
{	
	digitalWrite(m_trigPin, HIGH);
	delay(10);
	digitalWrite(m_echoPin, LOW);
}

int LengthSensor::Measure()
{	
	  Ping();
	  
	  //wait for high state, it can never occure. Wait for few milisekonds. Maybe try tree times before returning -1
	  if(digitalRead(m_echoPin) != HIGH)
	  {
		  return -1;
	  }
	  
	  int time = 0;
	  while(digitalRead(m_echoPin) != LOW) {
		  time++;
		  delay(1);
	  }
	  
	  return (time * 34) / 2000;
}
