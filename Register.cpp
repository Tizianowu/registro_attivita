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
