#ifndef LENGTH_DETECTOR_H
#define LENGTH_DETECTOR_H

#include <Arduino.h>
#include <stdlib.h>


typedef struct length_detector {
  int echo_pin;
  int trig_pin;
} length_detector;

length_detector *length_detector_create(int, int);
void length_detector_free(length_detector *);
static void length_detector_init(length_detector *);
static void length_detector_ping(int);
int length_detector_measure(length_detector *);

#endif
