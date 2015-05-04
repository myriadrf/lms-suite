#ifndef PNLSAMPLESGENERATOR_H
#define PNLSAMPLESGENERATOR_H

//(*Headers(pnlSamplesGenerator)
#include <wx/panel.h>
class wxTextCtrl;
class wxFlexGridSizer;
class wxSpinEvent;
class wxButton;
class wxSpinCtrl;
class wxGLCanvas;
class wxStaticText;
class wxRadioBox;
//*)
#include "OpenGLGraph.h"

class pnlSamplesGenerator: public wxPanel
{
	public:

		pnlSamplesGenerator(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size, int style = 0, wxString str = "");
		virtual ~pnlSamplesGenerator();

		//(*Declarations(pnlSamplesGenerator)
		wxPanel* Panel1;
		wxSpinCtrl* spinSamplingRate;
		wxButton* btnStartGenerating;
		wxStaticText* StaticText1;
		wxPanel* Panel2;
		wxStaticText* StaticText3;
		wxRadioBox* rgrDataSource;
		wxTextCtrl* txtFreq;
		wxStaticText* StaticText4;
		wxSpinCtrl* spinAmplitude;
		wxStaticText* StaticText2;
		wxButton* btnStopGenerating;
		wxButton* btnOpenFile;
		OpenGLGraph* glSignalGraph;
		//*)

	protected:

		//(*Identifiers(pnlSamplesGenerator)
		static const long ID_RADIOBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_SPINCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_SPINCTRL2;
		static const long ID_PANEL1;
		static const long ID_GLCANVAS1;
		static const long ID_PANEL2;
		static const long ID_STATICTEXT4;
		//*)

	private:
        float *m_isamples;
        float *m_qsamples;
        float *m_xaxis;
		//(*Handlers(pnlSamplesGenerator)
		void OnrgrDataSourceSelect(wxCommandEvent& event);
		void OnbtnStartGeneratingClick(wxCommandEvent& event);
		void OnbtnStopGeneratingClick(wxCommandEvent& event);
		void OnbtnOpenFileClick(wxCommandEvent& event);
		//*)

	protected:

		void BuildContent(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size);

		DECLARE_EVENT_TABLE()
};

#endif
