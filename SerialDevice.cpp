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


SerialDevice::SerialDevice(uint16_t _vendor_id, uint16_t _product_id):Serial()
{
	vendor_id = _vendor_id;
	product_id = _product_id;
}

SerialDevice::SerialDevice(void):Serial()
{
	vendor_id = CDC_VENDOR_ID; //
	product_id = CDC_PRODUCT_ID; //
	setTimeout(Timeout::simpleTimeout(500));
//	this->init();
}

SerialDevice::~SerialDevice()
{
	if (this->isOpen()) this->close();
}

string SerialDevice::print_deviceList(void)
{
	string s;
	ostringstream sstr;
	vector<PortInfo> devices_found = serial::list_ports();
	vector<PortInfo>::iterator iter = devices_found.begin();
	PortInfo device;

	while (iter != devices_found.end())
	{
		device = *iter++;
		sstr << device.port.c_str() << ", " << device.description.c_str() << ", " << device.hardware_id.c_str() << endl;
	}
	return sstr.str();
}

void SerialDevice::connect_device()
{
	string s1, s2, s3;
	ostringstream sstr;
	vector<PortInfo> devices_found;
	vector<PortInfo>::iterator iter;
	PortInfo device;

	devices_found = list_ports();
	iter = devices_found.begin();

	while (iter != devices_found.end())
	{
		device = *iter++;
		s1 = device.hardware_id.substr(0, 3);
		if (s1 == "USB")
		{
			s2 = device.hardware_id.substr(8, 4);
			s3 = device.hardware_id.substr(17, 4);
			if ((s2 == vendor_id) && (s3 == product_id))
			{
				setPort(device.port);
				/*setBaudrate(1200);
				open();
				Sleep(250);
				close();
				Sleep(15000);*/
				setBaudrate(9600);
				setBytesize(eightbits);
				setParity(parity_none);
				setStopbits(stopbits_one);
				setFlowcontrol(flowcontrol_none);

				open();
				return;
			}
		}
		s1 = device.hardware_id.substr(0, 7);
		if (s1 == "FTDIBUS") //	"FTDIBUS\\COMPORT&VID_0403&PID_6001"
		{
			setPort(device.port);
			/*setBaudrate(1200);
			open();
			Sleep(250);
			close();
			Sleep(15000);*/
			setBaudrate(9600);
			setBytesize(eightbits);
			setParity(parity_none);
			setStopbits(stopbits_one);
			setFlowcontrol(flowcontrol_none);

			open();
			return;
		}
	}
}

bool SerialDevice::isConnected()
{
	return this->isOpen();
}


int SerialDevice::GetValue(uint8_t command, uint32_t& val)  // get data FROM ignition module
{
	int status;
	uint32_t ret = 0;
	uint8_t data[DATA_NUMBER_SIZE_IN_BYTE + SERIAL_PROTOKOLL_BYTE];
	uint8_t cmd, sz;

	if (isConnected())
	{
		data[0] = SERIAL_FRAME_START;
		data[1] = command;
		data[2] = SERIAL_FRAME_DELIM;
		data[3] = 0;
		data[4] = SERIAL_FRAME_STOP;

		ret = write(&data[0], 5);
		if (ret != 5)
		{
			//*out << "Fehler schreiben serial\n";
			//this->reset_device();
		}
		else
		{
			status = receiveLoop(cmd, sz, &data[0]);
			if (status >= 0)
			{
				if (command != cmd) return -2;
				if (status > ((int)sizeof(uint32_t))) status = sizeof(uint32_t);
				while (status--)
				{
					ret <<= 8;
					ret = ret + data[status];
				}
			}
			val = ret;
			return 1;
		}
	}
	return -1;
}

int SerialDevice::receiveLoop(uint8_t& cmd, uint8_t& sz, uint8_t* data)
{
    uint8_t cnt;
    uint8_t state;
    uint8_t lt[2];

	try
    {
		
		waitByteTimes(SERIAL_PROTOKOLL_BYTE + DATA_NUMBER_SIZE_IN_BYTE);
		if (available() < (SERIAL_PROTOKOLL_BYTE + DATA_NUMBER_SIZE_IN_BYTE)) return -1;
		while (true)
		{
          read(lt, 1);
          if (lt[0] == SERIAL_FRAME_START)
             state = 1;  //found frame begin char 
          else
          {
            if (state == 1) //command byte
            {
              cmd = lt[0];
              state = 2;
            }
            else
			 if (state == 2) // data size byte
			 {
               if (lt[0] != SERIAL_FRAME_DELIM)
               {
                sz = lt[0];
                state = 3;
               }
             }
             else
			   if (state == 3) // data size byte
               {
				   if (lt[0] == SERIAL_FRAME_STOP)
				   {
					   break;
				   }
				   else
                   {
                     if (lt[0] != SERIAL_FRAME_DELIM)
                     {
						 if (cnt == DATA_NUMBER_SIZE_IN_BYTE) return -1;
					   data[cnt] = lt[0];
                       cnt++;
                     }
                   }
               }
          }
        }
		return cnt;
    }

    catch (const exception& e)
    {

    }
}


bool SerialDevice::get_OPcounter(uint32_t& val) 
{
	if (GetValue(REQ_operation_sec_GET, val) < 0) return false;
	return true;
}