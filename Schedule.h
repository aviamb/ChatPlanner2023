#ifndef __SCHEDULE_H__
#define __SCHEDULE_H__
#include <vector>
#include "Event.h"

class Schedule{
    private:
        std::vector<Event> hours[24];
};


#endif