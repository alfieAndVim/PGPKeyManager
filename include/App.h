#pragma once

#include <wx/wx.h>
#include <Main.h>

wxDECLARE_EVENT(key_creationEVT_PROCESS_COMPLETED, wxThreadEvent);

class App : public wxApp
{
public:
    App();
    ~App();

    virtual bool OnInit();

private:
    Main *m_frame1 = nullptr;

};