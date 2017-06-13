#ifndef LENGTH_DETECTOR_H
#define LENGTH_DETECTOR_H

#include <Arduino.h>


typedef struct length_detector {
  int echo_pin;
  int trig_pin;
  int (*measure)(int);
} length_detector;

length_detector *length_detector_create(int, int);
static void length_detector_init(length_detector *);
static void length_detector_ping(int);
static int length_detector_measure(length_detector *);

#endif
