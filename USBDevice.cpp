/***************************************************************
 * Name:      USBDevice.cpp
 * Purpose:   Code for USB Access Class
 * Author:    Helge ()
 * Created:   2020-09-03
 * Copyright: Helge ()
 * License:
 **************************************************************/

#include "USBDevice.h"
#include "TextStrings.h"

using namespace std;

	USBDevice::USBDevice(uint16_t _vendor_id, uint16_t _product_id)
	{
		vendor_id = _vendor_id;
		product_id = _product_id;
		out = new std::ostringstream();
		this->init();
	}

    USBDevice::USBDevice(uint16_t _vendor_id, uint16_t _product_id, std::ostringstream& iout)
    {
		vendor_id = _vendor_id; //
		product_id = _product_id; //
		out = &iout;
		this->init();
    }

	USBDevice::USBDevice(void)
	{
		vendor_id = DIGISPARK_VENDOR_ID; //
		product_id = DIGISPARK_PRODUCT_ID; //
		out = new std::ostringstream();
		//out = new std::ostream("");
		this->init();
	}

    USBDevice::~USBDevice()
    {
 		if (isConnected()) {
			libusb_release_interface(handle, 0);
			libusb_close(handle);
		}
		if (bibo_connected == true)
			libusb_exit(NULL);
    }


	void USBDevice::init() {
		int ret;

		interface_connected = false;
		handle = NULL;

		ret = libusb_init(NULL);
		if (ret < 0)
		{
			*out << "libusb_init(NULL) fehlgeschlagen" << endl << ends;
			bibo_connected = false;
			return;
		}
		bibo_connected = true;

	}

	void USBDevice::connect_device() {
		int ret;
		libusb_device_handle* _handle = NULL;

		if (!isConnected())
		{
			_handle = libusb_open_device_with_vid_pid(NULL, vendor_id, product_id);
			if (_handle == NULL) {  // have not connected my DigiSpark
				*out << STR_libusb_open_device_with_vid_pid_ERR << endl << ends;
				return;
			}
			ret = libusb_claim_interface(_handle, 0);
			if (ret < 0) {
				*out << STR_libusb_claim_interface_ERR << libusb_error_text(ret) << endl << ends;
				libusb_close(_handle);
				return;
			}
			handle = _handle;
			interface_connected = true;

		}
		else
			*out << STR_USB_DEVICE_ALREADY_CONNECTED << endl << ends;
		return;
	}


	void USBDevice::connect_device_with_search()
	{
		struct libusb_device** devs;
		struct libusb_device* dev;
		struct libusb_device_handle* _handle = NULL;
		ssize_t cnt;
		int ret, i = 0;
		unsigned int bus, addr;

		if (!isConnected())
		{
			cnt = libusb_get_device_list(NULL, &devs);
			if (cnt < 0)
			{
				*out << STR_libusb_get_device_list_ERR << libusb_error_text(cnt) << endl << ends;
				return;
			}

			while ((dev = devs[i++]) != NULL)
			{
				struct libusb_device_descriptor desc;

				ret = libusb_get_device_descriptor(dev, &desc);
				if (ret < 0)
				{
					*out << STR_libusb_get_device_descriptor_ERR << endl << ends;
					libusb_free_device_list(devs, 1);
					return;
				}
				if (desc.idVendor == vendor_id && desc.idProduct == product_id)
				{
					ret = libusb_open(dev, &_handle);
					if (ret < 0)
					{
						*out << STR_libusb_open_ERR << libusb_error_text(ret) << endl << ends;
						_handle = NULL;
						libusb_free_device_list(devs, 1);
						return;
					}

					ret = libusb_claim_interface(_handle, 0);
					if (ret < 0)
					{
						*out << STR_libusb_claim_interface_ERR << libusb_error_text(ret) << endl << ends;
						libusb_close(_handle);
						libusb_free_device_list(devs, 1);
						return;
					}
					bus = libusb_get_bus_number(dev);
					addr = libusb_get_device_address(dev);
					*out << STR_USB_FOUND << STR_USB_BUS << bus << "   " << STR_USB_DEVICE_ADDRESS << addr << "   " << STR_VENDOR_ID << vendor_id << "   " << STR_PRODUCT_ID << product_id << endl << ends;
					handle = _handle;
					interface_connected = true;
					libusb_free_device_list(devs, 1);
					return;
				}
			}
			libusb_free_device_list(devs, 1);
		}
		else
				*out << STR_USB_DEVICE_ALREADY_CONNECTED << endl << ends;

	}


	int USBDevice::claim_device(libusb_device* dev, int level, libusb_device_handle** handleusb)
	{
		int ret;
		std::string sout;

		if (find_device(dev, level, handleusb, sout) == 1)
		{
			ret = libusb_claim_interface(*handleusb, 0);
			if (ret < 0) {
				*out << STR_libusb_claim_interface_ERR << libusb_error_text(ret) << endl << ends;
				libusb_close(*handleusb);
				*handleusb = NULL;
				return -1;
			}
			else
				return 1;
		}
		return 0;
	}


	/* find the device and claim the interface */
	int USBDevice::find_device(libusb_device* dev, int level, libusb_device_handle** handleusb, std::string& sout)
	{
		struct libusb_device_descriptor desc;
		unsigned char strBuffer[256];
		int ret;
		unsigned int i, ii;
		std::ostringstream m, m1, m2;
		std::istringstream in;
		long _vendor_id, _product_id;
		libusb_device_handle* _handle;

		ret = libusb_get_device_descriptor(dev, &desc);
		if (ret < 0) {
			*out << STR_libusb_get_device_descriptor_ERR << endl << ends;
			sout = "";
			return -1;
		}

		_handle = NULL;
		ret = libusb_open(dev, &_handle);
		if (ret == LIBUSB_SUCCESS) {
			if (desc.iManufacturer) {
				ret = libusb_get_string_descriptor_ascii(_handle, desc.iManufacturer, strBuffer, sizeof(strBuffer));
				if (ret > 0) {
					strBuffer[ret] = 0;
					m1 << strBuffer;
				}
				else
					m1 << desc.idVendor;
			}
			else
				m1 << desc.idVendor;

			if (desc.iProduct) {
				ret = libusb_get_string_descriptor_ascii(_handle, desc.iProduct, strBuffer, sizeof(strBuffer));
				if (ret > 0) {
					strBuffer[ret] = 0;
					m2 << strBuffer;
				}
				else
					m2 << desc.idProduct;
			}
			else
				m2 << desc.idProduct;
		}
		else {
			m1 << desc.idVendor;
			m2 << desc.idProduct;
		}
		m1 << ends;
		m2 << ends;
		in.str(m1.str());
		in >> _vendor_id;
		in.str(m2.str());
		in >> _product_id;

		if ((_vendor_id == vendor_id) && (_product_id == product_id)) {
			i = libusb_get_bus_number(dev);
			ii = libusb_get_device_address(dev);
            m << STR_USB_FOUND << STR_USB_BUS << i << STR_USB_DEVICE_ADDRESS << ii << ": " << m1.str() << ":" << m2.str() << endl << ends;
			//		out << m.str();
			*handleusb = _handle;
			sout = m.str();
			return 1;
		}
		if (_handle)
			libusb_close(_handle);
		sout = "";
		return 0;
	}


std::string USBDevice::print_device(libusb_device* dev, int level)
{
	struct libusb_device_descriptor desc;
	libusb_device_handle* _handle = NULL;
	unsigned char strBuffer[256];
	int ret;
	unsigned int i, ii;
	std::ostringstream  m1, mout;
	std::string ss("");


	ret = libusb_get_device_descriptor(dev, &desc);
	if (ret < 0) {
		*out << STR_libusb_get_device_descriptor_ERR << endl << ends;
		return "";
	}
	ret = libusb_open(dev, &_handle);
	if (ret == LIBUSB_SUCCESS)
	{
		if (desc.iManufacturer)
		{
			ret = libusb_get_string_descriptor_ascii(_handle, desc.iManufacturer, strBuffer, sizeof(strBuffer));
			if (ret > 0) {
				strBuffer[ret] = 0;
				m1 << "   " << STR_VENDOR_ID << strBuffer;
			}
			else
				m1 << "   " << STR_VENDOR_ID << desc.idVendor;
		}
		else
			m1 << "   " << STR_VENDOR_ID << desc.idVendor;

		if (desc.iProduct) {
			ret = libusb_get_string_descriptor_ascii(_handle, desc.iProduct, strBuffer, sizeof(strBuffer));
			if (ret > 0) {
				strBuffer[ret] = 0;
				m1 << "   " << STR_PRODUCT_ID << strBuffer;
			}
			else
				m1 << "   " << STR_PRODUCT_ID << desc.idProduct;
		}
		else
			m1 << "   " << STR_PRODUCT_ID << desc.idProduct;
	}
	else
	{
			m1 << "   " << STR_VENDOR_ID << desc.idVendor << "   " << STR_PRODUCT_ID << desc.idProduct;
	}

	i = libusb_get_bus_number(dev);
	ii = libusb_get_device_address(dev);
	//m1 << ends;
	//mout << STR_USB_BUS << i << ",  " << "ä" <<  ii << ":"  <<  m1.str();
    mout << STR_USB_BUS << i << ",  " << STR_USB_DEVICE_ADDRESS <<  ii << ":"  <<  m1.str();
	if (_handle) {
			if (desc.iSerialNumber) {
				ret = libusb_get_string_descriptor_ascii(_handle, desc.iSerialNumber, strBuffer, sizeof(strBuffer));
					if (ret > 0)
						mout << "  - " << STR_USB_DEVICE_SERIAL << strBuffer << endl;
			}

	}
	mout << "\n";
			/*    needs further seaching work to get more details */
			/*	for (i = 0; i < desc.bNumConfigurations; i++) {
					struct libusb_config_descriptor* config;
					ret = libusb_get_config_descriptor(dev, i, &config);
					if (LIBUSB_SUCCESS != ret) {

						out << "  Couldn't retrieve descriptors" << endl;
						continue;
					}

					//print_configuration(config);

					libusb_free_config_descriptor(config);
				}

				if (_handle && desc.bcdUSB >= 0x0201) {
					//print_bos(_handle);
			} */

	if (_handle)
			libusb_close(_handle);
	//mout << ends;
	return mout.str();
}



const char* USBDevice::libusb_error_text(ssize_t err_number)
{
			switch (err_number) {
			case 0:
				return "LIBUSB_SUCCESS";
			case -1:
				return "LIBUSB_ERROR_IO";
			case -2:
				return "LIBUSB_ERROR_INVALID_PARAM";
			case -3:
				return "LIBUSB_ERROR_ACCESS";
			case -4:
				return "LIBUSB_ERROR_NO_DEVICE";
			case -5:
				return "LIBUSB_ERROR_NOT_FOUND";
			case -6:
				return "LIBUSB_ERROR_BUSY";
			case -7:
				return "LIBUSB_ERROR_TIMEOUT";
			case -8:
				return "LIBUSB_ERROR_OVERFLOW";
			case -9:
				return "LIBUSB_ERROR_PIPE";
			case -10:
				return "LIBUSB_ERROR_INTERRUPTED";
			case -11:
				return "LIBUSB_ERROR_NO_MEM";
			case -12:
				return "LIBUSB_ERROR_NOT_SUPPORTED";
			case -99:
				return "LIBUSB_ERROR_OTHER";
			}
			return "UNDEFINED ERROR";
}

int USBDevice::reset_device()
{
	if (isConnected()) {
		libusb_release_interface(handle, 0);
		libusb_close(handle);
		//libusb_exit(NULL);
		interface_connected = false;
	}
	return 1;
}

std::string USBDevice::print_deviceList()
{
	libusb_device** devs;
	ssize_t cnt;
	int i;
	std::string ss;

	cnt = libusb_get_device_list(NULL, &devs);
	if (cnt < 0)
    {
		*out << STR_libusb_get_device_list_ERR << libusb_error_text(cnt) << endl << ends;
		return "";
	}
	else
		*out << STR_USB_NOMBER_OF_DEVICES << cnt << endl;
	for (i = 0; devs[i]; ++i)
	ss += this->print_device(devs[i], 0);
	libusb_free_device_list(devs, 1);
	return ss;
}

std::string USBDevice::print_connectedDevice() {
	libusb_device** devs;
	libusb_device_handle* _handle;

	ssize_t cnt;
	int i;
	std::string ss = "";

	cnt = libusb_get_device_list(NULL, &devs);
	if (cnt < 0) {
		*out << STR_libusb_get_device_list_ERR << libusb_error_text(cnt) << endl << ends;
		return "";
	}

	for (i = 0; devs[i]; i++) {
		if (find_device(devs[i], 0, &_handle, ss) == 1) break;
	}
	libusb_free_device_list(devs, 1);
	return ss;
}


string USBDevice::readString() // blocking reading
{
	string ss("");
	int status;
	unsigned char data[DATA_STRING_SIZE_IN_BYTE];

	if (isConnected())
	{
		status = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE | LIBUSB_ENDPOINT_IN,
			REQ_LOGGING, 0, 0, data, DATA_STRING_SIZE_IN_BYTE, TIMEOUT);
		if(status)
		{
			if (status < 0)
			{
				*out << endl << libusb_error_name(status) << endl << ends;
				this->reset_device();
			}
			else
			{
				if (status > DATA_STRING_SIZE_IN_BYTE) status = DATA_STRING_SIZE_IN_BYTE;
				ss.append((char*)data, status);
			}
		}
	}
	return ss;
}


int USBDevice::SetValue(uint8_t cmd, uint16_t val1, uint16_t val2) // send data TO ignition module
{
	int status;
	unsigned char data[1];

	if (isConnected()) {
		status = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE | LIBUSB_ENDPOINT_OUT,
			cmd, val1, val2, data, 1, TIMEOUT);

		if (status < 0) {
			*out << endl << libusb_error_name(status) << endl << ends;
			reset_device();
			return status;
		}
		else
			return status;
	}
	return -1;
}


int USBDevice::GetValue(uint8_t cmd,  int& val)  // get data FROM ignition module
{
	int status, ret = 0;
	unsigned char data[DATA_NUMBER_SIZE_IN_BYTE];

	if (isConnected()) {
		status = libusb_control_transfer(handle, LIBUSB_REQUEST_TYPE_VENDOR | LIBUSB_RECIPIENT_DEVICE | LIBUSB_ENDPOINT_IN,
			cmd, 0, 0, data, DATA_NUMBER_SIZE_IN_BYTE, TIMEOUT);

		if (status < 0) {
			*out << endl << libusb_error_name(status) << endl << ends;
			this->reset_device();
		}
		else
		{
			ret = ret + data[0];
			val = ret;
			return 1;
		}
	}
	return -1;
}


std::string USBDevice::getLog()
{

	static std::string ss;

	ss = out->str();
	ss += readString();
	out->str("");
	out->clear();
	return ss;
}

bool USBDevice::getMode(int& val)
{
	int mode;

	if (GetValue(REQ_ignition_mode_GET, mode) == -1) return false;
	val = mode;
	return true;
}

bool USBDevice::setMode(uint8_t mode)
{
	if (SetValue(REQ_ignition_mode_SET, mode) < 0) return false;
	return true;
}

bool USBDevice::getStartHelpZZP(int& val)
{
	int v1;

	if (GetValue(REQ_ONBOARD_LED_GET, v1) == -1)	return false;
	val = v1;
	return true;
}

bool USBDevice::setStartHelpZZP(int8_t val)
{
	if (SetValue(REQ_ITH_startpoint_SET, val) < 0) return false;
	return true;
}

bool USBDevice::getStartHelpRPM(int& val)
{
	int v1;

		if (GetValue(REQ_starthelp_RPM_GET, v1) == -1)	return false;
	val = v1;
	return true;
}

bool USBDevice::setStartHelpRPM(int16_t val)
{
	if (SetValue(REQ_starthelp_RPM_SET, val) < 0) return false;
	return true;
}

bool USBDevice::getFixZZP(int& val)
{
	int vv;

	if (GetValue(REQ_ignition_fix_startpoint_GET, vv) == -1)	return false;
	val = vv;
	return true;
}

bool USBDevice::setFixZZP(int8_t val)
{
	if (SetValue(REQ_ignition_fix_startpoint_SET, val) < 0) return false;
	return true;
}

bool USBDevice::getDwellAngle(int& val)
{
	int vv;

	if (GetValue(REQ_Dwell_Angle_GET, vv) == -1)	return false;
	val = vv;
	return true;
}

bool USBDevice::setDwellAngle(int16_t val)
{
	if (SetValue(REQ_Dwell_Angle_SET, val) < 0) return false;
	return true;
}

bool USBDevice::getIPTable(int& val)
{
	int vv;

	if (GetValue(REQ_ip_tbl_GET, vv) == -1)	return false;
	val = vv;
	return true;
}

bool USBDevice::setIPTable(uint8_t val)
{
	if (SetValue(REQ_ip_tbl_SET, val) < 0) return false;
	return true;
}


bool USBDevice::getLED(int& led)
{
	int val;

	if (GetValue(REQ_ONBOARD_LED_GET, val) == -1) return false;
	led = val;
	return true;
}

bool USBDevice::setLED(uint8_t val)
{
	if (SetValue(REQ_ONBOARD_LED_SET, val) < 0) return false;
	return true;
}



