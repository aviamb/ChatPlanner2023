#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

    // public: std::vector<Event> hours[24];
vector<Event> Schedule::makeSchedule(){
    hours = taskList;
    return hours;
}

string Schedule::displaySchedule(){
    string s;
    for(int i = 0; i < hours.size(); i++){
        s = s + "hour " + to_string(i) + ":00 - " + hours[i].getName();
        endl(cout);
    }
    cout << s;
    return s;

}

void Schedule::displayDetailedSchedule(){
    for(int i = 0; i < hours.size(); i++){
        cout << "hour " << i << ":00 - ";
        hours[i].printEvent();
    }
}

void Schedule::saveSchedule(){

}

void Schedule::checkOffTask() {//main
    Event* targetEvent;

    string taskName;
    string newName;
    string newDesc;
    
    do {
        cout << "Enter the current name of your task: ";
        cin.ignore();
        getline(cin, taskName);
        cout << endl;

        targetEvent = checkOffTask(taskName);
        if (targetEvent == nullptr) {
            cout << "Not a valid input." << endl;
        }
    } while (targetEvent == nullptr);

    targetEvent->setDescription("[COMPLETED] " + targetEvent->getDescription());
    cout << targetEvent->getDescription();
    return;
}

Event* Schedule::checkOffTask(const string taskName){//helper
    Event* task = nullptr;
    for(int i = 0; i < taskList.size(); i++) {
        if (taskList.at(i).getName() == taskName) {
            task = &taskList.at(i);
            break;
        }
    }
    return task;
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
