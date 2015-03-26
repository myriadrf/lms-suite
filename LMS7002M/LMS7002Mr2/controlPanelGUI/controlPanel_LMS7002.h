// -----------------------------------------------------------------------------
// FILE: 		controlPanel_LMS7002.h
// DESCRIPTION: Header for controlPanel_LMS7002.cpp
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef CONTROLPANEL_LMS7002_H
#define CONTROLPANEL_LMS7002_H

#include <wx/notebook.h>
#include "SignalHandler.h"
#include "dlgRegisterMap.h"
//(*Headers(controlPanel_LMS7002)
#include <wx/frame.h>
class wxPanel;
class wxStatusBar;
class wxCheckBox;
class wxNotebookEvent;
class wxMenuBar;
class wxRichTextCtrl;
class wxNotebook;
class wxRadioButton;
class wxStaticText;
class wxMenu;
class wxFlexGridSizer;
class wxButton;
class wxStaticBoxSizer;
//*)

class LMS7002_MainControl;
class pnlSi5351;
class pnlADF;
class pnlRFE;
class pnlRBB;
class pnlTRF;
class pnlTBB;
class pnlLDO;
class pnlAFE;
class pnlBIAS;
class pnlXBUF;
class pnlCLKGEN;
class pnlSXT;
class pnlLimeLightPAD;
class pnlTxTSP;
class pnlRxTSP;
class pnlBIST;
class pnlCDS;
class pnlMCU_BD;
class pnlSPI;

class controlPanel_LMS7002: public wxFrame, public SignalHandler
{
public:
    void HandleMessage(const LMS_Message &msg);
    static void MessageHandler(const int signal, const char *msg, const int paraml);

    controlPanel_LMS7002(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    void SwitchChannel(int channel, bool configBoth);
    void Initialize();
    void UpdateGUI();
    void UpdateStatusBar();
    virtual ~controlPanel_LMS7002();

    //(*Declarations(controlPanel_LMS7002)
    wxRadioButton* rbtnEnChannelA;
    wxMenuItem* mnuRegistersMap;
    wxMenuItem* mnuRegistersTest;
    pnlTxTSP* tabTxTSP;
    pnlXBUF* tabXBUF;
    wxMenuItem* mnu_VerifyWrittenData;
    wxButton* btnClearMsgLog;
    pnlADF* tabADF4002;
    pnlBIAS* tabBIAS;
    wxButton* btnSaveProject;
    wxButton* btnNewProject;
    wxMenuItem* mnuSaveRegistersRVHEX;
    wxMenu* Menu3;
    pnlTBB* tabTBB;
    pnlCLKGEN* tabCLKGEN;
    wxCheckBox* chkSyncAB;
    wxRadioButton* rbtnEnChannelB;
    wxMenuItem* mnuReadToHex;
    wxMenuItem* menuConnectionSettings;
    pnlTRF* tabTRF;
    pnlCDS* tabCDS;
    wxNotebook* m_modulesNotebook;
    pnlRFE* tabRFE;
    wxButton* btnDownloadAll;
    pnlAFE* tabAFE;
    pnlLimeLightPAD* tabLimeLightPAD;
    wxMenuItem* mnuOpen;
    wxMenuItem* mnuNew;
    wxButton* btnReset;
    pnlRxTSP* tabRxTSP;
    pnlLDO* tabLDO;
    pnlBIST* tabBIST;
    wxStaticText* txtActiveChannel;
    pnlSPI* tabSPI;
    wxButton* btnUploadAll;
    wxRichTextCtrl* txtMessageLog;
    pnlMCU_BD* tabMCU_BD;
    wxFlexGridSizer* m_channelNameLayout;
    wxButton* btnOpenProject;
    wxButton* btnShowLog;
    wxMenuItem* mnuSave;
    pnlSXT* tabSXT;
    wxMenu* Menu4;
    pnlRBB* tabRBB;
    pnlSi5351* tabSi5351;
    wxStatusBar* m_controlStatusbar;
    //*)

protected:

    //(*Identifiers(controlPanel_LMS7002)
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_STATICTEXT1;
    static const long ID_BUTTON5;
    static const long ID_BUTTON6;
    static const long ID_BUTTON8;
    static const long ID_CHECKBOX1;
    static const long ID_RADIOBUTTON1;
    static const long ID_RADIOBUTTON2;
    static const long ID_TABSI5351;
    static const long ID_ADF;
    static const long ID_RFE;
    static const long ID_RBB;
    static const long ID_TRF;
    static const long ID_TBB;
    static const long ID_AFE;
    static const long ID_BIAS;
    static const long ID_LDO;
    static const long ID_XBUF;
    static const long ID_CLKGEN;
    static const long ID_SXRSXT;
    static const long ID_LIMELIGHTPAD;
    static const long ID_TXTSP;
    static const long ID_RXTSP;
    static const long ID_CDS;
    static const long ID_MCUBD;
    static const long ID_BIST;
    static const long ID_SPITAB;
    static const long ID_NOTEBOOK1;
    static const long ID_CONTROL_PANEL_MSG_LOG;
    static const long ID_BUTTON4;
    static const long ID_BUTTON7;
    static const long ID_MENUITEM2;
    static const long ID_MENUITEM3;
    static const long ID_MENUITEM4;
    static const long ID_MENUITEM5;
    static const long ID_MENUITEM7;
    static const long idMenuQuit;
    static const long ID_MENU_CONNECTION_SETTINGS;
    static const long ID_MENUITEM8;
    static const long ID_MENUITEM1;
    static const long ID_MENUITEM6;
    static const long idMenuAbout;
    static const long ID_CONTROL_STATUSBAR;
    //*)

private:

    //(*Handlers(controlPanel_LMS7002)
    void OnQuit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    void OnbtnClearMsgLogClick(wxCommandEvent& event);
    void OnbtnFindDevicesClick(wxCommandEvent& event);
    void OnmenuConnectionSettingsSelected(wxCommandEvent& event);
    void OnbtnNewProjectClick(wxCommandEvent& event);
    void OnbtnUpdateGUIClick(wxCommandEvent& event);
    void OnbtnOpenProjectClick(wxCommandEvent& event);
    void OnbtnSaveProjectClick(wxCommandEvent& event);
    void OnbtnUploadAllClick(wxCommandEvent& event);
    void OnConfiguringChannelsChange(wxCommandEvent& event);
    void Onmnu_SaveRegistersToFileSelected(wxCommandEvent& event);
    void OnbtnDownloadAllClick(wxCommandEvent& event);
    void OnmnuResetChipSelected(wxCommandEvent& event);
    void OnbtnShowLogClick(wxCommandEvent& event);
    void OnmnuRegistersTestSelected(wxCommandEvent& event);
    void OnbtnResetClick(wxCommandEvent& event);
    void OnmnuReadToHexSelected(wxCommandEvent& event);
    void OnmnuRegistersMapSelected(wxCommandEvent& event);
    void Onm_modulesNotebookPageChanged(wxNotebookEvent& event);
    void OnmnuSaveRegistersRVHEXSelected(wxCommandEvent& event);
    void Onmnu_VerifyWrittenDataSelected(wxCommandEvent& event);
    //*)
protected:
    bool m_overrideChannel;
    int m_selectedChannel;
    int m_lastUsedChannel;
    int m_selectedTab;
    dlgRegisterMap *m_regMapDlg;
    LMS7002_MainControl *lmsControl;
    void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

    DECLARE_EVENT_TABLE()
};

#endif
