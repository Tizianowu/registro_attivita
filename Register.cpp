//
// Created by Tiziano Wu on 13/09/24.
//

#include "Register.h"

Register::Register(const std::string &title):registername(title) {
}

vector<Activity> Register::comparedates(const Data& compareDay) {
    temporaryVec.clear();
    for (const auto act : activities)
        if(act.getDay()==compareDay)
            temporaryVec.push_back(act);
    return temporaryVec;
}
