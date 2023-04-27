//Including headers for the KeyRetrievalThread class
#include <KeyRetrievalThread.h>

//Constructor for the KeyRetrievalThread class
KeyRetrievalThread::KeyRetrievalThread() : wxThread(wxTHREAD_DETACHED)
{
    
}

KeyRetrievalThread::ExitCode KeyRetrievalThread::Entry()
{
    //Defines the GpgmeRepo object
    GpgmeRepo gpgmeRepo;

    //Creates a wxCommandEvent object to notify the main thread of the completion of the key generation process
    wxThreadEvent event(key_retrievalEVT_PROCESS_COMPLETED);

    //Defines a new vector of gpgme_key_t objects
    vector<gpgme_key_t> keys;

    //Tries to retrieve the keys
    try {
        keys = gpgmeRepo.GetKeys();
    } catch (const gpgme_error_t &e) {
        //If the key retrieval process fails, the error is sent to the main thread
        event.SetPayload(keys);
        wxQueueEvent(keyHandler, event.Clone());
        return (ExitCode)-1;
    }

    //If the key retrieval process succeeds, the keys are sent to the main thread
    event.SetPayload(keys);
    wxQueueEvent(keyHandler, event.Clone());
    return (ExitCode)0;
}

//Destructor for the KeyRetrievalThread class
KeyRetrievalThread::~KeyRetrievalThread()
{
    //dtor
}