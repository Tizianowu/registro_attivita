//
// Created by Tiziano Wu on 13/09/24.
//

#ifndef REGISTRO_ATTIVITA_ACTIVITY_H
#define REGISTRO_ATTIVITA_ACTIVITY_H


#include <string>
#include "Day.h"

using namespace std;

class Activity {
public:
    Activity(string description, int begintime, int endtime, Data act_day);

    const Data &getDay() const;
    const string &getDescription() const;
    int getBegin() const;
    int getAnEnd() const;

    bool operator==(const Activity& other) const {
        return description == other.description &&
               begin == other.begin &&
               end == other.end &&
               day == other.day; // Assumendo che Data abbia operator== implementato
    }

private:
    string description;
    int begin;
    int end;
    Data day;
};

#endif //REGISTRO_ATTIVITA_ACTIVITY_H
