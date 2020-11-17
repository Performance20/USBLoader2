/***************************************************************
 * Name:      SerialDevice.cpp
 * Purpose:   Code for Serial Access Class
 * Author:    Helge ()
 * Created:   2020-11-17
 * Copyright: Helge ()
 * License:
 **************************************************************/

#include "SerialDevice.h"
#include "TextStrings.h"


SerialDevice::SerialDevice():Serial()
{

}

string SerialDevice::ListDevicesString(void)
{
	string s;
	ostringstream sstr;
	vector<serial::PortInfo> devices_found = serial::list_ports();
	vector<serial::PortInfo>::iterator iter = devices_found.begin();

	while (iter != devices_found.end())
	{
		serial::PortInfo device = *iter++;
		sstr << device.port.c_str() << ", " << device.description.c_str() << ", " << device.hardware_id.c_str() << endl;
		//printf("(%s, %s, %s)\n", device.port.c_str(), device.description.c_str(),
			//device.hardware_id.c_str());
	}

	return sstr.str();
}

