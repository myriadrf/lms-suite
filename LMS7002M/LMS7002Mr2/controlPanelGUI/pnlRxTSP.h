// -----------------------------------------------------------------------------
// FILE: 		pnlRxTSP.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef pnlRxTSP_H
#define pnlRxTSP_H
//(*Headers(pnlRxTSP)
#include <wx/panel.h>
class wxSpinEvent;
class wxCheckBox;
class wxComboBox;
class wxRadioBox;
class wxStaticText;
class wxFlexGridSizer;
class wxSpinCtrl;
class wxButton;
class wxStaticBoxSizer;
//*)
class wxTextCtrl;
class wxRadioButton;
#include <map>
#include "RegistersMap.h"
#include "GUIPanel.h"
class LMS7002_MainControl;
class StdCombobox;
class pnlRxTSP : public wxPanel, GUIPanel
{
public:
    pnlRxTSP(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style=0, wxString name="");
    void Initialize(LMS7002_MainControl *pControl);
    void UpdateGUI();
    virtual ~pnlRxTSP();

//(*Declarations(pnlRxTSP)
wxStaticText* StaticText10;
wxStaticText* StaticText22;
wxStaticText* StaticText9;
wxStaticText* StaticText20;
wxRadioBox* rgrOFC;
wxStaticText* txtPhaseAlpha;
wxButton* btnReadRSSI;
wxCheckBox* chkEN_RXTSP;
wxFlexGridSizer* sizerNCOgrid;
wxStaticText* StaticText13;
wxStaticText* StaticText2;
wxStaticText* StaticText14;
wxStaticText* StaticText6;
StdCombobox* cmbAGC_ADESIRED_RXTSP;
StdCombobox* cmbGFIR3_N_RXTSP;
wxStaticText* StaticText19;
wxStaticText* StaticText0;
wxStaticText* StaticText8;
wxStaticText* StaticText11;
wxCheckBox* chkDC_BYP_RXTSP;
wxStaticText* StaticText18;
StdCombobox* cmbGCORRI_RXTSP;
wxButton* btnReadBist;
StdCombobox* cmbGFIR1_N_RXTSP;
StdCombobox* cmbGFIR2_L_RXTSP;
wxStaticText* StaticText1;
wxStaticText* StaticText3;
wxButton* btnUploadNCO;
StdCombobox* cmbGFIR3_L_RXTSP;
wxStaticText* StaticText21;
wxCheckBox* chkGC_BYP_RXTSP;
StdCombobox* cmbIQCORR_RXTSP;
wxStaticText* lblBSTATE_RXTSP;
wxButton* btnLoadGFIR3Coef;
wxRadioBox* rgrAGC_MODE_RXTSP;
StdCombobox* cmbGFIR1_L_RXTSP;
StdCombobox* cmbGCORRQ_RXTSP;
wxStaticText* lblRefClk;
wxButton* btnSetRefClk;
wxCheckBox* chkGFIR2_BYP_RXTSP;
wxStaticText* StaticText5;
wxStaticText* StaticText7;
StdCombobox* cmbHBD_OVR_RXTSP;
StdCombobox* cmbAGC_AVG_RXTSP;
wxCheckBox* chkGFIR1_BYP_RXTSP;
wxCheckBox* chkBSTART_RXTSP;
wxStaticText* StaticText15;
wxStaticText* StaticText12;
StdCombobox* cmbGFIR2_N_RXTSP;
wxStaticText* lblRSSI_RXTSP;
wxCheckBox* chkCMIX_P6DB_RXTSP;
wxButton* btnLoadGFIR2Coef;
wxRadioBox* rgrMODE;
wxButton* btnLoadGFIR1Coef;
wxStaticText* StaticText17;
wxStaticText* StaticText4;
wxCheckBox* chkGFIR3_BYP_RXTSP;
wxCheckBox* chkAGC_BYP_RXTSP;
wxSpinCtrl* spinAGC_K_RXTSP;
wxCheckBox* chkPH_BYP_RXTSP;
wxStaticText* StaticText16;
wxStaticText* lblBSIGQ_RXTSP;
wxCheckBox* chkCMIX_BYP_RXTSP;
StdCombobox* cmbDCCORR_AVG_RXTSP;
wxStaticText* lblBSIGI_RXTSP;
//*)

protected:
//(*Identifiers(pnlRxTSP)
static const long ID_STATICTEXT6;
static const long ID_BSTATE_RXTSP;
static const long ID_STATICTEXT5;
static const long ID_BSIGI_RXTSP;
static const long ID_STATICTEXT7;
static const long ID_BSIGQ_RXTSP;
static const long ID_BSTART_RXTSP;
static const long ID_BUTTON1;
static const long ID_STATICTEXT8;
static const long ID_GCORRQ_RXTSP;
static const long ID_STATICTEXT9;
static const long ID_GCORRI_RXTSP;
static const long ID_STATICTEXT10;
static const long ID_IQCORR_RXTSP;
static const long ID_STATICTEXT19;
static const long ID_STATICTEXT20;
static const long ID_STATICTEXT12;
static const long ID_DCCORR_AVG_RXTSP;
static const long ID_STATICTEXT11;
static const long ID_HBD_OVR_RXTSP;
static const long ID_CMIX_BYP_RXTSP;
static const long ID_AGC_BYP_RXTSP;
static const long ID_GFIR3_BYP_RXTSP;
static const long ID_GFIR2_BYP_RXTSP;
static const long ID_GFIR1_BYP_RXTSP;
static const long ID_DC_BYP_RXTSP;
static const long ID_GC_BYP_RXTSP;
static const long ID_PH_BYP_RXTSP;
static const long ID_STATICTEXT13;
static const long ID_GFIR1_L_RXTSP;
static const long ID_STATICTEXT14;
static const long ID_GFIR1_N_RXTSP;
static const long ID_BUTTON2;
static const long ID_STATICTEXT15;
static const long ID_GFIR2_L_RXTSP;
static const long ID_STATICTEXT16;
static const long ID_GFIR2_N_RXTSP;
static const long ID_BUTTON3;
static const long ID_STATICTEXT17;
static const long ID_GFIR3_L_RXTSP;
static const long ID_STATICTEXT18;
static const long ID_GFIR3_N_RXTSP;
static const long ID_BUTTON4;
static const long ID_EN_RXTSP;
static const long ID_CMIX_P6DB_RXTSP;
static const long ID_STATICTEXT1;
static const long ID_AGC_K_RXTSP;
static const long ID_STATICTEXT3;
static const long ID_AGC_AVG_RXTSP;
static const long ID_STATICTEXT2;
static const long ID_AGC_ADESIRED_RXTSP;
static const long ID_AGC_MODE_RXTSP;
static const long ID_STATICTEXT4;
static const long ID_RSSI_RXTSP;
static const long ID_BUTTON5;
static const long ID_MODE_RX;
static const long ID_OFC;
static const long ID_STATICTEXT21;
static const long ID_STATICTEXT22;
static const long ID_STATICTEXT23;
static const long ID_BUTTON6;
static const long ID_BUTTON7;
static const long ID_STATICTEXT24;
static const long ID_STATICTEXT25;
//*)

private:
//(*Handlers(pnlRxTSP)
    void ParameterChangeHandler(wxCommandEvent& event);
void OnspinAGC_K_RXTSPChange(wxSpinEvent& event);
void OnbtnLoadGFIR1CoefClick(wxCommandEvent& event);
void OnbtnLoadGFIR2CoefClick(wxCommandEvent& event);
void OnbtnLoadGFIR3CoefClick(wxCommandEvent& event);
void OnbtnReadBistClick(wxCommandEvent& event);
void OnbtnReadRSSIClick(wxCommandEvent& event);
void OnbtnUploadNCOClick(wxCommandEvent& event);
void OnrgrSELSelect(wxCommandEvent& event);
void OnbtnSetRefClkClick(wxCommandEvent& event);
void OnPHOAngleChanged(wxCommandEvent& event);
//*)

protected:
    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);
    void AssignEnumsToIds();
    void InitializeNCOgrid();
    void SetNCOgrid(const vector<double> &FCW, const vector<int> &PHO);
    wxString coefFilenames[3];
    vector<wxTextCtrl*> fcwFields;
    vector<wxTextCtrl*> phoFields;
    vector<wxRadioButton*> ncoRadioButtons;
    vector<wxStaticText*> phoAngles;
    DECLARE_EVENT_TABLE()
};
#endif
