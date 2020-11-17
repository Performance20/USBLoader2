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
#include "protocol.h"

using namespace std;
using namespace serial;

///////////////////////////////////////////////////////////////////////////////
/// Class Serial Connection via CDC USB serial port
///////////////////////////////////////////////////////////////////////////////
class SerialDevice : public Serial
{
private:
	
protected:

public:
	SerialDevice(void);
	string ListDevicesString(void);

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
