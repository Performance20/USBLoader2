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
const long USBLoader2Frame::ID_RADIOBUTTON1 = wxNewId();
const long USBLoader2Frame::ID_RADIOBUTTON2 = wxNewId();
const long USBLoader2Frame::ID_RADIOBUTTON3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT2 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT3 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL3 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT5 = wxNewId();
const long USBLoader2Frame::ID_RADIOBUTTON4 = wxNewId();
const long USBLoader2Frame::ID_RADIOBUTTON5 = wxNewId();
const long USBLoader2Frame::ID_RADIOBUTTON6 = wxNewId();
const long USBLoader2Frame::ID_PANEL2 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT1 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT7 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT8 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL1 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL4 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL5 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL6 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT10 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL7 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL8 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT11 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL9 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL10 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT12 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL11 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL12 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT13 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL13 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL14 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT14 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL15 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL16 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT15 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL17 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL18 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT16 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL19 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL20 = wxNewId();
const long USBLoader2Frame::ID_STATICTEXT17 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL21 = wxNewId();
const long USBLoader2Frame::ID_SPINCTRL22 = wxNewId();
const long USBLoader2Frame::ID_PANEL3 = wxNewId();
const long USBLoader2Frame::ID_PANEL4 = wxNewId();
const long USBLoader2Frame::ID_PANEL5 = wxNewId();
const long USBLoader2Frame::ID_PANEL6 = wxNewId();
const long USBLoader2Frame::ID_NOTEBOOK1 = wxNewId();
const long USBLoader2Frame::ID_TEXTCTRL2 = wxNewId();
const long USBLoader2Frame::ID_PANEL1 = wxNewId();
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
    wxGridSizer* GridSizer1;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenu* Menu3;
    wxMenuBar* HauptMenuBar;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;

    Create(parent, id, _("Zuendmodul Konfigurator "), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(500,700));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(184,200), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Notebook1 = new wxNotebook(Panel1, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, wxNB_FIXEDWIDTH|wxBORDER_RAISED, _T("ID_NOTEBOOK1"));
    Notebook1->SetFocus();
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxPoint(131,153), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer2 = new wxBoxSizer(wxVERTICAL);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Funktion"));
    RadioButton1 = new wxRadioButton(Panel2, ID_RADIOBUTTON1, _("Manuell"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    StaticBoxSizer1->Add(RadioButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton2 = new wxRadioButton(Panel2, ID_RADIOBUTTON2, _("Fester Abstand von OT"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    StaticBoxSizer1->Add(RadioButton2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton3 = new wxRadioButton(Panel2, ID_RADIOBUTTON3, _("Dynamisch von OT"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    StaticBoxSizer1->Add(RadioButton3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer1, 0, wxALL|wxEXPAND, 10);
    FlexGridSizer1 = new wxFlexGridSizer(2, 3, 0, 0);
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("Zuendzeitpunkt:"), wxDefaultPosition, wxDefaultSize, wxWANTS_CHARS, _T("ID_STATICTEXT2"));
    FlexGridSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl2 = new wxSpinCtrl(Panel2, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxSize(100,30), 0, -30, 20, 0, _T("ID_SPINCTRL2"));
    SpinCtrl2->SetValue(_T("0"));
    SpinCtrl2->SetToolTip(_("Grad von OT, bei dem gezündet wird = -22 Grad wäre 22 Grad vot OT"));
    FlexGridSizer1->Add(SpinCtrl2, 1, wxALL, 5);
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Grad (Wert 0 = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Spule laden:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText3->SetToolTip(_("Wieviel Grad von einer Umdrehung für das magnetische Laden der Zünnspule genutzt werden (bei Unterbrecher-Nocken ca. 180°)"));
    FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl3 = new wxSpinCtrl(Panel2, ID_SPINCTRL3, _T("270"), wxDefaultPosition, wxSize(100,30), 0, 90, 320, 270, _T("ID_SPINCTRL3"));
    SpinCtrl3->SetValue(_T("270"));
    FlexGridSizer1->Add(SpinCtrl3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel2, ID_STATICTEXT5, _("Grad"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer1->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(FlexGridSizer1, 0, wxALL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("LED"));
    RadioButton4 = new wxRadioButton(Panel2, ID_RADIOBUTTON4, _("Aus"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    StaticBoxSizer2->Add(RadioButton4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton5 = new wxRadioButton(Panel2, ID_RADIOBUTTON5, _("Eingangssignal"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON5"));
    StaticBoxSizer2->Add(RadioButton5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    RadioButton6 = new wxRadioButton(Panel2, ID_RADIOBUTTON6, _("Diagnose"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON6"));
    StaticBoxSizer2->Add(RadioButton6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND, 10);
    Panel2->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel2);
    BoxSizer2->SetSizeHints(Panel2);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    GridSizer1 = new wxGridSizer(11, 3, 0, 0);
    StaticText1 = new wxStaticText(Panel3, ID_STATICTEXT1, _("Pos."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel3, ID_STATICTEXT6, _("Umdr./Min"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    GridSizer1->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel3, ID_STATICTEXT7, _("Grad"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    GridSizer1->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel3, ID_STATICTEXT8, _("1."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
    GridSizer1->Add(StaticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrlTB1_1 = new wxSpinCtrl(Panel3, ID_SPINCTRL1, _T("500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 500, _T("ID_SPINCTRL1"));
    SpinCtrlTB1_1->SetValue(_T("500"));
    GridSizer1->Add(SpinCtrlTB1_1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl4 = new wxSpinCtrl(Panel3, ID_SPINCTRL4, _T("0"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, 0, _T("ID_SPINCTRL4"));
    SpinCtrl4->SetValue(_T("0"));
    GridSizer1->Add(SpinCtrl4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText9 = new wxStaticText(Panel3, ID_STATICTEXT9, _("2."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    GridSizer1->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl5 = new wxSpinCtrl(Panel3, ID_SPINCTRL5, _T("2000"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 2000, _T("ID_SPINCTRL5"));
    SpinCtrl5->SetValue(_T("2000"));
    GridSizer1->Add(SpinCtrl5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl6 = new wxSpinCtrl(Panel3, ID_SPINCTRL6, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL6"));
    SpinCtrl6->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrl6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(Panel3, ID_STATICTEXT10, _("3."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    GridSizer1->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl7 = new wxSpinCtrl(Panel3, ID_SPINCTRL7, _T("3000"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 3000, _T("ID_SPINCTRL7"));
    SpinCtrl7->SetValue(_T("3000"));
    GridSizer1->Add(SpinCtrl7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl8 = new wxSpinCtrl(Panel3, ID_SPINCTRL8, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL8"));
    SpinCtrl8->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrl8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText11 = new wxStaticText(Panel3, ID_STATICTEXT11, _("4."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    GridSizer1->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl9 = new wxSpinCtrl(Panel3, ID_SPINCTRL9, _T("3500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 3500, _T("ID_SPINCTRL9"));
    SpinCtrl9->SetValue(_T("3500"));
    GridSizer1->Add(SpinCtrl9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl10 = new wxSpinCtrl(Panel3, ID_SPINCTRL10, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL10"));
    SpinCtrl10->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrl10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(Panel3, ID_STATICTEXT12, _("5."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    GridSizer1->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl11 = new wxSpinCtrl(Panel3, ID_SPINCTRL11, _T("4500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 4500, _T("ID_SPINCTRL11"));
    SpinCtrl11->SetValue(_T("4500"));
    GridSizer1->Add(SpinCtrl11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl12 = new wxSpinCtrl(Panel3, ID_SPINCTRL12, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL12"));
    SpinCtrl12->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrl12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText13 = new wxStaticText(Panel3, ID_STATICTEXT13, _("6."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    GridSizer1->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl13 = new wxSpinCtrl(Panel3, ID_SPINCTRL13, _T("5000"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 5000, _T("ID_SPINCTRL13"));
    SpinCtrl13->SetValue(_T("5000"));
    GridSizer1->Add(SpinCtrl13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl14 = new wxSpinCtrl(Panel3, ID_SPINCTRL14, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL14"));
    SpinCtrl14->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrl14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText14 = new wxStaticText(Panel3, ID_STATICTEXT14, _("7."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    GridSizer1->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl15 = new wxSpinCtrl(Panel3, ID_SPINCTRL15, _T("5500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 5500, _T("ID_SPINCTRL15"));
    SpinCtrl15->SetValue(_T("5500"));
    GridSizer1->Add(SpinCtrl15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl16 = new wxSpinCtrl(Panel3, ID_SPINCTRL16, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL16"));
    SpinCtrl16->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrl16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText15 = new wxStaticText(Panel3, ID_STATICTEXT15, _("8."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    GridSizer1->Add(StaticText15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl17 = new wxSpinCtrl(Panel3, ID_SPINCTRL17, _T("6000"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 6000, _T("ID_SPINCTRL17"));
    SpinCtrl17->SetValue(_T("6000"));
    GridSizer1->Add(SpinCtrl17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl18 = new wxSpinCtrl(Panel3, ID_SPINCTRL18, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL18"));
    SpinCtrl18->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrl18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(Panel3, ID_STATICTEXT16, _("9."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    GridSizer1->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl19 = new wxSpinCtrl(Panel3, ID_SPINCTRL19, _T("6500"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 6500, _T("ID_SPINCTRL19"));
    SpinCtrl19->SetValue(_T("6500"));
    GridSizer1->Add(SpinCtrl19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl20 = new wxSpinCtrl(Panel3, ID_SPINCTRL20, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL20"));
    SpinCtrl20->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrl20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText17 = new wxStaticText(Panel3, ID_STATICTEXT17, _("10."), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    GridSizer1->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl21 = new wxSpinCtrl(Panel3, ID_SPINCTRL21, _T("7000"), wxDefaultPosition, wxSize(120,30), 0, 0, 10000, 7000, _T("ID_SPINCTRL21"));
    SpinCtrl21->SetValue(_T("7000"));
    GridSizer1->Add(SpinCtrl21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl22 = new wxSpinCtrl(Panel3, ID_SPINCTRL22, _T("-22"), wxDefaultPosition, wxSize(120,30), 0, -30, 20, -22, _T("ID_SPINCTRL22"));
    SpinCtrl22->SetValue(_T("-22"));
    GridSizer1->Add(SpinCtrl22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(GridSizer1);
    GridSizer1->Fit(Panel3);
    GridSizer1->SetSizeHints(Panel3);
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Panel5 = new wxPanel(Notebook1, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    Notebook1->AddPage(Panel2, _("Basis"), false);
    Notebook1->AddPage(Panel3, _("Tabelle1"), false);
    Notebook1->AddPage(Panel4, _("Tabelle2"), false);
    Notebook1->AddPage(Panel5, _("Tabelle3"), false);
    Notebook1->AddPage(Panel6, _("Werte"), false);
    BoxSizer1->Add(Notebook1, 2, wxALL|wxEXPAND, 5);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_LEFT|wxBORDER_SUNKEN, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    BoxSizer1->Add(TextCtrl2, 1, wxALL|wxEXPAND, 5);
    Panel1->SetSizer(BoxSizer1);
    BoxSizer1->Fit(Panel1);
    BoxSizer1->SetSizeHints(Panel1);
    HauptMenuBar = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    HauptMenuBar->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, idMenuVerbinden, _("Verbinden"), _("Verbinden Modul"), wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem4 = new wxMenuItem(Menu3, idMenuTrennen, _("Trennen"), _("Trennen Modul"), wxITEM_NORMAL);
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

	s << "Nicht verbunden";
	this->SetStatusText(s, 1);
}

void USBLoader2Frame::OnConnectUsb(wxCommandEvent& event)
{
    wxString s;

	s << "Verbunden";
	this->SetStatusText(s, 1);
}
