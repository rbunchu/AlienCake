/*
 * hardware_serial_wrapper.cpp
 *
 * Created: 2017-04-23 22:56:57
 *  Author: Bunchu
 */ 

 #include "HardwareSerial.h"
 #include "hardware_serial_wrapper.h"


 extern "C"
 {
	HardwareSerial* hardware_serial_get(void)
	{
		return &Serial;
	}

	void hardware_serial_begin(HardwareSerial *handle, int bandwith)
	{
		handle->begin(bandwith);
	}

	void hardware_serial_println(HardwareSerial *handle, const char *text)
	{
		handle->println(text);
	}
	
	void hardware_serial_printNumber(HardwareSerial *handle, int value)
	{
		handle->println(value);
	}
 };
