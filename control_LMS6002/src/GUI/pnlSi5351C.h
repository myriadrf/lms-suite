#ifndef pnlSi5351_H
#define pnlSi5351_H

#include "Si5351C.h"

//(*Headers(pnlSi5351C)
#include <wx/panel.h>
class wxTextCtrl;
class wxStaticBoxSizer;
class wxFlexGridSizer;
class wxButton;
class wxStaticText;
class wxCheckBox;
//*)

class pnlSi5351C: public wxPanel
{
public:

    pnlSi5351C(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style = 0, wxString name="");
    virtual ~pnlSi5351C();

    //(*Declarations(pnlSi5351C)
    wxTextCtrl* txtFreq_CLK0;
    wxCheckBox* chkEN_CLK5;
    wxStaticText* StaticText13;
    wxCheckBox* chkInvert_CLK7;
    wxTextCtrl* txtFreq_CLK1;
    wxCheckBox* chkInvert_CLK4;
    wxStaticText* StaticText1;
    wxStaticText* StaticText10;
    wxCheckBox* chkInvert_CLK2;
    wxTextCtrl* txtFreq_CLK2;
    wxStaticText* StaticText3;
    wxCheckBox* chkEN_CLK2;
    wxTextCtrl* txtFreq_CLK6;
    wxCheckBox* chkEN_CLK7;
    wxStaticText* StaticText8;
    wxStaticText* StaticText12;
    wxButton* btnResetToDefaults;
    wxTextCtrl* txtFreq_CLK3;
    wxStaticText* StaticText7;
    wxCheckBox* chkEN_CLK6;
    wxTextCtrl* txtFreq_CLK4;
    wxStaticText* StaticText4;
    wxCheckBox* chkInvert_CLK5;
    wxStaticText* StaticText5;
    wxStaticText* StaticText2;
    wxCheckBox* chkEN_CLK3;
    wxCheckBox* chkInvert_CLK6;
    wxCheckBox* chkEN_CLK4;
    wxStaticText* StaticText6;
    wxTextCtrl* txtFreq_CLK5;
    wxButton* btnLoadFile;
    wxTextCtrl* txtFreq_CLK7;
    wxTextCtrl* txtCLKIN_MHz;
    wxCheckBox* chkInvert_CLK0;
    wxCheckBox* chkInvert_CLK1;
    wxButton* btnConfigure;
    wxCheckBox* chkEN_CLK0;
    wxStaticText* StaticText9;
    wxCheckBox* chkInvert_CLK3;
    wxButton* btnUpload;
    wxCheckBox* chkEN_CLK1;
    wxStaticText* StaticText11;
    //*)

protected:

    //(*Identifiers(pnlSi5351C)
    static const long ID_BUTTON1;
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
    //(*Handlers(pnlSi5351C)
    void OnbtnLoadFileClick(wxCommandEvent& event);
    void OnbtnConfigureClockClick(wxCommandEvent& event);
    void OnbtnResetToDefaultsClick(wxCommandEvent& event);
    //*)

protected:

    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

    DECLARE_EVENT_TABLE()
};

#endif
