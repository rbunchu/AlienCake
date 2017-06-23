/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <LedBlinker.h>
#include <LengthSensor.h>
#include <HardwareSerial.h>

/*End of auto generated code by Atmel studio */
#define PIN_D4 4

//Detector pins
#define TRIG_PIN 6
#define ECHO_PIN 7

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio
LedBlinker led(PIN_D4);
LengthSensor sensor(ECHO_PIN, TRIG_PIN);

void setup() {
	#ifdef DEBUG
		Serial.begin(9600);
		Serial.println("Starting program for Alien Cake");
	#endif
	// put your setup code here, to run once:

	led.TurnOff();
}

void loop() {
	#ifdef DEBUG
		Serial.println("Distance detector on");
	#endif
  // put your main code here, to run repeatedly:
	int distance = sensor.Measure();
	
	#ifdef DEBUG
		Serial.println(distance);
	#endif
		
	if(distance > 0 && distance < 50)
	{
		led.TurnOn();
		delay(2000);
	}
	
	led.TurnOff();
}
