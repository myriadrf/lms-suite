// -----------------------------------------------------------------------------
// FILE: 		pnlSi5351C.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef pnlSi5351_H
#define pnlSi5351_H

//(*Headers(pnlSi5351)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/panel.h>
#include <wx/button.h>
//*)

class Si5351C;

class pnlSi5351: public wxPanel
{
public:

    pnlSi5351(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style = 0, wxString name="");
    void Initialize(Si5351C* pModule);
    virtual ~pnlSi5351();

    //(*Declarations(pnlSi5351)
    wxStaticText* StaticText10;
    wxStaticText* StaticText9;
    wxCheckBox* chkEN_CLK5;
    wxCheckBox* chkInvert_CLK6;
    wxTextCtrl* txtFreq_CLK7;
    wxTextCtrl* txtFreq_CLK1;
    wxCheckBox* chkEN_CLK3;
    wxCheckBox* chkEN_CLK4;
    wxCheckBox* chkInvert_CLK3;
    wxTextCtrl* txtFreq_CLK5;
    wxStaticText* StaticText13;
    wxStaticText* StaticText2;
    wxButton* btnLoadFile;
    wxTextCtrl* txtFreq_CLK0;
    wxStaticText* StaticText6;
    wxButton* btnResetToDefaults;
    wxStaticText* StaticText8;
    wxStaticText* StaticText11;
    wxStaticText* StaticText1;
    wxStaticText* StaticText3;
    wxButton* btnConfigure;
    wxCheckBox* chkEN_CLK6;
    wxTextCtrl* txtFreq_CLK3;
    wxTextCtrl* txtFreq_CLK6;
    wxTextCtrl* txtFreq_CLK2;
    wxStaticText* StaticText5;
    wxStaticText* StaticText7;
    wxCheckBox* chkInvert_CLK2;
    wxCheckBox* chkInvert_CLK0;
    wxCheckBox* chkEN_CLK1;
    wxStaticText* StaticText12;
    wxCheckBox* chkEN_CLK7;
    wxCheckBox* chkInvert_CLK1;
    wxTextCtrl* txtFreq_CLK4;
    wxStaticText* StaticText4;
    wxTextCtrl* txtCLKIN_MHz;
    wxCheckBox* chkInvert_CLK7;
    wxCheckBox* chkInvert_CLK5;
    wxCheckBox* chkEN_CLK2;
    wxCheckBox* chkEN_CLK0;
    wxCheckBox* chkInvert_CLK4;
    //*)

protected:

    //(*Identifiers(pnlSi5351)
    static const long ID_BUTTON2;
    static const long ID_BUTTON4;
    static const long ID_STATICTEXT1;
    static const long ID_TEXTCTRL1;
    static const long ID_STATICTEXT2;
    static const long ID_STATICTEXT11;
    static const long ID_STATICTEXT12;
    static const long ID_STATICTEXT13;
    static const long ID_STATICTEXT3;
    static const long ID_CHECKBOX1;
    static const long ID_TEXTCTRL2;
    static const long ID_CHECKBOX9;
    static const long ID_STATICTEXT4;
    static const long ID_CHECKBOX2;
    static const long ID_TEXTCTRL3;
    static const long ID_CHECKBOX10;
    static const long ID_STATICTEXT5;
    static const long ID_CHECKBOX3;
    static const long ID_TEXTCTRL4;
    static const long ID_CHECKBOX11;
    static const long ID_STATICTEXT6;
    static const long ID_CHECKBOX4;
    static const long ID_TEXTCTRL5;
    static const long ID_CHECKBOX12;
    static const long ID_STATICTEXT7;
    static const long ID_CHECKBOX5;
    static const long ID_TEXTCTRL6;
    static const long ID_CHECKBOX13;
    static const long ID_STATICTEXT8;
    static const long ID_CHECKBOX6;
    static const long ID_TEXTCTRL7;
    static const long ID_CHECKBOX14;
    static const long ID_STATICTEXT9;
    static const long ID_CHECKBOX7;
    static const long ID_TEXTCTRL8;
    static const long ID_CHECKBOX15;
    static const long ID_STATICTEXT10;
    static const long ID_CHECKBOX8;
    static const long ID_TEXTCTRL9;
    static const long ID_CHECKBOX16;
    static const long ID_BUTTON3;
    //*)

private:
    Si5351C *m_pModule;
    //(*Handlers(pnlSi5351)
    void OnbtnLoadFileClick(wxCommandEvent& event);
    void OnbtnConfigureClockClick(wxCommandEvent& event);
    void OnbtnResetToDefaultsClick(wxCommandEvent& event);
    //*)

protected:

    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

    DECLARE_EVENT_TABLE()
};

#endif
