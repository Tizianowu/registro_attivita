//
// Created by Tiziano Wu on 13/09/24.
//

#include "Mainframe.h"
MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title), registro("Registro generico") {
    CreateControls();
    CreateShowListControls();
    Setupsizers();
    Setupfoundsizers();
    BindEventHandlers();
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


void MainFrame::CreateShowListControls() {
    listPanel = new wxPanel(mainPanel);
    explainingtext = new wxStaticText(listPanel,wxID_ANY,"Activity Description                                                                     Activity Begin Time        Activity End Time        Activity day           Activity month          Activty year      ");
    BackButton = new wxButton(listPanel,wxID_ANY,"Back");
    founddescriptionActList = new wxListBox(listPanel, wxID_ANY);
    foundbeginList = new wxListBox(listPanel, wxID_ANY);
    foundendList = new wxListBox(listPanel, wxID_ANY);
    founddayList = new wxListBox(listPanel, wxID_ANY);
    foundmonthList = new wxListBox(listPanel, wxID_ANY);
    foundyearList = new wxListBox(listPanel,wxID_ANY);
    listPanel->Hide();
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
    mainSizer->Add(listPanel, 1, wxEXPAND | wxALL, 5);

    mainPanel->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);

    mainSizer->Layout();
}

void MainFrame::Setupfoundsizers() {
    wxBoxSizer* Sizer = new wxBoxSizer(wxVERTICAL);

    Sizer->Add(explainingtext);
    wxBoxSizer* subSizer = new wxBoxSizer(wxHORIZONTAL);
    subSizer->Add(founddescriptionActList,wxSizerFlags().Expand().Proportion(3));
    subSizer->AddSpacer(3);
    subSizer->Add(foundbeginList,wxSizerFlags().Expand().Proportion(1));
    subSizer->AddSpacer(3);
    subSizer->Add(foundendList,wxSizerFlags().Expand().Proportion(1));
    subSizer->AddSpacer(3);
    subSizer->Add(founddayList,wxSizerFlags().Expand().Proportion(1));
    subSizer->AddSpacer(3);
    subSizer->Add(foundmonthList,wxSizerFlags().Expand().Proportion(1));
    subSizer->AddSpacer(3);
    subSizer->Add(foundyearList,wxSizerFlags().Expand().Proportion(1));
    subSizer->AddSpacer(3);
    Sizer->Add(subSizer, wxSizerFlags().Expand().Proportion(1));
    Sizer->AddSpacer(25);
    Sizer->Add(BackButton);

    listPanel->SetSizer(Sizer);
}


void MainFrame::BindEventHandlers() {
    addButton->Bind(wxEVT_BUTTON, &MainFrame::AddButtonClicked, this);
    inputField->Bind(wxEVT_TEXT_ENTER, &MainFrame::InputEnter, this);
    desActivityList->Bind(wxEVT_KEY_DOWN,&MainFrame::OnListKeyDown,this);
    clearButton->Bind(wxEVT_BUTTON,&MainFrame::ClearButtonClicked,this);
}



void MainFrame::AddButtonClicked(const wxCommandEvent &evt) {
    addActivity();
}

void MainFrame::InputEnter(wxCommandEvent &evt) {
    addActivity();
}

void MainFrame::OnListKeyDown(wxKeyEvent &evt) {
    int keyCode = evt.GetKeyCode();
    int selectedIndex = desActivityList->GetSelection();

    if ((keyCode == WXK_DELETE || keyCode == WXK_BACK) && selectedIndex != wxNOT_FOUND) {
        deleteSelActivity();
    }
}

void MainFrame::ClearButtonClicked(const wxCommandEvent &evt) {
    if(desActivityList->IsEmpty())
        return;
    wxMessageDialog dialog(this,"are you sure you want to clear all?","clear",wxYES_NO | wxCANCEL);
    int result = dialog.ShowModal();
    if(result == wxID_YES){
        desActivityList->Clear();
        begtimeList->Clear();
        endTimeList->Clear();
        dayList->Clear();
        monthList->Clear();
        yearList->Clear();
        activities.clear();
    }
}



void MainFrame::addActivity() {
    wxString description = inputField->GetValue();
    std::string stdDescription = description.ToStdString();
    wxDateTime btime = beginTime->GetValue();
    wxDateTime etime = endTime->GetValue();
    int begtime = btime.GetHour() * 3600 + btime.GetMinute() * 60 + btime.GetSecond();
    int endtime = etime.GetHour() * 3600 + etime.GetMinute() * 60 + etime.GetSecond();

    int tempday = day->GetValue();
    int tempmonth = month->GetValue();
    int tempoyear = year->GetValue();
    Data date (tempday,tempmonth,tempoyear);
    if (date.dataValida(tempday,tempmonth,tempoyear)) {
        Activity activity(stdDescription, begtime, endtime, date);
        activities.push_back(activity);
        desActivityList->Insert(description, desActivityList->GetCount());
        int Bhours = btime.GetHour();
        int Bminutes = btime.GetMinute();
        int Bseconds = btime.GetSecond();
        wxString BtimeString = wxString::Format("%02d:%02d:%02d", Bhours, Bminutes, Bseconds);
        begtimeList->Insert(BtimeString, begtimeList->GetCount());
        int Ehours = etime.GetHour();    // Ottieni l'ora
        int Eminutes = etime.GetMinute(); // Ottieni i minuti
        int Eseconds = etime.GetSecond(); // Ottieni i secondi
        wxString EtimeString = wxString::Format("%02d:%02d:%02d", Ehours, Eminutes, Eseconds);
        endTimeList->Insert(EtimeString, endTimeList->GetCount());
        std::string dayStr = std::to_string(tempday);
        dayList->Insert(dayStr, dayList->GetCount());
        std::string monthStr = std::to_string(tempmonth);
        monthList->Insert(monthStr, monthList->GetCount());
        std::string yearStr = std::to_string(tempoyear);
        yearList->Insert(yearStr, yearList->GetCount());
        inputField->Clear();
        wxDateTime midnight(0,0,0);
        beginTime->SetValue(midnight);
        endTime->SetValue(midnight);
        day->SetValue(0);
        month->SetValue(0);
        year->SetValue(0);
        inputField->SetFocus();
    } else{
        wxMessageBox("data non valida");
    }
}

void MainFrame::deleteSelActivity() {
    int selectedIndex = desActivityList->GetSelection();
    if (selectedIndex == wxNOT_FOUND)
        return;
    {
        desActivityList->Delete(selectedIndex);
        begtimeList->Delete(selectedIndex);
        endTimeList->Delete(selectedIndex);
        dayList->Delete(selectedIndex);
        monthList->Delete(selectedIndex);
        yearList->Delete(selectedIndex);
    }
}
