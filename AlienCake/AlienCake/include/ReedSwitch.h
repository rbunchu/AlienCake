/*
 * ReedSwitch.h
 *
 * Created: 2017-06-30 15:09:00
 *  Author: Bunchu
 */ 


#ifndef REEDSWITCH_H_
#define REEDSWITCH_H_

class ReedSwitch
{
	private:
		int m_reedPin;
	public:
		ReedSwitch(int reedPin);
		//Checks if reed is connected
		int Check();
};



#endif /* REEDSWITCH_H_ */