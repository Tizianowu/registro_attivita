//
// Created by Tiziano Wu on 13/09/24.
//

#ifndef REGISTRO_ATTIVITA_MAINFRAME_H
#define REGISTRO_ATTIVITA_MAINFRAME_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/timectrl.h>
#include <filesystem>
#include <fstream>
#include "Register.h"

class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString &title);
private:
    void CreateControls();
    void SetupSizers();
    void CreateShowListControls();
    void SetupFoundSizers();
    void BindEventHandlers();

    void AddButtonClicked(const wxCommandEvent& evt);
    void InputEnter(wxCommandEvent&evt);
    void OnListKeyDown(wxKeyEvent &evt);
    void ClearButtonClicked(const wxCommandEvent& evt);
    void WindowClosed(wxCloseEvent& evt);
    void FindActivities(wxCommandEvent& evt);
    void BackButtonClicked(wxCommandEvent& evt);

    void saveFile(const std::vector<Activity> &lists, const std::string &filename);
    std::vector<Activity>loadFile(const std::string &filename);
    void addFromSaved();


    void addActivity();
    void deleteSelActivity();

    wxPanel* mainPanel;
    wxPanel* addActivityPanel;
    wxButton* addButton;
    wxStaticText* headlineText;
    wxStaticText* infoText;
    wxTextCtrl* inputField;
    wxTimePickerCtrl* beginTime;
    wxTimePickerCtrl*  endTime;
    wxSpinCtrl*  day;
    wxSpinCtrl*  month;
    wxSpinCtrl*  year;
    wxButton* clearButton;
    wxListBox* desActivityList;
    wxListBox* begTimeList;
    wxListBox* endTimeList;
    wxListBox* dayList;
    wxListBox* monthList;
    wxListBox* yearList;
    wxButton* find;
    wxSpinCtrl*  findDay;
    wxSpinCtrl*  findMonth;
    wxSpinCtrl*  findYear;

    wxPanel* listPanel;
    wxButton* BackButton;
    wxStaticText* explainingText;
    wxListBox* foundDescriptionActList;
    wxListBox* foundBeginList;
    wxListBox* foundEndList;
    wxListBox* foundDayList;
    wxListBox* foundMonthList;
    wxListBox* foundYearList;

    vector<Activity>activities;
    vector<Activity>foundActivities;
    Register registro;

    wxString secondsToHMS(int seconds) {
        int hours = seconds / 3600;
        int minutes = (seconds % 3600) / 60;
        int secs = seconds % 60;

        // Usa wxString::Format per formattare in hh:mm:ss
        return wxString::Format("%02d:%02d:%02d", hours, minutes, secs);
    }
};


#endif //REGISTRO_ATTIVITA_MAINFRAME_H
