//Ensuring the header file is included only once during compilation
#pragma once

//Including the necessary header files
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <gpgme.h>
#include <GpgmeRepo.h>
#include <vector>

//Defining the SignKeyForm class
class SignKeyForm : public wxDialog
{
public:
    SignKeyForm();
    ~SignKeyForm();

    //Defining the SignKeyForm functions
    void SignKey(wxCommandEvent &event);
    vector<gpgme_key_t> keysToSign;
    vector<gpgme_key_t> signingKeys;

    //Defining the SignKeyForm variables
    wxChoice *signingKey = nullptr;
    wxChoice *keyToSign = nullptr;
    wxDatePickerCtrl *keyExpiry = nullptr;

};