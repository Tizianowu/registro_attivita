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

    vector<Activity> searchByDate(const Data &compareDay);

    void deleteSelectedActivity(const Activity& act);

    int sizeOfRegister() const;

    bool findActivity(const Activity &act) const;


    void addActivity(const Activity& act) {
        activities.push_back(act);
    }

    void clearActivities() {
        activities.clear();
    };
private:

    vector<Activity> activities;
    string registerName;
};

#endif //REGISTRO_ATTIVITA_REGISTER_H
