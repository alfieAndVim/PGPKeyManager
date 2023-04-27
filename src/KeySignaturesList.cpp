#include <KeySignaturesList.h>

KeySignaturesList::KeySignaturesList(wxWindow *parent, gpgme_key_t key) : wxGrid(parent, wxID_ANY) {
    
    //Creating a vector of KeySignature objects
    vector<KeySignature> signatures;

    //Creating a signature struct
    gpgme_key_sig_t signature = key->uids->signatures;

    //Iterating through the signatures
    while(signature != NULL){
        KeySignature tempSignature;
        tempSignature.signatureEmail = signature->email;
        tempSignature.signatureName = signature->name;
        tempSignature.signatureComment = signature->comment;
        tempSignature.signatureExpiration = signature->expires;
        signatures.push_back(tempSignature);
        signature = signature->next;
    }

    //Creating a grid with the number of signatures and 4 columns
    this->CreateGrid(signatures.size(), 4);

    //Setting the column labels
    this->SetColLabelValue(0, "Name");
    this->SetColLabelValue(1, "Email");
    this->SetColLabelValue(2, "Comment");
    this->SetColLabelValue(3, "Expiration");

    //Iterating through the signatures vector
    for(int i = 0; i < signatures.size(); i++) {
        this->SetCellValue(i, 0, signatures[i].signatureName);
        this->SetCellValue(i, 1, signatures[i].signatureEmail);
        this->SetCellValue(i, 2, signatures[i].signatureComment);
        this->SetCellValue(i, 3, to_string(signatures[i].signatureExpiration));
    }

    //Setting the grid properties
    this->AutoSize();
    this->HideRowLabels();
}

KeySignaturesList::~KeySignaturesList() {
    
}