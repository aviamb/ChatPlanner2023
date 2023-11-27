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

// TEST(ScheduleTests, testScheduleDisplayMult){
//     Event e;
//     Event f;
//     vector<Event> vectorOfE = {e, f};
//     Schedule s;
//     ostream &out;
//     s.setTaskList(vectorOfE);
//     s.makeSchedule();
//     EXPECT_EQ(s.displaySchedule(out),"hour 0:00 - dummyhour 1:00 - dummy");
// }

// TEST(ScheduleTests, testScheduleDisplaySingle){
//     Event e;
//     Event f;
//     vector<Event> vectorOfE = {e};
//     Schedule s;
//     s.setTaskList(vectorOfE);
//     s.makeSchedule();
//     EXPECT_EQ(s.displaySchedule(),"hour 0:00 - dummy");
// }

#include <sstream>

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
TEST(EventTests,TestPrintLeisure){
    ostringstream out;
    Leisure l("swim","at the pool");
    l.printEvent(out);
    EXPECT_EQ(out.str(),"swim\n- at the pool -\n");
}
TEST(EventTests,TestPrintWork){
    ostringstream out;
    Work w("do hw",2,"at the library");
    w.printEvent(out);
    EXPECT_EQ(out.str(),"* do hw *\n- at the library -\n");
}
TEST(EventTests,TestPrintTaken){
    ostringstream out;
    Taken t;
    t.printEvent(out);
    EXPECT_EQ(out.str(),"-------------------\n");
}

TEST(ScheduleTests, TestAddLeisureTask){
    string testInputString="go workout\ngo to the gym\nno";
    istringstream testIn(testInputString);
    ostringstream out;
    Schedule s;
    s.addTask(testIn);
    s.displaySchedule(out);
    EXPECT_EQ("hour 0:00\ngo workout\n",out.str());
}
// TEST(ScheduleTests, TestAddWorkTask){
//     string testInputString="do hw\nat the library\nyes\n2";
//     stringstream testIn(testInputString);
//     Schedule s;
//     s.addTask(testIn);
//     EXPECT_EQ(s.getTaskListSize(),1);
// }

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
