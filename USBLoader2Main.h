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
#include <wx/choice.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/radiobox.h>
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
        static const long ID_STATICTEXT34;
        static const long ID_RADIOBOX1;
        static const long ID_STATICTEXT35;
        static const long ID_STATICTEXT36;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT37;
        static const long ID_STATICTEXT2;
        static const long ID_SPINCTRL2;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT3;
        static const long ID_SPINCTRL3;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT31;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT32;
        static const long ID_STATICTEXT33;
        static const long ID_CHOICE2;
        static const long ID_PANELBasis;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT8;
        static const long ID_SPINCTRLTB1_UM1;
        static const long ID_SPINCTRLTB1_GR1;
        static const long ID_STATICTEXT9;
        static const long ID_SPINCTRLTB1_UM2;
        static const long ID_SPINCTRLTB1_GR2;
        static const long ID_STATICTEXT10;
        static const long ID_SPINCTRLTB1_UM3;
        static const long ID_SPINCTRLTB1_GR3;
        static const long ID_STATICTEXT11;
        static const long ID_SPINCTRLTB1_UM4;
        static const long ID_SPINCTRLTB1_GR4;
        static const long ID_STATICTEXT12;
        static const long ID_SPINCTRLTB1_UM5;
        static const long ID_SPINCTRLTB1_GR5;
        static const long ID_STATICTEXT13;
        static const long ID_SPINCTRLTB1_UM6;
        static const long ID_SPINCTRLTB1_GR6;
        static const long ID_STATICTEXT14;
        static const long ID_SPINCTRLTB1_UM7;
        static const long ID_SPINCTRLTB1_GR7;
        static const long ID_STATICTEXT15;
        static const long ID_SPINCTRLTB1_UM8;
        static const long ID_SPINCTRLTB1_GR8;
        static const long ID_STATICTEXT16;
        static const long ID_SPINCTRLTB1_UM9;
        static const long ID_SPINCTRLTB1_GR9;
        static const long ID_STATICTEXT17;
        static const long ID_SPINCTRLTB1_UM10;
        static const long ID_SPINCTRLTB1_GR10;
        static const long ID_PANELTB1;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT21;
        static const long ID_SPINCTRLTB2_UM1;
        static const long ID_SPINCTRLTB2_GR1;
        static const long ID_STATICTEXT22;
        static const long ID_SPINCTRLTB2_UM2;
        static const long ID_SPINCTRLTB2_GR2;
        static const long ID_STATICTEXT23;
        static const long ID_SPINCTRLTB2_UM3;
        static const long ID_SPINCTRLTB2_GR3;
        static const long ID_STATICTEXT24;
        static const long ID_SPINCTRLTB2_UM4;
        static const long ID_SPINCTRLTB2_GR4;
        static const long ID_STATICTEXT25;
        static const long ID_SPINCTRLTB2_UM5;
        static const long ID_SPINCTRLTB2_GR5;
        static const long ID_STATICTEXT26;
        static const long ID_SPINCTRLTB2_UM6;
        static const long ID_SPINCTRLTB2_GR6;
        static const long ID_STATICTEXT27;
        static const long ID_SPINCTRLTB2_UM7;
        static const long ID_SPINCTRLTB2_GR7;
        static const long ID_STATICTEXT28;
        static const long ID_SPINCTRLTB2_UM8;
        static const long ID_SPINCTRLTB2_GR8;
        static const long ID_STATICTEXT29;
        static const long ID_SPINCTRLTB2_UM9;
        static const long ID_SPINCTRLTB2_GR9;
        static const long ID_STATICTEXT30;
        static const long ID_SPINCTRLTB2_UM10;
        static const long ID_SPINCTRLTB2_GR10;
        static const long ID_PANELTB2;
        static const long ID_PANELTB3;
        static const long ID_STATICTEXT46;
        static const long ID_STATICTEXT45;
        static const long ID_STATICTEXT44;
        static const long ID_STATICTEXT38;
        static const long ID_TEXTCTRLRPM;
        static const long ID_STATICTEXT39;
        static const long ID_STATICTEXT42;
        static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT43;
        static const long ID_STATICTEXT40;
        static const long ID_TEXTCTRLTPR;
        static const long ID_STATICTEXT41;
        static const long ID_PANELEchtWerte;
        static const long ID_NOTEBOOK1;
        static const long ID_TEXTCTRLLOG;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuVerbinden;
        static const long idMenuTrennen;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(USBLoader2Frame)
        wxChoice* Choice1;
        wxChoice* Choice2;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxNotebook* Notebook1;
        wxPanel* EchtWerte;
        wxPanel* Panel1;
        wxPanel* PanelBasis;
        wxPanel* PanelTB1;
        wxPanel* PanelTB2;
        wxPanel* PanelTB3;
        wxRadioBox* RadioBox1;
        wxSpinCtrl* SpinCtrl1;
        wxSpinCtrl* SpinCtrl2;
        wxSpinCtrl* SpinCtrl3;
        wxSpinCtrl* SpinCtrlSpinCtrlTB1_UM2;
        wxSpinCtrl* SpinCtrlTB1_GR10;
        wxSpinCtrl* SpinCtrlTB1_GR1;
        wxSpinCtrl* SpinCtrlTB1_GR2;
        wxSpinCtrl* SpinCtrlTB1_GR3;
        wxSpinCtrl* SpinCtrlTB1_GR4;
        wxSpinCtrl* SpinCtrlTB1_GR5;
        wxSpinCtrl* SpinCtrlTB1_GR6;
        wxSpinCtrl* SpinCtrlTB1_GR7;
        wxSpinCtrl* SpinCtrlTB1_GR8;
        wxSpinCtrl* SpinCtrlTB1_GR9;
        wxSpinCtrl* SpinCtrlTB1_UM10;
        wxSpinCtrl* SpinCtrlTB1_UM1;
        wxSpinCtrl* SpinCtrlTB1_UM3;
        wxSpinCtrl* SpinCtrlTB1_UM4;
        wxSpinCtrl* SpinCtrlTB1_UM5;
        wxSpinCtrl* SpinCtrlTB1_UM6;
        wxSpinCtrl* SpinCtrlTB1_UM7;
        wxSpinCtrl* SpinCtrlTB1_UM8;
        wxSpinCtrl* SpinCtrlTB1_UM9;
        wxSpinCtrl* SpinCtrlTB2_GR10;
        wxSpinCtrl* SpinCtrlTB2_GR1;
        wxSpinCtrl* SpinCtrlTB2_GR2;
        wxSpinCtrl* SpinCtrlTB2_GR3;
        wxSpinCtrl* SpinCtrlTB2_GR4;
        wxSpinCtrl* SpinCtrlTB2_GR5;
        wxSpinCtrl* SpinCtrlTB2_GR6;
        wxSpinCtrl* SpinCtrlTB2_GR7;
        wxSpinCtrl* SpinCtrlTB2_GR8;
        wxSpinCtrl* SpinCtrlTB2_GR9;
        wxSpinCtrl* SpinCtrlTB2_UM10;
        wxSpinCtrl* SpinCtrlTB2_UM1;
        wxSpinCtrl* SpinCtrlTB2_UM2;
        wxSpinCtrl* SpinCtrlTB2_UM3;
        wxSpinCtrl* SpinCtrlTB2_UM4;
        wxSpinCtrl* SpinCtrlTB2_UM5;
        wxSpinCtrl* SpinCtrlTB2_UM6;
        wxSpinCtrl* SpinCtrlTB2_UM7;
        wxSpinCtrl* SpinCtrlTB2_UM8;
        wxSpinCtrl* SpinCtrlTB2_UM9;
        wxStaticText* StaticText10;
        wxStaticText* StaticText11;
        wxStaticText* StaticText12;
        wxStaticText* StaticText13;
        wxStaticText* StaticText14;
        wxStaticText* StaticText15;
        wxStaticText* StaticText16;
        wxStaticText* StaticText17;
        wxStaticText* StaticText18;
        wxStaticText* StaticText19;
        wxStaticText* StaticText1;
        wxStaticText* StaticText20;
        wxStaticText* StaticText21;
        wxStaticText* StaticText22;
        wxStaticText* StaticText23;
        wxStaticText* StaticText24;
        wxStaticText* StaticText25;
        wxStaticText* StaticText26;
        wxStaticText* StaticText27;
        wxStaticText* StaticText28;
        wxStaticText* StaticText29;
        wxStaticText* StaticText2;
        wxStaticText* StaticText30;
        wxStaticText* StaticText31;
        wxStaticText* StaticText32;
        wxStaticText* StaticText33;
        wxStaticText* StaticText34;
        wxStaticText* StaticText35;
        wxStaticText* StaticText36;
        wxStaticText* StaticText37;
        wxStaticText* StaticText38;
        wxStaticText* StaticText39;
        wxStaticText* StaticText3;
        wxStaticText* StaticText40;
        wxStaticText* StaticText41;
        wxStaticText* StaticText42;
        wxStaticText* StaticText43;
        wxStaticText* StaticText44;
        wxStaticText* StaticText45;
        wxStaticText* StaticText46;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText6;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrlLOG;
        wxTextCtrl* TextCtrlRPM;
        wxTextCtrl* TextCtrlTPR;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // USBLoader2MAIN_H
