/***************************************************************
 * Name:      TextStrings.h
 * Purpose:   Defines Text Strings
 * Author:    Helge ()
 * Created:   2020-10-02
 * Copyright: Helge ()
 * License:
 **************************************************************/

 #include <wx/wx.h>

#define STR_CONNECTION_STATUS_CONNECTED                    _("Verbunden")
#define STR_CONNECTION_STATUS_NOT_CONNECTED                _("Nicht Verbunden")
#define STR_USB_DEVICE_ALREADY_CONNECTED                   _("Zündung ist bereits verbunden!!!")
#define STR_libusb_open_device_with_vid_pid_ERR            _("Kann USB Gerät nicht öffnen via libusb_open_device_with_vid_pid(....)")
#define STR_libusb_claim_interface_ERR                     _("Kann auf USB Interface nicht zugreifen via libusb_claim_interface: ")
#define STR_libusb_get_device_list_ERR                     _("Kann USB Geräteliste nicht abrufen via libusb_get_device_list: ")
#define STR_libusb_get_device_descriptor_ERR               _("Bekomme USB Decriptor nicht via libusb_get_device_descriptor")
#define STR_libusb_open_ERR                                _("Fehler beim Öffnen des USB Gerätes via libusb_open: ")
#define STR_USB_FOUND                                      _("USB Gerät gefunden - ")
#define STR_USB_BUS                                        _("Bus: ")
#define STR_USB_DEVICE_ADDRESS                             _("Gerät: ")
#define STR_VENDOR_ID                                      _("Vendor ID: ")
#define STR_PRODUCT_ID                                     _("Produkt ID: ")
#define STR_USB_DEVICE_SERIAL                              _("Seriennummer: ")
#define STR_USB_NOMBER_OF_DEVICES                          _("Anzahl der verbundenen USB Geräte: ")


/*

LIBUSB_SUCCESS 	                                            Success (no error)
LIBUSB_ERROR_IO 	                                        Input/output error.
LIBUSB_ERROR_INVALID_PARAM 	                                Invalid parameter.
LIBUSB_ERROR_ACCESS 	                                    Access denied (insufficient permissions)
LIBUSB_ERROR_NO_DEVICE 	                                    No such device (it may have been disconnected)
LIBUSB_ERROR_NOT_FOUND 	                                    Entity not found.
LIBUSB_ERROR_BUSY 	                                        Resource busy.
LIBUSB_ERROR_TIMEOUT 	                                    Operation timed out.
LIBUSB_ERROR_OVERFLOW 	                                    Overflow.
LIBUSB_ERROR_PIPE 	                                        Pipe error.
LIBUSB_ERROR_INTERRUPTED 	                                System call interrupted (perhaps due to signal)
LIBUSB_ERROR_NO_MEM 	                                    Insufficient memory.
LIBUSB_ERROR_NOT_SUPPORTED 	                                Operation not supported or unimplemented on this platform.
LIBUSB_ERROR_OTHER 	                                        Other error.

*/
