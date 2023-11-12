// #include "googletest/googletest//include/gtest/gtest.h"
#include "gtest/gtest.h"

#include <vector>
#include <string>

TEST(ScheduleTests, testScheduleCreation){
    vector<Event> e;
    Schedule s;
    EXPECT_EQ(s.makeSchedule(e), e)
}