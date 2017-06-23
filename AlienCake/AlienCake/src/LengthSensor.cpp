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
	delayMicroseconds(10);
	digitalWrite(m_trigPin, LOW);
}

int LengthSensor::Measure()
{	
	  Ping();
	  
	  //wait for high state, it can never occure. Wait for few milisekonds. Maybe try tree times before returning -1
	  while(digitalRead(m_echoPin) != HIGH)
	  {
		  delayMicroseconds(1);
	  }
	  
	  unsigned long time = micros();
	  while(digitalRead(m_echoPin) != LOW) {
		  delayMicroseconds(1);
	  }

	  time = micros() - time;
	  Serial.println(time);	  
	  return (time * 34) / 2000;
}
