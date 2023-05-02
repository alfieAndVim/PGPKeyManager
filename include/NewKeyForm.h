///////////////////////////////////////////////////////////
//Progamming Languages in Cyber Security - CW2 - U2138875//
///////////////////////////////////////////////////////////

//Ensuring the header file is included only once during compilation
#pragma once

//Including the necessary header files
#include <wx/wx.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <gpgme.h>
#include <iostream>
#include <KeyParms.h>
#include <GpgmeRepo.h>
#include <KeyCreationThread.h>
#include <Progress.h>

//Using the standard namespace
using namespace std;

//Defining the NewKeyForm class
class NewKeyForm : public wxDialog
{
public:
    //Defining the NewKeyForm methods
    NewKeyForm();
    ~NewKeyForm();
    gpgme_pubkey_algo_t ConvertAlgoStringToAlgorithm(string algo);
    void GenerateKeyPair(wxCommandEvent &event);
    void OnKeyCreationThreadCompletion(wxThreadEvent &event);
    
    //Defining the NewKeyForm variables
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