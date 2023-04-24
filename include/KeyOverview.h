#pragma once

#include <gpgme.h>
#include <GpgmeRepo.h>
#include <wx/wx.h>
#include <Main.h>

using namespace std;

class KeyOverview : public wxFrame {
public:
    KeyOverview(string keyId, wxWindow *parent);
    ~KeyOverview();

    void ShowKeyBlock(wxCommandEvent &event);
    void ShowSecretKeyBlock(wxCommandEvent &event);
    void SavePublicKey(wxCommandEvent &event);
    void SaveSecretKey(wxCommandEvent &event);
    void DeleteKey(wxCommandEvent &event);
    void CloseWindow(wxCloseEvent &event);
    string GetTimestamp(gpgme_key_t key);
    string GetExpriationDate(gpgme_key_t key);
    
private:
    

    gpgme_key_t publicKey;
    gpgme_key_t secretKey;

    bool hasSecretKey = false;
};