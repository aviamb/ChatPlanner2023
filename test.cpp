#include "gtest/gtest.h"
#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

TEST(ScheduleTests, testScheduleCreation){
    vector<Event> e;
    Schedule s;
    EXPECT_EQ(s.makeSchedule(e).size(),0);
}

// TEST(ScheduleTests, testScheduleDisplay){
//     vector<Event> e = [Event(), Event(), Event()];
// }

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}