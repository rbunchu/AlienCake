/*
 * MotorizedPole.h
 *
 * Created: 6/27/2017 10:08:50 AM
 *  Author: mkamuda
 *
 *	Based of stepper motor and ULN2003 driver
 */ 

#ifndef MOTORIZEDPOLE_H_
#define MOTORIZEDPOLE_H_

#include <AccelStepper.h>

class MotorizedPole
{
	private:
		int m_in1;
		int m_in2;
		int m_in3;
		int m_in4;
		double m_distance;
		AccelStepper *m_stepper;
	public:
		MotorizedPole(int in1, int in2, int in3, int in4, double distance);
		void Extend(void);
		void Retract(void);
};



#endif /* MOTORIZEDPOLE_H_ */