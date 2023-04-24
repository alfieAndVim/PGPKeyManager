#include <SignKeyForm.h>

using namespace std;

SignKeyForm::SignKeyForm() : wxDialog(nullptr, wxID_ANY, "Sign Key", wxPoint(30, 30), wxSize(800, 450))
{
    wxScrolledWindow *scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);

    scrolledWindow->SetScrollRate(5, 5);

    wxBoxSizer *scrollSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    GpgmeRepo gpgmeRepo;

    signingKeys = gpgmeRepo.GetSecretKeys();
    keysToSign = gpgmeRepo.GetKeys();

    wxStaticText *signingKeyLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key");
    signingKey = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    wxStaticText *keyToSignLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key To Sign");
    keyToSign = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    wxStaticText *keyExpiryLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Expiration");
    keyExpiry = new wxDatePickerCtrl(scrolledWindow, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);

    wxButton *signKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Sign Key");
    wxButton *cancelButton = new wxButton(scrolledWindow, wxID_ANY, "Cancel");

    for (int i = 0; i < signingKeys.size(); i++)
    {
        signingKey->Append(signingKeys[i]->uids->email);
    }

    for (int i = 0; i < keysToSign.size(); i++)
    {
        keyToSign->Append(keysToSign[i]->uids->email);
    }

    sizer->Add(signingKeyLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(signingKey, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyToSignLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyToSign, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyExpiryLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyExpiry, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(signKeyButton, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(cancelButton, wxSizerFlags(1).Expand().Border(wxALL, 5));

    signKeyButton->Bind(wxEVT_BUTTON, &SignKeyForm::SignKey, this);

    scrolledWindow->SetSizer(sizer);
    scrollSizer->Add(scrolledWindow, 1, wxEXPAND);
    SetSizer(scrollSizer);

    
}

void SignKeyForm::SignKey(wxCommandEvent &event)
{
    cout << "Sign Key" << endl;
    gpgme_key_t chosenSigningKey = signingKeys[signingKey->GetSelection()];
    gpgme_key_t chosenKeyToSign = keysToSign[keyToSign->GetSelection()];
    int chosenKeyExpiry = keyExpiry->GetValue().GetTicks();

    GpgmeRepo gpgmeRepo;

    try {
        gpgmeRepo.SignKey(chosenKeyToSign, chosenSigningKey, chosenKeyExpiry);
    } catch (const char *e) {
        wxMessageBox(e, "Error", wxOK | wxICON_ERROR);
    }

    wxMessageBox("Key Signed", "Success", wxOK | wxICON_INFORMATION);

    Close();
}

SignKeyForm::~SignKeyForm()
{
    //dtor
}