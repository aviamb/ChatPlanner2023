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
    Event e;
    Event f;
    vector<Event> vectorOfE = {e, f};
    Schedule s;
    s.setTaskList(vectorOfE);
    s.makeSchedule();
    EXPECT_EQ(s.displaySchedule(),"hour 0:00 - dummyhour 1:00 - dummy");
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}