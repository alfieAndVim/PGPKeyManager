#include <NewKeyForm.h>

NewKeyForm::NewKeyForm() : wxDialog(NULL, wxID_ANY, "New Key", wxPoint(30,30), wxSize(800,600))
{

    wxScrolledWindow *scrolledWindow = new wxScrolledWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxVSCROLL);
    
    scrolledWindow->SetScrollRate(5, 5);

    wxBoxSizer *scrollSizer = new wxBoxSizer(wxVERTICAL);
    

    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);

    wxStaticText *label1 = new wxStaticText(scrolledWindow, wxID_ANY, "Name");
    wxTextCtrl *text1 = new wxTextCtrl(scrolledWindow, wxID_ANY, "Name");
    wxStaticText *label2 = new wxStaticText(scrolledWindow, wxID_ANY, "Email");
    wxTextCtrl *text2 = new wxTextCtrl(scrolledWindow, wxID_ANY, "Email");
    wxStaticText *label3 = new wxStaticText(scrolledWindow, wxID_ANY, "Comment");
    wxTextCtrl *text3 = new wxTextCtrl(scrolledWindow, wxID_ANY, "Comment");
    wxStaticText *label4 = new wxStaticText(scrolledWindow, wxID_ANY, "Key Type");
    wxChoice *choice1 = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    wxStaticText *label5 = new wxStaticText(scrolledWindow, wxID_ANY, "Key Length");
    wxChoice *choice2 = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    wxStaticText *label6 = new wxStaticText(scrolledWindow, wxID_ANY, "Key Expiration");
    wxChoice *choice3 = new wxChoice(scrolledWindow, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0);
    wxStaticText *label7 = new wxStaticText(scrolledWindow, wxID_ANY, "Passphrase");
    wxTextCtrl *text4 = new wxTextCtrl(scrolledWindow, wxID_ANY, "Passphrase");
    wxStaticText *label8 = new wxStaticText(scrolledWindow, wxID_ANY, "Confirm Passphrase");
    wxTextCtrl *text5 = new wxTextCtrl(scrolledWindow, wxID_ANY, "Confirm Passphrase");

    wxButton *button1 = new wxButton(scrolledWindow, wxID_ANY, "Generate");
    wxButton *button2 = new wxButton(scrolledWindow, wxID_ANY, "Cancel");

    sizer->Add(label1, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(text1, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(label2, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(text2, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(label3, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(text3, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(label4, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(choice1, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(label5, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(choice2, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(label6, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(choice3, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(label7, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(text4, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(label8, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(text5, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(button1, wxSizerFlags(1).Expand().Border(wxALL, 5));
    sizer->Add(button2, wxSizerFlags(1).Expand().Border(wxALL, 5));

    scrolledWindow->SetSizer(sizer);
    scrollSizer->Add(scrolledWindow, 1, wxEXPAND);
    SetSizer(scrollSizer);

    //ctor
}

NewKeyForm::~NewKeyForm()
{
    //dtor
}