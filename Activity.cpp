//
// Created by Tiziano Wu on 13/09/24.
//

#include "Activity.h"
Activity::Activity(std::string description, int begintime, int endtime,Data act_day): description(description),day(act_day) {
    if(begintime<endtime){
        begin=begintime;
        end=endtime;
    }
    else{
        throw std::invalid_argument("Errore: l'orario di inizio deve essere inferiore all'orario di fine.");
    }
}

const Data &Activity::getDay() const {
    return day;
}

const string &Activity::getDescription() const {
    return description;
}

int Activity::getBegin() const {
    return begin;
}

int Activity::getAnEnd() const {
    return end;
}
