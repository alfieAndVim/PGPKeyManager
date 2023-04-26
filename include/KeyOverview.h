//Ensuring the header file is included only once during compilation
#pragma once

//Including the necessary header files
#include <gpgme.h>
#include <GpgmeRepo.h>
#include <wx/wx.h>
#include <Main.h>
#include <fstream>

//Using the standard namespace
using namespace std;

//Defining the KeyOverview class
class KeyOverview : public wxFrame {
public:
    KeyOverview(string keyId, wxWindow *parent);
    ~KeyOverview();

    //Defining the KeyOverview functions
    void ShowKeyBlock(wxCommandEvent &event);
    void ShowSecretKeyBlock(wxCommandEvent &event);
    void SavePublicKey(wxCommandEvent &event);
    void SaveSecretKey(wxCommandEvent &event);
    void DeleteKey(wxCommandEvent &event);
    void CloseWindow(wxCloseEvent &event);
    string GetTimestamp(gpgme_key_t key);
    string GetExpriationDate(gpgme_key_t key);
    
private:
    
    //Defining the KeyOverview variables
    gpgme_key_t publicKey;
    gpgme_key_t secretKey;

    bool hasSecretKey = false;
};