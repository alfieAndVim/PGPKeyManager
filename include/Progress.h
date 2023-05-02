///////////////////////////////////////////////////////////
//Progamming Languages in Cyber Security - CW2 - U2138875//
///////////////////////////////////////////////////////////

//Ensuring the header file is included only once during compilation
#pragma once

//Including the necessary header files
#include <wx/wx.h>
#include <wx/activityindicator.h>

//Defining the Progress class
class Progress : public wxDialog
{
public:
    Progress(wxWindow *parent);
    ~Progress();
};