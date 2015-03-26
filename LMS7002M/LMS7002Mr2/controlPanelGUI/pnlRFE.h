// -----------------------------------------------------------------------------
// FILE: 		pnlRFE.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef pnlRFE_H
#define pnlRFE_H
//(*Headers(pnlRFE)
#include <wx/panel.h>
class wxCheckBox;
class wxComboBox;
class wxRadioBox;
class wxStaticText;
class wxFlexGridSizer;
class wxStaticBoxSizer;
//*)
#include <map>
#include "RegistersMap.h"
#include "GUIPanel.h"
class LMS7002_MainControl;
class StdCombobox;
class pnlRFE : public wxPanel, GUIPanel
{
public:
    pnlRFE(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style=0, wxString name="");
    void Initialize(LMS7002_MainControl *pControl);
    void UpdateGUI();
    virtual ~pnlRFE();

//(*Declarations(pnlRFE)
wxStaticText* StaticText10;
wxStaticText* StaticText9;
wxRadioBox* rgrEN_NEXTRX_RFE;
StdCombobox* cmbRCOMP_TIA_RFE;
wxCheckBox* chkPD_RLOOPB_1_RFE;
wxCheckBox* chkPD_RLOOPB_2_RFE;
StdCombobox* cmbDCOFFQ_RFE;
StdCombobox* cmbCAP_RXMXO_RFE;
StdCombobox* cmbG_LNA_RFE;
StdCombobox* cmbCGSIN_LNA_RFE;
wxStaticText* StaticText13;
wxStaticText* StaticText2;
wxCheckBox* chkEN_INSHSW_H_RFE;
StdCombobox* cmbICT_LOOPB_RFE;
wxStaticText* StaticText14;
StdCombobox* cmbDCOFFI_RFE;
wxCheckBox* chkEN_INSHSW_LB1_RFE;
wxStaticText* StaticText6;
wxCheckBox* chkPD_TIA_RFE;
wxCheckBox* chkEN_G_RFE;
StdCombobox* cmbICT_LODC_RFE;
StdCombobox* cmbCFB_TIA_RFE;
wxStaticText* StaticText8;
wxStaticText* StaticText0;
wxStaticText* StaticText11;
wxCheckBox* chkPD_QGEN_RFE;
StdCombobox* cmbG_TIA_RFE;
wxStaticText* StaticText1;
StdCombobox* cmbICT_LNACMO_RFE;
wxStaticText* StaticText3;
wxCheckBox* chkPD_RSSI_RFE;
wxCheckBox* chkEN_INSHSW_W_RFE;
wxStaticText* StaticText5;
wxStaticText* StaticText7;
StdCombobox* cmbG_RXLOOPB_RFE;
wxCheckBox* chkPD_LNA_RFE;
StdCombobox* cmbCCOMP_TIA_RFE;
StdCombobox* cmbICT_LNA_RFE;
wxCheckBox* chkEN_DCOFF_RXFE_RFE;
wxStaticText* StaticText15;
wxStaticText* StaticText12;
wxCheckBox* chkPD_MXLOBUF_RFE;
StdCombobox* cmbSEL_PATH_RFE;
StdCombobox* cmbRFB_TIA_RFE;
wxStaticText* StaticText17;
StdCombobox* cmbICT_TIAOUT_RFE;
wxStaticText* StaticText4;
wxCheckBox* chkEN_INSHSW_LB2_RFE;
wxCheckBox* chkEN_INSHSW_L_RFE;
wxStaticText* StaticText16;
StdCombobox* cmbICT_TIAMAIN_RFE;
//*)

protected:
//(*Identifiers(pnlRFE)
static const long ID_PD_LNA_RFE;
static const long ID_PD_RLOOPB_1_RFE;
static const long ID_PD_RLOOPB_2_RFE;
static const long ID_PD_MXLOBUF_RFE;
static const long ID_PD_QGEN_RFE;
static const long ID_PD_RSSI_RFE;
static const long ID_PD_TIA_RFE;
static const long ID_EN_G_RFE;
static const long ID_STATICTEXT1;
static const long ID_SEL_PATH_RFE;
static const long ID_STATICTEXT2;
static const long ID_CAP_RXMXO_RFE;
static const long ID_STATICTEXT3;
static const long ID_CGSIN_LNA_RFE;
static const long ID_STATICTEXT4;
static const long ID_RCOMP_TIA_RFE;
static const long ID_STATICTEXT5;
static const long ID_RFB_TIA_RFE;
static const long ID_EN_NEXTRX_RFE;
static const long ID_EN_INSHSW_H_RFE;
static const long ID_EN_INSHSW_LB1_RFE;
static const long ID_EN_INSHSW_LB2_RFE;
static const long ID_EN_INSHSW_L_RFE;
static const long ID_EN_INSHSW_W_RFE;
static const long ID_STATICTEXT6;
static const long ID_DCOFFI_RFE;
static const long ID_STATICTEXT7;
static const long ID_DCOFFQ_RFE;
static const long ID_STATICTEXT8;
static const long ID_ICT_LODC_RFE;
static const long ID_EN_DCOFF_RXFE_RFE;
static const long ID_STATICTEXT9;
static const long ID_ICT_LOOPB_RFE;
static const long ID_STATICTEXT10;
static const long ID_ICT_TIAMAIN_RFE;
static const long ID_STATICTEXT11;
static const long ID_ICT_TIAOUT_RFE;
static const long ID_STATICTEXT12;
static const long ID_ICT_LNACMO_RFE;
static const long ID_STATICTEXT13;
static const long ID_ICT_LNA_RFE;
static const long ID_STATICTEXT14;
static const long ID_CCOMP_TIA_RFE;
static const long ID_STATICTEXT15;
static const long ID_CFB_TIA_RFE;
static const long ID_STATICTEXT16;
static const long ID_G_LNA_RFE;
static const long ID_STATICTEXT17;
static const long ID_G_RXLOOPB_RFE;
static const long ID_STATICTEXT18;
static const long ID_G_TIA_RFE;
//*)

private:
//(*Handlers(pnlRFE)
    void ParameterChangeHandler(wxCommandEvent& event);
//*)

protected:
    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);
    void AssignEnumsToIds();
    DECLARE_EVENT_TABLE()
};
#endif
