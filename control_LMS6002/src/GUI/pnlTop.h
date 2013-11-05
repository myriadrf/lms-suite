#ifndef PNLTOP_H
#define PNLTOP_H

//(*Headers(pnlTop)
#include <wx/panel.h>
class wxStaticBoxSizer;
class wxComboBox;
class wxFlexGridSizer;
class wxToggleButton;
class wxButton;
class wxStaticLine;
class wxCheckListBox;
class wxBoxSizer;
class wxStaticText;
class wxRadioBox;
class wxStaticBox;
class wxCheckBox;
//*)

class pnlTop: public wxPanel
{
	public:

		pnlTop(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int styles = 0, wxString idname="");
		virtual ~pnlTop();

        void FillComboBoxes();
        void SetGuiDefaults();
        void SetGuiDecode();
        void Initialize();

        bool UpdateGUI();
        void DownloadAllDCCalValues();

        /*int GetCalVal(int Addr);
        void SetCalVal(int Addr, int Val);
        void SetCalAddr(int Addr);*/
        void StartCalibration(int Addr);
        char GetCalStatus();
        void SetCalDefaults();

		//(*Declarations(pnlTop)
		wxRadioBox* rgrCLKSEL_LPFCAL;
		wxRadioBox* rgrRFLB;
		wxButton* btnReadRCCALVal;
		wxButton* btnDCReadVal;
		wxPanel* Panel7;
		wxButton* btnDCRstClbr;
		wxCheckListBox* chbSpiClkBuf;
		wxCheckBox* chbSLFBXCOBUF;
		wxCheckBox* chbPwrSoftTx;
		wxButton* btnDCStartClbr;
		wxCheckBox* chkLpfCalEnEnf;
		wxRadioBox* rgrTDDMOD;
		wxRadioBox* rgrBBLB;
		wxButton* btnDCLoadVal;
		wxCheckBox* chbPwrSoftRx;
		wxCheckBox* chkLpfCalEn;
		wxRadioBox* rgrSpiMode;
		wxStaticText* lblDC_CLBR_DONE;
		wxStaticText* lblDC_LOCK;
		wxStaticText* lblRCCAL_LPFCAL;
		wxStaticText* StaticText1;
		wxCheckBox* chbPDXCOBUF;
		wxStaticBox* StaticBox2;
		wxStaticText* StaticText3;
		wxCheckBox* chbRxTestModeEn;
		wxStaticLine* StaticLine1;
		wxCheckBox* chbPD_CLKLPFCAL;
		wxComboBox* cmbDCCalAddr;
		wxStaticText* lblDC_UD;
		wxStaticText* StaticText8;
		wxCheckBox* chbPwrRfLbsw;
		wxStaticText* StaticText7;
		wxComboBox* cmbCalVal;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxCheckBox* chkLpfCalRst;
		wxStaticText* StaticText2;
		wxComboBox* cmbLpfCalBw;
		wxRadioBox* rgrRXOUTSW;
		wxToggleButton* swReset;
		wxStaticText* StaticText6;
		wxRadioBox* rgrDecode;
		wxComboBox* cmbLpfCalCode;
		wxRadioBox* rgrFDDTDD;
		wxStaticText* StaticText9;
		wxCheckBox* chbBYPXCOBUF;
		wxStaticText* lbDC_REGVAL;
		wxCheckBox* chbPwrTopMods;
		wxCheckBox* chbPwrLpfCal;
		wxRadioBox* rgrDsmRst;
		//*)

	protected:

		//(*Identifiers(pnlTop)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICLINE1;
		static const long ID_COMBOBOX1;
		static const long ID_COMBOBOX2;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT4;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT10;
		static const long ID_RADIOBOX3;
		static const long ID_RADIOBOX4;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX3;
		static const long ID_CHECKBOX4;
		static const long ID_CHECKBOX5;
		static const long ID_RADIOBOX5;
		static const long ID_RADIOBOX6;
		static const long ID_RADIOBOX7;
		static const long ID_CHECKBOX6;
		static const long ID_CHECKBOX7;
		static const long ID_CHECKBOX8;
		static const long ID_CHECKLISTBOX1;
		static const long ID_RADIOBOX8;
		static const long ID_CHECKBOX10;
		static const long ID_CHECKBOX11;
		static const long ID_CHECKBOX12;
		static const long ID_CHECKBOX13;
		static const long ID_STATICBOX2;
		static const long ID_STATICTEXT11;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT13;
		static const long ID_COMBOBOX3;
		static const long ID_COMBOBOX4;
		static const long ID_STATICTEXT14;
		static const long ID_PANEL7;
		static const long ID_RADIOBOX1;
		static const long ID_RADIOBOX2;
		static const long ID_CHECKBOX9;
		static const long ID_RADIOBOX9;
		static const long ID_TOGGLEBUTTON1;
		//*)

	private:

		//(*Handlers(pnlTop)
		void rgrDecodeClick(wxCommandEvent& event);
		void rgrSpiModeClick(wxCommandEvent& event);
		void rgrDsmRstClick(wxCommandEvent& event);
		void chbRxTestModeEnClick(wxCommandEvent& event);
		void chbSpiClkBufClick(wxCommandEvent& event);
		void rgrRFLBClick(wxCommandEvent& event);
		void chkLpfCalRstClick(wxCommandEvent& event);
		void chkLpfCalEnClick(wxCommandEvent& event);
		void chkLpfCalEnEnfClick(wxCommandEvent& event);
		void cmbLpfCalCodeChange(wxCommandEvent& event);
		void cmbLpfCalBwChange(wxCommandEvent& event);
		void chbPwrTopModsClick(wxCommandEvent& event);
		void chbPwrSoftTxClick(wxCommandEvent& event);
		void chbPwrSoftRxClick(wxCommandEvent& event);
		void chbPwrLpfCalClick(wxCommandEvent& event);
		void chbPwrRfLbswClick(wxCommandEvent& event);
		void cmbDCCalAddrChange(wxCommandEvent& event);
		void cmbCalValChange(wxCommandEvent& event);
		void btnDCRstClbrClick(wxCommandEvent& event);
		void btnDCLoadValClick(wxCommandEvent& event);
		void btnDCStartClbrClick(wxCommandEvent& event);
		void btnDCReadValClick(wxCommandEvent& event);
		void rgrBBLBClick(wxCommandEvent& event);
		void rgrCLKSEL_LPFCALClick(wxCommandEvent& event);
		void chbPD_CLKLPFCALClick(wxCommandEvent& event);
		void rgrRXOUTSWClick(wxCommandEvent& event);
		void rgrFDDTDDClick(wxCommandEvent& event);
		void rgrTDDMODClick(wxCommandEvent& event);
		void chbPDXCOBUFClick(wxCommandEvent& event);
		void chbSLFBXCOBUFClick(wxCommandEvent& event);
		void chbBYPXCOBUFClick(wxCommandEvent& event);
		void btnReadRCCALValClick(wxCommandEvent& event);
		void swResetClick(wxCommandEvent& event);
		void OnEraseBackground(wxEraseEvent& event);
		void OnPaint(wxPaintEvent& event);
		//*)

        bool sendChanges;

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
