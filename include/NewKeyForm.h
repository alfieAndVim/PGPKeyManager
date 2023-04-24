#pragma once

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <gpgme.h>
#include <iostream>
#include <KeyParms.h>
#include <GpgmeRepo.h>

using namespace std;

class NewKeyForm : public wxDialog
{
public:
    NewKeyForm();
    ~NewKeyForm();
    gpgme_pubkey_algo_t ConvertAlgoStringToAlgorithm(string algo);
    void GenerateKeyPair(wxCommandEvent &event);
    
    wxTextCtrl *name = nullptr;
    wxTextCtrl *email = nullptr;
    wxTextCtrl *comment = nullptr;
    wxChoice *keyType = nullptr;
    wxChoice *keyLength = nullptr;
    wxDatePickerCtrl *keyExpiry = nullptr;
    wxTextCtrl *passphrase = nullptr;
    wxTextCtrl *passphraseConfirm = nullptr;
};