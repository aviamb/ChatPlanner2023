#include "gtest/gtest.h"
#include "Schedule.h"
#include "RawInput.h"
#include "Event.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;
#include <sstream>

TEST(RawInputTests,testNYY)
{
    stringstream preferences("no\nyes\nyes");
    RawInput r;
    vector<bool> vectorOfAskP = r.askPreferences(preferences);
    ASSERT_EQ(vectorOfAskP.size(), 3);
    EXPECT_FALSE(vectorOfAskP[0]);
    EXPECT_TRUE(vectorOfAskP[1]);
    EXPECT_TRUE(vectorOfAskP[2]);
}

TEST(RawInputTests,testNYN)
{
    stringstream preferences("no\nyes\nno");
    RawInput r;
    vector<bool> vectorOfAskP = r.askPreferences(preferences);
    ASSERT_EQ(vectorOfAskP.size(), 3);
    EXPECT_FALSE(vectorOfAskP[0]);
    EXPECT_TRUE(vectorOfAskP[1]);
    EXPECT_FALSE(vectorOfAskP[2]);
}

TEST(RawInputTests,testNNY)
{
    stringstream preferences("no\nno\nyes");
    RawInput r;
    vector<bool> vectorOfAskP = r.askPreferences(preferences);
    ASSERT_EQ(vectorOfAskP.size(), 3);
    EXPECT_FALSE(vectorOfAskP[0]);
    EXPECT_FALSE(vectorOfAskP[1]);
    EXPECT_TRUE(vectorOfAskP[2]);
}

TEST(RawInputTests,testY)
{
    stringstream preferences("yes");
    RawInput r;
    vector<bool> vectorOfAskP = r.askPreferences(preferences);
    ASSERT_EQ(vectorOfAskP.size(), 1);
    EXPECT_TRUE(vectorOfAskP[0]);
}

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

TEST(ScheduleTests, TestLazy){

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


TEST(ScheduleTests, TestDoNothing){

    stringstream preferences("yes\nno\nno");
    stringstream busyTimes("0");
    stringstream tasks("swim\nat the pool\nno\ne\nhw\nat the library\nyes\n1\nq");

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
    EXPECT_EQ(s.getHours().at(0).getName(),"free time");
}

TEST(ScheduleTests, TestPriority){

    stringstream preferences("no\nno\nno");
    stringstream busyTimes("0");
    stringstream tasks("swim\nat the pool\nyes\n3\ne\nhw\nat the library\nyes\n1\ne\nlecture\nfor cs100\nyes\n2\nq");

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

    EXPECT_EQ(s.getHours().at(0).getName(),"hw");

}

TEST(ScheduleTests, TestPriorityWithNonWork){

    stringstream preferences("no\nno\nno");
    stringstream busyTimes("0");
    stringstream tasks("swim\nat the pool\nyes\n3\ne\nhw\nat the library\nyes\n1\ne\nlecture\nfor cs100\nyes\n2\ne\nvideo games\nwith friends\nn\nq");

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

    EXPECT_EQ(s.getHours().at(8).getName(),"video games");
}

TEST(RawInputTests, TestOneTaskName) { //testing ONE task input, multiple word inputs only (for getline/cin testing)
    vector<Event> testTaskList;
    RawInput r; 

    stringstream tasks("cs100 milestone 4\ndemo preparation, unit testing,update README\ny\n1\nq");
 
    testTaskList = r.askTasks(tasks);

    EXPECT_EQ(testTaskList.at(0).getName(), "cs100 milestone 4");
}

TEST(RawInputTests, TestOneTaskDescription) {
    vector<Event> testTaskList;
    RawInput r;

    stringstream tasks("cs100 milestone 4\ndemo preparation, unit testing,update README\ny\n1\nq");

    testTaskList = r.askTasks(tasks);

    EXPECT_EQ(testTaskList.at(0).getDescription(), "demo preparation, unit testing,update README");
}

TEST(RawInputTests, TestOneTaskType) { 
    vector<Event> testTaskList;
    RawInput r;

    stringstream tasks("cs100 milestone 4\ndemo preparation, unit testing,update README\ny\n1\nq");

    testTaskList = r.askTasks(tasks);

    EXPECT_EQ(testTaskList.at(0).getType(), "Work");
}

TEST(RawInputTests, TestFourTaskName) { //testing MULTIPLE tasks with multiple/single word inputs mixed. tests elements later in the vector
    vector<Event> testTaskList;
    RawInput r;

    stringstream tasks("cs100 project\nmilestone 4\ny\n1\nA\nstudy for cs061\nquiz on wednesday\ny\n2\nA\noverwatch\nnew season!\nn\nA\nlab\nbio\nn\nq");

    testTaskList = r.askTasks(tasks);

    string s;

    for (int i = 0; i < 4; i++) {
        s += testTaskList.at(i).getName();
        s += " ";
    }

    EXPECT_EQ(s, "cs100 project study for cs061 overwatch lab ");
}

TEST(RawInputTests, TestFourTaskDescription) {
    vector<Event> testTaskList;
    RawInput r;

    stringstream tasks("cs100 project\nmilestone 4\ny\n1\nA\nstudy for cs061\nquiz on wednesday\ny\n2\nA\noverwatch\nnew season!\nn\nA\nlab\nbio\nn\nq");

    testTaskList = r.askTasks(tasks);

    string s;

    for (int i = 0; i < 4; i++) {
        s += testTaskList.at(i).getDescription();
        s += " ";
    }

    EXPECT_EQ(s, "milestone 4 quiz on wednesday new season! bio ");
}

TEST(RawInputTests, TestFourTaskType) {
    vector<Event> testTaskList;
    RawInput r;

    stringstream tasks("cs100 project\nmilestone 4\ny\n1\nA\nstudy for cs061\nquiz on wednesday\ny\n2\nA\noverwatch\nnew season!\nn\nA\nlab\nbio\nn\nq");

    testTaskList = r.askTasks(tasks);

    string s;

    for (int i = 0; i < 4; i++) {
        s += testTaskList.at(i).getType();
        s = s + "(" + to_string(testTaskList.at(i).getPriority()) + ")";
        s += " ";
    }

    EXPECT_EQ(s, "Work(1) Work(2) Leisure(0) Leisure(0) ");
}

TEST(RawInputTests, TestManyTaskName) {
    vector<Event> testTaskList;
    RawInput r;

    stringstream tasks;
    tasks << "cs100 project\nmilestone 4\ny\n1\nA\nstudy for cs061\nquiz on wednesday\ny\n2\nA\noverwatch\nnew season!\nn\nA\nlab\nbio\nn\nA\n";
    tasks << "take pills\nvitamin C\nN\nA\nwatch movie with friends\nnew hunger games\nN\nA\nskincare\nN/A\nN\nA\nattend Philosophy discussion\n11AM\nY\n3\nA\n";
    tasks << "swim\nat beach\nN\nA\ngo golfing\nwith mom\nn\nA\napply for internships\nmicrosoft,google,etc.\nY\n2\nA\nbrush teeth\nuse mouthwash\nn\nQ";

    testTaskList = r.askTasks(tasks);

    string s;

    for (int i = 0; i < 12; i++) {
        s += testTaskList.at(i).getName();
        s += " ";
    }

    EXPECT_EQ(s, "cs100 project study for cs061 overwatch lab take pills watch movie with friends skincare attend Philosophy discussion swim go golfing apply for internships brush teeth ");
}


TEST(RawInputTests, TestManyTaskDescription) {
    vector<Event> testTaskList;
    RawInput r;

    stringstream tasks;
    tasks << "cs100 project\nmilestone 4\ny\n1\nA\nstudy for cs061\nquiz on wednesday\ny\n2\nA\noverwatch\nnew season!\nn\nA\nlab\nbio\nn\nA\n";
    tasks << "take pills\nvitamin C\nN\nA\nwatch movie with friends\nnew hunger games\nN\nA\nskincare\nN/A\nN\nA\nattend Philosophy discussion\n11AM\nY\n3\nA\n";
    tasks << "swim\nat beach\nN\nA\ngo golfing\nwith mom\nn\nA\napply for internships\nmicrosoft,google,etc.\nY\n2\nA\nbrush teeth\nuse mouthwash\nn\nQ";

    testTaskList = r.askTasks(tasks);

    string s;

    for (int i = 0; i < 12; i++) {
        s += testTaskList.at(i).getDescription();
        s += " ";
    }

    EXPECT_EQ(s, "milestone 4 quiz on wednesday new season! bio vitamin C new hunger games N/A 11AM at beach with mom microsoft,google,etc. use mouthwash ");
}

TEST(RawInputTests, TestAskManyTask_Spaces) {
    vector<Event> testTaskList;
    RawInput r;

    stringstream tasks;
    tasks << "cs100 project\nmilestone 4\ny\n1\nA\nstudy for cs061\nquiz on wednesday\ny\n2\nA\noverwatch\nnew season!\nn\nA\nlab\nbio\nn\nA\n";
    tasks << "take pills\nvitamin C\nN\nA\nwatch movie with friends\nnew hunger games\nN\nA\nskincare\nN/A\nN\nA\nattend Philosophy discussion\n11AM\nY\n3\nA\n";
    tasks << "swim\nat beach\nN\nA\ngo golfing\nwith mom\nn\nA\napply for internships\nmicrosoft,google,etc.\nY\n2\nA\nbrush teeth\nuse mouthwash\nn\nQ";

    testTaskList = r.askTasks(tasks);

    string s;

    for (int i = 0; i < 12; i++) {
        s += testTaskList.at(i).getType();
        s = s + "(" + to_string(testTaskList.at(i).getPriority()) + ")";
        s += " ";
    }

    EXPECT_EQ(s, "Work(1) Work(2) Leisure(0) Leisure(0) Leisure(0) Leisure(0) Leisure(0) Work(3) Leisure(0) Leisure(0) Work(2) Leisure(0) ");
}


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}