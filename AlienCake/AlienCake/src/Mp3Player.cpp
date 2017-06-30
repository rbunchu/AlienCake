/*
 * mp3_player.c
 *
 * Created: 6/14/2017 8:49:43 AM
 *  Author: mkamuda
 */ 

#include <Arduino.h>
#include <Mp3Player.h>


Mp3Player::Mp3Player(int rxPin, int txPin, int busyPin)
{
	m_rxPin = rxPin;
	m_txPin = txPin;
	m_busyPin = busyPin;
	pinMode(m_busyPin, INPUT);
	m_softwareSerial = new SoftwareSerial(m_rxPin, m_txPin);
	m_softwareSerial->begin(9600);
	if(!m_mp3Player.begin(*m_softwareSerial))
	{
		#ifdef DEBUG
			Serial.println("Unable to begin:");
			Serial.println("1. Please recheck the connection!");
			Serial.println("2. Please insert SD card!");
		#endif
		//Hangs here if something goes wrong
		while(true);
	}

	#ifdef DEBUG
		Serial.println("MP3 player is online");
	#endif
	m_mp3Player.EQ(DFPLAYER_EQ_NORMAL);
	m_mp3Player.outputDevice(DFPLAYER_DEVICE_SD);

	VolumeMax();
}

Mp3Player::~Mp3Player()
{	
	delete m_softwareSerial;
}

void Mp3Player::VolumeMax()
{
	//Sets max volume
	m_mp3Player.volume(30);
}

void Mp3Player::Play()
{
	m_mp3Player.playMp3Folder(2);
}

void Mp3Player::Stop()
{
	m_mp3Player.stop();	
}

boolean Mp3Player::isBusy()
{
	int value = digitalRead(m_busyPin);
	return value == LOW;
}

