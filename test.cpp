#include "gtest/gtest.h"
#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <string>

TEST(ScheduleTests, testScheduleCreation){
    std::vector<Event> e;
    Schedule s;
    EXPECT_EQ(s.makeSchedule(e).size(),0);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}