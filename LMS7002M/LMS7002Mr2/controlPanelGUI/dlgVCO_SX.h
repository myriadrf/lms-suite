#ifndef DLGVCO_SX_H
#define DLGVCO_SX_H

#include "pnlFreqTable.h"
//(*Headers(dlgVCO_SX)
#include <wx/dialog.h>
class wxPanel;
class wxFlexGridSizer;
class wxButton;
//*)

class PLL_SX;

class dlgVCO_SX: public wxDialog
{
	public:

		dlgVCO_SX(PLL_SX *data, wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~dlgVCO_SX();

		//(*Declarations(dlgVCO_SX)
		wxButton* btnSave;
		wxButton* btnCancel;
		pnlFreqTable* pnlVCOL;
		wxButton* btnOK;
		wxButton* btnLoad;
		pnlFreqTable* pnlVCOM;
		pnlFreqTable* pnlVCOH;
		//*)

	protected:
        PLL_SX *pll_data;
		//(*Identifiers(dlgVCO_SX)
		static const long ID_PANEL1;
		static const long ID_PANEL2;
		static const long ID_PANEL3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		//*)

	private:

		//(*Handlers(dlgVCO_SX)
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
