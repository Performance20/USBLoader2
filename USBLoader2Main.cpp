/***************************************************************
 * Name:      USBLoader2Main.cpp
 * Purpose:   Code for Application Frame
 * Author:    Helge ()
 * Created:   2020-09-03
 * Copyright: Helge ()
 * License:
 **************************************************************/

#include "USBLoader2Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(USBLoader2Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

#include "About.h"



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
const long USBLoader2Frame::ID_RADIOBOX1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT35 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT36 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT37 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT62 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLStarthilfeUMDR = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT63 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT31 = wxNewId();
const long USBLoader2Frame::ID_CHOICE1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT32 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT64 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT65 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT33 = wxNewId();
const long USBLoader2Frame::ID_CHOICE2 = wxNewId();
const long USBLoader2Frame::ID_PANELBasis = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT11 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT12 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR5 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT13 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT14 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT15 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR8 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT16 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR9 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT17 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_UM10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB1_GR10 = wxNewId();
const long USBLoader2Frame::ID_PANELTB1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT18 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT19 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT20 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT21 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT22 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT23 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT24 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT25 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR5 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT26 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT27 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT28 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR8 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT29 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR9 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT30 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_UM10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB2_GR10 = wxNewId();
const long USBLoader2Frame::ID_PANELTB2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT49 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT50 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT51 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT52 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT53 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT54 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT55 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM4 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT56 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR5 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT57 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM6 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT58 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT59 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR8 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT60 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR9 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT61 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_UM10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRLTB3_GR10 = wxNewId();
const long USBLoader2Frame::ID_PANELTB3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT46 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT45 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT44 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT38 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLRPM = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT39 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT42 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRL1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT43 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT40 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLTPR = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT41 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT47 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRL2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT48 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT3 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLEchtModus = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT5 = wxNewId();
const long USBLoader2Frame::ID_PANELEchtWerte = wxNewId();
const long USBLoader2Frame::ID_NOTEBOOK1 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRLLOG = wxNewId();
const long USBLoader2Frame::ID_PANEL1 = wxNewId();
const long USBLoader2Frame::idMenuSpeichern = wxNewId();
const long USBLoader2Frame::idMenuQuit = wxNewId();
const long USBLoader2Frame::idMenuVerbinden = wxNewId();
const long USBLoader2Frame::idMenuTrennen = wxNewId();
const long USBLoader2Frame::idMenuAbout = wxNewId();
const long USBLoader2Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(USBLoader2Frame,wxFrame)
    //(*EventTable(USBLoader2Frame)
    //*)
END_EVENT_TABLE()

USBLoader2Frame::USBLoader2Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(USBLoader2Frame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxGridSizer* GridSizer1;
    wxGridSizer* GridSizer2;
    wxGridSizer* GridSizer3;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenu* Menu3;
    wxMenuBar* HauptMenuBar;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("Zuendmodul Konfigurator "), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(580,700));
    SetMinSize(wxSize(580,600));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(184,200), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH|wxBORDER_RAISED, _T("ID_NOTEBOOK1"));
    Notebook1->SetFocus();
    PanelBasis = new wxPanel(Notebook1, ID_PANELBasis, wxPoint(131,153), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELBasis"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticText34 = new wxStaticText(PanelBasis, ID_STATICTEXT34, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT34"));
    BoxSizer2->Add(StaticText34, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    wxString __wxRadioBoxChoices_1[4] =
    {
    	_("Manuell via Geber (M1)"),
    	_("Fester Zuendzeitpunkt von OT (M2)"),
    	_("Fester ZP von OT mit Starthilfe (M3)"),
    	_("Dynamisch nach Tabelle (M4)")
    };
    RadioBox1 = new wxRadioBox(PanelBasis, ID_RADIOBOX1, _("Basisfunktion"), wxDefaultPosition, wxDefaultSize, 4, __wxRadioBoxChoices_1, 2, 0, wxDefaultValidator, _T("ID_RADIOBOX1"));
    RadioBox1->SetSelection(1);
    BoxSizer2->Add(RadioBox1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText35 = new wxStaticText(PanelBasis, ID_STATICTEXT35, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
    BoxSizer2->Add(StaticText35, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1 = new wxFlexGridSizer(6, 3, 10, 0);
    StaticText36 = new wxStaticText(PanelBasis, ID_STATICTEXT36, _("Starthilfe Zuendzeitpunkt:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT36"));
    FlexGridSizer1->Add(StaticText36, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl1 = new wxSpinCtrl(PanelBasis, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRL1"));
    SpinCtrl1->SetValue(_T("0"));
    FlexGridSizer1->Add(SpinCtrl1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText37 = new wxStaticText(PanelBasis, ID_STATICTEXT37, _("Grad (Wert 0 = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
    FlexGridSizer1->Add(StaticText37, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText62 = new wxStaticText(PanelBasis, ID_STATICTEXT62, _("Starthilfe bis:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT62"));
    FlexGridSizer1->Add(StaticText62, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlStarthilfeUMDR = new wxSpinCtrl(PanelBasis, ID_SPINCTRLStarthilfeUMDR, _T("500"), wxDefaultPosition, wxSize(120,30), 0, 0, 2000, 500, _T("ID_SPINCTRLStarthilfeUMDR"));
    SpinCtrlStarthilfeUMDR->SetValue(_T("500"));
    FlexGridSizer1->Add(SpinCtrlStarthilfeUMDR, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText63 = new wxStaticText(PanelBasis, ID_STATICTEXT63, _("Umdrehungen/Min."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT63"));
    FlexGridSizer1->Add(StaticText63, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(PanelBasis, ID_STATICTEXT2, _("Fester Zuendzeitpunkt von OT:"), wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl2 = new wxSpinCtrl(PanelBasis, ID_SPINCTRL2, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL2"));
    SpinCtrl2->SetValue(_T("-22"));
    SpinCtrl2->SetToolTip(_("Grad von OT, bei dem gezündet wird = -22 Grad wäre 22 Grad vot OT"));
    FlexGridSizer1->Add(SpinCtrl2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(PanelBasis, ID_STATICTEXT4, _("Grad (Wert 0 = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText31 = new wxStaticText(PanelBasis, ID_STATICTEXT31, _("Aktive Zündtabelle:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
    FlexGridSizer1->Add(StaticText31, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(PanelBasis, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetSelection( Choice1->Append(_("Tabelle1")) );
    Choice1->Append(_("Tabelle2"));
    Choice1->Append(_("Tabelle3"));
    FlexGridSizer1->Add(Choice1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText32 = new wxStaticText(PanelBasis, ID_STATICTEXT32, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT32"));
    FlexGridSizer1->Add(StaticText32, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText64 = new wxStaticText(PanelBasis, ID_STATICTEXT64, _("Spule laden:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT64"));
    FlexGridSizer1->Add(StaticText64, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl4 = new wxSpinCtrl(PanelBasis, ID_SPINCTRL4, _T("270"), wxDefaultPosition, wxSize(120,30), 0, 90, 320, 270, _T("ID_SPINCTRL4"));
    SpinCtrl4->SetValue(_T("270"));
    FlexGridSizer1->Add(SpinCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText65 = new wxStaticText(PanelBasis, ID_STATICTEXT65, _("Grad"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT65"));
    FlexGridSizer1->Add(StaticText65, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText33 = new wxStaticText(PanelBasis, ID_STATICTEXT33, _("LED:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
    FlexGridSizer1->Add(StaticText33, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    Choice2 = new wxChoice(PanelBasis, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    Choice2->Append(_("Aus"));
    Choice2->SetSelection( Choice2->Append(_("Eingangssignal")) );
    Choice2->Append(_("Diagnose"));
    FlexGridSizer1->Add(Choice2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(FlexGridSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PanelBasis->SetSizer(BoxSizer2);
    BoxSizer2->Fit(PanelBasis);
    BoxSizer2->SetSizeHints(PanelBasis);
    PanelTB1 = new wxPanel(Notebook1, ID_PANELTB1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELTB1"));
    GridSizer1 = new wxGridSizer(11, 3, 0, 0);
    StaticText1 = new wxStaticText(PanelTB1, ID_STATICTEXT1, _("Position"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(PanelTB1, ID_STATICTEXT6, _("Umdrehung/Minute"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    GridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(PanelTB1, ID_STATICTEXT7, _("Grad (Wert 0 = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(PanelTB1, ID_STATICTEXT8, _("1."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    GridSizer1->Add(StaticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM1 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM1, _T("500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 500, _T("ID_SPINCTRLTB1_UM1"));
    SpinCtrlTB1_UM1->SetValue(_T("500"));
    GridSizer1->Add(SpinCtrlTB1_UM1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR1 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR1, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB1_GR1"));
    SpinCtrlTB1_GR1->SetValue(_T("0"));
    GridSizer1->Add(SpinCtrlTB1_GR1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(PanelTB1, ID_STATICTEXT9, _("2."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    GridSizer1->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlSpinCtrlTB1_UM2 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM2, _T("2000"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 2000, _T("ID_SPINCTRLTB1_UM2"));
    SpinCtrlSpinCtrlTB1_UM2->SetValue(_T("2000"));
    GridSizer1->Add(SpinCtrlSpinCtrlTB1_UM2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR2 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR2, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR2"));
    SpinCtrlTB1_GR2->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(PanelTB1, ID_STATICTEXT10, _("3."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    GridSizer1->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM3 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM3, _T("3000"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 3000, _T("ID_SPINCTRLTB1_UM3"));
    SpinCtrlTB1_UM3->SetValue(_T("3000"));
    GridSizer1->Add(SpinCtrlTB1_UM3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR3 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR3, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR3"));
    SpinCtrlTB1_GR3->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(PanelTB1, ID_STATICTEXT11, _("4."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    GridSizer1->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM4 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM4, _T("3500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 3500, _T("ID_SPINCTRLTB1_UM4"));
    SpinCtrlTB1_UM4->SetValue(_T("3500"));
    GridSizer1->Add(SpinCtrlTB1_UM4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR4 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR4, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR4"));
    SpinCtrlTB1_GR4->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(PanelTB1, ID_STATICTEXT12, _("5."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    GridSizer1->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM5 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM5, _T("4500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 4500, _T("ID_SPINCTRLTB1_UM5"));
    SpinCtrlTB1_UM5->SetValue(_T("4500"));
    GridSizer1->Add(SpinCtrlTB1_UM5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR5 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR5, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR5"));
    SpinCtrlTB1_GR5->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(PanelTB1, ID_STATICTEXT13, _("6."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    GridSizer1->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM6 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM6, _T("5000"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 5000, _T("ID_SPINCTRLTB1_UM6"));
    SpinCtrlTB1_UM6->SetValue(_T("5000"));
    GridSizer1->Add(SpinCtrlTB1_UM6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR6 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR6, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR6"));
    SpinCtrlTB1_GR6->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText14 = new wxStaticText(PanelTB1, ID_STATICTEXT14, _("7."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    GridSizer1->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM7 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM7, _T("5500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 5500, _T("ID_SPINCTRLTB1_UM7"));
    SpinCtrlTB1_UM7->SetValue(_T("5500"));
    GridSizer1->Add(SpinCtrlTB1_UM7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR7 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR7, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR7"));
    SpinCtrlTB1_GR7->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(PanelTB1, ID_STATICTEXT15, _("8."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    GridSizer1->Add(StaticText15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM8 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM8, _T("6000"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 6000, _T("ID_SPINCTRLTB1_UM8"));
    SpinCtrlTB1_UM8->SetValue(_T("6000"));
    GridSizer1->Add(SpinCtrlTB1_UM8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR8 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR8, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR8"));
    SpinCtrlTB1_GR8->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(PanelTB1, ID_STATICTEXT16, _("9."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    GridSizer1->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM9 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM9, _T("6500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 6500, _T("ID_SPINCTRLTB1_UM9"));
    SpinCtrlTB1_UM9->SetValue(_T("6500"));
    GridSizer1->Add(SpinCtrlTB1_UM9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR9 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR9, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR9"));
    SpinCtrlTB1_GR9->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(PanelTB1, ID_STATICTEXT17, _("10."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    GridSizer1->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_UM10 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_UM10, _T("7000"), wxDefaultPosition, wxSize(120,30), wxSP_VERTICAL, 0, 10000, 7000, _T("ID_SPINCTRLTB1_UM10"));
    SpinCtrlTB1_UM10->SetValue(_T("7000"));
    GridSizer1->Add(SpinCtrlTB1_UM10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_GR10 = new wxSpinCtrl(PanelTB1, ID_SPINCTRLTB1_GR10, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRLTB1_GR10"));
    SpinCtrlTB1_GR10->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrlTB1_GR10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PanelTB1->SetSizer(GridSizer1);
    GridSizer1->Fit(PanelTB1);
    GridSizer1->SetSizeHints(PanelTB1);
    PanelTB2 = new wxPanel(Notebook1, ID_PANELTB2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELTB2"));
    GridSizer2 = new wxGridSizer(11, 3, 0, 0);
    StaticText18 = new wxStaticText(PanelTB2, ID_STATICTEXT18, _("Pos."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
    GridSizer2->Add(StaticText18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText19 = new wxStaticText(PanelTB2, ID_STATICTEXT19, _("Umdrehung/Minute"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
    GridSizer2->Add(StaticText19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText20 = new wxStaticText(PanelTB2, ID_STATICTEXT20, _("Grad (Wert 0 = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
    GridSizer2->Add(StaticText20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText21 = new wxStaticText(PanelTB2, ID_STATICTEXT21, _("1."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
    GridSizer2->Add(StaticText21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM1 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM1, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM1"));
    SpinCtrlTB2_UM1->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR1 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR1, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 22, 0, _T("ID_SPINCTRLTB2_GR1"));
    SpinCtrlTB2_GR1->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText22 = new wxStaticText(PanelTB2, ID_STATICTEXT22, _("2."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
    GridSizer2->Add(StaticText22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM2 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM2, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM2"));
    SpinCtrlTB2_UM2->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR2 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR2, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR2"));
    SpinCtrlTB2_GR2->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText23 = new wxStaticText(PanelTB2, ID_STATICTEXT23, _("3."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
    GridSizer2->Add(StaticText23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM3 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM3, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM3"));
    SpinCtrlTB2_UM3->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR3 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR3, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR3"));
    SpinCtrlTB2_GR3->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText24 = new wxStaticText(PanelTB2, ID_STATICTEXT24, _("4."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
    GridSizer2->Add(StaticText24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM4 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM4, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM4"));
    SpinCtrlTB2_UM4->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR4 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR4, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR4"));
    SpinCtrlTB2_GR4->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText25 = new wxStaticText(PanelTB2, ID_STATICTEXT25, _("5."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
    GridSizer2->Add(StaticText25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM5 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM5, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM5"));
    SpinCtrlTB2_UM5->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR5 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR5, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR5"));
    SpinCtrlTB2_GR5->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText26 = new wxStaticText(PanelTB2, ID_STATICTEXT26, _("6."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
    GridSizer2->Add(StaticText26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM6 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM6, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM6"));
    SpinCtrlTB2_UM6->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR6 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR6, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR6"));
    SpinCtrlTB2_GR6->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText27 = new wxStaticText(PanelTB2, ID_STATICTEXT27, _("7."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT27"));
    GridSizer2->Add(StaticText27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM7 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM7, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM7"));
    SpinCtrlTB2_UM7->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR7 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR7, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR7"));
    SpinCtrlTB2_GR7->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText28 = new wxStaticText(PanelTB2, ID_STATICTEXT28, _("8."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT28"));
    GridSizer2->Add(StaticText28, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM8 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM8, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM8"));
    SpinCtrlTB2_UM8->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR8 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR8, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR8"));
    SpinCtrlTB2_GR8->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText29 = new wxStaticText(PanelTB2, ID_STATICTEXT29, _("9."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT29"));
    GridSizer2->Add(StaticText29, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM9 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM9, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM9"));
    SpinCtrlTB2_UM9->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR9 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR9, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR9"));
    SpinCtrlTB2_GR9->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText30 = new wxStaticText(PanelTB2, ID_STATICTEXT30, _("10"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
    GridSizer2->Add(StaticText30, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_UM10 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_UM10, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB2_UM10"));
    SpinCtrlTB2_UM10->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_UM10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB2_GR10 = new wxSpinCtrl(PanelTB2, ID_SPINCTRLTB2_GR10, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB2_GR10"));
    SpinCtrlTB2_GR10->SetValue(_T("0"));
    GridSizer2->Add(SpinCtrlTB2_GR10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PanelTB2->SetSizer(GridSizer2);
    GridSizer2->Fit(PanelTB2);
    GridSizer2->SetSizeHints(PanelTB2);
    PanelTB3 = new wxPanel(Notebook1, ID_PANELTB3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELTB3"));
    GridSizer3 = new wxGridSizer(11, 3, 0, 0);
    StaticText49 = new wxStaticText(PanelTB3, ID_STATICTEXT49, _("Position"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT49"));
    GridSizer3->Add(StaticText49, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText50 = new wxStaticText(PanelTB3, ID_STATICTEXT50, _("Umdrehung/Minute"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT50"));
    GridSizer3->Add(StaticText50, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText51 = new wxStaticText(PanelTB3, ID_STATICTEXT51, _("Grad (Wert 0 = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT51"));
    GridSizer3->Add(StaticText51, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText52 = new wxStaticText(PanelTB3, ID_STATICTEXT52, _("1."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT52"));
    GridSizer3->Add(StaticText52, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM1 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM1, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM1"));
    SpinCtrlTB3_UM1->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR1 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR"));
    SpinCtrlTB3_GR1->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText53 = new wxStaticText(PanelTB3, ID_STATICTEXT53, _("2."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT53"));
    GridSizer3->Add(StaticText53, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM2 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM2, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM2"));
    SpinCtrlTB3_UM2->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR2 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR2, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR2"));
    SpinCtrlTB3_GR2->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText54 = new wxStaticText(PanelTB3, ID_STATICTEXT54, _("3."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT54"));
    GridSizer3->Add(StaticText54, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM3 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM3, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM3"));
    SpinCtrlTB3_UM3->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR3 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR3, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR3"));
    SpinCtrlTB3_GR3->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText55 = new wxStaticText(PanelTB3, ID_STATICTEXT55, _("4."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT55"));
    GridSizer3->Add(StaticText55, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM4 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM4, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM4"));
    SpinCtrlTB3_UM4->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR4 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR4, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR4"));
    SpinCtrlTB3_GR4->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText56 = new wxStaticText(PanelTB3, ID_STATICTEXT56, _("5."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT56"));
    GridSizer3->Add(StaticText56, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM5 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM5, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM5"));
    SpinCtrlTB3_UM5->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR5 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR5, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR5"));
    SpinCtrlTB3_GR5->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText57 = new wxStaticText(PanelTB3, ID_STATICTEXT57, _("6."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT57"));
    GridSizer3->Add(StaticText57, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM6 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM6, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM6"));
    SpinCtrlTB3_UM6->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR6 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR6, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR6"));
    SpinCtrlTB3_GR6->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText58 = new wxStaticText(PanelTB3, ID_STATICTEXT58, _("7."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT58"));
    GridSizer3->Add(StaticText58, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM7 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM7, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM7"));
    SpinCtrlTB3_UM7->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR7 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR7, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR7"));
    SpinCtrlTB3_GR7->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText59 = new wxStaticText(PanelTB3, ID_STATICTEXT59, _("8."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT59"));
    GridSizer3->Add(StaticText59, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM8 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM8, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM8"));
    SpinCtrlTB3_UM8->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR8 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR8, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR8"));
    SpinCtrlTB3_GR8->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText60 = new wxStaticText(PanelTB3, ID_STATICTEXT60, _("9."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT60"));
    GridSizer3->Add(StaticText60, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM9 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM9, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM9"));
    SpinCtrlTB3_UM9->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR9 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR9, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR9"));
    SpinCtrlTB3_GR9->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText61 = new wxStaticText(PanelTB3, ID_STATICTEXT61, _("10."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT61"));
    GridSizer3->Add(StaticText61, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_UM10 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_UM10, _T("0"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 0, _T("ID_SPINCTRLTB3_UM10"));
    SpinCtrlTB3_UM10->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_UM10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB3_GR10 = new wxSpinCtrl(PanelTB3, ID_SPINCTRLTB3_GR10, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRLTB3_GR10"));
    SpinCtrlTB3_GR10->SetValue(_T("0"));
    GridSizer3->Add(SpinCtrlTB3_GR10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    PanelTB3->SetSizer(GridSizer3);
    GridSizer3->Fit(PanelTB3);
    GridSizer3->SetSizeHints(PanelTB3);
    EchtWerte = new wxPanel(Notebook1, ID_PANELEchtWerte, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANELEchtWerte"));
    FlexGridSizer2 = new wxFlexGridSizer(6, 3, 10, 0);
    StaticText46 = new wxStaticText(EchtWerte, ID_STATICTEXT46, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT46"));
    FlexGridSizer2->Add(StaticText46, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText45 = new wxStaticText(EchtWerte, ID_STATICTEXT45, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT45"));
    FlexGridSizer2->Add(StaticText45, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText44 = new wxStaticText(EchtWerte, ID_STATICTEXT44, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT44"));
    FlexGridSizer2->Add(StaticText44, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText38 = new wxStaticText(EchtWerte, ID_STATICTEXT38, _("Umdrehungen/Minute:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT38"));
    FlexGridSizer2->Add(StaticText38, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlRPM = new wxTextCtrl(EchtWerte, ID_TEXTCTRLRPM, _("00000"), wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLRPM"));
    TextCtrlRPM->SetMaxLength(5);
    FlexGridSizer2->Add(TextCtrlRPM, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText39 = new wxStaticText(EchtWerte, ID_STATICTEXT39, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT39"));
    FlexGridSizer2->Add(StaticText39, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText42 = new wxStaticText(EchtWerte, ID_STATICTEXT42, _("Umdrehungen/Sekunde:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT42"));
    FlexGridSizer2->Add(StaticText42, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(EchtWerte, ID_TEXTCTRL1, _("00000"), wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl1->SetMaxLength(5);
    FlexGridSizer2->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText43 = new wxStaticText(EchtWerte, ID_STATICTEXT43, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT43"));
    FlexGridSizer2->Add(StaticText43, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText40 = new wxStaticText(EchtWerte, ID_STATICTEXT40, _("Zeit pro Umdrehung:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT40"));
    FlexGridSizer2->Add(StaticText40, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlTPR = new wxTextCtrl(EchtWerte, ID_TEXTCTRLTPR, _("0000"), wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLTPR"));
    TextCtrlTPR->SetMaxLength(4);
    FlexGridSizer2->Add(TextCtrlTPR, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText41 = new wxStaticText(EchtWerte, ID_STATICTEXT41, _("Millisekunden"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT41"));
    FlexGridSizer2->Add(StaticText41, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText47 = new wxStaticText(EchtWerte, ID_STATICTEXT47, _("Aktueller Zuendzeitpunkt:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT47"));
    FlexGridSizer2->Add(StaticText47, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(EchtWerte, ID_TEXTCTRL2, _("00"), wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl2->SetMaxLength(2);
    FlexGridSizer2->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText48 = new wxStaticText(EchtWerte, ID_STATICTEXT48, _("Grad"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT48"));
    FlexGridSizer2->Add(StaticText48, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(EchtWerte, ID_STATICTEXT3, _("Modus:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer2->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrlEchtModus = new wxTextCtrl(EchtWerte, ID_TEXTCTRLEchtModus, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_NO_VSCROLL|wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRLEchtModus"));
    TextCtrlEchtModus->SetMaxLength(2);
    FlexGridSizer2->Add(TextCtrlEchtModus, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(EchtWerte, ID_STATICTEXT5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    EchtWerte->SetSizer(FlexGridSizer2);
    FlexGridSizer2->Fit(EchtWerte);
    FlexGridSizer2->SetSizeHints(EchtWerte);
    Notebook1->AddPage(PanelBasis, _("Basis"), false);
    Notebook1->AddPage(PanelTB1, _("Tabelle1"), false);
    Notebook1->AddPage(PanelTB2, _("Tabelle2"), false);
    Notebook1->AddPage(PanelTB3, _("Tabelle3"), false);
    Notebook1->AddPage(EchtWerte, _("Werte"), false);
    BoxSizer1->Add(Notebook1, 2, wxALL|wxEXPAND, 5);
    TextCtrlLOG = new wxTextCtrl(Panel1, ID_TEXTCTRLLOG, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_RICH|wxTE_LEFT|wxTE_WORDWRAP, wxDefaultValidator, _T("ID_TEXTCTRLLOG"));
    BoxSizer1->Add(TextCtrlLOG, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    HauptMenuBar = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu1, idMenuSpeichern, _("Speichern\tAlt-S"), _("Speichern der Konfiguration"), wxITEM_NORMAL);
    Menu1->Append(MenuItem5);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Schliessen\tAlt-F4"), _("Programmen beenden"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    HauptMenuBar->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, idMenuVerbinden, _("Verbinden\tAlt-V"), _("Verbinden Modul"), wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, idMenuTrennen, _("Trennen\tAlt-T"), _("Trennen Modul"), wxITEM_NORMAL);
    Menu3->Append(MenuItem4);
    HauptMenuBar->Append(Menu3, _("&Kommunikation"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    HauptMenuBar->Append(Menu2, _("Help"));
    SetMenuBar(HauptMenuBar);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[2] = { -1, -1 };
    int __wxStatusBarStyles_1[2] = { wxSB_RAISED, wxSB_RAISED };
    StatusBar1->SetFieldsCount(2,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(2,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuSpeichern,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnSpeichern);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnQuit);
    Connect(idMenuVerbinden,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnConnectUsb);
    Connect(idMenuTrennen,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnDisconnectUsb);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&USBLoader2Frame::OnAbout);
    //*)
}

USBLoader2Frame::~USBLoader2Frame()
{
    //(*Destroy(USBLoader2Frame)
    //*)
    fininish = true;
    delete digiSpark;
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
    wxString s;

    fininish = true;
    delete digiSpark;
    connected = false;
	s << "Nicht verbunden";
	this->SetStatusText(s, 1);
}

void USBLoader2Frame::OnConnectUsb(wxCommandEvent& event)
{
    wxString m, s;
	int led = 0;

	if (connected == true) // vendor 5824, product 1503
	{
		cout << "Device is already connected!!!" << endl << ends;
		return;
	}

	wxStreamToTextRedirector redirect(TextCtrlLOG);

	fininish = false;
	digiSpark = new USBDevice();

	//digiSpark->connect_device();
	digiSpark->connect_device_with_search();

	if (digiSpark->isConnected()) // vendor 5824, product 1503
	{
		s << "Verbunden";
		led = digiSpark->getLED();
	//	if (led > 0)
				//m_checkBox1->SetValue(true);
	//	else
	//		if (!led)
				//m_checkBox1->SetValue(false);
		connected = true;
	}
	else
	{
		s << "Nicht Verbunden";
		cout << digiSpark->getLog();
		cout << digiSpark->print_deviceList();
		cout << digiSpark->getLog();
		connected = false;
		delete digiSpark;
		return; // exit no device connected
	}
	this->SetStatusText(s, 1);
	int k = 0;
	while (fininish == false) {
		cout << digiSpark->getLog();
		cout << digiSpark->readString();

	/*	if (digiSpark->isConnected())
		{
			if (connected == false)
			{
				connected = true;
				s << "Verbunden";
				this->SetStatusText(s, 2);
			}

		}
		else
		{
			if (connected == true)
			{
				connected = false;
				s << "Nicht Verbunden";
				this->SetStatusText(s, 2);
			}
		}
*/
		wxYield();
		//::wxSleep(1);
	}
	return;
}

void USBLoader2Frame::OnSpeichern(wxCommandEvent& event)
{
}
