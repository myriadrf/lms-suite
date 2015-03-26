#ifndef DELAYED_COMBOBOX_H
#define DELAYED_COMBOBOX_H

#include <wx/wx.h>
#include <wx/choice.h>

/**
    wxWidgets combobox that appends string values on first focus event,
    because appending all combobox items takes long time.
*/
class DelayedCombobox : public wxChoice
{
public:
    DelayedCombobox(wxWindow *parent, wxWindowID id,
               const wxString& value = wxEmptyString,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               int n = 0, const wxString choices[] = NULL,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxChoiceNameStr);

    DelayedCombobox(wxWindow *parent, wxWindowID id,
               const wxPoint& pos = wxDefaultPosition,
               const wxSize& size = wxDefaultSize,
               int n = 0, const wxString choices[] = NULL,
               long style = 0,
               const wxValidator& validator = wxDefaultValidator,
               const wxString& name = wxChoiceNameStr);
    int Append(const wxString &str);
    void Append(const wxArrayString &sarray);
    void Clear();
    void SetSelection(int n);
    int GetSelection() const;
    void SetDefaultValues(wxArrayString &strings, int defaultSelection = 0);
protected:
    void OnFocusGot(wxFocusEvent& event);
    void OnEraseBackGround(wxEraseEvent& event) {};
private:

    void Initialize();
    wxArrayString m_strings;
    int m_defaultIndex;
    bool m_initialized;
    DECLARE_EVENT_TABLE()
};

#endif // DELAYED_COMBOBOX_H

