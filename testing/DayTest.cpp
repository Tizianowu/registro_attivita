//
// Created by Tiziano Wu on 15/09/24.
//
//
#include <gtest/gtest.h>
#include "../Day.cpp"
TEST(DataTest, TestGiorniNelMese) {
    Data d;
    EXPECT_EQ(d.giorniNelMese(1, 2024), 31);  // Gennaio ha 31 giorni
    EXPECT_EQ(d.giorniNelMese(2, 2024), 29);  // Anno bisestile, febbraio ha 29 giorni
    EXPECT_EQ(d.giorniNelMese(2, 2023), 28);  // Non bisestile, febbraio ha 28 giorni
    EXPECT_EQ(d.giorniNelMese(4, 2023), 30);  // Aprile ha 30 giorni
    EXPECT_EQ(d.giorniNelMese(13, 2023), 0);  // Mese non valido, restituisce 0
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

