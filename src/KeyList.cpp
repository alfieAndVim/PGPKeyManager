#include <vector>
#include <gpgme.h>
#include <KeyList.h>

using namespace std;

KeyList::KeyList(vector<gpgme_key_t> keys, wxWindow *parent) : wxGrid(parent, wxID_ANY) {

    this->CreateGrid(keys.size(), 4);

    this->SetColLabelValue(0, "Name");
    this->SetColLabelValue(1, "Email");
    this->SetColLabelValue(2, "Fingerprint");
    this->SetColLabelValue(3, "Key ID");

    for (int i = 0; i < keys.size(); i++)
    {
        gpgme_key_t key = keys[i];
        this->SetCellValue(i, 0, key->uids->name);
        this->SetCellValue(i, 1, key->uids->email);
        this->SetCellValue(i, 2, key->subkeys->fpr);
        this->SetCellValue(i, 3, key->subkeys->keyid);
    }
    
    this->AutoSize();
    this->EnableEditing(false);
    this->HideRowLabels();

}

KeyList::~KeyList() {
    //dtor
}