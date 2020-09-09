#ifndef ABOUT_H
#define ABOUT_H

//(*Headers(About)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
//*)

class About: public wxDialog
{
	public:

		About(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~About();

		//(*Declarations(About)
		wxButton* Button1;
		wxPanel* Panel1;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(About)
		static const long ID_BUTTON1;
		static const long ID_TEXTCTRL1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(About)
		void OnOKClick(wxCommandEvent& event);
		void OnKeyDown(wxKeyEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
