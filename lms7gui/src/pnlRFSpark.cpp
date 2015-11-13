/**
@file 	pnlRFSpark.cpp
@author Lime Microsystems
@brief 	panel for interacting with RFSpark board
*/
#include "pnlRFSpark.h"

#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/button.h>
#include <wx/image.h>
#include <wx/string.h>

#include <vector>
#include <lms7/ConnectionManager.h>

using namespace lms7;

const long pnlRFSpark::ID_BTNREADADC = wxNewId();
const long pnlRFSpark::ID_BTNREADALLADC = wxNewId();
const long pnlRFSpark::ID_BTNWRITEGPIO = wxNewId();
const long pnlRFSpark::ID_BTNREADGPIO = wxNewId();
const long pnlRFSpark::ID_CMBSELECTADC = wxNewId();

BEGIN_EVENT_TABLE(pnlRFSpark,wxPanel)
	
END_EVENT_TABLE()

wxString power2unitsString(char powerx3)
{
	switch (powerx3)
	{
	case -8:
		return "y";
	case -7:
		return "z";
	case -6:
		return "a";
	case -5:
		return "f";
	case -4:
		return "p";
	case -3:
		return "n";
	case -2:
		return "u";
	case -1:
		return "m";
	case 0:
		return "";
	case 1:
		return "k";
	case 2:
		return "M";
	case 3:
		return "G";
	case 4:
		return "T";
	case 5:
		return "P";
	case 6:
		return "E";
	case 7:
		return "Y";
	default:
		return "";
	}
}

pnlRFSpark::pnlRFSpark(ConnectionManager* pSerPort, wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size):
    PluginPanel(this)
{
    m_serPort = pSerPort;
	BuildContent(parent,id,pos,size);    
}

void pnlRFSpark::BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	//ADC values	
	wxFlexGridSizer* sizerADCs = new wxFlexGridSizer(0, 3, 0, 10);
	
	ADCdataGUI adcElement;	
	sizerADCs->Add(new wxStaticText(this, wxNewId(), _("Channel")), 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	sizerADCs->Add(new wxStaticText(this, wxNewId(), _("Value")), 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	//sizerADCs->Add(new wxStaticText(this, wxNewId(), _("10^3^")), 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	sizerADCs->Add(new wxStaticText(this, wxNewId(), _("Units")), 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	wxArrayString adcList;
    wxString adcNames[] = { "VDD12_TIA_RFE", "VDD_TBB", "VDD14_RBB", "DVDD_SXT", "VDD_DIC_SXT", "VDD12_TXBUF", "VDD12_VCO_SXT", "VDD14_LNA_RFE",
        "DVDD_SXR", "VDD_DIV_SXR", "VDD_CP_SXR", "VDD18_SXR", "VD_MXLOBUF_RFE", "VDD14_TIA_RFE", "VDD12_LNA_RFE", "VDD_TLOBUF_TRF",
        "VDD12_RXBIF", "VDD_AFE", "DIGPRVDD1", "VDD_SPI_BUF", "VDD18_TPAD_TRF", "DVDD_CGEN", "VDD_DIV_CGEN", "VDD_CP_CGEN", "VDD12_DIG", "VDD14_VCO_CGEN",
        "TSTAO", "TSTDO 0", "TSTDO 1", "3V3", "VDIO", "VDIO_BB"};
	for (int i = 0; i < mADCcount; ++i)
	{
        adcElement.title = new wxStaticText(this, wxNewId(), wxString::Format("%s", adcNames[i]));
		adcList.push_back(adcElement.title->GetLabel());
		adcElement.value = new wxStaticText(this, wxNewId(), _("????"));
		//adcElement.powerOf10 = new wxStaticText(this, wxNewId(), _("????"));
		adcElement.units	= new wxStaticText(this, wxNewId(), _("????"));
		sizerADCs->Add(adcElement.title, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
		sizerADCs->Add(adcElement.value, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
		//sizerADCs->Add(adcElement.powerOf10, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
		sizerADCs->Add(adcElement.units, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
		mADCgui.push_back(adcElement);
		ADCdata data;
		data.channel = i;
		data.powerOf10coefficient = 0;
		data.units = 0;
		data.value = 0;
		mADCdata.push_back(data);		
	}	
	
	btnReadAllADC = new wxButton(this, ID_BTNREADALLADC, "Refresh All");
	btnReadADC = new wxButton(this, ID_BTNREADADC, "Refresh");
	cmbADCselect = new wxComboBox(this, wxNewId(), adcList[0], wxDefaultPosition, wxDefaultSize, adcList);
	wxFlexGridSizer* sizerADCbuttons = new wxFlexGridSizer(0, 3, 5, 5);
	sizerADCbuttons->Add(btnReadAllADC, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	sizerADCbuttons->Add(btnReadADC, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	sizerADCbuttons->Add(cmbADCselect, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);	

	wxFlexGridSizer* sizerBoxADC = new wxFlexGridSizer(0, 1, 0, 0);
	sizerBoxADC->Add(sizerADCs, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	sizerBoxADC->Add(sizerADCbuttons, 1, wxALIGN_CENTER_VERTICAL | wxALIGN_TOP, 0);

	wxStaticBoxSizer* boxADC = new wxStaticBoxSizer(wxVERTICAL, this, _T("ADC values"));
	boxADC->Add(sizerBoxADC, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);

	wxFlexGridSizer* sizerGPIOs = new wxFlexGridSizer(0, 8, 10, 5);
	
    wxString gpios7_0[] = { "ADCinQ2_N 15", "ADCinQ2_P", "ADCinI2_N", "ADCinI2_P", "ADCinQ1_N", "ADCinQ1_P", "ADCinI1_N", "ADCinI1_P" };
    for (int j = 0; j < 8; ++j)
	{
        long id = wxNewId();
        wxCheckBox* chkgpio = new wxCheckBox(this, id, wxString::Format("%s", gpios7_0[j]));
        this->Connect(id, wxEVT_CHECKBOX, (wxObjectEventFunction)&pnlRFSpark::OnbtnWriteGPIO);
		sizerGPIOs->Add(chkgpio, wxALIGN_LEFT | wxALIGN_TOP, 0);
		mGPIOboxes.push_back(chkgpio);
	}

    wxString gpios15_8[] = {"GPIO 15", "DIG_RST", "G_PWR_DWN", "IQSELEN2RX_DIR", "IQSELEN1TX_DIR", "DIO_BUF_OE", "DIQ2TX_DIR", "DIQ2RX_DIR" };
    for (int j = 0; j < 8; ++j)
    {
        long id = wxNewId();
        wxCheckBox* chkgpio = new wxCheckBox(this, id, wxString::Format("%s", gpios15_8[j]));
        this->Connect(id, wxEVT_CHECKBOX, (wxObjectEventFunction)&pnlRFSpark::OnbtnWriteGPIO);
        sizerGPIOs->Add(chkgpio, wxALIGN_LEFT | wxALIGN_TOP, 0);
        mGPIOboxes.push_back(chkgpio);
    }
    wxString gpios23_16[] = { "GPIO 23", "GPIO 22", "GPIO 21", "GPIO 20", "GPIO 19", "GPIO 18", "TXEN_LMS", "RXEN_LMS"};
    for (int j = 0; j < 8; ++j)
    {
        long id = wxNewId();
        wxCheckBox* chkgpio = new wxCheckBox(this, id, wxString::Format("%s", gpios23_16[j]));
        this->Connect(id, wxEVT_CHECKBOX, (wxObjectEventFunction)&pnlRFSpark::OnbtnWriteGPIO);
        sizerGPIOs->Add(chkgpio, wxALIGN_LEFT | wxALIGN_TOP, 0);
        mGPIOboxes.push_back(chkgpio);
    }
    		
	wxButton* btnReadGPIO = new wxButton(this, ID_BTNREADGPIO, "Read");
	wxButton* btnWriteGPIO = new wxButton(this, ID_BTNWRITEGPIO, "Write");
	wxFlexGridSizer* sizerGPIObuttons = new wxFlexGridSizer(0, 2, 0, 5);
	sizerGPIObuttons->Add(btnReadGPIO, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	sizerGPIObuttons->Add(btnWriteGPIO, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);

	wxFlexGridSizer* sizerBoxGPIO = new wxFlexGridSizer(0, 1, 5, 5);
	sizerBoxGPIO->Add(sizerGPIOs, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	sizerBoxGPIO->Add(sizerGPIObuttons, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	
	wxStaticBoxSizer* boxGPIO = new wxStaticBoxSizer(wxVERTICAL, this, _T("GPIO states"));
	boxGPIO->Add(sizerBoxGPIO, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);

	wxFlexGridSizer* mainGrid = new wxFlexGridSizer(0, 2, 5, 5);	
	mainGrid->Add(boxADC, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	mainGrid->Add(boxGPIO, 1, wxALIGN_LEFT | wxALIGN_TOP, 0);
	  
	SetSizer(mainGrid);
	mainGrid->Fit(this);
	mainGrid->SetSizeHints(this);
	Layout();

	Connect(ID_BTNREADALLADC, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&pnlRFSpark::OnbtnRefreshAllADC);
	Connect(ID_BTNREADADC, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&pnlRFSpark::OnbtnRefreshADC);
	Connect(ID_BTNWRITEGPIO, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&pnlRFSpark::OnbtnWriteGPIO);
	Connect(ID_BTNREADGPIO, wxEVT_COMMAND_BUTTON_CLICKED, (wxObjectEventFunction)&pnlRFSpark::OnbtnReadGPIO);
}

pnlRFSpark::~pnlRFSpark()
{

}

void pnlRFSpark::UpdateADClabels()
{
	for (int i = 0; i < mADCdata.size(); ++i)
	{
		//mADCgui[i].title->SetLabelText(wxString::Format("ADC %02i", mADCdata[i].channel));
		mADCgui[i].value->SetLabelText(wxString::Format("%i", mADCdata[i].value));
		//mADCgui[i].powerOf10->SetLabelText(wxString::Format("%i", mADCdata[i].powerOf10coefficient));
		mADCgui[i].units->SetLabelText(wxString::Format("%s%s", power2unitsString(mADCdata[i].powerOf10coefficient), adcUnits2string(mADCdata[i].units)));
	}
}

void pnlRFSpark::OnbtnRefreshAllADC(wxCommandEvent& event)
{
	unsigned char out[mADCcount * 4];
	unsigned char in[mADCcount * 4];
	memset(in, 0, mADCcount * 4);
	unsigned long iLen = mADCcount * 4;

	for (int i = 0; i < mADCdata.size(); ++i)
		out[i] = i;

	int status = m_serPort->SendReadData(CMD_ANALOG_VAL_RD, out, mADCcount, in, iLen);
	if (STATUS_COMPLETED_CMD != status)
	{
		wxMessageBox(wxString::Format("Board response: %s", status2string(status)), "Warning");
		//return;
	}
	
	for (int i = 0; i < mADCdata.size(); ++i)
	{
		mADCdata[i].channel = in[i*4];
		mADCdata[i].units = (in[i*4+1] & 0xF0) >> 4;
		mADCdata[i].powerOf10coefficient = in[i*4+1] << 4;
		mADCdata[i].powerOf10coefficient = mADCdata[i].powerOf10coefficient >> 4;				
		mADCdata[i].value = in[i * 4 + 2] << 8 | in[i * 4 + 3];
	}
	UpdateADClabels();
}

void pnlRFSpark::OnbtnRefreshADC(wxCommandEvent& event)
{
	unsigned char out[16];
	unsigned char in[16];
	memset(in, 0, 4);
	unsigned long iLen = 4;

	int index = cmbADCselect->GetSelection();
	out[0] = index;
	
	int status = m_serPort->SendReadData(CMD_ANALOG_VAL_RD, out, 1, in, iLen);
	if (STATUS_COMPLETED_CMD != status)
	{
		wxMessageBox(wxString::Format("Board response: %s", status2string(status)), "Warning");
		//return;
	}

	if(index < mADCdata.size())
	{
		mADCdata[index].channel = in[0];
		mADCdata[index].units = (in[1] & 0xF0) >> 4;
		mADCdata[index].powerOf10coefficient = in[1] << 4;
		mADCdata[index].powerOf10coefficient = mADCdata[index].powerOf10coefficient >> 4;
		mADCdata[index].value = in[2] << 8 | in[3];
	}
	UpdateADClabels();
}

void pnlRFSpark::OnbtnWriteGPIO(wxCommandEvent& event)
{
	unsigned char out[56];
	memset(out, 0, 56);
	unsigned char in[56];
	memset(in, 0, 56);
	unsigned long iLen = 56;
	int gpioIndex = 0;
	int gpioByte = 0;
	for (int i = 0; i < mGPIOboxes.size()/8; ++i)
	{ 
		out[gpioByte] = 0;
		for (int j = 7; j >= 0; --j)		
			out[gpioByte] |= mGPIOboxes[gpioIndex++]->IsChecked() << j;	
		++gpioByte;
	}
	int status = m_serPort->SendData(CMD_GPIO_WR, out, 56);
	if (status != STATUS_COMPLETED_CMD)	
		wxMessageBox(wxString::Format("Board response: %s", status2string(status)), "Warning");
}

void pnlRFSpark::OnbtnReadGPIO(wxCommandEvent& event)
{
	unsigned char out[56];
	memset(out, 0, 56);
	unsigned char in[64];
	memset(in, 0, 64);
	unsigned long iLen = 56;
	int status = m_serPort->SendReadData(CMD_GPIO_RD, out, 56, in, iLen);

	if (status != STATUS_COMPLETED_CMD)
	{
		wxMessageBox(wxString::Format("Board response: %s", status2string(status)), "Warning");
		//return;
	}

	int gpioIndex = 0;
	int gpioByte = 0;
	for (int i = 0; i < mGPIOboxes.size() / 8; ++i)
	{		
		for (int j = 7; j >= 0 && gpioIndex < mGPIOboxes.size(); --j)
			mGPIOboxes[gpioIndex++]->SetValue( in[gpioByte] & (0x1 << j) );
		++gpioByte;
	}	
}
