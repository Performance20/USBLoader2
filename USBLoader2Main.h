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
//#include "ConfigData.h"

#include <string.h>
#include <iostream>
#include <sstream>

#include <wx/stdpaths.h>
#include <wx/config.h>
#include <wx/confbase.h>
#include <wx/fileconf.h>

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

#include "USBDevice.h"


using namespace std;

class USBLoader2Frame: public wxFrame
{
    public:

        USBLoader2Frame(wxWindow* parent,wxWindowID id = -1);
        //virtual ~USBLoader2Frame();
        ~USBLoader2Frame();

    private:

        USBDevice* digiSpark;
        bool fininish;
        bool connected;

        bool cfgchange;

      //  ConfigData config;

        void ConfigChange(void);
        bool isConfigChanged(void);
        void resetConfigChange(void);

        //(*Handlers(USBLoader2Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnDisconnectUsb(wxCommandEvent& event);
        void OnConnectUsb(wxCommandEvent& event);
        void OnSpeichern(wxCommandEvent& event);
        void OnRadioBoxBasisfunktionSelect(wxCommandEvent& event);
        void OnLadenKonfig(wxCommandEvent& event);
        void OnDataChange(wxCommandEvent& event);
        void OnSpinCtrlChange(wxSpinEvent& event);
        void OnClose(wxCloseEvent& event);
        //*)

        //(*Identifiers(USBLoader2Frame)
        static const long ID_STATICTEXT34;
        static const long ID_RADIOBOXBasisfunktion;
        static const long ID_STATICTEXT35;
        static const long ID_STATICTEXT36;
        static const long ID_SPINCTRLStarthilfe;
        static const long ID_STATICTEXT37;
        static const long ID_STATICTEXT62;
        static const long ID_SPINCTRLStarthilfeUMDR;
        static const long ID_STATICTEXT63;
        static const long ID_STATICTEXT2;
        static const long ID_SPINCTRL2FZZP;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT67;
        static const long ID_SPINCTRLSchliessWinkel;
        static const long ID_STATICTEXT68;
        static const long ID_STATICTEXT31;
        static const long ID_CHOICETAB;
        static const long ID_STATICTEXT32;
        static const long ID_STATICTEXT64;
        static const long ID_SPINCTRLSPLoad;
        static const long ID_STATICTEXT65;
        static const long ID_STATICTEXT33;
        static const long ID_CHOICELED;
        static const long ID_STATICTEXT66;
        static const long ID_PANELBasis;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT69;
        static const long ID_STATICTEXT8;
        static const long ID_SPINCTRLTB1_UM1;
        static const long ID_SPINCTRLTB1_GR1;
        static const long ID_SPINCTRLTB1_SW1;
        static const long ID_STATICTEXT9;
        static const long ID_SPINCTRLTB1_UM2;
        static const long ID_SPINCTRLTB1_GR2;
        static const long ID_SPINCTRLTB1_SW2;
        static const long ID_STATICTEXT10;
        static const long ID_SPINCTRLTB1_UM3;
        static const long ID_SPINCTRLTB1_GR3;
        static const long ID_SPINCTRLTB1_SW3;
        static const long ID_STATICTEXT11;
        static const long ID_SPINCTRLTB1_UM4;
        static const long ID_SPINCTRLTB1_GR4;
        static const long ID_SPINCTRLTB1_SW4;
        static const long ID_STATICTEXT12;
        static const long ID_SPINCTRLTB1_UM5;
        static const long ID_SPINCTRLTB1_GR5;
        static const long ID_SPINCTRLTB1_SW5;
        static const long ID_STATICTEXT13;
        static const long ID_SPINCTRLTB1_UM6;
        static const long ID_SPINCTRLTB1_GR6;
        static const long ID_SPINCTRLTB1_SW6;
        static const long ID_STATICTEXT14;
        static const long ID_SPINCTRLTB1_UM7;
        static const long ID_SPINCTRLTB1_GR7;
        static const long ID_SPINCTRLTB1_SW7;
        static const long ID_STATICTEXT15;
        static const long ID_SPINCTRLTB1_UM8;
        static const long ID_SPINCTRLTB1_GR8;
        static const long ID_SPINCTRLTB1_SW8;
        static const long ID_STATICTEXT16;
        static const long ID_SPINCTRLTB1_UM9;
        static const long ID_SPINCTRLTB1_GR9;
        static const long ID_SPINCTRLTB1_SW9;
        static const long ID_STATICTEXT17;
        static const long ID_SPINCTRLTB1_UM10;
        static const long ID_SPINCTRLTB1_GR10;
        static const long ID_SPINCTRLTB1_SW10;
        static const long ID_PANELTB1;
        static const long ID_STATICTEXT18;
        static const long ID_STATICTEXT19;
        static const long ID_STATICTEXT20;
        static const long ID_STATICTEXT72;
        static const long ID_STATICTEXT21;
        static const long ID_SPINCTRLTB2_UM1;
        static const long ID_SPINCTRLTB2_GR1;
        static const long ID_SPINCTRLTB2_SW1;
        static const long ID_STATICTEXT22;
        static const long ID_SPINCTRLTB2_UM2;
        static const long ID_SPINCTRLTB2_GR2;
        static const long ID_SPINCTRLTB2_SW2;
        static const long ID_STATICTEXT23;
        static const long ID_SPINCTRLTB2_UM3;
        static const long ID_SPINCTRLTB2_GR3;
        static const long ID_SPINCTRLTB2_SW3;
        static const long ID_STATICTEXT24;
        static const long ID_SPINCTRLTB2_UM4;
        static const long ID_SPINCTRLTB2_GR4;
        static const long ID_SPINCTRLTB2_SW4;
        static const long ID_STATICTEXT25;
        static const long ID_SPINCTRLTB2_UM5;
        static const long ID_SPINCTRLTB2_GR5;
        static const long ID_SPINCTRLTB2_SW5;
        static const long ID_STATICTEXT26;
        static const long ID_SPINCTRLTB2_UM6;
        static const long ID_SPINCTRLTB2_GR6;
        static const long ID_SPINCTRLTB2_SW6;
        static const long ID_STATICTEXT27;
        static const long ID_SPINCTRLTB2_UM7;
        static const long ID_SPINCTRLTB2_GR7;
        static const long ID_SPINCTRLTB2_SW7;
        static const long ID_STATICTEXT28;
        static const long ID_SPINCTRLTB2_UM8;
        static const long ID_SPINCTRLTB2_GR8;
        static const long ID_SPINCTRLTB2_SW8;
        static const long ID_STATICTEXT29;
        static const long ID_SPINCTRLTB2_UM9;
        static const long ID_SPINCTRLTB2_GR9;
        static const long ID_SPINCTRLTB2_SW9;
        static const long ID_STATICTEXT30;
        static const long ID_SPINCTRLTB2_UM10;
        static const long ID_SPINCTRLTB2_GR10;
        static const long ID_SPINCTRLTB2_SW10;
        static const long ID_PANELTB2;
        static const long ID_STATICTEXT49;
        static const long ID_STATICTEXT50;
        static const long ID_STATICTEXT51;
        static const long ID_STATICTEXT73;
        static const long ID_STATICTEXT52;
        static const long ID_SPINCTRLTB3_UM1;
        static const long ID_SPINCTRLTB3_GR;
        static const long ID_SPINCTRLTB3_SW1;
        static const long ID_STATICTEXT53;
        static const long ID_SPINCTRLTB3_UM2;
        static const long ID_SPINCTRLTB3_GR2;
        static const long ID_SPINCTRLTB3_SW2;
        static const long ID_STATICTEXT54;
        static const long ID_SPINCTRLTB3_UM3;
        static const long ID_SPINCTRLTB3_GR3;
        static const long ID_SPINCTRLTB3_SW3;
        static const long ID_STATICTEXT55;
        static const long ID_SPINCTRLTB3_UM4;
        static const long ID_SPINCTRLTB3_GR4;
        static const long ID_SPINCTRLTB3_SW4;
        static const long ID_STATICTEXT56;
        static const long ID_SPINCTRLTB3_UM5;
        static const long ID_SPINCTRLTB3_GR5;
        static const long ID_SPINCTRLTB3_SW5;
        static const long ID_STATICTEXT57;
        static const long ID_SPINCTRLTB3_UM6;
        static const long ID_SPINCTRLTB3_GR6;
        static const long ID_SPINCTRLTB3_SW6;
        static const long ID_STATICTEXT58;
        static const long ID_SPINCTRLTB3_UM7;
        static const long ID_SPINCTRLTB3_GR7;
        static const long ID_SPINCTRLTB3_SW7;
        static const long ID_STATICTEXT59;
        static const long ID_SPINCTRLTB3_UM8;
        static const long ID_SPINCTRLTB3_GR8;
        static const long ID_SPINCTRLTB3_SW8;
        static const long ID_STATICTEXT60;
        static const long ID_SPINCTRLTB3_UM9;
        static const long ID_SPINCTRLTB3_GR9;
        static const long ID_SPINCTRLTB3_SW9;
        static const long ID_STATICTEXT61;
        static const long ID_SPINCTRLTB3_UM10;
        static const long ID_SPINCTRLTB3_GR10;
        static const long ID_SPINCTRLTB3_SW10;
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
        static const long ID_STATICTEXT47;
        static const long ID_TEXTCTRL2;
        static const long ID_STATICTEXT48;
        static const long ID_STATICTEXT70;
        static const long ID_TEXTCTRL3;
        static const long ID_STATICTEXT71;
        static const long ID_STATICTEXT3;
        static const long ID_TEXTCTRLEchtModus;
        static const long ID_STATICTEXT5;
        static const long ID_PANELEchtWerte;
        static const long ID_NOTEBOOK1;
        static const long ID_TEXTCTRLLOG;
        static const long ID_PANEL1;
        static const long idMenuSpeichern;
        static const long idMenuLaden;
        static const long idMenuQuit;
        static const long idMenuVerbinden;
        static const long idMenuTrennen;
        static const long idMenuKonfigLaden;
        static const long ID_MenuidMenuKonfigHolen;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(USBLoader2Frame)
        wxChoice* ChoiceLED;
        wxChoice* ChoiceTAB;
        wxMenuItem* MenuItem3;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem5;
        wxMenuItem* MenuItem6;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem8;
        wxNotebook* Notebook1;
        wxPanel* EchtWerte;
        wxPanel* Panel1;
        wxPanel* PanelBasis;
        wxPanel* PanelTB1;
        wxPanel* PanelTB2;
        wxPanel* PanelTB3;
        wxRadioBox* RadioBoxBasisfunktion;
        wxSpinCtrl* SpinCtrlFZZP;
        wxSpinCtrl* SpinCtrlSPLoad;
        wxSpinCtrl* SpinCtrlSchliessWinkel;
        wxSpinCtrl* SpinCtrlStarthilfe;
        wxSpinCtrl* SpinCtrlStarthilfeUMDR;
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
        wxSpinCtrl* SpinCtrlTB1_SW10;
        wxSpinCtrl* SpinCtrlTB1_SW1;
        wxSpinCtrl* SpinCtrlTB1_SW2;
        wxSpinCtrl* SpinCtrlTB1_SW3;
        wxSpinCtrl* SpinCtrlTB1_SW4;
        wxSpinCtrl* SpinCtrlTB1_SW5;
        wxSpinCtrl* SpinCtrlTB1_SW6;
        wxSpinCtrl* SpinCtrlTB1_SW7;
        wxSpinCtrl* SpinCtrlTB1_SW8;
        wxSpinCtrl* SpinCtrlTB1_SW9;
        wxSpinCtrl* SpinCtrlTB1_UM10;
        wxSpinCtrl* SpinCtrlTB1_UM1;
        wxSpinCtrl* SpinCtrlTB1_UM2;
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
        wxSpinCtrl* SpinCtrlTB2_SW10;
        wxSpinCtrl* SpinCtrlTB2_SW1;
        wxSpinCtrl* SpinCtrlTB2_SW2;
        wxSpinCtrl* SpinCtrlTB2_SW3;
        wxSpinCtrl* SpinCtrlTB2_SW4;
        wxSpinCtrl* SpinCtrlTB2_SW5;
        wxSpinCtrl* SpinCtrlTB2_SW6;
        wxSpinCtrl* SpinCtrlTB2_SW7;
        wxSpinCtrl* SpinCtrlTB2_SW8;
        wxSpinCtrl* SpinCtrlTB2_SW9;
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
        wxSpinCtrl* SpinCtrlTB3_GR10;
        wxSpinCtrl* SpinCtrlTB3_GR1;
        wxSpinCtrl* SpinCtrlTB3_GR2;
        wxSpinCtrl* SpinCtrlTB3_GR3;
        wxSpinCtrl* SpinCtrlTB3_GR4;
        wxSpinCtrl* SpinCtrlTB3_GR5;
        wxSpinCtrl* SpinCtrlTB3_GR6;
        wxSpinCtrl* SpinCtrlTB3_GR7;
        wxSpinCtrl* SpinCtrlTB3_GR8;
        wxSpinCtrl* SpinCtrlTB3_GR9;
        wxSpinCtrl* SpinCtrlTB3_SW10;
        wxSpinCtrl* SpinCtrlTB3_SW1;
        wxSpinCtrl* SpinCtrlTB3_SW2;
        wxSpinCtrl* SpinCtrlTB3_SW3;
        wxSpinCtrl* SpinCtrlTB3_SW4;
        wxSpinCtrl* SpinCtrlTB3_SW5;
        wxSpinCtrl* SpinCtrlTB3_SW6;
        wxSpinCtrl* SpinCtrlTB3_SW7;
        wxSpinCtrl* SpinCtrlTB3_SW8;
        wxSpinCtrl* SpinCtrlTB3_SW9;
        wxSpinCtrl* SpinCtrlTB3_UM10;
        wxSpinCtrl* SpinCtrlTB3_UM1;
        wxSpinCtrl* SpinCtrlTB3_UM2;
        wxSpinCtrl* SpinCtrlTB3_UM3;
        wxSpinCtrl* SpinCtrlTB3_UM4;
        wxSpinCtrl* SpinCtrlTB3_UM5;
        wxSpinCtrl* SpinCtrlTB3_UM6;
        wxSpinCtrl* SpinCtrlTB3_UM7;
        wxSpinCtrl* SpinCtrlTB3_UM8;
        wxSpinCtrl* SpinCtrlTB3_UM9;
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
        wxStaticText* StaticText47;
        wxStaticText* StaticText48;
        wxStaticText* StaticText49;
        wxStaticText* StaticText4;
        wxStaticText* StaticText50;
        wxStaticText* StaticText51;
        wxStaticText* StaticText52;
        wxStaticText* StaticText53;
        wxStaticText* StaticText54;
        wxStaticText* StaticText55;
        wxStaticText* StaticText56;
        wxStaticText* StaticText57;
        wxStaticText* StaticText58;
        wxStaticText* StaticText59;
        wxStaticText* StaticText5;
        wxStaticText* StaticText60;
        wxStaticText* StaticText61;
        wxStaticText* StaticText62;
        wxStaticText* StaticText63;
        wxStaticText* StaticText64;
        wxStaticText* StaticText65;
        wxStaticText* StaticText66;
        wxStaticText* StaticText67;
        wxStaticText* StaticText68;
        wxStaticText* StaticText69;
        wxStaticText* StaticText6;
        wxStaticText* StaticText70;
        wxStaticText* StaticText71;
        wxStaticText* StaticText72;
        wxStaticText* StaticText73;
        wxStaticText* StaticText7;
        wxStaticText* StaticText8;
        wxStaticText* StaticText9;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl3;
        wxTextCtrl* TextCtrlEchtModus;
        wxTextCtrl* TextCtrlLOG;
        wxTextCtrl* TextCtrlRPM;
        wxTextCtrl* TextCtrlTPR;
        //*)

        DECLARE_EVENT_TABLE()
};

inline void USBLoader2Frame::ConfigChange(void)
{
    cfgchange = true;
}

inline bool USBLoader2Frame::isConfigChanged(void)
{
    return cfgchange;
}

inline void USBLoader2Frame::resetConfigChange(void)
{
    cfgchange = false;
}


#endif // USBLoader2MAIN_H
