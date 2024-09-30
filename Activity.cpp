//
// Created by Tiziano Wu on 13/09/24.
//

#include "Activity.h"
Activity::Activity(const std::string& description, int beginTime, int endTime, Data actDay): description(description), day(actDay) {
    if(beginTime < endTime){
        begin=beginTime;
        end=endTime;
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
