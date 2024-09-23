//
// Created by Tiziano Wu on 13/09/24.
//
#ifndef REGISTRO_GIORNO_DAY_H
#define REGISTRO_GIORNO_DAY_H
#include <iostream>

class Data {
public:
    Data() : day(1), month(1), year(1970) {};
    Data(int giorno, int mese, int anno) {
        if (dataValida(giorno, mese, anno)) {
            this->day = giorno;
            this->month = mese;
            this->year = anno;
        } else {
            throw std::invalid_argument("Errore: data non valida!");
        }
    }
    bool dataValida(int giorno, int mese, int anno) const;

    int getGiorno() const {
        return day;
    }
    int getMese() const {
        return month;
    }
    int getAnno() const {
        return year;
    }
    bool operator==(const Data& altraData) const;
private:
    int giorniNelMese(int mese, int anno) const;
    bool isBisestile(int anno) const {
        return ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0));
    }
    int day;
    int month;
    int year;
};


#endif //REGISTRO_GIORNO_DAY_H