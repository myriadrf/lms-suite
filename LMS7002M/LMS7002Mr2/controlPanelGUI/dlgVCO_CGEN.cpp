#include "dlgVCO_CGEN.h"
#include "PLL_CGEN.h"

#include <vector>
#include <wx/filedlg.h>
#include <fstream>
//(*InternalHeaders(dlgVCO_CGEN)
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/button.h>
#include <wx/string.h>
//*)

//(*IdInit(dlgVCO_CGEN)
const long dlgVCO_CGEN::ID_PANEL1 = wxNewId();
const long dlgVCO_CGEN::ID_BUTTON1 = wxNewId();
const long dlgVCO_CGEN::ID_BUTTON2 = wxNewId();
const long dlgVCO_CGEN::ID_BUTTON3 = wxNewId();
const long dlgVCO_CGEN::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(dlgVCO_CGEN,wxDialog)
	//(*EventTable(dlgVCO_CGEN)
	//*)
END_EVENT_TABLE()

dlgVCO_CGEN::dlgVCO_CGEN( PLL_CGEN *data, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    pll_data = data;
	BuildContent(parent,id,pos,size);
}

void dlgVCO_CGEN::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(dlgVCO_CGEN)
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer2->AddGrowableCol(0);
	FlexGridSizer2->AddGrowableRow(0);
	pnlVCO_CGEN = new pnlFreqTable(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	FlexGridSizer2->Add(pnlVCO_CGEN, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 5, 0, 0);
	btnOK = new wxButton(this, ID_BUTTON1, _T("Ok"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer3->Add(btnOK, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnCancel = new wxButton(this, ID_BUTTON2, _T("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	FlexGridSizer3->Add(btnCancel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnLoad = new wxButton(this, ID_BUTTON3, _T("Load"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	FlexGridSizer3->Add(btnLoad, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	btnSave = new wxButton(this, ID_BUTTON4, _T("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	FlexGridSizer3->Add(btnSave, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer3, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dlgVCO_CGEN::OnbtnOKClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dlgVCO_CGEN::OnbtnCancelClick);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dlgVCO_CGEN::OnbtnLoadClick);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&dlgVCO_CGEN::OnbtnSaveClick);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&dlgVCO_CGEN::OnInit);
	//*)
}

dlgVCO_CGEN::~dlgVCO_CGEN()
{
	//(*Destroy(dlgVCO_CGEN)
	//*)
}


void dlgVCO_CGEN::OnInit(wxInitDialogEvent& event)
{
    vector<double> freqs;
    freqs = pll_data->GetVCOFrequencies();
    for(unsigned i=0; i<freqs.size(); ++i)
        freqs[i] = freqs[i]/1000; // convert from MHz to GHz
    pnlVCO_CGEN->Initialize("VCO", freqs);
}

void dlgVCO_CGEN::OnbtnOKClick(wxCommandEvent& event)
{
    vector<double> freqs;
    freqs.clear();
    freqs = pnlVCO_CGEN->GetFrequencies();
    for(unsigned i=0; i<freqs.size(); ++i)
        freqs[i] = freqs[i]*1000; // convert from GHz to MHz
    pll_data->SetVCOFrequencies(&freqs[0], freqs.size());

    EndModal(wxID_OK);
}

void dlgVCO_CGEN::OnbtnCancelClick(wxCommandEvent& event)
{
    EndModal(wxID_CANCEL);
}

void dlgVCO_CGEN::OnbtnLoadClick(wxCommandEvent& event)
{
    wxFileDialog dlg(this, _("Open vco file"), "", "", "text (*.txt)|*.txt", wxFD_OPEN|wxFD_FILE_MUST_EXIST);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    fstream fin;
    fin.open(dlg.GetPath().ToStdString().c_str(), ios::in);

    char cline[128];
    int lineLen = 128;

    char vconame[80];
    char ctemp[80];
    double freq = 0;
    int freqCount = 0;

    vector<double> frequencies;

    while(!fin.eof())
    {
        freqCount = 0;
        fin.getline(cline, lineLen);
        //find name and frequency count
        sscanf(cline, "%s %s %i", vconame, ctemp, &freqCount);
        if(strcmp(vconame, "[VCO]") == 0)
        {
            frequencies.clear();
            for(int i=0; i<freqCount; ++i)
            {
                fin.getline(cline, lineLen);
                sscanf(cline, "%lf %s", &freq, ctemp);
                frequencies.push_back(freq);
            }
            pnlVCO_CGEN->Initialize("VCO", frequencies);
        }
        vconame[0] = 0;
    }
    fin.close();
}

void dlgVCO_CGEN::OnbtnSaveClick(wxCommandEvent& event)
{
    wxFileDialog dlg(this, _("Save vco file"), "", "", "text (*.txt)|*.txt", wxFD_SAVE|wxFD_OVERWRITE_PROMPT);
    if(dlg.ShowModal() == wxID_CANCEL)
        return;
    fstream fout;
    fout.open(dlg.GetPath().ToStdString().c_str(), ios::out);

    vector<double> freqs;
    freqs.clear();
    freqs = pnlVCO_CGEN->GetFrequencies();
    fout << "[VCO] count: " << freqs.size() << endl;
    for(unsigned i=0; i<freqs.size(); ++i)
        fout << freqs[i] << ' ' << "GHz" << endl;

    fout.close();
}
