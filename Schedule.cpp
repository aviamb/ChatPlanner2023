#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;


void Schedule::saveSchedule(){
    ofstream outFS;
    string str;
    outFS.open("log.txt",ios::app);
    if(!outFS.is_open()){
        cout<<"error opening log"<<endl;
    }
    for(int i=0; i<hours.size();i++){
        outFS<<hours.at(i).getName()<<" - "<<hours.at(i).getDescription()<<endl;
    }
    outFS.close();
}

    // public: std::vector<Event> hours[24];
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


void Schedule::displaySchedule(ostream & out){
    for(int i = 0; i < hours.size(); i++){
        out<< "hour "<< to_string(i) <<":00 - " << hours[i].getName()<<endl;
    }
}

void Schedule::displayDetailedSchedule(ostream &out){
    for(int i = 0; i < hours.size(); i++){
        out << "hour " << i << ":00 - \n";
        hours.at(i).printEvent(out);
    }
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
void Schedule::setBusyTimes(vector<bool> b){
    busyTimes=b;
}
        
void Schedule::addTask(istream &in){
    string name;
    string input;
    string priority;
    string description;
    cout<<"Enter task name"<<endl;
    in.ignore();
    getline(in,name);
    cout<<"Enter description of task"<<endl;
    getline(in,description);

    cout<<"Is this a work task?(yes/no)"<<endl;
    in>>input;
    if(input=="yes"){
        cout<<"Enter priority of task"<<endl;
        in>>priority;
        bool validPriority=false;
        while(!validPriority){
            if(isdigit(priority[0])){
                Work newTask(name,stoi(priority),description);
                taskList.push_back(newTask);
                validPriority=true;
            }else{
                cout<<"please enter an int"<<endl;
                in>>priority;
            }
        }
    }else{
        Leisure newTask(name,description);
        taskList.push_back(newTask);
    }    
}

int Schedule::getTaskListSize(){
    return taskList.size();
}

Schedule::Schedule(){

}
