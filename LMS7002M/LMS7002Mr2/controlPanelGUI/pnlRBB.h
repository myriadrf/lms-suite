// -----------------------------------------------------------------------------
// FILE: 		pnlRBB.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef pnlRBB_H
#define pnlRBB_H
//(*Headers(pnlRBB)
#include <wx/panel.h>
class wxCheckBox;
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
class pnlRBB : public wxPanel, GUIPanel
{
public:
    pnlRBB(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style=0, wxString name="");
    virtual void Initialize(LMS7002_MainControl *pControl);
    virtual void UpdateGUI();
    virtual ~pnlRBB();

//(*Declarations(pnlRBB)
wxStaticText* StaticText10;
wxStaticText* StaticText9;
wxButton* btnCalibrateHighBand;
wxCheckBox* chkPD_PGA_RBB;
StdCombobox* cmbC_CTL_PGA_RBB;
StdCombobox* cmbRCC_CTL_PGA_RBB;
StdCombobox* cmbC_CTL_LPFL_RBB;
wxCheckBox* chkEN_LB_LPFH_RBB;
wxCheckBox* chkPD_LPFL_RBB;
wxStaticText* StaticText2;
StdCombobox* cmbICT_PGA_IN_RBB;
wxButton* btnCalibrateLowBand;
wxStaticText* StaticText6;
wxStaticText* StaticText8;
wxStaticText* StaticText0;
wxStaticText* StaticText11;
StdCombobox* cmbRCC_CTL_LPFH_RBB;
wxStaticText* StaticText1;
wxStaticText* StaticText3;
wxCheckBox* chkPD_LPFH_RBB;
StdCombobox* cmbG_PGA_RBB;
wxCheckBox* chkEN_G_RBB;
wxStaticText* StaticText5;
wxStaticText* StaticText7;
wxRadioBox* rgrOSW_PGA_RBB;
StdCombobox* cmbICT_PGA_OUT_RBB;
StdCombobox* cmbINPUT_CTL_PGA_RBB;
wxStaticText* StaticText12;
wxCheckBox* chkEN_LB_LPFL_RBB;
wxStaticText* StaticText4;
StdCombobox* cmbC_CTL_LPFH_RBB;
StdCombobox* cmbRCC_CTL_LPFL_RBB;
StdCombobox* cmbR_CTL_LPF_RBB;
StdCombobox* cmbICT_LPF_OUT_RBB;
StdCombobox* cmbICT_LPF_IN_RBB;
//*)

protected:
//(*Identifiers(pnlRBB)
static const long ID_EN_LB_LPFH_RBB;
static const long ID_EN_LB_LPFL_RBB;
static const long ID_STATICTEXT1;
static const long ID_INPUT_CTL_PGA_RBB;
static const long ID_STATICTEXT2;
static const long ID_G_PGA_RBB;
static const long ID_STATICTEXT3;
static const long ID_C_CTL_PGA_RBB;
static const long ID_OSW_PGA_RBB;
static const long ID_STATICTEXT4;
static const long ID_R_CTL_LPF_RBB;
static const long ID_STATICTEXT5;
static const long ID_C_CTL_LPFH_RBB;
static const long ID_STATICTEXT6;
static const long ID_C_CTL_LPFL_RBB;
static const long ID_PD_LPFH_RBB;
static const long ID_PD_LPFL_RBB;
static const long ID_PD_PGA_RBB;
static const long ID_EN_G_RBB;
static const long ID_STATICTEXT7;
static const long ID_RCC_CTL_LPFH_RBB;
static const long ID_STATICTEXT8;
static const long ID_RCC_CTL_LPFL_RBB;
static const long ID_STATICTEXT9;
static const long ID_ICT_LPF_IN_RBB;
static const long ID_STATICTEXT10;
static const long ID_ICT_LPF_OUT_RBB;
static const long ID_STATICTEXT11;
static const long ID_ICT_PGA_OUT_RBB;
static const long ID_STATICTEXT12;
static const long ID_ICT_PGA_IN_RBB;
static const long ID_STATICTEXT13;
static const long ID_RCC_CTL_PGA_RBB;
static const long ID_BUTTON1;
static const long ID_BUTTON2;
//*)

private:
//(*Handlers(pnlRBB)
    void ParameterChangeHandler(wxCommandEvent& event);
void OnbtnCalibrateLowBandClick(wxCommandEvent& event);
void OnbtnCalibrateHighBandClick(wxCommandEvent& event);
//*)

protected:
    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);
    void AssignEnumsToIds();
    DECLARE_EVENT_TABLE()
};
#endif
