/***************************************************************
 * Name:      USBLoader2App.cpp
 * Purpose:   Code for Application Class
 * Author:    Helge ()
 * Created:   2020-09-03
 * Copyright: Helge ()
 * License:
 **************************************************************/

#include "USBLoader2App.h"

//(*AppHeaders
#include "USBLoader2Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(USBLoader2App);

bool USBLoader2App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	USBLoader2Frame* Frame = new USBLoader2Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
