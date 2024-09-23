//
// Created by Tiziano Wu on 15/09/24.
//
//
#include <gtest/gtest.h>
#include "../Day.h"

TEST(DataTest, CostruttoreDataValida) {
    // Test di una data valida
    Data d(15, 8, 2023);
    EXPECT_EQ(d.getGiorno(), 15);
    EXPECT_EQ(d.getMese(), 8);
    EXPECT_EQ(d.getAnno(), 2023);
}

TEST(DataTest, CostruttoreDataNonValida) {
    // Test di una data non valida (esempio: 31 aprile, mese di 30 giorni)
    EXPECT_THROW(Data(31, 4, 2023), std::invalid_argument);

    // Test di una data non valida (esempio: 29 febbraio in un anno non bisestile)
    EXPECT_THROW(Data(29, 2, 2021), std::invalid_argument);

    // Test di un mese non valido
    EXPECT_THROW(Data(10, 13, 2023), std::invalid_argument);

    // Test di un giorno non valido
    EXPECT_THROW(Data(0, 8, 2023), std::invalid_argument);

    // Test di un anno non valido
    EXPECT_THROW(Data(15, 8, -1), std::invalid_argument);
}

// Test per il metodo dataValida()
TEST(DataTest, TestDataValida) {
    Data d;
    EXPECT_TRUE(d.dataValida(29, 2, 2024));  // Anno bisestile, 29 febbraio è valido
    EXPECT_FALSE(d.dataValida(29, 2, 2023)); // Non bisestile, 29 febbraio non è valido
    EXPECT_TRUE(d.dataValida(31, 12, 2023)); // 31 dicembre è valido
    EXPECT_FALSE(d.dataValida(31, 4, 2023)); // 31 aprile non è valido (solo 30 giorni)
    EXPECT_FALSE(d.dataValida(0, 1, 2023));  // Giorno 0 non è valido
    EXPECT_FALSE(d.dataValida(15, 13, 2023)); // Mese non valido
}


TEST(DataTest, TestOperatorEqual) {
    Data d1(1,1,2024);
    Data d2(1, 1, 2024);
    Data d3(2, 1, 2024);

    EXPECT_TRUE(d1 == d2);  // Le due date dovrebbero essere uguali
    EXPECT_FALSE(d1 == d3); // Le due date non dovrebbero essere uguali
}

