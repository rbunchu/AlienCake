/*
 * led_blinker.c
 *
 * Created: 2017-06-10 21:44:28
 *  Author: Bunchu
 */ 

#include <Arduino.h>
#include <LedBlinker.h>


LedBlinker::LedBlinker(int ledPin)
{
	m_ledPin = ledPin;
	pinMode(m_ledPin, OUTPUT);	
}

LedBlinker::~LedBlinker()
{	
	//None
}

void LedBlinker::TurnOn()
{	
	digitalWrite(m_ledPin, HIGH);
}

void LedBlinker::TurnOff()
{
	digitalWrite(m_ledPin, LOW);
}
