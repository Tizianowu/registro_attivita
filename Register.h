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

    void addActivity(Activity act){
        activities.push_back(act);
    }
    void deleteSelectedActivity(Activity act){
        auto it = std::find(activities.begin(), activities.end(), act);
        if (it != activities.end()) {
            activities.erase(it);
        }
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
