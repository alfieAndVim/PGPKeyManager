///////////////////////////////////////////////////////////
//Progamming Languages in Cyber Security - CW2 - U2138875//
///////////////////////////////////////////////////////////

//Including the header files for the Progress class
#include <Progress.h>

//Implementing the Progress class in wxWidgets
Progress::Progress(wxWindow *parent) : wxDialog(parent, wxID_ANY, "Progress")
{
    //Creating a new activity indicator
    wxActivityIndicator *indicator = new wxActivityIndicator(this, wxID_ANY);
    //Starting the activity indicator
    indicator->Start();
    //Creating a new vertical box sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    //Adding the indicator to the sizer
    sizer->Add(indicator, 1, wxEXPAND);
    //Setting the sizer for the dialog
    SetSizer(sizer);
}

Progress::~Progress()
{
    //dtor
}