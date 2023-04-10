#pragma once

#include <wx/wx.h>
#include <wx/grid.h>
#include <gpgme.h>
#include <vector>

using namespace std;

class KeyList : public wxGrid {
public:
    KeyList(vector<gpgme_key_t> keys, wxWindow *parent);
    ~KeyList();

    
};