/*
 * MotorDriver.h
 *
 * Created: 6/14/2017 12:04:56 PM
 *  Author: mkamuda
 */ 


#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_

enum MotorDirection
{
	COUNTER_CLOCKWISE = 0,
	CLOCKWISE = 1
};

class MotorDriver
{
	public:
		MotorDriver(int, int);
		//Starts one of the motor with initial speed
		void Start(int);
		//Changes speed of motor. Max value is 255
		void ChangeSpeed(unsigned int);
		//Changes direction of motor spinning
		void ChangeDirection(MotorDirection);
		//Stops motor
		void Stop();
	private:
		int m_pwmEnablePin;
		int m_inputPin;
		MotorDirection m_motorDirection;
		unsigned int m_motorSpeed;
};



#endif /* MOTORDRIVER_H_ */