#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__
#include <vector>
#include <string>
#include "Event.h"

class Schedule{
    public:
        std::vector<Event> hours;
        std::vector<std::string> prefrences;
        std::vector<int> priority;
        
        std::vector<Event> makeSchedule(std::vector<Event> &e);
        Schedule();
};


#endif