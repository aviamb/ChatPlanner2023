#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__
#include <vector>
#include <string>
#include "Event.h"

using namespace std;

class Schedule{
    private:
        vector<Event> hours;
        vector<bool> preferences;
        vector<Event> taskList;
        vector<bool>busyTimes;
        int timeNow;
        int sleepTime;
    public:
        void makeSchedule();//2 tests
        void displaySchedule(ostream &);
        void displayDetailedSchedule(ostream &);
        void saveSchedule(); 
        void checkOffTask(istream&);//1 test
        Event* checkOffTask(string taskName);
        Schedule();
        void setTaskList(vector<Event>);
        void setPreferences(vector<bool>);
        void setBusyTime(vector<bool>);
        void addTask(Event);
        void setBusyTimes(vector<bool>);
        void addTask(istream &in);
        void setTimeNow(int);
        void setSleepTime(int);
        int getTaskListSize();
        int getTimeNow();
        int getSleepTime();
        vector<Event>getHours();
        void popOffExtraHours();
        ~Schedule();
};


#endif