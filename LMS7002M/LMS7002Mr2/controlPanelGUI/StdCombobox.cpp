// -----------------------------------------------------------------------------
// FILE: 		StdCombobox.cpp
// DESCRIPTION: Replacement for wxComboBox due to it's slow item appending
// DATE:		2013-11-28
// AUTHOR(s):	Lime Microsystems
// REVISIONS:
// -----------------------------------------------------------------------------

#include "StdCombobox.h"
#include <wx/event.h>
/** Custom combobox control for wxWidgets, because standard one works too slow
when adding many items to drop lists.
*/

StdCombobox::StdCombobox()
{

}

/** @brief StdCombobox
*/
StdCombobox::StdCombobox(wxWindow* parent, wxWindowID winid, const wxString str, const wxPoint& pos, const wxSize& size, long style, int a, int b, const wxValidator& val, const wxString& name)
{
    Create(parent, winid, pos, size);
}

/** @brief StdCombobox
*/
StdCombobox::StdCombobox(wxWindow* parent, wxWindowID winid, const wxPoint& pos, const wxSize& size, long style, int a, int b, const wxValidator& val, const wxString& name)
{
    Create(parent, winid, pos, size);
}

bool StdCombobox::Create(wxWindow *parent,
                         wxWindowID winid,
                         const wxPoint& pos,
                         const wxSize& size,
                         long style, int a, int b,
                         const wxValidator& val,
                         const wxString& name)
{
    bool status = wxComboCtrl::Create(parent, winid, wxEmptyString, pos, size, wxTE_PROCESS_ENTER, wxDefaultValidator, wxString(""));
    m_popup = new StdComboPopup(parent, winid);
    textOk = false;
    SetPopupControl(m_popup);
    return status;
}

/** @brief Appends string to drop list
*/
int StdCombobox::Append(const string& str)
{
    return m_popup->Append(str);
}

/** @brief Appends vector of strings to drop list
*/
int StdCombobox::Append(const vector<string> &sarray)
{
    return m_popup->Append(sarray);
}

/** @brief Appends one wxString to drop list
*/
int StdCombobox::Append(const wxString &str)
{
    return m_popup->Append(str.ToStdString());
}

/** @brief Clears items from drop list
*/
void StdCombobox::Clear()
{
    m_popup->Clear();
}

/** @brief Sets current selection from drop list
*/
bool StdCombobox::SetSelection(int n)
{
    if( m_popup->SetSelection(n) )
    {
        SetValue(m_popup->GetStringValue());
        return true;
    }
    return false;
    //Refresh();
}

/** @brief Returns current selection from drop list
*/
int StdCombobox::GetSelection()
{
    return m_popup->GetSelection();
}

/** @brief Changes selection when mouse wheel is turned
*/
void StdCombobox::OnMouseWheelMoved(wxMouseEvent &event)
{
    int selection = GetSelection();
    if(event.GetWheelRotation() < 0)
    {
        if( SetSelection( selection+1 ) )
            m_popup->SendComboboxEvent();
    }
    else if(event.GetWheelRotation() > 0)
    {
        if( SetSelection( selection-1 ) )
            m_popup->SendComboboxEvent();
    }
}

int possibleIndex = 0;

void StdCombobox::OnTextChanged(wxCommandEvent &event)
{
    int i = m_popup->FindStringIndex(event.GetString().ToStdString());
    if(i >= 0)
    {
        pendingIndex = i;
        textOk = true;
    }
    else
    {
        pendingIndex = -1;
        textOk = false;
    }
    return;
}

void StdCombobox::OnKeyDown(wxKeyEvent &event)
{
    int keyCode = event.GetKeyCode();
    if(keyCode == WXK_RETURN || keyCode == WXK_NUMPAD_ENTER)
    {
        if(textOk)
        {
            m_popup->SetSelection(pendingIndex);
            m_popup->SendComboboxEvent();
            textOk = false;
        }
        else
        {
            SetText( m_popup->GetStringValue() );
        }
        return;
    }
    event.ResumePropagation(1);
    event.Skip();
}

void StdCombobox::OnKillFocus(wxFocusEvent &event)
{
    if(textOk)
    {
        m_popup->SetSelection(pendingIndex);
        m_popup->SendComboboxEvent();
        textOk = false;
    }
    else
    {
        SetText( m_popup->GetStringValue() );
    }
    //event.Skip();
}

wxIMPLEMENT_DYNAMIC_CLASS(StdCombobox, wxComboCtrl)

BEGIN_EVENT_TABLE(StdCombobox, wxComboCtrl)
    EVT_MOUSEWHEEL(StdCombobox::OnMouseWheelMoved)
    EVT_TEXT(wxID_ANY, StdCombobox::OnTextChanged)
    EVT_KEY_DOWN(StdCombobox::OnKeyDown)
    //EVT_KILL_FOCUS(StdCombobox::OnKillFocus)
END_EVENT_TABLE()


StdComboPopup::StdComboPopup()
{
    m_cmbbox = NULL;
}

StdComboPopup::StdComboPopup(wxWindow *parent, wxWindowID winid)
{
    m_myID = winid;
    m_cmbbox = NULL;
    SetId(winid);
}

StdComboPopup::~StdComboPopup()
{

}

void StdComboPopup::Init()
{
    m_selection = -1;
    m_textHeight = 10;
    showLines = 10;
    pagePos = 0;
    initialized = false;
}

void StdComboPopup::OnScroll(wxScrollEvent& event)
{
    Refresh();
}

bool StdComboPopup::Create(wxWindow* parent)
{
    return Create(parent, wxID_ANY);
}

bool StdComboPopup::Create(wxWindow* parent, wxWindowID winid)
{
    m_cmbbox = parent;
    bool status = wxControl::Create(parent, winid);
    scrollbarwidth = 21;
    long scrollBarId = wxNewId();
    ScrollBar1 = new wxScrollBar(this, scrollBarId, wxPoint(100, 2) , wxSize(scrollbarwidth,215), wxSB_VERTICAL, wxDefaultValidator, _T("ID_SCROLLBAR1"));
    ScrollBar1->SetScrollbar(0, showLines, m_strings_items.size(), showLines-1);
    ScrollBar1->SetThumbPosition(m_selection);
    Connect(scrollBarId,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&StdComboPopup::OnScroll);
    return status;
}

void StdComboPopup::SetStringValue(const wxString& s)
{
    string str = s.ToStdString();
    for(unsigned int i=0; i<m_strings_items.size(); ++i)
    {
        if(m_strings_items[i] == str)
        {
            SetSelection(i);
            break;
        }
    }
}

wxString StdComboPopup::GetStringValue() const
{
    if ( m_selection >= 0 && m_selection < m_strings_items.size())
    {
        return m_strings_items[m_selection];
    }
    return wxEmptyString;
}

void StdComboPopup::OnMouseClick(wxMouseEvent &event)
{
    if( SetSelection(ScrollBar1->GetThumbPosition()+event.GetY()/m_textHeight) )
    {
        SendComboboxEvent();
    }
    Dismiss();
}

void StdComboPopup::OnPopup()
{
    int x, y;
    GetSize(&x, &y);
    SetSize(x, showLines*m_textHeight+10);
    if(ScrollBar1)
    {
        GetSize(&x, &y);
        ScrollBar1->SetPosition( wxPoint(x-scrollbarwidth, 2));
        ScrollBar1->SetSize(scrollbarwidth, y-5);
        ScrollBar1->SetScrollbar(0, showLines, m_strings_items.size(), showLines-1);
        ScrollBar1->SetThumbPosition(m_selection);
    }
}

void StdComboPopup::OnPaint(wxPaintEvent &event)
{
    wxPaintDC dc(this);
    // draw a rectangle
    int width, height;
    GetSize(&width, &height);
    dc.DrawRectangle( 0, 0, width, height );
    int scrollPos = ScrollBar1->GetThumbPosition();
    for(int i=0; i<showLines && (scrollPos+i) < m_strings_items.size(); ++i)
    {
        dc.DrawText(m_strings_items[scrollPos+i], 3, i*10);
    }
    event.Skip();
}

int StdComboPopup::Append(const string &str)
{
    int pos = m_strings_items.size();
    m_strings_items.push_back(str);
    return pos;
}

int StdComboPopup::Append(const vector<string> &items)
{
    int pos = m_strings_items.size();
    for(unsigned int i=0; i<items.size(); ++i)
        m_strings_items.push_back(items[i]);
    return pos;
}

void StdComboPopup::Clear()
{
    m_strings_items.clear();
}

bool StdComboPopup::SetSelection(int n)
{
    if(n < m_strings_items.size() && n >= 0)
    {
        m_selection = n;
        return true;
    }
    return false;
}
int StdComboPopup::GetSelection()
{
    return m_selection;
}

void StdComboPopup::OnMyEvent(wxCommandEvent& event)
{
    event.Skip();
}

void StdComboPopup::SendComboboxEvent()
{
    wxCommandEvent event(wxEVT_COMMAND_COMBOBOX_SELECTED);
    event.SetId(m_myID);
    event.SetInt(m_selection);
    event.SetEventObject((wxObject *)this);
    event.SetString(m_strings_items[m_selection]);
    wxPostEvent(GetParent()->GetEventHandler(), event);
}

bool StdComboPopup::FindItem(const wxString &item, wxString *trueItem)
{
    string str = item.ToStdString();
    for(unsigned int i=0; i<m_strings_items.size(); ++i)
    {
        if(m_strings_items[i] == str)
        {
            SetSelection(i);
            return true;
            break;
        }
    }
    return false;
}

int StdComboPopup::FindStringIndex(const string &str)
{
    for(unsigned int i=0; i<m_strings_items.size(); ++i)
    {
        if(m_strings_items[i] == str)
        {
            return i;
        }
    }
    return -1;
}

BEGIN_EVENT_TABLE(StdComboPopup, wxControl)
    EVT_LEFT_UP(StdComboPopup::OnMouseClick)
    EVT_PAINT(StdComboPopup::OnPaint)
    EVT_COMBOBOX(wxID_ANY, StdComboPopup::OnMyEvent)
END_EVENT_TABLE()

