/*
 * mp3_player.c
 *
 * Created: 6/14/2017 8:49:43 AM
 *  Author: mkamuda
 */ 

#include <Arduino.h>
#include <Mp3Player.h>


Mp3Player::Mp3Player(int rxPin, int txPin)
{
	m_rxPin = rxPin;
	m_txPin = txPin;
	m_softwareSerial = new SoftwareSerial(m_rxPin, m_txPin);
	m_softwareSerial->begin(9600);
	if(!m_mp3Player.begin(*m_softwareSerial))
	{
		#ifdef DEBUG
			Serial.println("Unable to begin:");
			Serial.println("1. Please recheck the connection!");
			Serial.println("2. Please insert SD card!");
		#endif
		//Handgs here if something goes wrong
		while(true);
	}
	
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
	m_mp3Player.play(1);
}

void Mp3Player::Stop()
{
	m_mp3Player.stop();	
}
