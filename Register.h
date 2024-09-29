//
// Created by Tiziano Wu on 13/09/24.
//

#ifndef REGISTRO_ATTIVITA_REGISTER_H
#define REGISTRO_ATTIVITA_REGISTER_H
#include <vector>
#include "Activity.h"

class Register {
public:
    Register(const string &title);

    vector<Activity> compareDates(const Data& compareDay);
    void deleteSelectedActivity(Activity act);
    int sizeOfRegister();
    bool findActivity(Activity act);


    void addActivity(Activity act){
        activities.push_back(act);
    }
    void clearActivities(){
        activities.clear();
    };
private:

    vector<Activity> activities;
    string registerName;
    vector<Activity> temporaryVec;
};

#endif //REGISTRO_ATTIVITA_REGISTER_H
