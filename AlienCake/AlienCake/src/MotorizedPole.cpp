/*
 * MotorizedPole.cpp
 *
 * Created: 6/27/2017 10:09:06 AM
 *  Author: mkamuda
 */ 

#include <Arduino.h>
#include <MotorizedPole.h>

#define HALFSTEP 8

MotorizedPole::MotorizedPole(int in1, int in2, int in3, int in4, double distance)
{
	m_in1 = in1;
	m_in2 = in2;
	m_in3 = in3;
	m_in4 = in4;
	m_distance = distance;
	
	m_stepper = new AccelStepper(HALFSTEP, m_in1, m_in2, m_in3, m_in4);
	m_stepper->setMaxSpeed(1000.0);
	m_stepper->setAcceleration(100.0);
	m_stepper->setSpeed(200);
}

void MotorizedPole::Extend()
{
	m_stepper->moveTo(m_distance);
	while(m_stepper->distanceToGo() != 0)
	{
		//wait to motor finish it distance
		delay(1);
	}
}

void MotorizedPole::Retract()
{
	m_stepper->moveTo(-m_distance);
	while(m_stepper->distanceToGo() != 0)
	{
		delay(1);
	}		
}