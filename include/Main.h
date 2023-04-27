// Ensuring the header file is included only once during compilation
#pragma once

//Including the necessary header files
#include <wx/wx.h>
#include <wx/artprov.h>
#include <wx/textfile.h>
#include <wx/grid.h>
#include <vector>
#include <GpgmeRepo.h>
#include <SignKeyForm.h>
#include <NewKeyForm.h>
#include <KeyList.h>
#include <iostream>
#include <gpgme.h>
#include <Progress.h>
#include <KeyRetrievalThread.h>

//Defining the Main class
class Main : public wxFrame
{
public:
    Main();
    ~Main();

    //Defining the Main functions
    void OnQuit(wxCommandEvent& event);
    void OnNew(wxCommandEvent& event);
    void OnImport(wxCommandEvent& event);
    void OnSign(wxCommandEvent& event);
    void OnKeysChanged();
    void OnKeysRetrieved(wxThreadEvent& event);

    //Defining the Main variables
    int KeySelected = -1;

private:
    //Defining the Main private variables
    vector<gpgme_key_t> keys;
    wxGrid *keyList = nullptr;
    wxBoxSizer *sizer = nullptr;
    wxActivityIndicator *progress = nullptr;
};