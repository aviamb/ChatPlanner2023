#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


void Schedule::saveSchedule(){
    //open file
    ofstream outFS;
    string str;
    outFS.open("log.txt");
    if(!outFS.is_open()){
        cout<<"error opening log"<<endl;
    }

    for(int i=0; i<hours.size();i++){
        outFS<<hours.at(i).getName()<<" - "<<hours.at(i).getDescription()<<endl;
    }
}

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
