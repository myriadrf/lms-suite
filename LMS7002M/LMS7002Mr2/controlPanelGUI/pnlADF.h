// -----------------------------------------------------------------------------
// FILE: 		pnlADF.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef PNLADF_H
#define PNLADF_H

#include "StdCombobox.h"

//(*Headers(pnlADF)
#include <wx/panel.h>
class wxSpinEvent;
class wxTextCtrl;
class wxComboBox;
class wxRadioBox;
class wxStaticText;
class wxFlexGridSizer;
class wxSpinCtrl;
class wxButton;
class wxStaticBoxSizer;
//*)

class ADF_module;

class pnlADF: public wxPanel
{
public:

    pnlADF(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int styles=0, wxString idname="");
    void Initialize(ADF_module* pModule);
    virtual ~pnlADF();

    void SetGuiDefaults();

    //(*Declarations(pnlADF)
    wxStaticText* StaticText10;
    wxButton* btnUpload;
    wxStaticText* StaticText9;
    wxRadioBox* rgrPDP_i;
    StdCombobox* cmbCS2_f;
    StdCombobox* cmbLDP;
    wxStaticText* StaticText13;
    wxStaticText* StaticText2;
    wxSpinCtrl* spinNCnt;
    wxStaticText* StaticText14;
    wxStaticText* StaticText6;
    StdCombobox* cmbCS1_f;
    StdCombobox* cmbMOC_f;
    wxStaticText* StaticText19;
    StdCombobox* cmbCS2_i;
    wxStaticText* StaticText8;
    wxStaticText* StaticText11;
    wxStaticText* StaticText18;
    wxRadioBox* rgrPD1_f;
    wxButton* btnCalcSend;
    StdCombobox* cmbCPG;
    StdCombobox* cmbFL_i;
    wxStaticText* StaticText1;
    wxRadioBox* rgrCPS_f;
    wxStaticText* StaticText3;
    wxTextCtrl* txtFref;
    wxRadioBox* rgrPDP_f;
    wxSpinCtrl* spinRCnt;
    wxRadioBox* rgrCPS_i;
    StdCombobox* cmbFL_f;
    StdCombobox* cmbMOC_i;
    wxRadioBox* rgrPD2_f;
    wxStaticText* StaticText5;
    wxStaticText* StaticText7;
    StdCombobox* cmbTC_f;
    StdCombobox* cmbCS1_i;
    wxStaticText* StaticText15;
    wxStaticText* StaticText12;
    wxRadioBox* rgrPD1_i;
    wxStaticText* lblFcomp;
    wxRadioBox* rgrCR_f;
    wxTextCtrl* txtFvco;
    wxStaticText* StaticText17;
    wxStaticText* StaticText4;
    wxRadioBox* rgrCR_i;
    wxStaticText* lblFvco;
    wxStaticText* StaticText16;
    wxRadioBox* rgrPD2_i;
    StdCombobox* cmbTC_i;
    StdCombobox* cmbABW;
    //*)

protected:

    //(*Identifiers(pnlADF)
    static const long ID_STATICTEXT1;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT3;
    static const long ID_COMBOBOX1;
    static const long ID_COMBOBOX2;
    static const long ID_SPINCTRL1;
    static const long ID_STATICTEXT4;
    static const long ID_STATICTEXT5;
    static const long ID_COMBOBOX3;
    static const long ID_SPINCTRL2;
    static const long ID_STATICTEXT6;
    static const long ID_STATICTEXT7;
    static const long ID_COMBOBOX4;
    static const long ID_COMBOBOX5;
    static const long ID_STATICTEXT8;
    static const long ID_STATICTEXT9;
    static const long ID_COMBOBOX6;
    static const long ID_COMBOBOX7;
    static const long ID_STATICTEXT10;
    static const long ID_COMBOBOX8;
    static const long ID_RADIOBOX1;
    static const long ID_RADIOBOX2;
    static const long ID_RADIOBOX3;
    static const long ID_RADIOBOX4;
    static const long ID_RADIOBOX5;
    static const long ID_STATICTEXT17;
    static const long ID_STATICTEXT18;
    static const long ID_COMBOBOX9;
    static const long ID_COMBOBOX10;
    static const long ID_STATICTEXT19;
    static const long ID_STATICTEXT20;
    static const long ID_COMBOBOX11;
    static const long ID_COMBOBOX12;
    static const long ID_STATICTEXT21;
    static const long ID_COMBOBOX13;
    static const long ID_RADIOBOX6;
    static const long ID_RADIOBOX7;
    static const long ID_RADIOBOX8;
    static const long ID_RADIOBOX9;
    static const long ID_RADIOBOX10;
    static const long ID_STATICTEXT11;
    static const long ID_STATICTEXT12;
    static const long ID_TEXTCTRL1;
    static const long ID_TEXTCTRL2;
    static const long ID_STATICTEXT13;
    static const long ID_STATICTEXT14;
    static const long ID_STATICTEXT15;
    static const long ID_STATICTEXT16;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    //*)

private:
    ADF_module* m_pModule;
    //(*Handlers(pnlADF)
    void OnbtnCalcSendClick(wxCommandEvent& event);
    void OnbtnUploadClick(wxCommandEvent& event);
    //*)

protected:

    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

    DECLARE_EVENT_TABLE()
};

#endif
