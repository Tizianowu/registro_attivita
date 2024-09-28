//
// Created by Tiziano Wu on 15/09/24.
//
#include <gtest/gtest.h>
#include "../Register.h"

class RegisterTest : public ::testing::Test {
protected:
    Register* registerInstance;

    void SetUp() override {
        registerInstance = new Register("Test Register");
    }

    void TearDown() override {
        delete registerInstance;
    }
};

TEST_F(RegisterTest, AddActivity) {
    Data day(13, 9, 2024); // Assuming Data constructor is in (year, month, day)
    Activity activity("Test Activity", 10, 12, day);

    registerInstance->addActivity(activity);

    std::vector<Activity> activities = registerInstance->compareDates(day);
    ASSERT_EQ(activities.size(), 1);
    EXPECT_EQ(activities[0].getDescription(), "Test Activity");
}

TEST_F(RegisterTest, CompareDates) {
    Data day1(13, 9, 2024);
    Data day2(14, 9, 2024);
    Activity activity1("Activity 1", 10, 12, day1);
    Activity activity2("Activity 2", 11, 13, day2);

    registerInstance->addActivity(activity1);
    registerInstance->addActivity(activity2);

    std::vector<Activity> activities = registerInstance->compareDates(day1);
    ASSERT_EQ(activities.size(), 1);
    EXPECT_EQ(activities[0].getDescription(), "Activity 1");
}

TEST_F(RegisterTest, DeleteSelectedActivity) {
    Data day(13, 9, 2024);
    Activity activity("Activity to Delete", 10, 12, day);

    registerInstance->addActivity(activity);
    registerInstance->deleteSelectedActivity(activity);

    std::vector<Activity> activities = registerInstance->compareDates(day);
    ASSERT_EQ(activities.size(), 0);
}

TEST_F(RegisterTest, ClearActivities) {
    Data day(13, 9, 2024);
    Activity activity1("Activity 1", 10, 12, day);
    Activity activity2("Activity 2", 10, 12, day);

    registerInstance->addActivity(activity1);
    registerInstance->addActivity(activity2);
    registerInstance->clearActivities();

    std::vector<Activity> activities = registerInstance->compareDates(day);
    ASSERT_EQ(activities.size(), 0);
}