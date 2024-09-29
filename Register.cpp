//
// Created by Tiziano Wu on 13/09/24.
//

#include "Register.h"

Register::Register(const std::string &title): registerName(title) {
}

vector<Activity> Register::compareDates(const Data& compareDay) {
    temporaryVec.clear();
    for (const auto act : activities)
        if(act.getDay()==compareDay)
            temporaryVec.push_back(act);
    return temporaryVec;
}

void Register::deleteSelectedActivity(Activity act) {
        auto it = std::find(activities.begin(), activities.end(), act);
        if (it != activities.end()) {
            activities.erase(it);
        }
}

bool Register::findActivity(Activity act) {
    bool found=false;
    for(const auto activ:activities)
        if(activ==act)
            found=true;
    return found;
}

int Register::sizeOfRegister() {
    return activities.size();
}