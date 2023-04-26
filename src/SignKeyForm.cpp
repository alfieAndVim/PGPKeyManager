//Including the header files for the SignKeyForm class
#include <SignKeyForm.h>

//Using the standard namespace
using namespace std;

//Implementing the SignKeyForm class in wxWidgets
SignKeyForm::SignKeyForm() : wxDialog(nullptr, wxID_ANY, "Sign Key", wxPoint(30, 30), wxSize(800, 450))
{
    //Creating a scolled window
    wxScrolledWindow *scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);

    //Setting the scroll rate for the scrolled window
    scrolledWindow->SetScrollRate(5, 5);

    //Creating a new box sizer
    wxBoxSizer *scrollSizer = new wxBoxSizer(wxVERTICAL);

    //Creating a new box sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    //Defining a new GpgmeRepo object
    GpgmeRepo gpgmeRepo;

    //Getting the secret keys and keys from the GpgmeRepo object
    signingKeys = gpgmeRepo.GetSecretKeys();
    keysToSign = gpgmeRepo.GetKeys();

    //Creating a new static text object and choice input for the signing key
    wxStaticText *signingKeyLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key");
    signingKey = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    //Creating a new static text object and choice input for the key to sign
    wxStaticText *keyToSignLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key To Sign");
    keyToSign = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    //Creating a new static text object and date picker for the key expiry
    wxStaticText *keyExpiryLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Expiration");
    keyExpiry = new wxDatePickerCtrl(scrolledWindow, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);

    //Creating a new button for signing the key and a cancel button
    wxButton *signKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Sign Key");
    wxButton *cancelButton = new wxButton(scrolledWindow, wxID_ANY, "Cancel");

    //Adding the options for the signing key and the key to sign
    for (int i = 0; i < signingKeys.size(); i++)
    {
        signingKey->Append(signingKeys[i]->uids->email);
    }

    for (int i = 0; i < keysToSign.size(); i++)
    {
        keyToSign->Append(keysToSign[i]->uids->email);
    }

    //Adding the static text and choice inputs to the sizer
    sizer->Add(signingKeyLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(signingKey, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyToSignLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyToSign, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyExpiryLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyExpiry, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(signKeyButton, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(cancelButton, wxSizerFlags(1).Expand().Border(wxALL, 5));

    //Binding the sign key button to the SignKey function
    signKeyButton->Bind(wxEVT_BUTTON, &SignKeyForm::SignKey, this);

    //Setting the sizer for the scrolled window and the scrolled window for the scroll sizer
    scrolledWindow->SetSizer(sizer);
    scrollSizer->Add(scrolledWindow, 1, wxEXPAND);
    SetSizer(scrollSizer);

    
}

//Defining the SignKey function
void SignKeyForm::SignKey(wxCommandEvent &event)
{
    //Getting the chosen signing key, key to sign and key expiry
    gpgme_key_t chosenSigningKey = signingKeys[signingKey->GetSelection()];
    gpgme_key_t chosenKeyToSign = keysToSign[keyToSign->GetSelection()];
    long chosenKeyExpiry = keyExpiry->GetValue().GetTicks();

    //Defining a new GpgmeRepo object
    GpgmeRepo gpgmeRepo;

    //Signing the key
    try {
        gpgmeRepo.SignKey(chosenKeyToSign, chosenSigningKey, chosenKeyExpiry);
    } catch (gpgme_error_t &e) {
        wxMessageBox(gpgme_strerror(e), "Error", wxOK | wxICON_ERROR);
        return;
    }

    //Showing a success message
    wxMessageBox("Key Signed", "Success", wxOK | wxICON_INFORMATION);

    //Closing the form
    Close();
}

SignKeyForm::~SignKeyForm()
{
    //dtor
}