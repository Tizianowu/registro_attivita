//
// Created by Tiziano Wu on 13/09/24.
//
#ifndef REGISTRO_GIORNO_DAY_H
#define REGISTRO_GIORNO_DAY_H
#include <iostream>

class Data {
private:
    int day;
    int month;
    int year;
public:
    Data() : day(1), month(1), year(1970) {};
    Data(int giorno, int mese, int anno) {
        if (dataValida(giorno, mese, anno)) {
            this->day = giorno;
            this->month = mese;
            this->year = anno;
        } else {
            std::cerr << "Errore: data non valida!" << std::endl;
        }
    }

    bool isBisestile(int anno) const {
        return ((anno % 4 == 0 && anno % 100 != 0) || (anno % 400 == 0));}
    int giorniNelMese(int mese, int anno) const;
    bool dataValida(int giorno, int mese, int anno) const;
    bool operator==(const Data& altraData) const;

    int getGiorno() const {
        return day;
    }
    int getMese() const {
        return month;
    }
    int getAnno() const {
        return year;
    }
};

#endif //REGISTRO_GIORNO_DAY_H