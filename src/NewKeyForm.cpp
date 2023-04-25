#include <NewKeyForm.h>

using namespace std;



NewKeyForm::NewKeyForm() : wxDialog(NULL, wxID_ANY, "New Key", wxPoint(30,30), wxSize(800,600))
{

    wxScrolledWindow *scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
    
    scrolledWindow->SetScrollRate(5, 5);

    wxBoxSizer *scrollSizer = new wxBoxSizer(wxVERTICAL);
    

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText *nameLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Name");
    name = new wxTextCtrl(scrolledWindow, wxID_ANY, "Name");
    wxStaticText *emailLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Email");
    email = new wxTextCtrl(scrolledWindow, wxID_ANY, "Email");
    wxStaticText *commentLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Comment");
    comment = new wxTextCtrl(scrolledWindow, wxID_ANY, "Comment");
    wxStaticText *keyTypeLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Type");
    keyType = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    wxStaticText *keyLengthLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Length");
    keyLength = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    wxStaticText *keyExpirationLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Expiration");
    keyExpiry = new wxDatePickerCtrl(scrolledWindow, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
    wxStaticText *passphraseLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Passphrase");
    passphrase = new wxTextCtrl(scrolledWindow, wxID_ANY, "Passphrase");
    wxStaticText *confirmPassphraseLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Confirm Passphrase");
    passphraseConfirm = new wxTextCtrl(scrolledWindow, wxID_ANY, "Confirm Passphrase");

    wxButton *generateKeyPair = new wxButton(scrolledWindow, wxID_ANY, "Generate");
    wxButton *cancel = new wxButton(scrolledWindow, wxID_ANY, "Cancel");

    generateKeyPair->Bind(wxEVT_BUTTON, &NewKeyForm::GenerateKeyPair, this);

    keyLength->Append("1024");
    keyLength->Append("2048");
    keyLength->Append("4096");

    keyType->Append("DSA");
    keyType->Append("RSA");
    keyType->Append("ElGamal");
    keyType->Append("ECDSA");
    keyType->Append("EdDSA");
    keyType->Append("ECDH");
    keyType->Append("ECC");



    sizer->Add(nameLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(name, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(emailLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(email, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(commentLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(comment, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyTypeLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyType, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyLengthLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyLength, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyExpirationLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(keyExpiry, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(passphraseLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(passphrase, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(confirmPassphraseLabel, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(passphraseConfirm, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(generateKeyPair, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(cancel, wxSizerFlags(1).Expand().Border(wxALL, 5));

    scrolledWindow->SetSizer(sizer);
    scrollSizer->Add(scrolledWindow, 1, wxEXPAND);
    SetSizer(scrollSizer);

    //ctor
}

gpgme_pubkey_algo_t NewKeyForm::ConvertAlgoStringToAlgorithm(string algo)
{
    if(algo == "DSA")
    {
        return GPGME_PK_DSA;
    }
    else if(algo == "RSA")
    {
        return GPGME_PK_RSA;
    }
    else if(algo == "ElGamal")
    {
        return GPGME_PK_ELG;
    }
    else if(algo == "ECDSA")
    {
        return GPGME_PK_ECDSA;
    }
    else if(algo == "EdDSA")
    {
        return GPGME_PK_ECDH;
    }
    else if(algo == "ECDH")
    {
        return GPGME_PK_ECDH;
    }
    else if(algo == "ECC")
    {
        return GPGME_PK_ECC;
    }
    else
    {
        return GPGME_PK_DSA;
    }
    
}

void NewKeyForm::GenerateKeyPair(wxCommandEvent &event)
{
    string keyName = name->GetValue().ToStdString();
    string keyEmail = email->GetValue().ToStdString();
    string keyComment = comment->GetValue().ToStdString();
    gpgme_pubkey_algo_t keyAlgorithm = ConvertAlgoStringToAlgorithm(keyType->GetStringSelection().ToStdString());
    int keyLengthInt = stoi(keyLength->GetStringSelection().ToStdString());
    string keyExpiration = keyExpiry->GetValue().FormatISODate().ToStdString();
    
    string keyPassphrase = passphrase->GetValue().ToStdString();
    string keyConfirmPassphrase = passphraseConfirm->GetValue().ToStdString();

    if(keyPassphrase != keyConfirmPassphrase)
    {
        wxMessageBox("Passphrases do not match", "Error", wxOK | wxICON_ERROR);
        return;
    }

    KeyParms keyParms;
    keyParms.keyName = keyName;
    keyParms.keyEmail = keyEmail;
    keyParms.keyComment = keyComment;
    keyParms.keyAlgo = gpgme_pubkey_algo_name(keyAlgorithm);
    keyParms.keyLength = keyLengthInt;
    keyParms.keyExpiry = keyExpiration;
    keyParms.keyPassphrase = keyPassphrase;

    cout << keyParms.getParms() << endl;

    GpgmeRepo gpgmeRepo;

    KeyCreationThread *keyCreationThread = new KeyCreationThread();

    keyCreationThread->parms = keyParms;
    keyCreationThread->newKeyHandler = this;

    if (keyCreationThread->Create() != wxTHREAD_NO_ERROR)
    {
        wxMessageBox("Can't create thread!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    if (keyCreationThread->Run() != wxTHREAD_NO_ERROR)
    {
        wxMessageBox("Can't create thread!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    
    this->loadingIndicator = new Progress(this);
    this->loadingIndicator->CentreOnParent();
    this->loadingIndicator->Show();

    Bind(key_creationEVT_PROCESS_COMPLETED, &NewKeyForm::OnKeyCreationThreadCompletion, this);
    

    
}

void NewKeyForm::OnKeyCreationThreadCompletion(wxThreadEvent &event)
{
    this->loadingIndicator->Close();
    

    wxMessageBox("Key creation thread completed", "Success", wxOK | wxICON_INFORMATION);
    Close();
}

NewKeyForm::~NewKeyForm()
{
    //dtor
}