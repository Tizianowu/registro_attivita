//
// Created by Tiziano Wu on 13/09/24.
//

#include "Day.h"
int Data::giorniNelMese(int mese, int anno) const {
    // Array dei giorni per ciascun mese (0-esimo indice inutilizzato per semplicità)
    int giorniPerMese[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mese == 2 && isBisestile(anno)) {
        return 29;
    }
    if (mese >= 1 && mese <= 12) {
        return giorniPerMese[mese - 1];
    }
    return 0;
}

bool Data::dataValida(int giorno, int mese, int anno) const{
    if (anno < 1 || mese < 1 || mese > 12) {
        return false;
    }
    int maxGiorni = giorniNelMese(mese, anno);
    return (giorno >= 1 && giorno <= maxGiorni);
}

bool Data::operator==(const Data &altraData) const {
    return (day == altraData.day &&
            month == altraData.month &&
            year == altraData.year);
}

