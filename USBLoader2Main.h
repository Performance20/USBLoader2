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
    wxSpinCtrl* SpinCtrl2;
    wxSpinCtrl* SpinCtrl3;
    wxStaticText* StaticText2;
    wxStaticText* StaticText3;
    wxStaticText* StaticText4;
    wxStaticText* StaticText5;
    wxStatusBar* StatusBar1;
    wxTextCtrl* TextCtrl2;
    //*)

    DECLARE_EVENT_TABLE()
};

#endif // USBLoader2MAIN_H
