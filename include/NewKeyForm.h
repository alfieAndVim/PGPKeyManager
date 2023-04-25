#pragma once

#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <gpgme.h>
#include <iostream>
#include <KeyParms.h>
#include <GpgmeRepo.h>
#include <KeyCreationThread.h>
#include <Progress.h>

using namespace std;

class NewKeyForm : public wxDialog
{
public:
    NewKeyForm();
    ~NewKeyForm();
    gpgme_pubkey_algo_t ConvertAlgoStringToAlgorithm(string algo);
    void GenerateKeyPair(wxCommandEvent &event);
    void OnKeyCreationThreadCompletion(wxThreadEvent &event);
    
    wxTextCtrl *name = nullptr;
    wxTextCtrl *email = nullptr;
    wxTextCtrl *comment = nullptr;
    wxChoice *keyType = nullptr;
    wxChoice *keyLength = nullptr;
    wxDatePickerCtrl *keyExpiry = nullptr;
    wxTextCtrl *passphrase = nullptr;
    wxTextCtrl *passphraseConfirm = nullptr;
    wxDialog *loadingIndicator = nullptr;
};