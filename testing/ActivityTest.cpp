//
// Created by Tiziano Wu on 15/09/24.
//
#include <gtest/gtest.h>
#include "../Activity.h"
TEST(ActivityTest, ConstructorAndGetters) {
    Data date(15, 8, 2024);
    Activity activity("Test Activity", 1200, 1300, date);

    EXPECT_EQ(activity.getDescription(), "Test Activity");
    EXPECT_EQ(activity.getBegin(), 1200);
    EXPECT_EQ(activity.getAnEnd(), 1300);
    EXPECT_EQ(activity.getDay().getGiorno(), 15);
    EXPECT_EQ(activity.getDay().getMese(), 8);
    EXPECT_EQ(activity.getDay().getAnno(), 2024);
}

// Test per la validità dei dati
TEST(ActivityTest, CheckDataValidity) {
    Data validDate(15, 8, 2024);
    Data invalidDate(31, 2, 2024);  // Febbraio 31 non è valido

    EXPECT_TRUE(validDate.dataValida(15, 8, 2024));
}
