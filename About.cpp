#include "About.h"

//(*InternalHeaders(About)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(About)
const long About::ID_BUTTON1 = wxNewId();
const long About::ID_TEXTCTRL1 = wxNewId();
const long About::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(About,wxDialog)
	//(*EventTable(About)
	//*)
END_EVENT_TABLE()

About::About(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(About)
	Create(parent, id, _("About"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxSize(300,300));
	Move(wxDefaultPosition);
	SetFocus();
	Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,0), wxSize(300,300), 0, _T("ID_PANEL1"));
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("OK"), wxPoint(112,232), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	Button1->SetFocus();
	TextCtrl1 = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("\nZuendmodul Konfigurator \n\nVersion: 0.0 \n\nHelge Scheunemann, Sept. 2020\n\nKontakt: zm-mz@scheuni.de"), wxPoint(24,40), wxSize(248,160), wxTE_NO_VSCROLL|wxTE_MULTILINE|wxTE_READONLY|wxTE_CENTRE|wxBORDER_SIMPLE, wxDefaultValidator, _T("ID_TEXTCTRL1"));

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&About::OnOKClick);
	//*)
}

About::~About()
{
	//(*Destroy(About)
	//*)
}


void About::OnOKClick(wxCommandEvent& event)
{
    Close();
}
