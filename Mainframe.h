//
// Created by Tiziano Wu on 13/09/24.
//

#ifndef REGISTRO_ATTIVITA_MAINFRAME_H
#define REGISTRO_ATTIVITA_MAINFRAME_H
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/timectrl.h>
#include "Register.h"

class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString &title);
private:
    void CreateControls();
    void Setupsizers();
    void CreateShowListControls();
    void Setupfoundsizers();
    void BindEventHandlers();

    void AddButtonClicked(const wxCommandEvent& evt);
    void InputEnter(wxCommandEvent&evt);

    void addActivity();

    wxPanel* mainPanel;
    wxPanel* AddActivityPanel;
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
    wxListBox* begtimeList;
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
    wxStaticText* explainingtext;
    wxListBox* founddescriptionActList;
    wxListBox* foundbeginList;
    wxListBox* foundendList;
    wxListBox* founddayList;
    wxListBox* foundmonthList;
    wxListBox* foundyearList;

    vector<Activity>activities;
    vector<Activity>foundActivities;
    Register registro;
};


#endif //REGISTRO_ATTIVITA_MAINFRAME_H
