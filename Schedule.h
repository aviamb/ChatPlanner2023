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
        // vector<int> priority;
        vector<Event> taskList;
        vector<bool>busyTimes;
    public:
        vector<Event> makeSchedule();
        string displaySchedule();
        void displayDetailedSchedule();
        void saveSchedule();
        void checkOffTask(string taskName);
        Schedule();
        void setTaskList(vector<Event> e);
        void setPreferences(vector<bool>);
        void setBusyTimes(vector<bool>);
        void addTask(Event);

};


#endif