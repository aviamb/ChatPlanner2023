#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__
#include <vector>
#include "Event.h"

class Schedule{
    public:
        std::vector<Event> hours;
    std::vector<Event> makeSchedule(std::vector<Event>);
};


#endif