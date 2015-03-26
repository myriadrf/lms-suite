// -----------------------------------------------------------------------------
// FILE: 		pnlLimeLightPAD.h
// DESCRIPTION:
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef pnlLimeLightPAD_H
#define pnlLimeLightPAD_H
//(*Headers(pnlLimeLightPAD)
#include <wx/panel.h>
class wxCheckBox;
class wxNotebookEvent;
class wxComboBox;
class wxStaticLine;
class wxRadioBox;
class wxNotebook;
class wxStaticText;
class wxFlexGridSizer;
class wxStaticBoxSizer;
//*)
#include <map>
#include "RegistersMap.h"
#include "GUIPanel.h"
class LMS7002_MainControl;
class StdCombobox;
class pnlLimeLightPAD : public wxPanel, GUIPanel
{
public:
    pnlLimeLightPAD(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize, int style=0, wxString name="");
    void Initialize(LMS7002_MainControl *pControl);
    void UpdateGUI();
    virtual ~pnlLimeLightPAD();

//(*Declarations(pnlLimeLightPAD)
wxStaticText* StaticText10;
wxStaticText* StaticText22;
wxStaticText* StaticText9;
StdCombobox* cmbLML2_RX_PRE;
wxStaticText* StaticText20;
wxRadioBox* rgrMAC;
wxStaticText* StaticText29;
wxNotebook* Notebook1;
wxCheckBox* chkTXEN_B;
wxCheckBox* chkSRST_RXFIFO;
StdCombobox* cmbLML1_S0S;
wxStaticText* StaticText13;
wxStaticText* StaticText33;
wxStaticText* StaticText2;
wxCheckBox* chkTXDIVEN;
wxCheckBox* chkFCLK1_PE;
wxStaticText* StaticText30;
wxStaticText* StaticText14;
wxCheckBox* chkMRST_RX_B;
wxCheckBox* chkMRST_TX_B;
wxStaticText* StaticText26;
wxStaticText* StaticText6;
wxCheckBox* chkTXNRX1_PE;
wxCheckBox* chkMCLK2_PE;
wxCheckBox* chkSCL_PE;
StdCombobox* cmbLML1_BIP;
StdCombobox* cmbLML2_RX_PST;
StdCombobox* cmbLML1_S1S;
wxStaticText* StaticText19;
wxStaticText* StaticText32;
StdCombobox* cmbLML1_TX_PST;
wxStaticText* StaticText8;
wxStaticText* StaticText11;
wxStaticText* StaticText18;
wxCheckBox* chkDIQ1_PE;
wxStaticText* StaticText31;
wxPanel* Panel1;
wxRadioBox* rgrSCL_DS;
wxCheckBox* chkLRST_TX_B;
StdCombobox* cmbRXRDCLK_MUX;
wxStaticText* StaticText1;
wxCheckBox* chkIQ_SEL_EN_2_PE;
wxStaticText* StaticText27;
StdCombobox* cmbLML2_AQP;
wxStaticText* StaticText3;
wxCheckBox* chkFCLK2_PE;
wxCheckBox* chkIQ_SEL_EN_1_PE;
wxRadioBox* rgrSDIO_DS;
wxStaticText* StaticText21;
wxCheckBox* chkMCLK1_PE;
StdCombobox* cmbMCLK2SRC;
StdCombobox* cmbLML1_BQP;
StdCombobox* cmbRXWRCLK_MUX;
wxStaticText* StaticText23;
wxStaticText* StaticText24;
wxRadioBox* rgrDIQ2_DS;
wxCheckBox* chkSRST_TXFIFO;
StdCombobox* cmbTXTSPCLKA_DIV;
StdCombobox* cmbLML1_RX_PRE;
wxCheckBox* chkTXNRX2_PE;
wxCheckBox* chkRXDIVEN;
wxCheckBox* chkMRST_TX_A;
wxCheckBox* chkDIQ2_PE;
StdCombobox* cmbDLB_MUX;
StdCombobox* cmbLML2_S2S;
StdCombobox* cmbLML2_TX_PST;
wxStaticText* StaticText5;
wxStaticText* StaticText34;
wxStaticText* StaticText7;
wxCheckBox* chkMOD_EN;
wxRadioBox* rgrSDA_DS;
StdCombobox* cmbTXWRCLK_MUX;
StdCombobox* cmbLML1_S2S;
wxCheckBox* chkTXEN_A;
wxCheckBox* chkLRST_RX_A;
wxRadioBox* rgrLML_MODE2;
wxCheckBox* chkRXEN_A;
wxCheckBox* chkMRST_RX_A;
wxStaticLine* StaticLine1;
wxRadioBox* rgrLML_TXNRXIQ2;
StdCombobox* cmbLML2_S0S;
wxCheckBox* chkSEN_PE;
wxStaticText* StaticText28;
wxCheckBox* chkTX_CLK_PE;
wxCheckBox* chkRXEN_B;
wxRadioBox* rgrLML_TXNRXIQ1;
wxStaticText* StaticText15;
wxRadioBox* rgrLML_FIDM2;
StdCombobox* cmbLML1_RX_PST;
wxStaticText* StaticText12;
StdCombobox* cmbLML1_AIP;
StdCombobox* cmbMCLK1SRC;
wxStaticText* StaticText35;
StdCombobox* cmbTXRDCLK_MUX;
wxPanel* Panel2;
StdCombobox* cmbLML2_S3S;
wxRadioBox* rgrLML_FIDM1;
wxCheckBox* chkSCLK_PE;
wxCheckBox* chkSDO_PE;
wxStaticText* StaticText25;
StdCombobox* cmbLML2_BQP;
StdCombobox* cmbLML1_S3S;
wxCheckBox* chkLRST_TX_A;
StdCombobox* cmbRXTSPCLKA_DIV;
StdCombobox* cmbLML2_S1S;
StdCombobox* cmbLML2_TX_PRE;
wxStaticText* StaticText17;
wxStaticText* StaticText4;
wxRadioBox* rgrSPIMODE;
wxRadioBox* rgrDIQ1_DS;
wxCheckBox* chkSDIO_PE;
wxCheckBox* chkRX_CLK_PE;
StdCombobox* cmbTX_MUX;
wxRadioBox* rgrLML_MODE1;
StdCombobox* cmbLML1_AQP;
wxCheckBox* chkLRST_RX_B;
StdCombobox* cmbLML2_AIP;
wxCheckBox* chkSDA_PE;
wxStaticText* StaticText16;
StdCombobox* cmbMIMO_SISO;
StdCombobox* cmbLML1_TX_PRE;
StdCombobox* cmbLML2_BIP;
//*)

protected:
//(*Identifiers(pnlLimeLightPAD)
static const long ID_TX_CLK_PE;
static const long ID_RX_CLK_PE;
static const long ID_SDA_PE;
static const long ID_SCL_PE;
static const long ID_SDIO_PE;
static const long ID_SDO_PE;
static const long ID_SCLK_PE;
static const long ID_SEN_PE;
static const long ID_DIQ2_PE;
static const long ID_IQ_SEL_EN_2_PE;
static const long ID_TXNRX2_PE;
static const long ID_FCLK2_PE;
static const long ID_MCLK2_PE;
static const long ID_DIQ1_PE;
static const long ID_IQ_SEL_EN_1_PE;
static const long ID_TXNRX1_PE;
static const long ID_FCLK1_PE;
static const long ID_MCLK1_PE;
static const long ID_MOD_EN;
static const long ID_STATICLINE1;
static const long ID_LML_FIDM1;
static const long ID_LML_FIDM2;
static const long ID_LML_MODE1;
static const long ID_LML_MODE2;
static const long ID_LML_TXNRXIQ1;
static const long ID_LML_TXNRXIQ2;
static const long ID_LRST_TX_B;
static const long ID_MRST_TX_B;
static const long ID_LRST_TX_A;
static const long ID_MRST_TX_A;
static const long ID_LRST_RX_B;
static const long ID_MRST_RX_B;
static const long ID_LRST_RX_A;
static const long ID_MRST_RX_A;
static const long ID_SRST_RXFIFO;
static const long ID_SRST_TXFIFO;
static const long ID_SDA_DS;
static const long ID_SCL_DS;
static const long ID_SDIO_DS;
static const long ID_DIQ2_DS;
static const long ID_DIQ1_DS;
static const long ID_STATICTEXT33;
static const long ID_DLB_MUX;
static const long ID_STATICTEXT34;
static const long ID_TX_MUX;
static const long ID_STATICTEXT35;
static const long ID_MIMO_SISO;
static const long ID_SPIMODE;
static const long ID_MAC;
static const long ID_RXEN_B;
static const long ID_RXEN_A;
static const long ID_TXEN_B;
static const long ID_TXEN_A;
static const long ID_PANEL1;
static const long ID_STATICTEXT1;
static const long ID_LML1_S3S;
static const long ID_STATICTEXT2;
static const long ID_LML1_S2S;
static const long ID_STATICTEXT3;
static const long ID_LML1_S1S;
static const long ID_STATICTEXT4;
static const long ID_LML1_S0S;
static const long ID_STATICTEXT5;
static const long ID_LML1_BQP;
static const long ID_STATICTEXT6;
static const long ID_LML1_BIP;
static const long ID_STATICTEXT7;
static const long ID_LML1_AQP;
static const long ID_STATICTEXT8;
static const long ID_LML1_AIP;
static const long ID_STATICTEXT9;
static const long ID_LML2_S3S;
static const long ID_STATICTEXT10;
static const long ID_LML2_S2S;
static const long ID_STATICTEXT11;
static const long ID_LML2_S1S;
static const long ID_STATICTEXT12;
static const long ID_LML2_S0S;
static const long ID_STATICTEXT13;
static const long ID_LML2_BQP;
static const long ID_STATICTEXT14;
static const long ID_LML2_BIP;
static const long ID_STATICTEXT15;
static const long ID_LML2_AQP;
static const long ID_STATICTEXT16;
static const long ID_LML2_AIP;
static const long ID_STATICTEXT25;
static const long ID_TXRDCLK_MUX;
static const long ID_STATICTEXT26;
static const long ID_TXWRCLK_MUX;
static const long ID_STATICTEXT27;
static const long ID_RXRDCLK_MUX;
static const long ID_STATICTEXT28;
static const long ID_RXWRCLK_MUX;
static const long ID_STATICTEXT29;
static const long ID_MCLK2SRC;
static const long ID_STATICTEXT30;
static const long ID_MCLK1SRC;
static const long ID_STATICTEXT31;
static const long ID_TXTSPCLKA_DIV;
static const long ID_STATICTEXT32;
static const long ID_RXTSPCLKA_DIV;
static const long ID_TXDIVEN;
static const long ID_RXDIVEN;
static const long ID_STATICTEXT17;
static const long ID_LML1_TX_PST;
static const long ID_STATICTEXT18;
static const long ID_LML1_TX_PRE;
static const long ID_STATICTEXT19;
static const long ID_LML1_RX_PST;
static const long ID_STATICTEXT20;
static const long ID_LML1_RX_PRE;
static const long ID_STATICTEXT21;
static const long ID_LML2_TX_PST;
static const long ID_STATICTEXT22;
static const long ID_LML2_TX_PRE;
static const long ID_STATICTEXT23;
static const long ID_LML2_RX_PST;
static const long ID_STATICTEXT24;
static const long ID_LML2_RX_PRE;
static const long ID_PANEL2;
static const long ID_NOTEBOOK1;
//*)

private:
//(*Handlers(pnlLimeLightPAD)
    void ParameterChangeHandler(wxCommandEvent& event);
//*)

protected:
    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);
    void AssignEnumsToIds();
    DECLARE_EVENT_TABLE()
};
#endif
