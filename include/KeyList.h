//Ensuring the header file is included only once during compilation
#pragma once

//Including the necessary header files
#include <wx/wx.h>
#include <wx/grid.h>
#include <gpgme.h>
#include <vector>
#include <Main.h>
#include <KeyOverview.h>

//Using the standard namespace
using namespace std;

//Defining the KeyList class
class KeyList : public wxGrid {
public:
    KeyList(vector<gpgme_key_t> keys, wxWindow *parent);

    void ShowKey(gpgme_key_t key);
    ~KeyList();
    
};