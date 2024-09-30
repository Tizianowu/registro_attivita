//
// Created by Tiziano Wu on 13/09/24.
//

#include "Mainframe.h"
MainFrame::MainFrame(const wxString &title) : wxFrame(nullptr, wxID_ANY, title), registro("Registro generico") {
        CreateControls();
        CreateShowListControls();
    SetupSizers();
    SetupFoundSizers();
        BindEventHandlers();
    addFromSaved();
}

void MainFrame::CreateControls() {
    wxFont headlineFont(wxFontInfo(wxSize(0,36)).Bold());
    wxFont mainFont(wxFontInfo(wxSize(0,16)));

    mainPanel = new wxPanel(this);
    mainPanel->SetFont(mainFont);

    addActivityPanel = new wxPanel(mainPanel);
    addButton = new wxButton(addActivityPanel, wxID_ANY, "Add");
    headlineText = new wxStaticText(addActivityPanel, wxID_ANY, "LISTA ATTIVITA");
    headlineText->SetFont(headlineFont);
    infoText = new wxStaticText(addActivityPanel, wxID_ANY, "begintime  endtime   day    month    year                               ");
    inputField = new wxTextCtrl(addActivityPanel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER);
    clearButton = new wxButton(addActivityPanel, wxID_ANY, "Clear", wxDefaultPosition, wxDefaultSize);
    desActivityList = new wxListBox(addActivityPanel, wxID_ANY);
    begTimeList = new wxListBox(addActivityPanel, wxID_ANY);
    endTimeList = new wxListBox(addActivityPanel, wxID_ANY);
    dayList = new wxListBox(addActivityPanel, wxID_ANY);
    monthList = new wxListBox(addActivityPanel, wxID_ANY);
    yearList = new wxListBox(addActivityPanel, wxID_ANY);
    wxDateTime midnight(0,0,0);
    beginTime = new wxTimePickerCtrl(addActivityPanel, wxID_ANY, midnight, wxDefaultPosition, wxDefaultSize);
    endTime= new wxTimePickerCtrl(addActivityPanel, wxID_ANY, midnight, wxDefaultPosition, wxDefaultSize);
    day = new wxSpinCtrl(addActivityPanel, wxID_ANY, "0000", wxDefaultPosition, wxDefaultSize, wxSP_WRAP, 0, 31);
    month = new wxSpinCtrl(addActivityPanel, wxID_ANY, "0000", wxDefaultPosition, wxDefaultSize, wxSP_WRAP, 0, 12);
    year = new wxSpinCtrl(addActivityPanel, wxID_ANY, "0000", wxDefaultPosition, wxDefaultSize, wxSP_WRAP, 0, 2025);

    findDay = new wxSpinCtrl(addActivityPanel, wxID_ANY, "0000", wxDefaultPosition, wxDefaultSize, wxSP_WRAP, 0, 31);
    findMonth = new wxSpinCtrl(addActivityPanel, wxID_ANY, "0000", wxDefaultPosition, wxDefaultSize, wxSP_WRAP, 0, 12);
    findYear = new wxSpinCtrl(addActivityPanel, wxID_ANY, "0000", wxDefaultPosition, wxDefaultSize, wxSP_WRAP, 0, 2025);
    find = new wxButton(addActivityPanel, wxID_ANY, "Find", wxDefaultPosition, wxDefaultSize);
}


void MainFrame::CreateShowListControls() {
    listPanel = new wxPanel(mainPanel);
    explainingText = new wxStaticText(listPanel, wxID_ANY, "Activity Description                                                                     Activity Begin Time        Activity End Time        Activity day           Activity month          Activty year      ");
    BackButton = new wxButton(listPanel,wxID_ANY,"Back");
    foundDescriptionActList = new wxListBox(listPanel, wxID_ANY);
    foundBeginList = new wxListBox(listPanel, wxID_ANY);
    foundEndList = new wxListBox(listPanel, wxID_ANY);
    foundDayList = new wxListBox(listPanel, wxID_ANY);
    foundMonthList = new wxListBox(listPanel, wxID_ANY);
    foundYearList = new wxListBox(listPanel, wxID_ANY);
    listPanel->Hide();
}


void MainFrame::SetupSizers() {
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
    subsubsubSizer->Add(begTimeList, wxSizerFlags().Expand().Proportion(1));
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

    addActivityPanel->SetSizer(Sizer);

    mainSizer->Add(addActivityPanel, 1, wxEXPAND | wxALL, 5);
    mainSizer->Add(listPanel, 1, wxEXPAND | wxALL, 5);

    mainPanel->SetSizer(mainSizer);
    mainSizer->SetSizeHints(this);

    mainSizer->Layout();
}

void MainFrame::SetupFoundSizers() {
    wxBoxSizer* Sizer = new wxBoxSizer(wxVERTICAL);

    Sizer->Add(explainingText);
    wxBoxSizer* subSizer = new wxBoxSizer(wxHORIZONTAL);
    subSizer->Add(foundDescriptionActList, wxSizerFlags().Expand().Proportion(3));
    subSizer->AddSpacer(3);
    subSizer->Add(foundBeginList, wxSizerFlags().Expand().Proportion(1));
    subSizer->AddSpacer(3);
    subSizer->Add(foundEndList, wxSizerFlags().Expand().Proportion(1));
    subSizer->AddSpacer(3);
    subSizer->Add(foundDayList, wxSizerFlags().Expand().Proportion(1));
    subSizer->AddSpacer(3);
    subSizer->Add(foundMonthList, wxSizerFlags().Expand().Proportion(1));
    subSizer->AddSpacer(3);
    subSizer->Add(foundYearList, wxSizerFlags().Expand().Proportion(1));
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
    find->Bind(wxEVT_BUTTON,&MainFrame::FindActivities,this);
    BackButton->Bind(wxEVT_BUTTON,&MainFrame::BackButtonClicked,this);
    this->Bind(wxEVT_CLOSE_WINDOW,&MainFrame::WindowClosed,this);
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
        begTimeList->Clear();
        endTimeList->Clear();
        dayList->Clear();
        monthList->Clear();
        yearList->Clear();
        registro.clearActivities();
    }
}

void MainFrame::FindActivities(wxCommandEvent &evt) {
    int day = findDay->GetValue();
    int month = findMonth->GetValue();
    int year = findYear->GetValue();
    try{
    Data tempday(day,month,year);
    if(tempday.dataValida(day,month,year)) {
        foundActivities = registro.searchByDate(tempday);
        if (!foundActivities.empty()) {
            for (const auto &act: foundActivities) {
                foundDescriptionActList->Append(act.getDescription());
                int beginTime = act.getBegin();
                int endTime = act.getAnEnd();
                wxString formattedBegin = secondsToHMS(beginTime);
                wxString formattedEnd = secondsToHMS(endTime);
                foundBeginList->Append(formattedBegin);
                foundEndList->Append(formattedEnd);
                foundDayList->Append(std::to_string(act.getDay().getGiorno()));
                foundMonthList->Append(std::to_string(act.getDay().getMese()));
                foundYearList->Append(std::to_string(act.getDay().getAnno()));
            }
            addActivityPanel->Hide();
            listPanel->Show();
            mainPanel->Layout();
        } else {
            wxMessageBox("non attività presenti con questa data");
        }
    }
    }catch (const std::invalid_argument& e) {
        wxMessageBox(wxString::Format("Errore durante l'inizializzazione: %s", e.what()));
    }
    catch (...) {
        wxMessageBox("Errore sconosciuto durante l'inizializzazione.");
    }

}

void MainFrame::BackButtonClicked(wxCommandEvent &evt) {
    foundDescriptionActList->Clear();
    foundBeginList->Clear();
    foundEndList->Clear();
    foundDayList->Clear();
    foundMonthList->Clear();
    foundYearList->Clear();
    foundActivities.clear();
    listPanel->Hide();
    addActivityPanel->Show();
    mainPanel->Layout();
}

void MainFrame::WindowClosed(wxCloseEvent &evt) {
    std::vector<Activity> activities;

    int count = desActivityList->GetCount();
    for (int i = 0; i < count; i++) {
        // Extract data from each list at index i
        wxString description = desActivityList->GetString(i);
        std::string begtimeStr = begTimeList->GetString(i).ToStdString();
        std::string endtimeStr = endTimeList->GetString(i).ToStdString();

        // Parsing the hh:mm:ss format for begin time
        int beginHours = std::stoi(begtimeStr.substr(0, 2));
        int beginMinutes = std::stoi(begtimeStr.substr(3, 2));
        int beginSeconds = std::stoi(begtimeStr.substr(6, 2));

        // Convert hh:mm:ss into total seconds for begin time
        int begin = (beginHours * 3600) + (beginMinutes * 60) + beginSeconds;

        // Parsing the hh:mm:ss format for end time
        int endHours = std::stoi(endtimeStr.substr(0, 2));
        int endMinutes = std::stoi(endtimeStr.substr(3, 2));
        int endSeconds = std::stoi(endtimeStr.substr(6, 2));

        // Convert hh:mm:ss into total seconds for end time
        int end = (endHours * 3600) + (endMinutes * 60) + endSeconds;
        int day = std::stoi(dayList->GetString(i).ToStdString());
        int month = std::stoi(monthList->GetString(i).ToStdString());
        int year = std::stoi(yearList->GetString(i).ToStdString());

        std::string stdDescription = std::string(description.mb_str());
        std::replace(stdDescription.begin(), stdDescription.end(), '_', ' ');

        Data activity_day(day, month, year);
        Activity activity(stdDescription, begin, end, activity_day);

        activities.push_back(activity);
    }
    saveFile(activities, "activities.txt");
    evt.Skip();
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
    try{
    Data date (tempday,tempmonth,tempoyear);
        if (date.dataValida(tempday, tempmonth, tempoyear)) {
            Activity activity(stdDescription, begtime, endtime, date);
            registro.addActivity(activity);
            desActivityList->Insert(description, desActivityList->GetCount());
            int Bhours = btime.GetHour();
            int Bminutes = btime.GetMinute();
            int Bseconds = btime.GetSecond();
            wxString BtimeString = wxString::Format("%02d:%02d:%02d", Bhours, Bminutes, Bseconds);
            begTimeList->Insert(BtimeString, begTimeList->GetCount());
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
            wxDateTime midnight(0, 0, 0);
            beginTime->SetValue(midnight);
            endTime->SetValue(midnight);
            day->SetValue(0);
            month->SetValue(0);
            year->SetValue(0);
            inputField->SetFocus();
        }
        }catch (const std::invalid_argument& e) {
            wxMessageBox(wxString::Format("Errore durante l'inizializzazione: %s", e.what()));
        }
        catch (...) {
            wxMessageBox("Errore sconosciuto durante l'inizializzazione.");
        }
}

void MainFrame::deleteSelActivity() {
    int selectedIndex = desActivityList->GetSelection();
    if (selectedIndex == wxNOT_FOUND)
        return;
    else{
        int day = wxAtoi(dayList->GetString(selectedIndex));
        int month = wxAtoi(monthList->GetString(selectedIndex));
        int year = wxAtoi(yearList->GetString(selectedIndex));
        Data dat(day, month, year);

        // Estrarre l'orario di inizio (hh:mm:ss) e convertirlo in secondi
        wxString btimeString = begTimeList->GetString(selectedIndex);
        long Bhours, Bminutes, Bseconds;
        btimeString.BeforeFirst(':').ToLong(&Bhours);
        btimeString.AfterFirst(':').BeforeFirst(':').ToLong(&Bminutes);
        btimeString.AfterLast(':').ToLong(&Bseconds);

        // Convertire l'orario di inizio in secondi
        int begintimeInSeconds = (Bhours * 3600) + (Bminutes * 60) + Bseconds;

        wxString etimeString = endTimeList->GetString(selectedIndex);
        long Ehours, Eminutes, Eseconds;
        etimeString.BeforeFirst(':').ToLong(&Ehours);
        etimeString.AfterFirst(':').BeforeFirst(':').ToLong(&Eminutes);
        etimeString.AfterLast(':').ToLong(&Eseconds);

        int endtimeInSeconds = (Ehours * 3600) + (Eminutes * 60) + Eseconds;
        Activity act(desActivityList->GetString(selectedIndex).ToStdString(), begintimeInSeconds,endtimeInSeconds,dat);
        desActivityList->Delete(selectedIndex);
        begTimeList->Delete(selectedIndex);
        endTimeList->Delete(selectedIndex);
        dayList->Delete(selectedIndex);
        monthList->Delete(selectedIndex);
        yearList->Delete(selectedIndex);
        registro.deleteSelectedActivity(act);
    }
}


void MainFrame::addFromSaved() {
    vector<Activity>tempVec = loadFile("activities.txt");
    for(const auto act : tempVec) {
        registro.addActivity(act);
    }
    std::vector<Activity>tasks = loadFile("activities.txt");
    for (const Activity& task : tasks) {
        int index = desActivityList->GetCount();
        desActivityList->Insert(task.getDescription(), index);
        int beginTimestamp = task.getBegin();  // task.getBegin() restituisce un intero (es: secondi)
        int Bhours = beginTimestamp / 3600;
        int Bminutes = (beginTimestamp % 3600) / 60;
        int Bseconds = beginTimestamp % 60;
        wxString beginTimeWx = wxString::Format("%02d:%02d:%02d", Bhours, Bminutes, Bseconds);
        begTimeList->Insert(beginTimeWx, index);// task.getBegin() restituisce un intero (es: secondi)
        int endTimestamp = task.getAnEnd();
        int Ehours = endTimestamp / 3600;
        int Eminutes = (endTimestamp % 3600) / 60;
        int Eseconds = endTimestamp % 60;
        wxString endTimeWx = wxString::Format("%02d:%02d:%02d", Ehours, Eminutes, Eseconds);
        endTimeList->Insert(endTimeWx,index);
        std::string dayStr = std::to_string(task.getDay().getGiorno());
        dayList->Insert(dayStr,index);
        std::string monthStr = std::to_string(task.getDay().getMese());
        monthList->Insert(monthStr,index);
        std::string yearStr = std::to_string(task.getDay().getAnno());
        yearList->Insert(yearStr,index);
    }
}

void MainFrame::saveFile(const std::vector<Activity> &lists, const std::string &filename) {
    std::ofstream ostream(filename);
    ostream << lists.size();
    for (const Activity& activity : lists) {
        std::string description = activity.getDescription();
        std::replace(description.begin(), description.end(), ' ', '_');
        ostream << '\n' << description << ' ' << activity.getBegin() << ' ' << activity.getAnEnd() << ' ' << activity.getDay().getGiorno() << ' ' << activity.getDay().getMese() << ' ' << activity.getDay().getAnno();
    }
}

std::vector<Activity> MainFrame::loadFile(const std::string &filename) {
    if (!std::filesystem::exists(filename)) {
        return std::vector<Activity>();
    }
    std::vector<Activity> activities;
    std::ifstream istream(filename);
    int n;
    istream >> n;
    for (int i = 0; i < n; i++) {
        std::string description;
        int begin, end;
        int day, month, year;
        // Read the fields from the file
        istream >> description >> begin >> end >> day >> month >> year;
        std::replace(description.begin(), description.end(), '_', ' ');
        Data activity_day(day, month, year);
        activities.emplace_back(description, begin, end, activity_day);
    }
    return activities;
}

