#include "Schedule.h"
#include "Event.h"
#include <vector>

    // public: std::vector<Event> hours[24];
std::vector<Event> Schedule::makeSchedule(std::vector<Event> taskList){
    hours = taskList;
}
