#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <iostream>

using namespace std;

    // public: std::vector<Event> hours[24];
vector<Event> Schedule::makeSchedule(){
    hours = taskList;
    return hours;
}

ostream Schedule::displaySchedule(){
    ostream s;
    for(int i = 0; i < hours.size(); i++){
        return s << "hour " << i << ":00 - " << schedule[i].getName();
    }

}

void Schedule::displayDetailedSchedule(){
    for(int i = 0; i < hours.size(); i++){
        cout << "hour " << i << ":00 - ";
        hours[i].printEvent();
    }
}

void Schedule::saveSchedule(){

}

void Schedule::checkOffTask(string taskName){

}

void Schedule::setTaskList(vector<Event> e){
    taskList = e;
}
void Schedule::setPreferences(vector<bool> p){
        preferences = p;
}
        
void addTask(Event);

Schedule::Schedule(){
    // vector<Event> hours;
    // vector<bool> preferences;
    // vector<int> priority;
    // vector<Event> taskList;
}
