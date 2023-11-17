#include "gtest/gtest.h"
#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;

TEST(ScheduleTests, testScheduleCreation){
    Event e;
    vector<Event> vectorOfE = {e};
    Schedule s;
    s.setTaskList(vectorOfE);
    EXPECT_EQ(s.makeSchedule().size(),1);
}

TEST(ScheduleTests, testScheduleDisplay){
    // Event e;
    // vector<Event> vectorOfE = {e};
    // Schedule s;
    // ostream h;
    // h = s.displaySchedule()
    // s.setTaskList(vectorOfE);

    // EXPECT_EQ(h,cout << "hour 1:00 - dummy");
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}