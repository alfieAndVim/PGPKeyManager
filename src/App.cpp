#include <App.h>
#include <Main.h>

wxIMPLEMENT_APP(App);

wxDEFINE_EVENT(key_creationEVT_PROCESS_COMPLETED, wxThreadEvent);

App::App()
{
    //ctor
}

App::~App()
{
    //dtor
}

bool App::OnInit()
{

    m_frame1 = new Main();
    m_frame1->Show();

    return true;
}