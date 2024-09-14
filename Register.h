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

    vector<Activity> comparedates(vector<Activity> activities,Data compareDay);
private:

    string registername;
    vector<Activity> temporaryVec;
};

#endif //REGISTRO_ATTIVITA_REGISTER_H
