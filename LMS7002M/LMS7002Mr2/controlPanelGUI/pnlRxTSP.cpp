// -----------------------------------------------------------------------------
// FILE: 		pnlRxTSP.cpp
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#include "pnlRxTSP.h"
#include <iostream>
#include <math.h>
#include "StdCombobox.h"
#include "dlgFloatInput.h"
#include "LMS7002_MainControl.h"
#include "../CommonUtilities.h"
#include "dlgGFIR_Coefficients.h"
//(*InternalHeaders(pnlRxTSP)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/checkbox.h>
#include <wx/spinctrl.h>
#include <wx/intl.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/combobox.h>
//*)
//(*IdInit(pnlRxTSP)
const long pnlRxTSP::ID_STATICTEXT6 = wxNewId();
const long pnlRxTSP::ID_BSTATE_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT5 = wxNewId();
const long pnlRxTSP::ID_BSIGI_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT7 = wxNewId();
const long pnlRxTSP::ID_BSIGQ_RXTSP = wxNewId();
const long pnlRxTSP::ID_BSTART_RXTSP = wxNewId();
const long pnlRxTSP::ID_BUTTON1 = wxNewId();
const long pnlRxTSP::ID_STATICTEXT8 = wxNewId();
const long pnlRxTSP::ID_GCORRQ_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT9 = wxNewId();
const long pnlRxTSP::ID_GCORRI_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT10 = wxNewId();
const long pnlRxTSP::ID_IQCORR_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT19 = wxNewId();
const long pnlRxTSP::ID_STATICTEXT20 = wxNewId();
const long pnlRxTSP::ID_STATICTEXT12 = wxNewId();
const long pnlRxTSP::ID_DCCORR_AVG_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT11 = wxNewId();
const long pnlRxTSP::ID_HBD_OVR_RXTSP = wxNewId();
const long pnlRxTSP::ID_CMIX_BYP_RXTSP = wxNewId();
const long pnlRxTSP::ID_AGC_BYP_RXTSP = wxNewId();
const long pnlRxTSP::ID_GFIR3_BYP_RXTSP = wxNewId();
const long pnlRxTSP::ID_GFIR2_BYP_RXTSP = wxNewId();
const long pnlRxTSP::ID_GFIR1_BYP_RXTSP = wxNewId();
const long pnlRxTSP::ID_DC_BYP_RXTSP = wxNewId();
const long pnlRxTSP::ID_GC_BYP_RXTSP = wxNewId();
const long pnlRxTSP::ID_PH_BYP_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT13 = wxNewId();
const long pnlRxTSP::ID_GFIR1_L_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT14 = wxNewId();
const long pnlRxTSP::ID_GFIR1_N_RXTSP = wxNewId();
const long pnlRxTSP::ID_BUTTON2 = wxNewId();
const long pnlRxTSP::ID_STATICTEXT15 = wxNewId();
const long pnlRxTSP::ID_GFIR2_L_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT16 = wxNewId();
const long pnlRxTSP::ID_GFIR2_N_RXTSP = wxNewId();
const long pnlRxTSP::ID_BUTTON3 = wxNewId();
const long pnlRxTSP::ID_STATICTEXT17 = wxNewId();
const long pnlRxTSP::ID_GFIR3_L_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT18 = wxNewId();
const long pnlRxTSP::ID_GFIR3_N_RXTSP = wxNewId();
const long pnlRxTSP::ID_BUTTON4 = wxNewId();
const long pnlRxTSP::ID_EN_RXTSP = wxNewId();
const long pnlRxTSP::ID_CMIX_P6DB_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT1 = wxNewId();
const long pnlRxTSP::ID_AGC_K_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT3 = wxNewId();
const long pnlRxTSP::ID_AGC_AVG_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT2 = wxNewId();
const long pnlRxTSP::ID_AGC_ADESIRED_RXTSP = wxNewId();
const long pnlRxTSP::ID_AGC_MODE_RXTSP = wxNewId();
const long pnlRxTSP::ID_STATICTEXT4 = wxNewId();
const long pnlRxTSP::ID_RSSI_RXTSP = wxNewId();
const long pnlRxTSP::ID_BUTTON5 = wxNewId();
const long pnlRxTSP::ID_MODE_RX = wxNewId();
const long pnlRxTSP::ID_OFC = wxNewId();
const long pnlRxTSP::ID_STATICTEXT21 = wxNewId();
const long pnlRxTSP::ID_STATICTEXT22 = wxNewId();
const long pnlRxTSP::ID_STATICTEXT23 = wxNewId();
const long pnlRxTSP::ID_BUTTON6 = wxNewId();
const long pnlRxTSP::ID_BUTTON7 = wxNewId();
const long pnlRxTSP::ID_STATICTEXT24 = wxNewId();
const long pnlRxTSP::ID_STATICTEXT25 = wxNewId();
//*)
BEGIN_EVENT_TABLE(pnlRxTSP,wxPanel)
//(*EventTable(pnlRxTSP)
//*)
END_EVENT_TABLE()

void pnlRxTSP::AssignEnumsToIds()
{
    wndId2Enum[ID_MODE_RX] = MODE_RX;
    wndId2Enum[ID_OFC] = OFC_RX;
    wndId2Enum[ID_AGC_ADESIRED_RXTSP] = AGC_ADESIRED_RXTSP;
    wndId2Enum[ID_AGC_AVG_RXTSP] = AGC_AVG_RXTSP;
    wndId2Enum[ID_AGC_BYP_RXTSP] = AGC_BYP_RXTSP;
    wndId2Enum[ID_AGC_K_RXTSP] = AGC_K_RXTSP;
    wndId2Enum[ID_AGC_MODE_RXTSP] = AGC_MODE_RXTSP;
    wndId2Enum[ID_BSTART_RXTSP] = BSTART_RXTSP;
    wndId2Enum[ID_CMIX_BYP_RXTSP] = CMIX_BYP_RXTSP;
    wndId2Enum[ID_CMIX_P6DB_RXTSP] = CMIX_P6DB_RXTSP;
    wndId2Enum[ID_DCCORR_AVG_RXTSP] = DCCORR_AVG_RXTSP;
    wndId2Enum[ID_DC_BYP_RXTSP] = DC_BYP_RXTSP;
    wndId2Enum[ID_EN_RXTSP] = EN_RXTSP;
    wndId2Enum[ID_GCORRI_RXTSP] = GCORRI_RXTSP;
    wndId2Enum[ID_GCORRQ_RXTSP] = GCORRQ_RXTSP;
    wndId2Enum[ID_GC_BYP_RXTSP] = GC_BYP_RXTSP;
    wndId2Enum[ID_GFIR1_BYP_RXTSP] = GFIR1_BYP_RXTSP;
    wndId2Enum[ID_GFIR1_L_RXTSP] = GFIR1_L_RXTSP;
    wndId2Enum[ID_GFIR1_N_RXTSP] = GFIR1_N_RXTSP;
    wndId2Enum[ID_GFIR2_BYP_RXTSP] = GFIR2_BYP_RXTSP;
    wndId2Enum[ID_GFIR2_L_RXTSP] = GFIR2_L_RXTSP;
    wndId2Enum[ID_GFIR2_N_RXTSP] = GFIR2_N_RXTSP;
    wndId2Enum[ID_GFIR3_BYP_RXTSP] = GFIR3_BYP_RXTSP;
    wndId2Enum[ID_GFIR3_L_RXTSP] = GFIR3_L_RXTSP;
    wndId2Enum[ID_GFIR3_N_RXTSP] = GFIR3_N_RXTSP;
    wndId2Enum[ID_HBD_OVR_RXTSP] = HBD_OVR_RXTSP;
    wndId2Enum[ID_IQCORR_RXTSP] = IQCORR_RXTSP;
    wndId2Enum[ID_PH_BYP_RXTSP] = PH_BYP_RXTSP;
}

pnlRxTSP::pnlRxTSP(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, int style, wxString name)
{
    coefFilenames[0] = "";
    coefFilenames[1] = "";
    coefFilenames[2] = "";
    lmsControl = NULL;
    BuildContent(parent,id,pos,size);
    AssignEnumsToIds();
}
void pnlRxTSP::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
//(*Initialize(pnlRxTSP)
wxStaticBoxSizer* GFIR2Sizer;
wxStaticBoxSizer* StaticBoxSizer2;
wxFlexGridSizer* FlexGridSizer4;
wxFlexGridSizer* BIST1Sizer;
wxFlexGridSizer* FlexGridSizer3;
wxFlexGridSizer* GFIR15Sizer;
wxStaticBoxSizer* InterpolationSizer;
wxFlexGridSizer* FlexGridSizer5;
wxFlexGridSizer* FlexGridSizer9;
wxStaticBoxSizer* GFIR1Sizer;
wxFlexGridSizer* FlexGridSizer2;
wxFlexGridSizer* FlexGridSizer7;
wxFlexGridSizer* GFIR37Sizer;
wxStaticBoxSizer* BypassSizer;
wxStaticBoxSizer* IQCorrectorSizer;
wxFlexGridSizer* Interpolation3Sizer;
wxFlexGridSizer* IQCorrector2Sizer;
wxFlexGridSizer* FlexGridSizer8;
wxStaticBoxSizer* DCCorrectorSizer;
wxFlexGridSizer* Bypass8Sizer;
wxFlexGridSizer* GFIR26Sizer;
wxFlexGridSizer* DCCorrector4Sizer;
wxFlexGridSizer* FlexGridSizer6;
wxStaticBoxSizer* StaticBoxSizer1;
wxFlexGridSizer* FlexGridSizer1;
wxStaticBoxSizer* BISTSizer;
wxStaticBoxSizer* GFIR3Sizer;

Create(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("wxID_ANY"));
FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 5);
FlexGridSizer5 = new wxFlexGridSizer(0, 1, 0, 5);
FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 5);
BISTSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("BIST"));
BIST1Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText5 = new wxStaticText(this, ID_STATICTEXT6, _("BIST state"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
BIST1Sizer->Add(StaticText5, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
lblBSTATE_RXTSP = new wxStaticText(this, ID_BSTATE_RXTSP, _("\?\?\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_BSTATE_RXTSP"));
BIST1Sizer->Add(lblBSTATE_RXTSP, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText4 = new wxStaticText(this, ID_STATICTEXT5, _("BIST signature ch. I"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
BIST1Sizer->Add(StaticText4, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
lblBSIGI_RXTSP = new wxStaticText(this, ID_BSIGI_RXTSP, _("\?\?\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_BSIGI_RXTSP"));
BIST1Sizer->Add(lblBSIGI_RXTSP, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText6 = new wxStaticText(this, ID_STATICTEXT7, _("BIST signature ch. Q"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
BIST1Sizer->Add(StaticText6, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
lblBSIGQ_RXTSP = new wxStaticText(this, ID_BSIGQ_RXTSP, _("\?\?\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_BSIGQ_RXTSP"));
BIST1Sizer->Add(lblBSIGQ_RXTSP, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkBSTART_RXTSP = new wxCheckBox(this, ID_BSTART_RXTSP, _("Start BIST"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BSTART_RXTSP"));
chkBSTART_RXTSP->SetValue(false);
chkBSTART_RXTSP->SetToolTip(_("Starts delta sigma built in self test. Keep it at 1 one at least three clock cycles"));
BIST1Sizer->Add(chkBSTART_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
btnReadBist = new wxButton(this, ID_BUTTON1, _("Read BIST"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
BIST1Sizer->Add(btnReadBist, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
BISTSizer->Add(BIST1Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer3->Add(BISTSizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
IQCorrectorSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("IQ Corrector"));
IQCorrector2Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText7 = new wxStaticText(this, ID_STATICTEXT8, _("Gain ch. Q"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
IQCorrector2Sizer->Add(StaticText7, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbGCORRQ_RXTSP = new StdCombobox(this, ID_GCORRQ_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_GCORRQ_RXTSP"));
cmbGCORRQ_RXTSP->SetToolTip(_("corrector value, channel Q Unsigned integer"));
IQCorrector2Sizer->Add(cmbGCORRQ_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText8 = new wxStaticText(this, ID_STATICTEXT9, _("Gain ch. I"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
IQCorrector2Sizer->Add(StaticText8, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbGCORRI_RXTSP = new StdCombobox(this, ID_GCORRI_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_GCORRI_RXTSP"));
cmbGCORRI_RXTSP->SetToolTip(_("corrector value, channel I Unsigned integer"));
IQCorrector2Sizer->Add(cmbGCORRI_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText9 = new wxStaticText(this, ID_STATICTEXT10, _("Phase corrector"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
IQCorrector2Sizer->Add(StaticText9, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbIQCORR_RXTSP = new StdCombobox(this, ID_IQCORR_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_IQCORR_RXTSP"));
cmbIQCORR_RXTSP->SetToolTip(_("Phase corrector value (tan(Alpha/2)). Integer, 2\'s complement"));
IQCorrector2Sizer->Add(cmbIQCORR_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText18 = new wxStaticText(this, ID_STATICTEXT19, _("Alpha"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT19"));
IQCorrector2Sizer->Add(StaticText18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
txtPhaseAlpha = new wxStaticText(this, ID_STATICTEXT20, _("0"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
IQCorrector2Sizer->Add(txtPhaseAlpha, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
IQCorrectorSizer->Add(IQCorrector2Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer3->Add(IQCorrectorSizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
DCCorrectorSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("DC Corrector"));
DCCorrector4Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText11 = new wxStaticText(this, ID_STATICTEXT12, _("Number of samples"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
DCCorrector4Sizer->Add(StaticText11, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbDCCORR_AVG_RXTSP = new StdCombobox(this, ID_DCCORR_AVG_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_DCCORR_AVG_RXTSP"));
cmbDCCORR_AVG_RXTSP->SetToolTip(_("Number of samples to average for Automatic DC corrector. Number of samples to average is 2DCCORR&AVG + 12"));
DCCorrector4Sizer->Add(cmbDCCORR_AVG_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
DCCorrectorSizer->Add(DCCorrector4Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer3->Add(DCCorrectorSizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
InterpolationSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Decimation"));
Interpolation3Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText10 = new wxStaticText(this, ID_STATICTEXT11, _("HBD ratio"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
Interpolation3Sizer->Add(StaticText10, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbHBD_OVR_RXTSP = new StdCombobox(this, ID_HBD_OVR_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_HBD_OVR_RXTSP"));
cmbHBD_OVR_RXTSP->SetToolTip(_("HBD interpolation ratio. Interpolation ratio is 2HBD&OVR+1"));
Interpolation3Sizer->Add(cmbHBD_OVR_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
InterpolationSizer->Add(Interpolation3Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer3->Add(InterpolationSizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
BypassSizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Bypass"));
Bypass8Sizer = new wxFlexGridSizer(0, 2, 0, 0);
chkCMIX_BYP_RXTSP = new wxCheckBox(this, ID_CMIX_BYP_RXTSP, _("CMIX"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CMIX_BYP_RXTSP"));
chkCMIX_BYP_RXTSP->SetValue(false);
chkCMIX_BYP_RXTSP->SetToolTip(_("CMIX bypass"));
Bypass8Sizer->Add(chkCMIX_BYP_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkAGC_BYP_RXTSP = new wxCheckBox(this, ID_AGC_BYP_RXTSP, _("AGC"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_AGC_BYP_RXTSP"));
chkAGC_BYP_RXTSP->SetValue(false);
chkAGC_BYP_RXTSP->SetToolTip(_("AGC bypass"));
Bypass8Sizer->Add(chkAGC_BYP_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkGFIR3_BYP_RXTSP = new wxCheckBox(this, ID_GFIR3_BYP_RXTSP, _("GFIR3"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_GFIR3_BYP_RXTSP"));
chkGFIR3_BYP_RXTSP->SetValue(false);
chkGFIR3_BYP_RXTSP->SetToolTip(_("GFIR3 bypass"));
Bypass8Sizer->Add(chkGFIR3_BYP_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkGFIR2_BYP_RXTSP = new wxCheckBox(this, ID_GFIR2_BYP_RXTSP, _("GFIR2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_GFIR2_BYP_RXTSP"));
chkGFIR2_BYP_RXTSP->SetValue(false);
chkGFIR2_BYP_RXTSP->SetToolTip(_("GFIR2 bypass"));
Bypass8Sizer->Add(chkGFIR2_BYP_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkGFIR1_BYP_RXTSP = new wxCheckBox(this, ID_GFIR1_BYP_RXTSP, _("GFIR1"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_GFIR1_BYP_RXTSP"));
chkGFIR1_BYP_RXTSP->SetValue(false);
chkGFIR1_BYP_RXTSP->SetToolTip(_("GFIR1 bypass"));
Bypass8Sizer->Add(chkGFIR1_BYP_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkDC_BYP_RXTSP = new wxCheckBox(this, ID_DC_BYP_RXTSP, _("DC corrector"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_DC_BYP_RXTSP"));
chkDC_BYP_RXTSP->SetValue(false);
chkDC_BYP_RXTSP->SetToolTip(_("DC corrector bypass"));
Bypass8Sizer->Add(chkDC_BYP_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkGC_BYP_RXTSP = new wxCheckBox(this, ID_GC_BYP_RXTSP, _("Gain corrector"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_GC_BYP_RXTSP"));
chkGC_BYP_RXTSP->SetValue(false);
chkGC_BYP_RXTSP->SetToolTip(_("Gain corrector bypass"));
Bypass8Sizer->Add(chkGC_BYP_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
chkPH_BYP_RXTSP = new wxCheckBox(this, ID_PH_BYP_RXTSP, _("Phase corrector"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_PH_BYP_RXTSP"));
chkPH_BYP_RXTSP->SetValue(false);
chkPH_BYP_RXTSP->SetToolTip(_("Phase corrector bypass"));
Bypass8Sizer->Add(chkPH_BYP_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
BypassSizer->Add(Bypass8Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer3->Add(BypassSizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
GFIR1Sizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("GFIR1"));
GFIR15Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText12 = new wxStaticText(this, ID_STATICTEXT13, _("Length"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
GFIR15Sizer->Add(StaticText12, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbGFIR1_L_RXTSP = new StdCombobox(this, ID_GFIR1_L_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_GFIR1_L_RXTSP"));
cmbGFIR1_L_RXTSP->SetToolTip(_("Parameter l of GFIR1 (l = roundUp(CoeffN/5)-1). Unsigned integer"));
GFIR15Sizer->Add(cmbGFIR1_L_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText13 = new wxStaticText(this, ID_STATICTEXT14, _("Clock Division Ratio:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
GFIR15Sizer->Add(StaticText13, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbGFIR1_N_RXTSP = new StdCombobox(this, ID_GFIR1_N_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_GFIR1_N_RXTSP"));
cmbGFIR1_N_RXTSP->SetToolTip(_("Clock division ratio of GFIR1 is GFIR1&N + 1. Unsigned integer"));
GFIR15Sizer->Add(cmbGFIR1_N_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
btnLoadGFIR1Coef = new wxButton(this, ID_BUTTON2, _("Coefficients"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
GFIR15Sizer->Add(btnLoadGFIR1Coef, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
GFIR1Sizer->Add(GFIR15Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer3->Add(GFIR1Sizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
GFIR2Sizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("GFIR2"));
GFIR26Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText14 = new wxStaticText(this, ID_STATICTEXT15, _("Length"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
GFIR26Sizer->Add(StaticText14, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbGFIR2_L_RXTSP = new StdCombobox(this, ID_GFIR2_L_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_GFIR2_L_RXTSP"));
cmbGFIR2_L_RXTSP->SetToolTip(_("Parameter l of GFIR2 (l = roundUp(CoeffN/5)-1). Unsigned integer"));
GFIR26Sizer->Add(cmbGFIR2_L_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText15 = new wxStaticText(this, ID_STATICTEXT16, _("Clock Division Ratio:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
GFIR26Sizer->Add(StaticText15, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbGFIR2_N_RXTSP = new StdCombobox(this, ID_GFIR2_N_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_GFIR2_N_RXTSP"));
cmbGFIR2_N_RXTSP->SetToolTip(_("Clock division ratio of GFIR2 is GFIR2&N + 1. Unsigned integer"));
GFIR26Sizer->Add(cmbGFIR2_N_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
btnLoadGFIR2Coef = new wxButton(this, ID_BUTTON3, _("Coefficients"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
GFIR26Sizer->Add(btnLoadGFIR2Coef, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
GFIR2Sizer->Add(GFIR26Sizer, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer3->Add(GFIR2Sizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
GFIR3Sizer = new wxStaticBoxSizer(wxHORIZONTAL, this, _("GFIR3"));
GFIR37Sizer = new wxFlexGridSizer(0, 2, 0, 5);
StaticText16 = new wxStaticText(this, ID_STATICTEXT17, _("Length"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
GFIR37Sizer->Add(StaticText16, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbGFIR3_L_RXTSP = new StdCombobox(this, ID_GFIR3_L_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_GFIR3_L_RXTSP"));
cmbGFIR3_L_RXTSP->SetToolTip(_("Parameter l of GFIR3 (l = roundUp(CoeffN/5)-1). Unsigned integer"));
GFIR37Sizer->Add(cmbGFIR3_L_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText17 = new wxStaticText(this, ID_STATICTEXT18, _("Clock Division Ratio:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT18"));
GFIR37Sizer->Add(StaticText17, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbGFIR3_N_RXTSP = new StdCombobox(this, ID_GFIR3_N_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_GFIR3_N_RXTSP"));
cmbGFIR3_N_RXTSP->SetToolTip(_("Clock division ratio of GFIR3 is GFIR3&N + 1. Unsigned integer"));
GFIR37Sizer->Add(cmbGFIR3_N_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
btnLoadGFIR3Coef = new wxButton(this, ID_BUTTON4, _("Coefficients"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
GFIR37Sizer->Add(btnLoadGFIR3Coef, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
GFIR3Sizer->Add(GFIR37Sizer, 0, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
FlexGridSizer3->Add(GFIR3Sizer, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
chkEN_RXTSP = new wxCheckBox(this, ID_EN_RXTSP, _("Enable RxTSP"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_EN_RXTSP"));
chkEN_RXTSP->SetValue(false);
chkEN_RXTSP->SetToolTip(_("RxTSP modules enable"));
FlexGridSizer3->Add(chkEN_RXTSP, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
chkCMIX_P6DB_RXTSP = new wxCheckBox(this, ID_CMIX_P6DB_RXTSP, _("Increase CMIX output by +6dB"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CMIX_P6DB_RXTSP"));
chkCMIX_P6DB_RXTSP->SetValue(false);
chkCMIX_P6DB_RXTSP->SetToolTip(_("Increase CMIX output by +6dB"));
FlexGridSizer3->Add(chkCMIX_P6DB_RXTSP, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
FlexGridSizer5->Add(FlexGridSizer3, 1, wxALIGN_LEFT|wxALIGN_TOP, 5);
FlexGridSizer9 = new wxFlexGridSizer(0, 3, 0, 0);
StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("AGC"));
FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
StaticText0 = new wxStaticText(this, ID_STATICTEXT1, _("AGC loop gain"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
FlexGridSizer2->Add(StaticText0, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
spinAGC_K_RXTSP = new wxSpinCtrl(this, ID_AGC_K_RXTSP, _T("1"), wxDefaultPosition, wxDefaultSize, 0, 0, 262143, 1, _T("ID_AGC_K_RXTSP"));
spinAGC_K_RXTSP->SetValue(_T("1"));
FlexGridSizer2->Add(spinAGC_K_RXTSP, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
StaticText2 = new wxStaticText(this, ID_STATICTEXT3, _("AGC Averaging window size"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
FlexGridSizer2->Add(StaticText2, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbAGC_AVG_RXTSP = new StdCombobox(this, ID_AGC_AVG_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_AGC_AVG_RXTSP"));
cmbAGC_AVG_RXTSP->SetToolTip(_("AGC Averaging window size"));
FlexGridSizer2->Add(cmbAGC_AVG_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticText1 = new wxStaticText(this, ID_STATICTEXT2, _("Desired output signal level"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
FlexGridSizer2->Add(StaticText1, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
cmbAGC_ADESIRED_RXTSP = new StdCombobox(this, ID_AGC_ADESIRED_RXTSP, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_AGC_ADESIRED_RXTSP"));
cmbAGC_ADESIRED_RXTSP->SetToolTip(_("AGC&ADESIRED"));
FlexGridSizer2->Add(cmbAGC_ADESIRED_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
wxString __wxRadioBoxChoices_1[3] =
{
	_("AGC"),
	_("RSSI"),
	_("Bypass")
};
rgrAGC_MODE_RXTSP = new wxRadioBox(this, ID_AGC_MODE_RXTSP, _("AGC MODE"), wxDefaultPosition, wxDefaultSize, 3, __wxRadioBoxChoices_1, 3, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_AGC_MODE_RXTSP"));
rgrAGC_MODE_RXTSP->SetSelection(0);
rgrAGC_MODE_RXTSP->SetToolTip(_("AGC&MODE"));
FlexGridSizer2->Add(rgrAGC_MODE_RXTSP, 0, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
StaticBoxSizer1->Add(FlexGridSizer2, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
FlexGridSizer9->Add(StaticBoxSizer1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
FlexGridSizer8 = new wxFlexGridSizer(4, 2, 0, 0);
StaticText3 = new wxStaticText(this, ID_STATICTEXT4, _("RSSI:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
FlexGridSizer8->Add(StaticText3, 0, wxLEFT|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
lblRSSI_RXTSP = new wxStaticText(this, ID_RSSI_RXTSP, _("\?\?\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_RSSI_RXTSP"));
FlexGridSizer8->Add(lblRSSI_RXTSP, 0, wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
btnReadRSSI = new wxButton(this, ID_BUTTON5, _("Read RSSI"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
FlexGridSizer8->Add(btnReadRSSI, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
FlexGridSizer9->Add(FlexGridSizer8, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
FlexGridSizer5->Add(FlexGridSizer9, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
FlexGridSizer1->Add(FlexGridSizer5, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("NCO"));
FlexGridSizer4 = new wxFlexGridSizer(3, 1, 0, 0);
FlexGridSizer6 = new wxFlexGridSizer(0, 3, 0, 0);
wxString __wxRadioBoxChoices_2[2] =
{
	_("FCW"),
	_("PHO")
};
rgrMODE = new wxRadioBox(this, ID_MODE_RX, _("Mode"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_2, 2, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_MODE_RX"));
FlexGridSizer6->Add(rgrMODE, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
wxString __wxRadioBoxChoices_3[2] =
{
	_("Binary offset"),
	_("Two\'s complement")
};
rgrOFC = new wxRadioBox(this, ID_OFC, _("Output format control"), wxDefaultPosition, wxDefaultSize, 2, __wxRadioBoxChoices_3, 2, wxRA_SPECIFY_COLS, wxDefaultValidator, _T("ID_OFC"));
FlexGridSizer6->Add(rgrOFC, 1, wxLEFT|wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
FlexGridSizer4->Add(FlexGridSizer6, 1, wxALIGN_LEFT|wxALIGN_TOP, 5);
sizerNCOgrid = new wxFlexGridSizer(0, 4, 2, 5);
sizerNCOgrid->Add(-1,-1,1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
StaticText19 = new wxStaticText(this, ID_STATICTEXT21, _("FCW(MHz)"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
sizerNCOgrid->Add(StaticText19, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
StaticText20 = new wxStaticText(this, ID_STATICTEXT22, _("PHO"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
sizerNCOgrid->Add(StaticText20, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
StaticText21 = new wxStaticText(this, ID_STATICTEXT23, _("Angle"), wxDefaultPosition, wxSize(48,13), 0, _T("ID_STATICTEXT23"));
sizerNCOgrid->Add(StaticText21, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
FlexGridSizer4->Add(sizerNCOgrid, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
FlexGridSizer7 = new wxFlexGridSizer(0, 4, 0, 0);
btnUploadNCO = new wxButton(this, ID_BUTTON6, _("Upload NCO"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
FlexGridSizer7->Add(btnUploadNCO, 1, wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
btnSetRefClk = new wxButton(this, ID_BUTTON7, _("Set Reference Clk"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
FlexGridSizer7->Add(btnSetRefClk, 1, wxLEFT|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
StaticText22 = new wxStaticText(this, ID_STATICTEXT24, _("RefClk(MHz):"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
FlexGridSizer7->Add(StaticText22, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
lblRefClk = new wxStaticText(this, ID_STATICTEXT25, _("30.72"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
FlexGridSizer7->Add(lblRefClk, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
FlexGridSizer4->Add(FlexGridSizer7, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
StaticBoxSizer2->Add(FlexGridSizer4, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_TOP, 5);
FlexGridSizer1->Add(StaticBoxSizer2, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
SetSizer(FlexGridSizer1);
FlexGridSizer1->Fit(this);
FlexGridSizer1->SetSizeHints(this);

Connect(ID_BSTART_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pnlRxTSP::OnbtnReadBistClick);
Connect(ID_GCORRQ_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_GCORRI_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_IQCORR_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_DCCORR_AVG_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_HBD_OVR_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_CMIX_BYP_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_AGC_BYP_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_GFIR3_BYP_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_GFIR2_BYP_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_GFIR1_BYP_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_DC_BYP_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_GC_BYP_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_PH_BYP_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_GFIR1_L_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_GFIR1_N_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pnlRxTSP::OnbtnLoadGFIR1CoefClick);
Connect(ID_GFIR2_L_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_GFIR2_N_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pnlRxTSP::OnbtnLoadGFIR2CoefClick);
Connect(ID_GFIR3_L_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_GFIR3_N_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pnlRxTSP::OnbtnLoadGFIR3CoefClick);
Connect(ID_EN_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_CMIX_P6DB_RXTSP,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_AGC_K_RXTSP,wxEVT_COMMAND_SPINCTRL_UPDATED,(wxObjectEventFunction)&pnlRxTSP::OnspinAGC_K_RXTSPChange);
Connect(ID_AGC_AVG_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_AGC_ADESIRED_RXTSP,wxEVT_COMMAND_COMBOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_AGC_MODE_RXTSP,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pnlRxTSP::OnbtnReadRSSIClick);
Connect(ID_MODE_RX,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_OFC,wxEVT_COMMAND_RADIOBOX_SELECTED,(wxObjectEventFunction)&pnlRxTSP::ParameterChangeHandler);
Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pnlRxTSP::OnbtnUploadNCOClick);
Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&pnlRxTSP::OnbtnSetRefClkClick);
//*)
    InitializeNCOgrid();
}
pnlRxTSP::~pnlRxTSP()
{
//(*Destroy(pnlRxTSP)
//*)
}
void pnlRxTSP::ParameterChangeHandler(wxCommandEvent& event)
{
    if(lmsControl == NULL)
    {
        std::cout << "pnlRxTSP panel don't have control module assigned" << std::endl;
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

    int evtint;
    float atangent;
    float angle;

    switch(parameter)
    {
    case IQCORR_RXTSP: // when changed recalculate alpha text field
        evtint = event.GetInt();
        atangent = atan( (evtint-2048)/2048.0 );
        angle = atangent * 180/3.141596 * 2;
        txtPhaseAlpha->SetLabel( wxString::Format("%f", angle));
        lmsControl->SetParam( parameter, indexToTwoComplement(event.GetInt(), lmsControl->getRegistersMap()->getParameterInfo(parameter).bitCount) );
        break;
    default:
        lmsControl->SetParam( parameter, event.GetInt());
    }
}

void pnlRxTSP::Initialize(LMS7002_MainControl *pControl)
{
    lmsControl = pControl;
    char ctemp[80];
    vector<string> temp;
    temp.clear();
    for(int i=0; i<4096; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbAGC_ADESIRED_RXTSP->Clear();
    cmbAGC_ADESIRED_RXTSP->Append(temp);
    //cmbAGC_ADESIRED_RXTSP->SetSelection( lmsControl->GetParam(AGC_ADESIRED_RXTSP));

    temp.clear();
    temp.push_back("2^7");
    temp.push_back("2^8");
    temp.push_back("2^9");
    temp.push_back("2^10");
    temp.push_back("2^11");
    temp.push_back("2^12");
    temp.push_back("2^13");
    temp.push_back("2^14");
    cmbAGC_AVG_RXTSP->Clear();
    cmbAGC_AVG_RXTSP->Append(temp);
    //cmbAGC_AVG_RXTSP->SetSelection( lmsControl->GetParam(AGC_AVG_RXTSP));

    spinAGC_K_RXTSP->SetRange(0, 262143);
    spinAGC_K_RXTSP->SetValue( lmsControl->GetParam(AGC_K_RXTSP));

    temp.clear();
    temp.push_back("2^12");
    temp.push_back("2^13");
    temp.push_back("2^14");
    temp.push_back("2^15");
    temp.push_back("2^16");
    temp.push_back("2^17");
    temp.push_back("2^18");
    temp.push_back("2^19");
    cmbDCCORR_AVG_RXTSP->Clear();
    cmbDCCORR_AVG_RXTSP->Append(temp);
    //cmbDCCORR_AVG_RXTSP->SetSelection( lmsControl->GetParam(DCCORR_AVG_RXTSP));

    temp.clear();
    for(int i=0; i<2048; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbGCORRI_RXTSP->Clear();
    cmbGCORRI_RXTSP->Append(temp);
    //cmbGCORRI_RXTSP->SetSelection( lmsControl->GetParam(GCORRI_RXTSP));

    temp.clear();
    for(int i=0; i<2048; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbGCORRQ_RXTSP->Clear();
    cmbGCORRQ_RXTSP->Append(temp);
    //cmbGCORRQ_RXTSP->SetSelection( lmsControl->GetParam(GCORRQ_RXTSP));

    temp.clear();
    for(int i=0; i<8; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbGFIR1_L_RXTSP->Clear();
    cmbGFIR1_L_RXTSP->Append(temp);
    //cmbGFIR1_L_RXTSP->SetSelection( lmsControl->GetParam(GFIR1_L_RXTSP));

    temp.clear();
    for(int i=0; i<256; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbGFIR1_N_RXTSP->Clear();
    cmbGFIR1_N_RXTSP->Append(temp);
    //cmbGFIR1_N_RXTSP->SetSelection( lmsControl->GetParam(GFIR1_N_RXTSP));

    temp.clear();
    for(int i=0; i<8; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbGFIR2_L_RXTSP->Clear();
    cmbGFIR2_L_RXTSP->Append(temp);
    //cmbGFIR2_L_RXTSP->SetSelection( lmsControl->GetParam(GFIR2_L_RXTSP));

    temp.clear();
    for(int i=0; i<256; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbGFIR2_N_RXTSP->Clear();
    cmbGFIR2_N_RXTSP->Append(temp);
    //cmbGFIR2_N_RXTSP->SetSelection( lmsControl->GetParam(GFIR2_N_RXTSP));

    temp.clear();
    for(int i=0; i<8; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbGFIR3_L_RXTSP->Clear();
    cmbGFIR3_L_RXTSP->Append(temp);
    //cmbGFIR3_L_RXTSP->SetSelection( lmsControl->GetParam(GFIR3_L_RXTSP));

    temp.clear();
    for(int i=0; i<256; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbGFIR3_N_RXTSP->Clear();
    cmbGFIR3_N_RXTSP->Append(temp);
    //cmbGFIR3_N_RXTSP->SetSelection( lmsControl->GetParam(GFIR3_N_RXTSP));

    temp.clear();
    temp.push_back("2^1");
    temp.push_back("2^2");
    temp.push_back("2^3");
    temp.push_back("2^4");
    temp.push_back("2^5");
    temp.push_back("Bypass");
    cmbHBD_OVR_RXTSP->Clear();
    cmbHBD_OVR_RXTSP->Append(temp);
    //cmbHBD_OVR_RXTSP->SetSelection( lmsControl->GetParam(HBD_OVR_RXTSP));

    temp.clear();
    for(int i=-2048; i<=2047; ++i)
        {sprintf(ctemp, "%i", i); temp.push_back(ctemp);}
    cmbIQCORR_RXTSP->Clear();
    cmbIQCORR_RXTSP->Append(temp);
    //cmbIQCORR_RXTSP->SetSelection( lmsControl->GetParam(IQCORR_RXTSP));
    UpdateTooltips(this);
    UpdateGUI(); //sets default selections
}

void pnlRxTSP::UpdateGUI()
{
    float refClk = lmsControl->GetReferenceFrequencyNCO(true);
    lblRefClk->SetLabel(wxString::Format("%f", refClk));
    //GetParent()->Freeze();
    long value = 0;
    value = lmsControl->GetParam(AGC_ADESIRED_RXTSP);
    cmbAGC_ADESIRED_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(AGC_AVG_RXTSP);
    cmbAGC_AVG_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(AGC_BYP_RXTSP);
    chkAGC_BYP_RXTSP->SetValue(value);

    value = lmsControl->GetParam(AGC_K_RXTSP);
    spinAGC_K_RXTSP->SetValue(value);

    value = lmsControl->GetParam(AGC_MODE_RXTSP);
    rgrAGC_MODE_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(BSTART_RXTSP);
    chkBSTART_RXTSP->SetValue(value);

    value = lmsControl->GetParam(CMIX_BYP_RXTSP);
    chkCMIX_BYP_RXTSP->SetValue(value);

    value = lmsControl->GetParam(CMIX_P6DB_RXTSP);
    chkCMIX_P6DB_RXTSP->SetValue(value);

    value = lmsControl->GetParam(DCCORR_AVG_RXTSP);
    cmbDCCORR_AVG_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(DC_BYP_RXTSP);
    chkDC_BYP_RXTSP->SetValue(value);

    value = lmsControl->GetParam(EN_RXTSP);
    chkEN_RXTSP->SetValue(value);

    value = lmsControl->GetParam(GCORRI_RXTSP);
    cmbGCORRI_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(GCORRQ_RXTSP);
    cmbGCORRQ_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(GC_BYP_RXTSP);
    chkGC_BYP_RXTSP->SetValue(value);

    value = lmsControl->GetParam(GFIR1_BYP_RXTSP);
    chkGFIR1_BYP_RXTSP->SetValue(value);

    value = lmsControl->GetParam(GFIR1_L_RXTSP);
    cmbGFIR1_L_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(GFIR1_N_RXTSP);
    cmbGFIR1_N_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(GFIR2_BYP_RXTSP);
    chkGFIR2_BYP_RXTSP->SetValue(value);

    value = lmsControl->GetParam(GFIR2_L_RXTSP);
    cmbGFIR2_L_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(GFIR2_N_RXTSP);
    cmbGFIR2_N_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(GFIR3_BYP_RXTSP);
    chkGFIR3_BYP_RXTSP->SetValue(value);

    value = lmsControl->GetParam(GFIR3_L_RXTSP);
    cmbGFIR3_L_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(GFIR3_N_RXTSP);
    cmbGFIR3_N_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(HBD_OVR_RXTSP);
    cmbHBD_OVR_RXTSP->SetSelection(value);

    value = lmsControl->GetParam(IQCORR_RXTSP);
    cmbIQCORR_RXTSP->SetSelection( twoComplementToIndex(value, lmsControl->getRegistersMap()->getParameterInfo(IQCORR_RXTSP).bitCount) );

    value = lmsControl->GetParam(PH_BYP_RXTSP);
    chkPH_BYP_RXTSP->SetValue(value);

    value = lmsControl->GetParam(MODE_RX);
    rgrMODE->SetSelection(value);

    value = lmsControl->GetParam(SEL_RX);
    if(value < ncoRadioButtons.size())
        ncoRadioButtons[value]->SetValue(true);

    vector<double> fcwFreqs;
    vector<int> phoCodes;
    lmsControl->GetNCOconfiguration(fcwFreqs, phoCodes, true);
    SetNCOgrid(fcwFreqs, phoCodes);
    //GetParent()->Thaw();
}

void pnlRxTSP::OnspinAGC_K_RXTSPChange(wxSpinEvent& event)
{
    ParameterChangeHandler(event);
}

void pnlRxTSP::OnbtnLoadGFIR1CoefClick(wxCommandEvent& event)
{
    dlgGFIR_Coefficients dlg;
    dlg.Initialize(lmsControl, coefFilenames[0], 1, true);
    dlg.ShowModal();

    coefFilenames[0] = dlg.txtFilename->GetLabel();
    /*wxFileDialog dlg(this, _("Open coefficients file"), "", "", "FIR Coeffs (*.fir)|*.fir", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    lmsControl->LoadGFIRCoefficients(dlg.GetPath().ToStdString(), 1, true);*/
}

void pnlRxTSP::OnbtnLoadGFIR2CoefClick(wxCommandEvent& event)
{
    dlgGFIR_Coefficients dlg;
    dlg.Initialize(lmsControl, coefFilenames[1], 2, true);
    dlg.ShowModal();

    coefFilenames[1] = dlg.txtFilename->GetLabel();
    /*wxFileDialog dlg(this, _("Open coefficients file"), "", "", "FIR Coeffs (*.fir)|*.fir", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    lmsControl->LoadGFIRCoefficients(dlg.GetPath().ToStdString(), 2, true);*/
}

void pnlRxTSP::OnbtnLoadGFIR3CoefClick(wxCommandEvent& event)
{
    dlgGFIR_Coefficients dlg;
    dlg.Initialize(lmsControl, coefFilenames[2], 3, true);
    dlg.ShowModal();

    coefFilenames[2] = dlg.txtFilename->GetLabel();
    /*wxFileDialog dlg(this, _("Open coefficients file"), "", "", "FIR Coeffs (*.fir)|*.fir", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    lmsControl->LoadGFIRCoefficients(dlg.GetPath().ToStdString(), 3, true);*/
}

void pnlRxTSP::OnbtnReadBistClick(wxCommandEvent& event)
{
    lmsControl->SetAutoDownload(true);
    unsigned int value;
    value = lmsControl->GetParam(BSTATE_RXTSP);
    lblBSTATE_RXTSP->SetLabel(wxString::Format("%i", value));
    value = lmsControl->GetParam(BSIGI_RXTSP);
    lblBSIGI_RXTSP->SetLabel(wxString::Format("0x%x", value));
    value = lmsControl->GetParam(BSIGQ_RXTSP);
    lblBSIGQ_RXTSP->SetLabel(wxString::Format("0x%x", value));
    lmsControl->SetAutoDownload(false);
}

void pnlRxTSP::OnbtnReadRSSIClick(wxCommandEvent& event)
{
    lmsControl->SetAutoDownload(true);
    unsigned int value;
    value = lmsControl->GetParam(RSSI_RXTSP);
    lblRSSI_RXTSP->SetLabel(wxString::Format("0x%04X", value));
    lmsControl->SetAutoDownload(false);
}

void pnlRxTSP::InitializeNCOgrid()
{
    fcwFields.clear();
    phoFields.clear();
    ncoRadioButtons.clear();
    phoAngles.clear();
    wxRadioButton *radiobtn;
    wxTextCtrl *fcwField;
    wxTextCtrl *phoField;
    wxStaticText *phoAngle;
    for(int i=0; i<16; ++i)
    {
        int btnId = wxNewId();
        if(i == 0)
            radiobtn = new wxRadioButton(this, btnId, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
        else
            radiobtn = new wxRadioButton(this, btnId, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
        sizerNCOgrid->Add(radiobtn, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
        ncoRadioButtons.push_back(radiobtn);
        Connect(btnId,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&pnlRxTSP::OnrgrSELSelect);
        fcwField = new wxTextCtrl(this, wxNewId(), wxString::Format("%f", 0.0) , wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
        sizerNCOgrid->Add(fcwField, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
        fcwFields.push_back(fcwField);
        phoField = new wxTextCtrl(this, wxNewId(), wxString::Format("%f", 0.0) , wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
        sizerNCOgrid->Add(phoField, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
        phoFields.push_back(phoField);
        phoAngle = new wxStaticText(this, wxNewId(), "0.0000");
        sizerNCOgrid->Add(phoAngle, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
        phoAngles.push_back(phoAngle);
        Connect(phoField->GetId(),wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&pnlRxTSP::OnPHOAngleChanged);
    }
    ncoRadioButtons[0]->SetValue(true);
    //sizerNCOgrid->Fit();
}

void pnlRxTSP::SetNCOgrid(const vector<double> &FCW, const vector<int> &PHO)
{
    for(unsigned i=0; i<FCW.size(); ++i)
        fcwFields[i]->SetValue(wxString::Format("%f", FCW[i]));
    for(unsigned i=0; i<PHO.size(); ++i)
        phoFields[i]->SetValue(wxString::Format("%i", PHO[i]));
}


void pnlRxTSP::OnbtnUploadNCOClick(wxCommandEvent& event)
{
    vector<double> fcwValues;
    vector<int> phoValues;

    double dvalue;
    long lvalue;
    for(int i=0; i<16; ++i)
    {
        fcwFields[i]->GetValue().ToDouble(&dvalue);
        fcwValues.push_back(dvalue);
        phoFields[i]->GetValue().ToLong(&lvalue);
        phoValues.push_back(lvalue);
    }
    lmsControl->SetNCOconfiguration(fcwValues, phoValues, true);
}

void pnlRxTSP::OnrgrSELSelect(wxCommandEvent& event)
{
    for(unsigned int i=0; i<ncoRadioButtons.size(); ++i)
        if(ncoRadioButtons[i]->GetId() == event.GetId())
        {
            lmsControl->SetParam(SEL_RX, i);
            break;
        }
}

void pnlRxTSP::OnbtnSetRefClkClick(wxCommandEvent& event)
{
    dlgFloatInput dlg(this, "Reference frequency (MHz):", "Rx NCO Reference Frequency", lmsControl->GetReferenceFrequencyNCO(true));
    if( dlg.ShowModal() == wxID_OK)
    {
        lmsControl->SetReferenceFrequencyNCO(dlg.GetValue(), true);
        lblRefClk->SetLabel(wxString::Format("%f", dlg.GetValue()));
    }
}

void pnlRxTSP::OnPHOAngleChanged(wxCommandEvent& event)
{
    long phoVal = 0;
    for(unsigned i=0; i<phoFields.size(); ++i)
    {
        if(phoFields[i]->GetId() == event.GetId())
        {
            phoFields[i]->GetValue().ToLong(&phoVal);
            phoAngles[i]->SetLabel(wxString::Format("%3.4f", 2.0*180*phoVal/(65536.0)));
            break;
        }
    }
}