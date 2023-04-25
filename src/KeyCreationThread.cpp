#include <KeyCreationThread.h>
#include <App.h>

KeyCreationThread::KeyCreationThread() : wxThread(wxTHREAD_DETACHED)
{
    
}

KeyCreationThread::ExitCode KeyCreationThread::Entry()
{
    GpgmeRepo gpgmeRepo;

    string keyParms = parms.getParms();
    wxCommandEvent event(key_creationEVT_PROCESS_COMPLETED);

    try {
        gpgmeRepo.GenerateKeyPair(parms);
    } catch (const std::exception& e) {
        cout << e.what() << endl;
        
        event.SetInt(-1);
        event.SetString(e.what());
        wxQueueEvent(newKeyHandler, event.Clone());

        return (ExitCode)-1;
    }

    event.SetInt(0);
    event.SetString("Key pair generated successfully");
    wxQueueEvent(newKeyHandler, event.Clone());
    return (ExitCode)0;
    
}

KeyCreationThread::~KeyCreationThread()
{
    //dtor
}