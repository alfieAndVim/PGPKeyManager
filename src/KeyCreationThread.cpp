// Including headers for the KeyCreationThread class and the App class
#include <KeyCreationThread.h>

//Constructor for the KeyCreationThread class as a detached thread
KeyCreationThread::KeyCreationThread() : wxThread(wxTHREAD_DETACHED)
{
    
}

//The Entry() function is the function that is called when the thread is started
KeyCreationThread::ExitCode KeyCreationThread::Entry()
{
    //Defines the GpgmeRepo object
    GpgmeRepo gpgmeRepo;

    //Gets the key parameters from the KeyParms object
    string keyParms = parms.getParms();
    //Creates a wxCommandEvent object to notify the main thread of the completion of the key generation process
    wxThreadEvent event(key_creationEVT_PROCESS_COMPLETED);

    cout << "key parms: " << keyParms << endl;

    //Tries to generate the key pair
    try {
        gpgmeRepo.GenerateKeyPair(parms);
    } catch (const gpgme_error_t &e) {
        
        cout << "error caught" << endl;
        //If the key generation process fails, the error is sent to the main thread
        event.SetPayload(1);
        
        //The event is queued to be sent to the main thread
        wxQueueEvent(newKeyHandler, event.Clone());

        //The thread is terminated
        return (ExitCode)-1;
    }

    cout << "success" << endl;

    //If the key generation process succeeds, the success message is sent to the main thread
    event.SetPayload(0);
    //The event is queued to be sent to the main thread
    wxQueueEvent(newKeyHandler, event.Clone());
    //The thread is terminated
    return (ExitCode)0;
    
}

//Destructor for the KeyCreationThread class
KeyCreationThread::~KeyCreationThread()
{
    //dtor
}