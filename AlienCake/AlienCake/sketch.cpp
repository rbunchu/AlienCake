/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
#include <LedBlinker.h>
#include <LengthSensor.h>
#include <Mp3Player.h>
#include <HardwareSerial.h>
#include <MotorDriver.h>
#include <ReedSwitch.h>

/*End of auto generated code by Atmel studio */
#define PIN_D4 4

//Detector pins
#define TRIG_PIN 6
#define ECHO_PIN 7

//Mp3 player pins
#define MP3_TX 11
#define MP3_RX 10
#define MP3_BUSY 3

//Motor pins
#define MOTOR_ENABLE 9
#define MOTOR_INPUT_1 8
#define MOTOR_INPUT_2 5

//Reed switch
#define PIN_D12 12

//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio
LedBlinker led(PIN_D4);
LengthSensor sensor(ECHO_PIN, TRIG_PIN);
Mp3Player *mp3;
MotorDriver driver(new MotorDriverCConfig(MOTOR_ENABLE, MOTOR_INPUT_1, MOTOR_INPUT_2), NULL);
ReedSwitch reedSwitch(PIN_D12);

unsigned long stopTime = 0;

void setup() {
	#ifdef DEBUG
		Serial.begin(9600);
		Serial.println("Starting program for Alien Cake");
	#endif
	// put your setup code here, to run once:
	mp3 = new Mp3Player(MP3_RX, MP3_TX, MP3_BUSY);
	delay(1000); //Wait 1 second to mp3 player init itself

	led.TurnOff();
	pinMode(PIN_D12, INPUT_PULLUP);
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
		 
	if(distance > 0 && distance < 60) //About 1 meter
	{
		led.TurnOn();
		//Check if player is playing mp3
		if(!mp3->isBusy())
		{
			mp3->Play();
		}		
		
		if(distance < 40) //half a meter turn on motorized pole
		{
			driver.Start(DriverCanalType::CANAL_1, 250);
			delay(3000);
			driver.Stop(DriverCanalType::CANAL_1);
			driver.ChangeDirection(DriverCanalType::CANAL_1, COUNTER_CLOCKWISE);
			driver.Start(DriverCanalType::CANAL_1, 250);
			while(reedSwitch.Check() != LOW)
			{
				//Run motor until switch is connected
				delay(10);
			}
			driver.Stop(DriverCanalType::CANAL_1);
		}
		delay(2000);
		stopTime = millis();
	}

	if(mp3->isBusy() && (millis() - stopTime > 1000))
	{
		mp3->Stop();
		stopTime = 0;
	}

	led.TurnOff();
}
