#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<Event> Schedule::makeSchedule(){
    int j = 0;
    for(int i = 1; i < busy.size(); i++){
        if(busy[i] == false){
            hours.push_back(taskList[j]);
            j++;
        }
        else{
            Taken e = Taken();
            hours.push_back(e);
        }
    }

    
    // for(int i = 1; i < 24){
    //     hours.push_back(Event());
    // }

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

void Schedule::checkOffTask(string taskName){

}

void Schedule::setTaskList(vector<Event> e){
    taskList = e;
}
void Schedule::setPreferences(vector<bool> p){
        preferences = p;
}

void Schedule::setBusyTimes(vector<bool> b){
    busyTimes=b;
}
        
void addTask(Event e){
    taskList.push_back(e);
}

Schedule::Schedule(){

}
