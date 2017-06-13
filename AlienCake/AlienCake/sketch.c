/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include "led_blinker.h"
#include "length_detector.h"
#include "hardware_serial_wrapper.h"

/*End of auto generated code by Atmel studio */
#define PIN_D4 5

//Detector pins
#define TRIG_PIN 8
#define ECHO_PIN 9

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio

led_blinker *led;
length_detector *detector;

#ifdef DEBUG
HardwareSerial *serial;
#endif

void setup() {
	#ifdef DEBUG
		serial = hardware_serial_get();
		hardware_serial_begin(serial, 9600);
		hardware_serial_println(serial, "Starting program for Alien Cake");
	#endif
	// put your setup code here, to run once:
	led = led_create(PIN_D4);
	detector = length_detector_create(TRIG_PIN, ECHO_PIN);
	
	led_turn_off(led->led_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
	int distance = length_detector_measure(detector);
	
	if(distance > 0)
	{
		led_turn_on(led->led_pin);
		delay(2000);
	}
	
	led_turn_off(led->led_pin);
}
