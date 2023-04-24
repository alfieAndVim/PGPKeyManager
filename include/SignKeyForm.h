#pragma once

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <gpgme.h>
#include <GpgmeRepo.h>
#include <vector>

class SignKeyForm : public wxDialog
{
public:
    SignKeyForm();
    ~SignKeyForm();
    void SignKey(wxCommandEvent &event);

    vector<gpgme_key_t> keysToSign;
    vector<gpgme_key_t> signingKeys;
    wxChoice *signingKey = nullptr;
    wxChoice *keyToSign = nullptr;
    wxDatePickerCtrl *keyExpiry = nullptr;

};