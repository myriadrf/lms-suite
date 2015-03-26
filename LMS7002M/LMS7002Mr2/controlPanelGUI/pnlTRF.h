// -----------------------------------------------------------------------------
// FILE: 		pnlTRF.cpp
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef pnlTRF_H
#define pnlTRF_H
//(*Headers(pnlTRF)
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
class pnlTRF : public wxPanel, GUIPanel
{
public:
    pnlTRF(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style=0, wxString name="");
    void Initialize(LMS7002_MainControl *pControl);
    void UpdateGUI();
    virtual ~pnlTRF();

//(*Declarations(pnlTRF)
wxStaticText* StaticText10;
wxStaticText* StaticText9;
wxRadioBox* rgrGCAS_GNDREF_TXPAD_TRF;
wxCheckBox* chkPD_PDET_TRF;
StdCombobox* cmbICT_MAIN_TXPAD_TRF;
StdCombobox* cmbLOADR_PDET_TRF;
StdCombobox* cmbEN_LOWBWLOMX_TMX_TRF;
wxStaticText* StaticText2;
wxCheckBox* chkSEL_BAND1_TRF;
StdCombobox* cmbLOBIASP_TXX_TRF;
StdCombobox* cmbLOSS_LIN_TXPAD_TRF;
StdCombobox* cmbEN_AMPHF_PDET_TRF;
wxStaticText* StaticText6;
wxStaticText* StaticText8;
wxStaticText* StaticText0;
wxStaticText* StaticText11;
wxCheckBox* chkSEL_BAND2_TRF;
wxStaticText* StaticText1;
wxCheckBox* chkPD_TLOBUF_TRF;
wxStaticText* StaticText3;
wxCheckBox* chkPD_TXPAD_TRF;
StdCombobox* cmbEN_NEXTTX_TRF;
StdCombobox* cmbF_TXPAD_TRF;
wxStaticText* StaticText5;
wxStaticText* StaticText7;
wxCheckBox* chkEN_LOOPB_TXPAD_TRF;
StdCombobox* cmbLOSS_MAIN_TXPAD_TRF;
StdCombobox* cmbL_LOOPB_TXPAD_TRF;
wxStaticText* StaticText12;
StdCombobox* cmbVGCAS_TXPAD_TRF;
wxCheckBox* chkEN_G_TRF;
wxStaticText* StaticText4;
StdCombobox* cmbLOBIASN_TXM_TRF;
StdCombobox* cmbICT_LIN_TXPAD_TRF;
//*)

protected:
//(*Identifiers(pnlTRF)
static const long ID_STATICTEXT1;
static const long ID_EN_LOWBWLOMX_TMX_TRF;
static const long ID_STATICTEXT2;
static const long ID_EN_NEXTTX_TRF;
static const long ID_STATICTEXT3;
static const long ID_EN_AMPHF_PDET_TRF;
static const long ID_STATICTEXT4;
static const long ID_F_TXPAD_TRF;
static const long ID_STATICTEXT5;
static const long ID_L_LOOPB_TXPAD_TRF;
static const long ID_STATICTEXT6;
static const long ID_LOSS_LIN_TXPAD_TRF;
static const long ID_STATICTEXT7;
static const long ID_LOSS_MAIN_TXPAD_TRF;
static const long ID_STATICTEXT8;
static const long ID_VGCAS_TXPAD_TRF;
static const long ID_STATICTEXT9;
static const long ID_LOBIASN_TXM_TRF;
static const long ID_STATICTEXT10;
static const long ID_LOBIASP_TXX_TRF;
static const long ID_SEL_BAND1_TRF;
static const long ID_SEL_BAND2_TRF;
static const long ID_EN_LOOPB_TXPAD_TRF;
static const long ID_STATICTEXT11;
static const long ID_LOADR_PDET_TRF;
static const long ID_STATICTEXT12;
static const long ID_ICT_LIN_TXPAD_TRF;
static const long ID_STATICTEXT13;
static const long ID_ICT_MAIN_TXPAD_TRF;
static const long ID_PD_PDET_TRF;
static const long ID_PD_TLOBUF_TRF;
static const long ID_PD_TXPAD_TRF;
static const long ID_EN_G_TRF;
static const long ID_GCAS_GNDREF_TXPAD_TRF;
//*)

private:
//(*Handlers(pnlTRF)
    void ParameterChangeHandler(wxCommandEvent& event);
//*)

protected:
    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);
    void AssignEnumsToIds();
    DECLARE_EVENT_TABLE()
};
#endif
