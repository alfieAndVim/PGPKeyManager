#pragma once

#include <wx/wx.h>
#include <wx/grid.h>
#include <gpgme.h>
#include <vector>
#include <Main.h>
#include <KeyOverview.h>

using namespace std;

class KeyList : public wxGrid {
public:
    KeyList(vector<gpgme_key_t> keys, wxWindow *parent);

    void ShowKey(gpgme_key_t key);
    ~KeyList();
    
};