/**
@file pnlRFSpark.h
@author Lime Microsystems
*/
#ifndef PNLRFSPARK_H
#define PNLRFSPARK_H

#include <wx/panel.h>
class wxStaticText;
class wxFlexGridSizer;
class wxButton;
class wxStaticBoxSizer;

#include "PluginPanel.h"
#include <vector>
class ConnectionManager;

class pnlRFSpark: public wxPanel, public PluginPanel
{
	public:		
		struct ADCdata
		{
			unsigned char channel;
			unsigned char units;
			char powerOf10coefficient;
			short value;
		};

		struct ADCdataGUI
		{
			wxStaticText* title;
			wxStaticText* units;
			wxStaticText* powerOf10;
			wxStaticText* value;
		};

		pnlRFSpark(ConnectionManager* pSerPort, wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~pnlRFSpark();

		wxButton* btnReadADC;
		wxButton* btnReadAllADC;
		wxComboBox* cmbADCselect;
		/*
		wxButton* btnStopWFM;
		wxStaticText* lblProgressPercent;
		wxGauge* progressBar;
		wxBitmapButton* btnOpenWFM;
		wxButton* btnLoadOnetone;
		wxStaticText* txtFilename;
		wxButton* btnLoadCustom;
		wxButton* btnLoadWCDMA;*/

	protected:
		static const int mADCcount = 32;
		static const long ID_BTNREADADC;
		static const long ID_BTNREADALLADC;
		static const long ID_BTNWRITEGPIO;
		static const long ID_BTNREADGPIO;
		static const long ID_CMBSELECTADC;
		std::vector<ADCdata> mADCdata;
		std::vector<ADCdataGUI> mADCgui;
		std::vector<wxCheckBox*> mGPIOboxes;

	private:
		void UpdateADClabels();
		void OnbtnRefreshAllADC(wxCommandEvent& event);
		void OnbtnRefreshADC(wxCommandEvent& event);
		void OnbtnWriteGPIO(wxCommandEvent& event);
		void OnbtnReadGPIO(wxCommandEvent& event);

	protected:
        ConnectionManager* m_serPort;
		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
