/*
 * MotorDriver.cpp
 *
 * Created: 6/14/2017 12:05:12 PM
 *  Author: mkamuda
 */ 

#include <MotorDriver.h>
#include <Arduino.h>

MotorDriverCConfig::MotorDriverCConfig(int enable, int input1, int input2)
{
	m_enable = enable;
	m_input1 = input1;
	m_input2 = input2;
}

int MotorDriverCConfig::GetEnable()
{
	return m_enable;
}

int MotorDriverCConfig::GetInput1()
{
	return m_input1;
}

int MotorDriverCConfig::GetInput2()
{
	return m_input2;
}

void MotorDriverCConfig::SetInput(int input1, int input2)
{
	m_input1 = input1;
	m_input2 = input2;
}

void MotorDriverCConfig::SetEnable(int enable)
{
	m_enable = enable;
}


MotorDriver::MotorDriver(MotorDriverCConfig* canal1, MotorDriverCConfig* canal2)
: m_canal1(canal1), m_canal2(canal2)
{
	m_motorDirection = MotorDirection::CLOCKWISE;
	m_motorSpeed = 0;
	
	if(m_canal1 != NULL)
	{
		Initialize(m_canal1);
	}

	if(m_canal2 != NULL)
	{
		Initialize(m_canal2);
	}	
}

void MotorDriver::Start(DriverCanalType type, int speed)
{	
	MotorDriverCConfig *canal = type == DriverCanalType::CANAL_1 ? m_canal1 : m_canal2;
	if(canal == NULL)
	{
		//Do nothing if canal is not defined
		return;
	}
	
	analogWrite(canal->GetEnable(), speed);
}

void MotorDriver::Stop(DriverCanalType type)
{
	MotorDriverCConfig *canal = type == DriverCanalType::CANAL_1 ? m_canal1 : m_canal2;
	if(canal == NULL)
	{
		return;		
	}
	
	analogWrite(canal->GetEnable(), 0);
}

void MotorDriver::ChangeDirection(DriverCanalType type, MotorDirection direction)
{
	if(direction == m_motorDirection)
	{		
		//do nothing if directions are the same
		return;	
	}
	
	m_motorDirection = direction;

	MotorDriverCConfig *canal = type == DriverCanalType::CANAL_1 ? m_canal1 : m_canal2;
	if(canal == NULL)
	{
		return;
	}

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

	MotorDriverCConfig *canal = type == DriverCanalType::CANAL_1 ? m_canal1 : m_canal2;
	if(canal == NULL)
	{
		return;
	}

	analogWrite(canal->GetEnable(), actSpeed);
}

void MotorDriver::Initialize(MotorDriverCConfig *canal)
{
	pinMode(canal->GetEnable(), OUTPUT);
	pinMode(canal->GetInput1(), OUTPUT);
	pinMode(canal->GetInput2(), OUTPUT);
	analogWrite(canal->GetEnable(), 0);
	digitalWrite(canal->GetInput1(), LOW);
	digitalWrite(canal->GetInput2(), HIGH);
}