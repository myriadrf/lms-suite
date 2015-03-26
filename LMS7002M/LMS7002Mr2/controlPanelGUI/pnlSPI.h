// -----------------------------------------------------------------------------
// FILE: 		pnlSPI.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef PNLSPI_H
#define PNLSPI_H

//(*Headers(pnlSPI)
#include <wx/panel.h>
class wxSpinEvent;
class wxCheckBox;
class wxTextCtrl;
class wxRichTextCtrl;
class wxRadioBox;
class wxStaticText;
class wxFlexGridSizer;
class wxSpinCtrl;
class wxButton;
class wxStaticBoxSizer;
//*)

#include <string>

class LMS7002_MainControl;
class ConnectionManager;

class pnlSPI: public wxPanel
{
	public:

		pnlSPI(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style=0, wxString name="");
		void Initialize( LMS7002_MainControl *pControl);
		virtual ~pnlSPI();
		void PrintLine(const std::string msg);

		int RunModuleTest(int moduleId, bool customInterval = false);

		//(*Declarations(pnlSPI)
		wxStaticText* StaticText10;
		wxButton* btnBatchRead;
		wxButton* btnTestTBB;
		wxStaticText* StaticText9;
		wxButton* btnTestLimeLight;
		wxCheckBox* chkSaveToFile;
		wxStaticText* lblReadVal;
		wxButton* btnTestBIST;
		wxCheckBox* chkTestWrittenData;
		wxCheckBox* chkTripleCheck;
		wxButton* btnTestAFE;
		wxButton* btnTestRBB;
		wxRichTextCtrl* txtTestText;
		wxButton* btnTestRxNCO;
		wxTextCtrl* txtEndAddr;
		wxStaticText* StaticText2;
		wxStaticText* StaticText6;
		wxButton* btnTestInterval;
		wxButton* btnWrTester;
		wxButton* btnWrite;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxButton* btnTestRxTSP;
		wxButton* btnTestCDS;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticText* lblRstatus;
		wxRadioBox* rgrChannelSelect;
		wxButton* btnTestSXRSXT;
		wxButton* btnTestBIAS;
		wxSpinCtrl* spinBatchCount;
		wxButton* btnTestTxNCO;
		wxTextCtrl* txtStartAddr;
		wxStaticText* StaticText5;
		wxButton* btnTestCGEN;
		wxStaticText* StaticText7;
		wxButton* btnTestXBUF;
		wxTextCtrl* txtWvalue;
		wxButton* btnTestLDO;
		wxButton* btnTestRFE;
		wxButton* btnPurgeCOM;
		wxButton* btnTestTxTSP;
		wxCheckBox* chkSaveToFileBatch;
		wxButton* btnTestTRF;
		wxButton* btnRead;
		wxTextCtrl* txtWriteAddr;
		wxStaticText* StaticText4;
		wxTextCtrl* txtReadAddr;
		wxStaticText* lblWstatus;
		wxTextCtrl* txtHexInput;
		wxCheckBox* chkBatchWR;
		//*)

	protected:

		//(*Identifiers(pnlSPI)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT9;
		static const long ID_TEXTCTRL3;
		static const long ID_BUTTON1;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_BUTTON21;
		static const long ID_STATICTEXT13;
		static const long ID_SPINCTRL1;
		static const long ID_CHECKBOX3;
		static const long ID_BUTTON22;
		static const long ID_CHECKBOX4;
		static const long ID_BUTTON23;
		static const long ID_CHECKBOX5;
		static const long ID_RADIOBOX1;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL4;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_STATICTEXT11;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT12;
		static const long ID_TEXTCTRL6;
		static const long ID_BUTTON20;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_BUTTON7;
		static const long ID_BUTTON8;
		static const long ID_BUTTON9;
		static const long ID_BUTTON19;
		static const long ID_BUTTON10;
		static const long ID_BUTTON11;
		static const long ID_BUTTON12;
		static const long ID_BUTTON13;
		static const long ID_BUTTON14;
		static const long ID_BUTTON15;
		static const long ID_BUTTON16;
		static const long ID_BUTTON17;
		static const long ID_BUTTON18;
		static const long ID_RICHTEXTCTRL1;
		//*)

	private:

		//(*Handlers(pnlSPI)
		void OnbtnWriteClick(wxCommandEvent& event);
		void OnbtnReadClick(wxCommandEvent& event);
		void OnrgrChannelSelectSelect(wxCommandEvent& event);
		void OnbtnTestLimeLightClick(wxCommandEvent& event);
		void OnbtnTestAFEClick(wxCommandEvent& event);
		void OnbtnTestBIASClick(wxCommandEvent& event);
		void OnbtnTestXBUFClick(wxCommandEvent& event);
		void OnbtnTestCGENClick(wxCommandEvent& event);
		void OnbtnTestLDOClick(wxCommandEvent& event);
		void OnbtnTestBISTClick(wxCommandEvent& event);
		void OnbtnTestTRFClick(wxCommandEvent& event);
		void OnbtnTestTBBClick(wxCommandEvent& event);
		void OnbtnTestRFEClick(wxCommandEvent& event);
		void OnbtnTestRBBClick(wxCommandEvent& event);
		void OnbtnTestSXRSXTClick(wxCommandEvent& event);
		void OnbtnTestTxTSPClick(wxCommandEvent& event);
		void OnbtnTestTxNCOClick(wxCommandEvent& event);
		void OnbtnTestRxTSPClick(wxCommandEvent& event);
		void OnbtnTestRxNCOClick(wxCommandEvent& event);
		void OnbtnTestCDSClick(wxCommandEvent& event);
		void OnbtnTestIntervalClick(wxCommandEvent& event);
		void OnbtnBatchReadClick(wxCommandEvent& event);
		void OnbtnWrTesterClick(wxCommandEvent& event);
		void OnchkTripleCheckClick(wxCommandEvent& event);
		void OnbtnPurgeCOMClick(wxCommandEvent& event);
		void OnchkTestWrittenDataClick(wxCommandEvent& event);
		//*)

	protected:
	    LMS7002_MainControl *lmsControl;
        ConnectionManager *m_serPort;
		void BuildContent(wxWindow *parent, wxWindowID id);

		DECLARE_EVENT_TABLE()
};

#endif
