#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <iostream>

using namespace std;

    // public: std::vector<Event> hours[24];
vector<Event> Schedule::makeSchedule(vector<Event> &taskList){
    hours = taskList;
    return hours;
}

void Schedule::displaySchedule(){
    for(int i = 0; i < hours.size(); i++){
        cout << "hour " << i << ":00 - " << hours[i].getName();
    }
}

void Schedule::displayDetailedSchedule(){
    for(int i = 0; i < hours.size(); i++){
        cout << "hour " << i << ":00 - ";
        hours[i].printEvent();
    }
}

void Schedule::writeToFile(){

}

Schedule::Schedule(){
    vector<Event> hours;
    vector<bool> prefrences;
    vector<int> priority;
}
