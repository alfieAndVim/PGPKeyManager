//Ensuring the header file is included only once during compilation
#pragma once

//Including the necessary header files
#include <gpgme.h>
#include <iostream>
#include <wx/wx.h>
#include <wx/thread.h>
#include <GpgmeRepo.h>
#include <KeyParms.h>
#include <App.h>
#include <NewKeyForm.h>

//Using the standard namespace
using namespace std;

//Defining the KeyCreationThread class
class KeyCreationThread : public wxThread
{
public:
    KeyCreationThread();
    ~KeyCreationThread();
    KeyParms parms;
    wxDialog *newKeyHandler;

protected:
    //Overriding the wxThread::Entry method
    virtual wxThread::ExitCode Entry();
};