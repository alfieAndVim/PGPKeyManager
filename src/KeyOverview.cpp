#include <KeyOverview.h>
#include <fstream>

using namespace std;

KeyOverview::KeyOverview(string keyId, wxWindow *parent) : wxFrame(parent, wxID_ANY, "Key Overview", wxDefaultPosition, wxSize(500, 400))
{
    
    GpgmeRepo gpgmeRepo;

    gpgme_key_t publicKey;
    gpgme_key_t secretKey;

    bool hasSecretKey = false;

    Bind(wxEVT_CLOSE_WINDOW, &KeyOverview::CloseWindow, this);

    try {
        this->publicKey = gpgmeRepo.GetKeyById(keyId);
        //publicKey = gpgmeRepo.GetKeyById(keyId);
    } catch (const char *e) {
        wxMessageBox(e, "Error", wxOK | wxICON_ERROR);
        this->Close();
        return;
    }

    try {
        this->secretKey = gpgmeRepo.GetSecretKeyById(keyId);
        //secretKey = gpgmeRepo.GetSecretKeyById(keyId);
        this->hasSecretKey = true;
        //hasSecretKey = true;
    } catch (const char *e) {
        this->hasSecretKey = false;
        //hasSecretKey = false;
    }

    wxScrolledWindow *scrolledWindow = new wxScrolledWindow(this, wxID_ANY);

    scrolledWindow->SetScrollRate(5, 5);

    wxBoxSizer *scrollSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText *emailLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Email:");

    wxFont font = emailLabel->GetFont();
    font.SetWeight(wxFONTWEIGHT_BOLD);
    emailLabel->SetFont(font);

    wxStaticText *email = new wxStaticText(scrolledWindow, wxID_ANY, this->publicKey->uids->email);
    wxStaticText *nameLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Name:");
    nameLabel->SetFont(font);

    wxStaticText *name = new wxStaticText(scrolledWindow, wxID_ANY, this->publicKey->uids->name);
    wxStaticText *fingerprintLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Fingerprint:");
    fingerprintLabel->SetFont(font);

    wxStaticText *fingerprint = new wxStaticText(scrolledWindow, wxID_ANY, this->publicKey->subkeys->fpr);
    wxStaticText *keyIdentifierLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key ID:");
    keyIdentifierLabel->SetFont(font);

    wxStaticText *keyIdentifier = new wxStaticText(scrolledWindow, wxID_ANY, keyId);

    wxStaticText *keyTypeLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Type:");
    keyTypeLabel->SetFont(font);

    wxStaticText *keyType = new wxStaticText(scrolledWindow, wxID_ANY, gpgme_pubkey_algo_name(this->publicKey->subkeys->pubkey_algo));

    wxStaticText *keyLengthLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Length:");
    keyLengthLabel->SetFont(font);

    wxStaticText *keyLength = new wxStaticText(scrolledWindow, wxID_ANY, to_string(this->publicKey->subkeys->length).c_str());

    wxStaticText *creationDateLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Creation Date:");
    creationDateLabel->SetFont(font);

    wxStaticText *creationDate = new wxStaticText(scrolledWindow, wxID_ANY, GetTimestamp(this->publicKey));

    wxStaticText *expirationDateLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Expiration Date:");
    expirationDateLabel->SetFont(font);

    wxStaticText *expirationDate = new wxStaticText(scrolledWindow, wxID_ANY, GetExpriationDate(this->publicKey));

    wxStaticText *secretKeyLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Has Secret Key:");
    secretKeyLabel->SetFont(font);

    wxStaticText *hasSecretKeyText = new wxStaticText(scrolledWindow, wxID_ANY, this->hasSecretKey ? "Yes" : "No");

    wxButton *showPublicKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Show Public Key");
    
    wxButton *showSecretKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Show Secret Key");

    wxButton *savePublicKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Save Public Key");

    wxButton *saveSecretKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Save Secret Key");

    wxButton *deleteKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Delete Key");


    if (!this->hasSecretKey) {
        showSecretKeyButton->Disable();
        saveSecretKeyButton->Disable();
    }

    showPublicKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::ShowKeyBlock, this);
    showSecretKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::ShowSecretKeyBlock, this);
    savePublicKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::SavePublicKey, this);
    saveSecretKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::SaveSecretKey, this);
    deleteKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::DeleteKey, this);

    sizer->Add(emailLabel, 0, wxALL, 5);
    sizer->Add(email, 0, wxALL, 5);
    sizer->Add(nameLabel, 0, wxALL, 5);
    sizer->Add(name, 0, wxALL, 5);
    sizer->Add(fingerprintLabel, 0, wxALL, 5);
    sizer->Add(fingerprint, 0, wxALL, 5);
    sizer->Add(keyIdentifierLabel, 0, wxALL, 5);
    sizer->Add(keyIdentifier, 0, wxALL, 5);
    sizer->Add(keyTypeLabel, 0, wxALL, 5);
    sizer->Add(keyType, 0, wxALL, 5);
    sizer->Add(secretKeyLabel, 0, wxALL, 5);
    sizer->Add(hasSecretKeyText, 0, wxALL, 5);
    sizer->Add(keyLengthLabel, 0, wxALL, 5);
    sizer->Add(keyLength, 0, wxALL, 5);
    sizer->Add(creationDateLabel, 0, wxALL, 5);
    sizer->Add(creationDate, 0, wxALL, 5);
    sizer->Add(expirationDateLabel, 0, wxALL, 5);
    sizer->Add(expirationDate, 0, wxALL, 5);
    sizer->Add(showPublicKeyButton, 0, wxALL, 5);
    sizer->Add(showSecretKeyButton, 0, wxALL, 5);
    sizer->Add(savePublicKeyButton, 0, wxALL, 5);
    sizer->Add(saveSecretKeyButton, 0, wxALL, 5);
    sizer->Add(deleteKeyButton, 0, wxALL, 5);

    scrolledWindow->SetSizer(sizer);
    scrollSizer->Add(scrolledWindow, 1, wxEXPAND);

    SetSizer(scrollSizer);

    
}

KeyOverview::~KeyOverview()
{
    //dtor
}

void KeyOverview::ShowKeyBlock(wxCommandEvent &event)
{
    GpgmeRepo gpgmeRepo;
    wxMessageBox(gpgmeRepo.GetKeyBlock(this->publicKey), "Key Block", wxOK | wxICON_INFORMATION);
}

void KeyOverview::ShowSecretKeyBlock(wxCommandEvent &event)
{
    GpgmeRepo gpgmeRepo;
    wxMessageBox(gpgmeRepo.GetKeyBlock(this->secretKey, true), "Key Block", wxOK | wxICON_INFORMATION);
}

void KeyOverview::SavePublicKey(wxCommandEvent &event)
{
    GpgmeRepo gpgmeRepo;
    
    wxString defaultFilename = this->publicKey->uids->email;
    defaultFilename += ".asc";
    wxString defaultDir = wxGetCwd();
    wxString wildcard = "Public Key (*.asc)|*.asc";

    wxFileDialog saveFileDialog(this, "Save Public Key", defaultDir, defaultFilename, wildcard, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    ofstream fileStream(saveFileDialog.GetPath().ToStdString());
    if (fileStream.is_open()) {
        fileStream << gpgmeRepo.GetKeyBlock(this->publicKey);
        fileStream.close();
    }

}

void KeyOverview::SaveSecretKey(wxCommandEvent &event)
{
    GpgmeRepo gpgmeRepo;
    
    wxString defaultFilename = this->publicKey->uids->email;
    defaultFilename += "-SECRET";
    defaultFilename += ".asc";
    wxString defaultDir = wxGetCwd();
    wxString wildcard = "Secret Key (*.asc)|*.asc";

    wxFileDialog saveFileDialog(this, "Save Secret Key", defaultDir, defaultFilename, wildcard, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    if (saveFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    ofstream fileStream(saveFileDialog.GetPath().ToStdString());
    if (fileStream.is_open()) {
        fileStream << gpgmeRepo.GetKeyBlock(this->secretKey, true);
        fileStream.close();
    }
}

void KeyOverview::DeleteKey(wxCommandEvent &event)
{
    GpgmeRepo gpgmeRepo;

    try {
        gpgmeRepo.DeleteKey(this->publicKey);
    } catch (const char *e) {
        wxMessageBox(e, "Error", wxOK | wxICON_ERROR);
        return;
    }
    this->Close();
}

void KeyOverview::CloseWindow(wxCloseEvent &event)
{
    this->Destroy();
}

string KeyOverview::GetTimestamp(gpgme_key_t key)
{
    time_t timestamp = key->subkeys->timestamp;
    struct tm *timeinfo = localtime(&timestamp);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}


string KeyOverview::GetExpriationDate(gpgme_key_t key)
{
    time_t timestamp = key->subkeys->expires;
    if (timestamp == 0) {
        return "Never";
    }
    struct tm *timeinfo = localtime(&timestamp);
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    return string(buffer);
}
