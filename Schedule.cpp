#include "Schedule.h"
#include "Event.h"
#include <vector>

using namespace std;

    // public: std::vector<Event> hours[24];
vector<Event> Schedule::makeSchedule(vector<Event> &taskList){
    hours = taskList;
    return hours;
}

Schedule::Schedule(){
    vector<Event> hours;
    vector<string> prefrences;
    vector<int> priority;
}
