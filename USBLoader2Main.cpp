/***************************************************************
 * Name:      USBLoader2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Helge ()
 * Created:   2020-09-03
 * Copyright: Helge ()
 * License:
 **************************************************************/

using namespace std;

#include "USBLoader2Main.h"
#include <wx/msgdlg.h>
#include <wx/filedlg.h>

//(*InternalHeaders(USBLoader2Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "TextStrings.h"
#include "About.h"

//locale ger("de_DE.UTF-8");

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(USBLoader2Frame)
const long USBLoader2Frame::ID_STATICTEXT34 = wxNewId();
const long USBLoader2Frame::ID_RADIOBOXBasisfunktion = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT35 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT36 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLStarthilfe = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT37 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT62 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLStarthilfeUMDR = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT63 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL2FZZP = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT67 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLSchliessWinkel = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT68 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT31 = wxNewId();
const long USBLoader2Frame::ID_CHOICETAB = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT32 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT33 = wxNewId();
const long USBLoader2Frame::ID_CHOICELED = wxNewId();
const long USBLoader2Frame::ID_PANELBasis = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT69 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT11 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT12 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW5 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT13 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT14 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT15 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW8 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT16 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW9 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT17 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_SW10 = wxNewId();
const long USBLoader2Frame::ID_PANELTB1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT18 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT19 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT20 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT72 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT21 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT22 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT23 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT24 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT25 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW5 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT26 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT27 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT28 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW8 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT29 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW9 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT30 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_SW10 = wxNewId();
const long USBLoader2Frame::ID_PANELTB2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT49 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT50 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT51 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT73 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT52 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT53 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT54 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT55 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT56 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW5 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT57 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT58 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT59 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW8 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT60 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW9 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT61 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_SW10 = wxNewId();
const long USBLoader2Frame::ID_PANELTB3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT46 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT45 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT44 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT109 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT112 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT38 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLRPM = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT39 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT115 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT42 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRL1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT43 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT118 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT40 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLTPR = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT41 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT121 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT47 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRL2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT48 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT124 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT70 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRL3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT71 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT125 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT3 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLEchtModus = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT5 = wxNewId();
const long USBLoader2Frame::ID_PANELEchtWerte = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT78 = wxNewId();
const long USBLoader2Frame::ID_CHOICE1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT77 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT81 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLStrom = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT83 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT64 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT66 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLDOUBLE1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT74 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT86 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLWatt = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT88 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT65 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT75 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLDOUBLE2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT76 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT89 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT90 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT91 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT82 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT79 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLSpinCtrlSatturationF = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT80 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT92 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLMaxSchlWin = wxNewId();
const long USBLoader2Frame::ID_BUTTONZPBerechnen = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT87 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT84 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLSatTime = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT85 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT95 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLZPEnergie = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT96 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT94 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT101 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT102 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT103 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT104 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT105 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT106 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT98 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM1 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT107 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT108 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU1 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD1 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM2 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT110 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT111 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU2 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD2 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM3 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT113 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT114 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU3 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD3 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM4 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT116 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT117 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU4 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD4 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM5 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU5 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT119 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT120 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU5 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD5 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM6 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT122 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT123 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU6 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD6 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM7 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT126 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT127 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU7 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD7 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM8 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU8 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT93 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT97 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU8 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD8 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM9 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU9 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT99 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT100 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU9 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD9 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLRPM10 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLMSU10 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT129 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT130 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLGRADU10 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLD10 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLProz10 = wxNewId();
const long USBLoader2Frame::ID_PANEL_ZSpule = wxNewId();
const long USBLoader2Frame::ID_NOTEBOOK1 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLOG = wxNewId();
const long USBLoader2Frame::ID_PANEL1 = wxNewId();
const long USBLoader2Frame::idMenuSpeichern = wxNewId();
const long USBLoader2Frame::idMenuLaden = wxNewId();
const long USBLoader2Frame::idMenuLogLeeren = wxNewId();
const long USBLoader2Frame::idMenuQuit = wxNewId();
const long USBLoader2Frame::idMenuVerbinden = wxNewId();
const long USBLoader2Frame::idMenuTrennen = wxNewId();
const long USBLoader2Frame::idMenuKonfigLaden = wxNewId();
const long USBLoader2Frame::idMenuKonfigESpeichern = wxNewId();
const long USBLoader2Frame::idMenuidMenuKonfigHolen = wxNewId();
const long USBLoader2Frame::idMenuLogmodus = wxNewId();
const long USBLoader2Frame::idMenuAbout = wxNewId();
const long USBLoader2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(USBLoader2Frame,wxFrame)
    //(*EventTable(USBLoader2Frame)
    //*)
END_EVENT_TABLE()

USBLoader2Frame::USBLoader2Frame(wxWindow* parent, wxWindowID id)
{
    //(*Initialize(USBLoader2Frame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxGridSizer* GridSizer1;
    wxGridSizer* GridSizer2;
    wxGridSizer* GridSizer3;
    wxMenu* Datei;
    wxMenu* Hilfe;
    wxMenu* Kommunikation;
    wxMenuBar* HauptMenuBar;
    wxMenuItem* Hilfe_Info;
    wxMenuItem* MenuItem1;

    Create(parent, wxID_ANY, _("Zündmodul Konfigurator "), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(820,700));
    SetMinSize(wxSize(820,700));
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH|wxBORDER_RAISED, _T("ID_NOTEBOOK1"));
    Notebook1->SetFocus();
    PanelBasis = new wxPanel(Notebook1, ID_PANELBasis, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELBasis"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticText34 = new wxStaticText(PanelBasis, ID_STATICTEXT34, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    BoxSizer2->Add(StaticText34, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_1[4] =
    {
    	_("Manuell via Geber (M0)"),
    	_("Fester Zündzeitpunkt von OT (M1)"),
    	_("Fester ZP von OT mit Starthilfe (M2)"),
    	_("Dynamisch nach Tabelle (M3)")
    };
    RadioBoxBasisfunktion = new wxRadioBox(PanelBasis, ID_RADIOBOXBasisfunktion, _("Basisfunktion"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_1, 2, 0, wxDefaultValidator, _T("ID_RADIOBOXBasisfunktion"));
    RadioBoxBasisfunktion->SetSelection(1);
    BoxSizer2->Add(RadioBoxBasisfunktion, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText35 = new wxStaticText(PanelBasis, ID_STATICTEXT35, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    BoxSizer2->Add(StaticText35, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1 = new wxFlexGridSizer(7, 3, 10, 0);
    StaticText36 = new wxStaticText(PanelBasis, ID_STATICTEXT36, _("Starthilfe Zündzeitpunkt:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
    FlexGridSizer1->Add(StaticText36, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlStarthilfe = new wxSpinCtrl(PanelBasis, ID_SPINCTRLStarthilfe, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLStarthilfe"));
    SpinCtrlStarthilfe->SetValue(_T("0"));
    SpinCtrlStarthilfe->SetToolTip(_("Zündzeitpunkt beim Starten im Modus M3"));
    FlexGridSizer1->Add(SpinCtrlStarthilfe, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText37 = new wxStaticText(PanelBasis, ID_STATICTEXT37, _("Grad (Wert 0 = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
    FlexGridSizer1->Add(StaticText37, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText62 = new wxStaticText(PanelBasis, ID_STATICTEXT62, _("Starthilfe bis:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT62"));
    FlexGridSizer1->Add(StaticText62, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlStarthilfeUMDR = new wxSpinCtrl(PanelBasis, ID_SPINCTRLStarthilfeUMDR, _T("500"), wxDefaultPosition, wxSize(120,25), 0, 0, 2000, 500, _T("ID_SPINCTRLStarthilfeUMDR"));
    SpinCtrlStarthilfeUMDR->SetValue(_T("500"));
    SpinCtrlStarthilfeUMDR->SetToolTip(_("Bis zu welcher Umdrehung der Starthilfe Zündzeitpunkt genutzt wird (Modus M3). Wird die Umdrehung höher, wird auf  festen Zündzeitpunkt umgestellt."));
    FlexGridSizer1->Add(SpinCtrlStarthilfeUMDR, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText63 = new wxStaticText(PanelBasis, ID_STATICTEXT63, _("Umdrehungen/Min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT63"));
    FlexGridSizer1->Add(StaticText63, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(PanelBasis, ID_STATICTEXT2, _("Fester Zündzeitpunkt von OT:"), wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlFZZP = new wxSpinCtrl(PanelBasis, ID_SPINCTRL2FZZP, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRL2FZZP"));
    SpinCtrlFZZP->SetValue(_T("-22"));
    SpinCtrlFZZP->SetToolTip(_("Grad weg von OT, bei dem gezündet wird z: Bsp. -22 Grad wäre 22 Grad vor OT"));
    FlexGridSizer1->Add(SpinCtrlFZZP, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(PanelBasis, ID_STATICTEXT4, _("Grad (Wert 0 = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText67 = new wxStaticText(PanelBasis, ID_STATICTEXT67, _("Schließwinkel:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT67"));
    FlexGridSizer1->Add(StaticText67, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlSchliessWinkel = new wxSpinCtrl(PanelBasis, ID_SPINCTRLSchliessWinkel, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLSchliessWinkel"));
    SpinCtrlSchliessWinkel->SetValue(_T("-180"));
    SpinCtrlSchliessWinkel->SetHelpText(_("Ab welcher Gradzahl die Spule gegen Masse geladen wird, Werte vom ZZP -140 bis - 240 Grad möglich.  Bei der ETZ mit Elektronikzündung zum Beispiel -180 Grad = eine  halber Umdrehung vor dem Zündzeitpunkt."));
    FlexGridSizer1->Add(SpinCtrlSchliessWinkel, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText68 = new wxStaticText(PanelBasis, ID_STATICTEXT68, _("Grad (Wert = Grad vor ZZP)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT68"));
    FlexGridSizer1->Add(StaticText68, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText31 = new wxStaticText(PanelBasis, ID_STATICTEXT31, _("Aktive Zündtabelle:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    FlexGridSizer1->Add(StaticText31, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    ChoiceTAB = new wxChoice(PanelBasis, ID_CHOICETAB, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICETAB"));
    ChoiceTAB->SetSelection( ChoiceTAB->Append(_("Tabelle1")) );
    ChoiceTAB->Append(_("Tabelle2"));
    ChoiceTAB->Append(_("Tabelle3"));
    ChoiceTAB->SetToolTip(_("Aktiv benutzte Zündzeitpunkt-Tabelle  bei Modus M4"));
    ChoiceTAB->SetHelpText(_("Test"));
    FlexGridSizer1->Add(ChoiceTAB, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText32 = new wxStaticText(PanelBasis, ID_STATICTEXT32, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    FlexGridSizer1->Add(StaticText32, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText33 = new wxStaticText(PanelBasis, ID_STATICTEXT33, _("LED:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    FlexGridSizer1->Add(StaticText33, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    ChoiceLED = new wxChoice(PanelBasis, ID_CHOICELED, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICELED"));
    ChoiceLED->Append(_("Aus"));
    ChoiceLED->Append(_("An"));
    ChoiceLED->Append(_("Blinken"));
    ChoiceLED->SetSelection( ChoiceLED->Append(_("Eingangssignal")) );
    ChoiceLED->Append(_("Diagnose"));
    ChoiceLED->SetToolTip(_("Verhalten der LED"));
    FlexGridSizer1->Add(ChoiceLED, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(FlexGridSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PanelBasis->SetSizer(BoxSizer2);
    BoxSizer2->Fit(PanelBasis);
    BoxSizer2->SetSizeHints(PanelBasis);
    PanelTB1 = new wxPanel(Notebook1, ID_PANELTB1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELTB1"));
    GridSizer1 = new wxGridSizer(11, 4, 0, 0);
    StaticText1 = new wxStaticText(PanelTB1, ID_STATICTEXT1, _("Position"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(PanelTB1, ID_STATICTEXT6, _("Umdrehung/Minute"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    GridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(PanelTB1, ID_STATICTEXT7, _("ZZP (Wert 0° = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText69 = new wxStaticText(PanelTB1, ID_STATICTEXT69, _("Schließwinkel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT69"));
    GridSizer1->Add(StaticText69, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(PanelTB1, ID_STATICTEXT8, _("1."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    GridSizer1->Add(StaticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM1 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM1, _T("500"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 500, _T("ID_SPINCTRLTB1_UM1"));
    SpinCtrlTB1_UM1->SetValue(_T("500"));
    GridSizer1->Add(SpinCtrlTB1_UM1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR1 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR1, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB1_GR1"));
    SpinCtrlTB1_GR1->SetValue(_T("0"));
    GridSizer1->Add(SpinCtrlTB1_GR1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW1 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW1, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW1"));
    SpinCtrlTB1_SW1->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW1, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(PanelTB1, ID_STATICTEXT9, _("2."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    GridSizer1->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM2 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM2, _T("2000"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 2000, _T("ID_SPINCTRLTB1_UM2"));
    SpinCtrlTB1_UM2->SetValue(_T("2000"));
    GridSizer1->Add(SpinCtrlTB1_UM2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR2 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR2, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR2"));
    SpinCtrlTB1_GR2->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW2 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW2, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW2"));
    SpinCtrlTB1_SW2->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW2, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(PanelTB1, ID_STATICTEXT10, _("3."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    GridSizer1->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM3 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM3, _T("3000"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 3000, _T("ID_SPINCTRLTB1_UM3"));
    SpinCtrlTB1_UM3->SetValue(_T("3000"));
    GridSizer1->Add(SpinCtrlTB1_UM3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR3 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR3, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR3"));
    SpinCtrlTB1_GR3->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW3 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW3, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW3"));
    SpinCtrlTB1_SW3->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW3, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(PanelTB1, ID_STATICTEXT11, _("4."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    GridSizer1->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM4 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM4, _T("3500"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 3500, _T("ID_SPINCTRLTB1_UM4"));
    SpinCtrlTB1_UM4->SetValue(_T("3500"));
    GridSizer1->Add(SpinCtrlTB1_UM4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR4 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR4, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR4"));
    SpinCtrlTB1_GR4->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW4 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW4, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW4"));
    SpinCtrlTB1_SW4->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW4, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(PanelTB1, ID_STATICTEXT12, _("5."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    GridSizer1->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM5 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM5, _T("4500"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 4500, _T("ID_SPINCTRLTB1_UM5"));
    SpinCtrlTB1_UM5->SetValue(_T("4500"));
    GridSizer1->Add(SpinCtrlTB1_UM5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR5 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR5, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR5"));
    SpinCtrlTB1_GR5->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW5 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW5, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW5"));
    SpinCtrlTB1_SW5->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW5, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(PanelTB1, ID_STATICTEXT13, _("6."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    GridSizer1->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM6 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM6, _T("5000"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 5000, _T("ID_SPINCTRLTB1_UM6"));
    SpinCtrlTB1_UM6->SetValue(_T("5000"));
    GridSizer1->Add(SpinCtrlTB1_UM6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR6 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR6, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR6"));
    SpinCtrlTB1_GR6->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW6 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW6, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW6"));
    SpinCtrlTB1_SW6->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW6, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText14 = new wxStaticText(PanelTB1, ID_STATICTEXT14, _("7."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    GridSizer1->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM7 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM7, _T("5500"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 5500, _T("ID_SPINCTRLTB1_UM7"));
    SpinCtrlTB1_UM7->SetValue(_T("5500"));
    GridSizer1->Add(SpinCtrlTB1_UM7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR7 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR7, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR7"));
    SpinCtrlTB1_GR7->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW7 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW7, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW7"));
    SpinCtrlTB1_SW7->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW7, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(PanelTB1, ID_STATICTEXT15, _("8."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    GridSizer1->Add(StaticText15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM8 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM8, _T("6000"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 6000, _T("ID_SPINCTRLTB1_UM8"));
    SpinCtrlTB1_UM8->SetValue(_T("6000"));
    GridSizer1->Add(SpinCtrlTB1_UM8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR8 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR8, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR8"));
    SpinCtrlTB1_GR8->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW8 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW8, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW8"));
    SpinCtrlTB1_SW8->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW8, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(PanelTB1, ID_STATICTEXT16, _("9."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    GridSizer1->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM9 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM9, _T("6500"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 6500, _T("ID_SPINCTRLTB1_UM9"));
    SpinCtrlTB1_UM9->SetValue(_T("6500"));
    GridSizer1->Add(SpinCtrlTB1_UM9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR9 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR9, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR9"));
    SpinCtrlTB1_GR9->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW9 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW9, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW9"));
    SpinCtrlTB1_SW9->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW9, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(PanelTB1, ID_STATICTEXT17, _("10."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    GridSizer1->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM10 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM10, _T("7000"), wxDefaultPosition, wxSize(120,25), wxSP_VERTICAL, 0, 10000, 7000, _T("ID_SPINCTRLTB1_UM10"));
    SpinCtrlTB1_UM10->SetValue(_T("7000"));
    GridSizer1->Add(SpinCtrlTB1_UM10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR10 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR10, _T("-22"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR10"));
    SpinCtrlTB1_GR10->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_SW10 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_SW10, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB1_SW10"));
    SpinCtrlTB1_SW10->SetValue(_T("-180"));
    GridSizer1->Add(SpinCtrlTB1_SW10, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    PanelTB1->SetSizer(GridSizer1);
    GridSizer1->Fit(PanelTB1);
    GridSizer1->SetSizeHints(PanelTB1);
    PanelTB2 = new wxPanel(Notebook1, ID_PANELTB2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELTB2"));
    GridSizer2 = new wxGridSizer(11, 4, 0, 0);
    StaticText18 = new wxStaticText(PanelTB2, ID_STATICTEXT18, _("Position"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    GridSizer2->Add(StaticText18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(PanelTB2, ID_STATICTEXT19, _("Umdrehung/Minute"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    GridSizer2->Add(StaticText19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(PanelTB2, ID_STATICTEXT20, _("ZZP (Wert 0° = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    GridSizer2->Add(StaticText20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText72 = new wxStaticText(PanelTB2, ID_STATICTEXT72, _("Schließwinkel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT72"));
    GridSizer2->Add(StaticText72, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText21 = new wxStaticText(PanelTB2, ID_STATICTEXT21, _("1."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    GridSizer2->Add(StaticText21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM1 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM1, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM1"));
    SpinCtrlTB2_UM1->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR1 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR1, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 22, 0, _T("ID_SPINCTRLTB2_GR1"));
    SpinCtrlTB2_GR1->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW1 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW1, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW1"));
    SpinCtrlTB2_SW1->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText22 = new wxStaticText(PanelTB2, ID_STATICTEXT22, _("2."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    GridSizer2->Add(StaticText22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM2 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM2, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM2"));
    SpinCtrlTB2_UM2->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR2 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR2, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR2"));
    SpinCtrlTB2_GR2->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW2 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW2, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW2"));
    SpinCtrlTB2_SW2->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText23 = new wxStaticText(PanelTB2, ID_STATICTEXT23, _("3."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    GridSizer2->Add(StaticText23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM3 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM3, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM3"));
    SpinCtrlTB2_UM3->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR3 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR3, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR3"));
    SpinCtrlTB2_GR3->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW3 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW3, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW3"));
    SpinCtrlTB2_SW3->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText24 = new wxStaticText(PanelTB2, ID_STATICTEXT24, _("4."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    GridSizer2->Add(StaticText24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM4 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM4, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM4"));
    SpinCtrlTB2_UM4->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR4 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR4, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR4"));
    SpinCtrlTB2_GR4->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW4 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW4, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW4"));
    SpinCtrlTB2_SW4->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText25 = new wxStaticText(PanelTB2, ID_STATICTEXT25, _("5."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    GridSizer2->Add(StaticText25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM5 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM5, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM5"));
    SpinCtrlTB2_UM5->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR5 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR5, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR5"));
    SpinCtrlTB2_GR5->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW5 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW5, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW5"));
    SpinCtrlTB2_SW5->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText26 = new wxStaticText(PanelTB2, ID_STATICTEXT26, _("6."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    GridSizer2->Add(StaticText26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM6 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM6, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM6"));
    SpinCtrlTB2_UM6->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR6 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR6, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR6"));
    SpinCtrlTB2_GR6->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW6 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW6, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW6"));
    SpinCtrlTB2_SW6->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText27 = new wxStaticText(PanelTB2, ID_STATICTEXT27, _("7."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    GridSizer2->Add(StaticText27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM7 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM7, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM7"));
    SpinCtrlTB2_UM7->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR7 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR7, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR7"));
    SpinCtrlTB2_GR7->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW7 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW7, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW7"));
    SpinCtrlTB2_SW7->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText28 = new wxStaticText(PanelTB2, ID_STATICTEXT28, _("8."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    GridSizer2->Add(StaticText28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM8 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM8, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM8"));
    SpinCtrlTB2_UM8->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR8 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR8, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR8"));
    SpinCtrlTB2_GR8->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW8 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW8, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW8"));
    SpinCtrlTB2_SW8->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText29 = new wxStaticText(PanelTB2, ID_STATICTEXT29, _("9."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    GridSizer2->Add(StaticText29, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM9 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM9, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM9"));
    SpinCtrlTB2_UM9->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR9 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR9, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR9"));
    SpinCtrlTB2_GR9->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW9 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW9, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW9"));
    SpinCtrlTB2_SW9->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText30 = new wxStaticText(PanelTB2, ID_STATICTEXT30, _("10."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    GridSizer2->Add(StaticText30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM10 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM10, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM10"));
    SpinCtrlTB2_UM10->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR10 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR10, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR10"));
    SpinCtrlTB2_GR10->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_SW10 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_SW10, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB2_SW10"));
    SpinCtrlTB2_SW10->SetValue(_T("-180"));
    GridSizer2->Add(SpinCtrlTB2_SW10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    PanelTB2->SetSizer(GridSizer2);
    GridSizer2->Fit(PanelTB2);
    GridSizer2->SetSizeHints(PanelTB2);
    PanelTB3 = new wxPanel(Notebook1, ID_PANELTB3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELTB3"));
    GridSizer3 = new wxGridSizer(11, 4, 0, 0);
    StaticText49 = new wxStaticText(PanelTB3, ID_STATICTEXT49, _("Position"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT49"));
    GridSizer3->Add(StaticText49, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText50 = new wxStaticText(PanelTB3, ID_STATICTEXT50, _("Umdrehung/Minute"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT50"));
    GridSizer3->Add(StaticText50, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText51 = new wxStaticText(PanelTB3, ID_STATICTEXT51, _("ZZP (Wert 0° = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT51"));
    GridSizer3->Add(StaticText51, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText73 = new wxStaticText(PanelTB3, ID_STATICTEXT73, _("Schließwinkel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT73"));
    GridSizer3->Add(StaticText73, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText52 = new wxStaticText(PanelTB3, ID_STATICTEXT52, _("1."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT52"));
    GridSizer3->Add(StaticText52, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM1 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM1, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM1"));
    SpinCtrlTB3_UM1->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR1 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR"));
    SpinCtrlTB3_GR1->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW1 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW1, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW1"));
    SpinCtrlTB3_SW1->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText53 = new wxStaticText(PanelTB3, ID_STATICTEXT53, _("2."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT53"));
    GridSizer3->Add(StaticText53, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM2 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM2, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM2"));
    SpinCtrlTB3_UM2->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR2 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR2, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR2"));
    SpinCtrlTB3_GR2->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW2 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW2, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW2"));
    SpinCtrlTB3_SW2->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText54 = new wxStaticText(PanelTB3, ID_STATICTEXT54, _("3."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT54"));
    GridSizer3->Add(StaticText54, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM3 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM3, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM3"));
    SpinCtrlTB3_UM3->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR3 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR3, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR3"));
    SpinCtrlTB3_GR3->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW3 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW3, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW3"));
    SpinCtrlTB3_SW3->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText55 = new wxStaticText(PanelTB3, ID_STATICTEXT55, _("4."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT55"));
    GridSizer3->Add(StaticText55, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM4 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM4, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM4"));
    SpinCtrlTB3_UM4->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR4 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR4, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR4"));
    SpinCtrlTB3_GR4->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW4 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW4, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW4"));
    SpinCtrlTB3_SW4->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText56 = new wxStaticText(PanelTB3, ID_STATICTEXT56, _("5."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT56"));
    GridSizer3->Add(StaticText56, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM5 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM5, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM5"));
    SpinCtrlTB3_UM5->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR5 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR5, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR5"));
    SpinCtrlTB3_GR5->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW5 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW5, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW5"));
    SpinCtrlTB3_SW5->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText57 = new wxStaticText(PanelTB3, ID_STATICTEXT57, _("6."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT57"));
    GridSizer3->Add(StaticText57, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM6 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM6, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM6"));
    SpinCtrlTB3_UM6->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR6 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR6, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR6"));
    SpinCtrlTB3_GR6->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW6 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW6, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW6"));
    SpinCtrlTB3_SW6->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText58 = new wxStaticText(PanelTB3, ID_STATICTEXT58, _("7."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT58"));
    GridSizer3->Add(StaticText58, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM7 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM7, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM7"));
    SpinCtrlTB3_UM7->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR7 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR7, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR7"));
    SpinCtrlTB3_GR7->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW7 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW7, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW7"));
    SpinCtrlTB3_SW7->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText59 = new wxStaticText(PanelTB3, ID_STATICTEXT59, _("8."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT59"));
    GridSizer3->Add(StaticText59, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM8 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM8, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM8"));
    SpinCtrlTB3_UM8->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR8 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR8, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR8"));
    SpinCtrlTB3_GR8->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW8 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW8, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW8"));
    SpinCtrlTB3_SW8->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText60 = new wxStaticText(PanelTB3, ID_STATICTEXT60, _("9."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT60"));
    GridSizer3->Add(StaticText60, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM9 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM9, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM9"));
    SpinCtrlTB3_UM9->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR9 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR9, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR9"));
    SpinCtrlTB3_GR9->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW9 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW9, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW9"));
    SpinCtrlTB3_SW9->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW9, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText61 = new wxStaticText(PanelTB3, ID_STATICTEXT61, _("10."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT61"));
    GridSizer3->Add(StaticText61, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM10 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM10, _T("0"), wxDefaultPosition, wxSize(120,25), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM10"));
    SpinCtrlTB3_UM10->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR10 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR10, _T("0"), wxDefaultPosition, wxSize(120,25), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR10"));
    SpinCtrlTB3_GR10->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_SW10 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_SW10, _T("-180"), wxDefaultPosition, wxSize(120,25), 0, -240, -140, -180, _T("ID_SPINCTRLTB3_SW10"));
    SpinCtrlTB3_SW10->SetValue(_T("-180"));
    GridSizer3->Add(SpinCtrlTB3_SW10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    PanelTB3->SetSizer(GridSizer3);
    GridSizer3->Fit(PanelTB3);
    GridSizer3->SetSizeHints(PanelTB3);
    EchtWerte = new wxPanel(Notebook1, ID_PANELEchtWerte, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELEchtWerte"));
    FlexGridSizer2 = new wxFlexGridSizer(7, 4, 10, 0);
    StaticText46 = new wxStaticText(EchtWerte, ID_STATICTEXT46, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT46"));
    FlexGridSizer2->Add(StaticText46, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText45 = new wxStaticText(EchtWerte, ID_STATICTEXT45, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT45"));
    FlexGridSizer2->Add(StaticText45, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText44 = new wxStaticText(EchtWerte, ID_STATICTEXT44, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT44"));
    FlexGridSizer2->Add(StaticText44, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText109 = new wxStaticText(EchtWerte, ID_STATICTEXT109, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT109"));
    FlexGridSizer2->Add(StaticText109, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText112 = new wxStaticText(EchtWerte, ID_STATICTEXT112, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT112"));
    FlexGridSizer2->Add(StaticText112, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText38 = new wxStaticText(EchtWerte, ID_STATICTEXT38, _("Umdrehungen/Minute:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT38"));
    FlexGridSizer2->Add(StaticText38, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlRPM = new wxTextCtrl(EchtWerte, ID_TEXTCTRLRPM, _("00000"), wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLRPM"));
    TextCtrlRPM->SetMaxLength(5);
    FlexGridSizer2->Add(TextCtrlRPM, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText39 = new wxStaticText(EchtWerte, ID_STATICTEXT39, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
    FlexGridSizer2->Add(StaticText39, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText115 = new wxStaticText(EchtWerte, ID_STATICTEXT115, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT115"));
    FlexGridSizer2->Add(StaticText115, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText42 = new wxStaticText(EchtWerte, ID_STATICTEXT42, _("Umdrehungen/Sekunde:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT42"));
    FlexGridSizer2->Add(StaticText42, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(EchtWerte, ID_TEXTCTRL1, _("00000"), wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetMaxLength(5);
    FlexGridSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText43 = new wxStaticText(EchtWerte, ID_STATICTEXT43, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT43"));
    FlexGridSizer2->Add(StaticText43, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText118 = new wxStaticText(EchtWerte, ID_STATICTEXT118, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT118"));
    FlexGridSizer2->Add(StaticText118, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText40 = new wxStaticText(EchtWerte, ID_STATICTEXT40, _("Zeit pro Umdrehung:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT40"));
    FlexGridSizer2->Add(StaticText40, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlTPR = new wxTextCtrl(EchtWerte, ID_TEXTCTRLTPR, _("0000"), wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLTPR"));
    TextCtrlTPR->SetMaxLength(4);
    FlexGridSizer2->Add(TextCtrlTPR, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText41 = new wxStaticText(EchtWerte, ID_STATICTEXT41, _("Millisekunden"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT41"));
    FlexGridSizer2->Add(StaticText41, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText121 = new wxStaticText(EchtWerte, ID_STATICTEXT121, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT121"));
    FlexGridSizer2->Add(StaticText121, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText47 = new wxStaticText(EchtWerte, ID_STATICTEXT47, _("Zündzeitpunkt:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT47"));
    FlexGridSizer2->Add(StaticText47, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(EchtWerte, ID_TEXTCTRL2, _("0"), wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->SetMaxLength(3);
    FlexGridSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText48 = new wxStaticText(EchtWerte, ID_STATICTEXT48, _("Grad"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT48"));
    FlexGridSizer2->Add(StaticText48, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText124 = new wxStaticText(EchtWerte, ID_STATICTEXT124, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT124"));
    FlexGridSizer2->Add(StaticText124, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText70 = new wxStaticText(EchtWerte, ID_STATICTEXT70, _("Schließwinkel:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT70"));
    FlexGridSizer2->Add(StaticText70, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(EchtWerte, ID_TEXTCTRL3, _("0"), wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    TextCtrl3->SetMaxLength(4);
    FlexGridSizer2->Add(TextCtrl3, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText71 = new wxStaticText(EchtWerte, ID_STATICTEXT71, _("Grad"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT71"));
    FlexGridSizer2->Add(StaticText71, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText125 = new wxStaticText(EchtWerte, ID_STATICTEXT125, wxEmptyString, wxDefaultPosition, wxSize(150,0), 0, _T("ID_STATICTEXT125"));
    FlexGridSizer2->Add(StaticText125, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(EchtWerte, ID_STATICTEXT3, _("Modus:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlEchtModus = new wxTextCtrl(EchtWerte, ID_TEXTCTRLEchtModus, _("Mx"), wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLEchtModus"));
    TextCtrlEchtModus->SetMaxLength(2);
    FlexGridSizer2->Add(TextCtrlEchtModus, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(EchtWerte, ID_STATICTEXT5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    EchtWerte->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(EchtWerte);
    FlexGridSizer2->SetSizeHints(EchtWerte);
    ZSpule = new wxPanel(Notebook1, ID_PANEL_ZSpule, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL_ZSpule"));
    FlexGridSizer3 = new wxFlexGridSizer(16, 7, 0, 1);
    StaticText78 = new wxStaticText(ZSpule, ID_STATICTEXT78, _("Spulenspannung:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT78"));
    FlexGridSizer3->Add(StaticText78, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    Spannung = new wxChoice(ZSpule, ID_CHOICE1, wxDefaultPosition, wxSize(80,25), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Spannung->Append(_("6 V"));
    Spannung->SetSelection( Spannung->Append(_("12 V")) );
    FlexGridSizer3->Add(Spannung, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText77 = new wxStaticText(ZSpule, ID_STATICTEXT77, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT77"));
    FlexGridSizer3->Add(StaticText77, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText81 = new wxStaticText(ZSpule, ID_STATICTEXT81, _("Strom:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT81"));
    FlexGridSizer3->Add(StaticText81, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlStrom = new wxTextCtrl(ZSpule, ID_TEXTCTRLStrom, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLStrom"));
    TextCtrlStrom->SetMaxLength(3);
    FlexGridSizer3->Add(TextCtrlStrom, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText83 = new wxStaticText(ZSpule, ID_STATICTEXT83, _("A"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT83"));
    FlexGridSizer3->Add(StaticText83, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText64 = new wxStaticText(ZSpule, ID_STATICTEXT64, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT64"));
    FlexGridSizer3->Add(StaticText64, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText66 = new wxStaticText(ZSpule, ID_STATICTEXT66, _("Wiederstand Primärwindung:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT66"));
    FlexGridSizer3->Add(StaticText66, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    WiederstandPrim = new wxSpinCtrlDouble(ZSpule, ID_SPINCTRLDOUBLE1, _T("5"), wxDefaultPosition, wxSize(110,25), wxALIGN_RIGHT, 0, 10, 0, 0.1, _T("ID_SPINCTRLDOUBLE1"));
    WiederstandPrim->SetValue(_T("5"));
    FlexGridSizer3->Add(WiederstandPrim, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText74 = new wxStaticText(ZSpule, ID_STATICTEXT74, _("Ohm"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT74"));
    FlexGridSizer3->Add(StaticText74, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText86 = new wxStaticText(ZSpule, ID_STATICTEXT86, _("Leistg:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT86"));
    FlexGridSizer3->Add(StaticText86, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlWatt = new wxTextCtrl(ZSpule, ID_TEXTCTRLWatt, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLWatt"));
    TextCtrlWatt->SetMaxLength(5);
    FlexGridSizer3->Add(TextCtrlWatt, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText88 = new wxStaticText(ZSpule, ID_STATICTEXT88, _("W"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT88"));
    FlexGridSizer3->Add(StaticText88, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText65 = new wxStaticText(ZSpule, ID_STATICTEXT65, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT65"));
    FlexGridSizer3->Add(StaticText65, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText75 = new wxStaticText(ZSpule, ID_STATICTEXT75, _("Induktivität Primärwindung:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT75"));
    FlexGridSizer3->Add(StaticText75, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    InduktPrim = new wxSpinCtrlDouble(ZSpule, ID_SPINCTRLDOUBLE2, _T("10"), wxDefaultPosition, wxSize(110,25), wxALIGN_RIGHT, 0, 50, 0, 0.1, _T("ID_SPINCTRLDOUBLE2"));
    InduktPrim->SetValue(_T("10"));
    FlexGridSizer3->Add(InduktPrim, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText76 = new wxStaticText(ZSpule, ID_STATICTEXT76, _("mH"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT76"));
    FlexGridSizer3->Add(StaticText76, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText89 = new wxStaticText(ZSpule, ID_STATICTEXT89, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT89"));
    FlexGridSizer3->Add(StaticText89, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText90 = new wxStaticText(ZSpule, ID_STATICTEXT90, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT90"));
    FlexGridSizer3->Add(StaticText90, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText91 = new wxStaticText(ZSpule, ID_STATICTEXT91, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT91"));
    FlexGridSizer3->Add(StaticText91, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText82 = new wxStaticText(ZSpule, ID_STATICTEXT82, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT82"));
    FlexGridSizer3->Add(StaticText82, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText79 = new wxStaticText(ZSpule, ID_STATICTEXT79, _("Sättigungsfaktor:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT79"));
    FlexGridSizer3->Add(StaticText79, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    Saturation = new wxSpinCtrl(ZSpule, ID_SPINCTRLSpinCtrlSatturationF, _T("3"), wxDefaultPosition, wxSize(110,25), wxALIGN_RIGHT, 0, 10, 3, _T("ID_SPINCTRLSpinCtrlSatturationF"));
    Saturation->SetValue(_T("3"));
    FlexGridSizer3->Add(Saturation, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText80 = new wxStaticText(ZSpule, ID_STATICTEXT80, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT80"));
    FlexGridSizer3->Add(StaticText80, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText92 = new wxStaticText(ZSpule, ID_STATICTEXT92, _("max. S-Winkel"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT92"));
    FlexGridSizer3->Add(StaticText92, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlMaxSchlWin = new wxSpinCtrl(ZSpule, ID_SPINCTRLMaxSchlWin, _T("270"), wxDefaultPosition, wxSize(110,25), 0, 0, 360, 270, _T("ID_SPINCTRLMaxSchlWin"));
    SpinCtrlMaxSchlWin->SetValue(_T("270"));
    FlexGridSizer3->Add(SpinCtrlMaxSchlWin, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ButtonZPBerechnen = new wxButton(ZSpule, ID_BUTTONZPBerechnen, _("Berechnen"), wxDefaultPosition, wxSize(80,30), 0, wxDefaultValidator, _T("ID_BUTTONZPBerechnen"));
    FlexGridSizer3->Add(ButtonZPBerechnen, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText87 = new wxStaticText(ZSpule, ID_STATICTEXT87, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT87"));
    FlexGridSizer3->Add(StaticText87, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText84 = new wxStaticText(ZSpule, ID_STATICTEXT84, _("Zeit Sättigung:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT84"));
    FlexGridSizer3->Add(StaticText84, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlSatTime = new wxTextCtrl(ZSpule, ID_TEXTCTRLSatTime, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLSatTime"));
    TextCtrlSatTime->SetMaxLength(4);
    FlexGridSizer3->Add(TextCtrlSatTime, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText85 = new wxStaticText(ZSpule, ID_STATICTEXT85, _("ms"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT85"));
    FlexGridSizer3->Add(StaticText85, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText95 = new wxStaticText(ZSpule, ID_STATICTEXT95, _("max. Energie:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT95"));
    FlexGridSizer3->Add(StaticText95, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlZPEnergie = new wxTextCtrl(ZSpule, ID_TEXTCTRLZPEnergie, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLZPEnergie"));
    TextCtrlZPEnergie->SetMaxLength(5);
    FlexGridSizer3->Add(TextCtrlZPEnergie, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText96 = new wxStaticText(ZSpule, ID_STATICTEXT96, _("mWs"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT96"));
    FlexGridSizer3->Add(StaticText96, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText94 = new wxStaticText(ZSpule, ID_STATICTEXT94, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT94"));
    FlexGridSizer3->Add(StaticText94, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText101 = new wxStaticText(ZSpule, ID_STATICTEXT101, _("U/min"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT101"));
    FlexGridSizer3->Add(StaticText101, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText102 = new wxStaticText(ZSpule, ID_STATICTEXT102, _("         ms/U"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT102"));
    FlexGridSizer3->Add(StaticText102, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText103 = new wxStaticText(ZSpule, ID_STATICTEXT103, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT103"));
    FlexGridSizer3->Add(StaticText103, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText104 = new wxStaticText(ZSpule, ID_STATICTEXT104, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT104"));
    FlexGridSizer3->Add(StaticText104, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText105 = new wxStaticText(ZSpule, ID_STATICTEXT105, _("S-Winkel (Grad)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT105"));
    FlexGridSizer3->Add(StaticText105, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText106 = new wxStaticText(ZSpule, ID_STATICTEXT106, _("Energie (mWs)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT106"));
    FlexGridSizer3->Add(StaticText106, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText98 = new wxStaticText(ZSpule, ID_STATICTEXT98, _("Prozent"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT98"));
    FlexGridSizer3->Add(StaticText98, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM1 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM1, _T("2000"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 2000, _T("ID_SPINCTRLRPM1"));
    SpinCtrlRPM1->SetValue(_T("2000"));
    FlexGridSizer3->Add(SpinCtrlRPM1, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU1 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU1, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU1"));
    FlexGridSizer3->Add(TextCtrlMSU1, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText107 = new wxStaticText(ZSpule, ID_STATICTEXT107, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT107"));
    FlexGridSizer3->Add(StaticText107, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText108 = new wxStaticText(ZSpule, ID_STATICTEXT108, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT108"));
    FlexGridSizer3->Add(StaticText108, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU1 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU1, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU1"));
    FlexGridSizer3->Add(TextCtrlGRADU1, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD1 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD1, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD1"));
    FlexGridSizer3->Add(TextCtrlLD1, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz1 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz1, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz1"));
    FlexGridSizer3->Add(TextCtrlProz1, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM2 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM2, _T("3000"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 3000, _T("ID_SPINCTRLRPM2"));
    SpinCtrlRPM2->SetValue(_T("3000"));
    FlexGridSizer3->Add(SpinCtrlRPM2, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU2 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU2, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU2"));
    FlexGridSizer3->Add(TextCtrlMSU2, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText110 = new wxStaticText(ZSpule, ID_STATICTEXT110, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT110"));
    FlexGridSizer3->Add(StaticText110, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText111 = new wxStaticText(ZSpule, ID_STATICTEXT111, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT111"));
    FlexGridSizer3->Add(StaticText111, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU2 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU2, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU2"));
    FlexGridSizer3->Add(TextCtrlGRADU2, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD2 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD2, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD2"));
    FlexGridSizer3->Add(TextCtrlLD2, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz2 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz2, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz2"));
    FlexGridSizer3->Add(TextCtrlProz2, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM3 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM3, _T("3500"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 3500, _T("ID_SPINCTRLRPM3"));
    SpinCtrlRPM3->SetValue(_T("3500"));
    FlexGridSizer3->Add(SpinCtrlRPM3, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU3 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU3, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU3"));
    TextCtrlMSU3->SetMaxSize(wxSize(80,25));
    FlexGridSizer3->Add(TextCtrlMSU3, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText113 = new wxStaticText(ZSpule, ID_STATICTEXT113, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT113"));
    FlexGridSizer3->Add(StaticText113, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText114 = new wxStaticText(ZSpule, ID_STATICTEXT114, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT114"));
    FlexGridSizer3->Add(StaticText114, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU3 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU3, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU3"));
    FlexGridSizer3->Add(TextCtrlGRADU3, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD3 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD3, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD3"));
    FlexGridSizer3->Add(TextCtrlLD3, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz3 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz3, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz3"));
    FlexGridSizer3->Add(TextCtrlProz3, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM4 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM4, _T("4000"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 4000, _T("ID_SPINCTRLRPM4"));
    SpinCtrlRPM4->SetValue(_T("4000"));
    FlexGridSizer3->Add(SpinCtrlRPM4, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU4 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU4, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU4"));
    TextCtrlMSU4->SetMaxSize(wxSize(80,25));
    FlexGridSizer3->Add(TextCtrlMSU4, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText116 = new wxStaticText(ZSpule, ID_STATICTEXT116, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT116"));
    FlexGridSizer3->Add(StaticText116, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText117 = new wxStaticText(ZSpule, ID_STATICTEXT117, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT117"));
    FlexGridSizer3->Add(StaticText117, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU4 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU4, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU4"));
    FlexGridSizer3->Add(TextCtrlGRADU4, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD4 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD4, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD4"));
    FlexGridSizer3->Add(TextCtrlLD4, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz4 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz4, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz4"));
    FlexGridSizer3->Add(TextCtrlProz4, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM5 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM5, _T("4500"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 4500, _T("ID_SPINCTRLRPM5"));
    SpinCtrlRPM5->SetValue(_T("4500"));
    FlexGridSizer3->Add(SpinCtrlRPM5, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU5 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU5, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU5"));
    TextCtrlMSU5->SetMaxSize(wxSize(80,25));
    FlexGridSizer3->Add(TextCtrlMSU5, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText119 = new wxStaticText(ZSpule, ID_STATICTEXT119, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT119"));
    FlexGridSizer3->Add(StaticText119, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText120 = new wxStaticText(ZSpule, ID_STATICTEXT120, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT120"));
    FlexGridSizer3->Add(StaticText120, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU5 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU5, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU5"));
    FlexGridSizer3->Add(TextCtrlGRADU5, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD5 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD5, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD5"));
    FlexGridSizer3->Add(TextCtrlLD5, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz5 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz5, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz5"));
    FlexGridSizer3->Add(TextCtrlProz5, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM6 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM6, _T("5000"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 5000, _T("ID_SPINCTRLRPM6"));
    SpinCtrlRPM6->SetValue(_T("5000"));
    FlexGridSizer3->Add(SpinCtrlRPM6, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU6 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU6, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU6"));
    TextCtrlMSU6->SetMaxSize(wxSize(80,25));
    FlexGridSizer3->Add(TextCtrlMSU6, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText122 = new wxStaticText(ZSpule, ID_STATICTEXT122, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT122"));
    FlexGridSizer3->Add(StaticText122, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText123 = new wxStaticText(ZSpule, ID_STATICTEXT123, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT123"));
    FlexGridSizer3->Add(StaticText123, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU6 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU6, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU6"));
    FlexGridSizer3->Add(TextCtrlGRADU6, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD6 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD6, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD6"));
    FlexGridSizer3->Add(TextCtrlLD6, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz6 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz6, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz6"));
    FlexGridSizer3->Add(TextCtrlProz6, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM7 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM7, _T("5500"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 5500, _T("ID_SPINCTRLRPM7"));
    SpinCtrlRPM7->SetValue(_T("5500"));
    FlexGridSizer3->Add(SpinCtrlRPM7, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU7 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU7, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU7"));
    FlexGridSizer3->Add(TextCtrlMSU7, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText126 = new wxStaticText(ZSpule, ID_STATICTEXT126, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT126"));
    FlexGridSizer3->Add(StaticText126, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText127 = new wxStaticText(ZSpule, ID_STATICTEXT127, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT127"));
    FlexGridSizer3->Add(StaticText127, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU7 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU7, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU7"));
    FlexGridSizer3->Add(TextCtrlGRADU7, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD7 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD7, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD7"));
    FlexGridSizer3->Add(TextCtrlLD7, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz7 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz7, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz7"));
    FlexGridSizer3->Add(TextCtrlProz7, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM8 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM8, _T("6000"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 6000, _T("ID_SPINCTRLRPM8"));
    SpinCtrlRPM8->SetValue(_T("6000"));
    FlexGridSizer3->Add(SpinCtrlRPM8, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU8 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU8, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU8"));
    FlexGridSizer3->Add(TextCtrlMSU8, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText93 = new wxStaticText(ZSpule, ID_STATICTEXT93, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT93"));
    FlexGridSizer3->Add(StaticText93, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText97 = new wxStaticText(ZSpule, ID_STATICTEXT97, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT97"));
    FlexGridSizer3->Add(StaticText97, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU8 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU8, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU8"));
    FlexGridSizer3->Add(TextCtrlGRADU8, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD8 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD8, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD8"));
    FlexGridSizer3->Add(TextCtrlLD8, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz8 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz8, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz8"));
    FlexGridSizer3->Add(TextCtrlProz8, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM9 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM9, _T("6500"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 6500, _T("ID_SPINCTRLRPM9"));
    SpinCtrlRPM9->SetValue(_T("6500"));
    FlexGridSizer3->Add(SpinCtrlRPM9, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU9 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU9, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU9"));
    FlexGridSizer3->Add(TextCtrlMSU9, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText99 = new wxStaticText(ZSpule, ID_STATICTEXT99, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT99"));
    FlexGridSizer3->Add(StaticText99, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText100 = new wxStaticText(ZSpule, ID_STATICTEXT100, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT100"));
    FlexGridSizer3->Add(StaticText100, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU9 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU9, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU9"));
    FlexGridSizer3->Add(TextCtrlGRADU9, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD9 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD9, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD9"));
    FlexGridSizer3->Add(TextCtrlLD9, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz9 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz9, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz9"));
    FlexGridSizer3->Add(TextCtrlProz9, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlRPM10 = new wxSpinCtrl(ZSpule, ID_SPINCTRLRPM10, _T("7000"), wxDefaultPosition, wxSize(120,25), 0, 0, 20000, 7000, _T("ID_SPINCTRLRPM10"));
    SpinCtrlRPM10->SetValue(_T("7000"));
    FlexGridSizer3->Add(SpinCtrlRPM10, 4, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlMSU10 = new wxTextCtrl(ZSpule, ID_TEXTCTRLMSU10, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLMSU10"));
    FlexGridSizer3->Add(TextCtrlMSU10, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText129 = new wxStaticText(ZSpule, ID_STATICTEXT129, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT129"));
    FlexGridSizer3->Add(StaticText129, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText130 = new wxStaticText(ZSpule, ID_STATICTEXT130, _("min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT130"));
    FlexGridSizer3->Add(StaticText130, 4, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlGRADU10 = new wxTextCtrl(ZSpule, ID_TEXTCTRLGRADU10, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLGRADU10"));
    FlexGridSizer3->Add(TextCtrlGRADU10, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlLD10 = new wxTextCtrl(ZSpule, ID_TEXTCTRLLD10, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLLD10"));
    FlexGridSizer3->Add(TextCtrlLD10, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlProz10 = new wxTextCtrl(ZSpule, ID_TEXTCTRLProz10, wxEmptyString, wxDefaultPosition, wxSize(80,25), wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLProz10"));
    FlexGridSizer3->Add(TextCtrlProz10, 4, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    ZSpule->SetSizer(FlexGridSizer3);
    FlexGridSizer3->Fit(ZSpule);
    FlexGridSizer3->SetSizeHints(ZSpule);
    Notebook1->AddPage(PanelBasis, _("Basis"), false);
    Notebook1->AddPage(PanelTB1, _("Tabelle1"), false);
    Notebook1->AddPage(PanelTB2, _("Tabelle2"), false);
    Notebook1->AddPage(PanelTB3, _("Tabelle3"), false);
    Notebook1->AddPage(EchtWerte, _("Werte"), false);
    Notebook1->AddPage(ZSpule, _("Zündspule"), false);
    BoxSizer1->Add(Notebook1, 2, wxALL|wxEXPAND, 5);
    TextCtrlLOG = new wxTextCtrl(Panel1, ID_TEXTCTRLLOG, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxTE_LEFT|wxTE_WORDWRAP, wxDefaultValidator, _T("ID_TEXTCTRLLOG"));
    BoxSizer1->Add(TextCtrlLOG, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    HauptMenuBar = new wxMenuBar();
    Datei = new wxMenu();
    MenuItem5 = new wxMenuItem(Datei, idMenuSpeichern, _("Konfiguration Speichern\tAlt-S"), _("Speichern Konfiguration in Datei"), wxITEM_NORMAL);
    Datei->Append(MenuItem5);
    MenuItem8 = new wxMenuItem(Datei, idMenuLaden, _("Konfiguration Laden\tAlt-L"), _("Laden Konfiguration aus Datei"), wxITEM_NORMAL);
    Datei->Append(MenuItem8);
    Datei->AppendSeparator();
    MenuItem2 = new wxMenuItem(Datei, idMenuLogLeeren, _("Logausgabe leeren"), _("Logausgabefenster leeren"), wxITEM_NORMAL);
    Datei->Append(MenuItem2);
    Datei->AppendSeparator();
    MenuItem1 = new wxMenuItem(Datei, idMenuQuit, _("Schließen\tAlt-F4"), _("Programmen beenden"), wxITEM_NORMAL);
    Datei->Append(MenuItem1);
    HauptMenuBar->Append(Datei, _("Datei"));
    Kommunikation = new wxMenu();
    Komm_VerbModul = new wxMenuItem(Kommunikation, idMenuVerbinden, _("Verbinden Zündmodul"), _("Verbinden Modul"), wxITEM_NORMAL);
    Kommunikation->Append(Komm_VerbModul);
    Komm_TennModul = new wxMenuItem(Kommunikation, idMenuTrennen, _("Trennen Zündmodul"), _("Trennen Modul"), wxITEM_NORMAL);
    Kommunikation->Append(Komm_TennModul);
    Komm_TennModul->Enable(false);
    Kommunikation->AppendSeparator();
    Komm_KonfRueber = new wxMenuItem(Kommunikation, idMenuKonfigLaden, _("Konfig übertragen -> Zündmodul"), _("Konfiguration in Zündmodul laden"), wxITEM_NORMAL);
    Kommunikation->Append(Komm_KonfRueber);
    Komm_KonfRueber->Enable(false);
    Komm_EEpromSave = new wxMenuItem(Kommunikation, idMenuKonfigESpeichern, _("Konfig übetragen + Ablegen im EEprom"), _("Konfiguration übertragen und im EEprom ablegen"), wxITEM_NORMAL);
    Kommunikation->Append(Komm_EEpromSave);
    Komm_EEpromSave->Enable(false);
    Kommunikation->AppendSeparator();
    Komm_KonfHolen = new wxMenuItem(Kommunikation, idMenuidMenuKonfigHolen, _("Konfig holen <- Zündmodul"), _("Konfiguration aus Zündmodul holen"), wxITEM_NORMAL);
    Kommunikation->Append(Komm_KonfHolen);
    Komm_KonfHolen->Enable(false);
    Kommunikation->AppendSeparator();
    Komm_LogMode = new wxMenuItem(Kommunikation, idMenuLogmodus, _("Modul Log-Modus"), _("Im Modul den Log-Modus an/abschalte"), wxITEM_CHECK);
    Kommunikation->Append(Komm_LogMode);
    Komm_LogMode->Enable(false);
    HauptMenuBar->Append(Kommunikation, _("Kommunikation"));
    Hilfe = new wxMenu();
    Hilfe_Info = new wxMenuItem(Hilfe, idMenuAbout, _("Info\tF1"), _("Zeigt Programm Infos"), wxITEM_NORMAL);
    Hilfe->Append(Hilfe_Info);
    HauptMenuBar->Append(Hilfe, _("Hilfe"));
    SetMenuBar(HauptMenuBar);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { -1, -1 };
    int __wxStatusBarStyles_1[2] = { wxSB_RAISED, wxSB_RAISED };
    StatusBar1->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_RADIOBOXBasisfunktion,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnDataChange);
    Connect(ID_SPINCTRLStarthilfe,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLStarthilfeUMDR,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRL2FZZP,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLSchliessWinkel,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_CHOICETAB,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnDataChange);
    Connect(ID_CHOICELED,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnDataChange);
    Connect(ID_SPINCTRLTB1_UM1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_SW1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_UM2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_SW2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_UM3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_SW3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_UM4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_SW4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_UM5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_SW5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_UM6,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR6,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_UM7,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR7,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_SW7,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_UM8,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR8,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_SW8,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_UM9,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR9,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_SW9,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_UM10,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_GR10,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB1_SW10,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM6,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM7,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM8,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM9,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB2_UM10,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM1,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM2,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM3,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM4,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM5,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM6,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM7,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM8,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM9,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_SPINCTRLTB3_UM10,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&USBLoader2Frame::OnSpinCtrlChange);
    Connect(ID_BUTTONZPBerechnen,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&USBLoader2Frame::OnButtonZPBerechnenClick);
    Connect(idMenuSpeichern,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnSpeichern);
    Connect(idMenuLaden,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnLadenKonfig);
    Connect(idMenuLogLeeren,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnMenuItemLogLeerenSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnQuit);
    Connect(idMenuVerbinden,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnConnectUsb);
    Connect(idMenuTrennen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnDisconnectUsb);
    Connect(idMenuKonfigLaden,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnConfigUpload);
    Connect(idMenuKonfigESpeichern,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnKomm_EEpromSaveSelected);
    Connect(idMenuidMenuKonfigHolen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnConfigDownload);
    Connect(idMenuLogmodus,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnLogModeSet);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnAbout);
    //*)

    resetConfigChange();
    //* set some default Values
    wxStreamToTextRedirector redirect(TextCtrlLOG);

	this->SetStatusText(STR_CONNECTION_STATUS_NOT_CONNECTED, 1);
    digiSpark = NULL;
}

USBLoader2Frame::~USBLoader2Frame()
{
    //(*Destroy(USBLoader2Frame)
    //*)
    fininish = true;
    if (digiSpark != NULL) delete digiSpark;
}

void USBLoader2Frame::activateMenuComm(bool val)
{
    Komm_TennModul->Enable(val);
    Komm_KonfRueber->Enable(val);
    Komm_KonfHolen->Enable(val);
    Komm_LogMode->Enable(val);
    Komm_VerbModul->Enable(!val);
    Komm_EEpromSave->Enable(val);
}

void USBLoader2Frame::writeLog(wxString str)
{
    if (str.size() > 0) TextCtrlLOG->AppendText(str);
}


void USBLoader2Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void USBLoader2Frame::OnAbout(wxCommandEvent& event)
{
    //wxString msg = wxbuildinfo(long_f);
    //wxMessageBox(msg, _("Welcome to..."));
    About aDialog(this);
    aDialog.ShowModal();
}

void USBLoader2Frame::OnDisconnectUsb(wxCommandEvent& event)
{
    fininish = true;
    if (digiSpark != NULL) delete digiSpark;
    digiSpark = NULL;
    connected = false;
	this->SetStatusText(STR_CONNECTION_STATUS_NOT_CONNECTED, 1);
	activateMenuComm(false);
}

void USBLoader2Frame::OnConnectUsb(wxCommandEvent& event)
{
    wxString m, s;

    if (connected == true) // vendor 5824, product 1503
	{
        writeLog(STR_USB_DEVICE_ALREADY_CONNECTED + '\n');
		return;
	}

	//wxStreamToTextRedirector redirect(TextCtrlLOG);

	fininish = false;
	digiSpark = new USBDevice();

	//digiSpark->connect_device();
	digiSpark->connect_device_with_search();

	if (digiSpark->isConnected()) // vendor 5824, product 1503
	{
	    //writeLog(digiSpark->getLog());
		this->SetStatusText(STR_CONNECTION_STATUS_CONNECTED, 1);
		connected = true;
	}
	else
	{
        this->SetStatusText(STR_CONNECTION_STATUS_NOT_CONNECTED, 1);
        writeLog(STR_USB_NOT_FOUND + '\n');
        writeLog(digiSpark->print_deviceList());
        writeLog(digiSpark->getLog());
		connected = false;
		delete digiSpark;
		activateMenuComm(false);
		return; // exit no device connected
	}
    CheckLOGMode();
    activateMenuComm(true);

	while (fininish == false) {
		writeLog(digiSpark->getLog());

		wxYield();
		//::wxSleep(1);
	}
	return;
}

void USBLoader2Frame::OnSpeichern(wxCommandEvent& event)
{
    wxFileConfig *ConfigINI;
    wxString appPath, tmps;


    wxFileDialog saveFileDialog(this, _("Konfiguration speichern"), "", "", "CFG Dateien (*.cfg)|*.cfg", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (saveFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    appPath = saveFileDialog.GetPath();
    tmps = appPath.AfterLast('.');
    if (appPath.AfterLast('.') != "cfg")
    {
        appPath.append(".cfg");
    }

    ConfigINI = new wxFileConfig(wxEmptyString, wxEmptyString, appPath);
    ConfigINI->DeleteAll(); // clean before write the whole config

    ConfigINI->SetPath("/Basis");
	ConfigINI->Write("Basisfunktion",RadioBoxBasisfunktion->GetSelection());
    ConfigINI->Write("StarthilfeZZP",SpinCtrlStarthilfe->GetValue());
    ConfigINI->Write("StarthilfeUPM",SpinCtrlStarthilfeUMDR->GetValue());
    ConfigINI->Write("ZZP",SpinCtrlFZZP->GetValue());
    ConfigINI->Write("SlWiFest",SpinCtrlSchliessWinkel->GetValue());
    ConfigINI->Write("ZTAB",ChoiceTAB->GetSelection());
    ConfigINI->Write("LED",ChoiceLED->GetSelection());

    ConfigINI->SetPath("/Tabelle1");
    ConfigINI->Write("UPM1",SpinCtrlTB1_UM1->GetValue());
    ConfigINI->Write("Grad1",SpinCtrlTB1_GR1->GetValue());
    ConfigINI->Write("SlWi1",SpinCtrlTB1_SW1->GetValue());
    ConfigINI->Write("UPM2",SpinCtrlTB1_UM2->GetValue());
    ConfigINI->Write("Grad2",SpinCtrlTB1_GR2->GetValue());
    ConfigINI->Write("SlWi2",SpinCtrlTB1_SW2->GetValue());
    ConfigINI->Write("UPM3",SpinCtrlTB1_UM3->GetValue());
    ConfigINI->Write("Grad3",SpinCtrlTB1_GR3->GetValue());
    ConfigINI->Write("SlWi3",SpinCtrlTB1_SW3->GetValue());
    ConfigINI->Write("UPM4",SpinCtrlTB1_UM4->GetValue());
    ConfigINI->Write("Grad4",SpinCtrlTB1_GR4->GetValue());
    ConfigINI->Write("SlWi4",SpinCtrlTB1_SW4->GetValue());
    ConfigINI->Write("UPM5",SpinCtrlTB1_UM5->GetValue());
    ConfigINI->Write("Grad5",SpinCtrlTB1_GR5->GetValue());
    ConfigINI->Write("SlWi5",SpinCtrlTB1_SW5->GetValue());
    ConfigINI->Write("UPM6",SpinCtrlTB1_UM6->GetValue());
    ConfigINI->Write("Grad6",SpinCtrlTB1_GR6->GetValue());
    ConfigINI->Write("SlWi6",SpinCtrlTB1_SW6->GetValue());
    ConfigINI->Write("UPM7",SpinCtrlTB1_UM7->GetValue());
    ConfigINI->Write("Grad7",SpinCtrlTB1_GR7->GetValue());
    ConfigINI->Write("SlWi7",SpinCtrlTB1_SW7->GetValue());
    ConfigINI->Write("UPM8",SpinCtrlTB1_UM8->GetValue());
    ConfigINI->Write("Grad8",SpinCtrlTB1_GR8->GetValue());
    ConfigINI->Write("SlWi8",SpinCtrlTB1_SW8->GetValue());
    ConfigINI->Write("UPM9",SpinCtrlTB1_UM9->GetValue());
    ConfigINI->Write("Grad9",SpinCtrlTB1_GR9->GetValue());
    ConfigINI->Write("SlWi9",SpinCtrlTB1_SW9->GetValue());
    ConfigINI->Write("UPM10",SpinCtrlTB1_UM10->GetValue());
    ConfigINI->Write("Grad10",SpinCtrlTB1_GR10->GetValue());
    ConfigINI->Write("SlWi10",SpinCtrlTB1_SW10->GetValue());

    ConfigINI->SetPath("/Tabelle2");
    ConfigINI->Write("UPM1",SpinCtrlTB2_UM1->GetValue());
    ConfigINI->Write("Grad1",SpinCtrlTB2_GR1->GetValue());
    ConfigINI->Write("SlWi1",SpinCtrlTB2_SW1->GetValue());
    ConfigINI->Write("UPM2",SpinCtrlTB2_UM2->GetValue());
    ConfigINI->Write("Grad2",SpinCtrlTB2_GR2->GetValue());
    ConfigINI->Write("SlWi2",SpinCtrlTB2_SW2->GetValue());
    ConfigINI->Write("UPM3",SpinCtrlTB2_UM3->GetValue());
    ConfigINI->Write("Grad3",SpinCtrlTB2_GR3->GetValue());
    ConfigINI->Write("SlWi3",SpinCtrlTB2_SW3->GetValue());
    ConfigINI->Write("UPM4",SpinCtrlTB2_UM4->GetValue());
    ConfigINI->Write("Grad4",SpinCtrlTB2_GR4->GetValue());
    ConfigINI->Write("SlWi4",SpinCtrlTB2_SW4->GetValue());
    ConfigINI->Write("UPM5",SpinCtrlTB2_UM5->GetValue());
    ConfigINI->Write("Grad5",SpinCtrlTB2_GR5->GetValue());
    ConfigINI->Write("SlWi5",SpinCtrlTB2_SW5->GetValue());
    ConfigINI->Write("UPM6",SpinCtrlTB2_UM6->GetValue());
    ConfigINI->Write("Grad6",SpinCtrlTB2_GR6->GetValue());
    ConfigINI->Write("SlWi6",SpinCtrlTB2_SW6->GetValue());
    ConfigINI->Write("UPM7",SpinCtrlTB2_UM7->GetValue());
    ConfigINI->Write("Grad7",SpinCtrlTB2_GR7->GetValue());
    ConfigINI->Write("SlWi7",SpinCtrlTB2_SW7->GetValue());
    ConfigINI->Write("UPM8",SpinCtrlTB2_UM8->GetValue());
    ConfigINI->Write("Grad8",SpinCtrlTB2_GR8->GetValue());
    ConfigINI->Write("SlWi8",SpinCtrlTB2_SW8->GetValue());
    ConfigINI->Write("UPM9",SpinCtrlTB2_UM9->GetValue());
    ConfigINI->Write("Grad9",SpinCtrlTB2_GR9->GetValue());
    ConfigINI->Write("SlWi9",SpinCtrlTB2_SW9->GetValue());
    ConfigINI->Write("UPM10",SpinCtrlTB2_UM10->GetValue());
    ConfigINI->Write("Grad10",SpinCtrlTB2_GR10->GetValue());
    ConfigINI->Write("SlWi10",SpinCtrlTB2_SW10->GetValue());

    ConfigINI->SetPath("/Tabelle3");
    ConfigINI->Write("UPM1",SpinCtrlTB3_UM1->GetValue());
    ConfigINI->Write("Grad1",SpinCtrlTB3_GR1->GetValue());
    ConfigINI->Write("SlWi1",SpinCtrlTB3_SW1->GetValue());
    ConfigINI->Write("UPM2",SpinCtrlTB3_UM2->GetValue());
    ConfigINI->Write("Grad2",SpinCtrlTB3_GR2->GetValue());
    ConfigINI->Write("SlWi2",SpinCtrlTB3_SW2->GetValue());
    ConfigINI->Write("UPM3",SpinCtrlTB3_UM3->GetValue());
    ConfigINI->Write("Grad3",SpinCtrlTB3_GR3->GetValue());
    ConfigINI->Write("SlWi3",SpinCtrlTB3_SW3->GetValue());
    ConfigINI->Write("UPM4",SpinCtrlTB3_UM4->GetValue());
    ConfigINI->Write("Grad4",SpinCtrlTB3_GR4->GetValue());
    ConfigINI->Write("SlWi4",SpinCtrlTB3_SW4->GetValue());
    ConfigINI->Write("UPM5",SpinCtrlTB3_UM5->GetValue());
    ConfigINI->Write("Grad5",SpinCtrlTB3_GR5->GetValue());
    ConfigINI->Write("SlWi5",SpinCtrlTB3_SW5->GetValue());
    ConfigINI->Write("UPM6",SpinCtrlTB3_UM6->GetValue());
    ConfigINI->Write("Grad6",SpinCtrlTB3_GR6->GetValue());
    ConfigINI->Write("SlWi6",SpinCtrlTB3_SW6->GetValue());
    ConfigINI->Write("UPM7",SpinCtrlTB3_UM7->GetValue());
    ConfigINI->Write("Grad7",SpinCtrlTB3_GR7->GetValue());
    ConfigINI->Write("SlWi7",SpinCtrlTB3_SW7->GetValue());
    ConfigINI->Write("UPM8",SpinCtrlTB3_UM8->GetValue());
    ConfigINI->Write("Grad8",SpinCtrlTB3_GR8->GetValue());
    ConfigINI->Write("SlWi8",SpinCtrlTB3_SW8->GetValue());
    ConfigINI->Write("UPM9",SpinCtrlTB3_UM9->GetValue());
    ConfigINI->Write("Grad9",SpinCtrlTB3_GR9->GetValue());
    ConfigINI->Write("SlWi9",SpinCtrlTB3_SW9->GetValue());
    ConfigINI->Write("UPM10",SpinCtrlTB3_UM10->GetValue());
    ConfigINI->Write("Grad10",SpinCtrlTB3_GR10->GetValue());
    ConfigINI->Write("SlWi10",SpinCtrlTB3_SW10->GetValue());

    ConfigINI->SetPath("/CalcIGC");
    ConfigINI->Write("Power",Spannung->GetSelection());
    ConfigINI->Write("ResPrim",WiederstandPrim->GetValue());
    ConfigINI->Write("InductPrim",InduktPrim->GetValue());
    ConfigINI->Write("Saturation",Saturation->GetValue());
    ConfigINI->Write("RPM1",SpinCtrlRPM1->GetValue());
    ConfigINI->Write("RPM2",SpinCtrlRPM2->GetValue());
    ConfigINI->Write("RPM3",SpinCtrlRPM3->GetValue());
    ConfigINI->Write("RPM4",SpinCtrlRPM4->GetValue());
    ConfigINI->Write("RPM5",SpinCtrlRPM5->GetValue());
    ConfigINI->Write("RPM6",SpinCtrlRPM6->GetValue());
    ConfigINI->Write("RPM7",SpinCtrlRPM7->GetValue());
    ConfigINI->Write("RPM8",SpinCtrlRPM8->GetValue());
    ConfigINI->Write("RPM9",SpinCtrlRPM9->GetValue());
    ConfigINI->Write("RPM10",SpinCtrlRPM10->GetValue());

    ConfigINI->Flush();//Force save data in .ini file
    delete ConfigINI;

    resetConfigChange();
}

void USBLoader2Frame::OnRadioBoxBasisfunktionSelect(wxCommandEvent& event)
{
    wxString s;

    s << RadioBoxBasisfunktion->GetSelection() << '\n';
    writeLog(s);


}



void USBLoader2Frame::OnLadenKonfig(wxCommandEvent& event)
{

    if (isConfigChanged() == true)
    {
     if ( wxMessageBox("Änderungen nicht gespeichert.., wirklich überschreiben?", "Bitte bestätigen",
                          wxICON_QUESTION | wxYES_NO) != wxYES )
        {
            return;
        }
    }

    wxFileConfig *ConfigINI;
    wxString appPath, tmps;

    wxFileDialog openFileDialog(this, _("Konfiguration laden"), "", "", "CFG Datei (*.cfg)|*.cfg", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;     // the user changed idea...

    appPath = openFileDialog.GetPath();

    ConfigINI = new wxFileConfig(wxEmptyString, wxEmptyString, appPath);

	ConfigINI->SetPath("/Basis");
    RadioBoxBasisfunktion->SetSelection(ConfigINI->Read("Basisfunktion", 1));
    SpinCtrlStarthilfe->SetValue(ConfigINI->Read("StarthilfeZZP", "0"));
    SpinCtrlStarthilfeUMDR->SetValue(ConfigINI->Read("StarthilfeUPM", "500"));
    SpinCtrlFZZP->SetValue(ConfigINI->Read("ZZP", "-22"));
    SpinCtrlSchliessWinkel->SetValue(ConfigINI->Read("SlWiFest", "-180"));
    ChoiceTAB->SetSelection(ConfigINI->Read("ZTAB", 1));
    ChoiceLED->SetSelection(ConfigINI->Read("LED", 3));

    ConfigINI->SetPath("/Tabelle1");
    SpinCtrlTB1_UM1->SetValue(ConfigINI->Read("UPM1", "500"));
    SpinCtrlTB1_GR1->SetValue(ConfigINI->Read("Grad1", "0"));
    SpinCtrlTB1_SW1->SetValue(ConfigINI->Read("SlWi1", "-180"));
    SpinCtrlTB1_UM2->SetValue(ConfigINI->Read("UPM2", "2000"));
    SpinCtrlTB1_GR2->SetValue(ConfigINI->Read("Grad2", "-22"));
    SpinCtrlTB1_SW2->SetValue(ConfigINI->Read("SlWi2", "-180"));
    SpinCtrlTB1_UM3->SetValue(ConfigINI->Read("UPM3", "3000"));
    SpinCtrlTB1_GR3->SetValue(ConfigINI->Read("Grad3", "-22"));
    SpinCtrlTB1_SW3->SetValue(ConfigINI->Read("SlWi3", "-180"));
    SpinCtrlTB1_UM4->SetValue(ConfigINI->Read("UPM4", "3500"));
    SpinCtrlTB1_GR4->SetValue(ConfigINI->Read("Grad4", "-22"));
    SpinCtrlTB1_SW4->SetValue(ConfigINI->Read("SlWi4", "-180"));
    SpinCtrlTB1_UM5->SetValue(ConfigINI->Read("UPM5", "4000"));
    SpinCtrlTB1_GR5->SetValue(ConfigINI->Read("Grad5", "-22"));
    SpinCtrlTB1_SW5->SetValue(ConfigINI->Read("SlWi5", "-180"));
    SpinCtrlTB1_UM6->SetValue(ConfigINI->Read("UPM6", "4500"));
    SpinCtrlTB1_GR6->SetValue(ConfigINI->Read("Grad6", "-22"));
    SpinCtrlTB1_SW6->SetValue(ConfigINI->Read("SlWi6", "-180"));
    SpinCtrlTB1_UM7->SetValue(ConfigINI->Read("UPM7", "5000"));
    SpinCtrlTB1_GR7->SetValue(ConfigINI->Read("Grad7", "-22"));
    SpinCtrlTB1_SW7->SetValue(ConfigINI->Read("SlWi7", "-180"));
    SpinCtrlTB1_UM8->SetValue(ConfigINI->Read("UPM8", "5500"));
    SpinCtrlTB1_GR8->SetValue(ConfigINI->Read("Grad8", "-22"));
    SpinCtrlTB1_SW8->SetValue(ConfigINI->Read("SlWi8", "-180"));
    SpinCtrlTB1_UM9->SetValue(ConfigINI->Read("UPM9", "6500"));
    SpinCtrlTB1_GR9->SetValue(ConfigINI->Read("Grad9", "-22"));
    SpinCtrlTB1_SW9->SetValue(ConfigINI->Read("SlWi9", "-180"));
    SpinCtrlTB1_UM10->SetValue(ConfigINI->Read("UPM10", "7000"));
    SpinCtrlTB1_GR10->SetValue(ConfigINI->Read("Grad10", "-22"));
    SpinCtrlTB1_SW10->SetValue(ConfigINI->Read("SlWi10", "-180"));

    ConfigINI->SetPath("/Tabelle2");
    SpinCtrlTB2_UM1->SetValue(ConfigINI->Read("UPM1", "0"));
    SpinCtrlTB2_GR1->SetValue(ConfigINI->Read("Grad1", "0"));
    SpinCtrlTB2_SW1->SetValue(ConfigINI->Read("SlWi1", "-180"));
    SpinCtrlTB2_UM2->SetValue(ConfigINI->Read("UPM2", "0"));
    SpinCtrlTB2_GR2->SetValue(ConfigINI->Read("Grad2", "0"));
    SpinCtrlTB2_SW2->SetValue(ConfigINI->Read("SlWi2", "-180"));
    SpinCtrlTB2_UM3->SetValue(ConfigINI->Read("UPM3", "0"));
    SpinCtrlTB2_GR3->SetValue(ConfigINI->Read("Grad3", "0"));
    SpinCtrlTB2_SW3->SetValue(ConfigINI->Read("SlWi3", "-180"));
    SpinCtrlTB2_UM4->SetValue(ConfigINI->Read("UPM4", "0"));
    SpinCtrlTB2_GR4->SetValue(ConfigINI->Read("Grad4", "0"));
    SpinCtrlTB2_SW4->SetValue(ConfigINI->Read("SlWi4", "-180"));
    SpinCtrlTB2_UM5->SetValue(ConfigINI->Read("UPM5", "0"));
    SpinCtrlTB2_GR5->SetValue(ConfigINI->Read("Grad5", "0"));
    SpinCtrlTB2_SW5->SetValue(ConfigINI->Read("SlWi5", "-180"));
    SpinCtrlTB2_UM6->SetValue(ConfigINI->Read("UPM6", "0"));
    SpinCtrlTB2_GR6->SetValue(ConfigINI->Read("Grad6", "0"));
    SpinCtrlTB2_SW6->SetValue(ConfigINI->Read("SlWi6", "-180"));
    SpinCtrlTB2_UM7->SetValue(ConfigINI->Read("UPM7", "0"));
    SpinCtrlTB2_GR7->SetValue(ConfigINI->Read("Grad7", "0"));
    SpinCtrlTB2_SW7->SetValue(ConfigINI->Read("SlWi7", "-180"));
    SpinCtrlTB2_UM8->SetValue(ConfigINI->Read("UPM8", "0"));
    SpinCtrlTB2_GR8->SetValue(ConfigINI->Read("Grad8", "0"));
    SpinCtrlTB2_SW8->SetValue(ConfigINI->Read("SlWi8", "-180"));
    SpinCtrlTB2_UM9->SetValue(ConfigINI->Read("UPM9", "0"));
    SpinCtrlTB2_GR9->SetValue(ConfigINI->Read("Grad9", "0"));
    SpinCtrlTB2_SW9->SetValue(ConfigINI->Read("SlWi9", "-180"));
    SpinCtrlTB2_UM10->SetValue(ConfigINI->Read("UPM10", "0"));
    SpinCtrlTB2_GR10->SetValue(ConfigINI->Read("Grad10", "0"));
    SpinCtrlTB2_SW10->SetValue(ConfigINI->Read("SlWi10", "-180"));

    ConfigINI->SetPath("/Tabelle3");
    SpinCtrlTB3_UM1->SetValue(ConfigINI->Read("UPM1", "0"));
    SpinCtrlTB3_GR1->SetValue(ConfigINI->Read("Grad1", "0"));
    SpinCtrlTB3_SW1->SetValue(ConfigINI->Read("SlWi1", "-180"));
    SpinCtrlTB3_UM2->SetValue(ConfigINI->Read("UPM2", "0"));
    SpinCtrlTB3_GR2->SetValue(ConfigINI->Read("Grad2", "0"));
    SpinCtrlTB3_SW2->SetValue(ConfigINI->Read("SlWi2", "-180"));
    SpinCtrlTB3_UM3->SetValue(ConfigINI->Read("UPM3", "0"));
    SpinCtrlTB3_GR3->SetValue(ConfigINI->Read("Grad3", "0"));
    SpinCtrlTB3_SW3->SetValue(ConfigINI->Read("SlWi3", "-180"));
    SpinCtrlTB3_UM4->SetValue(ConfigINI->Read("UPM4", "0"));
    SpinCtrlTB3_GR4->SetValue(ConfigINI->Read("Grad4", "0"));
    SpinCtrlTB3_SW4->SetValue(ConfigINI->Read("SlWi4", "-180"));
    SpinCtrlTB3_UM5->SetValue(ConfigINI->Read("UPM5", "0"));
    SpinCtrlTB3_GR5->SetValue(ConfigINI->Read("Grad5", "0"));
    SpinCtrlTB3_SW5->SetValue(ConfigINI->Read("SlWi5", "-180"));
    SpinCtrlTB3_UM6->SetValue(ConfigINI->Read("UPM6", "0"));
    SpinCtrlTB3_GR6->SetValue(ConfigINI->Read("Grad6", "0"));
    SpinCtrlTB3_SW6->SetValue(ConfigINI->Read("SlWi6", "-180"));
    SpinCtrlTB3_UM7->SetValue(ConfigINI->Read("UPM7", "0"));
    SpinCtrlTB3_GR7->SetValue(ConfigINI->Read("Grad7", "0"));
    SpinCtrlTB3_SW7->SetValue(ConfigINI->Read("SlWi7", "-180"));
    SpinCtrlTB3_UM8->SetValue(ConfigINI->Read("UPM8", "0"));
    SpinCtrlTB3_GR8->SetValue(ConfigINI->Read("Grad8", "0"));
    SpinCtrlTB3_SW8->SetValue(ConfigINI->Read("SlWi8", "-180"));
    SpinCtrlTB3_UM9->SetValue(ConfigINI->Read("UPM9", "0"));
    SpinCtrlTB3_GR9->SetValue(ConfigINI->Read("Grad9", "0"));
    SpinCtrlTB3_SW9->SetValue(ConfigINI->Read("SlWi9", "-180"));
    SpinCtrlTB3_UM10->SetValue(ConfigINI->Read("UPM10", "0"));
    SpinCtrlTB3_GR10->SetValue(ConfigINI->Read("Grad10", "0"));
    SpinCtrlTB3_SW10->SetValue(ConfigINI->Read("SlWi10", "-180"));

    ConfigINI->SetPath("/CalcIGC");
    Spannung->SetSelection(ConfigINI->Read("Power", 1));
    WiederstandPrim->SetValue(ConfigINI->Read("ResPrim", "5"));
    InduktPrim->SetValue(ConfigINI->Read("InductPrim", "10"));
    Saturation->SetValue(ConfigINI->Read("Saturation", "3"));
    SpinCtrlRPM1->SetValue(ConfigINI->Read("RPM1", "2000"));
    SpinCtrlRPM2->SetValue(ConfigINI->Read("RPM2", "3000"));
    SpinCtrlRPM3->SetValue(ConfigINI->Read("RPM3", "3500"));
    SpinCtrlRPM4->SetValue(ConfigINI->Read("RPM4", "4000"));
    SpinCtrlRPM5->SetValue(ConfigINI->Read("RPM5", "4500"));
    SpinCtrlRPM6->SetValue(ConfigINI->Read("RPM6", "5000"));
    SpinCtrlRPM7->SetValue(ConfigINI->Read("RPM7", "5500"));
    SpinCtrlRPM8->SetValue(ConfigINI->Read("RPM8", "6000"));
    SpinCtrlRPM9->SetValue(ConfigINI->Read("RPM9", "6500"));
    SpinCtrlRPM10->SetValue(ConfigINI->Read("RPM10", "7000"));

    resetConfigChange();
}

void USBLoader2Frame::OnDataChange(wxCommandEvent& event)
{
    ConfigChange();
}

void USBLoader2Frame::OnSpinCtrlChange(wxSpinEvent& event)
{
    ConfigChange();
}

void USBLoader2Frame::OnClose(wxCloseEvent& event)
{

    if (isConfigChanged() == true)
    {
     if ( wxMessageBox("Änderungen nicht gespeichert.., wirklich schließen?",
                          "Bitte bestätigen",
                          wxICON_QUESTION | wxYES_NO) != wxYES )
        {
            event.Veto();
            return;
        }
    }
    event.Skip();
    Destroy();
}

void USBLoader2Frame::OnConfigUpload(wxCommandEvent& event)
{
    digiSpark->setIgnMode(RadioBoxBasisfunktion->GetSelection());      // Mode M0 - 3
    writeLog(digiSpark->getLog());
    digiSpark->setStartHelpZZP(SpinCtrlStarthilfe->GetValue());     // Starhilfe Grad
    writeLog(digiSpark->getLog());
    digiSpark->setStartHelpRPM(SpinCtrlStarthilfeUMDR->GetValue()); // Starhilfe RPM
    writeLog(digiSpark->getLog());
    digiSpark->setFixZZP(SpinCtrlFZZP->GetValue());                 // fester ZZP von OT
    writeLog(digiSpark->getLog());
    digiSpark->setDwellAngle(SpinCtrlSchliessWinkel->GetValue());   // Schliesswinkel
    writeLog(digiSpark->getLog());
    digiSpark->setIPTable(ChoiceTAB->GetSelection());               // Zündtabelle
    writeLog(digiSpark->getLog());
    digiSpark->setLED(ChoiceLED->GetSelection());                   //LED
    writeLog(digiSpark->getLog());
}

void USBLoader2Frame::OnConfigDownload(wxCommandEvent& event)
{
    int8_t  valByte = 0;
    uint8_t uvalByte = 0;
    int16_t valWord = 0;
    uint16_t uvalWord = 0;
    ///uint32_t uvalDWord = 0;

    if (digiSpark->getIgnMode(uvalByte)) RadioBoxBasisfunktion->SetSelection(uvalByte);
    writeLog(digiSpark->getLog());
    if (digiSpark->getStartHelpZZP(valByte)) SpinCtrlStarthilfe->SetValue(valByte);
    writeLog(digiSpark->getLog());
    if (digiSpark->getStartHelpRPM(uvalWord)) SpinCtrlStarthilfeUMDR->SetValue(uvalWord);
    writeLog(digiSpark->getLog());
    if (digiSpark->getFixZZP(valByte)) SpinCtrlFZZP->SetValue(valByte);
    writeLog(digiSpark->getLog());
    if (digiSpark->getDwellAngle(valWord)) SpinCtrlSchliessWinkel->SetValue(valWord);
    writeLog(digiSpark->getLog());
    if (digiSpark->getIPTable(uvalByte)) ChoiceTAB->SetSelection(uvalByte);
    writeLog(digiSpark->getLog());
    if (digiSpark->getLED(uvalByte)) ChoiceLED->SetSelection(uvalByte);
    writeLog(digiSpark->getLog());
}

void USBLoader2Frame::CheckLOGMode(void)
{
    uint8_t mode = 0;
    if (connected == true)
    {
        if (digiSpark->getLOGMode(mode))
        {
            if (mode == VAL_LOG_ON)
                Komm_LogMode->Check(true);
            else
                if (mode == VAL_LOG_OFF)
                    Komm_LogMode->Check(false);
                else
                    Komm_LogMode->Check(false);
        }
    }
    else
    {
        Komm_LogMode->Check(false);
    }
}


void USBLoader2Frame::OnLogModeSet(wxCommandEvent& event)
{
    if (Komm_LogMode->IsChecked())
    {
        if (connected == true)
            digiSpark->setLOGMode(VAL_LOG_ON);
    }
    else
    {
        if (connected == true)
            digiSpark->setLOGMode(VAL_LOG_OFF);
    }
}


void USBLoader2Frame::OnButtonZPBerechnenClick(wxCommandEvent& event)
{
    double idp, wip, szp, tau, engi, volt, strom, watt, msu, gradu, maxdw, prowatt, proz;
    const double CALC6F = 60000.0F;
    unsigned int rpm;
    wxString rstr;

    idp = InduktPrim->GetValue();
    wip = WiederstandPrim->GetValue();
    szp = Saturation->GetValue();
    maxdw = SpinCtrlMaxSchlWin->GetValue();
    tau = idp * szp / wip;
    switch(Spannung->GetSelection())
    {
        case 0: volt = 6.9F; break;
        case 1: volt = 13.8F; break;
        default: volt = 0.0F;
    };
    rstr = wxString::FromDouble(tau, 1);
    TextCtrlSatTime->SetValue(rstr);

    strom = volt / wip;
    rstr = wxString::FromDouble(strom, 1);
    TextCtrlStrom->SetValue(rstr);
    watt = volt * strom;
    rstr = wxString::FromDouble(watt, 1);
    TextCtrlWatt->SetValue(rstr);

    engi = 0.5F * strom * strom * idp;
    rstr = wxString::FromDouble(engi, 1);
    TextCtrlZPEnergie->SetValue(rstr);

    rpm = SpinCtrlRPM1->GetValue();
    msu = CALC6F / (double) rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU1->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU1->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD1->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz1->SetValue(rstr);

    rpm = SpinCtrlRPM2->GetValue();
    msu = CALC6F / rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU2->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU2->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD2->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz2->SetValue(rstr);

    rpm = SpinCtrlRPM3->GetValue();
    msu = CALC6F / rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU3->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU3->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD3->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz3->SetValue(rstr);

    rpm = SpinCtrlRPM4->GetValue();
    msu = CALC6F / rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU4->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU4->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD4->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz4->SetValue(rstr);

    rpm = SpinCtrlRPM5->GetValue();
    msu = CALC6F / rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU5->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU5->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD5->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz5->SetValue(rstr);

    rpm = SpinCtrlRPM6->GetValue();
    msu = CALC6F / rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU6->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU6->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD6->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz6->SetValue(rstr);

    rpm = SpinCtrlRPM7->GetValue();
    msu = CALC6F / rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU7->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU7->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD7->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz7->SetValue(rstr);

    rpm = SpinCtrlRPM8->GetValue();
    msu = CALC6F / rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU8->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU8->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD8->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz8->SetValue(rstr);

    rpm = SpinCtrlRPM9->GetValue();
    msu = CALC6F / rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU9->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU9->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD9->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz9->SetValue(rstr);

    rpm = SpinCtrlRPM10->GetValue();
    msu = CALC6F / rpm;
    gradu = tau * 360 / msu;
    rstr = wxString::FromDouble(msu, 0);
    TextCtrlMSU10->SetValue(rstr);
    rstr = wxString::FromDouble(gradu, 0);
    TextCtrlGRADU10->SetValue(rstr);
    if ( gradu <= maxdw)
         prowatt =   engi;
    else
         prowatt = maxdw * engi / gradu;
    rstr = wxString::FromDouble(prowatt, 1);
    TextCtrlLD10->SetValue(rstr);
    proz = prowatt / engi * 100;
    rstr = wxString::FromDouble(proz, 1);
    TextCtrlProz10->SetValue(rstr);
}

void USBLoader2Frame::OnMenuItemLogLeerenSelected(wxCommandEvent& event)
{
    TextCtrlLOG->Clear();
}

void USBLoader2Frame::OnKomm_EEpromSaveSelected(wxCommandEvent& event)
{
    OnConfigUpload(event);
    digiSpark->write_EEpromParameter();                                     // Save paramter in the eeprom
}
