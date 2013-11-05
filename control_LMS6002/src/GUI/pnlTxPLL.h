#ifndef PNLTXPLL_H
#define PNLTXPLL_H

//(*Headers(pnlTxPLL)
#include <wx/panel.h>
class wxTextCtrl;
class wxStaticBoxSizer;
class wxNotebook;
class wxComboBox;
class wxFlexGridSizer;
class wxSpinButton;
class wxSpinEvent;
class wxButton;
class wxBoxSizer;
class wxNotebookEvent;
class wxStaticText;
class wxRadioBox;
class wxCheckBox;
//*)

#include <fstream>
#include <ostream>
using namespace std;

class pnlTxPLL: public wxPanel
{
	public:

		pnlTxPLL(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int styles = 0, wxString idname="");
		virtual ~pnlTxPLL();

        void FillComboBoxes();
		void SetGuiDefaults();
        void SetGuiDecode();
        void Initialize();

        bool ChipVsGui(ofstream &out, wxString Caption, bool bWrAll);
        bool UpdateGUI();

        void SetRefClk(double RefClk);
        double GetRefClk();

        void BIST_ShowState(bool State);
        void BIST_ShowSignature();

		//(*Declarations(pnlTxPLL)
		wxComboBox* cmbDITHN;
		wxComboBox* cmbSELOUT;
		wxCheckBox* chkDITHEN;
		wxStaticText* lblVcoF;
		wxPanel* Panel6;
		wxStaticText* StaticText21;
		wxRadioBox* rgrMODE;
		wxStaticText* StaticText13;
		wxStaticText* StaticText14;
		wxPanel* Panel7;
		wxStaticText* StaticText15;
		wxStaticText* lblAutoTuneSatatus;
		wxStaticText* lblFvco8Int;
		wxComboBox* cmbICHP;
		wxStaticText* lblNfrac;
		wxStaticText* StaticText17;
		wxStaticText* lblNint;
		wxComboBox* cmbOFFUP;
		wxRadioBox* rgrBCLKSEL;
		wxCheckBox* chbBYPVCOREG;
		wxCheckBox* chkTRI;
		wxCheckBox* chbPDVCOREG;
		wxRadioBox* rgrSELVCO;
		wxCheckBox* chkENFEEDDIV;
		wxStaticText* lblBSTATE;
		wxStaticText* lblROutF;
		wxTextCtrl* txtDesFreq;
		wxButton* btnClbr;
		wxComboBox* cmbVCOCAP;
		wxButton* Button1;
		wxCheckBox* chkPFDPD;
		wxCheckBox* chkCapLog;
		wxStaticText* lblN;
		wxStaticText* lblFvco4Int;
		wxStaticText* StaticText20;
		wxButton* btnReadVtune;
		wxStaticText* StaticText18;
		wxStaticText* StaticText1;
		wxStaticText* StaticText10;
		wxStaticText* lblDiv;
		wxStaticText* StaticText16;
		wxButton* btnChoose;
		wxSpinButton* CSpinButton1;
		wxCheckBox* chbEN_PFD_UP;
		wxComboBox* cmbOFFDOWN;
		wxPanel* Panel2;
		wxComboBox* cmbVOVCOREG;
		wxCheckBox* chbPwrPllMods;
		wxCheckBox* chkENLAMP;
		wxStaticText* StaticText3;
		wxPanel* Panel4;
		wxButton* btnTune;
		wxRadioBox* rgrBINSEL;
		wxStaticText* StaticText23;
		wxCheckBox* chkENLOBUF;
		wxCheckBox* chbFSTVCOBG;
		wxStaticText* StaticText8;
		wxStaticText* StaticText12;
		wxStaticText* lblVTUNE_H;
		wxStaticText* lblFvco2Int;
		wxCheckBox* chbAUTOBYP;
		wxPanel* Panel3;
		wxStaticText* lblFvco16Int;
		wxStaticText* StaticText7;
		wxButton* btnCalc;
		wxStaticText* lblFvcoInt;
		wxPanel* Panel15;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxComboBox* cmbBCODE;
		wxStaticText* lblVTUNE_L;
		wxCheckBox* chkPASSEN_TSTOD_SD;
		wxNotebook* Notebook1;
		wxRadioBox* rgrFRANGE;
		wxComboBox* cmbACODE;
		wxStaticText* StaticText6;
		wxButton* btnReadBISTState;
		wxCheckBox* chkPD_VCOCOMP_SX;
		wxRadioBox* rgrDecode;
		wxCheckBox* chkPOL;
		wxStaticText* lblBSIG;
		wxStaticText* StaticText19;
		wxCheckBox* chkOEN_TSTD_SX;
		wxStaticText* StaticText9;
		wxStaticText* StaticText11;
		wxCheckBox* chkPFDCLKP;
		//*)

	protected:

		//(*Identifiers(pnlTxPLL)
		static const long ID_RADIOBOX1;
		static const long ID_CHECKBOX1;
		static const long ID_CHECKBOX2;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_BUTTON3;
		static const long ID_CHECKBOX3;
		static const long ID_COMBOBOX1;
		static const long ID_STATICTEXT3;
		static const long ID_PANEL2;
		static const long ID_STATICTEXT4;
		static const long ID_COMBOBOX2;
		static const long ID_CHECKBOX4;
		static const long ID_CHECKBOX5;
		static const long ID_CHECKBOX6;
		static const long ID_BUTTON4;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_PANEL3;
		static const long ID_CHECKBOX7;
		static const long ID_CHECKBOX8;
		static const long ID_CHECKBOX9;
		static const long ID_CHECKBOX10;
		static const long ID_CHECKBOX11;
		static const long ID_CHECKBOX12;
		static const long ID_CHECKBOX13;
		static const long ID_CHECKBOX14;
		static const long ID_CHECKBOX15;
		static const long ID_CHECKBOX16;
		static const long ID_CHECKBOX17;
		static const long ID_PANEL6;
		static const long ID_STATICTEXT33;
		static const long ID_STATICTEXT35;
		static const long ID_STATICTEXT34;
		static const long ID_COMBOBOX5;
		static const long ID_COMBOBOX6;
		static const long ID_COMBOBOX7;
		static const long ID_COMBOBOX8;
		static const long ID_CHECKBOX18;
		static const long ID_COMBOBOX9;
		static const long ID_STATICTEXT36;
		static const long ID_PANEL15;
		static const long ID_RADIOBOX2;
		static const long ID_TEXTCTRL1;
		static const long ID_SPINBUTTON1;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT12;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT16;
		static const long ID_STATICTEXT17;
		static const long ID_STATICTEXT19;
		static const long ID_STATICTEXT18;
		static const long ID_STATICTEXT20;
		static const long ID_RADIOBOX3;
		static const long ID_STATICTEXT9;
		static const long ID_COMBOBOX3;
		static const long ID_STATICTEXT10;
		static const long ID_COMBOBOX4;
		static const long ID_STATICTEXT21;
		static const long ID_STATICTEXT22;
		static const long ID_STATICTEXT23;
		static const long ID_STATICTEXT24;
		static const long ID_STATICTEXT25;
		static const long ID_STATICTEXT26;
		static const long ID_STATICTEXT27;
		static const long ID_STATICTEXT28;
		static const long ID_STATICTEXT29;
		static const long ID_STATICTEXT30;
		static const long ID_STATICTEXT31;
		static const long ID_STATICTEXT32;
		static const long ID_RADIOBOX4;
		static const long ID_PANEL4;
		static const long ID_STATICTEXT37;
		static const long ID_BUTTON6;
		static const long ID_STATICTEXT38;
		static const long ID_BUTTON7;
		static const long ID_RADIOBOX5;
		static const long ID_RADIOBOX6;
		static const long ID_PANEL7;
		static const long ID_NOTEBOOK1;
		//*)

	private:

		//(*Handlers(pnlTxPLL)
		void btnCalcClick(wxCommandEvent& event);
		void chkDITHENClick(wxCommandEvent& event);
		void cmbDITHNChange(wxCommandEvent& event);
		void chbPwrPllModsClick(wxCommandEvent& event);
		void rgrDecodeClick(wxCommandEvent& event);
		void rgrMODEClick(wxCommandEvent& event);
		void rgrSELVCOClick(wxCommandEvent& event);
		void rgrFRANGEClick(wxCommandEvent& event);
		void cmbSELOUTChange(wxCommandEvent& event);
		void cmbICHPChange(wxCommandEvent& event);
		void cmbOFFUPChange(wxCommandEvent& event);
		void cmbOFFDOWNChange(wxCommandEvent& event);
		void cmbVCOCAPChange(wxCommandEvent& event);
		void cmbBCODEChange(wxCommandEvent& event);
		void cmbACODEChange(wxCommandEvent& event);
		void chkENLOBUFClick(wxCommandEvent& event);
		void chkENLAMPClick(wxCommandEvent& event);
		void chkPFDPDClick(wxCommandEvent& event);
		void chkENFEEDDIVClick(wxCommandEvent& event);
		void btnClbrClick(wxCommandEvent& event);
		void btnChooseClick(wxCommandEvent& event);
		void chkPD_VCOCOMP_SXClick(wxCommandEvent& event);
		void chkOEN_TSTD_SXClick(wxCommandEvent& event);
		void chkPASSEN_TSTOD_SDClick(wxCommandEvent& event);
		void btnReadVtuneClick(wxCommandEvent& event);
		void btnTuneClick(wxCommandEvent& event);
		void chkPFDCLKPClick(wxCommandEvent& event);
		void chkTRIClick(wxCommandEvent& event);
		void chkPOLClick(wxCommandEvent& event);
		void chbAUTOBYPClick(wxCommandEvent& event);
		void chbEN_PFD_UPClick(wxCommandEvent& event);
		void chbBYPVCOREGClick(wxCommandEvent& event);
		void chbPDVCOREGClick(wxCommandEvent& event);
		void chbFSTVCOBGClick(wxCommandEvent& event);
		void cmbVOVCOREGChange(wxCommandEvent& event);
		void rgrBCLKSELClick(wxCommandEvent& event);
		void rgrBINSELClick(wxCommandEvent& event);
		void btnReadBISTStateClick(wxCommandEvent& event);
		void Button1Click(wxCommandEvent& event);
		void btnBSTARTClick(wxCommandEvent& event);
		void txtDesFreqChange(wxCommandEvent& event);
		void CSpinButton1DownClick(wxCommandEvent& event);
		void CSpinButton1UpClick(wxCommandEvent& event);
		void OnCSpinButton1ChangeUp(wxSpinEvent& event);
		void OnCSpinButton1ChangeDown(wxSpinEvent& event);
		void OnEraseBackground(wxEraseEvent& event);
		//*)

	protected:
        char m_cMAddr;
        //TdlgFreqVsCap *dlgFreqVsCap;
        bool sendChanges;
		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
