#include "gtest/gtest.h"
#include "Schedule.h"
#include "RawInput.h"
#include "Event.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
#include <sstream>

TEST(EventTests,TestTakenConstructor){
    Taken t;
    EXPECT_EQ(t.getName(), "-------");
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

TEST(ScheduleTests, TestProcrastinator){

    stringstream preferences("no\nyes\nno");
    stringstream busyTimes("10\n11\n17\n18\n0");
    stringstream tasks("swim\nat the pool\nno\nhw\nat the library\nyes\n1\nq");

    Schedule s;
    RawInput r;
    s.setTimeNow(9);
    s.setSleepTime(19);
    
    s.setPreferences(r.askPreferences(preferences));
    s.setBusyTimes(r.askBusyTimes(9,19,busyTimes));
    cin.ignore();
    s.setTaskList(r.askTasks(tasks));
    s.popOffExtraHours();
    s.makeSchedule();
    EXPECT_EQ(s.getHours().at(6).getName(),"hw");
}

TEST(ScheduleTests, TestCheckOffNonProcrastinator){
    stringstream preferences("no\nno\nno");
    stringstream busyTimes("10\n11\n17\n18\n0");
    stringstream tasks("swim\nat the pool\nno\nhw\nat the library\nyes\n1\nq");
    stringstream checkOff("swim");
    Schedule s;
    RawInput r;
    s.setTimeNow(9);
    s.setSleepTime(19);
    s.setPreferences(r.askPreferences(preferences));
    s.setBusyTimes(r.askBusyTimes(9,19,busyTimes));
    cin.ignore();
    s.setTaskList(r.askTasks(tasks));
    s.popOffExtraHours();
    s.makeSchedule();
    Event *doneTask;
    doneTask=s.checkOffTask("swim");
    doneTask->setName("[COMPLETED] " + doneTask->getName());
    cin.ignore();
    EXPECT_EQ(s.getHours().at(6).getName(),"[COMPLETED] swim");
}

TEST(ScheduleTests,testAddTask){

    stringstream addNewTask("\ngo to library\ndo hw\nyes\nP\nt\n25\nf\n1");
    
    stringstream preferences("no\nno\nno");
    stringstream busyTimes("0");
    stringstream checkOff("swim");
    Schedule s;
    RawInput r;
    s.setTimeNow(9);
    s.setSleepTime(19);
    s.setPreferences(r.askPreferences(preferences));
    s.setBusyTimes(r.askBusyTimes(9,19,busyTimes));
    cin.ignore();
    s.popOffExtraHours();
    s.addTask(addNewTask);
    s.makeSchedule();
    EXPECT_EQ(s.getHours().at(0).getName(),"go to library");
}





int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
