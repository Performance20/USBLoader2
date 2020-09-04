/***************************************************************
 * Name:      USBLoader2Main.h
 * Purpose:   Defines Application Frame
 * Author:    Helge ()
 * Created:   2020-09-03
 * Copyright: Helge ()
 * License:
 **************************************************************/

#ifndef USBLoader2MAIN_H
#define USBLoader2MAIN_H

//(*Headers(USBLoader2Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class USBLoader2Frame: public wxFrame
{
    public:

        USBLoader2Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~USBLoader2Frame();

    private:

        //(*Handlers(USBLoader2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnDisconnectUsb(wxCommandEvent& event);
        void OnConnectUsb(wxCommandEvent& event);
        //*)

        //(*Identifiers(USBLoader2Frame)
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_RADIOBUTTON3;
        static const long ID_STATICTEXT2;
        static const long ID_SPINCTRL2;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT3;
        static const long ID_SPINCTRL3;
        static const long ID_STATICTEXT5;
        static const long ID_RADIOBUTTON4;
        static const long ID_RADIOBUTTON5;
        static const long ID_RADIOBUTTON6;
        static const long ID_PANEL2;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_SPINCTRL1;
        static const long ID_SPINCTRL4;
        static const long ID_STATICTEXT9;
        static const long ID_SPINCTRL5;
        static const long ID_SPINCTRL6;
        static const long ID_STATICTEXT10;
        static const long ID_SPINCTRL7;
        static const long ID_SPINCTRL8;
        static const long ID_STATICTEXT11;
        static const long ID_SPINCTRL9;
        static const long ID_SPINCTRL10;
        static const long ID_STATICTEXT12;
        static const long ID_SPINCTRL11;
        static const long ID_SPINCTRL12;
        static const long ID_STATICTEXT13;
        static const long ID_SPINCTRL13;
        static const long ID_SPINCTRL14;
        static const long ID_STATICTEXT14;
        static const long ID_SPINCTRL15;
        static const long ID_SPINCTRL16;
        static const long ID_STATICTEXT15;
        static const long ID_SPINCTRL17;
        static const long ID_SPINCTRL18;
        static const long ID_STATICTEXT16;
        static const long ID_SPINCTRL19;
        static const long ID_SPINCTRL20;
        static const long ID_STATICTEXT17;
        static const long ID_SPINCTRL21;
        static const long ID_SPINCTRL22;
        static const long ID_PANEL3;
        static const long ID_PANEL4;
        static const long ID_PANEL5;
        static const long ID_PANEL6;
        static const long ID_NOTEBOOK1;
        static const long ID_TEXTCTRL2;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuVerbinden;
        static const long idMenuTrennen;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(USBLoader2Frame)
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxNotebook* Notebook1;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxPanel* Panel3;
        wxPanel* Panel4;
        wxPanel* Panel5;
        wxPanel* Panel6;
        wxRadioButton* RadioButton1;
        wxRadioButton* RadioButton2;
        wxRadioButton* RadioButton3;
        wxRadioButton* RadioButton4;
        wxRadioButton* RadioButton5;
        wxRadioButton* RadioButton6;
        wxSpinCtrl* SpinCtrl10;
        wxSpinCtrl* SpinCtrl11;
        wxSpinCtrl* SpinCtrl12;
        wxSpinCtrl* SpinCtrl13;
        wxSpinCtrl* SpinCtrl14;
        wxSpinCtrl* SpinCtrl15;
        wxSpinCtrl* SpinCtrl16;
        wxSpinCtrl* SpinCtrl17;
        wxSpinCtrl* SpinCtrl18;
        wxSpinCtrl* SpinCtrl19;
        wxSpinCtrl* SpinCtrl20;
        wxSpinCtrl* SpinCtrl21;
        wxSpinCtrl* SpinCtrl22;
        wxSpinCtrl* SpinCtrl2;
        wxSpinCtrl* SpinCtrl3;
        wxSpinCtrl* SpinCtrl4;
        wxSpinCtrl* SpinCtrl5;
        wxSpinCtrl* SpinCtrl6;
        wxSpinCtrl* SpinCtrl7;
        wxSpinCtrl* SpinCtrl8;
        wxSpinCtrl* SpinCtrl9;
        wxSpinCtrl* SpinCtrlTB1_1;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
        wxStaticText* StaticText13;
        wxStaticText* StaticText14;
        wxStaticText* StaticText15;
        wxStaticText* StaticText16;
        wxStaticText* StaticText17;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl2;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // USBLoader2MAIN_H
