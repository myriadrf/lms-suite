// -----------------------------------------------------------------------------
// FILE: 		pnlCDS.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef pnlCDS_H
#define pnlCDS_H
//(*Headers(pnlCDS)
#include <wx/panel.h>
class wxCheckBox;
class wxRadioBox;
class wxFlexGridSizer;
class wxStaticBoxSizer;
//*)
#include <map>
#include "RegistersMap.h"
#include "GUIPanel.h"
class LMS7002_MainControl;
class StdCombobox;
class pnlCDS : public wxPanel, GUIPanel
{
public:
    pnlCDS(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style=0, wxString name="");
    void Initialize(LMS7002_MainControl *pControl);
    void UpdateGUI();
    virtual ~pnlCDS();

//(*Declarations(pnlCDS)
wxRadioBox* rgrCDS_TXBLML;
wxCheckBox* chkCDSN_RXALML ;
wxCheckBox* chkCDSN_TXBLML;
wxRadioBox* rgrCDS_MCLK1;
wxRadioBox* rgrCDS_RXBTSP;
wxRadioBox* rgrCDS_RXBLML;
wxCheckBox* chkCDSN_TXATSP;
wxCheckBox* chkCDSN_RXATSP;
wxCheckBox* chkCDSN_RXBTSP;
wxCheckBox* chkCDSN_TXALML;
wxCheckBox* chkCDSN_MCLK2;
wxRadioBox* rgrCDS_RXATSP;
wxRadioBox* rgrCDS_RXALML;
wxRadioBox* rgrCDS_TXALML;
wxCheckBox* chkCDSN_TXBTSP;
wxCheckBox* chkCDSN_MCLK1;
wxCheckBox* chkCDSN_RXBLML;
wxRadioBox* rgrCDS_TXATSP;
wxRadioBox* rgrCDS_TXBTSP;
wxRadioBox* rgrCDS_MCLK2;
//*)

protected:
//(*Identifiers(pnlCDS)
static const long ID_CDSN_TXBTSP;
static const long ID_CDSN_TXATSP;
static const long ID_CDSN_RXBTSP;
static const long ID_CDSN_RXATSP;
static const long ID_CDSN_TXBLML;
static const long ID_CDSN_TXALML;
static const long ID_CDSN_RXBLML;
static const long ID_CDSN_RXALML ;
static const long ID_CDSN_MCLK2;
static const long ID_CDSN_MCLK1;
static const long ID_CDS_MCLK2;
static const long ID_CDS_MCLK1;
static const long ID_CDS_TXBTSP;
static const long ID_CDS_TXATSP;
static const long ID_CDS_RXBTSP;
static const long ID_CDS_RXATSP;
static const long ID_CDS_TXBLML;
static const long ID_CDS_TXALML;
static const long ID_CDS_RXBLML;
static const long ID_CDS_RXALML;
//*)

private:
//(*Handlers(pnlCDS)
    void ParameterChangeHandler(wxCommandEvent& event);
//*)

protected:
    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);
    void AssignEnumsToIds();
    DECLARE_EVENT_TABLE()
};
#endif
