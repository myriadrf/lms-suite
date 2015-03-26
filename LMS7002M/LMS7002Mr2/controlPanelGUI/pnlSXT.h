// -----------------------------------------------------------------------------
// FILE: 		pnlSXT.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef pnlSXT_H
#define pnlSXT_H
//(*Headers(pnlSXT)
#include <wx/panel.h>
class wxCheckBox;
class wxTextCtrl;
class wxComboBox;
class wxRadioBox;
class wxStaticText;
class wxFlexGridSizer;
class wxButton;
class wxStaticBoxSizer;
//*)
#include <map>
#include "RegistersMap.h"
#include "GUIPanel.h"
class LMS7002_MainControl;
class StdCombobox;
class pnlSXT : public wxPanel, GUIPanel
{
public:
    pnlSXT(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style=0, wxString name="");
    void Initialize(LMS7002_MainControl *pControl);
    void UpdateGUI();
    void UpdateReadOnlyValues();
    virtual ~pnlSXT();

//(*Declarations(pnlSXT)
wxStaticText* StaticText10;
wxRadioBox* rgrSEL_VCO;
StdCombobox* cmbDIV_LOCH;
wxStaticText* StaticText22;
wxStaticText* StaticText9;
wxCheckBox* chkPD_VCO;
wxStaticText* StaticText20;
wxCheckBox* chkEN_SDM_TSTO;
wxStaticText* lblVCOfreq;
wxCheckBox* chkRESET_N;
wxButton* btnUpdateValues;
wxCheckBox* chkPD_CP;
StdCombobox* cmbCSW_VCO;
wxStaticText* lblRefClk_MHz;
StdCombobox* cmbCP2_PLL;
wxStaticText* StaticText13;
wxStaticText* StaticText2;
wxStaticText* StaticText14;
wxCheckBox* chkPD_FDIV;
wxStaticText* lblVCO_CMPHO;
StdCombobox* cmbTST_SX;
wxStaticText* StaticText26;
wxStaticText* StaticText6;
StdCombobox* cmbCP3_PLL;
wxStaticText* lblFRAC_SDM;
wxStaticText* lblRealOutFrequency;
wxStaticText* StaticText19;
wxStaticText* StaticText8;
wxStaticText* StaticText11;
wxStaticText* lblEN_DIV2_DIVPROG;
wxButton* btnTune;
wxStaticText* StaticText18;
StdCombobox* cmbICT_VCO;
StdCombobox* cmbPW_DIV4_LOCH;
wxStaticText* lblVCO_CMPLO;
wxStaticText* StaticText1;
wxCheckBox* chkPD_LOCH_T2RBUF;
wxStaticText* StaticText3;
wxCheckBox* chkEN_COARSEPLL;
wxCheckBox* chkEN_INTONLY_SDM;
wxStaticText* StaticText24;
wxButton* btnCalculate;
wxTextCtrl* txtFrequency;
wxCheckBox* chkEN_SDM_CLK;
wxCheckBox* chkREVPH_PFD;
wxRadioBox* rgrENDIV2_usage;
StdCombobox* cmbVDIV_VCO;
wxStaticText* StaticText5;
wxStaticText* StaticText7;
wxCheckBox* chkPD_SDM;
wxCheckBox* chkSX_DITHER_EN;
StdCombobox* cmbCZ;
wxCheckBox* chkCURLIM_VCO;
wxButton* btnShowVCO;
wxStaticText* StaticText15;
wxStaticText* StaticText12;
wxCheckBox* chkEN_DIV2_DIVPROG;
StdCombobox* cmbIPULSE_CP;
StdCombobox* cmbSEL_SDMCLK;
wxCheckBox* chkSPDUP_VCO;
wxCheckBox* chkEN_G;
wxCheckBox* chkREV_SDMCLK;
wxCheckBox* chkBYPLDO_VCO;
wxCheckBox* chkPD_VCO_COMP;
StdCombobox* cmbPW_DIV2_LOCH;
wxStaticText* StaticText17;
StdCombobox* cmbIOFFSET_CP;
wxStaticText* StaticText4;
wxStaticText* lblDivider;
wxStaticText* StaticText16;
wxStaticText* lblINT_SDM;
StdCombobox* cmbRSEL_LDO_VCO;
wxButton* btnChangeRefClk;
//*)

protected:
//(*Identifiers(pnlSXT)
static const long ID_STATICTEXT4;
static const long ID_PW_DIV2_LOCH;
static const long ID_STATICTEXT5;
static const long ID_PW_DIV4_LOCH;
static const long ID_STATICTEXT6;
static const long ID_DIV_LOCH;
static const long ID_PD_LOCH_T2RBUF;
static const long ID_PD_CP;
static const long ID_PD_FDIV;
static const long ID_PD_SDM;
static const long ID_PD_VCO_COMP;
static const long ID_PD_VCO;
static const long ID_EN_G;
static const long ID_SEL_VCO;
static const long ID_BUTTON4;
static const long ID_STATICTEXT16;
static const long ID_VCO_CMPHO;
static const long ID_STATICTEXT17;
static const long ID_VCO_CMPLO;
static const long ID_BUTTON1;
static const long ID_STATICTEXT9;
static const long ID_VDIV_VCO;
static const long ID_STATICTEXT10;
static const long ID_ICT_VCO;
static const long ID_BUTTON5;
static const long ID_STATICTEXT29;
static const long ID_STATICTEXT30;
static const long ID_RESET_N;
static const long ID_SPDUP_VCO;
static const long ID_BYPLDO_VCO;
static const long ID_EN_COARSEPLL;
static const long ID_CURLIM_VCO;
static const long ID_EN_DIV2_DIVPROG;
static const long ID_EN_INTONLY_SDM;
static const long ID_EN_SDM_CLK;
static const long ID_EN_SDM_TSTO;
static const long ID_REV_SDMCLK;
static const long ID_SX_DITHER_EN;
static const long ID_REVPH_PFD;
static const long ID_STATICTEXT7;
static const long ID_TST_SX;
static const long ID_STATICTEXT8;
static const long ID_SEL_SDMCLK;
static const long ID_STATICTEXT11;
static const long ID_RSEL_LDO_VCO;
static const long ID_STATICTEXT12;
static const long ID_IOFFSET_CP;
static const long ID_STATICTEXT13;
static const long ID_IPULSE_CP;
static const long ID_STATICTEXT18;
static const long ID_CP2_PLL;
static const long ID_STATICTEXT19;
static const long ID_CP3_PLL;
static const long ID_STATICTEXT20;
static const long ID_CZ;
static const long ID_STATICTEXT1;
static const long ID_CSW_VCO;
static const long ID_TEXTCTRL1;
static const long ID_BUTTON2;
static const long ID_BUTTON3;
static const long ID_RADIOBOX1;
static const long ID_STATICTEXT2;
static const long ID_STATICTEXT3;
static const long ID_STATICTEXT21;
static const long ID_STATICTEXT22;
static const long ID_STATICTEXT23;
static const long ID_STATICTEXT24;
static const long ID_STATICTEXT25;
static const long ID_STATICTEXT26;
static const long ID_STATICTEXT27;
static const long ID_STATICTEXT28;
static const long ID_STATICTEXT14;
static const long ID_STATICTEXT15;
//*)

private:
//(*Handlers(pnlSXT)
    void ParameterChangeHandler(wxCommandEvent& event);
void OnbtnUpdateValuesClick(wxCommandEvent& event);
void OnbtnCalculateClick(wxCommandEvent& event);
void OnbtnTuneClick(wxCommandEvent& event);
void OnbtnShowVCOClick(wxCommandEvent& event);
void OnbtnChangeRefClkClick(wxCommandEvent& event);
//*)

protected:
    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);
    void AssignEnumsToIds();
    DECLARE_EVENT_TABLE()
};
#endif
