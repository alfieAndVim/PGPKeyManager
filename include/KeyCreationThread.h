#pragma once

#include <gpgme.h>
#include <iostream>
#include <wx/wx.h>
#include <wx/thread.h>
#include <GpgmeRepo.h>
#include <KeyParms.h>
#include <App.h>
#include <NewKeyForm.h>

using namespace std;

class KeyCreationThread : public wxThread
{
public:
    KeyCreationThread();
    ~KeyCreationThread();
    KeyParms parms;
    wxDialog *newKeyHandler;

protected:
    virtual wxThread::ExitCode Entry();
};