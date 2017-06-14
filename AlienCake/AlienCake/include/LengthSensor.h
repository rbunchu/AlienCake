#ifndef LENGTH_DETECTOR_H
#define LENGTH_DETECTOR_H

#include <Arduino.h>
#include <stdlib.h>


class LengthSensor
{
public:
	LengthSensor(int, int);
	int Measure();
private:
	int m_echoPin;
	int m_trigPin;
	void Ping();
};

#endif
