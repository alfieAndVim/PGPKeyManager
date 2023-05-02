///////////////////////////////////////////////////////////
//Progamming Languages in Cyber Security - CW2 - U2138875//
///////////////////////////////////////////////////////////

//including header files for the main and app classes
#include <App.h>
#include <Main.h>

//implementing the app class in wxWidgets
wxIMPLEMENT_APP(App);

//defining the event for the key creation process
wxDEFINE_EVENT(key_creationEVT_PROCESS_COMPLETED, wxThreadEvent);
//defining the event for the key retrieval process
wxDEFINE_EVENT(key_retrievalEVT_PROCESS_COMPLETED, wxThreadEvent);

//Basic wxwidgets structure derived from WxWidgets (2023)
//constructor and destructor for the app class
App::App()
{
    //ctor
}

App::~App()
{
    //dtor
}

//function to initialize the app and show the main frame
bool App::OnInit()
{

    m_frame1 = new Main();
    m_frame1->Show();

    return true;
}