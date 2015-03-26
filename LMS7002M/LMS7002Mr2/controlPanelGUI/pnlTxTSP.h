// -----------------------------------------------------------------------------
// FILE: 		pnlTxTSP.cpp
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef pnlTxTSP_H
#define pnlTxTSP_H
//(*Headers(pnlTxTSP)
#include <wx/panel.h>
class wxCheckBox;
class wxComboBox;
class wxRadioBox;
class wxStaticText;
class wxFlexGridSizer;
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
class pnlTxTSP : public wxPanel, GUIPanel
{
public:
    pnlTxTSP(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style=0, wxString name="");
    void Initialize(LMS7002_MainControl *pControl);
    void UpdateGUI();
    virtual ~pnlTxTSP();

//(*Declarations(pnlTxTSP)
wxStaticText* StaticText10;
StdCombobox* cmbIQCORR_TXTSP;
wxStaticText* StaticText9;
wxRadioBox* rgrOFC;
wxStaticText* txtPhaseAlpha;
StdCombobox* cmbHBI_OVR_TXTSP;
StdCombobox* cmbDCCORRI_TXTSP;
wxFlexGridSizer* sizerNCOgrid;
wxCheckBox* chkGC_BYP_TXTSP;
wxCheckBox* chkISINC_BYP_TXTSP;
wxStaticText* StaticText13;
wxStaticText* lblBSIGI_TXTSP;
wxStaticText* StaticText2;
wxStaticText* StaticText14;
wxStaticText* StaticText6;
StdCombobox* cmbGFIR3_L_TXTSP;
StdCombobox* cmbGFIR2_N_TXTSP;
wxStaticText* lblBSIGQ_TXTSP;
wxCheckBox* chkBSTART_TXTSP;
wxStaticText* StaticText19;
wxStaticText* StaticText8;
wxStaticText* StaticText0;
wxStaticText* StaticText11;
wxStaticText* StaticText18;
wxCheckBox* chkGFIR2_BYP_TXTSP;
wxCheckBox* chkEN_TXTSP;
wxStaticText* StaticText1;
wxStaticText* StaticText3;
wxButton* btnUploadNCO;
StdCombobox* cmbGFIR1_L_TXTSP;
StdCombobox* cmbGCORRI_TXTSP;
wxButton* btnLoadGFIR3Coef;
wxCheckBox* chkDC_BYP_TXTSP;
wxStaticText* lblRefClk;
wxButton* btnSetRefClk;
wxStaticText* StaticText5;
StdCombobox* cmbDCCORRQ_TXTSP;
wxStaticText* StaticText7;
StdCombobox* cmbGFIR3_N_TXTSP;
wxCheckBox* chkPH_BYP_TXTSP;
wxCheckBox* chkGFIR1_BYP_TXTSP;
wxCheckBox* chkGFIR3_BYP_TXTSP;
wxStaticText* StaticText15;
wxButton* btnReadBIST;
wxStaticText* StaticText12;
StdCombobox* cmbGFIR2_L_TXTSP;
StdCombobox* cmbGFIR1_N_TXTSP;
wxButton* btnLoadGFIR2Coef;
wxRadioBox* rgrMODE;
wxButton* btnLoadGFIR1Coef;
wxStaticText* StaticText17;
wxStaticText* StaticText4;
StdCombobox* cmbGCORRQ_TXTSP;
wxStaticText* StaticText16;
wxCheckBox* chkCMIX_P6DB_TXTSP;
wxCheckBox* chkCMIX_BYP_TXTSP;
wxStaticText* lblBSTATE_TXTSP;
//*)

protected:
//(*Identifiers(pnlTxTSP)
static const long ID_STATICTEXT2;
static const long ID_BSTATE_TXTSP;
static const long ID_STATICTEXT1;
static const long ID_BSIGI_TXTSP;
static const long ID_STATICTEXT3;
static const long ID_BSIGQ_TXTSP;
static const long ID_BSTART_TXTSP;
static const long ID_BUTTON2;
static const long ID_STATICTEXT4;
static const long ID_GCORRQ_TXTSP;
static const long ID_STATICTEXT5;
static const long ID_GCORRI_TXTSP;
static const long ID_STATICTEXT6;
static const long ID_IQCORR_TXTSP;
static const long ID_STATICTEXT16;
static const long ID_STATICTEXT17;
static const long ID_STATICTEXT8;
static const long ID_DCCORRI_TXTSP;
static const long ID_STATICTEXT9;
static const long ID_DCCORRQ_TXTSP;
static const long ID_STATICTEXT7;
static const long ID_HBI_OVR_TXTSP;
static const long ID_CMIX_BYP_TXTSP;
static const long ID_ISINC_BYP_TXTSP;
static const long ID_GFIR3_BYP_TXTSP;
static const long ID_GFIR2_BYP_TXTSP;
static const long ID_GFIR1_BYP_TXTSP;
static const long ID_DC_BYP_TXTSP;
static const long ID_GC_BYP_TXTSP;
static const long ID_PH_BYP_TXTSP;
static const long ID_STATICTEXT10;
static const long ID_GFIR1_L_TXTSP;
static const long ID_STATICTEXT11;
static const long ID_GFIR1_N_TXTSP;
static const long ID_BUTTON3;
static const long ID_STATICTEXT12;
static const long ID_GFIR2_L_TXTSP;
static const long ID_STATICTEXT13;
static const long ID_GFIR2_N_TXTSP;
static const long ID_BUTTON4;
static const long ID_STATICTEXT14;
static const long ID_GFIR3_L_TXTSP;
static const long ID_STATICTEXT15;
static const long ID_GFIR3_N_TXTSP;
static const long ID_BUTTON5;
static const long ID_EN_TXTSP;
static const long ID_CMIX_P6DB_TXTSP;
static const long ID_MODE_TX;
static const long ID_OFC;
static const long ID_STATICTEXT18;
static const long ID_STATICTEXT19;
static const long ID_STATICTEXT20;
static const long ID_BUTTON1;
static const long ID_BUTTON6;
static const long ID_STATICTEXT21;
static const long ID_STATICTEXT22;
//*)

private:
//(*Handlers(pnlTxTSP)
    void ParameterChangeHandler(wxCommandEvent& event);
void OnbtnReadBISTClick(wxCommandEvent& event);
void OnbtnLoadGFIR1CoefClick(wxCommandEvent& event);
void OnbtnLoadGFIR2CoefClick(wxCommandEvent& event);
void OnbtnLoadGFIR3CoefClick(wxCommandEvent& event);
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
