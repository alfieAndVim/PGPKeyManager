#include <Progress.h>

Progress::Progress(wxWindow *parent) : wxDialog(parent, wxID_ANY, "Progress")
{
    wxActivityIndicator *indicator = new wxActivityIndicator(this, wxID_ANY);
    indicator->Start();

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(indicator, 1, wxEXPAND);
    SetSizer(sizer);
}

Progress::~Progress()
{
    //dtor
}