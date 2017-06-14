/*
 * MotorDriver.cpp
 *
 * Created: 6/14/2017 12:05:12 PM
 *  Author: mkamuda
 */ 

#include <MotorDriver.h>
#include <Arduino.h>

MotorDriver::MotorDriver(int pwmEnablePin, int inputPin)
{
	m_pwmEnablePin = pwmEnablePin;
	m_inputPin = inputPin;
	m_motorDirection = MotorDirection::CLOCKWISE;
	m_motorSpeed = 0;	
	
	pinMode(m_pwmEnablePin, OUTPUT);
	digitalWrite(m_pwmEnablePin, LOW);
	pinMode(m_inputPin, OUTPUT);
	digitalWrite(m_inputPin, LOW);
}

void MotorDriver::Start(int speed)
{	
	analogWrite(m_pwmEnablePin, speed);
}

void MotorDriver::Stop()
{	
	analogWrite(m_pwmEnablePin, 0);
}

void MotorDriver::ChangeDirection(MotorDirection direction)
{
	if(direction == m_motorDirection)
	{		
		//do nothing if directions are the same
		return;	
	}
	
	if(direction == COUNTER_CLOCKWISE)
	{		
		digitalWrite(m_inputPin, HIGH);	
	}
	else
	{			
		digitalWrite(m_inputPin, LOW);
	}
}

void MotorDriver::ChangeSpeed(unsigned int speed)
{
	int actSpeed = speed;
	if(speed > 255)
	{
		actSpeed = 255;
	}

	analogWrite(m_pwmEnablePin, actSpeed);
}