/*
 * object_detector.h
 *
 * Created: 2017-06-10 22:53:02
 *  Author: Bunchu
 */ 


#ifndef OBJECT_DETECTOR_H_
#define OBJECT_DETECTOR_H_


typedef struct object_detector
{
	int trigger_pin;
	int echo_pin;
	void (*send)(int);
	int (*detect)(int);
};

object_detector * object_detector_create(int, int);
void object_detector_free();
static void object_detector_send(int);
static void object_detector_detect(int);


#endif /* OBJECT_DETECTOR_H_ */