#include <Main.h>
#include <NewKeyForm.h>
#include <KeyList.h>
#include <iostream>
#include <gpgme.h>
#include <GpgmeRepo.h>

using namespace std;

Main::Main() : wxFrame(NULL, wxID_ANY, "PGPKeyManager", wxPoint(30,30), wxSize(800,600))
{

    GpgmeRepo repo;
    vector<gpgme_key_t> keys = repo.GetKeys();

    this->keys = keys;

    //wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    this->sizer = new wxBoxSizer(wxVERTICAL);

    wxToolBar *toolbar = CreateToolBar(wxTB_HORIZONTAL | wxTB_FLAT | wxTB_TEXT);
    //wxGrid *grid = new KeyList(keys, this);

    this->keyList = new KeyList(keys, this);

    toolbar->AddTool(wxID_NEW, "New", wxArtProvider::GetBitmap(wxART_NEW));
    toolbar->AddTool(wxID_ADD, "Import", wxArtProvider::GetBitmap(wxART_FILE_OPEN));
    toolbar->AddTool(wxID_APPLY, "Sign", wxArtProvider::GetBitmap(wxART_TICK_MARK));

    toolbar->Realize();

    this->sizer->Add(toolbar, 0, wxEXPAND);

    this->sizer->Add(this->keyList, 1, wxEXPAND);

    SetSizer(this->sizer);
    
    Connect(wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Main::OnNew));
    Connect(wxID_ADD, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Main::OnImport));
    Connect(wxID_APPLY, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Main::OnSign));

    Layout();   
}

void Main::OnQuit(wxCommandEvent& WXUNUSED(event)){
    cout << "Quit" << endl;
    Close(true);
    
}

void Main::OnNew(wxCommandEvent& WXUNUSED(event)){
    cout << "New" << endl;
    wxDialog *dialog = new NewKeyForm();
    
    dialog->ShowModal();
    delete dialog;
    this->OnKeysChanged();
}

void Main::OnImport(wxCommandEvent& WXUNUSED(event)){

    GpgmeRepo gpgmeRepo;

    wxFileDialog *openFileDialog = new wxFileDialog(this, _("Open key file"), "", "", "Key files (*.asc)|*.asc", wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog->ShowModal() == wxID_CANCEL)
        return;

    try {
        gpgmeRepo.ImportKey(openFileDialog->GetPath().ToStdString());
        this->OnKeysChanged();
    } catch (const char *msg) {
        wxMessageBox(msg, "Error", wxOK | wxICON_ERROR);
    }
}

void Main::OnSign(wxCommandEvent& WXUNUSED(event)){
    cout << "Sign" << endl;
    wxDialog *dialog = new SignKeyForm();

    dialog->ShowModal();
    delete dialog;
    this->OnKeysChanged();
}

void Main::OnKeysChanged(){

    GpgmeRepo gpgmeRepo;

    this->keys = gpgmeRepo.GetKeys();
    this->sizer->Remove(1);
    this->keyList = new KeyList(this->keys, this);
    this->sizer->Add(this->keyList, 1, wxEXPAND);
    SetSizer(this->sizer);
    Layout();
}


Main::~Main()
{
    //dtor
}