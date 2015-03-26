// -----------------------------------------------------------------------------
// FILE: 		StdCombobox.h
// DESCRIPTION: Header for StdCombobox.cpp
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#ifndef STD_COMBOBOX_H
#define STD_COMBOBOX_H

#include <wx/wx.h>
#include <wx/combo.h>
#include <vector>
using namespace std;

class StdComboPopup : public wxControl, public wxComboPopup
{
public:
    StdComboPopup();
    StdComboPopup(wxWindow *parent, wxWindowID winid);
    ~StdComboPopup();

    void OnMyEvent(wxCommandEvent& event);

    virtual bool FindItem(const wxString &item, wxString *trueItem=NULL);

    virtual void Init();
    void OnScroll(wxScrollEvent& event);
    virtual bool Create(wxWindow* parent);
    virtual bool Create(wxWindow* parent, wxWindowID id);
    virtual wxWindow *GetControl() { return this; }
    virtual void SetStringValue(const wxString& s);
    virtual wxString GetStringValue() const;
    void OnMouseClick(wxMouseEvent &event);
    void OnPopup();
    void OnPaint(wxPaintEvent &event);

    bool SetSelection(int n);
    int GetSelection();

    int Append(const string &str);
    int Append(const vector<string> &items);
    void Clear();

    void SendComboboxEvent();
    int FindStringIndex(const string &str);

protected:
    int m_myID;
    wxWindow *m_cmbbox;
    vector<string> m_strings_items;
    wxScrollBar *ScrollBar1;
    int width;
    int m_textHeight;

    int scrollbarwidth;
    int showLines;
    int m_selection;
    int pagePos;
    bool initialized;

private:
    DECLARE_EVENT_TABLE()
};


class StdCombobox : public wxComboCtrl
{
public:
    StdCombobox();
    StdCombobox(wxWindow *parent,
              wxWindowID winid,
              const wxString str = wxEmptyString,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = 0, int a=0, int b=0,
              const wxValidator& val = wxDefaultValidator,
              const wxString& name = "StdCombobox");

    StdCombobox(wxWindow *parent,
              wxWindowID winid,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = 0, int a=0, int b=0,
              const wxValidator& val = wxDefaultValidator,
              const wxString& name = "StdCombobox");

    bool Create(wxWindow *parent,
              wxWindowID winid,
              const wxPoint& pos = wxDefaultPosition,
              const wxSize& size = wxDefaultSize,
              long style = 0, int a=0, int b=0,
              const wxValidator& val = wxDefaultValidator,
              const wxString& name = "StdCombobox");

    int Append(const string &str);
    int Append(const wxString &str);
    int Append(const vector<string> &sarray);
    void Clear();
    bool SetSelection(int n);
    int GetSelection();

    bool textOk;
    int pendingIndex;

protected:
    void OnKeyDown(wxKeyEvent &event);
    void OnTextChanged(wxCommandEvent &event);
    void OnMouseWheelMoved(wxMouseEvent &event);
    void OnKillFocus(wxFocusEvent &event);
    StdComboPopup *m_popup;

    DECLARE_DYNAMIC_CLASS(StdCombobox)
    DECLARE_EVENT_TABLE()

};

#endif // STD_COMBOBOX_H

