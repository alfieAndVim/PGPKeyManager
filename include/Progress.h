#pragma once

#include <wx/wx.h>
#include <wx/activityindicator.h>

class Progress : public wxDialog
{
public:
    Progress(wxWindow *parent);
    ~Progress();
};