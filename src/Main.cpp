//Including the header file for the Main class
#include <Main.h>

//Using the standard namespace
using namespace std;

//The constructor for the Main class inheriting the wxFrame class
Main::Main() : wxFrame(NULL, wxID_ANY, "PGPKeyManager", wxPoint(30,30), wxSize(800,600))
{

    //Creating a new GpgmeRepo object
    GpgmeRepo repo;
    //Getting the keys from the repo
    vector<gpgme_key_t> keys = repo.GetKeys();

    //Setting the keys property
    this->keys = keys;

    //Creating a new wxBoxSizer object
    this->sizer = new wxBoxSizer(wxVERTICAL);

    //Creating a new toolbar
    wxToolBar *toolbar = CreateToolBar(wxTB_HORIZONTAL | wxTB_FLAT | wxTB_TEXT);

    //Creating a new KeyList object
    this->keyList = new KeyList(keys, this);

    //Adding the toolbar buttons for new, import and sign of keys
    toolbar->AddTool(wxID_NEW, "New", wxArtProvider::GetBitmap(wxART_NEW));
    toolbar->AddTool(wxID_ADD, "Import", wxArtProvider::GetBitmap(wxART_FILE_OPEN));
    toolbar->AddTool(wxID_APPLY, "Sign", wxArtProvider::GetBitmap(wxART_TICK_MARK));

    //Adding the toolbar to the layout
    toolbar->Realize();

    //Adding the toolbar and the key list to the sizer
    this->sizer->Add(toolbar, 0, wxEXPAND);
    this->sizer->Add(this->keyList, 1, wxEXPAND);

    //Setting the sizer for the frame
    SetSizer(this->sizer);
    
    //Binding the toolbar buttons to their respective functions
    Connect(wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Main::OnNew));
    Connect(wxID_ADD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Main::OnImport));
    Connect(wxID_APPLY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Main::OnSign));

    //Updating the layout
    Layout();   
}

//Event function to quit the application
void Main::OnQuit(wxCommandEvent& WXUNUSED(event)){
    Close(true);
}

//Event function to show the new key form
void Main::OnNew(wxCommandEvent& WXUNUSED(event)){
    wxDialog *dialog = new NewKeyForm();
    dialog->ShowModal();
    this->Enable();
    delete dialog;
    //updates the key list
    this->OnKeysChanged();
}

//Event function to show the import key window
void Main::OnImport(wxCommandEvent& WXUNUSED(event)){

    GpgmeRepo gpgmeRepo;
    //Opens a new file dialog
    wxFileDialog *openFileDialog = new wxFileDialog(this, _("Open key file"), "", "", "Key files (*.asc)|*.asc", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    //If the user cancels the dialog, return
    if (openFileDialog->ShowModal() == wxID_CANCEL)
        return;

    //Try to import the key using the file path
    try {
        gpgmeRepo.ImportKey(openFileDialog->GetPath().ToStdString());
        this->OnKeysChanged();
    } catch (gpgme_error_t &e) {
        wxMessageBox(gpgme_strerror(e), "Error", wxOK | wxICON_ERROR);
    }
}

//Event function to show the sign key window
void Main::OnSign(wxCommandEvent& WXUNUSED(event)){
    cout << "Sign" << endl;
    wxDialog *dialog = new SignKeyForm();

    dialog->ShowModal();
    delete dialog;
    this->OnKeysChanged();
}

//Event function to update the key list
void Main::OnKeysChanged(){

    GpgmeRepo gpgmeRepo;

    //Gets the keys from the repo
    this->keys = gpgmeRepo.GetKeys();
    //Removes the key list from the sizer
    this->sizer->Remove(1);
    //Deletes the old key list
    delete this->keyList;
    //Creates a new key list
    this->keyList = new KeyList(this->keys, this);
    //Adds the new key list to the sizer
    this->sizer->Add(this->keyList, 1, wxEXPAND);
    //Updates the layout
    SetSizer(this->sizer);
    Layout();
}


Main::~Main()
{
    //dtor
}