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
* Get Hardware serial Handle
*/
HardwareSerial* hardware_serial_get(void);
void hardware_serial_begin(HardwareSerial *,int);
void hardware_serial_println(HardwareSerial*, const char *);

#ifdef __cplusplus
}
#endif


#endif /* HARDWARE_SERIAL_WRAPPER_H_ */