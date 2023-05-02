///////////////////////////////////////////////////////////
//Progamming Languages in Cyber Security - CW2 - U2138875//
///////////////////////////////////////////////////////////

//Ensuring the header file is included only once during compilation
#pragma once
//Including the necessary header files
#include <wx/wx.h>
#include <Main.h>

//Defining the thread event for the key creation process
wxDECLARE_EVENT(key_creationEVT_PROCESS_COMPLETED, wxThreadEvent);
//Defining the thread event for the key retrieval process
wxDECLARE_EVENT(key_retrievalEVT_PROCESS_COMPLETED, wxThreadEvent);

//Basic wxwidgets structure derived from WxWidgets (2023)
//Defining the app class
class App : public wxApp
{
public:
    App();
    ~App();

    //Function to initialize the app and show the main frame
    virtual bool OnInit();

private:
    //Pointer to the main frame
    wxFrame *m_frame1 = nullptr;

};