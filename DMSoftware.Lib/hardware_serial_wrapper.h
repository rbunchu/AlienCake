/*
 * hardware_serial_wrapper.h
 *
 * Created: 2017-04-23 22:56:21
 *  Author: Bunchu
 */ 


#ifndef HARDWARE_SERIAL_WRAPPER_H_
#define HARDWARE_SERIAL_WRAPPER_H_

#ifdef __cplusplus
extern "C" {
#endif

typedef struct HardwareSerial HardwareSerial;

/*
* Gets Hardware serial Handle
*/
HardwareSerial* hardware_serial_get(void);

/*
*	Setups hardware serial
*/
void hardware_serial_begin(HardwareSerial *,int);

/*
*	Prints characters to serial. New line
*/
void hardware_serial_println(HardwareSerial*, const char *);

/*
*	Prints number to serial. New line
*/
void hardware_serial_printNumber(HardwareSerial*, int);

#ifdef __cplusplus
}
#endif


#endif /* HARDWARE_SERIAL_WRAPPER_H_ */