/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <LedBlinker.h>
#include <LengthSensor.h>
#include <Mp3Player.h>
#include <HardwareSerial.h>

/*End of auto generated code by Atmel studio */
#define PIN_D4 4

//Detector pins
#define TRIG_PIN 6
#define ECHO_PIN 7

//Mp3 player pins
#define MP3_TX 11
#define MP3_RX 10

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio
LedBlinker led(PIN_D4);
LengthSensor sensor(ECHO_PIN, TRIG_PIN);
Mp3Player *mp3;

void setup() {
	#ifdef DEBUG
		Serial.begin(9600);
		Serial.println("Starting program for Alien Cake");
	#endif
	// put your setup code here, to run once:
	mp3 = new Mp3Player(MP3_RX, MP3_TX);

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
		mp3->Play();
		delay(2000);
	}
	
	led.TurnOff();
}
