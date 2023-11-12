// #include "googletest/googletest//include/gtest/gtest.h"
#include "gtest/gtest.h"

#include <vector>
#include <string>

class EventStub : public Event{

}

TEST(ScheduleTests, testScheduleCreation){
    vector<Event> e;
    Schedule s;
    EXPECT_EQ(s.makeSchedule(e), e)
}