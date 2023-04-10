#pragma once
#include <wx/wx.h>
#include <wx/artprov.h>

class Main : public wxFrame
{
public:
    Main();
    ~Main();

    void OnQuit(wxCommandEvent& event);
    void OnNew(wxCommandEvent& event);

//private:

    

    //wxButton *m_button1 = nullptr;
    //wxTextCtrl *m_textCtrl1 = nullptr;
};