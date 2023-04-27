#pragma once

#include <gpgme.h>
#include <wx/wx.h>
#include <wx/grid.h>
#include <KeySignature.h>
#include <iostream>
#include <vector>

using namespace std;

class KeySignaturesList : public wxGrid {
public:
    KeySignaturesList(wxWindow *parent, gpgme_key_t key);
    ~KeySignaturesList();
    string ConvertTimestampToDate(long timestamp);
};