//
// Created by Tiziano Wu on 13/09/24.
//

#include "Mainframe.h"
MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title) {
    CreateControls();
    Setupsizers();
}

void MainFrame::CreateControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0,36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0,16)));

    mainPanel = new wxPanel(this);
    mainPanel->SetFont(mainFont);

    AddActivityPanel = new wxPanel(mainPanel);
    addButton = new wxButton(AddActivityPanel,wxID_ANY,"Add");
    headlineText = new wxStaticText(AddActivityPanel,wxID_ANY,"LISTA ATTIVITA");
    headlineText->SetFont(headlineFont);
    infoText = new wxStaticText(AddActivityPanel,wxID_ANY,"begintime  endtime   day    month    year                               ");
    inputField = new wxTextCtrl(AddActivityPanel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize,wxTE_PROCESS_ENTER);
    clearButton = new wxButton(AddActivityPanel, wxID_ANY, "Clear", wxDefaultPosition, wxDefaultSize);
    desActivityList = new wxListBox(AddActivityPanel, wxID_ANY);
    begtimeList = new wxListBox(AddActivityPanel, wxID_ANY);
    endTimeList = new wxListBox(AddActivityPanel, wxID_ANY);
    dayList = new wxListBox(AddActivityPanel, wxID_ANY);
    monthList = new wxListBox(AddActivityPanel, wxID_ANY);
    yearList = new wxListBox(AddActivityPanel,wxID_ANY);
    wxDateTime midnight(0,0,0);
    beginTime = new wxTimePickerCtrl(AddActivityPanel,wxID_ANY,midnight,wxDefaultPosition,wxDefaultSize);
    endTime= new wxTimePickerCtrl(AddActivityPanel,wxID_ANY,midnight,wxDefaultPosition,wxDefaultSize);
    day = new wxSpinCtrl(AddActivityPanel,wxID_ANY,"0000",wxDefaultPosition,wxDefaultSize,wxSP_WRAP,0,31);
    month = new wxSpinCtrl(AddActivityPanel,wxID_ANY,"0000",wxDefaultPosition,wxDefaultSize,wxSP_WRAP,0,12);
    year = new wxSpinCtrl(AddActivityPanel,wxID_ANY,"0000",wxDefaultPosition,wxDefaultSize,wxSP_WRAP,0,2025);

    findDay = new wxSpinCtrl(AddActivityPanel,wxID_ANY,"0000",wxDefaultPosition,wxDefaultSize,wxSP_WRAP,0,31);
    findMonth = new wxSpinCtrl(AddActivityPanel,wxID_ANY,"0000",wxDefaultPosition,wxDefaultSize,wxSP_WRAP,0,12);
    findYear = new wxSpinCtrl(AddActivityPanel,wxID_ANY,"0000",wxDefaultPosition,wxDefaultSize,wxSP_WRAP,0,2025);
    find = new wxButton(AddActivityPanel,wxID_ANY,"Find",wxDefaultPosition,wxDefaultSize);
}

void MainFrame::Setupsizers() {
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer* Sizer = new wxBoxSizer(wxVERTICAL);
    Sizer->Add(headlineText, wxSizerFlags().CenterHorizontal());
    Sizer->AddSpacer(25);
    Sizer->Add(infoText, wxSizerFlags().Right());

    wxBoxSizer* subSizer = new wxBoxSizer(wxHORIZONTAL);
    subSizer->Add(inputField,wxSizerFlags().Proportion(1));
    subSizer->Add(beginTime);
    subSizer->AddSpacer(5);
    subSizer->Add(endTime);
    subSizer->AddSpacer(5);
    subSizer->Add(day);
    subSizer->AddSpacer(5);
    subSizer->Add(month);
    subSizer->AddSpacer(5);
    subSizer->Add(year);
    subSizer->Add(addButton);
    subSizer->AddSpacer(5);
    Sizer->Add(subSizer, wxSizerFlags().Expand());
    subSizer->AddSpacer(5);

    wxBoxSizer* subsubsubSizer = new wxBoxSizer(wxHORIZONTAL);
    subsubsubSizer->Add(desActivityList,wxSizerFlags().Expand().Proportion(5));
    subsubsubSizer->AddSpacer(3);
    subsubsubSizer->Add(begtimeList,wxSizerFlags().Expand().Proportion(1));
    subsubsubSizer->AddSpacer(3);
    subsubsubSizer->Add(endTimeList,wxSizerFlags().Expand().Proportion(1));
    subsubsubSizer->AddSpacer(3);
    subsubsubSizer->Add(dayList,wxSizerFlags().Expand().Proportion(1));
    subsubsubSizer->AddSpacer(3);
    subsubsubSizer->Add(monthList,wxSizerFlags().Expand().Proportion(1));
    subsubsubSizer->AddSpacer(3);
    subsubsubSizer->Add(yearList,wxSizerFlags().Expand().Proportion(1));
    subsubsubSizer->AddSpacer(3);
    Sizer->Add(subsubsubSizer, wxSizerFlags().Expand().Proportion(1));
    Sizer->Add(clearButton);
    Sizer->AddSpacer(25);

    wxBoxSizer* subsubSizer = new wxBoxSizer(wxHORIZONTAL);
    subsubSizer->Add(findDay);
    subsubSizer->AddSpacer(5);
    subsubSizer->Add(findMonth);
    subsubSizer->AddSpacer(5);
    subsubSizer->Add(findYear);
    subsubSizer->Add(find);
    Sizer->Add(subsubSizer, wxSizerFlags().Expand());

    wxGridSizer* outSizer = new wxGridSizer(1);
    outSizer->Add(Sizer, wxSizerFlags().Border(wxALL, 25).Expand());

    AddActivityPanel->SetSizer(Sizer);

    mainSizer->Add(AddActivityPanel, 1, wxEXPAND | wxALL, 5);

    mainPanel->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);

    mainSizer->Layout();
}