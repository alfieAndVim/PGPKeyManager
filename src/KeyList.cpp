//Including the header file for the KeyList class
#include <KeyList.h>

//Using the standard namespace
using namespace std;

//The constructor for the KeyList class inheriting the wxGrid class
KeyList::KeyList(vector<gpgme_key_t> keys, wxWindow *parent) : wxGrid(parent, wxID_ANY) {

    //Creating the grid with the number of keys and 4 columns
    this->CreateGrid(keys.size(), 4);

    this->SetColLabelValue(0, "Name");
    this->SetColLabelValue(1, "Email");
    this->SetColLabelValue(2, "Fingerprint");
    this->SetColLabelValue(3, "Key ID");
    

    //Iterating through the keys vector
    for (int i = 0; i < keys.size(); i++)
    {
        //Getting the key at the current index
        gpgme_key_t key = keys[i];
        //Setting the cell values for the current row
        this->SetCellValue(i, 0, key->uids->name);
        this->SetCellValue(i, 1, key->uids->email);
        this->SetCellValue(i, 2, key->subkeys->fpr);
        this->SetCellValue(i, 3, key->subkeys->keyid);
    }
    
    //Setting the grid properties
    this->AutoSize();
    this->EnableEditing(false);
    this->HideRowLabels();
    this->SetSelectionMode(wxGrid::wxGridSelectRows);

    //Binding the left double click event to the ShowKey function
    this->Bind(wxEVT_GRID_CELL_LEFT_DCLICK, [=](wxGridEvent& event) {
        //Getting the parent window
        Main *main = (Main *) this->GetParent();
        //Disabling the parent window
        main->Disable();
        //Getting the row index of the double clicked cell
        int row = event.GetRow();
        //Getting the key at the row index
        gpgme_key_t key = keys[row];
        //Calling the ShowKey function
        this->ShowKey(key);
    });

}

//Function to show an overview of a key
void KeyList::ShowKey(gpgme_key_t key) {
    //Creating a new KeyOverview object
    KeyOverview *overview = new KeyOverview(key->subkeys->keyid, NULL);
    //Binding the close event of the overview window to a lambda function
    overview->Bind(wxEVT_CLOSE_WINDOW, [=](wxCloseEvent& event) {

        //Getting the parent window
        Main *main = (Main *) this->GetParent();
        //Enabling the parent window
        main->Enable();
        //Calling the OnKeysChanged function to update the key list
        main->OnKeysChanged();
        //Destroying the overview window
        overview->Destroy();
    });
    //Showing the overview window
    overview->Show();
}

//The destructor for the KeyList class
KeyList::~KeyList() {
    //dtor
}

