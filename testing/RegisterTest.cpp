//
// Created by Tiziano Wu on 15/09/24.
//
#include <gtest/gtest.h>
#include "../Register.h"

class RegisterTest : public ::testing::Test {
protected:
    RegisterTest() : reg("Test Register") {}

    Register reg;
};
// Test per verificare che comparedates trovi i giorni corrispondenti
TEST_F(RegisterTest, ComparedatesFindsMatchingDays) {
    Data day1(1, 1, 2024);
    Data day2(2, 1, 2024);
    Data day3(3, 1, 2024);

    std::vector<Activity> activities = {
            Activity("Event1", 800, 1000, day1),
            Activity("Event2", 1100, 1300, day2),
            Activity("Event3", 1400, 1600, day1),
            Activity("Event4", 1700, 1900, day3)
    };
    std::vector<Activity> result = reg.comparedates(activities, day1);

    ASSERT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].getDay(), day1);
    EXPECT_EQ(result[1].getDay(), day1);
}

// Test per verificare che comparedates non trovi giorni non corrispondenti
TEST_F(RegisterTest, ComparedatesFindsNoMatchingDays) {
    Data day1(1, 1, 2024);
    Data day2(2, 1, 2024);

    std::vector<Activity> activities = {
            Activity("Event1", 800, 1000, day2),
            Activity("Event2", 1100, 1300, day2),
            Activity("Event3", 1400, 1600, day2)
    };

    std::vector<Activity> result = reg.comparedates(activities, day1);
    ASSERT_TRUE(result.empty());
}
