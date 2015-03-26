// -----------------------------------------------------------------------------
// FILE: 		pnlTRF.cpp
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#include "pnlTRF.h"
#include <iostream>
#include "StdCombobox.h"
#include "LMS7002_MainControl.h"
//(*InternalHeaders(pnlTRF)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/combobox.h>
//*)
//(*IdInit(pnlTRF)
const long pnlTRF::ID_STATICTEXT1 = wxNewId();
const long pnlTRF::ID_EN_LOWBWLOMX_TMX_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT2 = wxNewId();
const long pnlTRF::ID_EN_NEXTTX_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT3 = wxNewId();
const long pnlTRF::ID_EN_AMPHF_PDET_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT4 = wxNewId();
const long pnlTRF::ID_F_TXPAD_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT5 = wxNewId();
const long pnlTRF::ID_L_LOOPB_TXPAD_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT6 = wxNewId();
const long pnlTRF::ID_LOSS_LIN_TXPAD_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT7 = wxNewId();
const long pnlTRF::ID_LOSS_MAIN_TXPAD_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT8 = wxNewId();
const long pnlTRF::ID_VGCAS_TXPAD_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT9 = wxNewId();
const long pnlTRF::ID_LOBIASN_TXM_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT10 = wxNewId();
const long pnlTRF::ID_LOBIASP_TXX_TRF = wxNewId();
const long pnlTRF::ID_SEL_BAND1_TRF = wxNewId();
const long pnlTRF::ID_SEL_BAND2_TRF = wxNewId();
const long pnlTRF::ID_EN_LOOPB_TXPAD_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT11 = wxNewId();
const long pnlTRF::ID_LOADR_PDET_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT12 = wxNewId();
const long pnlTRF::ID_ICT_LIN_TXPAD_TRF = wxNewId();
const long pnlTRF::ID_STATICTEXT13 = wxNewId();
const long pnlTRF::ID_ICT_MAIN_TXPAD_TRF = wxNewId();
const long pnlTRF::ID_PD_PDET_TRF = wxNewId();
const long pnlTRF::ID_PD_TLOBUF_TRF = wxNewId();
const long pnlTRF::ID_PD_TXPAD_TRF = wxNewId();
const long pnlTRF::ID_EN_G_TRF = wxNewId();
const long pnlTRF::ID_GCAS_GNDREF_TXPAD_TRF = wxNewId();
//*)
BEGIN_EVENT_TABLE(pnlTRF,wxPanel)
//(*EventTable(pnlTRF)
//*)
END_EVENT_TABLE()

void pnlTRF::AssignEnumsToIds()
{
    wndId2Enum[ID_EN_AMPHF_PDET_TRF] = EN_AMPHF_PDET_TRF;
    wndId2Enum[ID_EN_G_TRF] = EN_G_TRF;
    wndId2Enum[ID_EN_LOOPB_TXPAD_TRF] = EN_LOOPB_TXPAD_TRF;
    wndId2Enum[ID_EN_LOWBWLOMX_TMX_TRF] = EN_LOWBWLOMX_TMX_TRF;
    wndId2Enum[ID_EN_NEXTTX_TRF] = EN_NEXTTX_TRF;
    wndId2Enum[ID_F_TXPAD_TRF] = F_TXPAD_TRF;
    wndId2Enum[ID_GCAS_GNDREF_TXPAD_TRF] = GCAS_GNDREF_TXPAD_TRF;
    wndId2Enum[ID_ICT_LIN_TXPAD_TRF] = ICT_LIN_TXPAD_TRF;
    wndId2Enum[ID_ICT_MAIN_TXPAD_TRF] = ICT_MAIN_TXPAD_TRF;
    wndId2Enum[ID_LOADR_PDET_TRF] = LOADR_PDET_TRF;
    wndId2Enum[ID_LOBIASN_TXM_TRF] = LOBIASN_TXM_TRF;
    wndId2Enum[ID_LOBIASP_TXX_TRF] = LOBIASP_TXX_TRF;
    wndId2Enum[ID_LOSS_LIN_TXPAD_TRF] = LOSS_LIN_TXPAD_TRF;
    wndId2Enum[ID_LOSS_MAIN_TXPAD_TRF] = LOSS_MAIN_TXPAD_TRF;
    wndId2Enum[ID_L_LOOPB_TXPAD_TRF] = L_LOOPB_TXPAD_TRF;
    wndId2Enum[ID_PD_PDET_TRF] = PD_PDET_TRF;
    wndId2Enum[ID_PD_TLOBUF_TRF] = PD_TLOBUF_TRF;
    wndId2Enum[ID_PD_TXPAD_TRF] = PD_TXPAD_TRF;
    wndId2Enum[ID_SEL_BAND1_TRF] = SEL_BAND1_TRF;
    wndId2Enum[ID_SEL_BAND2_TRF] = SEL_BAND2_TRF;
    wndId2Enum[ID_VGCAS_TXPAD_TRF] = VGCAS_TXPAD_TRF;
}

pnlTRF::pnlTRF(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, int style, wxString name)
{
    lmsControl = NULL;
    BuildContent(parent,id,pos,size);
    AssignEnumsToIds();
}
void pnlTRF::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
//(*Initialize(pnlTRF)
wxFlexGridSizer* FlexGridSizer2;
wxFlexGridSizer* UNGROUPED1Sizer;
wxFlexGridSizer* Biascurrent4Sizer;
wxStaticBoxSizer* UNGROUPEDSizer;
wxFlexGridSizer* Powerdowncontrols3Sizer;
wxStaticBoxSizer* PowerdetectorSizer;
wxFlexGridSizer* Powerdetector2Sizer;
wxStaticBoxSizer* BiascurrentSizer;
wxStaticBoxSizer* PowerdowncontrolsSizer;
wxFlexGridSizer* FlexGridSizer1;

Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 5);
UNGROUPEDSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("UNGROUPED"));
UNGROUPED1Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText0 = new wxStaticText(this, ID_STATICTEXT1, _("High pass pole freqency"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
UNGROUPED1Sizer->Add(StaticText0, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbEN_LOWBWLOMX_TMX_TRF = new StdCombobox(this, ID_EN_LOWBWLOMX_TMX_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_EN_LOWBWLOMX_TMX_TRF"));
cmbEN_LOWBWLOMX_TMX_TRF->SetToolTip(_("Controls the high pass pole frequency of the RC biasing the gate of the mixer switches"));
UNGROUPED1Sizer->Add(cmbEN_LOWBWLOMX_TMX_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText1 = new wxStaticText(this, ID_STATICTEXT2, _("Enable daisy chain LO buffer"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
UNGROUPED1Sizer->Add(StaticText1, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbEN_NEXTTX_TRF = new StdCombobox(this, ID_EN_NEXTTX_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_EN_NEXTTX_TRF"));
cmbEN_NEXTTX_TRF->SetToolTip(_("Enables the daisy change LO buffer going from TRF&1 to TRF2"));
UNGROUPED1Sizer->Add(cmbEN_NEXTTX_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText2 = new wxStaticText(this, ID_STATICTEXT3, _("Enable TXPAD power detector preamplifier"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
UNGROUPED1Sizer->Add(StaticText2, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbEN_AMPHF_PDET_TRF = new StdCombobox(this, ID_EN_AMPHF_PDET_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_EN_AMPHF_PDET_TRF"));
cmbEN_AMPHF_PDET_TRF->SetToolTip(_("Enables the TXPAD power detector preamplifier"));
UNGROUPED1Sizer->Add(cmbEN_AMPHF_PDET_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText3 = new wxStaticText(this, ID_STATICTEXT4, _("Switched capacitor at TXPAD output"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
UNGROUPED1Sizer->Add(StaticText3, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbF_TXPAD_TRF = new StdCombobox(this, ID_F_TXPAD_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_F_TXPAD_TRF"));
cmbF_TXPAD_TRF->SetToolTip(_("controls the switched capacitor at the TXPAD output. Is used for tine tuning of the TXPAD output"));
UNGROUPED1Sizer->Add(cmbF_TXPAD_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText4 = new wxStaticText(this, ID_STATICTEXT5, _("Loss of loopback path at TX side"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
UNGROUPED1Sizer->Add(StaticText4, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbL_LOOPB_TXPAD_TRF = new StdCombobox(this, ID_L_LOOPB_TXPAD_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_L_LOOPB_TXPAD_TRF"));
cmbL_LOOPB_TXPAD_TRF->SetToolTip(_("Controls the loss of the of the loopback path at the TX side"));
UNGROUPED1Sizer->Add(cmbL_LOOPB_TXPAD_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText5 = new wxStaticText(this, ID_STATICTEXT6, _("TXPAD linearizing part gain"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
UNGROUPED1Sizer->Add(StaticText5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbLOSS_LIN_TXPAD_TRF = new StdCombobox(this, ID_LOSS_LIN_TXPAD_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LOSS_LIN_TXPAD_TRF"));
cmbLOSS_LIN_TXPAD_TRF->SetToolTip(_("Controls the gain of the linearizing part of of the TXPAD"));
UNGROUPED1Sizer->Add(cmbLOSS_LIN_TXPAD_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText6 = new wxStaticText(this, ID_STATICTEXT7, _("TXPAD gain and output power"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
UNGROUPED1Sizer->Add(StaticText6, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbLOSS_MAIN_TXPAD_TRF = new StdCombobox(this, ID_LOSS_MAIN_TXPAD_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LOSS_MAIN_TXPAD_TRF"));
cmbLOSS_MAIN_TXPAD_TRF->SetToolTip(_("Controls the gain  output power of the TXPAD"));
UNGROUPED1Sizer->Add(cmbLOSS_MAIN_TXPAD_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText7 = new wxStaticText(this, ID_STATICTEXT8, _("Bias voltage at gate of TXPAD cascade"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
UNGROUPED1Sizer->Add(StaticText7, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbVGCAS_TXPAD_TRF = new StdCombobox(this, ID_VGCAS_TXPAD_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_VGCAS_TXPAD_TRF"));
cmbVGCAS_TXPAD_TRF->SetToolTip(_("Controls the bias voltage at the gate of TXPAD cascade"));
UNGROUPED1Sizer->Add(cmbVGCAS_TXPAD_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText8 = new wxStaticText(this, ID_STATICTEXT9, _("Bias at gate of mixer NMOS"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
UNGROUPED1Sizer->Add(StaticText8, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbLOBIASN_TXM_TRF = new StdCombobox(this, ID_LOBIASN_TXM_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LOBIASN_TXM_TRF"));
cmbLOBIASN_TXM_TRF->SetToolTip(_("Controls the bias at the gate of the mixer NMOS"));
UNGROUPED1Sizer->Add(cmbLOBIASN_TXM_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText9 = new wxStaticText(this, ID_STATICTEXT10, _("Bias at gate of mixer PMOS"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
UNGROUPED1Sizer->Add(StaticText9, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbLOBIASP_TXX_TRF = new StdCombobox(this, ID_LOBIASP_TXX_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_LOBIASP_TXX_TRF"));
cmbLOBIASP_TXX_TRF->SetToolTip(_("Controls the bias at the gate of the mixer PMOS"));
UNGROUPED1Sizer->Add(cmbLOBIASP_TXX_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkSEL_BAND1_TRF = new wxCheckBox(this, ID_SEL_BAND1_TRF, _("Enable signal for TXFE, band 1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SEL_BAND1_TRF"));
chkSEL_BAND1_TRF->SetValue(false);
chkSEL_BAND1_TRF->SetToolTip(_("Enable signal for TXFE, band 1"));
UNGROUPED1Sizer->Add(chkSEL_BAND1_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkSEL_BAND2_TRF = new wxCheckBox(this, ID_SEL_BAND2_TRF, _("Enable signal for TXFE, band 2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SEL_BAND2_TRF"));
chkSEL_BAND2_TRF->SetValue(false);
chkSEL_BAND2_TRF->SetToolTip(_("Enable signal for TXFE, band 2"));
UNGROUPED1Sizer->Add(chkSEL_BAND2_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkEN_LOOPB_TXPAD_TRF = new wxCheckBox(this, ID_EN_LOOPB_TXPAD_TRF, _("Enable TXPAD loopback path"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_EN_LOOPB_TXPAD_TRF"));
chkEN_LOOPB_TXPAD_TRF->SetValue(false);
chkEN_LOOPB_TXPAD_TRF->SetToolTip(_("Enables the TXPAD loopback path"));
UNGROUPED1Sizer->Add(chkEN_LOOPB_TXPAD_TRF, 0, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 0);
UNGROUPEDSizer->Add(UNGROUPED1Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer1->Add(UNGROUPEDSizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
PowerdetectorSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Power detector"));
Powerdetector2Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText10 = new wxStaticText(this, ID_STATICTEXT11, _("Resistive load"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
Powerdetector2Sizer->Add(StaticText10, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbLOADR_PDET_TRF = new StdCombobox(this, ID_LOADR_PDET_TRF, wxEmptyString, wxDefaultPosition, wxSize(160,21), 0, 0, 0, wxDefaultValidator, _T("ID_LOADR_PDET_TRF"));
cmbLOADR_PDET_TRF->SetToolTip(_("Controls the resistive load of the Power detector"));
Powerdetector2Sizer->Add(cmbLOADR_PDET_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
PowerdetectorSizer->Add(Powerdetector2Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer2->Add(PowerdetectorSizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
BiascurrentSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Bias current"));
Biascurrent4Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText11 = new wxStaticText(this, ID_STATICTEXT12, _("Linearization section"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
Biascurrent4Sizer->Add(StaticText11, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbICT_LIN_TXPAD_TRF = new StdCombobox(this, ID_ICT_LIN_TXPAD_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ICT_LIN_TXPAD_TRF"));
cmbICT_LIN_TXPAD_TRF->SetToolTip(_("Control the bias current of the linearization section of the TXPAD"));
Biascurrent4Sizer->Add(cmbICT_LIN_TXPAD_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText12 = new wxStaticText(this, ID_STATICTEXT13, _("Main gm section"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
Biascurrent4Sizer->Add(StaticText12, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbICT_MAIN_TXPAD_TRF = new StdCombobox(this, ID_ICT_MAIN_TXPAD_TRF, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ICT_MAIN_TXPAD_TRF"));
cmbICT_MAIN_TXPAD_TRF->SetToolTip(_("Control the bias current of the main gm section of the TXPAD"));
Biascurrent4Sizer->Add(cmbICT_MAIN_TXPAD_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
BiascurrentSizer->Add(Biascurrent4Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer2->Add(BiascurrentSizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
PowerdowncontrolsSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Power down controls"));
Powerdowncontrols3Sizer = new wxFlexGridSizer(0, 1, 0, 0);
chkPD_PDET_TRF = new wxCheckBox(this, ID_PD_PDET_TRF, _("Power detector"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_PD_PDET_TRF"));
chkPD_PDET_TRF->SetValue(false);
chkPD_PDET_TRF->SetToolTip(_("Powerdown signal for Power Detector"));
Powerdowncontrols3Sizer->Add(chkPD_PDET_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkPD_TLOBUF_TRF = new wxCheckBox(this, ID_PD_TLOBUF_TRF, _("TX LO buffer"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_PD_TLOBUF_TRF"));
chkPD_TLOBUF_TRF->SetValue(false);
chkPD_TLOBUF_TRF->SetToolTip(_("Powerdown signal for TX LO buffer"));
Powerdowncontrols3Sizer->Add(chkPD_TLOBUF_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkPD_TXPAD_TRF = new wxCheckBox(this, ID_PD_TXPAD_TRF, _("TXPAD"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_PD_TXPAD_TRF"));
chkPD_TXPAD_TRF->SetValue(false);
chkPD_TXPAD_TRF->SetToolTip(_("Powerdown signal for TXPAD"));
Powerdowncontrols3Sizer->Add(chkPD_TXPAD_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkEN_G_TRF = new wxCheckBox(this, ID_EN_G_TRF, _("Enable individual power downs"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_EN_G_TRF"));
chkEN_G_TRF->SetValue(false);
chkEN_G_TRF->SetToolTip(_("Enable control for all the TRF&1 power downs"));
Powerdowncontrols3Sizer->Add(chkEN_G_TRF, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
PowerdowncontrolsSizer->Add(Powerdowncontrols3Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer2->Add(PowerdowncontrolsSizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
wxString __wxRadioBoxChoices_1[2] =
{
	_("VDD"),
	_("GNDS")
};
rgrGCAS_GNDREF_TXPAD_TRF = new wxRadioBox(this, ID_GCAS_GNDREF_TXPAD_TRF, _("TXPAD cascode transistor gate bias"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 2, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_GCAS_GNDREF_TXPAD_TRF"));
rgrGCAS_GNDREF_TXPAD_TRF->SetSelection(0);
rgrGCAS_GNDREF_TXPAD_TRF->SetToolTip(_("Controls if the TXPAD cascode transistor gate bias is referred to VDD or GND"));
FlexGridSizer2->Add(rgrGCAS_GNDREF_TXPAD_TRF, 1, wxALIGN_LEFT|wxALIGN_TOP, 5);
FlexGridSizer1->Add(FlexGridSizer2, 1, wxALIGN_LEFT|wxALIGN_TOP, 5);
SetSizer(FlexGridSizer1);
FlexGridSizer1->Fit(this);
FlexGridSizer1->SetSizeHints(this);

Connect(ID_EN_LOWBWLOMX_TMX_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_EN_NEXTTX_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_EN_AMPHF_PDET_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_F_TXPAD_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_L_LOOPB_TXPAD_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_LOSS_LIN_TXPAD_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_LOSS_MAIN_TXPAD_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_VGCAS_TXPAD_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_LOBIASN_TXM_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_LOBIASP_TXX_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_SEL_BAND1_TRF,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_SEL_BAND2_TRF,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_EN_LOOPB_TXPAD_TRF,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_LOADR_PDET_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_ICT_LIN_TXPAD_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_ICT_MAIN_TXPAD_TRF,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_PD_PDET_TRF,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_PD_TLOBUF_TRF,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_PD_TXPAD_TRF,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_EN_G_TRF,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
Connect(ID_GCAS_GNDREF_TXPAD_TRF,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&pnlTRF::ParameterChangeHandler);
//*)
}
pnlTRF::~pnlTRF()
{
//(*Destroy(pnlTRF)
//*)
}
void pnlTRF::ParameterChangeHandler(wxCommandEvent& event)
{
    if(lmsControl == NULL)
    {
        std::cout << "pnlTRF panel don't have control module assigned" << std::endl;
        return;
    }

    LMS7002_Parameter parameter;
    try
    {
        parameter = wndId2Enum.at(event.GetId());
    }
    catch( std::exception & e )
    {
        std::cout << "Control element(ID = " << event.GetId() << ") don't have assigned LMS parameter enumeration." << std::endl;
        return;
    }
    switch(parameter)
    {
    default:
        lmsControl->SetParam( parameter, event.GetInt());
        //std::cout << "control id " << event.GetId() << " value " << event.GetInt() << std::endl;
    }
}

void pnlTRF::Initialize(LMS7002_MainControl *pControl)
{
    lmsControl = pControl;
    char ctemp[80];
    vector<string> temp;
    temp.clear();
    for(int i=0; i<4; ++i)
{sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbEN_AMPHF_PDET_TRF->Clear();
    cmbEN_AMPHF_PDET_TRF->Append(temp);
    cmbEN_AMPHF_PDET_TRF->SetSelection( lmsControl->GetParam(EN_AMPHF_PDET_TRF));

    temp.clear();
    temp.push_back("High band - bias resisotr 3K");
    temp.push_back("Low band -bias resistor 30K");
    cmbEN_LOWBWLOMX_TMX_TRF->Clear();
    cmbEN_LOWBWLOMX_TMX_TRF->Append(temp);
    cmbEN_LOWBWLOMX_TMX_TRF->SetSelection( lmsControl->GetParam(EN_LOWBWLOMX_TMX_TRF));

    temp.clear();
    temp.push_back("Buffer disabled (SISO)");
    temp.push_back("Buffer enalbed(MIMO)");
    cmbEN_NEXTTX_TRF->Clear();
    cmbEN_NEXTTX_TRF->Append(temp);
    cmbEN_NEXTTX_TRF->SetSelection( lmsControl->GetParam(EN_NEXTTX_TRF));

    temp.clear();
    for(int i=0; i<8; ++i)
{sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbF_TXPAD_TRF->Clear();
    cmbF_TXPAD_TRF->Append(temp);
    cmbF_TXPAD_TRF->SetSelection( lmsControl->GetParam(F_TXPAD_TRF));

    temp.clear();
    for(int i=0; i<32; ++i)
{sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbICT_LIN_TXPAD_TRF->Clear();
    cmbICT_LIN_TXPAD_TRF->Append(temp);
    cmbICT_LIN_TXPAD_TRF->SetSelection( lmsControl->GetParam(ICT_LIN_TXPAD_TRF));

    temp.clear();
    for(int i=0; i<32; ++i)
{sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbICT_MAIN_TXPAD_TRF->Clear();
    cmbICT_MAIN_TXPAD_TRF->Append(temp);
    cmbICT_MAIN_TXPAD_TRF->SetSelection( lmsControl->GetParam(ICT_MAIN_TXPAD_TRF));

    temp.clear();
    temp.push_back("R_DIFF 5K||2.5K||1.25K");
    temp.push_back("R_DIFF 5K||1.25K");
    temp.push_back("R_DIFF 5K||2.5K");
    temp.push_back("R_DIFF 5K");
    cmbLOADR_PDET_TRF->Clear();
    cmbLOADR_PDET_TRF->Append(temp);
    cmbLOADR_PDET_TRF->SetSelection( lmsControl->GetParam(LOADR_PDET_TRF));

    temp.clear();
    for(int i=0; i<32; ++i)
{sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbLOBIASN_TXM_TRF->Clear();
    cmbLOBIASN_TXM_TRF->Append(temp);
    cmbLOBIASN_TXM_TRF->SetSelection( lmsControl->GetParam(LOBIASN_TXM_TRF));

    temp.clear();
    for(int i=0; i<32; ++i)
{sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbLOBIASP_TXX_TRF->Clear();
    cmbLOBIASP_TXX_TRF->Append(temp);
    cmbLOBIASP_TXX_TRF->SetSelection( lmsControl->GetParam(LOBIASP_TXX_TRF));

    temp.clear();
    for(int i=0; i<32; ++i)
{sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbLOSS_LIN_TXPAD_TRF->Clear();
    cmbLOSS_LIN_TXPAD_TRF->Append(temp);
    cmbLOSS_LIN_TXPAD_TRF->SetSelection( lmsControl->GetParam(LOSS_LIN_TXPAD_TRF));

    temp.clear();
    for(int i=0; i<32; ++i)
{sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbLOSS_MAIN_TXPAD_TRF->Clear();
    cmbLOSS_MAIN_TXPAD_TRF->Append(temp);
    cmbLOSS_MAIN_TXPAD_TRF->SetSelection( lmsControl->GetParam(LOSS_MAIN_TXPAD_TRF));

    temp.clear();
    temp.push_back("Loss=0 dB");
    temp.push_back("Loss=20*log10(5)");
    temp.push_back("Loss=20*log10(11)");
    temp.push_back("Loss=20*log10(16)");
    cmbL_LOOPB_TXPAD_TRF->Clear();
    cmbL_LOOPB_TXPAD_TRF->Append(temp);
    cmbL_LOOPB_TXPAD_TRF->SetSelection( lmsControl->GetParam(L_LOOPB_TXPAD_TRF));

    temp.clear();
    for(int i=0; i<32; ++i)
{sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbVGCAS_TXPAD_TRF->Clear();
    cmbVGCAS_TXPAD_TRF->Append(temp);
    cmbVGCAS_TXPAD_TRF->SetSelection( lmsControl->GetParam(VGCAS_TXPAD_TRF));
    UpdateTooltips(this);
}

void pnlTRF::UpdateGUI()
{
    //GetParent()->Freeze();
    long value = 0;
    value = lmsControl->GetParam(EN_AMPHF_PDET_TRF);
    cmbEN_AMPHF_PDET_TRF->SetSelection(value);

    value = lmsControl->GetParam(EN_G_TRF);
    chkEN_G_TRF->SetValue(value);

    value = lmsControl->GetParam(EN_LOOPB_TXPAD_TRF);
    chkEN_LOOPB_TXPAD_TRF->SetValue(value);

    value = lmsControl->GetParam(EN_LOWBWLOMX_TMX_TRF);
    cmbEN_LOWBWLOMX_TMX_TRF->SetSelection(value);

    value = lmsControl->GetParam(EN_NEXTTX_TRF);
    cmbEN_NEXTTX_TRF->SetSelection(value);

    value = lmsControl->GetParam(F_TXPAD_TRF);
    cmbF_TXPAD_TRF->SetSelection(value);

    value = lmsControl->GetParam(GCAS_GNDREF_TXPAD_TRF);
    rgrGCAS_GNDREF_TXPAD_TRF->SetSelection(value);

    value = lmsControl->GetParam(ICT_LIN_TXPAD_TRF);
    cmbICT_LIN_TXPAD_TRF->SetSelection(value);

    value = lmsControl->GetParam(ICT_MAIN_TXPAD_TRF);
    cmbICT_MAIN_TXPAD_TRF->SetSelection(value);

    value = lmsControl->GetParam(LOADR_PDET_TRF);
    cmbLOADR_PDET_TRF->SetSelection(value);

    value = lmsControl->GetParam(LOBIASN_TXM_TRF);
    cmbLOBIASN_TXM_TRF->SetSelection(value);

    value = lmsControl->GetParam(LOBIASP_TXX_TRF);
    cmbLOBIASP_TXX_TRF->SetSelection(value);

    value = lmsControl->GetParam(LOSS_LIN_TXPAD_TRF);
    cmbLOSS_LIN_TXPAD_TRF->SetSelection(value);

    value = lmsControl->GetParam(LOSS_MAIN_TXPAD_TRF);
    cmbLOSS_MAIN_TXPAD_TRF->SetSelection(value);

    value = lmsControl->GetParam(L_LOOPB_TXPAD_TRF);
    cmbL_LOOPB_TXPAD_TRF->SetSelection(value);

    value = lmsControl->GetParam(PD_PDET_TRF);
    chkPD_PDET_TRF->SetValue(value);

    value = lmsControl->GetParam(PD_TLOBUF_TRF);
    chkPD_TLOBUF_TRF->SetValue(value);

    value = lmsControl->GetParam(PD_TXPAD_TRF);
    chkPD_TXPAD_TRF->SetValue(value);

    value = lmsControl->GetParam(SEL_BAND1_TRF);
    chkSEL_BAND1_TRF->SetValue(value);

    value = lmsControl->GetParam(SEL_BAND2_TRF);
    chkSEL_BAND2_TRF->SetValue(value);

    value = lmsControl->GetParam(VGCAS_TXPAD_TRF);
    cmbVGCAS_TXPAD_TRF->SetSelection(value);

    //GetParent()->Thaw();
}

