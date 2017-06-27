/*
 * MotorDriver.h
 *
 * Created: 6/14/2017 12:04:56 PM
 * Author: mkamuda
 * Using L293D driver
 */ 


#ifndef MOTORDRIVER_H_
#define MOTORDRIVER_H_

enum MotorDirection
{
	COUNTER_CLOCKWISE = 0,
	CLOCKWISE = 1
};

//Type of motor canal. L293D has two canals
enum DriverCanalType
{
	CANAL_1 = 0,
	CANAL_2 = 1
};

//Motor driver pin connection for one canal
class MotorDriverCConfig
{
	private:
		int m_input1;
		int m_input2;
		int m_enable;
	public:
		MotorDriverCConfig(int, int, int);
		int GetInput1();
		int GetInput2();
		int GetEnable();
		void SetInput(int, int);
		void SetEnable(int);
};


class MotorDriver
{
	public:
		MotorDriver(MotorDriverCConfig *, MotorDriverCConfig *);
		//Starts one of the motor with initial speed
		void Start(DriverCanalType, int);
		//Changes speed of motor. Max value is 255
		void ChangeSpeed(DriverCanalType type, unsigned int);
		//Changes direction of motor spinning
		void ChangeDirection(DriverCanalType, MotorDirection);
		//Stops motor
		void Stop(DriverCanalType);
	private:
		MotorDriverCConfig *m_canal1;
		MotorDriverCConfig *m_canal2;
		MotorDirection m_motorDirection;
		unsigned int m_motorSpeed;
		void Initialize(MotorDriverCConfig *);
};



#endif /* MOTORDRIVER_H_ */