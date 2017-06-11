/*
 * led_blinker.c
 *
 * Created: 2017-06-10 21:44:28
 *  Author: Bunchu
 */ 

#include "Arduino.h"
#include "led_blinker.h"


led_blinker* led_create(int led_pin)
{
	led_blinker *led = malloc(sizeof(led_blinker));
	led->led_pin = led_pin;
	led->turn_on = led_turn_on;
	led->turn_off = led_turn_off;
	led_init(led->led_pin);

	return led;
}

void led_destroy(led_blinker* led)
{
	free(led);
}

void led_init(int led_pin)
{
	pinMode(led_pin, OUTPUT);
}
 
void led_turn_on(int led_pin)
{
	digitalWrite(led_pin, HIGH);
}

void led_turn_off(int led_pin)
{
	digitalWrite(led_pin, LOW);
}
