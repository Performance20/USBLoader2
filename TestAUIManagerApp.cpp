/***************************************************************
 * Name:      TestAUIManagerApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Helge ()
 * Created:   2020-09-03
 * Copyright: Helge ()
 * License:
 **************************************************************/

#include "TestAUIManagerApp.h"

//(*AppHeaders
#include "TestAUIManagerMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(TestAUIManagerApp);

bool TestAUIManagerApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	TestAUIManagerFrame* Frame = new TestAUIManagerFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
