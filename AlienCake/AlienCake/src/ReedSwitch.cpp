/*
 * ReedSwitch.cpp
 *
 * Created: 2017-06-30 15:20:53
 *  Author: Bunchu
 */ 

 #include <ReedSwitch.h>
 #include <Arduino.h>

 ReedSwitch::ReedSwitch(int reedPin)
 {
	m_reedPin = reedPin;
	pinMode(m_reedPin, INPUT_PULLUP);
 }

 int ReedSwitch::Check()
 {
	#ifdef DEBUG
		Serial.println("Checking if reed is connected");
	#endif

	int result = digitalRead(m_reedPin);
	#ifdef DEBUG
		Serial.println(result);
	#endif

	return result;
 }