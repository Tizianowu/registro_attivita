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

TEST(ActivityTest, CreateActivitySuccess) {
    Data validDate(13,9,2024); // Example date
    EXPECT_NO_THROW(Activity activity("Test Activity", 10, 12, validDate));
}

TEST(ActivityTest, CreateActivityThrowsOnInvalidTime) {
    Data validDate(13,9,2024);
    EXPECT_THROW(Activity activity("Invalid Activity", 12, 10, validDate), std::invalid_argument);
}