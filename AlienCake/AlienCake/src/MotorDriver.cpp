/*
 * MotorDriver.cpp
 *
 * Created: 6/14/2017 12:05:12 PM
 *  Author: mkamuda
 */ 

#include <MotorDriver.h>
#include <Arduino.h>

MotorDriverCanal::MotorDriverCanal(int enable, int input1, int input2)
{
	m_enable = enable;
	m_input1 = input1;
	m_input2 = input2;
}

int MotorDriverCanal::GetEnable()
{
	return m_enable;
}

int MotorDriverCanal::GetInput1()
{
	return m_input1;
}

int MotorDriverCanal::GetInput2()
{
	return m_input2;
}

void MotorDriverCanal::SetInput(int input1, int input2)
{
	m_input1 = input1;
	m_input2 = input2;
}

void MotorDriverCanal::SetEnable(int enable)
{
	m_enable = enable;
}


MotorDriver::MotorDriver(MotorDriverCanal &canal1)
: m_canal1(canal1)
{
	m_motorDirection = MotorDirection::CLOCKWISE;
	m_motorSpeed = 0;	
	//First canal
	pinMode(m_canal1.GetEnable(), OUTPUT);
	pinMode(m_canal1.GetInput1(), OUTPUT);
	pinMode(m_canal1.GetInput2(), OUTPUT);
	digitalWrite(m_canal1.GetEnable(), LOW);
	digitalWrite(m_canal1.GetInput1(), LOW);
	digitalWrite(m_canal1.GetInput2(), HIGH);
}

void MotorDriver::Start(DriverCanalType type, int speed)
{	
	if(type == DriverCanalType::CANAL_1)
	{
		analogWrite(m_canal1.GetEnable(), speed);
	}
}

void MotorDriver::Stop(DriverCanalType type)
{
	if(type == DriverCanalType::CANAL_1)
	{
		analogWrite(m_canal1.GetEnable(), 0);
	}
}

void MotorDriver::ChangeDirection(DriverCanalType type, MotorDirection direction)
{
	if(direction == m_motorDirection)
	{		
		//do nothing if directions are the same
		return;	
	}
	
	m_motorDirection = direction;

	MotorDriverCanal *canal = &m_canal1;

	if(m_motorDirection == MotorDirection::COUNTER_CLOCKWISE)
	{
		digitalWrite(canal->GetInput1(), HIGH);
		digitalWrite(canal->GetInput2(), LOW);
	}
	else
	{
		digitalWrite(canal->GetInput1(), LOW);
		digitalWrite(canal->GetInput2(), HIGH);
	}
}

void MotorDriver::ChangeSpeed(DriverCanalType type, unsigned int speed)
{
	int actSpeed = speed;
	if(speed > 255)
	{
		actSpeed = 255;
	}

	analogWrite(m_canal1.GetEnable(), actSpeed);
}