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

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxToolBar *toolbar = CreateToolBar(wxTB_HORIZONTAL | wxTB_FLAT | wxTB_TEXT);
    wxGrid *grid = new KeyList(keys, this);

    toolbar->AddTool(wxID_NEW, "New", wxArtProvider::GetBitmap(wxART_NEW));
    toolbar->AddTool(wxID_OPEN, "Open", wxArtProvider::GetBitmap(wxART_FILE_OPEN));
    toolbar->AddTool(wxID_SAVE, "Save", wxArtProvider::GetBitmap(wxART_FILE_SAVE));

    toolbar->Realize();

    sizer->Add(toolbar, 0, wxEXPAND);

    sizer->Add(grid, 1, wxEXPAND);

    SetSizer(sizer);
    
    Connect(wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(Main::OnNew));

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
}

Main::~Main()
{
    //dtor
}