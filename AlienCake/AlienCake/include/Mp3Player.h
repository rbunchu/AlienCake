/*
 * mp3_player.h
 *
 * Created: 6/14/2017 8:38:54 AM
 *  Author: mkamuda
 */ 


#ifndef MP3_PLAYER_H_
#define MP3_PLAYER_H_

#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

class Mp3Player
{
	public:
		Mp3Player(int, int);
		~Mp3Player();
		void Play();
		void Stop();
	private:
		int m_rxPin;
		int m_txPin;
		SoftwareSerial *m_softwareSerial;
		DFRobotDFPlayerMini m_mp3Player;
		void VolumeMax();
};

#endif /* MP3_PLAYER_H_ */