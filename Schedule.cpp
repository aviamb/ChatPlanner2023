#include "Schedule.h"
#include "Event.h"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

Schedule::~Schedule(){
    hours.clear();
    preferences.clear();
    taskList.clear();
    busyTimes.clear();
}

void Schedule::saveSchedule(){
    ofstream outFS;
    string str;
    outFS.open("log.txt",ios::app);
    if(!outFS.is_open()){
        cout<<"error opening log"<<endl;
    }
    int hour=timeNow+1;
    for(int i=0; i<hours.size();i++){
        outFS<<hour<<":00 "<<hours.at(i).getName()<<" - "<<hours.at(i).getDescription()<<endl;
        hour++;
    }
    outFS.close();
}

    // public: std::vector<Event> hours[24];
void Schedule::makeSchedule(){
    cout<<"hours length is "<<hours.size()<<endl;
    cout<<"busy times lenght is "<<busyTimes.size()<<endl;
    cout<<"preferences length is "<<preferences.size()<<endl;
    cout<<"tasklist length is "<<taskList.size()<<endl;
    Leisure sleep("go to bed","");
    hours.at(hours.size()-1)=sleep;

    for(unsigned i = 0; i < busyTimes.size(); i++){
        if(busyTimes.at(i) == true){
            Taken e;
            hours.at(i-timeNow)=e;
        }
    } 
    vector<Event> leisureList;
    vector<Event> workList;
    for(int i=0; i<taskList.size();i++){
        if(taskList.at(i).getType()=="Leisure"){
            leisureList.push_back(taskList.at(i));
        }else{
            workList.push_back(taskList.at(i));
        }
    }

    if(preferences.at(0)==false){//index 0 is hardcoded to doing nothing

        int leisureIndex=0;
        int workIndex=0;
        if(preferences.at(1)==true){//true means procrastinator
            cout<<"procrastinator"<<endl;
            for(int i=0; i<hours.size();i++){
                if(leisureList.size()==leisureIndex){//if already at end of list
                    break;
                }
                if(hours.at(i).getName()=="free time"){
                    hours.at(i)=leisureList.at(leisureIndex);
                    leisureIndex++;
                }

            }

            workList = sortWorkEvents(workList);
            for(int i=hours.size()-1; i>=0;i--){//last element is always go to bed
                cout<<"setting work events"<<endl;
                if(workList.size()==workIndex){//if already at end of list
                    break;
                }
                if( !(hours.at(i).getType()=="Taken"|| (hours.at(i).getType()=="Leisure" && hours.at(i).getName()!="free time"))){//if it is not a user set leisure activity or taken
                    hours.at(i)=workList.at(workIndex);
                    workIndex++;
                }
            }
        }else{
            leisureIndex=0;
            workIndex=0;
            cout<<"not a prcastinator"<<endl;
            workList = sortWorkEvents(workList);
            for(int i=0; i<hours.size();i++){

                if(workList.size()==workIndex){//if already at end of list
                    break;
                }
                if(hours.at(i).getName()=="free time"){
                    cout<<"setting work events"<<endl;
                    hours.at(i)=workList.at(workIndex);
                    workIndex++;
                }
            }
            for(int i=hours.size()-2; i>=0;i--){//last element is always go to bed
                if(leisureList.size()==leisureIndex){//if already at end of list
                    cout<<"bruh";
                    break;
                }
                if((hours.at(i).getName()=="free time")){//if it is not a user set leisure activity or taken
                    cout<<"hm"<<endl;
                    hours.at(i)=leisureList.at(leisureIndex);
                    leisureIndex++;
                }
            }
        }
    }
    taskList.clear();

}

vector<Event> Schedule::sortWorkEvents(vector<Event> & workEvents){
    cout<<"sorting work events"<<endl;
    for(int i = 0; i < workEvents.size(); i++){
        int minIndex = i;
        for (int j = i + 1; j < workEvents.size(); j++) {
            if (workEvents[j].getPriority() < workEvents[minIndex].getPriority()) {
                minIndex = j;
            }
        }
        Event tobeswapped = workEvents[i];
        workEvents[i] = workEvents[minIndex];
        workEvents[minIndex] = tobeswapped;
    }
    cout<<"end of work events"<<endl;
    return workEvents;
}

void Schedule::setTimeNow(int t){
    timeNow=t;
}

int Schedule::getTimeNow(){
    return timeNow;
}

int Schedule::getSleepTime(){
    return sleepTime;
}

void Schedule::setSleepTime(int t){
    sleepTime=t;
}

vector<Event> Schedule::getHours(){
    return hours;
}


void Schedule::displaySchedule(ostream & out){

    for(unsigned i=0;i<hours.size();i++){
        out<<"hour "<<1+timeNow+i;
        out<<":00 - " << hours.at(i).getName()<<endl;
    }
}

void Schedule::displayDetailedSchedule(ostream &out){
    for(int i = 0; i < hours.size(); i++){
        out << "hour " << i << ":00 - \n";
        hours.at(i).printEvent(out);
    }
}

void Schedule::checkOffTask(istream &in) {//main
    Event* targetEvent;

    string taskName;
    string newName;
    string newDesc;
    
    do {
        cout << "Enter the current name of your task: ";
        // in.ignore();
        getline(in, taskName);
        cout << endl;

        targetEvent = checkOffTask(taskName);
        if (targetEvent == nullptr) {
            cout << "Not a valid input." << endl;
        }
    } while (targetEvent == nullptr);

    targetEvent->setName("[COMPLETED] " + targetEvent->getName());
    // cout << targetEvent->getDescription();
    return;
}

Event* Schedule::checkOffTask(const string taskName){//helper
    Event* task = nullptr;
    for(int i = 0; i < hours.size(); i++) {
        if (hours.at(i).getName() == taskName) {
            task = &hours.at(i);
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

                if(stoi(priority)<4 && stoi(priority)>0){
                    Work newTask(name,stoi(priority),description);
                    taskList.push_back(newTask);
                    validPriority=true;
                }else{
                    cout<<"please enter a valid priority"<<endl;
                    in>>priority;
                }
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
    for(int i=0; i<24;i++){
        Leisure e("free time"," ");
        hours.push_back(e);
    }

}

void Schedule::popOffExtraHours(){
    for(int i=0; i<timeNow+(24-sleepTime);i++){
        hours.pop_back();
    }
}
