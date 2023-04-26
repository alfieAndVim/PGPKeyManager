//Including the header file for the NewKeyForm class
#include <NewKeyForm.h>

//Using thr standard namespace
using namespace std;

//Constructor for the new key form class
NewKeyForm::NewKeyForm() : wxDialog(NULL, wxID_ANY, "New Key", wxPoint(30,30), wxSize(800,600))
{

    //Creates a new scrolled window
    wxScrolledWindow *scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
    
    //Sets the scroll rate
    scrolledWindow->SetScrollRate(5, 5);

    //Creates a new box sizer
    wxBoxSizer *scrollSizer = new wxBoxSizer(wxVERTICAL);
    
    //Creates a new box sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    //Creates a new static text object and text input for the key name
    wxStaticText *nameLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Name");
    name = new wxTextCtrl(scrolledWindow, wxID_ANY, "Name");
    //Creates a new static text object and text input for the key email
    wxStaticText *emailLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Email");
    email = new wxTextCtrl(scrolledWindow, wxID_ANY, "Email");
    //Creates a new static text object and text input for the key comment
    wxStaticText *commentLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Comment");
    comment = new wxTextCtrl(scrolledWindow, wxID_ANY, "Comment");
    //Creates a new static text object and choice input for the key type
    wxStaticText *keyTypeLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Type");
    keyType = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    //Creates a new static text object and choice input for the key length
    wxStaticText *keyLengthLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Length");
    keyLength = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    //Creates a new static text object and date picker input for the key expiration
    wxStaticText *keyExpirationLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Key Expiration");
    keyExpiry = new wxDatePickerCtrl(scrolledWindow, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT | wxDP_SHOWCENTURY);
    //Creates a new static text object and text input for the key passphrase
    wxStaticText *passphraseLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Passphrase");
    passphrase = new wxTextCtrl(scrolledWindow, wxID_ANY, "Passphrase");
    //Creates a new static text object and text input for the key passphrase confirmation
    wxStaticText *confirmPassphraseLabel = new wxStaticText(scrolledWindow, wxID_ANY, "Confirm Passphrase");
    passphraseConfirm = new wxTextCtrl(scrolledWindow, wxID_ANY, "Confirm Passphrase");

    //Creates a new button for generating a key pair and a button for cancelling the key generation
    wxButton *generateKeyPair = new wxButton(scrolledWindow, wxID_ANY, "Generate");
    wxButton *cancel = new wxButton(scrolledWindow, wxID_ANY, "Cancel");

    //Binds the generate key pair button to the generate key pair function
    generateKeyPair->Bind(wxEVT_BUTTON, &NewKeyForm::GenerateKeyPair, this);

    //Adds length options for the key length choice
    keyLength->Append("1024");
    keyLength->Append("2048");
    keyLength->Append("4096");

    //Adds type options for the key type choice
    keyType->Append("DSA");
    keyType->Append("RSA");
    keyType->Append("ElGamal");
    keyType->Append("ECDSA");
    keyType->Append("EdDSA");
    keyType->Append("ECDH");
    keyType->Append("ECC");

    //Adds the objects to the sizer
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

    //Sets the sizer for the scrolled window
    scrolledWindow->SetSizer(sizer);
    //Adds the scrolled window to the scroll sizer
    scrollSizer->Add(scrolledWindow, 1, wxEXPAND);
    //Sets the scroll sizer for the dialog
    SetSizer(scrollSizer);

    //ctor
}

//Function to convert a string to a gpgme algorithm type
gpgme_pubkey_algo_t NewKeyForm::ConvertAlgoStringToAlgorithm(string algo)
{
    //Allows from the selection of the algorithm type, defaults to DSA
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

//Function to generate a key pair
void NewKeyForm::GenerateKeyPair(wxCommandEvent &event)
{
    //Gets the values from the inputs from the user
    string keyName = name->GetValue().ToStdString();
    string keyEmail = email->GetValue().ToStdString();
    string keyComment = comment->GetValue().ToStdString();
    gpgme_pubkey_algo_t keyAlgorithm = ConvertAlgoStringToAlgorithm(keyType->GetStringSelection().ToStdString());
    int keyLengthInt = stoi(keyLength->GetStringSelection().ToStdString());
    string keyExpiration = keyExpiry->GetValue().FormatISODate().ToStdString();
    string keyPassphrase = passphrase->GetValue().ToStdString();
    string keyConfirmPassphrase = passphraseConfirm->GetValue().ToStdString();

    //Checks if the passphrases match
    if(keyPassphrase != keyConfirmPassphrase)
    {
        wxMessageBox("Passphrases do not match", "Error", wxOK | wxICON_ERROR);
        return;
    }

    //Defines a new key parameters object, sets the class variables to the values from the user
    KeyParms keyParms;
    keyParms.keyName = keyName;
    keyParms.keyEmail = keyEmail;
    keyParms.keyComment = keyComment;
    keyParms.keyAlgo = gpgme_pubkey_algo_name(keyAlgorithm);
    keyParms.keyLength = keyLengthInt;
    keyParms.keyExpiry = keyExpiration;
    keyParms.keyPassphrase = keyPassphrase;

    //Defines a new GpgmeRepo object
    GpgmeRepo gpgmeRepo;

    //Creates a new key creation thread object
    KeyCreationThread *keyCreationThread = new KeyCreationThread();

    //Sets the key creation thread parameters to the key parameters object
    keyCreationThread->parms = keyParms;
    //Sets the key creation thread handler to the new key form
    keyCreationThread->newKeyHandler = this;

    //Creates the thread, displays an error message if it fails
    if (keyCreationThread->Create() != wxTHREAD_NO_ERROR)
    {
        wxMessageBox("Can't create thread!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    //Runs the thread, displays an error message if it fails
    if (keyCreationThread->Run() != wxTHREAD_NO_ERROR)
    {
        wxMessageBox("Can't create thread!", "Error", wxOK | wxICON_ERROR);
        return;
    }

    //Shows the loading indicator and disables parent view
    this->loadingIndicator = new Progress(this);
    this->loadingIndicator->CentreOnParent();
    this->loadingIndicator->Show();
    this->Disable();

    //Binds the key creation thread completion event to the new key form
    Bind(key_creationEVT_PROCESS_COMPLETED, &NewKeyForm::OnKeyCreationThreadCompletion, this);
    

    
}

//Function to handle the key creation thread completion event
void NewKeyForm::OnKeyCreationThreadCompletion(wxThreadEvent &event)
{
    //Closes the loading indicator
    this->loadingIndicator->Close();

    //Enables the parent view
    this->Enable();
    
    //Checks if the key creation failed, displays an error message if it did
    if(event.GetInt() == -1){
        wxMessageBox("Key creation failed", "Error", wxOK | wxICON_ERROR);
    } else {
        wxMessageBox("Key creation succeeded", "Success", wxOK | wxICON_INFORMATION);
        Close();
    }

}

NewKeyForm::~NewKeyForm()
{
    //dtor
}