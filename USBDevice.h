/***************************************************************
 * Name:      USBDevice.h
 * Purpose:   Defines USB Access Class usinf libusb.lib
 * Author:    Helge ()
 * Created:   2020-09-03
 * Copyright: Helge ()
 * License:
 **************************************************************/

#pragma once


#include <string.h>
#include <iostream>
#include <sstream>

#if defined(__linux__)
#include "libusb-1.0/libusb.h"
#elif defined(_WINDOWS)
#include "libusb/libusb.h"
#endif

#include "protocol.h"

using namespace std;


// HID Class-Specific Requests values(section 7.2 of the HID specifications)
#define HID_GET_REPORT                0x01
#define HID_GET_IDLE                  0x02
#define HID_GET_PROTOCOL              0x03
#define HID_SET_REPORT                0x09
#define HID_SET_IDLE                  0x0A
#define HID_SET_PROTOCOL              0x0B
#define HID_REPORT_TYPE_INPUT         0x01
#define HID_REPORT_TYPE_OUTPUT        0x02
#define HID_REPORT_TYPE_FEATURE       0x03

#define CTRL_IN  LIBUSB_ENDPOINT_IN|LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE
#define CTRL_OUT LIBUSB_ENDPOINT_OUT|LIBUSB_REQUEST_TYPE_CLASS|LIBUSB_RECIPIENT_INTERFACE

#define DIGISPARK_VENDOR_ID			0x16c0;
#define DIGISPARK_PRODUCT_ID		0x05df;
#define PACKET_CTRL_LEN 			1
#define TIMEOUT						1000 /* timeout in ms */
#define TRANSBUFFERSIZE				5  // max. bytes to transfer per ctrl message = 4 Bytes & 0


///////////////////////////////////////////////////////////////////////////////
/// Class USB Connection
///////////////////////////////////////////////////////////////////////////////
class USBDevice
{
private:

	bool fininish;
	uint16_t vendor_id;
	uint16_t product_id;
	bool interface_connected;
	bool bibo_connected;
	bool USB_init;
	ostringstream* out;
	libusb_device_handle* handle;  // handle DigiSpark
	string  readed;

	string print_device(libusb_device* dev, int level);
	int find_device(libusb_device* dev, int level, libusb_device_handle** handleusb, std::string& sout);
	int claim_device(libusb_device* dev, int level, libusb_device_handle** handleusb);
	const char* libusb_error_text(ssize_t err_number);

	void init();
	int reset_device();
	int SetValue(uint8_t cmd, uint16_t val1, uint16_t val2 = 0);
	int GetValue(uint8_t cmd, uint32_t& val);

	int SetValueBlock(uint8_t cmd, uint16_t val1, uint16_t val2, uint8_t* data, uint16_t size);
	int GetValueBlock(uint8_t cmd, uint16_t val1, uint16_t val2, uint8_t* data, uint16_t size);

	string readString();

protected:

public:
	USBDevice(uint16_t _vendor_id, uint16_t _product_id);
	USBDevice(uint16_t _vendor_id, uint16_t _product_id, std::ostringstream& iout);
	USBDevice();
	~USBDevice();

	void connect_device();
	void connect_device_with_search();

	string print_deviceList();
	string print_connectedDevice();

	string getLog();

	bool setLOGMode(uint8_t mode);
	bool getLOGMode(uint8_t& mode);

	bool setIgnMode(uint8_t mode);
	bool getIgnMode(uint8_t& mode);

	bool setStartHelpZZP(int8_t val);
	bool getStartHelpZZP(int8_t& val);

	bool setStartHelpRPM(uint16_t val);
	bool getStartHelpRPM(uint16_t& val);

	bool setFixZZP(int8_t val);
	bool getFixZZP(int8_t& val);


	bool getDwellAngle(int16_t& val);
	bool setDwellAngle(int16_t val);

	bool getIPTable(uint8_t& val);
	bool setIPTable(uint8_t val);

	bool getLED(uint8_t& val);
	bool setLED(uint8_t val);
	bool setLED_on();
	bool setLED_off();

	bool set_OPcounter(uint32_t val) ;
	bool get_OPcounter(uint32_t& val);

	bool write_EEpromParameter();
	bool write_EEpromTable1();
	bool write_EEpromTable2();
	bool write_EEpromTable3();
	bool reset_EEprom();
	bool write_TableToEEprom(unsigned char tbnr, ignition_point_t* tbl, uint8_t size);
	bool get_TableFromEEprom(unsigned char tbnr, ignition_point_t* tbl, uint8_t size);
	bool isConnected();
};

inline bool USBDevice::isConnected()
{
	return this->interface_connected;
}

inline bool USBDevice::setLED_off(void)
{
	return setLED(VAL_LED_STATE_OFF);
}

inline bool USBDevice::setLED_on(void)
{
	return setLED(VAL_LED_STATE_ON);
}


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
