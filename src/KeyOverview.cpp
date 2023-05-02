///////////////////////////////////////////////////////////
//Progamming Languages in Cyber Security - CW2 - U2138875//
///////////////////////////////////////////////////////////

//Including the header file for the KeyOverview class
#include <KeyOverview.h>

//Using the standard namespace
using namespace std;


KeyOverview::KeyOverview(gpgme_key_t key, wxWindow *parent) : wxFrame(parent, wxID_ANY, "Key Overview", wxDefaultPosition, wxSize(600, 400))
{
    //Creating a new instance of the GpgmeRepo class
    GpgmeRepo gpgmeRepo;

    //Defining the public and secret key variables
    gpgme_key_t publicKey;
    gpgme_key_t secretKey;

    char *keyId;

    //Defining the hasSecretKey variable
    bool hasSecretKey = false;

    //Binding the CloseWindow function to the wxEVT_CLOSE_WINDOW event
    Bind(wxEVT_CLOSE_WINDOW, &KeyOverview::CloseWindow, this);

    //Setting the public key
    this->publicKey = key;
    //Setting the key ID
    keyId = key->subkeys->keyid;
    

    //Getting the secret key by the key ID
    try {
        this->secretKey = gpgmeRepo.GetSecretKeyById(key->subkeys->keyid);
        this->hasSecretKey = true;
        
    } catch (gpgme_error_t &e) {
        this->hasSecretKey = false;
        
    }

    //Creating a new instance of the wxScrolledWindow class
    wxScrolledWindow *scrolledWindow = new wxScrolledWindow(this, wxID_ANY);

    //Setting the scroll rate of the scrolled window
    scrolledWindow->SetScrollRate(5, 5);

    //Creating a new instance of the wxBoxSizer class
    wxBoxSizer *scrollSizer = new wxBoxSizer(wxVERTICAL);
    //Creating a new instance of the wxBoxSizer class
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    //Creating a static text object and setting the email of the public key as the label
    wxStaticText *emailLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Email:");
    wxFont font = emailLabel->GetFont();
    font.SetWeight(wxFONTWEIGHT_BOLD);
    emailLabel->SetFont(font);
    wxStaticText *email = new wxStaticText(scrolledWindow, wxID_ANY, this->publicKey->uids->email);
    
    //Creating a static text object and setting the name of the public key as the label
    wxStaticText *nameLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Name:");
    nameLabel->SetFont(font);
    wxStaticText *name = new wxStaticText(scrolledWindow, wxID_ANY, this->publicKey->uids->name);
    
    //Creating a static text object and setting the fingerprint of the public key as the label
    wxStaticText *fingerprintLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Fingerprint:");
    fingerprintLabel->SetFont(font);
    wxStaticText *fingerprint = new wxStaticText(scrolledWindow, wxID_ANY, this->publicKey->subkeys->fpr);
    
    //Creating a static text object and setting the key ID of the public key as the label
    wxStaticText *keyIdentifierLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key ID:");
    keyIdentifierLabel->SetFont(font);
    wxStaticText *keyIdentifier = new wxStaticText(scrolledWindow, wxID_ANY, keyId);

    //Creating a static text object and setting the key type of the public key as the label
    wxStaticText *keyTypeLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Type:");
    keyTypeLabel->SetFont(font);
    wxStaticText *keyType = new wxStaticText(scrolledWindow, wxID_ANY, gpgme_pubkey_algo_name(this->publicKey->subkeys->pubkey_algo));

    //Creating a static text object and setting the key length of the public key as the label
    wxStaticText *keyLengthLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Length:");
    keyLengthLabel->SetFont(font);
    wxStaticText *keyLength = new wxStaticText(scrolledWindow, wxID_ANY, to_string(this->publicKey->subkeys->length).c_str());

    //Creating a static text object and setting the creation date of the public key as the label
    wxStaticText *creationDateLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Creation Date:");
    creationDateLabel->SetFont(font);
    wxStaticText *creationDate = new wxStaticText(scrolledWindow, wxID_ANY, GetTimestamp(this->publicKey));

    //Creating a static text object and setting the expiration date of the public key as the label
    wxStaticText *expirationDateLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Expiration Date:");
    expirationDateLabel->SetFont(font);
    wxStaticText *expirationDate = new wxStaticText(scrolledWindow, wxID_ANY, GetExpriationDate(this->publicKey));

    //Creating a static text object and setting the availablitity of a secret key for the public key as the label
    wxStaticText *secretKeyLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Has Secret Key:");
    secretKeyLabel->SetFont(font);
    wxStaticText *hasSecretKeyText = new wxStaticText(scrolledWindow, wxID_ANY, this->hasSecretKey ? "Yes" : "No");

    //Creating a wxbutton object to show the public key block
    wxButton *showPublicKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Show Public Key");
    
    //Creating a wxbutton object to show the secret key block
    wxButton *showSecretKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Show Secret Key");

    //Creating a wxbutton object to save the public key
    wxButton *savePublicKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Save Public Key");

    //Creating a wxbutton object to save the secret key
    wxButton *saveSecretKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Save Secret Key");

    //Creating a wxbutton object to delete the key
    wxButton *deleteKeyButton = new wxButton(scrolledWindow, wxID_ANY, "Delete Key");

    wxGrid *keySignatures = new KeySignaturesList(scrolledWindow, this->publicKey);

    //Checks if the public key has a secret key and disables the secret key buttons as necessary
    if (!this->hasSecretKey) {
        showSecretKeyButton->Disable();
        saveSecretKeyButton->Disable();
    }

    //Binds the buttons to their respective event functions
    showPublicKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::ShowKeyBlock, this);
    showSecretKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::ShowSecretKeyBlock, this);
    savePublicKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::SavePublicKey, this);
    saveSecretKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::SaveSecretKey, this);
    deleteKeyButton->Bind(wxEVT_BUTTON, &KeyOverview::DeleteKey, this);

    //Adds all the elements to the views sizer (layout)
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
    sizer->Add(keySignatures, 0, wxALL, 5);

    //Sets the sizer to the scrolled window and the scrolled window to the views sizer
    scrolledWindow->SetSizer(sizer);
    scrollSizer->Add(scrolledWindow, 1, wxEXPAND);

    //Sets the views sizer to the view
    SetSizer(scrollSizer);

    
}

//deconstructor for the KeyOverview class
KeyOverview::~KeyOverview()
{
    //dtor
}

//Event function to show the key block of the public key
void KeyOverview::ShowKeyBlock(wxCommandEvent &event)
{
    GpgmeRepo gpgmeRepo;
    wxMessageBox(gpgmeRepo.GetKeyBlock(this->publicKey), "Key Block", wxOK | wxICON_INFORMATION);
}

//Event function to show the key block of the secret key
void KeyOverview::ShowSecretKeyBlock(wxCommandEvent &event)
{
    GpgmeRepo gpgmeRepo;
    wxMessageBox(gpgmeRepo.GetKeyBlock(this->secretKey, true), "Key Block", wxOK | wxICON_INFORMATION);
}

//Event function to save the public key
void KeyOverview::SavePublicKey(wxCommandEvent &event)
{
    GpgmeRepo gpgmeRepo;
    
    //Sets the default filename to the email of the public key
    wxString defaultFilename = this->publicKey->uids->email;
    //Adds the extension to the filename
    defaultFilename += ".asc";
    //Sets the default directory to the current working directory
    wxString defaultDir = wxGetCwd();
    //Sets the wildcard to only show .asc files
    wxString wildcard = "Public Key (*.asc)|*.asc";

    //Creates a wxFileDialog object to save the public key
    wxFileDialog saveFileDialog(this, "Save Public Key", defaultDir, defaultFilename, wildcard, wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

    //Checks if the user pressed cancel
    if (saveFileDialog.ShowModal() == wxID_CANCEL) {
        return;
    }

    //Creates a file stream object to write the public key to the file
    ofstream fileStream(saveFileDialog.GetPath().ToStdString());
    if (fileStream.is_open()) {
        fileStream << gpgmeRepo.GetKeyBlock(this->publicKey);
        fileStream.close();
    }

}

//Event function to save the secret key
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

//Event function to delete the key
void KeyOverview::DeleteKey(wxCommandEvent &event)
{
    GpgmeRepo gpgmeRepo;

    //Uses the gpgmeRepo to delete the key
    try {
        gpgmeRepo.DeleteKey(this->publicKey);
    } catch (gpgme_error_t &e) {
        wxMessageBox(gpgme_strerror(e), "Error", wxOK | wxICON_ERROR);
        return;
    }
    this->Close();
}

//Event function to close the window
void KeyOverview::CloseWindow(wxCloseEvent &event)
{
    this->Destroy();
}

//Function to get the timestamp of the key
string KeyOverview::GetTimestamp(gpgme_key_t key)
{
    //Gets the timestamp from the key and converts it to a string
    time_t timestamp = key->subkeys->timestamp;
    //Compares the UTM epoch time to the timestamp
    struct tm *timeinfo = localtime(&timestamp);
    //Creates a buffer to store the timestamp in
    char buffer[80];
    //Converts the timestamp to a string
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    //Returns the timestamp as a string
    return string(buffer);
}

//Function to get the expiration date of the key
string KeyOverview::GetExpriationDate(gpgme_key_t key)
{
    //Gets the expiration date from the key and converts it to a string
    time_t timestamp = key->subkeys->expires;
    //Checks that the key expires
    if (timestamp == 0) {
        return "Never";
    }
    //Compares the UTM epoch time to the timestamp
    struct tm *timeinfo = localtime(&timestamp);
    //Creates a buffer to store the timestamp in
    char buffer[80];
    //Converts the timestamp to a string
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", timeinfo);
    //Returns the timestamp as a string
    return string(buffer);
}
