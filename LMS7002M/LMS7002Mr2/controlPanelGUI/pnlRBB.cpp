// -----------------------------------------------------------------------------
// FILE: 		pnlRBB.cpp
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#include "pnlRBB.h"
#include <iostream>
#include "StdCombobox.h"
#include "LMS7002_MainControl.h"
//(*InternalHeaders(pnlRBB)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/intl.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/combobox.h>
//*)
//(*IdInit(pnlRBB)
const long pnlRBB::ID_EN_LB_LPFH_RBB = wxNewId();
const long pnlRBB::ID_EN_LB_LPFL_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT1 = wxNewId();
const long pnlRBB::ID_INPUT_CTL_PGA_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT2 = wxNewId();
const long pnlRBB::ID_G_PGA_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT3 = wxNewId();
const long pnlRBB::ID_C_CTL_PGA_RBB = wxNewId();
const long pnlRBB::ID_OSW_PGA_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT4 = wxNewId();
const long pnlRBB::ID_R_CTL_LPF_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT5 = wxNewId();
const long pnlRBB::ID_C_CTL_LPFH_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT6 = wxNewId();
const long pnlRBB::ID_C_CTL_LPFL_RBB = wxNewId();
const long pnlRBB::ID_PD_LPFH_RBB = wxNewId();
const long pnlRBB::ID_PD_LPFL_RBB = wxNewId();
const long pnlRBB::ID_PD_PGA_RBB = wxNewId();
const long pnlRBB::ID_EN_G_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT7 = wxNewId();
const long pnlRBB::ID_RCC_CTL_LPFH_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT8 = wxNewId();
const long pnlRBB::ID_RCC_CTL_LPFL_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT9 = wxNewId();
const long pnlRBB::ID_ICT_LPF_IN_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT10 = wxNewId();
const long pnlRBB::ID_ICT_LPF_OUT_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT11 = wxNewId();
const long pnlRBB::ID_ICT_PGA_OUT_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT12 = wxNewId();
const long pnlRBB::ID_ICT_PGA_IN_RBB = wxNewId();
const long pnlRBB::ID_STATICTEXT13 = wxNewId();
const long pnlRBB::ID_RCC_CTL_PGA_RBB = wxNewId();
const long pnlRBB::ID_BUTTON1 = wxNewId();
const long pnlRBB::ID_BUTTON2 = wxNewId();
//*)
BEGIN_EVENT_TABLE(pnlRBB,wxPanel)
//(*EventTable(pnlRBB)
//*)
END_EVENT_TABLE()

void pnlRBB::AssignEnumsToIds()
{
    wndId2Enum[ID_C_CTL_LPFH_RBB] = C_CTL_LPFH_RBB;
    wndId2Enum[ID_C_CTL_LPFL_RBB] = C_CTL_LPFL_RBB;
    wndId2Enum[ID_C_CTL_PGA_RBB] = C_CTL_PGA_RBB;
    wndId2Enum[ID_EN_G_RBB] = EN_G_RBB;
    wndId2Enum[ID_EN_LB_LPFH_RBB] = EN_LB_LPFH_RBB;
    wndId2Enum[ID_EN_LB_LPFL_RBB] = EN_LB_LPFL_RBB;
    wndId2Enum[ID_G_PGA_RBB] = G_PGA_RBB;
    wndId2Enum[ID_ICT_LPF_IN_RBB] = ICT_LPF_IN_RBB;
    wndId2Enum[ID_ICT_LPF_OUT_RBB] = ICT_LPF_OUT_RBB;
    wndId2Enum[ID_ICT_PGA_IN_RBB] = ICT_PGA_IN_RBB;
    wndId2Enum[ID_ICT_PGA_OUT_RBB] = ICT_PGA_OUT_RBB;
    wndId2Enum[ID_INPUT_CTL_PGA_RBB] = INPUT_CTL_PGA_RBB;
    wndId2Enum[ID_OSW_PGA_RBB] = OSW_PGA_RBB;
    wndId2Enum[ID_PD_LPFH_RBB] = PD_LPFH_RBB;
    wndId2Enum[ID_PD_LPFL_RBB] = PD_LPFL_RBB;
    wndId2Enum[ID_PD_PGA_RBB] = PD_PGA_RBB;
    wndId2Enum[ID_RCC_CTL_LPFH_RBB] = RCC_CTL_LPFH_RBB;
    wndId2Enum[ID_RCC_CTL_LPFL_RBB] = RCC_CTL_LPFL_RBB;
    wndId2Enum[ID_RCC_CTL_PGA_RBB] = RCC_CTL_PGA_RBB;
    wndId2Enum[ID_R_CTL_LPF_RBB] = R_CTL_LPF_RBB;
}

pnlRBB::pnlRBB(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, int style, wxString name)
{
    lmsControl = NULL;
    BuildContent(parent,id,pos,size);
    AssignEnumsToIds();
}
void pnlRBB::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
//(*Initialize(pnlRBB)
wxFlexGridSizer* Powerdowncontrols2Sizer;
wxStaticBoxSizer* OperationalamplifierSizer;
wxFlexGridSizer* UNGROUPED1Sizer;
wxStaticBoxSizer* UNGROUPEDSizer;
wxFlexGridSizer* RCtimeconstant3Sizer;
wxStaticBoxSizer* PowerdowncontrolsSizer;
wxStaticBoxSizer* StaticBoxSizer1;
wxFlexGridSizer* FlexGridSizer1;
wxStaticBoxSizer* RCtimeconstantSizer;
wxFlexGridSizer* Operationalamplifier4Sizer;

Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 5);
UNGROUPEDSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("UNGROUPED"));
UNGROUPED1Sizer = new wxFlexGridSizer(0, 2, 0, 0);
chkEN_LB_LPFH_RBB = new wxCheckBox(this, ID_EN_LB_LPFH_RBB, _("EN_LB_LPFH_RBB"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_EN_LB_LPFH_RBB"));
chkEN_LB_LPFH_RBB->SetValue(false);
chkEN_LB_LPFH_RBB->SetToolTip(_("This is the loopback enable signal that is enabled when high band LPFH&RBB is selected for the loopback path that connects the loopb&lpfi inputs to the virtual ground of the LPFH&RBB block"));
UNGROUPED1Sizer->Add(chkEN_LB_LPFH_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkEN_LB_LPFL_RBB = new wxCheckBox(this, ID_EN_LB_LPFL_RBB, _("EN_LB_LPFL_RBB"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_EN_LB_LPFL_RBB"));
chkEN_LB_LPFL_RBB->SetValue(false);
chkEN_LB_LPFL_RBB->SetToolTip(_("This is the loopback enable signal that is enabled when the high-band low pass filter LPFL&RBB is selected for the loopback path that connects the loopb&lpf inputs to the virtual ground of the LPFL&RBB block"));
UNGROUPED1Sizer->Add(chkEN_LB_LPFL_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText0 = new wxStaticText(this, ID_STATICTEXT1, _("PGA input"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
UNGROUPED1Sizer->Add(StaticText0, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbINPUT_CTL_PGA_RBB = new StdCombobox(this, ID_INPUT_CTL_PGA_RBB, wxEmptyString, wxDefaultPosition, wxSize(160,21), 0, 0, 0, wxDefaultValidator, _T("ID_INPUT_CTL_PGA_RBB"));
cmbINPUT_CTL_PGA_RBB->SetToolTip(_("There are a total of four different differential inputs to the PGA. Only one of them is active at a time"));
UNGROUPED1Sizer->Add(cmbINPUT_CTL_PGA_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText1 = new wxStaticText(this, ID_STATICTEXT2, _("PGA gain"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
UNGROUPED1Sizer->Add(StaticText1, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbG_PGA_RBB = new StdCombobox(this, ID_G_PGA_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_G_PGA_RBB"));
cmbG_PGA_RBB->SetToolTip(_("This is the gain of the PGA"));
UNGROUPED1Sizer->Add(cmbG_PGA_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText2 = new wxStaticText(this, ID_STATICTEXT3, _("PGA Feedback capacitor"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
UNGROUPED1Sizer->Add(StaticText2, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbC_CTL_PGA_RBB = new StdCombobox(this, ID_C_CTL_PGA_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_C_CTL_PGA_RBB"));
cmbC_CTL_PGA_RBB->SetToolTip(_("Control the value of the feedback capacitor of the PGA that is used to help against the parasitic cap at the virtual node for stability"));
UNGROUPED1Sizer->Add(cmbC_CTL_PGA_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
wxString __wxRadioBoxChoices_1[2] =
{
	_("ADC"),
	_("output pads")
};
rgrOSW_PGA_RBB = new wxRadioBox(this, ID_OSW_PGA_RBB, _("PGA connected to"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_1, 1, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_OSW_PGA_RBB"));
rgrOSW_PGA_RBB->SetSelection(0);
rgrOSW_PGA_RBB->SetToolTip(_("There are two instances of the PGA circuit in the design. The output of the RBB&LPF blocks are connected the input of these PGA blocks (common). The output of one of them is connected to two pads pgaoutn and pgaoutp and the output of the other PGA is connected directly to the ADC input"));
UNGROUPED1Sizer->Add(rgrOSW_PGA_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
UNGROUPEDSizer->Add(UNGROUPED1Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer1->Add(UNGROUPEDSizer, 0, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
RCtimeconstantSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("RC time constant"));
RCtimeconstant3Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText3 = new wxStaticText(this, ID_STATICTEXT4, _("Resistance"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
RCtimeconstant3Sizer->Add(StaticText3, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbR_CTL_LPF_RBB = new StdCombobox(this, ID_R_CTL_LPF_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_R_CTL_LPF_RBB"));
cmbR_CTL_LPF_RBB->SetToolTip(_("Controls the absolute value of the resistance of the RC time constant of the RBB&LPF blocks (both Low and High)"));
RCtimeconstant3Sizer->Add(cmbR_CTL_LPF_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText4 = new wxStaticText(this, ID_STATICTEXT5, _("Capacitance of RC time constant (rxMode from 37MHz to 108MHz)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
RCtimeconstant3Sizer->Add(StaticText4, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbC_CTL_LPFH_RBB = new StdCombobox(this, ID_C_CTL_LPFH_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_C_CTL_LPFH_RBB"));
cmbC_CTL_LPFH_RBB->SetToolTip(_("Controls the capacitance value of the RC time constant of RBB&LPFH and it varies with the respective rxMode from 37MHz to 108MHz"));
RCtimeconstant3Sizer->Add(cmbC_CTL_LPFH_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText5 = new wxStaticText(this, ID_STATICTEXT6, _("Capacitance of RC time constant (rxMode from 1.4MHz to 20MHz)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
RCtimeconstant3Sizer->Add(StaticText5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbC_CTL_LPFL_RBB = new StdCombobox(this, ID_C_CTL_LPFL_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_C_CTL_LPFL_RBB"));
cmbC_CTL_LPFL_RBB->SetToolTip(_("Controls the capacitance value of the RC time constant of RBB&LPFH and it varies with the respective rxMode from 1.4MHz to 20MHz."));
RCtimeconstant3Sizer->Add(cmbC_CTL_LPFL_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
RCtimeconstantSizer->Add(RCtimeconstant3Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer1->Add(RCtimeconstantSizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 0);
PowerdowncontrolsSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Power down controls"));
Powerdowncontrols2Sizer = new wxFlexGridSizer(0, 1, 0, 0);
chkPD_LPFH_RBB = new wxCheckBox(this, ID_PD_LPFH_RBB, _("LPFH block"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_PD_LPFH_RBB"));
chkPD_LPFH_RBB->SetValue(false);
chkPD_LPFH_RBB->SetToolTip(_("Power down of the LPFH block"));
Powerdowncontrols2Sizer->Add(chkPD_LPFH_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkPD_LPFL_RBB = new wxCheckBox(this, ID_PD_LPFL_RBB, _("LPFL block"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_PD_LPFL_RBB"));
chkPD_LPFL_RBB->SetValue(false);
chkPD_LPFL_RBB->SetToolTip(_("Power down of the LPFL block"));
Powerdowncontrols2Sizer->Add(chkPD_LPFL_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkPD_PGA_RBB = new wxCheckBox(this, ID_PD_PGA_RBB, _("PGA block"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_PD_PGA_RBB"));
chkPD_PGA_RBB->SetValue(false);
chkPD_PGA_RBB->SetToolTip(_("Power down of the PGA block"));
Powerdowncontrols2Sizer->Add(chkPD_PGA_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkEN_G_RBB = new wxCheckBox(this, ID_EN_G_RBB, _("Enable individual power downs"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_EN_G_RBB"));
chkEN_G_RBB->SetValue(false);
chkEN_G_RBB->SetToolTip(_("Enable control for all the RBB&1 power downs"));
Powerdowncontrols2Sizer->Add(chkEN_G_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
PowerdowncontrolsSizer->Add(Powerdowncontrols2Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer1->Add(PowerdowncontrolsSizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
OperationalamplifierSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Operational amplifier"));
Operationalamplifier4Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText6 = new wxStaticText(this, ID_STATICTEXT7, _("Stability passive compensation"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
Operationalamplifier4Sizer->Add(StaticText6, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbRCC_CTL_LPFH_RBB = new StdCombobox(this, ID_RCC_CTL_LPFH_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_RCC_CTL_LPFH_RBB"));
cmbRCC_CTL_LPFH_RBB->SetToolTip(_("Controls the stability passive compensation of the LPFH&RBB operational amplifier"));
Operationalamplifier4Sizer->Add(cmbRCC_CTL_LPFH_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText7 = new wxStaticText(this, ID_STATICTEXT8, _("Stability passive compensation"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
Operationalamplifier4Sizer->Add(StaticText7, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbRCC_CTL_LPFL_RBB = new StdCombobox(this, ID_RCC_CTL_LPFL_RBB, wxEmptyString, wxDefaultPosition, wxSize(157,21), 0, 0, 0, wxDefaultValidator, _T("ID_RCC_CTL_LPFL_RBB"));
cmbRCC_CTL_LPFL_RBB->SetToolTip(_("Controls the stability passive compensation of the LPFL&RBB operational amplifier."));
Operationalamplifier4Sizer->Add(cmbRCC_CTL_LPFL_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText8 = new wxStaticText(this, ID_STATICTEXT9, _("Input stage reference bias current (RBB_LPF)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
Operationalamplifier4Sizer->Add(StaticText8, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbICT_LPF_IN_RBB = new StdCombobox(this, ID_ICT_LPF_IN_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ICT_LPF_IN_RBB"));
cmbICT_LPF_IN_RBB->SetToolTip(_("Controls the reference bias current of the input stage of the operational amplifier used in RBB&LPF blocks (Low or High). "));
Operationalamplifier4Sizer->Add(cmbICT_LPF_IN_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText9 = new wxStaticText(this, ID_STATICTEXT10, _("Output stage reference bias current (RBB_LPF)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
Operationalamplifier4Sizer->Add(StaticText9, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbICT_LPF_OUT_RBB = new StdCombobox(this, ID_ICT_LPF_OUT_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ICT_LPF_OUT_RBB"));
cmbICT_LPF_OUT_RBB->SetToolTip(_("the reference bias current of the output stage of the operational amplifier used in RBB&LPF blocks (low or High)"));
Operationalamplifier4Sizer->Add(cmbICT_LPF_OUT_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText10 = new wxStaticText(this, ID_STATICTEXT11, _("Output stage reference bias current (PGA)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
Operationalamplifier4Sizer->Add(StaticText10, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbICT_PGA_OUT_RBB = new StdCombobox(this, ID_ICT_PGA_OUT_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ICT_PGA_OUT_RBB"));
cmbICT_PGA_OUT_RBB->SetToolTip(_("Controls the output stage reference bias current of the operational amplifier used in the PGA circuit"));
Operationalamplifier4Sizer->Add(cmbICT_PGA_OUT_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText11 = new wxStaticText(this, ID_STATICTEXT12, _("Input stage reference bias current (PGA)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
Operationalamplifier4Sizer->Add(StaticText11, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbICT_PGA_IN_RBB = new StdCombobox(this, ID_ICT_PGA_IN_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ICT_PGA_IN_RBB"));
cmbICT_PGA_IN_RBB->SetToolTip(_("Controls the input stage reference bias current of the operational amplifier used in the PGA circuit"));
Operationalamplifier4Sizer->Add(cmbICT_PGA_IN_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText12 = new wxStaticText(this, ID_STATICTEXT13, _("Stability passive compensation"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
Operationalamplifier4Sizer->Add(StaticText12, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbRCC_CTL_PGA_RBB = new StdCombobox(this, ID_RCC_CTL_PGA_RBB, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_RCC_CTL_PGA_RBB"));
cmbRCC_CTL_PGA_RBB->SetToolTip(_("Controls the stability passive compensation of the PGA&RBB operational amplifier"));
Operationalamplifier4Sizer->Add(cmbRCC_CTL_PGA_RBB, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
OperationalamplifierSizer->Add(Operationalamplifier4Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer1->Add(OperationalamplifierSizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Calibration"));
btnCalibrateLowBand = new wxButton(this, ID_BUTTON1, _("Calibrate LowBand"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
StaticBoxSizer1->Add(btnCalibrateLowBand, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
btnCalibrateHighBand = new wxButton(this, ID_BUTTON2, _("Calibrate HighBand"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
StaticBoxSizer1->Add(btnCalibrateHighBand, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALIGN_LEFT|wxALIGN_TOP, 5);
SetSizer(FlexGridSizer1);
FlexGridSizer1->Fit(this);
FlexGridSizer1->SetSizeHints(this);

Connect(ID_EN_LB_LPFH_RBB,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_EN_LB_LPFL_RBB,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_INPUT_CTL_PGA_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_G_PGA_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_C_CTL_PGA_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_OSW_PGA_RBB,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_R_CTL_LPF_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_C_CTL_LPFH_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_C_CTL_LPFL_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_PD_LPFH_RBB,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_PD_LPFL_RBB,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_PD_PGA_RBB,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_EN_G_RBB,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_RCC_CTL_LPFH_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_RCC_CTL_LPFL_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_ICT_LPF_IN_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_ICT_LPF_OUT_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_ICT_PGA_OUT_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_ICT_PGA_IN_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_RCC_CTL_PGA_RBB,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRBB::ParameterChangeHandler);
Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pnlRBB::OnbtnCalibrateLowBandClick);
Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pnlRBB::OnbtnCalibrateHighBandClick);
//*)
}
pnlRBB::~pnlRBB()
{
//(*Destroy(pnlRBB)
//*)
}
void pnlRBB::ParameterChangeHandler(wxCommandEvent& event)
{
    if(lmsControl == NULL)
    {
        std::cout << "pnlRBB panel don't have control module assigned" << std::endl;
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

void pnlRBB::Initialize(LMS7002_MainControl *pControl)
{
    lmsControl = pControl;
    char ctemp[80];
    vector<string> temp;
    temp.clear();
    for(int i=0; i<256; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbC_CTL_LPFH_RBB->Clear();
    cmbC_CTL_LPFH_RBB->Append(temp);
    cmbC_CTL_LPFH_RBB->SetSelection( lmsControl->GetParam(C_CTL_LPFH_RBB));

    temp.clear();
    for(int i=0; i<2048; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbC_CTL_LPFL_RBB->Clear();
    cmbC_CTL_LPFL_RBB->Append(temp);
    cmbC_CTL_LPFL_RBB->SetSelection( lmsControl->GetParam(C_CTL_LPFL_RBB));

    temp.clear();
    for(int i=0; i<512; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbC_CTL_PGA_RBB->Clear();
    cmbC_CTL_PGA_RBB->Append(temp);
    cmbC_CTL_PGA_RBB->SetSelection( lmsControl->GetParam(C_CTL_PGA_RBB));

    temp.clear();
    for(int i=0; i<32; ++i)
        {sprintf(ctemp, "%i dB", -12+i); temp.push_back(ctemp);}
    cmbG_PGA_RBB->Clear();
    cmbG_PGA_RBB->Append(temp);
    cmbG_PGA_RBB->SetSelection( lmsControl->GetParam(G_PGA_RBB));

    temp.clear();
    for(int i=0; i<32; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbICT_LPF_IN_RBB->Clear();
    cmbICT_LPF_IN_RBB->Append(temp);
    cmbICT_LPF_IN_RBB->SetSelection( lmsControl->GetParam(ICT_LPF_IN_RBB));

    temp.clear();
    for(int i=0; i<32; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbICT_LPF_OUT_RBB->Clear();
    cmbICT_LPF_OUT_RBB->Append(temp);
    cmbICT_LPF_OUT_RBB->SetSelection( lmsControl->GetParam(ICT_LPF_OUT_RBB));

    temp.clear();
    for(int i=0; i<32; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbICT_PGA_IN_RBB->Clear();
    cmbICT_PGA_IN_RBB->Append(temp);
    cmbICT_PGA_IN_RBB->SetSelection( lmsControl->GetParam(ICT_PGA_IN_RBB));

    temp.clear();
    for(int i=0; i<32; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbICT_PGA_OUT_RBB->Clear();
    cmbICT_PGA_OUT_RBB->Append(temp);
    cmbICT_PGA_OUT_RBB->SetSelection( lmsControl->GetParam(ICT_PGA_OUT_RBB));

    temp.clear();
    temp.push_back("LPFL_RBB block as input");
    temp.push_back("LPFH_RBB as input");
    temp.push_back("LPF bypass");
    temp.push_back("loopback from TX");
    temp.push_back("loopback path from peak detector");
    cmbINPUT_CTL_PGA_RBB->Clear();
    cmbINPUT_CTL_PGA_RBB->Append(temp);
    cmbINPUT_CTL_PGA_RBB->SetSelection( lmsControl->GetParam(INPUT_CTL_PGA_RBB));

    temp.clear();
    for(int i=0; i<8; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbRCC_CTL_LPFH_RBB->Clear();
    cmbRCC_CTL_LPFH_RBB->Append(temp);
    cmbRCC_CTL_LPFH_RBB->SetSelection( lmsControl->GetParam(RCC_CTL_LPFH_RBB));

    temp.clear();
    temp.push_back("when rxMode is 1.4MHz");
    temp.push_back("when 3MHz");
    temp.push_back("when 5MHz");
    temp.push_back("when 10MHz");
    temp.push_back("when 15MHz");
    temp.push_back("when 20MHz");
    cmbRCC_CTL_LPFL_RBB->Clear();
    cmbRCC_CTL_LPFL_RBB->Append(temp);
    cmbRCC_CTL_LPFL_RBB->SetSelection( lmsControl->GetParam(RCC_CTL_LPFL_RBB));

    temp.clear();
    for(int i=0; i<32; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbRCC_CTL_PGA_RBB->Clear();
    cmbRCC_CTL_PGA_RBB->Append(temp);
    cmbRCC_CTL_PGA_RBB->SetSelection( lmsControl->GetParam(RCC_CTL_PGA_RBB));

    temp.clear();
    for(int i=0; i<32; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbR_CTL_LPF_RBB->Clear();
    cmbR_CTL_LPF_RBB->Append(temp);
    cmbR_CTL_LPF_RBB->SetSelection( lmsControl->GetParam(R_CTL_LPF_RBB));
    UpdateTooltips(this);
}

void pnlRBB::UpdateGUI()
{
    //GetParent()->Freeze();
    long value = 0;
    value = lmsControl->GetParam(C_CTL_LPFH_RBB);
    cmbC_CTL_LPFH_RBB->SetSelection(value);

    value = lmsControl->GetParam(C_CTL_LPFL_RBB);
    cmbC_CTL_LPFL_RBB->SetSelection(value);

    value = lmsControl->GetParam(C_CTL_PGA_RBB);
    cmbC_CTL_PGA_RBB->SetSelection(value);

    value = lmsControl->GetParam(EN_G_RBB);
    chkEN_G_RBB->SetValue(value);

    value = lmsControl->GetParam(EN_LB_LPFH_RBB);
    chkEN_LB_LPFH_RBB->SetValue(value);

    value = lmsControl->GetParam(EN_LB_LPFL_RBB);
    chkEN_LB_LPFL_RBB->SetValue(value);

    value = lmsControl->GetParam(G_PGA_RBB);
    cmbG_PGA_RBB->SetSelection(value);

    value = lmsControl->GetParam(ICT_LPF_IN_RBB);
    cmbICT_LPF_IN_RBB->SetSelection(value);

    value = lmsControl->GetParam(ICT_LPF_OUT_RBB);
    cmbICT_LPF_OUT_RBB->SetSelection(value);

    value = lmsControl->GetParam(ICT_PGA_IN_RBB);
    cmbICT_PGA_IN_RBB->SetSelection(value);

    value = lmsControl->GetParam(ICT_PGA_OUT_RBB);
    cmbICT_PGA_OUT_RBB->SetSelection(value);

    value = lmsControl->GetParam(INPUT_CTL_PGA_RBB);
    cmbINPUT_CTL_PGA_RBB->SetSelection(value);

    value = lmsControl->GetParam(OSW_PGA_RBB);
    rgrOSW_PGA_RBB->SetSelection(value);

    value = lmsControl->GetParam(PD_LPFH_RBB);
    chkPD_LPFH_RBB->SetValue(value);

    value = lmsControl->GetParam(PD_LPFL_RBB);
    chkPD_LPFL_RBB->SetValue(value);

    value = lmsControl->GetParam(PD_PGA_RBB);
    chkPD_PGA_RBB->SetValue(value);

    value = lmsControl->GetParam(RCC_CTL_LPFH_RBB);
    cmbRCC_CTL_LPFH_RBB->SetSelection(value);

    value = lmsControl->GetParam(RCC_CTL_LPFL_RBB);
    cmbRCC_CTL_LPFL_RBB->SetSelection(value);

    value = lmsControl->GetParam(RCC_CTL_PGA_RBB);
    cmbRCC_CTL_PGA_RBB->SetSelection(value);

    value = lmsControl->GetParam(R_CTL_LPF_RBB);
    cmbR_CTL_LPF_RBB->SetSelection(value);

    //GetParent()->Thaw();
}


void pnlRBB::OnbtnCalibrateLowBandClick(wxCommandEvent& event)
{
    lmsControl->algorithms->Calibration_LowBand_RBB(lmsControl->GetConfigChannel());
}

void pnlRBB::OnbtnCalibrateHighBandClick(wxCommandEvent& event)
{
    lmsControl->algorithms->Calibration_HighBand_RBB(lmsControl->GetConfigChannel());
}
