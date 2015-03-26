#ifndef dlgVCO_CGEN_H
#define dlgVCO_CGEN_H

#include "pnlFreqTable.h"
//(*Headers(dlgVCO_CGEN)
#include <wx/dialog.h>
class wxPanel;
class wxFlexGridSizer;
class wxButton;
//*)

class PLL_CGEN;

class dlgVCO_CGEN: public wxDialog
{
	public:

		dlgVCO_CGEN(PLL_CGEN *data, wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgVCO_CGEN();

		//(*Declarations(dlgVCO_CGEN)
		wxButton* btnSave;
		wxButton* btnCancel;
		wxButton* btnOK;
		wxButton* btnLoad;
		pnlFreqTable* pnlVCO_CGEN;
		//*)

	protected:
        PLL_CGEN *pll_data;
		//(*Identifiers(dlgVCO_CGEN)
		static const long ID_PANEL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		//*)

	private:

		//(*Handlers(dlgVCO_CGEN)
		void OnInit(wxInitDialogEvent& event);
		void OnbtnOKClick(wxCommandEvent& event);
		void OnbtnCancelClick(wxCommandEvent& event);
		void OnbtnLoadClick(wxCommandEvent& event);
		void OnbtnSaveClick(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
