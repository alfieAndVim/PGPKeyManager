#pragma once
#include <wx/wx.h>
#include <wx/artprov.h>
#include <wx/textfile.h>
#include <wx/grid.h>
#include <vector>
#include <GpgmeRepo.h>
#include <SignKeyForm.h>

class Main : public wxFrame
{
public:
    Main();
    ~Main();

    void OnQuit(wxCommandEvent& event);
    void OnNew(wxCommandEvent& event);
    void OnImport(wxCommandEvent& event);
    void OnSign(wxCommandEvent& event);
    void OnKeysChanged();

    int KeySelected = -1;

private:
    vector<gpgme_key_t> keys;
    wxGrid *keyList = nullptr;
    wxBoxSizer *sizer = nullptr;
    

    //wxButton *m_button1 = nullptr;
    //wxTextCtrl *m_textCtrl1 = nullptr;
};