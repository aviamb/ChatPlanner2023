#include "gtest/gtest.h"
<<<<<<< HEAD
#include "Event.h"
#include "Schedule.h"
#include "RawInput.h"

TEST(EventTests,TestTakenConstructor){
    Taken t;
    EXPECT_EQ(t.getName(), "");
    EXPECT_EQ(t.getDescription(), "");
}
TEST(EventTests,TestLeisureConstructor){
    Leisure l("go for a swim","at the gym");
    EXPECT_EQ(l.getName(), "go for a swim");
    EXPECT_EQ(l.getDescription(), "at the gym");

}
TEST(EventTests,TestWorkConstructor){
    Work w("do hw",2,"at the library");
    EXPECT_EQ(w.getName(), "do hw");
    EXPECT_EQ(w.getDescription(), "at the library");
}
// TEST(MainTests, TestCallOrder1){
//     Schedule s;
// }
=======
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
>>>>>>> fd46928f1d1cd6fa27652c3879a25adc62702d77

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
<<<<<<< HEAD
}
=======
}
>>>>>>> fd46928f1d1cd6fa27652c3879a25adc62702d77
