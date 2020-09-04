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
enum wxbuildinfoformat
{
    short_f, long_f
};

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
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenu* Menu3;
    wxMenuBar* HauptMenuBar;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxStaticBoxSizer* StaticBoxSizer2;

    Create(parent, id, _("USB Zuendmodul Konfigurator"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(500,600));
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
    SpinCtrl2 = new wxSpinCtrl(Panel2, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxSize(115,30), 0, -30, 20, 0, _T("ID_SPINCTRL2"));
    SpinCtrl2->SetValue(_T("0"));
    SpinCtrl2->SetToolTip(_("Grad von OT, bei dem gezündet wird = -22 Grad wäre 22 Grad vot OT"));
    FlexGridSizer1->Add(SpinCtrl2, 1, wxALL, 5);
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("Grad (Wert 0 = OT)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer1->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel2, ID_STATICTEXT3, _("Spule laden:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText3->SetToolTip(_("Wieviel Grad von einer Umdrehung für das magnetische Laden der Zünnspule genutzt werden (bei Unterbrecher-Nocken ca. 180°)"));
    FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    SpinCtrl3 = new wxSpinCtrl(Panel2, ID_SPINCTRL3, _T("270"), wxDefaultPosition, wxSize(115,30), 0, 90, 320, 270, _T("ID_SPINCTRL3"));
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
    Panel4 = new wxPanel(Notebook1, ID_PANEL4, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    Panel5 = new wxPanel(Notebook1, ID_PANEL5, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel6 = new wxPanel(Notebook1, ID_PANEL6, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL6"));
    Notebook1->AddPage(Panel2, _("Basis"), false);
    Notebook1->AddPage(Panel3, _("Tabelle1"), false);
    Notebook1->AddPage(Panel4, _("Tabelle2"), false);
    Notebook1->AddPage(Panel5, _("Tabelle3"), false);
    Notebook1->AddPage(Panel6, _("Werte"), false);
    BoxSizer1->Add(Notebook1, 2, wxALL|wxEXPAND, 5);
    TextCtrl2 = new wxTextCtrl(Panel1, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_LEFT|wxBORDER_SUNKEN, wxDefaultValidator, _T("ID_TEXTCTRL2"));
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
