// -----------------------------------------------------------------------------
// FILE: 		controlPanel_LMS7002.cpp
// DESCRIPTION: main program window
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#include "controlPanel_LMS7002.h"
#include "../version.h"

#include <iostream>
#include <vector>
using namespace std;

#include "MessageLog.h"
#include "../CommonUtilities.h"
#include "LMS7002_MainControl.h"
#include "ConnectionManager.h"
#include "pnlSi5351.h"
#include "pnlADF.h"
#include "pnlRFE.h"
#include "pnlRBB.h"
#include "pnlTRF.h"
#include "pnlTBB.h"
#include "pnlAFE.h"
#include "pnlBIAS.h"
#include "pnlLDO.h"
#include "pnlXBUF.h"
#include "pnlCLKGEN.h"
#include "pnlSXT.h"
#include "pnlLimeLightPAD.h"
#include "pnlTxTSP.h"
#include "pnlRxTSP.h"
#include "pnlBIST.h"
#include "pnlCDS.h"
#include "pnlMCU_BD.h"
#include "pnlSPI.h"

#include "dlgAbout.h"
#include "dlgMessageLog.h"
#include "dlgConnectionManager.h"
#include "dlgRegisterTest.h"
#include <wx/msgdlg.h>
#include <wx/listbox.h>
#include <wx/radiobox.h>
//(*InternalHeaders(controlPanel_LMS7002)
#include <wx/notebook.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/checkbox.h>
#include <wx/radiobut.h>
#include <wx/panel.h>
#include <wx/settings.h>
#include <wx/font.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/intl.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/statusbr.h>
//*)

//(*IdInit(controlPanel_LMS7002)
const long controlPanel_LMS7002::ID_BUTTON1 = wxNewId();
const long controlPanel_LMS7002::ID_BUTTON2 = wxNewId();
const long controlPanel_LMS7002::ID_BUTTON3 = wxNewId();
const long controlPanel_LMS7002::ID_STATICTEXT1 = wxNewId();
const long controlPanel_LMS7002::ID_BUTTON5 = wxNewId();
const long controlPanel_LMS7002::ID_BUTTON6 = wxNewId();
const long controlPanel_LMS7002::ID_BUTTON8 = wxNewId();
const long controlPanel_LMS7002::ID_CHECKBOX1 = wxNewId();
const long controlPanel_LMS7002::ID_RADIOBUTTON1 = wxNewId();
const long controlPanel_LMS7002::ID_RADIOBUTTON2 = wxNewId();
const long controlPanel_LMS7002::ID_TABSI5351 = wxNewId();
const long controlPanel_LMS7002::ID_ADF = wxNewId();
const long controlPanel_LMS7002::ID_RFE = wxNewId();
const long controlPanel_LMS7002::ID_RBB = wxNewId();
const long controlPanel_LMS7002::ID_TRF = wxNewId();
const long controlPanel_LMS7002::ID_TBB = wxNewId();
const long controlPanel_LMS7002::ID_AFE = wxNewId();
const long controlPanel_LMS7002::ID_BIAS = wxNewId();
const long controlPanel_LMS7002::ID_LDO = wxNewId();
const long controlPanel_LMS7002::ID_XBUF = wxNewId();
const long controlPanel_LMS7002::ID_CLKGEN = wxNewId();
const long controlPanel_LMS7002::ID_SXRSXT = wxNewId();
const long controlPanel_LMS7002::ID_LIMELIGHTPAD = wxNewId();
const long controlPanel_LMS7002::ID_TXTSP = wxNewId();
const long controlPanel_LMS7002::ID_RXTSP = wxNewId();
const long controlPanel_LMS7002::ID_CDS = wxNewId();
const long controlPanel_LMS7002::ID_MCUBD = wxNewId();
const long controlPanel_LMS7002::ID_BIST = wxNewId();
const long controlPanel_LMS7002::ID_SPITAB = wxNewId();
const long controlPanel_LMS7002::ID_NOTEBOOK1 = wxNewId();
const long controlPanel_LMS7002::ID_CONTROL_PANEL_MSG_LOG = wxNewId();
const long controlPanel_LMS7002::ID_BUTTON4 = wxNewId();
const long controlPanel_LMS7002::ID_BUTTON7 = wxNewId();
const long controlPanel_LMS7002::ID_MENUITEM2 = wxNewId();
const long controlPanel_LMS7002::ID_MENUITEM3 = wxNewId();
const long controlPanel_LMS7002::ID_MENUITEM4 = wxNewId();
const long controlPanel_LMS7002::ID_MENUITEM5 = wxNewId();
const long controlPanel_LMS7002::ID_MENUITEM7 = wxNewId();
const long controlPanel_LMS7002::idMenuQuit = wxNewId();
const long controlPanel_LMS7002::ID_MENU_CONNECTION_SETTINGS = wxNewId();
const long controlPanel_LMS7002::ID_MENUITEM8 = wxNewId();
const long controlPanel_LMS7002::ID_MENUITEM1 = wxNewId();
const long controlPanel_LMS7002::ID_MENUITEM6 = wxNewId();
const long controlPanel_LMS7002::idMenuAbout = wxNewId();
const long controlPanel_LMS7002::ID_CONTROL_STATUSBAR = wxNewId();
//*)

BEGIN_EVENT_TABLE(controlPanel_LMS7002,wxFrame)
    //(*EventTable(controlPanel_LMS7002)
    //*)
END_EVENT_TABLE()

controlPanel_LMS7002 *g_pControlPanel = NULL;

const string cWindowTitle = "Control LMS7002";
const int cDeviceInfoCollumn = 1;

/** @brief Handles messages coming from control logic
    @param msg message about event
*/
void controlPanel_LMS7002::HandleMessage(const LMS_Message &msg)
{
    string stemp;
    switch(msg.type)
    {
    case MSG_BOARD_CONNECTED:
        stemp = cWindowTitle;
        stemp.append(" - ");
        stemp.append(msg.text);
        SetTitle( stemp );

        stemp = msg.text;
        stemp = stemp.substr( stemp.find_first_of("|")+1, string::npos);
        m_controlStatusbar->SetStatusText(stemp, cDeviceInfoCollumn);

        break;
    case MSG_BOARD_DISCONNECTED:
        SetTitle( cWindowTitle );
        m_controlStatusbar->SetStatusText("Board disconnected", cDeviceInfoCollumn);
        break;
    case MSG_REGISTER_TEST:
        if(tabSPI)
            tabSPI->PrintLine(msg.text);
        break;
    case MSG_PROGRAMMING_PACKET_SENT:
        if(tabMCU_BD)
            tabMCU_BD->SetProgressBar(msg.param1);
        break;
    default:
        break;
    }

    if(msg.type == MSG_CRITICAL_ERROR)
    {
        wxMessageDialog dlg(this, msg.text, "Critical error");
        dlg.ShowModal();
    }
    else if(msg.type == MSG_SHOW_WARNING)
    {
        wxMessageDialog dlg(this, msg.text, "WARNING");
        dlg.ShowModal();
    }
}

controlPanel_LMS7002::controlPanel_LMS7002(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    m_overrideChannel = false;
    m_lastUsedChannel = 0;
    m_selectedChannel = 0;
    m_regMapDlg = NULL;
    g_pControlPanel = this;
    long t1 = getMilis();
    lmsControl = new LMS7002_MainControl();
    long t2 = getMilis();
    BuildContent(parent,id,pos,size);
    SetTitle( cWindowTitle );
    m_selectedTab = m_modulesNotebook->GetSelection();
    m_controlStatusbar->SetStatusText("Board disconnected", cDeviceInfoCollumn);
    cout << "control panel build content " << getMilis()-t2 << " ms" << endl;
#warning icon from resources not implemented for linux
    #ifndef LINUX
    SetIcon(wxICON(ControlPanel_icon));
    #endif
    Initialize();
    cout << "control panel created in " << getMilis()-t1 << " ms" << endl;
    MessageLog::getInstance()->registerForNotifications( MessageHandler );

    lmsControl->RegisterForNotifications(this);
}

void controlPanel_LMS7002::Initialize()
{
    long t1 = getMilis();
    long ti = t1;

    lmsControl->getRegistersMap()->SetAutoUpload(false);
    tabADF4002->Initialize( lmsControl->getADF() );
    cout << "ADF4002 initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabSi5351->Initialize( lmsControl->getSi5356() );
    cout << "Si5356 initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabRFE->Initialize( lmsControl );
    cout << "RFE initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabRBB->Initialize( lmsControl );
    cout << "RBB initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabTRF->Initialize( lmsControl );
    cout << "TRF initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabTBB->Initialize( lmsControl );
    cout << "TBB initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabAFE->Initialize( lmsControl );
    cout << "AFE initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabBIAS->Initialize( lmsControl );
    cout << "BIAS initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabLDO->Initialize( lmsControl );
    cout << "LDO initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabXBUF->Initialize( lmsControl );
    cout << "XBUF initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabCLKGEN->Initialize( lmsControl );
    cout << "CLKGEN initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabSXT->Initialize( lmsControl );
    cout << "SXT initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabLimeLightPAD->Initialize( lmsControl );
    cout << "LIME ligth initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabTxTSP->Initialize( lmsControl );
    cout << "Tx TSP initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabRxTSP->Initialize( lmsControl );
    cout << "Rx TSP initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabBIST->Initialize( lmsControl );
    cout << "BIST initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabCDS->Initialize( lmsControl );
    cout << "CDS initialized in " << getMilis()-ti << " ms" << endl;
    ti = getMilis();
    tabMCU_BD->Initialize(lmsControl);
    cout << "MCU_BD initialized in " << getMilis()-ti << " ms" << endl;

    tabSPI->Initialize(lmsControl);

    cout << "control panel initialized in " << getMilis()-t1 << " ms" << endl;

    //lmsControl->getSerPort()->Open();

    UpdateGUI();
    lmsControl->getRegistersMap()->SetAutoUpload(true);

    m_regMapDlg = new dlgRegisterMap(this);
    m_regMapDlg->Initialize(lmsControl);
}

void controlPanel_LMS7002::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(controlPanel_LMS7002)
    wxFlexGridSizer* FlexGridSizer4;
    wxMenuItem* MenuItem2;
    wxFlexGridSizer* controlPanelSizer;
    wxFlexGridSizer* flexgridToolbar;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxStaticBoxSizer* StaticBoxSizer1;
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu2;
    wxMenuBar* m_ControlManuBar;

    Create(parent, id, _("LMS_7002M control panel"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxDEFAULT_FRAME_STYLE|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX|wxCLIP_CHILDREN, _T("id"));
    SetClientSize(wxSize(1024,750));
    SetMinSize(wxSize(1024,600));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNFACE));
    controlPanelSizer = new wxFlexGridSizer(3, 1, 0, 0);
    controlPanelSizer->AddGrowableCol(0);
    controlPanelSizer->AddGrowableRow(1);
    flexgridToolbar = new wxFlexGridSizer(0, 7, 0, 0);
    flexgridToolbar->AddGrowableCol(3);
    btnNewProject = new wxButton(this, ID_BUTTON1, _("New"), wxDefaultPosition, wxSize(50,35), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    flexgridToolbar->Add(btnNewProject, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnOpenProject = new wxButton(this, ID_BUTTON2, _("Open"), wxDefaultPosition, wxSize(50,35), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    flexgridToolbar->Add(btnOpenProject, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnSaveProject = new wxButton(this, ID_BUTTON3, _("Save"), wxDefaultPosition, wxSize(50,35), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    flexgridToolbar->Add(btnSaveProject, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_channelNameLayout = new wxFlexGridSizer(0, 2, 0, 0);
    txtActiveChannel = new wxStaticText(this, ID_STATICTEXT1, _("Active Ch: A&&B"), wxDefaultPosition, wxSize(327,39), wxALIGN_LEFT, _T("ID_STATICTEXT1"));
    wxFont txtActiveChannelFont(24,wxDEFAULT,wxFONTSTYLE_NORMAL,wxBOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    txtActiveChannel->SetFont(txtActiveChannelFont);
    m_channelNameLayout->Add(txtActiveChannel, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
    btnUploadAll = new wxButton(this, ID_BUTTON5, _("GUI --> Chip"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    FlexGridSizer4->Add(btnUploadAll, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    btnDownloadAll = new wxButton(this, ID_BUTTON6, _("Chip --> GUI"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    FlexGridSizer4->Add(btnDownloadAll, 1, wxLEFT|wxRIGHT|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    btnReset = new wxButton(this, ID_BUTTON8, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
    FlexGridSizer4->Add(btnReset, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_channelNameLayout->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    flexgridToolbar->Add(m_channelNameLayout, 1, wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Configuring Channels"));
    chkSyncAB = new wxCheckBox(this, ID_CHECKBOX1, _("Both"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    chkSyncAB->SetValue(true);
    StaticBoxSizer1->Add(chkSyncAB, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    rbtnEnChannelA = new wxRadioButton(this, ID_RADIOBUTTON1, _("A/SXR"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    rbtnEnChannelA->SetValue(true);
    StaticBoxSizer1->Add(rbtnEnChannelA, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    rbtnEnChannelB = new wxRadioButton(this, ID_RADIOBUTTON2, _("B/SXT"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    StaticBoxSizer1->Add(rbtnEnChannelB, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    flexgridToolbar->Add(StaticBoxSizer1, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    controlPanelSizer->Add(flexgridToolbar, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    m_modulesNotebook = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    m_modulesNotebook->SetMinSize(wxSize(800,450));
    tabSi5351 = new pnlSi5351(m_modulesNotebook, ID_TABSI5351, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_TABSI5351"));
    tabADF4002 = new pnlADF(m_modulesNotebook, ID_ADF, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_ADF"));
    tabRFE = new pnlRFE(m_modulesNotebook, ID_RFE, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_RFE"));
    tabRBB = new pnlRBB(m_modulesNotebook, ID_RBB, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_RBB"));
    tabTRF = new pnlTRF(m_modulesNotebook, ID_TRF, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_TRF"));
    tabTBB = new pnlTBB(m_modulesNotebook, ID_TBB, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_TBB"));
    tabAFE = new pnlAFE(m_modulesNotebook, ID_AFE, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_AFE"));
    tabBIAS = new pnlBIAS(m_modulesNotebook, ID_BIAS, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_BIAS"));
    tabLDO = new pnlLDO(m_modulesNotebook, ID_LDO, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_LDO"));
    tabXBUF = new pnlXBUF(m_modulesNotebook, ID_XBUF, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_XBUF"));
    tabCLKGEN = new pnlCLKGEN(m_modulesNotebook, ID_CLKGEN, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_CLKGEN"));
    tabSXT = new pnlSXT(m_modulesNotebook, ID_SXRSXT, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_SXRSXT"));
    tabLimeLightPAD = new pnlLimeLightPAD(m_modulesNotebook, ID_LIMELIGHTPAD, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_LIMELIGHTPAD"));
    tabTxTSP = new pnlTxTSP(m_modulesNotebook, ID_TXTSP, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_TXTSP"));
    tabRxTSP = new pnlRxTSP(m_modulesNotebook, ID_RXTSP, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_RXTSP"));
    tabCDS = new pnlCDS(m_modulesNotebook, ID_CDS, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_CDS"));
    tabMCU_BD = new pnlMCU_BD(m_modulesNotebook, ID_MCUBD, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_MCUBD"));
    tabBIST = new pnlBIST(m_modulesNotebook, ID_BIST, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_BIST"));
    tabSPI = new pnlSPI(m_modulesNotebook, ID_SPITAB, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_SPITAB"));
    m_modulesNotebook->AddPage(tabSi5351, _("Si5351C"), false);
    m_modulesNotebook->AddPage(tabADF4002, _("ADF4002"), false);
    m_modulesNotebook->AddPage(tabRFE, _("RFE"), false);
    m_modulesNotebook->AddPage(tabRBB, _("RBB"), false);
    m_modulesNotebook->AddPage(tabTRF, _("TRF"), false);
    m_modulesNotebook->AddPage(tabTBB, _("TBB"), false);
    m_modulesNotebook->AddPage(tabAFE, _("AFE"), false);
    m_modulesNotebook->AddPage(tabBIAS, _("BIAS"), false);
    m_modulesNotebook->AddPage(tabLDO, _("LDO"), false);
    m_modulesNotebook->AddPage(tabXBUF, _("XBUF"), false);
    m_modulesNotebook->AddPage(tabCLKGEN, _("CLKGEN"), false);
    m_modulesNotebook->AddPage(tabSXT, _("SXT/SXR"), false);
    m_modulesNotebook->AddPage(tabLimeLightPAD, _("LimeLight && PAD"), false);
    m_modulesNotebook->AddPage(tabTxTSP, _("TxTSP"), false);
    m_modulesNotebook->AddPage(tabRxTSP, _("RxTSP"), false);
    m_modulesNotebook->AddPage(tabCDS, _("CDS"), false);
    m_modulesNotebook->AddPage(tabMCU_BD, _("MCU"), false);
    m_modulesNotebook->AddPage(tabBIST, _("BIST"), false);
    m_modulesNotebook->AddPage(tabSPI, _("SPI"), false);
    controlPanelSizer->Add(m_modulesNotebook, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    txtMessageLog = new wxRichTextCtrl(this, ID_CONTROL_PANEL_MSG_LOG, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxRE_MULTILINE|wxRE_READONLY|wxVSCROLL, wxDefaultValidator, _T("ID_CONTROL_PANEL_MSG_LOG"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    txtMessageLog->SetMinSize(wxSize(400,64));
    FlexGridSizer1->Add(txtMessageLog, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 1, 0, 0);
    btnClearMsgLog = new wxButton(this, ID_BUTTON4, _("Clear"), wxDefaultPosition, wxSize(40,24), 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer2->Add(btnClearMsgLog, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    btnShowLog = new wxButton(this, ID_BUTTON7, _("Log"), wxDefaultPosition, wxSize(40,24), 0, wxDefaultValidator, _T("ID_BUTTON7"));
    FlexGridSizer2->Add(btnShowLog, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    controlPanelSizer->Add(FlexGridSizer1, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(controlPanelSizer);
    m_ControlManuBar = new wxMenuBar();
    Menu1 = new wxMenu();
    mnuNew = new wxMenuItem(Menu1, ID_MENUITEM2, _("New"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(mnuNew);
    mnuOpen = new wxMenuItem(Menu1, ID_MENUITEM3, _("Open"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(mnuOpen);
    mnuSave = new wxMenuItem(Menu1, ID_MENUITEM4, _("Save"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(mnuSave);
    mnuReadToHex = new wxMenuItem(Menu1, ID_MENUITEM5, _("Chip --> Hex"), _("Reads chip configuration and saves to file"), wxITEM_NORMAL);
    Menu1->Append(mnuReadToHex);
    mnuSaveRegistersRVHEX = new wxMenuItem(Menu1, ID_MENUITEM7, _("Save registers (rv-hex)"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(mnuSaveRegistersRVHEX);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    m_ControlManuBar->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    menuConnectionSettings = new wxMenuItem(Menu3, ID_MENU_CONNECTION_SETTINGS, _("Connection Settings"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(menuConnectionSettings);
    mnu_VerifyWrittenData = new wxMenuItem(Menu3, ID_MENUITEM8, _("Verify written data"), wxEmptyString, wxITEM_CHECK);
    Menu3->Append(mnu_VerifyWrittenData);
    m_ControlManuBar->Append(Menu3, _("Options"));
    Menu4 = new wxMenu();
    mnuRegistersTest = new wxMenuItem(Menu4, ID_MENUITEM1, _("Registers Test"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(mnuRegistersTest);
    mnuRegistersMap = new wxMenuItem(Menu4, ID_MENUITEM6, _("Registers Map"), wxEmptyString, wxITEM_NORMAL);
    Menu4->Append(mnuRegistersMap);
    m_ControlManuBar->Append(Menu4, _("Tools"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    m_ControlManuBar->Append(Menu2, _("Help"));
    SetMenuBar(m_ControlManuBar);
    m_controlStatusbar = new wxStatusBar(this, ID_CONTROL_STATUSBAR, 0, _T("ID_CONTROL_STATUSBAR"));
    int __wxStatusBarWidths_1[4] = { 64, -64, -64, -64 };
    int __wxStatusBarStyles_1[4] = { wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL, wxSB_NORMAL };
    m_controlStatusbar->SetFieldsCount(4,__wxStatusBarWidths_1);
    m_controlStatusbar->SetStatusStyles(4,__wxStatusBarStyles_1);
    SetStatusBar(m_controlStatusbar);
    SetSizer(controlPanelSizer);
    Layout();
    Center();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnNewProjectClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnOpenProjectClick);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnSaveProjectClick);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnUploadAllClick);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnDownloadAllClick);
    Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnResetClick);
    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&controlPanel_LMS7002::OnConfiguringChannelsChange);
    Connect(ID_RADIOBUTTON1,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnConfiguringChannelsChange);
    Connect(ID_RADIOBUTTON2,wxEVT_COMMAND_RADIOBUTTON_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnConfiguringChannelsChange);
    Connect(ID_NOTEBOOK1,wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,(wxObjectEventFunction)&controlPanel_LMS7002::Onm_modulesNotebookPageChanged);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnClearMsgLogClick);
    Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnShowLogClick);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnNewProjectClick);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnOpenProjectClick);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnbtnSaveProjectClick);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnmnuReadToHexSelected);
    Connect(ID_MENUITEM7,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnmnuSaveRegistersRVHEXSelected);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnQuit);
    Connect(ID_MENU_CONNECTION_SETTINGS,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnmenuConnectionSettingsSelected);
    Connect(ID_MENUITEM8,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::Onmnu_VerifyWrittenDataSelected);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnmnuRegistersTestSelected);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnmnuRegistersMapSelected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&controlPanel_LMS7002::OnAbout);
    //*)
    //GetParent()->Thaw();
}

controlPanel_LMS7002::~controlPanel_LMS7002()
{
    g_pControlPanel = NULL;
    MessageLog::getInstance()->unregisterFromNotifications( MessageHandler );
    //(*Destroy(controlPanel_LMS7002)
    //*)
}

void controlPanel_LMS7002::OnQuit(wxCommandEvent& event)
{
    lmsControl->UnregisterFromNotifications(this);
    delete lmsControl;
    Close();
}

/** @brief Displays message box with program version and build date
*/
void controlPanel_LMS7002::OnAbout(wxCommandEvent& event)
{
    dlgAbout dlg(this);
    dlg.ShowModal();
}

void controlPanel_LMS7002::OnbtnClearMsgLogClick(wxCommandEvent& event)
{
    txtMessageLog->Clear();
}

void controlPanel_LMS7002::OnbtnFindDevicesClick(wxCommandEvent& event)
{
    lmsControl->FindDevices();
}

void controlPanel_LMS7002::OnmenuConnectionSettingsSelected(wxCommandEvent& event)
{
    dlgConnectionManager *dlg = new dlgConnectionManager(NULL);
    dlg->SetConnectionManager(lmsControl->getSerPort());
    dlg->ShowModal();
    delete dlg;
    UpdateStatusBar();
}

void controlPanel_LMS7002::OnbtnNewProjectClick(wxCommandEvent& event)
{
    lmsControl->ResetChip();
    UpdateGUI();
}

void controlPanel_LMS7002::OnbtnUpdateGUIClick(wxCommandEvent& event)
{
    UpdateGUI();
}

void controlPanel_LMS7002::OnbtnOpenProjectClick(wxCommandEvent& event)
{
    wxFileDialog dlg(this, _("Open config file"), "", "", "Project-File (*.ini)|*.ini|Project-binary-file (*.txt)|*.txt", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    lmsControl->LoadFromFile( dlg.GetPath().ToStdString());
    OnbtnUpdateGUIClick(event);
}

void controlPanel_LMS7002::OnbtnSaveProjectClick(wxCommandEvent& event)
{
    wxFileDialog dlg(this, _("Save config file"), "", "", "Project-File (*.ini)|*.ini|Project-binary-file (*.txt)|*.txt", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (dlg.ShowModal() == wxID_CANCEL)
        return;
    if(dlg.GetFilterIndex() == 0)
        lmsControl->SaveToFile( dlg.GetPath().ToStdString(), false);
    else
        lmsControl->SaveToFile( dlg.GetPath().ToStdString(), true);
}

void controlPanel_LMS7002::OnbtnUploadAllClick(wxCommandEvent& event)
{
    lmsControl->UploadAll();
}

void controlPanel_LMS7002::OnConfiguringChannelsChange(wxCommandEvent& event)
{
    if(rbtnEnChannelA->GetValue() == true)
    {
        SwitchChannel(0, chkSyncAB->GetValue());
    }
    else if(rbtnEnChannelB->GetValue() == true)
    {
        SwitchChannel(1, chkSyncAB->GetValue());
    }
}

void controlPanel_LMS7002::Onmnu_SaveRegistersToFileSelected(wxCommandEvent& event)
{
    OnbtnSaveProjectClick(event);
}

void controlPanel_LMS7002::UpdateGUI()
{
    long t0;
    long t1 = t0 = getMilis();
    long t2 = t1;
        tabRFE->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE RFE " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabRBB->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE RBB " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabTRF->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE TRF " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabTBB->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE TBB " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabAFE->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE AFE " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabLDO->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE LDO " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabBIAS->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE BIAS " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabXBUF->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE XBUF " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabCLKGEN->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE CLKGEN " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabSXT->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE SXT " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabLimeLightPAD->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE LIMELIGHT " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabTxTSP->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE TXTSP " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabRxTSP->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE RXTSP " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabBIST->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE BIST " << t2-t1 << " ms" << endl;
        t1 = t2;
        tabCDS->UpdateGUI();
        t2 = getMilis();
        cout << "UPDATE CDS " << t2-t1 << " ms" << endl;
        t1 = t2;
    cout << "UPDATE GUI " << getMilis()-t0 << " ms" << endl;
}

void controlPanel_LMS7002::MessageHandler(const int signal, const char *msg, const int paraml)
{
    wxRichTextCtrl *txtMessageLog = g_pControlPanel->txtMessageLog;
    if(g_pControlPanel)
    {
        switch(signal)
        {
        case 1:
            if(txtMessageLog->GetNumberOfLines() > 250)
            {
                txtMessageLog->Clear();
            }
            txtMessageLog->AppendText(msg);
            txtMessageLog->ShowPosition(txtMessageLog->GetLastPosition()-1);
            txtMessageLog->Update();
            break;
        }
    }
}

void controlPanel_LMS7002::OnbtnDownloadAllClick(wxCommandEvent& event)
{
    lmsControl->DownloadAll();
    UpdateGUI();
}

void controlPanel_LMS7002::OnmnuResetChipSelected(wxCommandEvent& event)
{
    lmsControl->ResetChip();
}

void controlPanel_LMS7002::OnbtnShowLogClick(wxCommandEvent& event)
{
    dlgMessageLog dlg(this);
    dlg.ShowModal();
}

void controlPanel_LMS7002::OnmnuRegistersTestSelected(wxCommandEvent& event)
{
    dlgRegisterTest dlg(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, lmsControl);
    dlg.ShowModal();
}

void controlPanel_LMS7002::UpdateStatusBar()
{

}

void controlPanel_LMS7002::OnbtnResetClick(wxCommandEvent& event)
{
    lmsControl->ResetChip();
}

void controlPanel_LMS7002::OnmnuReadToHexSelected(wxCommandEvent& event)
{
    wxFileDialog dlg(this, _("Save config file"), "", "", "Project-binary-file (*.txt)|*.txt", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if (dlg.ShowModal() == wxID_CANCEL)
        return;
    lmsControl->getRegistersMap()->DownloadToHex( dlg.GetPath().ToStdString() );
}

void controlPanel_LMS7002::OnmnuRegistersMapSelected(wxCommandEvent& event)
{
    if(m_regMapDlg)
    {
        m_regMapDlg->Show(true);
        m_regMapDlg->UpdateTables();
    }
}

void controlPanel_LMS7002::SwitchChannel(int channel, bool configBoth)
{
    m_selectedChannel = channel;
    lmsControl->SelectConfigChannel(channel, configBoth);
    chkSyncAB->SetValue(configBoth);

    if(channel == 0)
    {
        rbtnEnChannelA->SetValue(true);
        rbtnEnChannelB->SetValue(false);
    }
    else if(channel == 1)
    {
        rbtnEnChannelA->SetValue(false);
        rbtnEnChannelB->SetValue(true);
    }
    else
    {
        rbtnEnChannelA->SetValue(false);
        rbtnEnChannelB->SetValue(false);
    }
    tabRFE->UpdateGUI();
    tabRBB->UpdateGUI();

    tabTRF->UpdateGUI();

    tabTBB->UpdateGUI();
    tabSXT->UpdateGUI();

    tabTxTSP->UpdateGUI();
    tabRxTSP->UpdateGUI();

    int pageSel = m_modulesNotebook->GetSelection();
    wxNotebookPage *page = m_modulesNotebook->GetPage(pageSel);
    int pageId = page->GetId();

    if(pageId == ID_SXRSXT)
    {
        if(chkSyncAB->GetValue() == true)
        {
            txtActiveChannel->SetLabel("Active Ch: SXR&&SXT");
        }
        else if(m_selectedChannel == 0)
            txtActiveChannel->SetLabel("Active Ch: SXR");
        else if(m_selectedChannel == 1)
            txtActiveChannel->SetLabel("Active Ch: SXT");
    }
    else
    {

    if(configBoth)
    {
        txtActiveChannel->SetLabel("Active Ch: A&&B");
    }
    else if(channel == 0)
        txtActiveChannel->SetLabel("Active Ch: A");
    else if(channel == 1)
        txtActiveChannel->SetLabel("Active Ch: B");
    }
}

void controlPanel_LMS7002::Onm_modulesNotebookPageChanged(wxNotebookEvent& event)
{
    int pageSel = event.GetSelection();
    wxNotebookPage *page = m_modulesNotebook->GetPage(pageSel);

    long pageId = page->GetId();

    if(pageId == tabSXT->GetId())
    {
        if(chkSyncAB->GetValue() == true)
        {
            txtActiveChannel->SetLabel("Active Ch: SXR&&SXT");
        }
        else if(m_selectedChannel == 0)
            txtActiveChannel->SetLabel("Active Ch: SXR");
        else if(m_selectedChannel == 1)
            txtActiveChannel->SetLabel("Active Ch: SXT");
    }
    else
    {

    if(chkSyncAB->GetValue() == true)
    {
        txtActiveChannel->SetLabel("Active Ch: A&&B");
    }
    else if(m_selectedChannel == 0)
        txtActiveChannel->SetLabel("Active Ch: A");
    else if(m_selectedChannel == 1)
        txtActiveChannel->SetLabel("Active Ch: B");
    }

    if(pageId == tabAFE->GetId() || pageId==tabBIAS->GetId() || pageId==tabXBUF->GetId() || pageId == tabCLKGEN->GetId() || pageId==tabLDO->GetId() || pageId==tabBIAS->GetId())
    {
        if(m_overrideChannel == false)
        {
            m_overrideChannel = true;
            m_lastUsedChannel = m_selectedChannel;
        }
        SwitchChannel(0, false);
    }
    else
    {
        if(m_overrideChannel == true)
        {
            m_overrideChannel = false;
            SwitchChannel(m_lastUsedChannel, false);
        }
    }
}

void controlPanel_LMS7002::OnmnuSaveRegistersRVHEXSelected(wxCommandEvent& event)
{
    wxFileDialog dlg(this, _("Save rv-hex"), "", "", "Registers rv-hex (*.txt)|*.txt", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    lmsControl->CreateConfigurationInstructions(dlg.GetPath().ToStdString());
}

void controlPanel_LMS7002::Onmnu_VerifyWrittenDataSelected(wxCommandEvent& event)
{
    lmsControl->getSerPort()->EnableTestWrittenData(mnu_VerifyWrittenData->IsChecked());
}
