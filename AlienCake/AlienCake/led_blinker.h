/*
 * led_blinker.h
 *
 * Created: 2017-06-10 21:41:38
 *  Author: Bunchu
 */ 


#ifndef LED_BLINKER_H_
#define LED_BLINKER_H_


typedef struct led_blinker
{
	int led_pin;
	void (*turn_on)(int);
	void (*turn_off)(int);
}led_blinker;

led_blinker *led_create(int);
void led_destroy(led_blinker*);
static void led_init(int);
static void led_turn_on(int);
static void led_turn_off(int);



#endif /* LED_BLINKER_H_ */