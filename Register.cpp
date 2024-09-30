//
// Created by Tiziano Wu on 13/09/24.
//

#include "Register.h"

Register::Register(const std::string &title): registerName(title) {
}

vector<Activity> Register::searchByDate(const Data& compareDay) {
    vector<Activity> temporaryVec;
    temporaryVec.clear();
    for (const auto act : activities)
        if(act.getDay()==compareDay)
            temporaryVec.push_back(act);
    return temporaryVec;
}

void Register::deleteSelectedActivity(const Activity& act) {
        auto it = std::find(activities.begin(), activities.end(), act);
        if (it != activities.end()) {
            activities.erase(it);
        }
}

bool Register::findActivity(const Activity& act)const {
    bool found=false;
    for(const auto activ:activities)
        if(activ==act)
            found=true;
    return found;
}

int Register::sizeOfRegister()const {
    return activities.size();
}