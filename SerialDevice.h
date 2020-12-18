/***************************************************************
 * Name:      SerialDevice.h
 * Purpose:   Defines Serial Access Class using serial.lib
 * Author:    Helge ()
 * Created:   2020-11-17
 * Copyright: Helge ()
 * License:
 **************************************************************/

#pragma once


#include <string.h>
#include <iostream>
#include <sstream>
#include <cstdio>

#if defined(__linux__)
#include <unistd.h>
#elif defined(_WINDOWS)
#include <windows.h>
#endif

#include "serial/serial.h"
#include "s/SimpleSerial.h"

#include "protocol.h"

using namespace std;
using namespace serial;


//#define CDC_VENDOR_ID		"1A86";
//#define CDC_PRODUCT_ID		"7523";
#define CDC_VENDOR_ID		"10C4";
#define CDC_PRODUCT_ID		"EA60";


///////////////////////////////////////////////////////////////////////////////
/// Class Serial Connection via CDC USB serial port
///////////////////////////////////////////////////////////////////////////////
class SerialDevice : public Serial
{
private:
	string vendor_id;
	string product_id;

	int receiveLoop(uint8_t& cmd, uint8_t& sz, uint8_t* data);
	int GetValue(uint8_t cmd, uint32_t& val);  // get data FROM ignition module


protected:

public:
	SerialDevice(uint16_t _vendor_id, uint16_t _product_id);
	SerialDevice(void);
	string print_deviceList(void);
	void connect_device();
	~SerialDevice();
	bool isConnected();

	bool get_OPcounter(uint32_t& val);
};



/*
typedef signed char        int8_t;
typedef short              int16_t;
typedef int                int32_t;
typedef long long          int64_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned int       uint32_t;
typedef unsigned long long uint64_t;

 Wert = ( int ) ( ( ( unsigned int )( Byte1 << 8 ) ) | Byte2 );

*/
