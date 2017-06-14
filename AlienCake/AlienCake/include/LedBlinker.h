/*
 * led_blinker.h
 *
 * Created: 2017-06-10 21:41:38
 *  Author: Bunchu
 */ 


#ifndef LED_BLINKER_H_
#define LED_BLINKER_H_


class LedBlinker
{
	public:
		LedBlinker(int);
		~LedBlinker();
		void TurnOn();
		void TurnOff();
	private:
		int m_ledPin;
};

#endif /* LED_BLINKER_H_ */