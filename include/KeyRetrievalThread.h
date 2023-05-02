///////////////////////////////////////////////////////////
//Progamming Languages in Cyber Security - CW2 - U2138875//
///////////////////////////////////////////////////////////

//Ensuring the thread is only included once during compilation
#pragma once

//Including the necessary header files
#include <gpgme.h>
#include <wx/wx.h>
#include <wx/grid.h>
#include <vector>
#include <GpgmeRepo.h>
#include <App.h>

//Using the standard namespace
using namespace std;

//Defining the KeyRetrievalThread class
class KeyRetrievalThread : public wxThread
{
public:
    KeyRetrievalThread();
    ~KeyRetrievalThread();
    wxFrame *keyHandler;

protected:
    //Overriding the wxThread::Entry method
    virtual wxThread::ExitCode Entry();
};